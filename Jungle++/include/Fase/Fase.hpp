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

//Gerenciadores
#include "..\Gerenciador\GerenciadorColisao.hpp"
#include "..\Gerenciador\GerenciadorEvento.hpp"

//Listas
#include "..\Lista\ListaEntidade.hpp"

namespace Jungle {

    namespace Fase {

        class Fase : public Ente {
        protected:
            Lista::ListaEntidade listaPersonagens;
            Lista::ListaEntidade listaObstaculos;
            Gerenciador::GerenciadorColisao* pColisao;
            Parallax::Fundo fundo;
        public:
            Fase(const IDs::IDs ID_Fase, const IDs::IDs ID_Fundo);
            ~Fase();
            Entidade::Entidade* criaInimigo(const sf::Vector2f pos, Entidade::Personagem::Jogador::Jogador* jogador);
            Entidade::Personagem::Jogador::Jogador* criarJogador(const sf::Vector2f pos);
            Entidade::Entidade* criarPlataforma(const sf::Vector2f pos);
            Entidade::Entidade* criarCaixa(const sf::Vector2f pos);
            virtual void criarFundo() = 0;
            virtual void criarEntidades() = 0;
            void executar();
            void desenhar();
        };

    }

}