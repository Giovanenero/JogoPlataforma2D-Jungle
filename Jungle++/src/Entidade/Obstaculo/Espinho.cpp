#include "../../../include/Entidade/Obstaculo/Espinho.hpp"

namespace Jungle {

    namespace Entidade {

        namespace Obstaculo {

            Espinho::Espinho(const sf::Vector2f pos, const sf::Vector2f tam):
                Obstaculo(pos, tam, IDs::IDs::espinho), dano(DANO_ESPINHO_PADRAO)
            {
                inicializarAnimacao();
            }
            
            Espinho::~Espinho(){

            }

            void Espinho::inicializarAnimacao(){
                textura = pGrafico->carregarTextura(CAMINHO_TEXTURA_ESPINHO);
                corpo.setTexture(&textura);
            }
            
            void Espinho::setDano(const float dano){
                this->dano = dano;
            }
            
            const float Espinho::getDano() const {
                return dano;
            }

            void Espinho::colisao(Entidade* outraEntidade, sf::Vector2f ds){
                if(outraEntidade->getID() == IDs::IDs::jogador){
                    Personagem::Jogador::Jogador* pJogador = dynamic_cast<Personagem::Jogador::Jogador*>(outraEntidade);
                    pJogador->tomarDano(dano);
                }
            }

            const std::string Espinho::salvar(){
                std::string linha = "";
                //salvando atributos da entidade
                linha += std::to_string(static_cast<int>(ID)) + ' ';
                linha += std::to_string(pos.x) + ' ';
                linha += std::to_string(pos.y) + ' ';
                linha += std::to_string(tam.x) + ' ';
                linha += std::to_string(tam.y) + ' ';
                //salvando atributos do espinho
                linha += std::to_string(dano);
                return linha;
            }

        }

    }

}