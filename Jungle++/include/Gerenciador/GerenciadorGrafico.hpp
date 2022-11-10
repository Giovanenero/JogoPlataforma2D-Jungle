#pragma once 

#define TELA_X 800.0f
#define TELA_Y 600.0f

#include <SFML\Graphics.hpp>
#include <iostream>

namespace Jungle {

    namespace Gerenciador {
        
        class GerenciadorGrafico {
        private:
            sf::RenderWindow* window;
            sf::View camera;

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
            void atualizarCamera(sf::Vector2f posJogador);
            const sf::View getCamera();
        };

    }

}