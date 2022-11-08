#include "..\..\include\Gerenciador\GerenciadorEvento.hpp"

Jungle::Gerenciador::GerenciadorEvento* Jungle::Gerenciador::GerenciadorEvento::pEvento = nullptr;

Jungle::Gerenciador::GerenciadorEvento::GerenciadorEvento():
    pGrafico(pGrafico->getGerenciadorGrafico())
{

}

Jungle::Gerenciador::GerenciadorEvento::~GerenciadorEvento(){
    
}

Jungle::Gerenciador::GerenciadorEvento* Jungle::Gerenciador::GerenciadorEvento::getGerenciadorEvento(){
    if(pEvento == nullptr){
        pEvento = new GerenciadorEvento();
    }
    return pEvento;
}
void Jungle::Gerenciador::GerenciadorEvento::setJogador(Entidade::Personagem::Jogador::Jogador* pJogador){
    this->pJogador = pJogador;
}

void Jungle::Gerenciador::GerenciadorEvento::verificaTeclaPressionada(sf::Keyboard::Key tecla){
    if(tecla == sf::Keyboard::A){
        pJogador->andar(true);
    } else if(tecla == sf::Keyboard::D){
        pJogador->andar(false);
    } else if(tecla == sf::Keyboard::W){
        pJogador->pular();
    } else if(tecla == sf::Keyboard::S){
        pJogador->atacar(true);
    } else if(tecla == sf::Keyboard::Escape){
        pGrafico->fecharJanela();
    }
}

void Jungle::Gerenciador::GerenciadorEvento::verificaTeclaSolta(sf::Keyboard::Key tecla){
    if(tecla == sf::Keyboard::A || tecla == sf::Keyboard::D){
        pJogador->parar();
    }
}

void Jungle::Gerenciador::GerenciadorEvento::executar(){
    sf::Event evento;
    while(pGrafico->getWindow()->pollEvent(evento)){
        if(evento.type == sf::Event::KeyPressed){
            verificaTeclaPressionada(evento.key.code);
        } else if(evento.type == sf::Event::KeyReleased){
            verificaTeclaSolta(evento.key.code);
        } else if(evento.type == sf::Event::Closed){
            pGrafico->fecharJanela();
        }
    }
}