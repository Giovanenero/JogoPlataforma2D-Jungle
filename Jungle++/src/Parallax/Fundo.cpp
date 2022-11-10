#include "..\..\include\Parallax\Fundo.hpp"

Jungle::Parallax::Fundo::Fundo():
    Ente(IDs::IDs::fundo), posAnteriorCamera(pGrafico->getCamera().getCenter()),
    camadas()
{  
    addCamada("Jungle++/img/Fase/Fase1/camada1.png", 0.0f);
    addCamada("Jungle++/img/Fase/Fase1/camada2.png", 0.0f);
    addCamada("Jungle++/img/Fase/Fase1/camada3.png", 0.1f);
    addCamada("Jungle++/img/Fase/Fase1/camada4.png", 0.2f);
    addCamada("Jungle++/img/Fase/Fase1/camada5.png", 0.3f);
    addCamada("Jungle++/img/Fase/Fase1/camada6.png", 0.5f);
    addCamada("Jungle++/img/Fase/Fase1/camada7.png", 0.75f);
    addCamada("Jungle++/img/Fase/Fase1/camada8.png", 1.5f);

}

Jungle::Parallax::Fundo::~Fundo(){
    for(int i = 0; i < camadas.size(); i++){
        Camada* camada = camadas.at(i);
        if(camada){
            delete(camada);
            camada = nullptr;
        }
    }
    camadas.clear();
}

void Jungle::Parallax::Fundo::executar(){
    sf::Vector2f posCamera = pGrafico->getCamera().getCenter();
    sf::Vector2f ds = posCamera - posAnteriorCamera;
    posAnteriorCamera = posCamera;
    if(ds.x != 0.0f){
        ds.x *= 0.5f;
        for(int i = camadas.size() - 1; i >= 0; i--){
            camadas.at(i)->atualizar(ds, posCamera);
        }
    }
    desenhar();
}

void Jungle::Parallax::Fundo::desenhar(){
    for(int i = 0; i < camadas.size(); i++){
        Camada* camada = camadas.at(i);
        camada->desenharCamada(pGrafico->getWindow());
    }
}

void Jungle::Parallax::Fundo::addCamada(const char* caminhoTextura, const float vel){
    Camada* camada = new Camada((sf::Vector2f)pGrafico->getWindow()->getSize(), pGrafico->carregarTextura(caminhoTextura), vel);
    if(camada == nullptr){
        std::cout << "ERRO::Jungle::Parallax::Fundo::nao foi possivel criar uma camada" << std::endl;
        exit(1);
    }
    camadas.push_back(camada);
}