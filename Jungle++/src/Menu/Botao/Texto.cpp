#include "../../../include/Menu/Botao/Texto.hpp"

namespace Jungle {

    namespace Menu {

        namespace Botao {

            Texto::Texto(const sf::Font fonte, const std::string info, const unsigned int tamFonte):
                fonte(fonte), texto(), info(info), corTexto(sf::Color::White),
                corBorda(sf::Color::Black), tamFonte(tamFonte)
            {
                inicializa();
            }

            Texto::~Texto(){

            }

            void Texto::inicializa(){
                texto.setString(info);
                texto.setCharacterSize(tamFonte);
                texto.setFont(fonte);
                texto.setOutlineThickness(5.0f);
                texto.setOutlineColor(corBorda);
                texto.setFillColor(corTexto);
                tam = sf::Vector2f(texto.getGlobalBounds().width, texto.getGlobalBounds().height);
            }

            void Texto::setCorTexto(const sf::Color corTexto){
                this->corTexto = corTexto;
                texto.setFillColor(corTexto);
            }

            const sf::Text Texto::getTexto() const{
                return texto;
            }

            void Texto::setPos(const sf::Vector2f pos){
                this->pos = pos;
                texto.setPosition(pos);
            }

            const sf::Vector2f Texto::getPos() const{
                return pos;
            }

            const sf::Vector2f Texto::getTam() const{
                return tam;
            }

            void Texto::setTamanhoBorda(const float tamBorda){
                texto.setOutlineThickness(tamBorda);
                tam = sf::Vector2f(texto.getGlobalBounds().width, texto.getGlobalBounds().height);
            }

            void Texto::setEspacamento(const float tamEspaco){
                texto.setLetterSpacing(tamEspaco);
                tam = sf::Vector2f(texto.getGlobalBounds().width, texto.getGlobalBounds().height);
            }

            void Texto::setString(std::string nome){
                texto.setString(nome);
                tam = sf::Vector2f(texto.getGlobalBounds().width, texto.getGlobalBounds().height);
            }

            const std::string Texto::getString() const {
                return texto.getString();
            }
            
            void Texto::setTamFonte(const unsigned int tamFonte){
                texto.setCharacterSize(tamFonte);
                tam = sf::Vector2f(texto.getGlobalBounds().width, texto.getGlobalBounds().height);
            }

        }

    }

}