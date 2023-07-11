#include "../../../include/Entidade/Item/Projetil.hpp"

namespace Jungle {

    namespace Entidade {

        namespace Item {

            Projetil::Projetil(Personagem::Personagem* personagem):
                Arma(IDs::IDs::projetil_inimigo, personagem), animacao(&corpo),
                velocidade(sf::Vector2f(0.0f, 0.0f)), colidiu(true), paraEsquerda(false)
            {
                if(personagem != nullptr){
                    inicializarAnimacao();
                }
            }

            Projetil::~Projetil(){

            }

            void Projetil::inicializarAnimacao(){
                if(personagem != nullptr){
                    setTam(sf::Vector2f(TAMANHO_PROJETIL, TAMANHO_PROJETIL));
                    switch (personagem->getID())
                    {
                        case (IDs::IDs::alma):
                        {
                            animacao.addAnimacao("Jungle++/img/Personagem/Inimigo/Alma/ProjetilAlma.png" , "ATACA", 4, 0.12f, sf::Vector2f(5.0f, 5.0f), sf::Vector2f(tam.x / 2.0f, tam.y / 2.2f), false);
                        }
                            break;
                    }
                }
            }

            void Projetil::setVelocidade(const sf::Vector2f velocidade){
                this->velocidade = velocidade;
            }

            void Projetil::setColidiu(const bool colidiu){
                this->colidiu = colidiu;
                if(colidiu){
                    setPos(sf::Vector2f(-1000.0f, -1000.0f));
                    velocidade = sf::Vector2f(0.0f, 0.0f);
                }
            }

            const bool Projetil::getColidiu() const{
                return colidiu;
            }

            void Projetil::setSentido(const bool paraEsquerda){
                this->paraEsquerda = paraEsquerda;
                velocidade = paraEsquerda ? sf::Vector2f(velocidade.x * -1, velocidade.y) : velocidade;
            }

            void Projetil::atualizarPosicao(){
                const float tempo = pGrafico->getTempo();
                sf::Vector2f posFinal(0.0f, 0.0f);

                //MRU
                posFinal.x = pos.x + velocidade.x * tempo;

                //MRUV
                posFinal.y = pos.y + velocidade.y * tempo + (-GRAVIDADE * (tempo * tempo))/2;

                setPos(posFinal);

                sf::Vector2f posCentro = pGrafico->getCamera().getCenter();
                sf::Vector2f tamJanela = pGrafico->getTamJanela();
                if(pos.x < posCentro.x - tamJanela.x / 2.0f || pos.x > posCentro.x + tamJanela.x / 2.0f ||
                    pos.y < posCentro.y - tamJanela.y / 2.0f || pos.y > posCentro.y + tamJanela.y / 2.0f
                ){
                    setVelocidade(sf::Vector2f(0.0f, 0.0f));
                    setColidiu(true);
                }
            }

            void Projetil::atualizarAnimacao(){
               animacao.atualizar(paraEsquerda, "ATACA");
            }

            void Projetil::desenhar(){
                pGrafico->desenhaElemento(corpo);
            }

            void Projetil::atualizar(){
                if(!colidiu){
                    atualizarPosicao();
                    atualizarAnimacao();
                    desenhar();
                }
            }

        }

    }
    
}