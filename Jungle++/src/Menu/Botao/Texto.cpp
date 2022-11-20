#include "..\..\..\include\Menu\Botao\Texto.hpp"

namespace Jungle {

    namespace Menu {

        namespace Botao {

            Texto::Texto(sf::Font fonte, const std::string texto):
                fonte(fonte), texto()
            {
                this->texto.setString(texto);
                inicializa();
            }

            Texto::~Texto(){

            }

            void Texto::inicializa(){
                texto.setFont(fonte);
            }

            void Texto::setString(const std::string texto){
                this->texto.setString(texto);
            }

            const std::string Texto::getString(){
                return texto.getString();
            }

            sf::Text Texto::getTexto(){
                return texto;
            }

        }

    }

}