#pragma once 

#include "..\Gerenciador\GerenciadorGrafico.hpp"
#include <SFML\Graphics.hpp>

namespace Jungle {

    namespace Animador {

        class Imagem {
        private:
            Gerenciador::GerenciadorGrafico* pGrafico;
            sf::Texture textura;
            const unsigned int qtdImagem;
            unsigned int imgAtual;
            sf::IntRect tamanho;
            const float tempoTroca;
            float tempoTotal;
        public:
            Imagem(const char* caminhoTextura, const unsigned int qtdImagem, const float trocaImg);
            ~Imagem();
            void atualizar(const bool paraEsquerda, const float dt);
            const sf::IntRect getTamanho() const;
        };

    }

}