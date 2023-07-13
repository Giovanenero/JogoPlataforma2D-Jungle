#pragma once 

#include "MenuPrincipal.hpp"
#include "Botao/BotaoVolume.hpp"

#define TAMANHO_BOTAO_MENU_OPCAO_X 350.0f
#define TAMANHO_BOTAO_MENU_OPCAO_Y 80.0f

#define VELOCIDADE_BOTAO_VOLUME 2.0f

namespace Jungle {

    namespace Menu {

        class MenuOpcaoPrincipal: public MenuPrincipal {
        private:
            const float velocidadeBotao;
            static Gerenciador::GerenciadorMusica* pMusica;
            
            void addBotao(const std::string info, const sf::Vector2f pos, const IDs::IDs ID, const sf::Color corSelecionado, const float posInicioFundo);
            void atualizarVolume(const float volume, Botao::BotaoVolume* botaoVolume);
            void alterarVolume(const bool aumentando);
        public:
            MenuOpcaoPrincipal();
            ~MenuOpcaoPrincipal();
            void criarBotoes();
            void selecionaEsquerda();
            void selecionaDireita();
            void executar();
        };

    }

}