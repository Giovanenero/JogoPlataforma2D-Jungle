#include "..\..\include\Fase\FaseFloresta.hpp"

Jungle::Fase::FaseFloresta::FaseFloresta():
    Fase(IDs::IDs::faseFloresta, IDs::IDs::florestaBranca)
{
    criaFundo();
    criaEntidades();
}

Jungle::Fase::FaseFloresta::~FaseFloresta(){

}

void Jungle::Fase::FaseFloresta::criaFundo(){
    fundo.addCamada("Jungle++/img/Fase/FLorestaBranca/camada1.png", 0.0f);
    fundo.addCamada("Jungle++/img/Fase/FLorestaBranca/camada2.png", 0.1f);
    fundo.addCamada("Jungle++/img/Fase/FLorestaBranca/camada3.png", 0.3f);
    fundo.addCamada("Jungle++/img/Fase/FLorestaBranca/camada4.png", 0.5f);
    fundo.addCamada("Jungle++/img/Fase/FLorestaBranca/camada5.png", 1.0f);  
}

void Jungle::Fase::FaseFloresta::criaEntidades(){

}

void Jungle::Fase::FaseFloresta::executar(){

}

