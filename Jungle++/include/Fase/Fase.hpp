#pragma once

//Classe Base
#include "..\Ente.hpp"

//Fundo efeito Parallax
#include "..\Parallax\Fundo.hpp"

#include "..\Entidade\Entidade.hpp"

//Personagens
#include "..\Entidade\Personagem\Jogador\Jogador.hpp"
#include "..\Entidade\Personagem\Inimigo\Inimigo.hpp"

//Obstaculos
#include "..\Entidade\Obstaculo\Caixa.hpp"
#include "..\Entidade\Obstaculo\Plataforma.hpp"

namespace Jungle {

    namespace Fase {

        class Fase : public Ente {
        protected:
            Parallax::Fundo fundo;
        public:
            Fase(const IDs::IDs ID_Fase, const IDs::IDs ID_Fundo);
            ~Fase();
            virtual void criaFundo() = 0;
            virtual void criaEntidades() = 0;
            virtual void executar() = 0;
            Entidade::Entidade* criaPlataforma(const sf::Vector2f pos);
            Entidade::Entidade* criaCaixa(const sf::Vector2f pos);
            Entidade::Entidade* criaInimigo(const sf::Vector2f pos, Entidade::Personagem::Jogador::Jogador* jogador);
        };

    }

}