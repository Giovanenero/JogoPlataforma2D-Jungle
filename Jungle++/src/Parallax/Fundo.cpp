#include "..\..\include\Parallax\Fundo.hpp"

Jungle::Parallax::Fundo::Fundo():
    Ente(IDs::IDs::fundo), posAnteriorCamera(pGrafico->getCamera().getCenter()),
    camadas()
{  
    sf::Vector2f tamTela = (sf::Vector2f)pGrafico->getWindow()->getSize();
    Camada* camada1 = new Camada(tamTela, pGrafico->carregarTextura("Jungle++/img/Fase/Fase1/camada1.png"), 0.0f);
    Camada* camada2 = new Camada(tamTela, pGrafico->carregarTextura("Jungle++/img/Fase/Fase1/camada2.png"), 0.0f);
    Camada* camada3 = new Camada(tamTela, pGrafico->carregarTextura("Jungle++/img/Fase/Fase1/camada3.png"), 0.1f);
    Camada* camada4 = new Camada(tamTela, pGrafico->carregarTextura("Jungle++/img/Fase/Fase1/camada4.png"), 0.2f);
    Camada* camada5 = new Camada(tamTela, pGrafico->carregarTextura("Jungle++/img/Fase/Fase1/camada5.png"), 0.3f);
    Camada* camada6 = new Camada(tamTela, pGrafico->carregarTextura("Jungle++/img/Fase/Fase1/camada6.png"), 0.5f);
    Camada* camada7 = new Camada(tamTela, pGrafico->carregarTextura("Jungle++/img/Fase/Fase1/camada7.png"), 0.75f);
    Camada* camada8 = new Camada(tamTela, pGrafico->carregarTextura("Jungle++/img/Fase/Fase1/camada8.png"), 1.5f);
    
    camadas.push_back(camada1);
    camadas.push_back(camada2);
    camadas.push_back(camada3);
    camadas.push_back(camada4);
    camadas.push_back(camada5);
    camadas.push_back(camada6);
    camadas.push_back(camada7);
    camadas.push_back(camada8);

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
        //camada->atualizar(ds, posCamera);
        ds.x *= 0.5f;
        for(int i = camadas.size() - 1; i >= 0; i--){
            camadas.at(i)->atualizar(ds, posCamera);
        }
    }
    desenhar();
}

void Jungle::Parallax::Fundo::desenhar(){
    /*
    pGrafico->getWindow()->draw(camada->getFundo());
    pGrafico->getWindow()->draw(camada->getFundoAux());
    */
    for(int i = 0; i < camadas.size(); i++){
        Camada* camada = camadas.at(i);
        pGrafico->desenhaElemento(camada->getFundo());
        pGrafico->desenhaElemento(camada->getFundoAux());
    }
}