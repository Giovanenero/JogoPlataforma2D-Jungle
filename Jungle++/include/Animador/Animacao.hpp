#pragma once

#include "Imagem.hpp"
#include <map>

namespace Jungle {

    namespace Animador {

        class Animacao {
        private:
            sf::RectangleShape* corpo;
            std::map<std::string, Imagem> mapImagem;
            sf::Clock relogio;
            std::string imgAtual;
        public:
            Animacao(sf::RectangleShape* corpo);
            ~Animacao();            
            void atualizar(const bool paraEsquerda, std::string imgAtual);
            void addAnimacao(const char* caminhoTextura, std::string nomeAnimacao, int qtdImagem, const float trocaImg);
        };

    }

}