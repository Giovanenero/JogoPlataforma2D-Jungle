#include "../../include/Entidade/Entidade.hpp"

namespace Jungle {

    namespace Entidade {

        Entidade::Entidade(const sf::Vector2f tam, const IDs::IDs ID, const sf::Vector2f pos):
            Ente(ID), corpo(sf::RectangleShape(tam)), pos(pos), tam(tam), podeRemover(false)
        {
            corpo.setPosition(pos);
        }

        Entidade::~Entidade(){
            
        }

        const std::string Entidade::salvarEntidade(){
            std::string linha = salvarEnte();
            linha += std::to_string(pos.x) + ' ';
            linha += std::to_string(pos.y) + ' ';
            linha += std::to_string(tam.x) + ' ';
            linha += std::to_string(tam.y) + ' ';
            return linha;
        }

        const sf::RectangleShape Entidade::getCorpo() const{
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

        const sf::Vector2f Entidade::getPos() const{
            return pos;
        }

        const sf::Vector2f Entidade::getTam() const{
            return tam;
        }

        const bool Entidade::getRemover() const {
            return podeRemover;
        }

        void Entidade::remover(){
            podeRemover = true;
        }

        void Entidade::desenhar(){
            pGrafico->desenhaElemento(corpo);
        }

    }

}