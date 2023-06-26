#pragma once

#include "Menu.hpp"
#include "../Parallax/Fundo.hpp"
#include <fstream>
#include <vector>

#define TAMANHO_BOTAO_MENU_PERFIL_X 100.0f
#define TAMANHO_BOTAO_MENU_PERFIL_Y 50.0f
#define TAMANHO_SETA 50.0f
#define QUANTIDADE_PARAMETRO_CARD 8
#define CAMINHO_ARQUIVO "Jungle++/arquivo/Card/cardPerfil.txt"

namespace Jungle {

    namespace Menu {

        class MenuPerfil: public Menu {
            class Card {
                private:
                    sf::RectangleShape corpo;
                    sf::Texture textura;
                    const sf::Color corSelecionado;

                    void desenhar() const;
                public:
                    Card(const char* tipo, const sf::Vector2f tam, const sf::Vector2f pos, const char* caminhoTextura);
                    ~Card();
                    void executar();
            };
            private:
                Parallax::Fundo fundo;
                std::list<Card*> listaCards;
                std::list<Card*>::iterator iteratorCard;
                std::ifstream arquivo;
                sf::RectangleShape painelPerfil;
                std::vector<sf::RectangleShape> setas;

                void criarFundo();
                void criarBotoes();
                void inicializarCards();
                void executarCards();
                void inicializarSetas();
                void executarSetas();
            public:
                MenuPerfil();
                ~MenuPerfil();
                void mudarEstadoObservador();
                void executar();
                void selecionaEsquerda();
                void selecionaDireita();
        };

    }

}