#include "..\..\include\Fase\FlorestaVermelha.hpp"

Jungle::Fase::FlorestaVermelha::FlorestaVermelha():
    Fase(IDs::IDs::fase_florestaVermelha, IDs::IDs::fundo_florestaVermelha)
{

}

Jungle::Fase::FlorestaVermelha::~FlorestaVermelha(){

}

void Jungle::Fase::FlorestaVermelha::criarFundo(){
    fundo.addCamada("Jungle++/img/Fase/FLorestaVermelha/camada1.png", 0.0f);
    fundo.addCamada("Jungle++/img/Fase/FLorestaVermelha/camada2.png", 0.1f);
    fundo.addCamada("Jungle++/img/Fase/FLorestaVermelha/camada3.png", 0.3f);
    fundo.addCamada("Jungle++/img/Fase/FLorestaVermelha/camada4.png", 0.5f);
}

void Jungle::Fase::FlorestaVermelha::criarEntidades(){
    Entidade::Personagem::Jogador::Jogador* jogador = criarJogador(sf::Vector2f(100.0f, 400.0f));
    Gerenciador::GerenciadorEvento* pEvento = pEvento->getGerenciadorEvento();
    pEvento->setJogador(jogador);
    listaPersonagens.addEntidade(static_cast<Entidade::Entidade*>(jogador));
    
    for(int i = 0; i < 10; i++){
        listaObstaculos.addEntidade(criarPlataforma(sf::Vector2f((i - 2) * 300.0f, 550.0f)));
    }

    for(int i = 0; i < 4; i++){
        listaPersonagens.addEntidade(criaInimigo(sf::Vector2f(500.0f * (i + 1), 0.0f), jogador));
    }

    
    listaObstaculos.addEntidade(criarPlataforma(sf::Vector2f(200.0f, 400.0f)));
    listaObstaculos.addEntidade(criarPlataforma(sf::Vector2f(500.0f, 400.0f)));
    listaObstaculos.addEntidade(criarPlataforma(sf::Vector2f(600.0f, 250.0f)));
    listaObstaculos.addEntidade(criarCaixa(sf::Vector2f(0.0f, 500.0f)));
    listaObstaculos.addEntidade(criarCaixa(sf::Vector2f(300.0f, 350.0f)));
    
}