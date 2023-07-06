#pragma once 

#include <SFML/Graphics.hpp>
#include "../Lista/ListaEntidade.hpp"
#include <cmath>

namespace Jungle {

    namespace Gerenciador {

        class GerenciadorColisao {
        private:
            Lista::ListaEntidade* listaPersonagem;
            Lista::ListaEntidade* listaObstaculo;
        public:
            GerenciadorColisao(Lista::ListaEntidade* listaPersonagem, Lista::ListaEntidade* listaObstaculo);
            ~GerenciadorColisao();
            const sf::Vector2f calculaColisao(Entidade::Entidade* ent1, Entidade::Entidade* ent2);
            void executar();
        };

    }

}