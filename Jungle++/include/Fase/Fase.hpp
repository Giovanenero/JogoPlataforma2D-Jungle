#pragma once

//Classe Base
#include "..\Ente.hpp"

//Fundo efeito Parallax
#include "..\Parallax\Fundo.hpp"

//Gerenciadores
#include "..\Gerenciador\GerenciadorColisao.hpp"

//Listas
#include "..\Lista\ListaEntidade.hpp"

//Construtor
#include "..\Construtor\ConstrutorEntidade.hpp"

#include <fstream>

namespace Jungle {

    namespace Fase {

        class Fase : public Ente {
        protected:
            Lista::ListaEntidade listaPersonagens;
            Lista::ListaEntidade listaObstaculos;
            Construtor::ConstrutorEntidade construtorEntidade;
            Gerenciador::GerenciadorColisao* pColisao;
            Parallax::Fundo fundo;

            void atualizarEntidades();
        public:
            Fase(const IDs::IDs ID_Fase, const IDs::IDs ID_Fundo);
            ~Fase();
            virtual void criarFundo() = 0;
            virtual void criarMapa() = 0;
            void criarEntidade(char letra, const sf::Vector2i pos);
            void executar();
            void desenhar();
            Entidade::Personagem::Jogador::Jogador* getJogador();
        };

    }

}