#include "..\..\include\Parallax\Fundo.hpp"

Jungle::Parallax::Fundo::Fundo():
    Ente(IDs::IDs::fundo), posAnteriorCamera(pGrafico->getCamera().getCenter()),
    camadas()
{  
    /*
    addCamada("Jungle++/img/Fase/FlorestaVermelha/camada1.png", 0.0f);
    addCamada("Jungle++/img/Fase/FlorestaVermelha/camada2.png", 0.0f);
    addCamada("Jungle++/img/Fase/FlorestaVermelha/camada3.png", 0.1f);
    addCamada("Jungle++/img/Fase/FlorestaVermelha/camada4.png", 0.2f);
    addCamada("Jungle++/img/Fase/FlorestaVermelha/camada5.png", 0.3f);
    addCamada("Jungle++/img/Fase/FlorestaVermelha/camada6.png", 0.5f);
    addCamada("Jungle++/img/Fase/FlorestaVermelha/camada7.png", 0.75f);
    addCamada("Jungle++/img/Fase/FlorestaVermelha/camada8.png", 1.5f);
    */

    /*
    addCamada("Jungle++/img/Fase/FLorestaBranca/camada1.png", 0.0f);
    addCamada("Jungle++/img/Fase/FLorestaBranca/camada2.png", 0.1f);
    addCamada("Jungle++/img/Fase/FLorestaBranca/camada3.png", 0.3f);
    addCamada("Jungle++/img/Fase/FLorestaBranca/camada4.png", 0.5f);
    addCamada("Jungle++/img/Fase/FLorestaBranca/camada5.png", 1.0f);
    */
    

   
    addCamada("Jungle++/img/Fase/FlorestaNegra/camada1.png", 0.0f);
    addCamada("Jungle++/img/Fase/FlorestaNegra/camada2.png", 0.05f);
    addCamada("Jungle++/img/Fase/FlorestaNegra/camada3.png", 0.1f);
    addCamada("Jungle++/img/Fase/FlorestaNegra/camada4.png", 0.15f);
    addCamada("Jungle++/img/Fase/FlorestaNegra/camada5.png", 0.2f);
    addCamada("Jungle++/img/Fase/FlorestaNegra/camada6.png", 0.4f);
    addCamada("Jungle++/img/Fase/FlorestaNegra/camada7.png", 0.6f);
   
   
    

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