#pragma once 

#include "..\Gerenciador\GerenciadorGrafico.hpp"
#include <SFML\Graphics.hpp>

namespace Jungle {

    namespace Animador {

        class Imagem {
        private:
            Gerenciador::GerenciadorGrafico* pGrafico;
            sf::Texture textura;
            sf::IntRect tamanho;
            const sf::Vector2f escala;
            const unsigned int qtdImagem;
            unsigned int imgAtual;
            const float tempoTroca;
            float tempoTotal;
        public:
            Imagem(const char* caminhoTextura, const unsigned int qtdImagem, const float tempoTroca, const sf::Vector2f escala);
            ~Imagem();
            void atualizar(const bool paraEsquerda, const float dt);
            void resetar();
            const sf::IntRect getTamanho() const;
            const sf::Texture* getTextura() const;
            const sf::Vector2f getEscala() const;
        };

    }

}