#include "../../include/Gerenciador/GerenciadorMusica.hpp"

namespace Jungle {

    namespace Gerenciador {

        GerenciadorMusica* GerenciadorMusica::pMusica = nullptr;

        GerenciadorMusica::GerenciadorMusica():
            mapMusica(), volumeGeral(100.0f)
        {
            addMusica(IDs::IDs::estado_menu_principal, "Jungle++/musica/menu-principal.ogg");
            addMusica(IDs::IDs::estado_menu_pausa, "Jungle++/musica/menu-pausa.ogg");
            addMusica(IDs::IDs::jogar_florestaBranca, "Jungle++/musica/jogo.ogg");
            addMusica(IDs::IDs::jogar_florestaVermelha, "Jungle++/musica/jogo.ogg");
            IDMusicaAtual = IDs::IDs::vazio;
        }

        GerenciadorMusica::~GerenciadorMusica(){
            std::map<IDs::IDs, sf::Music*>::iterator it = mapMusica.begin();
            while(it != mapMusica.end()){
                if(it->second != nullptr){
                    delete(it->second);
                    it->second = nullptr;
                }
                it++;
            }
            mapMusica.clear();
        }

        GerenciadorMusica* GerenciadorMusica::getGerenciadorMusica(){
            if(pMusica == nullptr){
                pMusica = new GerenciadorMusica();
            }
            return pMusica;
        }

        void GerenciadorMusica::addMusica(const IDs::IDs IDMusica, const char* caminhoMusica){
            sf::Music* musica = new sf::Music();
            if(!musica->openFromFile(caminhoMusica)){
                std::cout << "ERROR::Jungle::Gerenciador::GerenciadorMusica::nao foi possivel encontrar o caminho " << caminhoMusica;
                exit(1);
            }
            musica->setLoop(true);
            mapMusica.insert(std::pair<IDs::IDs, sf::Music*>(IDMusica, musica));
        }

        void GerenciadorMusica::mudarMusica(const IDs::IDs IDOutraMusica){
            /*
            switch (IDOutraMusica)
            {
                case (IDs::IDs::estado_menu_principal):
                {
                    if(IDMusicaAtual != IDs::IDs::estado_menu_opcaoPrincipal){
                        if(IDMusicaAtual != IDs::IDs::vazio){
                            parar();   
                        }
                        mapMusica[IDOutraMusica]->play();
                    }
                }
                    break;
                case (IDs::IDs::estado_menu_opcaoPrincipal):
                {
                    IDMusicaAtual = IDOutraMusica;
                }
                    break;
                case (IDs::IDs::estado_menu_pausa):
                {
                    pausar();
                    mapMusica[IDOutraMusica]->play();

                }
                    break;
                case (IDs::IDs::jogar_florestaBranca):
                {
                    parar();
                    mapMusica[IDOutraMusica]->play();
                }
                    break;
                case (IDs::IDs::jogar_florestaVermelha):
                {
                    parar();
                    mapMusica[IDOutraMusica]->play();
                }
                    break;
            }
            IDMusicaAtual = IDOutraMusica;
            */
        }

        void GerenciadorMusica::pausar(){
            mapMusica[IDMusicaAtual]->pause();
        }

        void GerenciadorMusica::despausar(){
            mapMusica[IDMusicaAtual]->play();
        }

        void GerenciadorMusica::parar(){
            mapMusica[IDMusicaAtual]->stop();
        }

        void GerenciadorMusica::setVolume(const float vol, const IDs::IDs ID){
            mapMusica[ID]->setVolume(vol);
        }

        void GerenciadorMusica::setVolumeGeral(const float volumeGeral){
            this->volumeGeral = volumeGeral;
        }

        const float GerenciadorMusica::getVolume(const IDs::IDs ID){
            return mapMusica[ID]->getVolume();
        }

        const float GerenciadorMusica::getVolumeGeral() const{
            return volumeGeral;
        }

    }

}