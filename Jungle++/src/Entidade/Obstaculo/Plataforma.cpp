#include "..\..\..\include\Entidade\Obstaculo\Plataforma.hpp"


Jungle::Entidade::Obstaculo::Plataforma::Plataforma(sf::Vector2f pos):
    Obstaculo(pos, sf::Vector2f(TAMANHO_PLATAFORMA_X, TAMANHO_PLATAFORMA_Y), IDs::IDs::plataforma, CAMINHO_TEXTURA_PLATAFORMA)
{
    //textura = pGrafico->carregarTextura(CAMINHO_TEXTURA_PLATAFORMA);
    //corpo.setTexture(&textura);
    //corpo.setFillColor(sf::Color::Green);
}

Jungle::Entidade::Obstaculo::Plataforma::~Plataforma(){

}

void Jungle::Entidade::Obstaculo::Plataforma::colisao(Entidade* outraEntidade, sf::Vector2f ds){
    sf::Vector2f posOutro = outraEntidade->getPos();
    sf::Vector2f tamOutro = outraEntidade->getTam();

    if(outraEntidade->getID() == IDs::IDs::jogador || outraEntidade->getID() == IDs::IDs::esqueleto ||
        outraEntidade->getID() == IDs::IDs::minotauro
    ){
        colisaoObstaculo(ds, static_cast<Personagem::Personagem*>(outraEntidade));
    }
}