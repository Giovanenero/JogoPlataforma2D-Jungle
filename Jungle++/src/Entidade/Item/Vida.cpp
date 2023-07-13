#include "../../../include/Entidade/Item/Vida.hpp"

namespace Jungle {

    namespace Entidade {

        namespace Item {

            Vida::Vida(const sf::Vector2f pos):
                Entidade(sf::Vector2f(TAMANHO_VIDA, TAMANHO_VIDA), IDs::IDs::vida, pos), animacao(&corpo)
            {
                srand(time(NULL));
                vida = rand()%VIDA_MAXIMA + VIDA_MINIMA; 
                if(vida < 50.0f){
                    setTam(sf::Vector2f(TAMANHO_VIDA / 1.7f , TAMANHO_VIDA / 1.7f));
                }
                inicializarAnimacao();
            }

            Vida::~Vida(){

            }

            void Vida::inicializarAnimacao(){
                animacao.addAnimacao("Jungle++/img/Item/vida.png", "VIDA", 3, 0.20f, sf::Vector2f(1.0f, 1.0f));
            }
            
            void Vida::atualizarAnimacao(){
                animacao.atualizar(true, "VIDA");
            }

            void Vida::colisao(Entidade* outraEntidade, sf::Vector2f ds){
                const IDs::IDs ID_Outro = outraEntidade->getID();
                if(ID_Outro == IDs::IDs::jogador){
                    Personagem::Jogador::Jogador* jogador = dynamic_cast<Personagem::Jogador::Jogador*>(outraEntidade);
                    jogador->setVida(vida);
                    podeRemover = true;
                }
            }

            const std::string Vida::salvar(){
                std::string linha = "";
                //salvando atributos da entidade
                linha += std::to_string(static_cast<int>(ID)) + ' ';
                linha += std::to_string(pos.x) + ' ';
                linha += std::to_string(pos.y) + ' ';
                linha += std::to_string(tam.x) + ' ';
                linha += std::to_string(tam.y) + ' ';
                //salvando atributos da vida
                linha += std::to_string(vida);
                return linha;
            }

            void Vida::atualizar(){
                atualizarAnimacao();

                desenhar();
            }

            const float Vida::getVida() const{
                return vida;
            }

        }

    }

}