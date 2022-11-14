#include "..\..\include\Fase\Fase.hpp"

Jungle::Fase::Fase::Fase(const IDs::IDs ID_Fase, const IDs::IDs ID_Fundo):
    Ente(ID_Fase), fundo(ID_Fundo)
{

}

Jungle::Fase::Fase::~Fase(){

}

Jungle::Entidade::Entidade* Jungle::Fase::Fase::criaPlataforma(const sf::Vector2f pos){
    Entidade::Obstaculo::Plataforma* plataforma = new Entidade::Obstaculo::Plataforma(pos, sf::Vector2f(300.0f, 50.0f));
    if(plataforma == nullptr){
        std::cout << "Jungle::Fase::nao foi possivel criar uma plataforma" << std::endl;
        exit(1);
    }
    return static_cast<Entidade::Entidade*>(plataforma);
}

Jungle::Entidade::Entidade* Jungle::Fase::Fase::criaCaixa(const sf::Vector2f pos){
    Entidade::Obstaculo::Caixa* caixa = new Entidade::Obstaculo::Caixa(pos, sf::Vector2f(50.0f, 50.0f));
    if(caixa == nullptr){
        std::cout << "Jungle::Fase::nao foi possivel criar uma caixa" << std::endl;
        exit(1);
    }
    return static_cast<Entidade::Entidade*>(caixa);
}

Jungle::Entidade::Entidade* Jungle::Fase::Fase::criaInimigo(const sf::Vector2f pos, Entidade::Personagem::Jogador::Jogador* jogador){
    Entidade::Personagem::Inimigo::Inimigo* inimigo = new Entidade::Personagem::Inimigo::Inimigo(pos, sf::Vector2f(50.0f, 90.0f), jogador);
    if(inimigo == nullptr){
        std::cout << "Jungle::Fase::nao foi possivel criar um inimigo" << std::endl;
        exit(1);
    }
    return static_cast<Entidade::Entidade*>(inimigo);
}
