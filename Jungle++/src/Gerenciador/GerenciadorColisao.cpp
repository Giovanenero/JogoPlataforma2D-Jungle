#include "../../include/Gerenciador/GerenciadorColisao.hpp"

namespace Jungle {

    namespace Gerenciador {

        GerenciadorColisao::GerenciadorColisao(Lista::ListaEntidade* listaPersonagem, Lista::ListaEntidade* listaObstaculo):
            listaPersonagem(listaPersonagem), listaObstaculo(listaObstaculo)
        {

        }

        GerenciadorColisao::~GerenciadorColisao(){
            //a lista de entidade é deletado na fase
        }

        const sf::Vector2f GerenciadorColisao::calculaColisao(Entidade::Entidade* ent1, Entidade::Entidade* ent2){
            sf::Vector2f pos1 = ent1->getPos();
            sf::Vector2f pos2 = ent2->getPos();

            sf::Vector2f tam1 = ent1->getTam();
            sf::Vector2f tam2 = ent2->getTam();
            
            sf::Vector2f distanciaEntreCentros(
                fabs((pos1.x + tam1.x/2.0f) - (pos2.x + tam2.x/2.0f)),
                fabs((pos1.y + tam1.y/2.0f) - (pos2.y + tam2.y/2.0f))
            );
            sf::Vector2f somaMetadeRectangulo(tam1.x/2.0f + tam2.x/2.0f, tam1.y/2.0f + tam2.y/2.0f);
            return sf::Vector2f(distanciaEntreCentros.x - somaMetadeRectangulo.x, distanciaEntreCentros.y - somaMetadeRectangulo.y);
        }

        void GerenciadorColisao::executar(){
            //verifica colisao entre Personagens e Personagens e Obstáculos 
            for(int i = 0; i < listaPersonagem->getTam() - 1; i++){
                Entidade::Entidade* ent1 = listaPersonagem->operator[](i);
                for(int j = i + 1; j < listaPersonagem->getTam(); j++){
                    Entidade::Entidade* ent2 = listaPersonagem->operator[](j);
                    sf::Vector2f ds = calculaColisao(ent1, ent2);
                    if(ds.x < 0.0f && ds.y < 0.0f){
                        ent1->colisao(ent2, ds);
                    }
                }
            }

            //verifica colisao entre Personagens e Obstáculos 
            for(int i = 0; i < listaPersonagem->getTam(); i++){
                Entidade::Entidade* ent1 = listaPersonagem->operator[](i);
                for(int j = 0; j < listaObstaculo->getTam(); j++){
                    Entidade::Entidade* ent2 = listaObstaculo->operator[](j);
                    sf::Vector2f ds = calculaColisao(ent1, ent2);
                    if(ds.x < 0.0f && ds.y < 0.0f){
                        /*
                        if(
                            ent2->getID() == IDs::IDs::plataforma_movel ||
                            ent2->getID() == IDs::IDs::plataforma       || 
                            ent2->getID() == IDs::IDs::caixa            ||
                        ){
                            ent2->colisao(ent1, ds);
                        } else {
                            // outro obstáculo 
                        }
                        */
                       ent2->colisao(ent1, ds);
                    }
                }
            }

            //verifica colisao entre Obstáculos 
            /*
            for(int i = 0; i < listaObstaculo->getTam(); i++){
                Entidade::Entidade* ent1 = listaObstaculo->operator[](i);
                for(int j = i + 1; j < listaObstaculo->getTam(); j++){
                    Entidade::Entidade* ent2 = listaObstaculo->operator[](j);
                    sf::Vector2f ds = calculaColisao(ent1, ent2);
                    if(ds.x < 0.0f && ds.y < 0.0f){
                        ent2->colisao(ent1, ds);
                    }
                }
            }
            */
        }

    }

}
