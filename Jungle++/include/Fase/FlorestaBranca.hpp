#pragma once

#include "Fase.hpp"
#include "../Entidade/Personagem/Inimigo/Carniceiro.hpp"

namespace Jungle {

    namespace Fase {

        class FlorestaBranca : public Fase  {
        private:
            void recuperarJogada(const std::vector<std::string> vectorEntidades, const std::vector<std::string> vectorInfoFase);
            void criarMapa1();
            void criarMapa2();
            void criarMapa3();
        public:
            FlorestaBranca(const std::vector<std::string> vectorEntidades, const std::vector<std::string> vectorInfoFase, const IDs::IDs ID);
            FlorestaBranca(const IDs::IDs ID = IDs::IDs::floresta_branca_parte_1);
            ~FlorestaBranca();
            void criarFundo();
            void criarMapa(const IDs::IDs ID_Mapa);
        };

    }

}