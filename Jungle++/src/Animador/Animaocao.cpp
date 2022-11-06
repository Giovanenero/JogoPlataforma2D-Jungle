#include "..\..\include\Animador\Animacao.hpp"

Jungle::Animador::Animacao::Animacao(sf::RectangleShape* corpo):
    pGrafico(pGrafico->getGerenciadorGrafico()), corpo(corpo), mapTextura()
{

}

Jungle::Animador::Animacao::~Animacao(){

}

void Jungle::Animador::Animacao::atualizar(){
    //atualizar animacao;
}