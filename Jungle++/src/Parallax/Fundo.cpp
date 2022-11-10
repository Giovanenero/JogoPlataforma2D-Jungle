#include "..\..\include\Parallax\Fundo.hpp"

Jungle::Parallax::Fundo::Fundo():
    Ente(IDs::IDs::fundo), posAnteriorCamera(pGrafico->getCamera().getCenter())
{

}

Jungle::Parallax::Fundo::~Fundo(){

}

void Jungle::Parallax::Fundo::executar(){
    sf::Vector2f posCamera = pGrafico->getCamera().getCenter();
    const sf::Vector2f ds = posCamera - posAnteriorCamera;
    posAnteriorCamera = posCamera;
}

void Jungle::Parallax::Fundo::desenhar(){
    //vai renderizar as camadas...
}