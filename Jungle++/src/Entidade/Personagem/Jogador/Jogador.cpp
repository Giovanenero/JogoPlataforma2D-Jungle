#include "..\..\..\..\include\Entidade\Personagem\Jogador\Jogador.hpp"

#include <cmath>

Jungle::Entidade::Personagem::Jogador::Jogador::Jogador(const sf::Vector2f pos, const sf::Vector2f tam):
    Personagem(pos, tam, VELOCIDADE_JOGADOR, IDs::IDs::jogador), noChao(false)

{
    inicializa();
}


void Jungle::Entidade::Personagem::Jogador::Jogador::inicializa(){
    animacao.addAnimacao("Jungle++/img/Jogador/Anda.png", "ANDA", 10, 0.12f, sf::Vector2f(6,2));
    animacao.addAnimacao("Jungle++/img/Jogador/Ataca.png", "ATACA", 10, 0.1f, sf::Vector2f(6,2));
    animacao.addAnimacao("Jungle++/img/Jogador/Parado.png", "PARADO", 10, 0.15f, sf::Vector2f(6,2));
    animacao.addAnimacao("Jungle++/img/Jogador/Pula.png", "PULA", 3, 0.15f, sf::Vector2f(6,2));
    animacao.addAnimacao("Jungle++/img/Jogador/Cai.png", "CAI", 3, 0.15f, sf::Vector2f(6,2));
    animacao.addAnimacao("Jungle++/img/Jogador/Morre.png", "MORRE", 10, 0.15f, sf::Vector2f(6,2));
    animacao.addAnimacao("Jungle++/img/Jogador/tomaDano.png", "TOMA_DANO", 1, 0.15f, sf::Vector2f(6,2));
    corpo.setOrigin(sf::Vector2f(tam.x / 2.5f, tam.y / 2.0f));
}

void Jungle::Entidade::Personagem::Jogador::Jogador::atualizar(){
    /**
        * @ return void 
        * 
        * Faz o movimeto do jogador e atualiza animação
     */
    atualizarPosicao();
    atualizarAnimacao();
    pGrafico->atualizarCamera(pos);
}

void Jungle::Entidade::Personagem::Jogador::Jogador::atualizarAnimacao(){
    if(!noChao && velFinal.y > 0.0f){
        animacao.atualizar(paraEsquerda, "CAI");
    } else if(!noChao){
        animacao.atualizar(paraEsquerda, "PULA");
    } else if(atacando){
        animacao.atualizar(paraEsquerda, "ATACA");
    } else if(podeAndar){
        animacao.atualizar(paraEsquerda, "ANDA");
    } else {
        animacao.atualizar(paraEsquerda, "PARADO");
    }
}

void Jungle::Entidade::Personagem::Jogador::Jogador::colisao(Entidade* outraEntidade, sf::Vector2f ds){
    switch(outraEntidade->getID()){
        case (IDs::IDs::inimigo):
        {
            
        }
        break;
        case(IDs::IDs::plataforma):
        {
            
        }
    }   
}

void Jungle::Entidade::Personagem::Jogador::Jogador::pular(){
    if(noChao){
        velFinal.y = -sqrt(2.0f * GRAVIDADE * TAMANHO_PULO);
        noChao = false;
    }
}

void Jungle::Entidade::Personagem::Jogador::Jogador::podePular(){
    noChao = true;
}