#include "..\..\include\Animador\Animacao.hpp"

Jungle::Animador::Animacao::Animacao(sf::RectangleShape* corpo):
    corpo(corpo), mapImagem(), imgAtual(""), relogio()
{

}

Jungle::Animador::Animacao::~Animacao(){
    mapImagem.clear();
}

void Jungle::Animador::Animacao::atualizar(const bool paraEsquerda, std::string imgAtual){
    //atualizar animacao;
    if(this->imgAtual != imgAtual){
        this->imgAtual = imgAtual;
    }
    float dt = relogio.getElapsedTime().asSeconds();
    relogio.restart();
    mapImagem[this->imgAtual]->atualizar(paraEsquerda, dt);
    corpo->setTextureRect(mapImagem[this->imgAtual]->getTamanho());
    corpo->setTexture(mapImagem[this->imgAtual]->getTextura());
}

void Jungle::Animador::Animacao::addAnimacao(const char* caminhoTextura, std::string nomeAnimacao, int qtdImagem, const float trocaImg){
    Imagem* img = new Imagem(caminhoTextura, qtdImagem, trocaImg);
    mapImagem.insert(std::pair<std::string, Imagem*>(nomeAnimacao, img));
}