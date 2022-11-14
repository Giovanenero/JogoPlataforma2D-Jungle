#include "..\..\include\Fase\FaseFloresta.hpp"

Jungle::Fase::FaseFloresta::FaseFloresta():
    Fase(IDs::IDs::faseFloresta, IDs::IDs::florestaBranca)
{
    criarFundo();
    criarEntidades();
}

Jungle::Fase::FaseFloresta::~FaseFloresta(){

}

void Jungle::Fase::FaseFloresta::criarFundo(){
    fundo.addCamada("Jungle++/img/Fase/FLorestaBranca/camada1.png", 0.0f);
    fundo.addCamada("Jungle++/img/Fase/FLorestaBranca/camada2.png", 0.1f);
    fundo.addCamada("Jungle++/img/Fase/FLorestaBranca/camada3.png", 0.3f);
    fundo.addCamada("Jungle++/img/Fase/FLorestaBranca/camada4.png", 0.5f);
    fundo.addCamada("Jungle++/img/Fase/FLorestaBranca/camada5.png", 1.0f);  
}

void Jungle::Fase::FaseFloresta::criarEntidades(){
    Entidade::Personagem::Jogador::Jogador* jogador = criarJogador(sf::Vector2f(100.0f, 400.0f));
    Gerenciador::GerenciadorEvento* pEvento = pEvento->getGerenciadorEvento();
    pEvento->setJogador(jogador);
    listaPersonagens.addEntidade(static_cast<Entidade::Entidade*>(jogador));
    
    for(int i = 0; i < 10; i++){
        listaObstaculos.addEntidade(criarPlataforma(sf::Vector2f(i * 300.0f, 550.0f)));
    }

    for(int i = 0; i < 2; i++){
        listaPersonagens.addEntidade(criaInimigo(sf::Vector2f(500.0f * (i + 1), 0.0f), jogador));
    }

    listaObstaculos.addEntidade(criarPlataforma(sf::Vector2f(500.0f, 400.0f)));
    listaObstaculos.addEntidade(criarPlataforma(sf::Vector2f(900.0f, 400.0f)));
    listaObstaculos.addEntidade(criarPlataforma(sf::Vector2f(1200.0f, 400.0f)));
    listaObstaculos.addEntidade(criarPlataforma(sf::Vector2f(1100.0f, 250.0f)));
    listaObstaculos.addEntidade(criarCaixa(sf::Vector2f(400.0f, 500.0f)));
    listaObstaculos.addEntidade(criarCaixa(sf::Vector2f(1000.0f, 350.0f)));
}

void Jungle::Fase::FaseFloresta::executar(){
    fundo.executar();
    desenhar();
    pColisao->executar();
}

