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
    Imagem* img = mapImagem[this->imgAtual];
    sf::Vector2f tamCorpo = corpo->getSize();
    sf::Vector2u aux = img->getEscala();
    
    img->atualizar(paraEsquerda, dt);
    sf::IntRect tam = img->getTamanho();
    corpo->setTextureRect(img->getTamanho());
    corpo->setTexture(img->getTextura());
    corpo->setScale(aux.x, aux.y);
    corpo->setOrigin(tamCorpo/2.0f);
}

void Jungle::Animador::Animacao::addAnimacao(const char* caminhoTextura, std::string nomeAnimacao, int qtdImagem, const float tempoTroda, const sf::Vector2u escala){
    Imagem* img = new Imagem(caminhoTextura, qtdImagem, tempoTroda, escala);
    mapImagem.insert(std::pair<std::string, Imagem*>(nomeAnimacao, img));
}