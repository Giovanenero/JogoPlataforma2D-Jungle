#pragma once

#include "Fase.hpp"
#include "../Entidade/Item/Projetil.hpp"
#include "../Entidade/Item/Vida.hpp"
#include "../Entidade/Personagem/Inimigo/Alma.hpp"

namespace Jungle {

    namespace Fase {

        class FlorestaBranca : public Fase  {
            void recuperarJogada(const std::string caminhoArquivo);
        public:
            FlorestaBranca(const std::string caminhoArquivo = "");
            ~FlorestaBranca();
            void criarFundo();
            void criarMapa();
        };

    }

}