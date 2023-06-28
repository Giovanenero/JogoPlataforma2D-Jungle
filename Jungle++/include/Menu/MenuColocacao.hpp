#pragma once

#include "Menu.hpp"
#include <vector> 
#include <fstream>

#define CAMINHO_ARQUIVO_COLOCACAO "Jungle++/arquivo/Colocacao/colocacao.txt"
#define QUANTIDADE_PALAVRAS 2
#define CAMINHO_FONTE_COLOCACAO "Jungle++/fonte/menuColocacao.ttf"

namespace Jungle {

    namespace Menu {

        class MenuColocacao: public Menu {
            private:
                std::vector<Botao::Texto*> vectorTexto;
                Parallax::Fundo fundo;
                std::ifstream arquivo;

                void criarTexto(std::string linha);
                void criarBotoes();
                void criarFundo();
                void criarColocacao();
                void desenharColocacao();
            public:
                MenuColocacao();
                ~MenuColocacao();
                void executar();
        };

    }

}