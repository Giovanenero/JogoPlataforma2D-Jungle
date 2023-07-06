#pragma once 

#include <iostream>
#include "../IDs.hpp"
#include <SFML/Audio.hpp>
#include <map>

namespace Jungle {

    namespace Gerenciador {

        class GerenciadorMusica {
        private:
            std::map<IDs::IDs, sf::Music*> mapMusica;
            IDs::IDs IDMusicaAtual;
            float volumeGeral;

            void addMusica(const IDs::IDs IDMusica, const char* caminhoMusica);
            static GerenciadorMusica* pMusica;
            GerenciadorMusica();
        public:
            ~GerenciadorMusica();
            static GerenciadorMusica* getGerenciadorMusica();
            void mudarMusica(const IDs::IDs IDOutraMusica);
            void pausar();
            void despausar();
            void parar();
            void setVolume(const float vol, const IDs::IDs ID);
            const float getVolume(const IDs::IDs ID);
            void setVolumeGeral(const float volumeGeral);
            const float getVolumeGeral() const;
        };

    }

}