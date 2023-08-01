#include "../../include/Fase/FlorestaVermelha.hpp"

namespace Jungle {

    namespace Fase {

        FlorestaVermelha::FlorestaVermelha():
            Fase(IDs::IDs::fase_florestaVermelha, IDs::IDs::fundo_florestaVermelha)
        {

        }

        FlorestaVermelha::~FlorestaVermelha(){

        }

        void FlorestaVermelha::recuperarJogada(const std::vector<std::string> vectorEntidades, const std::vector<std::string> vectorInfoFase){
            //terminar...
        }

        void FlorestaVermelha::criarFundo(){
            fundo.addCamada("Jungle++/img/Fase/FLorestaVermelha/camada1.png", 0.0f);
            fundo.addCamada("Jungle++/img/Fase/FLorestaVermelha/camada2.png", 0.1f);
            fundo.addCamada("Jungle++/img/Fase/FLorestaVermelha/camada3.png", 0.3f);
            fundo.addCamada("Jungle++/img/Fase/FLorestaVermelha/camada4.png", 0.5f);
        }

        void FlorestaVermelha::criarMapa(const IDs::IDs ID_Mapa){
            //terminar...
        }

    }

}