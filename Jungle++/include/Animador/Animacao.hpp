#pragma once

#include "Imagem.hpp"
#include <map>

namespace Jungle {

    namespace Animador {

        class Animacao {
        private:
            sf::RectangleShape* corpo;
            std::map<std::string, Imagem*> mapImagem;
            sf::Clock relogio;
            std::string imgAtual;
        public:
            Animacao(sf::RectangleShape* corpo);
            ~Animacao();
            const std::string getImgAtual() const;
            const unsigned int getQuadroAtual();
            void setQuadroAtual(const unsigned int imgAtual);
            const float getTempoTotal();
            void setTempoTotal(const float tempoTotal);
            void setImgAtual(const std::string imgAtual);
            void atualizar(const bool paraEsquerda, std::string imgAtual);
            void addAnimacao(const char* caminhoTextura, std::string nomeAnimacao, const unsigned int qtdImagem, const float tempoTroca, const sf::Vector2f escala, const sf::Vector2f origin = sf::Vector2f(0.0f, 0.0f), const bool horizontal = true);
        };

    }

}