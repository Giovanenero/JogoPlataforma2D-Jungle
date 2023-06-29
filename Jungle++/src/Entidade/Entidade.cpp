#include "..\..\include\Entidade\Entidade.hpp"

namespace Jungle {

    namespace Entidade {

        Entidade::Entidade(const sf::Vector2f tam, const IDs::IDs ID, const sf::Vector2f pos):
            Ente(ID), corpo(sf::RectangleShape(tam)), pos(pos), tam(tam), podeRemover(false)
        {
            corpo.setPosition(pos);
        }

        Entidade::~Entidade(){
            
        }

        const sf::RectangleShape Entidade::getCorpo(){
            return corpo;
        }

        void Entidade::setPos(const sf::Vector2f pos){
            corpo.setPosition(pos);
            this->pos = pos;
        }

        void Entidade::setTam(const sf::Vector2f tam){
            corpo.setSize(tam);
            this->tam = tam;
        }

        sf::Vector2f Entidade::getPos(){
            return pos;
        }

        const sf::Vector2f Entidade::getTam(){
            return tam;
        }

        const bool Entidade::getRemover() const {
            return podeRemover;
        }

        void Entidade::desenhar(){
            pGrafico->desenhaElemento(corpo);
        }

    }

}