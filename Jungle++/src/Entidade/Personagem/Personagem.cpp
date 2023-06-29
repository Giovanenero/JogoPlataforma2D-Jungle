#include "..\..\..\include\Entidade\Personagem\Personagem.hpp"

Jungle::Entidade::Personagem::Personagem::Personagem(const sf::Vector2f pos, const sf::Vector2f tam, const float vel, const IDs::IDs ID,  const float tempoMorrer, const float tempoDano):
    Entidade(tam, ID, pos), andando(false), paraEsquerda(false), relogio(), 
    dt(0.0f), velFinal(sf::Vector2f(vel, 0.0f)), velMax(vel), atacando(false),
    animacao(&corpo), tempoAnimacaoMorrer(tempoMorrer), tempoMorrer(0.0f),
    vidaMaxima(100.0f), vida(100.0f), tempoAnimacaoTomarDano(tempoDano), tempoDano(0.0f),
    morrendo(false)
{

}

Jungle::Entidade::Personagem::Personagem::~Personagem(){

}

void Jungle::Entidade::Personagem::Personagem::andar(const bool paraEsquerda){
    atacando = false;
    andando = true;
    this->paraEsquerda = paraEsquerda;
}

void Jungle::Entidade::Personagem::Personagem::parar(){
    andando = false;
}

void Jungle::Entidade::Personagem::Personagem::atacar(const bool atacando){
    andando = false;
    this->atacando = atacando;
}

void Jungle::Entidade::Personagem::Personagem::atualizarPosicao(){
    dt = pGrafico->getTempo();
    //vai resetar o relógio no caso de jogo pausado;

    if(dt > 0.3f){
        dt = 0.0f;
    }
    //relogio.restart();
    sf::Vector2f ds(0.0f, 0.0f);

    //move na horizontal
    if(andando){
        ds.x = velFinal.x * dt;
        if(paraEsquerda){
            ds.x *= -1;
        }
    }

        //sofre o efeito da gravidade
    velFinal.y += GRAVIDADE * dt;
    ds.y = velFinal.y * GRAVIDADE;

    //atualiza posição
    setPos(sf::Vector2f(pos.x + ds.x, pos.y + ds.y));

    //atualiza velocidade na horizontal
    velFinal.x = velMax;

    //carrega o tempo pra ele levar outro dano
    atualizarTomarDano();

    //desenha na janela
    desenhar();
}

void Jungle::Entidade::Personagem::Personagem::setVelFinal(sf::Vector2f velFinal){
    this->velFinal = velFinal;
}

const sf::Vector2f Jungle::Entidade::Personagem::Personagem::getVelFinal() const{
    return velFinal;
}

const bool Jungle::Entidade::Personagem::Personagem::getMorrer() const {
    return morrendo;
}

const bool Jungle::Entidade::Personagem::Personagem::getLevandoDano() const {
    return levandoDano;
}

void Jungle::Entidade::Personagem::Personagem::atualizarTomarDano(){
    tempoDano += pGrafico->getTempo();
    if(levandoDano && tempoDano > tempoAnimacaoTomarDano){
        levandoDano = false;
        tempoDano = 0.0f;
    }
}

void Jungle::Entidade::Personagem::Personagem::tomarDano(const float dano){
    std::cout << tempoDano << std::endl;
    if(!levandoDano){
        levandoDano = true;
        andando = false;
        vida -= dano;
        if(vida <= 0.0f){
            morrendo = true;
        }
        tempoDano = 0.0f;
    }
}

void Jungle::Entidade::Personagem::Personagem::atualizarAnimacao(){
    if(morrendo){
        animacao.atualizar(paraEsquerda, "MORRE");
        tempoMorrer += pGrafico->getTempo();
        if(tempoMorrer > tempoAnimacaoMorrer){
            podeRemover = true;
            tempoMorrer = 0.0f;
        }
    } else if(levandoDano){
        animacao.atualizar(paraEsquerda, "TOMADANO");
    } else if(andando){
        animacao.atualizar(paraEsquerda, "ANDA");
    } else {
        animacao.atualizar(paraEsquerda, "PARADO");
    }
}