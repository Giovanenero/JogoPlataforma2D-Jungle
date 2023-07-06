#pragma once 

#include "BotaoTexto.hpp"
#include "../../Gerenciador/GerenciadorMusica.hpp"

#define TAMANHO_BARRA_VOLUME_X 300.0f
#define TAMANHO_BARRA_VOLUME_Y 30.0f

#define TAMANHO_BOTAO_VOLUME_X 50.0f
#define TAMANHO_BOTAO_VOLUME_Y 30.0f

namespace Jungle {

    namespace Menu {

        namespace Botao {

            class BotaoVolume: public BotaoTexto {
            private:
                sf::RectangleShape fundoVolume;
                sf::RectangleShape corpoVolume;

                static Gerenciador::GerenciadorMusica* pMusica;
                const float posInicioFundo;
                const float parametrizacao;
                float posInicioBarra;
                float posFimBarra;
                void atualizarVolume();
            public:
                BotaoVolume(const std::string info, const sf::Vector2f tam,const sf::Vector2f pos, const IDs::IDs ID, const sf::Color corSelecionado, const float posInicioFundo);
                ~BotaoVolume();
                void desenhar();
                void alterarVolume(const float volume);
            };

        }

    }

}