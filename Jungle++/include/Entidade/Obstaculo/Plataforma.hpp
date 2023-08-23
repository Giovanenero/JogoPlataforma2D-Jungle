#pragma once

#include "Obstaculo.hpp"
#include "../Personagem/Personagem.hpp"

#define CAMINHO_TEXTURA_PLATAFORMA_PADRAO "Jungle++/img/Obstaculo/Plataforma.png"
#define CAMINHO_TEXTURA_PLATAFORMA_FLUTUANTE_1 "Jungle++/img/Obstaculo/Flutuante1.png"
#define CAMINHO_TEXTURA_PLATAFORMA_FLUTUANTE_2 "Jungle++/img/Obstaculo/Flutuante2.png"
#define CAMINHO_TEXTURA_PLATAFORMA_FLUTUANTE_MAIOR "Jungle++/img/Obstaculo/FlutuanteMaior.png"
#define CAMINHO_TEXTURA_PLATAFORMA_MADEIRA "Jungle++/img/Obstaculo/PlataformaMadeira.png"
#define CAMINHO_TEXTURA_PAREDE "Jungle++/img/Obstaculo/Parede.png"
#define CAMINHO_TEXTURA_PAREDE_FLUTUANTE "Jungle++/img/Obstaculo/ParedeFlutuante.png"
#define CAMINHO_TEXTURA_PLATAFORMA_PONTE_DIREITA "Jungle++/img/Obstaculo/PonteDireita.png"
#define CAMINHO_TEXTURA_PLATAFORMA_PONTE_ESQUERDA "Jungle++/img/Obstaculo/PonteEsquerda.png"
#define ESCALA_PLATAFORMA_X 1
#define ESCALA_PLATAFORMA_Y 1
#define TAMANHO_PLATAFORMA_X 350.0f
#define TAMANHO_PLATAFORMA_Y 50.0f
#define TAMANHO_FLUTUANTE_X 80.0f
#define TAMANHO_FLUTUANTE_Y 40.0f

namespace Jungle {

    namespace Entidade {

        namespace Obstaculo {

            class Plataforma : public Obstaculo {
                protected:
                    std::string type;
                    sf::Vector2f escala;

                    void inicializarAnimacao();
                    const std::string salvarPlataforma();
                public:
                    Plataforma(const IDs::IDs ID, const sf::Vector2f pos, const sf::Vector2f tam, const std::string type);
                    Plataforma(const std::vector<std::string> atributos);
                    ~Plataforma();
                    void setEscala(const sf::Vector2f escala);
                    virtual void colisao(Entidade* outraEntidade, sf::Vector2f ds = sf::Vector2f(0.0f, 0.0f));
                    virtual const std::string salvar();
            };

        }

    }

}