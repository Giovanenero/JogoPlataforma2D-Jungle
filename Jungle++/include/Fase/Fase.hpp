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

    namespace Observador {
        class ObservadorFase;
    }

    namespace Fase {

        class Fase : public Ente {
        private:
            Observador::ObservadorFase* observadorFase; 
        protected:
            Lista::ListaEntidade listaPersonagens;
            Lista::ListaEntidade listaObstaculos;
            Construtor::ConstrutorEntidade construtorEntidade;
            Gerenciador::GerenciadorColisao* pColisao;
            Parallax::Fundo fundo;
            
        public:
            Fase(const IDs::IDs ID_Fase, const IDs::IDs ID_Fundo);
            ~Fase();
            virtual void criarFundo() = 0;
            virtual void criarMapa() = 0;
            void criarEntidade(char letra, const sf::Vector2i pos);
            void executar();
            void desenhar();
            Entidade::Personagem::Jogador::Jogador* getJogador();
            void mudarEstadoObservador();
        };

    }

}