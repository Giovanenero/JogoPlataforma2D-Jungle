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
            const sf::Vector2u escala;
            const unsigned int qtdImagem;
            unsigned int imgAtual;
            const float tempoTroca;
            float tempoTotal;
        public:
            Imagem(const char* caminhoTextura, const unsigned int qtdImagem, const float tempoTroca, const sf::Vector2u escala);
            ~Imagem();
            void atualizar(const bool paraEsquerda, const float dt);
            const sf::IntRect getTamanho();
            const sf::Texture* getTextura();
            const sf::Vector2u getEscala() const;
        };

    }

}