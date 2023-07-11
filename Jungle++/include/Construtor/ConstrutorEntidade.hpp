#pragma once 

//personagens
#include "../Entidade/Personagem/Jogador/Jogador.hpp"
#include "../Entidade/Personagem/Inimigo/Esqueleto.hpp"
#include "../Entidade/Personagem/Inimigo/Chefao/Minotauro.hpp"

//obstaculos
#include "../Entidade/Obstaculo/Caixa.hpp"
#include "../Entidade/Obstaculo/Plataforma.hpp"
#include "../Entidade/Item/Arma.hpp"

namespace Jungle {

    namespace Construtor {

        class ConstrutorEntidade {
        private:
            Entidade::Personagem::Jogador::Jogador* pJogador;
            void verificaJogador();
        public:
            ConstrutorEntidade(Entidade::Personagem::Jogador::Jogador* pJogador);
            ConstrutorEntidade();
            ~ConstrutorEntidade();
            Entidade::Entidade* criarMinotauro(const sf::Vector2f pos);
            Entidade::Entidade* criarEsqueleto(const sf::Vector2f pos);
            Entidade::Entidade* criarJogador(const sf::Vector2f pos, Entidade::Item::Arma* arma);
            Entidade::Entidade* criarPlataforma(const sf::Vector2f pos);
            Entidade::Entidade* criarCaixa(const sf::Vector2f pos);

        };

    }

}