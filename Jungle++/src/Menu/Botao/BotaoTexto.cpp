#include "..\..\..\include\Menu\Botao\BotaoTexto.hpp"

namespace Jungle {

    namespace Menu {

        namespace Botao {

            BotaoTexto::BotaoTexto(const std::string info,  const sf::Vector2f tam, const sf::Vector2f pos, const IDs::IDs ID, const sf::Color corSelecionado):
                Botao(tam, pos, ID), corSelecionado(corSelecionado), 
                texto(pGrafico->carregarFonte(CAMINHO_FONTE), info), selecionado(false)
            {
                sf::Vector2f tamTexto = this->texto.getTam();
                sf::Vector2f posTexto = sf::Vector2f(
                    pos.x + tam.x / 2.0f - tamTexto.x / 2.05f,
                    pos.y + tam.y / 2.0f - tamTexto.y * 1.2f
                );
                this->texto.setPos(posTexto);
            }
            BotaoTexto::~BotaoTexto(){

            }

            const sf::Vector2f BotaoTexto::getTamTexto() const{
                return sf::Vector2f(texto.getTexto().getGlobalBounds().width, texto.getTexto().getGlobalBounds().height);
            }

            void BotaoTexto::desenhar(){
                atualizarTexto();
                pGrafico->desenhaElemento(texto.getTexto());
            }
            
            void BotaoTexto::atualizarTexto(){
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
                
            void BotaoTexto::setSelecionado(bool selecionado){
                texto.setCorTexto(selecionado ? corSelecionado : sf::Color::White);
                this->selecionado = selecionado;
                texto.resetar();
            }
            
            const bool BotaoTexto::getSelecionado() const{
                return selecionado;
            }

        }

    }

}