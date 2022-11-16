#pragma once

//Classe Base
#include "..\Ente.hpp"

//Fundo efeito Parallax
#include "..\Parallax\Fundo.hpp"

#include "..\Construtor\ConstrutorFase.hpp"

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
            Construtor::ConstrutorFase construtor;
        public:
            Fase(const IDs::IDs ID_Fase, const IDs::IDs ID_Fundo);
            ~Fase();
            virtual void criarFundo() = 0;
            virtual void criarMapa() = 0;
            void criarEntidade(char letra, const sf::Vector2i pos);
            void executar();
            void desenhar();
        };

    }

}