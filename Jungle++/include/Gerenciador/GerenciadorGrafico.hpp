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

            //movimentar a camera
            sf::View camera;

            //a construtora privada faz parte do padrão de projeto singleton
            static GerenciadorGrafico* pGrafico;
            GerenciadorGrafico();
        public:
            ~GerenciadorGrafico();
            static GerenciadorGrafico* getGerenciadorGrafico();
            sf::RenderWindow* getWindow();
            sf::Texture carregarTextura(const char* caminhoTextura);
            sf::Font carregarFonte(const char* caminhoFonte);
            void limpaJanela();
            void desenhaElemento(sf::RectangleShape corpo);
            void desenhaElemento(sf::Text texto);
            void mostraElementos();
            void fecharJanela();
            const bool verificaJanelaAberta();
            void atualizarCamera(const sf::Vector2f posJogador);
            const sf::View getCamera();
            void resetarJanela();
            const sf::Vector2f getTamJanela() const;
        };

    }

}