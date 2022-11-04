#include "..\..\include\Entidade\Entidade.hpp"

Jungle::Entidade::Entidade::Entidade(const sf::Vector2f pos, const sf::Vector2f tam, const IDs::IDs ID):
    corpo(sf::RectangleShape(tam)), ID(ID), pos(pos), tam(tam)
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

const IDs::IDs Jungle::Entidade::Entidade::getID() const{
    return ID;
}