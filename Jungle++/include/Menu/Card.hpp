#pragma once

#include "Menu.hpp"
#include "Botao/Texto.hpp"

#define CAMINHO_FONTE_CARD "Jungle++/fonte/menu.ttf"

namespace Jungle {

    namespace Menu {

         class Card {
            private:
                sf::Texture* textura;
                sf::RectangleShape* corpo;
                Botao::Texto textoInfo;
                const std::string caminhoArquivoEntidades;
                const std::string caminhoArquivoFase;
                const std::string caminhoImage;
                sf::Color cor;
                bool selecionado;
                bool existe;
            
                static Gerenciador::GerenciadorGrafico* pGrafico;
            public:
                Card(const sf::Vector2f pos, const std::string caminhoArquivoEntidades, const std::string caminhoArquivoFase, const std::string caminhoImage);
                ~Card();
                const std::string getCaminhoArquivoEntidades() const;
                const std::string getCaminhoArquivoFase() const;
                const std::string getCaminhoImage() const;
                void setColor(const sf::Color cor);
                void setSelecionado(const bool selecionado);
                const bool getSelecionado() const;
                const bool getExiste() const;
                void deletarTextura();
                void desenhar();
        };

    }

}