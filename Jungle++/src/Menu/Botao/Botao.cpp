#include "..\..\..\include\Menu\Botao\Botao.hpp"

namespace Jungle {

    namespace Menu {

        namespace Botao {

            Botao::Botao(const std::string texto, const sf::Vector2f tam,const sf::Vector2f pos):
                Ente(IDs::IDs::botao), caixaTexto(pGrafico->carregarFonte(CAMINHO_FONTE), texto),
                selecionado(false), pos(pos), tam(tam), relogio(),
                tempoTrocaCor(0.02f), tempo(0.0f)
            {
                caixa.setPosition(pos);
                caixa.setSize(tam);
                sf::Vector2f tamTexto = caixaTexto.getTam();
                sf::Vector2f posTexto = sf::Vector2f(
                    pos.x + tam.x / 2.0f - tamTexto.x / 2.0f,
                    pos.y + tam.y / 2.0f - tamTexto.y * 1.5f
                );
                caixaTexto.setPos(posTexto);
                caixa.setFillColor(sf::Color::Transparent);
            }

            Botao::~Botao(){

            }

            void Botao::setSelecionado(const bool selecionado){
                this->selecionado = selecionado;
            }

            void Botao::atualizarTexto(){
                const float dt = relogio.getElapsedTime().asSeconds();
                relogio.restart();
                tempo += dt;
                if(selecionado){
                    if(tempo > tempoTrocaCor){
                        int transparente = caixaTexto.getTransparente();
                        if(caixaTexto.getClareando()){
                            //texto clareando
                            transparente += 5;
                            if(transparente > 255){
                                transparente = 255;
                                caixaTexto.mudarClareando();
                            }
                        } else {
                            //texto escurecendo
                            transparente -= 5;
                            if(transparente < 0){
                                transparente = 0;
                                caixaTexto.mudarClareando();
                            }
                        }
                        caixaTexto.setTransparente(transparente);
                        tempo = 0.0f;
                    }
                } else {
                    tempo = 0.0f;
                }
            }

            void Botao::desenhar(){
                atualizarTexto();
                pGrafico->desenhaElemento(caixa);
                pGrafico->desenhaElemento(caixaTexto.getTexto());
            }

        }

    }

}