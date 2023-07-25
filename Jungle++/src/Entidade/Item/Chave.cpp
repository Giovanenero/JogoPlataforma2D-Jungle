#include "../../../include/Entidade/Item/Chave.hpp"
#include "../../../include/Entidade/Obstaculo/Porta.hpp"
#include "../../../include/Entidade/Personagem/Jogador/Jogador.hpp"

namespace Jungle {

    namespace Entidade {

        namespace Item {

            Chave::Chave(const sf::Vector2f pos, const sf::Vector2f tam):
                Entidade(tam, IDs::IDs::caixa, pos), animacao(&corpo), porta(nullptr),
                coletou(false)
            {
                animacao.addAnimacao("Jungle++/img/Item/chave.png", "CHAVE", 5, 0.3f, sf::Vector2f(1.2f, 1.2f), sf::Vector2f(tam.x / 4.0f, tam.y / 5.5f));
            }
            
            Chave::~Chave(){

            }
            
            void Chave::setPorta(Obstaculo::Porta* porta){
                this->porta = porta;
            }

            Obstaculo::Porta* Chave::getPorta(){
                return porta;
            }

            void Chave::setColetou(const bool coletou){
                this->coletou = coletou; 
            }

            const bool Chave::getColetou() const{
                return coletou;
            }

            void Chave::colisao(Entidade* outraEntidade, sf::Vector2f ds){
                //terminar...
                if(!coletou){
                    if(outraEntidade->getID() == IDs::IDs::jogador){
                        Personagem::Jogador::Jogador* pJogador = dynamic_cast<Personagem::Jogador::Jogador*>(outraEntidade);
                        pJogador->addChave(this);
                    }
                }
            }

            const std::string Chave::salvar(){
                //terminar...
                return "";
            }

            void Chave::atualizar(){
                animacao.atualizar(true, "CHAVE");
                desenhar();
            }

        }

    }

}