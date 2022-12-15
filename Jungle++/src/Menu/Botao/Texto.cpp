#include "..\..\..\include\Menu\Botao\Texto.hpp"

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
                texto.setOutlineThickness(5);
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
                texto.setPosition(pos);
            }

            sf::Vector2f Texto::getTam(){
                return tam;
            }

        }

    }

}