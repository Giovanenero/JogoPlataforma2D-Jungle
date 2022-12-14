#include "..\..\..\include\Entidade\Personagem\Personagem.hpp"

Jungle::Entidade::Personagem::Personagem::Personagem(const sf::Vector2f pos, const sf::Vector2f tam, const float vel, const IDs::IDs ID):
    Entidade(pos, tam, ID), podeAndar(false), paraEsquerda(false), relogio(), 
    dt(0.0f), velFinal(sf::Vector2f(vel, 0.0f)), velMax(vel), atacando(false),
    animacao(&corpo)
{

}

Jungle::Entidade::Personagem::Personagem::~Personagem(){

}

void Jungle::Entidade::Personagem::Personagem::andar(const bool paraEsquerda){
    atacando = false;
    podeAndar = true;
    this->paraEsquerda = paraEsquerda;
}

void Jungle::Entidade::Personagem::Personagem::parar(){
    podeAndar = false;
}

void Jungle::Entidade::Personagem::Personagem::atacar(const bool atacando){
    podeAndar = false;
    this->atacando = atacando;
}

void Jungle::Entidade::Personagem::Personagem::atualizarPosicao(){
    dt = relogio.getElapsedTime().asSeconds();
    //vai resetar o relógio no caso de jogo pausado;
    if(dt > 0.3){
        dt = 0.0f;
    }
    relogio.restart();
    sf::Vector2f ds(0.0f, 0.0f);

    //move na horizontal
    if(podeAndar){
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

    //desenha na janela
    desenhar();
}

void Jungle::Entidade::Personagem::Personagem::setVelFinal(sf::Vector2f velFinal){
    this->velFinal = velFinal;
}

const sf::Vector2f Jungle::Entidade::Personagem::Personagem::getVelFinal() const{
    return velFinal;
}

void Jungle::Entidade::Personagem::Personagem::atualizarAnimacao(){
    if(podeAndar){
        animacao.atualizar(paraEsquerda, "ANDA");
    } else {
        animacao.atualizar(paraEsquerda, "PARADO");
    }
}