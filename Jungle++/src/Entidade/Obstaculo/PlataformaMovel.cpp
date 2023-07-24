#include "../../../include/Entidade/Obstaculo/PlataformaMovel.hpp"
#include "../../../include/Entidade/Item/Projetil.hpp"

namespace Jungle {

    namespace Entidade {

        namespace Obstaculo {

            PlataformaMovel::PlataformaMovel(const IDs::IDs ID, const sf::Vector2f pos, const float distancia, const sf::Vector2f tam, const bool ehFlutuante, const bool horizontal):
                Plataforma(ID, pos, tam, ehFlutuante), horizontal(horizontal), posFinal(pos.x + distancia),
                posInicial(pos.x), paraEsquerda(pos.x > posFinal), paraBaixo(pos.y > posFinal),
                velocidade(sf::Vector2f(VELOCIDADE_PLATAFORMA, VELOCIDADE_PLATAFORMA)), tempo(0.0f),
                ds(sf::Vector2f(0.0f, 0.0f))
            {

            }
            
            PlataformaMovel::~PlataformaMovel(){

            }

            void PlataformaMovel::inicializarAnimacao(){
                textura = pGrafico->carregarTextura(CAMINHO_TEXTURA_PLATAFORMA_FLUTUANTE);
                corpo.setTexture(&textura);
            }

            void PlataformaMovel::atualizarPosicao(){
                if(horizontal){
                    if(pos.x >= posFinal || pos.x <= posInicial){
                        paraEsquerda = !paraEsquerda;
                    }
                    ds = sf::Vector2f((paraEsquerda ? -velocidade.x : velocidade.x) * tempo, 0.0f);
                } else {
                    if(pos.y >= posFinal || pos.y <= posInicial){
                        paraBaixo = !paraBaixo;
                    }
                    ds = sf::Vector2f(0.0f, (paraBaixo ? -velocidade.y : velocidade.y) * tempo);
                }
                setPos(pos + ds);
            }

            void PlataformaMovel::colisao(Entidade* outraEntidade, sf::Vector2f ds){
                if(outraEntidade->getID() == IDs::IDs::jogador){
                    colisaoObstaculo(ds, static_cast<Personagem::Personagem*>(outraEntidade));
                    Personagem::Jogador::Jogador* pJogador = dynamic_cast<Personagem::Jogador::Jogador*>(outraEntidade);
                    if(!pJogador->getAndando()){
                        pJogador->setPos(pJogador->getPos() + this->ds);
                    }
                    //faz outra coisa
                } else if(
                    outraEntidade->getID() == IDs::IDs::esqueleto   ||
                    outraEntidade->getID() == IDs::IDs::minotauro   || 
                    outraEntidade->getID() == IDs::IDs::alma
                ){
                    colisaoObstaculo(ds, static_cast<Personagem::Personagem*>(outraEntidade));
                } else if(outraEntidade->getID() == IDs::IDs::projetil_inimigo){
                    Item::Projetil* projetil = dynamic_cast<Item::Projetil*>(outraEntidade);
                    projetil->setColidiu(true);
                    projetil->setVelocidade(sf::Vector2f(0.0f, 0.0f));
                }
            }
            
            void PlataformaMovel::atualizar(){
                tempo = pGrafico->getTempo();
                atualizarPosicao();
                desenhar();
            }

        }

    }

}