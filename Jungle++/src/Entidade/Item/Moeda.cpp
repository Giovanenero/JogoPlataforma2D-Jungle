#include "..\..\..\include\Entidade\Item\Moeda.hpp"
#include "../../../include/Entidade/Personagem/Jogador/Jogador.hpp"

namespace Jungle {

    namespace Entidade {

        namespace Item {

            Moeda::Moeda(const sf::Vector2f pos, std::string tipo):
                Entidade(sf::Vector2f(TAMANHO_MOEDA, TAMANHO_MOEDA), IDs::IDs::moeda_amarela, pos),
                tipo(tipo), pontos(tipo == "MOEDA_AMARELA" ? PONTOS_MOEDA_AMARELA : PONTOS_MOEDA_CINZA),
                animacao(&corpo)
            {
                inicializarAnimacao();
            }

            Moeda::~Moeda(){

            }

            void Moeda::inicializarAnimacao(){
                animacao.addAnimacao(tipo == "MOEDA_AMARELA" ? CAMINHO_MOEDA_AMARELA : CAMINHO_MOEDA_CINZA, tipo, 8, 0.12f, sf::Vector2f(1.0f, 1.0f));
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