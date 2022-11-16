#include "..\..\include\Fase\Fase.hpp"

Jungle::Fase::Fase::Fase(const IDs::IDs ID_Fase, const IDs::IDs ID_Fundo):
    Ente(ID_Fase), fundo(ID_Fundo), listaPersonagens(), listaObstaculos(),
    pColisao(new Gerenciador::GerenciadorColisao(&listaPersonagens, &listaObstaculos)),
    construtor()
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

void Jungle::Fase::Fase::criarEntidade(char letra, const sf::Vector2i pos){
    sf::Vector2f posAux = sf::Vector2f(pos.x * 50.0f, pos.y * 50.0f);
    switch (letra)
    {
        case ('e'):
        {
            listaPersonagens.addEntidade(construtor.criarEsqueleto(posAux));
        }
        break;
        case('c'):
        {
            listaObstaculos.addEntidade(construtor.criarCaixa(posAux));
        }
        break;
        case('#'):
        {
            listaObstaculos.addEntidade(construtor.criarPlataforma(posAux));
        }
        break;
        case('j'):{
            listaPersonagens.addEntidade(construtor.criarJogador(posAux));
        }
        break;
        case('m'):{
            listaPersonagens.addEntidade(construtor.criarMinotauro(posAux));
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