#pragma once

#include "Arma.hpp"
#include "../../Animador/Animacao.hpp"

namespace Jungle {

    namespace Entidade {

        namespace Item {

            class Projetil: public Arma {
                private:
                    Animador::Animacao animacao;

                    void inicializarAnimacao();
                public:
                    Projetil(Personagem::Personagem* personagem = nullptr);
                    ~Projetil();
                    void atualizar();
            };

        }

    }

}