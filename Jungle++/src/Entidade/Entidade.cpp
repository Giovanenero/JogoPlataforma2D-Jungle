#include "..\..\include\Entidade\Entidade.hpp"

Jungle::Entidade::Entidade::Entidade(const sf::Vector2f pos, const sf::Vector2f tam, const IDs::IDs ID):
    Ente(ID), corpo(sf::RectangleShape(tam)), pos(pos), tam(tam)
{
    corpo.setPosition(pos);
}

Jungle::Entidade::Entidade::~Entidade(){
    
}

const sf::RectangleShape Jungle::Entidade::Entidade::getCorpo(){
    return corpo;
}

void Jungle::Entidade::Entidade::setPos(sf::Vector2f pos){
    corpo.setPosition(pos);
    this->pos = pos;
}

const sf::Vector2f Jungle::Entidade::Entidade::getPos(){
    return pos;
}

const sf::Vector2f Jungle::Entidade::Entidade::getTam(){
    return tam;
}

void Jungle::Entidade::Entidade::desenhar(){
    pGrafico->desenhaElemento(corpo);
}