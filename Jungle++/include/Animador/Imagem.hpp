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
            const unsigned int qtdImagem;
            unsigned int imgAtual;
            const float tempoTroca;
            float tempoTotal;
        public:
            Imagem(const char* caminhoTextura, const unsigned int qtdImagem, const float tempoTroca);
            ~Imagem();
            void atualizar(const bool paraEsquerda, const float dt);
            const sf::IntRect getTamanho();
            const sf::Texture* getTextura();
        };

    }

}