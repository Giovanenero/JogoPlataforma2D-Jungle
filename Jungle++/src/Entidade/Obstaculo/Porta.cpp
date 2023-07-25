#include "../../../include/Entidade/Obstaculo/Porta.hpp"

namespace Jungle {

    namespace Entidade {

        namespace Obstaculo {

            Porta::Porta(const sf::Vector2f pos, const sf::Vector2f tam, Item::Chave* chave):
                Obstaculo(pos, tam, IDs::IDs::porta), animacao(&corpo), tempoAbrindo(0.0f),
                fechada(false), abrindo(true), chave(chave)
            {
                inicializarAnimacao();
            }

            Porta::~Porta(){

            }

            void Porta::inicializarAnimacao(){
                sf::Vector2f origin(0.0f, -10.0f);
                animacao.addAnimacao("Jungle++/img/Obstaculo/Porta/portaAbrindo.png", "PORTA_ABRINDO", 14, 0.10f, sf::Vector2f(1.0f, 1.0f), origin);
                animacao.addAnimacao("Jungle++/img/Obstaculo/Porta/portaAberta.png", "PORTA_ABERTA", 1, 1.0f, sf::Vector2f(1.0f, 1.0f), origin);
                animacao.addAnimacao("Jungle++/img/Obstaculo/Porta/portaFechada.png", "PORTA_FECHADA", 1, 1.0f, sf::Vector2f(1.0f, 1.0f), origin);
            }

            void Porta::atualizarAnimacao(){
                if(fechada){
                    animacao.atualizar(true, "PORTA_FECHADA");
                } else if(abrindo){
                    tempoAbrindo += pGrafico->getTempo();
                    animacao.atualizar(true, "PORTA_ABRINDO");
                    if(tempoAbrindo > TEMPO_PORTA_ABRINDO){
                        tempoAbrindo = 0.0f;
                        abrindo = false;
                    }
                } else {
                    animacao.atualizar(true, "PORTA_ABERTA");
                }
            }

            Item::Chave* Porta::getChave(){
                return chave;
            }

            void Porta::colisao(Entidade* outraEntidade, sf::Vector2f ds){
                //terminar...
            }
            
            void Porta::atualizar(){
                atualizarAnimacao();
                desenhar();
            }

        }

    }

}