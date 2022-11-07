#include "..\..\..\include\Entidade\Obstaculo\Obstaculo.hpp"

Jungle::Entidade::Obstaculo::Obstaculo::Obstaculo(const sf::Vector2f pos, const sf::Vector2f tam, const IDs::IDs ID, const char* caminhoTextura):
    Entidade(pos, tam, ID)
{
    textura = pGrafico->carregarTextura(caminhoTextura);
    corpo.setTexture(&textura);
}

Jungle::Entidade::Obstaculo::Obstaculo::~Obstaculo(){

}

void Jungle::Entidade::Obstaculo::Obstaculo::atualizar(){
    desenhar();
}