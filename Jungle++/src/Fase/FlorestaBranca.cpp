#include "../../include/Fase/FlorestaBranca.hpp"
#include "../../include/Entidade/Item/Moeda.hpp"

Jungle::Fase::FlorestaBranca::FlorestaBranca():
    Fase(IDs::IDs::fase_florestaBranca, IDs::IDs::fundo_florestaBranca)
{
    
}

Jungle::Fase::FlorestaBranca::~FlorestaBranca(){

}

void Jungle::Fase::FlorestaBranca::criarFundo(){
    fundo.addCamada("Jungle++/img/Fase/FlorestaBranca/camada1.png", 0.0f);
    fundo.addCamada("Jungle++/img/Fase/FlorestaBranca/camada2.png", 0.1f);
    fundo.addCamada("Jungle++/img/Fase/FlorestaBranca/camada3.png", 0.3f);
    fundo.addCamada("Jungle++/img/Fase/FlorestaBranca/camada4.png", 0.5f);
    fundo.addCamada("Jungle++/img/Fase/FlorestaBranca/camada5.png", 1.0f);
}

void Jungle::Fase::FlorestaBranca::criarMapa(){
    //teste...
    Entidade::Item::Arma* arma = new Entidade::Item::Arma(IDs::IDs::espada_jogador);
    if(arma == nullptr){
        std::cout << "Jungle::Construtor::ConstrutorFase::nao foi possivel criar uma Espada" << std::endl;
        exit(1);
    }
    Entidade::Item::Moeda* moeda1 = new Entidade::Item::Moeda(sf::Vector2f(300.0f, 500.0f));
    listaPersonagens->addEntidade(static_cast<Entidade::Entidade*>(moeda1));
    Entidade::Item::Moeda* moeda2 = new Entidade::Item::Moeda(sf::Vector2f(1200.0f, 80.0f), IDs::IDs::moeda_cinza);
    Entidade::Item::Vida* vida = new Entidade::Item::Vida(sf::Vector2f(1400.0f, 350.0f));
    listaPersonagens->addEntidade(static_cast<Entidade::Entidade*>(vida));
    listaPersonagens->addEntidade(static_cast<Entidade::Entidade*>(moeda2));
    listaPersonagens->addEntidade(static_cast<Entidade::Entidade*>(arma));
    
    Entidade::Personagem::Jogador::Jogador* jogador = new Entidade::Personagem::Jogador::Jogador(sf::Vector2f(100.0f, 400.0f), arma);

    //Entidade::Entidade* jogador = construtorEntidade.criarJogador(sf::Vector2f(100.0f, 400.0f), arma);
    arma->setPersonagem(static_cast<Entidade::Personagem::Personagem*>(jogador));
    listaPersonagens->addEntidade(static_cast<Entidade::Entidade*>(jogador));
    
    for(int i = -2; i < 8; i++){
        listaObstaculos->addEntidade(construtorEntidade.criarPlataforma(sf::Vector2f(i * 300.0f, 550.0f)));
    }

    for(int i = 0; i < 6; i++){
        Entidade::Item::Arma* espadaInimigo = new Entidade::Item::Arma(IDs::IDs::espada_inimigo);
        //Entidade::Personagem::Inimigo::Esqueleto* esqueleto = dynamic_cast<Entidade::Personagem::Inimigo::Esqueleto*>(construtorEntidade.criarEsqueleto(sf::Vector2f(400.0f * (i + 0.5f), 0.0f))); 
        Entidade::Personagem::Inimigo::Esqueleto* esq = new Entidade::Personagem::Inimigo::Esqueleto(sf::Vector2f(400.0f * (i + 0.5f), 0.0f), jogador);
        esq->setArma(espadaInimigo);
        listaPersonagens->addEntidade(static_cast<Entidade::Entidade*>(espadaInimigo));
        listaPersonagens->addEntidade(static_cast<Entidade::Entidade*>(esq));
    }

    Entidade::Personagem::Inimigo::Alma* alma1 = new Entidade::Personagem::Inimigo::Alma(sf::Vector2f(200.0f, 500.0f), jogador);
    Entidade::Item::Projetil* proj1 = new Entidade::Item::Projetil();
    alma1->setArma(static_cast<Entidade::Item::Arma*>(proj1));
    proj1->inicializarAnimacao();
    listaPersonagens->addEntidade(static_cast<Entidade::Entidade*>(proj1));
    listaPersonagens->addEntidade(static_cast<Entidade::Entidade*>(alma1));


    listaObstaculos->addEntidade(construtorEntidade.criarPlataforma(sf::Vector2f(500.0f, 400.0f)));
    listaObstaculos->addEntidade(construtorEntidade.criarPlataforma(sf::Vector2f(900.0f, 400.0f)));
    listaObstaculos->addEntidade(construtorEntidade.criarPlataforma(sf::Vector2f(1200.0f, 400.0f)));
    listaObstaculos->addEntidade(construtorEntidade.criarPlataforma(sf::Vector2f(1100.0f, 250.0f)));
    listaObstaculos->addEntidade(construtorEntidade.criarCaixa(sf::Vector2f(400.0f, 500.0f)));
    listaObstaculos->addEntidade(construtorEntidade.criarCaixa(sf::Vector2f(1000.0f, 350.0f)));
}

