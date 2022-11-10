#include "..\..\include\Parallax\Fundo.hpp"

Jungle::Parallax::Fundo::Fundo(sf::Vector2f* posJogador):
    Ente(IDs::IDs::fundo), posJogador(posJogador), posAnterior(*posJogador)
{

}

Jungle::Parallax::Fundo::~Fundo(){

}

void Jungle::Parallax::Fundo::executar(){
    sf::Vector2f ds = *posJogador - posAnterior;
    posAnterior = *posJogador;
}

void Jungle::Parallax::Fundo::desenhar(){
    //vai renderizar as camadas...
}