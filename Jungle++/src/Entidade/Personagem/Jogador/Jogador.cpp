#include "..\..\..\..\include\Entidade\Personagem\Jogador\Jogador.hpp"

#include <cmath>

Jungle::Entidade::Personagem::Jogador::Jogador::Jogador(const sf::Vector2f pos, const sf::Vector2f tam):
    Personagem(pos, tam, VELOCIDADE_JOGADOR, IDs::IDs::jogador), noChao(false), animacao(&corpo)

{
    inicializa();
}


void Jungle::Entidade::Personagem::Jogador::Jogador::inicializa(){
    animacao.addAnimacao("Jungle++/img/Jogador/Anda.png", "ANDA", 10, 0.12f, sf::Vector2f(6,2));
    animacao.addAnimacao("Jungle++/img/Jogador/Ataca.png", "ATACA", 10, 0.15f, sf::Vector2f(5,2));
    animacao.addAnimacao("Jungle++/img/Jogador/Parado.png", "PARADO", 10, 0.15f, sf::Vector2f(6,2));
}

void Jungle::Entidade::Personagem::Jogador::Jogador::atualizar(){
    /**
        * @ return void 
        * 
        * Faz o movimeto do jogador e atualiza animação
     */
    atualizarPosicao();
    atualizarAnimacao();
}

void Jungle::Entidade::Personagem::Jogador::Jogador::atualizarAnimacao(){
    if(podeAtacar){
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
            //std::cout << "Pode bater no inimigo e inimigo pode bater no jogador" << std::endl;
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
