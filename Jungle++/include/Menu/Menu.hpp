#pragma once 

#include "../Ente.hpp"
#include "Card.hpp"
#include "Botao/BotaoTexto.hpp"
#include "Botao/Texto.hpp"
#include "../Parallax/Fundo.hpp"
#include <list>

#define TAMANHO_BOTAO_X 350.0f
#define TAMANHO_BOTAO_Y 50.0f

namespace Jungle {

    namespace Observador {
        class ObservadorMenu;
    }

    namespace Menu {

        class Menu: public Ente {
        protected:
            Observador::ObservadorMenu* observadorMenu;
            std::list<Botao::BotaoTexto*> listaBotaoTexto;
            std::list<Botao::BotaoTexto*>::iterator it;
            const sf::Vector2f tamBotao;
            const sf::Vector2f tamJanela;
            sf::Vector2f posFundo;
            Botao::Texto titulo;
            bool mouseSelecionado;

            void atualizarPosicaoFundo();
            virtual void criarFundo(){};
            virtual void criarBotoes() = 0;
            void inicializarIterator();
        public:
            Menu(const IDs::IDs ID, const sf::Vector2f tamBotao, const std::string nome, const unsigned int tamFonte);
            ~Menu();
            void addBotao(const std::string info, const sf::Vector2f pos, const IDs::IDs ID, const sf::Color corSelecionado);
            void mudarEstadoObservador();
            void selecionaCima();
            void selecionaBaixo();
            virtual void selecionaEsquerda(){}
            virtual void selecionaDireita(){}
            const IDs::IDs getIDBotaoSelecionado() const;
            void eventoMouse(const sf::Vector2f posMouse);
            const bool getMouseSelecionado() const;
            virtual void executar() = 0;
            void desenhar();
        };

    }
    
}