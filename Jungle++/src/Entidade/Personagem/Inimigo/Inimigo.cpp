#include "..\..\..\..\include\Entidade\Personagem\Inimigo\Inimigo.hpp"

Jungle::Entidade::Personagem::Inimigo::Inimigo::Inimigo(const sf::Vector2f pos, const sf::Vector2f tam, Jogador::Jogador* jogador):
    Personagem(pos, tam, VELOCIDADE_INIMIGO, IDs::IDs::inimigo), jogador(jogador), dtAux(0.0f)
{
    corpo.setFillColor(sf::Color::Red);
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
    
}

void Jungle::Entidade::Personagem::Inimigo::Inimigo::atualizaMovimentoAleatorio(){
    if(dtAux > 3.0f){
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
    dtAux += relogio.getElapsedTime().asSeconds();
    relogio.restart();
}

void Jungle::Entidade::Personagem::Inimigo::Inimigo::colisao(Entidade* outraEntidade, sf::Vector2f ds){
    switch(outraEntidade->getID()){
        case (IDs::IDs::jogador):
        {
            std::cout << "Bate jogador e jogador pode bater no inimigo" << std::endl;
        }
        break;
        case (IDs::IDs::inimigo):
        {
            std::cout << "Empurra inimigo" << std::endl;
        }
        break;
    }
}