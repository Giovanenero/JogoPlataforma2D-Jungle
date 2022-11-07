#include "..\..\include\Animador\Animacao.hpp"
#include "Imagem.hpp"

Jungle::Animador::Animacao::Animacao(sf::RectangleShape* corpo):
    corpo(corpo), mapImagem()
{

}

Jungle::Animador::Animacao::~Animacao(){

}

void Jungle::Animador::Animacao::atualizar(const bool paraEsquerda, std::string imgAtual){
    //atualizar animacao;
    if(this->imgAtual != imgAtual){
        this->imgAtual = imgAtual;
    }
    const float dt = relogio.getElapsedTime().asSeconds();
    relogio.restart();
    mapImagem[imgAtual].atualizar(paraEsquerda, dt);
}

void Jungle::Animador::Animacao::addAnimacao(const char* caminhoTextura, std::string nomeAnimacao, int qtdImagem, const float trocaImg){
    Imagem img(caminhoTextura, qtdImagem, trocaImg);
    mapImagem.insert(std::pair<std::string, Imagem>(nomeAnimacao, img));
}