#include "..\..\include\Construtor\ConstrutorFase.hpp"

namespace Jungle {

    namespace Construtor {

        ConstrutorFase::ConstrutorFase(){

        }

        ConstrutorFase::~ConstrutorFase(){

        }

        Entidade::Entidade* ConstrutorFase::criarPlataforma(const sf::Vector2f pos){
            Entidade::Obstaculo::Plataforma* plataforma = new Entidade::Obstaculo::Plataforma(pos);
            if(plataforma == nullptr){
                std::cout << "Jungle::Construtor::ConstrutorFase::nao foi possivel criar uma plataforma" << std::endl;
                exit(1);
            }
            return static_cast<Entidade::Entidade*>(plataforma);
        }

        Entidade::Entidade* ConstrutorFase::criarCaixa(const sf::Vector2f pos){
            Entidade::Obstaculo::Caixa* caixa = new Entidade::Obstaculo::Caixa(pos);
            if(caixa == nullptr){
                std::cout << "Jungle::Construtor::ConstrutorFase::nao foi possivel criar uma caixa" << std::endl;
                exit(1);
            }
            return static_cast<Entidade::Entidade*>(caixa);
        }

        Entidade::Entidade* ConstrutorFase::criarEsqueleto(const sf::Vector2f pos){
            Gerenciador::GerenciadorEvento* pEvento = pEvento->getGerenciadorEvento();
            Entidade::Personagem::Jogador::Jogador* pJogador = pEvento->getJogador();
            Entidade::Personagem::Inimigo::Esqueleto* esqueleto = new Entidade::Personagem::Inimigo::Esqueleto(pos, pJogador);
            if(esqueleto == nullptr){
                std::cout << "Jungle::Construtor::ConstrutorFase::nao foi possivel criar um esqueleto" << std::endl;
                exit(1);
            }
            return static_cast<Entidade::Entidade*>(esqueleto);
        }

        Entidade::Entidade* ConstrutorFase::criarJogador(const sf::Vector2f pos){
            Entidade::Personagem::Jogador::Jogador* jogador = new Entidade::Personagem::Jogador::Jogador(pos);
            if(jogador == nullptr){
                std::cout << "Jungle::Construtor::ConstrutorFase::nao foi possivel criar um Jogador" << std::endl;
                exit(1);
            }
            Gerenciador::GerenciadorEvento* pEvento = pEvento->getGerenciadorEvento();
            pEvento->setJogador(jogador);
            return static_cast<Entidade::Entidade*>(jogador);
        }

        Entidade::Entidade* ConstrutorFase::criarMinotauro(const sf::Vector2f pos){
            Gerenciador::GerenciadorEvento* pEvento = pEvento->getGerenciadorEvento();
            Entidade::Personagem::Jogador::Jogador* pJogador = pEvento->getJogador();
            Entidade::Personagem::Inimigo::Chefao::Minotauro* minotauro = new Entidade::Personagem::Inimigo::Chefao::Minotauro(pos, pJogador);
            if(minotauro == nullptr){
                std::cout << "Jungle::Construtor::ConstrutorFase::nao foi possivel criar um minotauro" << std::endl;
                exit(1);
            }
            return static_cast<Entidade::Entidade*>(minotauro);
        }

    }

}