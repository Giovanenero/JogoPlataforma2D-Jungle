#include "../../include/Construtor/ConstrutorEntidade.hpp"
#include "../../include/Fase/Fase.hpp"

namespace Jungle {

    namespace Construtor {

        ConstrutorEntidade::ConstrutorEntidade(Entidade::Personagem::Jogador::Jogador* pJogador):
            pJogador(pJogador)
        {

        }

        ConstrutorEntidade::ConstrutorEntidade():
            pJogador(nullptr)
        {

        }

        ConstrutorEntidade::~ConstrutorEntidade(){

        }

        void ConstrutorEntidade::verificaJogador(){
            if(pJogador == nullptr){
                throw "ERROR::Jungle::Construtor::ConctrutorEntidade::pJogador eh nullptr";
            }
        }

        Entidade::Entidade* ConstrutorEntidade::criarPlataforma(const sf::Vector2f pos){
            Entidade::Obstaculo::Plataforma* plataforma = new Entidade::Obstaculo::Plataforma(pos);
            if(plataforma == nullptr){
                std::cout << "Jungle::Construtor::ConstrutorFase::nao foi possivel criar uma plataforma" << std::endl;
                exit(1);
            }
            return static_cast<Entidade::Entidade*>(plataforma);
        }

        Entidade::Entidade* ConstrutorEntidade::criarCaixa(const sf::Vector2f pos){
            Entidade::Obstaculo::Caixa* caixa = new Entidade::Obstaculo::Caixa(pos);
            if(caixa == nullptr){
                std::cout << "Jungle::Construtor::ConstrutorFase::nao foi possivel criar uma caixa" << std::endl;
                exit(1);
            }
            return static_cast<Entidade::Entidade*>(caixa);
        }

        Entidade::Entidade* ConstrutorEntidade::criarEsqueleto(const sf::Vector2f pos){
            verificaJogador();
            Entidade::Personagem::Inimigo::Esqueleto* esqueleto = new Entidade::Personagem::Inimigo::Esqueleto(pos, pJogador);
            if(esqueleto == nullptr){
                std::cout << "Jungle::Construtor::ConstrutorFase::nao foi possivel criar um esqueleto" << std::endl;
                exit(1);
            }
            return static_cast<Entidade::Entidade*>(esqueleto);
        }
        
        Entidade::Entidade* ConstrutorEntidade::criarJogador(const sf::Vector2f pos, Entidade::Item::Arma* arma){
            Entidade::Personagem::Jogador::Jogador* jogador = new Entidade::Personagem::Jogador::Jogador(pos, arma);
            if(jogador == nullptr){
                std::cout << "Jungle::Construtor::ConstrutorFase::nao foi possivel criar um Jogador" << std::endl;
                exit(1);
            }
            if(pJogador == nullptr){
                pJogador = jogador;
            }
            return static_cast<Entidade::Entidade*>(jogador);
        }

        Entidade::Entidade* ConstrutorEntidade::criarMinotauro(const sf::Vector2f pos){
            verificaJogador();
            Entidade::Personagem::Inimigo::Chefao::Minotauro* minotauro = new Entidade::Personagem::Inimigo::Chefao::Minotauro(pos, pJogador);
            if(minotauro == nullptr){
                std::cout << "Jungle::Construtor::ConstrutorFase::nao foi possivel criar um minotauro" << std::endl;
                exit(1);
            }
            return static_cast<Entidade::Entidade*>(minotauro);
        }

    }

}