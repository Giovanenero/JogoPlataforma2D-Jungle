#pragma once

//gerenciadores
#include "..\Gerenciador\GerenciadorEvento.hpp"

//personagens
#include "..\Entidade\Personagem\Jogador\Jogador.hpp"
#include "..\Entidade\Personagem\Inimigo\Esqueleto.hpp"
#include "..\Entidade\Personagem\Inimigo\Chefao\Minotauro.hpp"

//obstaculos
#include "..\Entidade\Obstaculo\Caixa.hpp"
#include "..\Entidade\Obstaculo\Plataforma.hpp"

namespace Jungle {

    namespace Construtor {

        class ConstrutorFase {
        public:
            ConstrutorFase();
            ~ConstrutorFase();
            Entidade::Entidade* criarMinotauro(const sf::Vector2f pos);
            Entidade::Entidade* criarEsqueleto(const sf::Vector2f pos);
            Entidade::Entidade* criarJogador(const sf::Vector2f pos);
            Entidade::Entidade* criarPlataforma(const sf::Vector2f pos);
            Entidade::Entidade* criarCaixa(const sf::Vector2f pos);
        };

    } 

}