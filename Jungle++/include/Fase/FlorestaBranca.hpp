#pragma once

#include "Fase.hpp"
#include "../Entidade/Item/Projetil.hpp"
#include "../Entidade/Item/Vida.hpp"
#include "../Entidade/Personagem/Inimigo/Alma.hpp"

namespace Jungle {

    namespace Fase {

        class FlorestaBranca : public Fase  {
        private:
            void recuperarJogada(const std::string arquivoEntidades, const std::vector<std::string> vectorInfoFase);
        public:
            FlorestaBranca(const std::string arquivoEntidades = "", const std::vector<std::string> vectorInfoFase = {});
            ~FlorestaBranca();
            void criarFundo();
            void criarMapa();
        };

    }

}