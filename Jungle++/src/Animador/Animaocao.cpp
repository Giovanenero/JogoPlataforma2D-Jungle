#include "..\..\include\Animador\Animacao.hpp"

Jungle::Animador::Animacao::Animacao(sf::RectangleShape* corpo):
    corpo(corpo), mapImagem(), imgAtual(""), relogio()
{

}

Jungle::Animador::Animacao::~Animacao(){
    mapImagem.clear();
}

void Jungle::Animador::Animacao::atualizar(const bool paraEsquerda, std::string imgAtual){
    if(this->imgAtual != imgAtual){
        if(this->imgAtual != ""){
            mapImagem[this->imgAtual]->resetar();
        }
        this->imgAtual = imgAtual;
    }
    float dt = relogio.getElapsedTime().asSeconds();
    relogio.restart();
    Imagem* img = mapImagem[this->imgAtual];
    sf::Vector2f tamCorpo = corpo->getSize();
    sf::Vector2f aux = img->getEscala();
    
    img->atualizar(paraEsquerda, dt);
    sf::IntRect tam = img->getTamanho();
    corpo->setTextureRect(img->getTamanho());
    corpo->setTexture(img->getTextura());
    corpo->setScale(aux.x, aux.y);
    corpo->setOrigin(sf::Vector2f(tamCorpo.x / 2.5f, tamCorpo.y / 2.0f));
}

void Jungle::Animador::Animacao::addAnimacao(const char* caminhoTextura, std::string nomeAnimacao, int qtdImagem, const float tempoTroda, const sf::Vector2f escala){
    Imagem* img = new Imagem(caminhoTextura, qtdImagem, tempoTroda, escala);
    mapImagem.insert(std::pair<std::string, Imagem*>(nomeAnimacao, img));
}