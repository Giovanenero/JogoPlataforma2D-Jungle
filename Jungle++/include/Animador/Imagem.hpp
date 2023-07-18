#pragma once 

#include "../Gerenciador/GerenciadorGrafico.hpp"
#include <SFML/Graphics.hpp>

namespace Jungle {

    namespace Animador {

        class Imagem {
        private:
            Gerenciador::GerenciadorGrafico* pGrafico;
            sf::Texture textura;
            sf::IntRect tamanho;
            const bool horizontal;
            const sf::Vector2f escala;
            const unsigned int qtdImagem;
            unsigned int imgAtual;
            const float tempoTroca;
            float tempoTotal;
            const sf::Vector2f origin;
        public:
            Imagem(const char* caminhoTextura, const unsigned int qtdImagem, const float tempoTroca, const sf::Vector2f escala, const sf::Vector2f origin, const bool horizontal);
            ~Imagem();
            void atualizar(const bool paraEsquerda, const float dt);
            void resetar();
            const unsigned int getQuadroAtual() const;
            void setQuadroAtual(const unsigned int imgAtual);
            const float getTempoTotal() const;
            void setTempoTotal(const float tempoTotal);
            const sf::IntRect getTamanho() const;
            const sf::Texture* getTextura() const;
            const sf::Vector2f getEscala() const;
            const sf::Vector2f getOrigin() const;
        };

    }

}