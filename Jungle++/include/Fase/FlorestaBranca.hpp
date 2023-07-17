#pragma once

#include "Fase.hpp"
#include "../Entidade/Item/Projetil.hpp"
#include "../Entidade/Item/Vida.hpp"
#include "../Entidade/Personagem/Inimigo/Alma.hpp"

namespace Jungle {

    namespace Fase {

        class FlorestaBranca : public Fase  {
            void recuperarJogada(const char* caminhoArquivo);
        public:
            FlorestaBranca(const char* caminhoArquivo = "");
            ~FlorestaBranca();
            void criarFundo();
            void criarMapa();
        };

    }

}