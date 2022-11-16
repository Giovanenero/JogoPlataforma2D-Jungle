#include "..\..\include\Fase\Fase.hpp"

Jungle::Fase::Fase::Fase(const IDs::IDs ID_Fase, const IDs::IDs ID_Fundo):
    Ente(ID_Fase), fundo(ID_Fundo), listaPersonagens(), listaObstaculos(),
    pColisao(new Gerenciador::GerenciadorColisao(&listaPersonagens, &listaObstaculos))
{
    if(pColisao == nullptr){
        std::cout << "Jungle::Fase::nao foi possivel criar um Gerenciador de Colisao" << std::endl;
        exit(1);
    }
}

Jungle::Fase::Fase::~Fase(){
    if(pColisao){
        delete(pColisao);
        pColisao = nullptr;
    }
    listaObstaculos.limparLista();
    listaPersonagens.limparLista();
}

void Jungle::Fase::Fase::criarPlataforma(const sf::Vector2f pos){
    Entidade::Obstaculo::Plataforma* plataforma = new Entidade::Obstaculo::Plataforma(pos, sf::Vector2f(300.0f, 50.0f));
    if(plataforma == nullptr){
        std::cout << "Jungle::Fase::nao foi possivel criar uma plataforma" << std::endl;
        exit(1);
    }
    listaObstaculos.addEntidade(static_cast<Entidade::Entidade*>(plataforma));
}

void Jungle::Fase::Fase::criarCaixa(const sf::Vector2f pos){
    Entidade::Obstaculo::Caixa* caixa = new Entidade::Obstaculo::Caixa(pos, sf::Vector2f(50.0f, 50.0f));
    if(caixa == nullptr){
        std::cout << "Jungle::Fase::nao foi possivel criar uma caixa" << std::endl;
        exit(1);
    }
    listaObstaculos.addEntidade(static_cast<Entidade::Entidade*>(caixa));
}

void Jungle::Fase::Fase::criarEsqueleto(const sf::Vector2f pos){
    Gerenciador::GerenciadorEvento* pEvento = pEvento->getGerenciadorEvento();
    Entidade::Personagem::Jogador::Jogador* pJogador = pEvento->getJogador();
    Entidade::Personagem::Inimigo::Esqueleto* esqueleto = new Entidade::Personagem::Inimigo::Esqueleto(pos, sf::Vector2f(50.0f, 90.0f), pJogador);
    if(esqueleto == nullptr){
        std::cout << "Jungle::Fase::nao foi possivel criar um esqueleto" << std::endl;
        exit(1);
    }
    listaPersonagens.addEntidade(static_cast<Entidade::Entidade*>(esqueleto));
}

void Jungle::Fase::Fase::criarJogador(const sf::Vector2f pos){
    Entidade::Personagem::Jogador::Jogador* jogador = new Entidade::Personagem::Jogador::Jogador(pos, sf::Vector2f(50.0f, 90.0f));
    if(jogador == nullptr){
        std::cout << "Jungle::Fase::nao foi possivel criar um Jogador" << std::endl;
        exit(1);
    }
    Gerenciador::GerenciadorEvento* pEvento = pEvento->getGerenciadorEvento();
    pEvento->setJogador(jogador);
    listaPersonagens.addEntidade(static_cast<Entidade::Entidade*>(jogador));
}

void Jungle::Fase::Fase::criarMinotauro(const sf::Vector2f pos){
    Gerenciador::GerenciadorEvento* pEvento = pEvento->getGerenciadorEvento();
    Entidade::Personagem::Jogador::Jogador* pJogador = pEvento->getJogador();
    Entidade::Personagem::Inimigo::Chefao::Minotauro* minotauro = new Entidade::Personagem::Inimigo::Chefao::Minotauro(pos, sf::Vector2f(60.0f, 110.0f), pJogador);
    if(minotauro == nullptr){
        std::cout << "Jungle::Fase::nao foi possivel criar um minotauro" << std::endl;
        exit(1);
    }
    listaPersonagens.addEntidade(static_cast<Entidade::Entidade*>(minotauro));
}

void Jungle::Fase::Fase::criarEntidade(char letra, const sf::Vector2i pos){
    sf::Vector2f posAux = sf::Vector2f(pos.x * 50.0f, pos.y * 50.0f);
    switch (letra)
    {
        case ('e'):
        {
            criarEsqueleto(posAux);
        }
        break;
        case('c'):
        {
            criarCaixa(posAux);
        }
        break;
        case('#'):
        {
            criarPlataforma(posAux);
        }
        break;
        case('j'):{
            criarJogador(posAux);
        }
        break;
        case('m'):{
            criarMinotauro(posAux);
        }
        break;
    }
}

void Jungle::Fase::Fase::desenhar(){
    listaPersonagens.executar();
    listaObstaculos.executar();
}

void Jungle::Fase::Fase::executar(){
    //atualiza fundo
    fundo.executar();

    //atualiza entidade e desenha
    desenhar();

    //verifica colisão
    pColisao->executar();
}