#include "../../../include/Menu/Botao/Botao.hpp"

namespace Jungle {

    namespace Menu {

        namespace Botao {

            Botao::Botao(const sf::Vector2f tam, const sf::Vector2f pos, const IDs::IDs ID, const float tempoTroca, const sf::Vector2f tamMax):
                Ente(ID), pos(pos), tam(tam), textura(new sf::Texture()), tamMax(tamMax == sf::Vector2f(0.0f, 0.0f) ? tam : tamMax),
                tempoTroca(tempoTroca), tempo(0.0f), tamInicial(tam), aumentando(true)
            {
                caixa.setPosition(pos);
                caixa.setSize(tam);
            }

            Botao::~Botao(){
                if(textura){
                    delete(textura);
                    textura = nullptr;
                }
            }

            void Botao::atualizarPosicaoCaixa(const sf::Vector2f pos){
                this->pos = pos;
                caixa.setPosition(pos);
            }

            const sf::Vector2f Botao::getPos() const{
                return caixa.getPosition();
            }

            void Botao::setTextura(sf::Texture* textura){
                this->textura = textura;
                caixa.setTexture(textura);
            }

            void Botao::desenhar(){
                pGrafico->desenhaElemento(caixa);
            }

            void Botao::atualizarAnimacao(){
                this->tempo += pGrafico->getTempo();
                if(this->tempo < tempoTroca){
                    const float acres = tempo * (aumentando ? 1 : -1);
                    tam = sf::Vector2f(tam.x + acres, tam.y + acres);
                    if(tam.x > tamMax.x || tam.x < tamInicial.x){
                        aumentando = !aumentando;
                    } else {
                        caixa.setSize(tam);
                    }
                } else {
                    this->tempo = 0.0f;
                }
            }

        }

    }

}