#include "..\..\..\..\include\Entidade\Personagem\Inimigo\Inimigo.hpp"

Jungle::Entidade::Personagem::Inimigo::Inimigo::Inimigo(const sf::Vector2f pos, const sf::Vector2f tam, Jogador::Jogador* jogador):
    Personagem(pos, tam, VELOCIDADE_INIMIGO, IDs::IDs::inimigo), jogador(jogador), dtAux(0.0f)
{
    inicializa();
    srand(time(NULL));
    moveAleatorio = rand()%3;
    if(moveAleatorio == 0){
        parar();
    } else if(moveAleatorio == 1){
        andar(true);
    } else {
        andar(false);
    }
}

Jungle::Entidade::Personagem::Inimigo::Inimigo::~Inimigo(){

}

void Jungle::Entidade::Personagem::Inimigo::Inimigo::inicializa(){
    animacao.addAnimacao("Jungle++/img/Inimigo/Esqueleto/Parado.png", "PARADO", 11, 0.12f, sf::Vector2f(1.0f, 1.10f));
    animacao.addAnimacao("Jungle++/img/Inimigo/Esqueleto/Anda.png", "ANDA", 13, 0.15f, sf::Vector2f(1.0f, 1.10f));
    corpo.setOrigin(sf::Vector2f(tam.x / 12.0f, tam.y / 8.5f));
}

void Jungle::Entidade::Personagem::Inimigo::Inimigo::atualizaMovimentoAleatorio(){
    if(dtAux > 1.0f){
        moveAleatorio = rand()%3;
        if(moveAleatorio == 0){
            parar();
        } else if(moveAleatorio == 1){
            andar(true);
        } else {
            andar(false);
        }
        dtAux = 0.0f;
    } 
}

void Jungle::Entidade::Personagem::Inimigo::Inimigo::atualizar(){
    sf::Vector2f posJogador = jogador->getPos();
    sf::Vector2f posInimigo = getPos();
    if(fabs(posJogador.x - posInimigo.x) <= RAIO_PERSEGUIR_X && fabs(posJogador.y - posInimigo.y) <= RAIO_PERSEGUIR_Y){
        if(posJogador.x - posInimigo.x > 0.0f){
            andar(false);
        } else {
            andar(true);
        }
    } else {
        atualizaMovimentoAleatorio();
    }
    atualizarPosicao();
    dtAux += relogio.getElapsedTime().asSeconds() * 100;
    relogio.restart();
    atualizarAnimacao();
}

void Jungle::Entidade::Personagem::Inimigo::Inimigo::colisao(Entidade* outraEntidade, sf::Vector2f ds){
    switch(outraEntidade->getID()){
        case (IDs::IDs::jogador):
        {
            //std::cout << "Bate jogador e jogador pode bater no inimigo" << std::endl;
        }
        break;
        case (IDs::IDs::inimigo):
        {
            //std::cout << "Empurra inimigo" << std::endl;
        }
        break;
    }
}