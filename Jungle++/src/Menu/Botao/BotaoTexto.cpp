#include "../../../include/Menu/Botao/BotaoTexto.hpp"

namespace Jungle {

    namespace Menu {

        namespace Botao {

            BotaoTexto::BotaoTexto(const std::string info,  const sf::Vector2f tam, const sf::Vector2f pos, const IDs::IDs ID, const sf::Color corSelecionado):
                Botao(tam, pos, ID, TEMPO_TROCAR_COR), corSelecionado(corSelecionado), 
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
                atualizarAnimacao();
                pGrafico->desenhaElemento(texto.getTexto());
            }
            
            void BotaoTexto::atualizarAnimacao(){
                this->tempo += pGrafico->getTempo();
                if(selecionado){
                    if(this->tempo > tempoTroca){
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
                        this->tempo = 0.0f;
                    }
                } else {
                    this->tempo = 0.0f;
                }
            }

            void BotaoTexto::atualizarPosicaoCaixa(const sf::Vector2f pos){
                this->pos = pos;
                caixa.setPosition(pos);
                sf::Vector2f tamTexto = this->texto.getTam();
                sf::Vector2f posTexto = sf::Vector2f(
                    pos.x + tam.x / 2.0f - tamTexto.x / 2.05f,
                    pos.y + tam.y / 2.0f - tamTexto.y * 1.2f
                );
                this->texto.setPos(posTexto);
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