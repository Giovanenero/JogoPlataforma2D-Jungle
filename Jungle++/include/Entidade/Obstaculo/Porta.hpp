#pragma once

#include "Obstaculo.hpp"
#include "../Item/Chave.hpp"
#include "../../Animador/Animacao.hpp"
#include "../Personagem/Jogador/Jogador.hpp"

#define TEMPO_PORTA_ABRINDO 1.4f
#define TEMPO_ENTRAR 0.5f

namespace Jungle {

    namespace Entidade {

        namespace Obstaculo {

            class Porta : public Obstaculo {
                private:
                    Item::Chave* chave;
                    bool fechada;
                    bool abrindo;
                    float tempoAbrindo;
                    Animador::Animacao animacao;
                    sf::RectangleShape fundoPorta;
                    Menu::Botao::Texto textoPorta;
                    sf::RectangleShape caixaTexto;
                    bool mostrarTexto;
                    bool coletou;
                    IDs::IDs ID_Fase;

                    void inicializarAnimacao();
                    void atualizarAnimacao();
                    void inicializarTexto(std::string texto);
                public:
                    Porta(const sf::Vector2f pos, const sf::Vector2f tam, Item::Chave* chave, const IDs::IDs ID_Fase);
                    Porta(const std::vector<std::string> atributos, Item::Chave* chave);
                    ~Porta();
                    Item::Chave* getChave();
                    const IDs::IDs getIDFase() const;
                    void colidindoJogador(Personagem::Jogador::Jogador* pJogador);
                    void colisao(Entidade* outraEntidade, sf::Vector2f ds = sf::Vector2f(0.0f, 0.0f));
                    const std::string salvar();
                    void desenhar();
                    void atualizar();
            };

        }

    }

}