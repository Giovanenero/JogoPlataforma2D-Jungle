#pragma once 

#include <SFML\Graphics.hpp>
#include <iostream>

namespace Jungle {

    namespace Gerenciador {
        
        class GerenciadorGrafico {
        private:
            sf::RenderWindow* window;

            //a construtora privada faz parte do padrão de projeto singleton
            static GerenciadorGrafico* pGrafico;
            GerenciadorGrafico();
        public:
            ~GerenciadorGrafico();
            static GerenciadorGrafico* getGerenciadorGrafico();
            sf::RenderWindow* getWindow();
            sf::Texture carregarTextura(const char* caminhoTextura);
            void limpaJanela();
            void desenhaElemento(sf::RectangleShape corpo);
            void mostraElementos();
            void fecharJanela();
            const bool verificaJanelaAberta();
        };

    }

}