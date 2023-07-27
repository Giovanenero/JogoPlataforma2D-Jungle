#pragma once

#include "Fase.hpp"

namespace Jungle {

    namespace Fase {

        class FlorestaBranca : public Fase  {
        private:
            void recuperarJogada(const std::string arquivoEntidades, const std::vector<std::string> vectorInfoFase);
            void criarMapa1();
            void criarMapa2();
        public:
            FlorestaBranca(const std::string arquivoEntidades, const std::vector<std::string> vectorInfoFase);
            FlorestaBranca(const IDs::IDs ID_Mapa = IDs::IDs::floresta_branca_parte_1);
            ~FlorestaBranca();
            void criarFundo();
            void criarMapa(const IDs::IDs ID_Mapa);
        };

    }

}