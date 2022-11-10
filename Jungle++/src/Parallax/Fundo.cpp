#include "..\..\include\Parallax\Fundo.hpp"

Jungle::Parallax::Fundo::Fundo(sf::Vector2f* posJogador):
    Ente(IDs::IDs::fundo), posJogador(posJogador)
{

}

Jungle::Parallax::Fundo::~Fundo(){

}

void Jungle::Parallax::Fundo::executar(){
    std::cout << posJogador->x << "\n ";
}

void Jungle::Parallax::Fundo::desenhar(){
    //vai renderizar as camadas...
}