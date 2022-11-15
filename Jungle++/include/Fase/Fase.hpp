#pragma once

//Classe Base
#include "..\Ente.hpp"

//Fundo efeito Parallax
#include "..\Parallax\Fundo.hpp"

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

#include <fstream>

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
            void criaInimigo(const sf::Vector2f pos);
            void criarJogador(const sf::Vector2f pos);
            void criarPlataforma(const sf::Vector2f pos);
            void criarCaixa(const sf::Vector2f pos);
            virtual void criarFundo() = 0;
            virtual void criarMapa() = 0;
            void criarEntidade(char letra, const sf::Vector2i pos);
            void executar();
            void desenhar();
        };

    }

}