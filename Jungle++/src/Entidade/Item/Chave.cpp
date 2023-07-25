#include "../../../include/Entidade/Item/Chave.hpp"
#include "../../../include/Entidade/Obstaculo/Porta.hpp"

namespace Jungle {

    namespace Entidade {

        namespace Item {

            Chave::Chave(const sf::Vector2f pos, const sf::Vector2f tam):
                Entidade(tam, IDs::IDs::caixa, pos), animacao(&corpo), porta(nullptr)
            {
                animacao.addAnimacao("Jungle++/img/Item/chave.png", "CHAVE", 5, 0.3f, sf::Vector2f(1.0f, 1.0f));
            }
            
            Chave::~Chave(){

            }
            
            void Chave::setPorta(Obstaculo::Porta* porta){
                this->porta = porta;
            }

            Obstaculo::Porta* Chave::getPorta(){
                return porta;
            }

            void Chave::colisao(Entidade* outraEntidade, sf::Vector2f ds){
                //terminar...
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