#pragma once

#include "Menu.hpp"
#include "Botao\BotaoVolume.hpp"

#define TAMANHO_BOTAO_MENU_OPCAO_X 350.0f
#define TAMANHO_BOTAO_MENU_OPCAO_Y 80.0f

#define VELOCIDADE_BOTAO_VOLUME 2.0f

namespace Jungle {

    namespace Menu {

        class MenuOpcao: public Menu {
        protected:
            const float velocidadeBotao;
            static Gerenciador::GerenciadorMusica* pMusica;

            void addBotao(const std::string info, const sf::Vector2f pos, const IDs::IDs ID, const sf::Color corSelecionado, const float posInicioFundo);
            void atualizarVolume(const float volume, Botao::BotaoVolume* botaoVolume);
        public:
            MenuOpcao();
            ~MenuOpcao();
            void alterarVolume(const bool aumentando);
            void executar() = 0;
        };

    }

}