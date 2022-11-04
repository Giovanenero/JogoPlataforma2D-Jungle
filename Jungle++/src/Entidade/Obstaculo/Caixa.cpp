#include "..\..\..\include\Entidade\Obstaculo\Caixa.hpp"

Jungle::Entidade::Obstaculo::Caixa::Caixa(sf::Vector2f pos, sf::Vector2f tam):
    Obstaculo(pos, tam, IDs::IDs::caixa), podeEmpurrar(false)
{
    //terminar...
}

Jungle::Entidade::Obstaculo::Caixa::~Caixa(){

}

void Jungle::Entidade::Obstaculo::Caixa::colisao(Entidade* outraEntidade, sf::Vector2f ds){

}

void Jungle::Entidade::Obstaculo::Caixa::atualizar(){

}