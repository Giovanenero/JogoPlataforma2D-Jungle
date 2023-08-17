#include "../../include/Parallax/Fundo.hpp"

namespace Jungle {

    namespace Parallax {

        Fundo::Fundo(const IDs::IDs ID):
            Ente(ID), posAnteriorCamera(pGrafico->getCamera().getCenter()),
            camadas()
        {  

        }   

        Fundo::~Fundo(){
            for(int i = 0; i < camadas.size(); i++){
                Camada* camada = camadas.at(i);
                if(camada){
                    delete(camada);
                    camada = nullptr;
                }
            }
            camadas.clear();
        }

        void Fundo::desenhar(){
            for(int i = 0; i < camadas.size(); i++){
                Camada* camada = camadas.at(i);
                camada->desenharCamada(pGrafico->getWindow());
            }
        }

        void Fundo::addCamada(const char* caminhoTextura, const float vel){
            Camada* camada = new Camada((sf::Vector2f)pGrafico->getWindow()->getSize(), pGrafico->carregarTextura(caminhoTextura), vel);
            if(camada == nullptr){
                std::cout << "ERRO::Fundo::nao foi possivel criar uma camada" << std::endl;
                exit(1);
            }
            camadas.push_back(camada);
        }

        void Fundo::atualizarPosicao(){
            sf::Vector2f posCamera = pGrafico->getCamera().getCenter();
            sf::Vector2f ds = posCamera - posAnteriorCamera;
            posAnteriorCamera = posCamera;
            for(int i = 0; i < camadas.size(); i++){
                camadas.at(i)->atualizar(ds, posCamera);
            }
        }

        void Fundo::executar(){
            atualizarPosicao();
            desenhar();
        }

    }

}