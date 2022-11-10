#include "..\..\include\Parallax\Camada.hpp"

Jungle::Parallax::Camada::Camada(const sf::Vector2f tamJanela, sf::Texture textura)
{
    fundo.setScale(tamJanela);
    fundo.setTexture(textura);
    fundo.setPosition(sf::Vector2f(0.0f, 0.0f));

    fundoAuxiliar.setScale(tamJanela);
    fundoAuxiliar.setTexture(textura);
    fundoAuxiliar.setPosition(tamJanela.x, 0.0f);
}

Jungle::Parallax::Camada::~Camada(){

}

void Jungle::Parallax::Camada::atualizar(const sf::Vector2f ds){
    
    sf::Vector2f posFundo = fundo.getPosition();

    if(posFundo.x)

    if(ds.x > 0.0f){
        //rola a sprite para a esquerda
        
    } else {

    }
}