#include "..\..\include\Fase\FlorestaBranca.hpp"
#include "../../include/Entidade/Item/Moeda.hpp"

Jungle::Fase::FlorestaBranca::FlorestaBranca():
    Fase(IDs::IDs::fase_florestaBranca, IDs::IDs::fundo_florestaBranca)
{
    
}

Jungle::Fase::FlorestaBranca::~FlorestaBranca(){

}

void Jungle::Fase::FlorestaBranca::criarFundo(){
    fundo.addCamada("Jungle++/img/Fase/FLorestaBranca/camada1.png", 0.0f);
    fundo.addCamada("Jungle++/img/Fase/FLorestaBranca/camada2.png", 0.1f);
    fundo.addCamada("Jungle++/img/Fase/FLorestaBranca/camada3.png", 0.3f);
    fundo.addCamada("Jungle++/img/Fase/FLorestaBranca/camada4.png", 0.5f);
    fundo.addCamada("Jungle++/img/Fase/FLorestaBranca/camada5.png", 1.0f);
}

void Jungle::Fase::FlorestaBranca::criarMapa(){
    //teste...
    Entidade::Item::Espada* espada = new Entidade::Item::Espada(IDs::IDs::espada_jogador);
    if(espada == nullptr){
        std::cout << "Jungle::Construtor::ConstrutorFase::nao foi possivel criar uma Espada" << std::endl;
        exit(1);
    }
    Entidade::Item::Moeda* moeda1 = new Entidade::Item::Moeda(sf::Vector2f(300.0f, 500.0f));
    listaPersonagens.addEntidade(static_cast<Entidade::Entidade*>(moeda1));
    Entidade::Item::Moeda* moeda2 = new Entidade::Item::Moeda(sf::Vector2f(1200.0f, 200.0f), IDs::IDs::moeda_cinza);
    listaPersonagens.addEntidade(static_cast<Entidade::Entidade*>(moeda2));
    listaPersonagens.addEntidade(static_cast<Entidade::Entidade*>(espada));
 
    Entidade::Entidade* jogador = construtorEntidade.criarJogador(sf::Vector2f(100.0f, 400.0f), espada);
    espada->setEntidade(jogador);
    listaPersonagens.addEntidade(jogador);
    
    for(int i = -2; i < 8; i++){
        listaObstaculos.addEntidade(construtorEntidade.criarPlataforma(sf::Vector2f(i * 300.0f, 550.0f)));
    }

    for(int i = 0; i < 2; i++){
        Entidade::Item::Espada* espadaInimigo = new Entidade::Item::Espada(IDs::IDs::espada_inimigo);
        Entidade::Personagem::Inimigo::Esqueleto* esqueleto = dynamic_cast<Entidade::Personagem::Inimigo::Esqueleto*>(construtorEntidade.criarEsqueleto(sf::Vector2f(500.0f * (i + 1), 0.0f))); 
        esqueleto->setEspada(espadaInimigo);
        listaPersonagens.addEntidade(static_cast<Entidade::Entidade*>(espadaInimigo));
        listaPersonagens.addEntidade(static_cast<Entidade::Entidade*>(esqueleto));
    }
    listaObstaculos.addEntidade(construtorEntidade.criarPlataforma(sf::Vector2f(500.0f, 400.0f)));
    listaObstaculos.addEntidade(construtorEntidade.criarPlataforma(sf::Vector2f(900.0f, 400.0f)));
    listaObstaculos.addEntidade(construtorEntidade.criarPlataforma(sf::Vector2f(1200.0f, 400.0f)));
    listaObstaculos.addEntidade(construtorEntidade.criarPlataforma(sf::Vector2f(1100.0f, 250.0f)));
    listaObstaculos.addEntidade(construtorEntidade.criarCaixa(sf::Vector2f(400.0f, 500.0f)));
    listaObstaculos.addEntidade(construtorEntidade.criarCaixa(sf::Vector2f(1000.0f, 350.0f)));
}

