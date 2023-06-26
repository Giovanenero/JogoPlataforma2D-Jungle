#include "..\..\..\include\Menu\Botao\Botao.hpp"

namespace Jungle {

    namespace Menu {

        namespace Botao {

            Botao::Botao(const sf::Vector2f tam, const sf::Vector2f pos, const IDs::IDs ID):
                Ente(ID), pos(pos), tam(tam), relogio(),
                tempoTrocaCor(TEMPO_TROCAR_COR), tempo(0.0f)
            {
                caixa.setPosition(pos);
                caixa.setSize(tam);
                caixa.setFillColor(sf::Color::Transparent);
            }

            Botao::~Botao(){

            }

            void Botao::atualizarPosicaoCaixa(const sf::Vector2f pos){
                this->pos = pos;
                caixa.setPosition(pos);
                /*
                sf::Vector2f tamTexto = this->texto.getTam();
                sf::Vector2f posTexto = sf::Vector2f(
                    pos.x + tam.x / 2.0f - tamTexto.x / 2.05f,
                    pos.y + tam.y / 2.0f - tamTexto.y * 1.2f
                );
                this->texto.setPos(posTexto);
                */
            }

            const sf::Vector2f Botao::getPos() const{
                return caixa.getPosition();
            }

        }

    }

}