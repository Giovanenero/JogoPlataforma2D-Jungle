#include "..\..\..\include\Menu\Botao\Botao.hpp"

namespace Jungle {

    namespace Menu {

        namespace Botao {

            Botao::Botao(const std::string info, const sf::Vector2f tam, const sf::Vector2f pos, const IDs::IDs ID, const sf::Color corSelecionado):
                Ente(ID), texto(pGrafico->carregarFonte(CAMINHO_FONTE), info), 
                selecionado(false), pos(pos), tam(tam), relogio(),
                tempoTrocaCor(TEMPO_TROCAR_COR), tempo(0.0f), corSelecionado(corSelecionado)
            {
                caixaTexto.setPosition(pos);
                caixaTexto.setSize(tam);
                sf::Vector2f tamTexto = this->texto.getTam();
                sf::Vector2f posTexto = sf::Vector2f(
                    pos.x + tam.x / 2.0f - tamTexto.x / 2.05f,
                    pos.y + tam.y / 2.0f - tamTexto.y * 1.2f
                );
                this->texto.setPos(posTexto);
                //arrumar
                caixaTexto.setFillColor(sf::Color::Transparent);
            }

            Botao::~Botao(){

            }

            void Botao::setSelecionado(const bool selecionado){
                texto.setCorTexto(selecionado ? corSelecionado : sf::Color::White);
                this->selecionado = selecionado;
                texto.resetar();
            }

            const bool Botao::getSelecionado() const{
                return selecionado;
            }

            void Botao::atualizarTexto(){
                const float dt = relogio.getElapsedTime().asSeconds();
                relogio.restart();
                tempo += dt;
                if(selecionado){
                    if(tempo > tempoTrocaCor){
                        int transparente = texto.getTransparente();
                        if(texto.getClareando()){
                            //texto clareando
                            transparente += 5;
                            if(transparente > 255){
                                transparente = 255;
                                texto.mudarClareando();
                            }
                        } else {
                            //texto escurecendo
                            transparente -= 5;
                            if(transparente < 0){
                                transparente = 0;
                                texto.mudarClareando();
                            }
                        }
                        texto.setTransparente(transparente);
                        tempo = 0.0f;
                    }
                } else {
                    tempo = 0.0f;
                }
            }

            void Botao::atualizarPosicao(const sf::Vector2f pos){
                this->pos = pos;
                caixaTexto.setPosition(pos);
                sf::Vector2f tamTexto = this->texto.getTam();
                sf::Vector2f posTexto = sf::Vector2f(
                    pos.x + tam.x / 2.0f - tamTexto.x / 2.05f,
                    pos.y + tam.y / 2.0f - tamTexto.y * 1.2f
                );
                this->texto.setPos(posTexto);
            }

            const sf::Vector2f Botao::getPos() const{
                return caixaTexto.getPosition();
            }

            const sf::Vector2f Botao::getTamTexto() const{
                return sf::Vector2f(texto.getTexto().getGlobalBounds().width, texto.getTexto().getGlobalBounds().height);
            }

            void Botao::desenhar(){
                atualizarTexto();
                //pGrafico->desenhaElemento(caixaTexto);
                pGrafico->desenhaElemento(texto.getTexto());
            }

        }

    }

}