#include "..\include\Principal.hpp"

Jungle::Principal::Principal():
    listaPersonagem(), listaObstaculo(), pGrafico(pGrafico->getGerenciadorGrafico()), 
    pEvento(pEvento->getGerenciadorEvento()),
    colisor(&listaPersonagem, &listaObstaculo)
{
    if(pGrafico == nullptr){
        std::cout << "ERROR::Jungle::Principal nao foi possivel criar o GerenciadorGrafico" << std::endl;
        exit(1);
    }

    if(pEvento == nullptr){
        std::cout << "ERROR::Jungle::Principal nao foi possivel criar um GerenciadorEvento" << std::endl;
        exit(1);
    }
    
    instanciaEntidades();

    executar();
}

Jungle::Principal::~Principal(){
    listaObstaculo.limparLista();
    listaPersonagem.limparLista();

    if(fundo){
        delete(fundo);
        fundo = nullptr;
    }
}

void Jungle::Principal::instanciaEntidades(){

    //cria personagens e obstaculos
    jogador = new Entidade::Personagem::Jogador::Jogador(sf::Vector2f(100.0f, 400.0f), sf::Vector2f(50.0f, 90.0f));
    Entidade::Obstaculo::Plataforma* p1 = new Entidade::Obstaculo::Plataforma(sf::Vector2f(0.0f, 550.0f), sf::Vector2f(300.0f, 50.0f));
    Entidade::Obstaculo::Plataforma* p2 = new Entidade::Obstaculo::Plataforma(sf::Vector2f(300.0f, 550.0f), sf::Vector2f(300.0f, 50.0f));
    Entidade::Obstaculo::Plataforma* p3 = new Entidade::Obstaculo::Plataforma(sf::Vector2f(600.0f, 550.0f), sf::Vector2f(300.0f, 50.0f));
    Entidade::Obstaculo::Plataforma* p4 = new Entidade::Obstaculo::Plataforma(sf::Vector2f(500.0f, 400.0f), sf::Vector2f(300.0f, 50.0f));
    Entidade::Obstaculo::Plataforma* p5 = new Entidade::Obstaculo::Plataforma(sf::Vector2f(150.0f, 250.0f), sf::Vector2f(300.0f, 50.0f));
    Entidade::Obstaculo::Caixa *c1 = new Entidade::Obstaculo::Caixa(sf::Vector2f(200.0f, 500.0f), sf::Vector2f(50.0f, 50.0f));
    Entidade::Obstaculo::Caixa *c2 = new Entidade::Obstaculo::Caixa(sf::Vector2f(650.0f, 350.0f), sf::Vector2f(50.0f, 50.0f));

    Entidade::Personagem::Inimigo::Inimigo* i1 = new Entidade::Personagem::Inimigo::Inimigo(sf::Vector2f(500.0f, 100.0f), sf::Vector2f(50.0f, 90.0f), jogador);
    Entidade::Personagem::Inimigo::Inimigo* i2 = new Entidade::Personagem::Inimigo::Inimigo(sf::Vector2f(300.0f, 0.0f), sf::Vector2f(50.0f, 90.0f), jogador);

    //transforma eles em entidades
    Entidade::Entidade* e1 = static_cast<Entidade::Entidade*>(jogador);
    Entidade::Entidade* e2 = static_cast<Entidade::Entidade*>(p1);
    Entidade::Entidade* e3 = static_cast<Entidade::Entidade*>(p2);
    Entidade::Entidade* e4 = static_cast<Entidade::Entidade*>(p3);
    Entidade::Entidade* e5 = static_cast<Entidade::Entidade*>(p4);
    Entidade::Entidade* e6 = static_cast<Entidade::Entidade*>(p5);
    Entidade::Entidade* e7 = static_cast<Entidade::Entidade*>(c1);
    Entidade::Entidade* e8 = static_cast<Entidade::Entidade*>(c2);

    Entidade::Entidade* e9 = static_cast<Entidade::Entidade*>(i1);
    Entidade::Entidade* e10 = static_cast<Entidade::Entidade*>(i2);

    //adiciona na lista de entidades
    listaPersonagem.addEntidade(e1);
    listaPersonagem.addEntidade(e9);
    listaPersonagem.addEntidade(e10);

    //add na lista obstaculo
    listaObstaculo.addEntidade(e2);
    listaObstaculo.addEntidade(e3);
    listaObstaculo.addEntidade(e4);
    listaObstaculo.addEntidade(e5);
    listaObstaculo.addEntidade(e6);
    listaObstaculo.addEntidade(e7);
    listaObstaculo.addEntidade(e8);

    pEvento->setJogador(jogador);

    fundo = new Parallax::Fundo(jogador->getEnderecoPos());
}

void Jungle::Principal::executar(){
    /**
     * @ return void 
     * 
     * Loop principal do jogo em que ocorre todo os eventos e move as entidades
     */

    while(pGrafico->verificaJanelaAberta()){
        //gerencia eventos
        pEvento->executar();

        //limpa janela
        pGrafico->limpaJanela();

        //pinta entidades
        listaPersonagem.executar();
        listaObstaculo.executar();

        //colisão
        colisor.executar();

        //mostra tudo na janela
        pGrafico->mostraElementos();

        //fundo->executar();
    }
}