#include "..\include\Principal.hpp"

Jungle::Principal::Principal():
    listaPersonagem(), listaObstaculo(), pGrafico(pGrafico->getGerenciadorGrafico()), 
    pEvento(pEvento->getGerenciadorEvento()),
    colisor(&listaPersonagem, &listaObstaculo),
    fundo()
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
}

void Jungle::Principal::instanciaEntidades(){

    //cria personagens e obstaculos
    Entidade::Personagem::Jogador::Jogador* jogador = new Entidade::Personagem::Jogador::Jogador(sf::Vector2f(100.0f, 400.0f), sf::Vector2f(50.0f, 90.0f));

    for(int i = 0; i < 10; i++){
        Entidade::Obstaculo::Plataforma* p = new Entidade::Obstaculo::Plataforma(sf::Vector2f(0.0f + i * 300.0f, 550.0f), sf::Vector2f(300.0f, 50.0f));
        Entidade::Entidade* e = static_cast<Entidade::Entidade*>(p);
        listaObstaculo.addEntidade(e);
    }

    Entidade::Personagem::Inimigo::Inimigo* i1 = new Entidade::Personagem::Inimigo::Inimigo(sf::Vector2f(500.0f, 100.0f), sf::Vector2f(50.0f, 90.0f), jogador);
    Entidade::Personagem::Inimigo::Inimigo* i2 = new Entidade::Personagem::Inimigo::Inimigo(sf::Vector2f(300.0f, 0.0f), sf::Vector2f(50.0f, 90.0f), jogador);

    //transforma eles em entidades
    Entidade::Entidade* e1 = static_cast<Entidade::Entidade*>(jogador);

    Entidade::Entidade* e9 = static_cast<Entidade::Entidade*>(i1);
    Entidade::Entidade* e10 = static_cast<Entidade::Entidade*>(i2);

    //adiciona na lista de entidades
    listaPersonagem.addEntidade(e1);
    listaPersonagem.addEntidade(e9);
    listaPersonagem.addEntidade(e10);

    pEvento->setJogador(jogador);
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

        //efeito parallax
        fundo.executar();

        //pinta entidades
        listaPersonagem.executar();
        listaObstaculo.executar();

        //colisão
        colisor.executar();

        //mostra tudo na janela
        pGrafico->mostraElementos();
    }
}