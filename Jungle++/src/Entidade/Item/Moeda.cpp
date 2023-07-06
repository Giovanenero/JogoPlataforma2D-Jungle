#include "../../../include/Entidade/Item/Moeda.hpp"
#include "../../../include/Entidade/Personagem/Jogador/Jogador.hpp"

namespace Jungle {

    namespace Entidade {

        namespace Item {

            Moeda::Moeda(const sf::Vector2f pos, const IDs::IDs ID):
                Entidade(sf::Vector2f(TAMANHO_MOEDA, TAMANHO_MOEDA), ID, pos), 
                pontos(ID == IDs::IDs::moeda_amarela ? PONTOS_MOEDA_AMARELA : PONTOS_MOEDA_CINZA),
                animacao(&corpo), tipo(ID == IDs::IDs::moeda_amarela ? "MOEDA_AMARELA" : "MOEDA_CINZA")
            {
                inicializarAnimacao();
            }

            Moeda::~Moeda(){

            }

            void Moeda::inicializarAnimacao(){
                const char* caminhoTextura = ID == IDs::IDs::moeda_amarela ? CAMINHO_MOEDA_AMARELA : CAMINHO_MOEDA_CINZA; 
                animacao.addAnimacao(caminhoTextura , tipo, 8, 0.12f, sf::Vector2f(1.0f, 1.0f));
            }

            void Moeda::colisao(Entidade* outraEntidade, sf::Vector2f ds){
                if(outraEntidade->getID() == IDs::IDs::jogador){
                    Personagem::Jogador::Jogador* pJogador = dynamic_cast<Personagem::Jogador::Jogador*>(outraEntidade);
                    pJogador->addPontuacao(pontos);
                    podeRemover = true;
                }
            }

            void Moeda::atualizar(){
                animacao.atualizar(false, tipo);
                desenhar();
            }

        }

    }

}