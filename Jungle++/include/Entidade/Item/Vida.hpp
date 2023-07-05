#pragma once

#include "../Entidade.hpp"

#define TAMANHO_VIDA 50.0f
#define CAMINHO_VIDA "Jungle++/img/Item/vida.png"
#define VIDA_MAXIMA 100.0f
#define VIDA_MINIMA 20.0f

namespace Jungle {

    namespace Entidade {

        namespace Item {

            class Vida : public Entidade {
                private:
                public:
                    Vida(const sf::Vector2f pos);
                    ~Vida();
                    void atualizar();
            };

        }

    }

}