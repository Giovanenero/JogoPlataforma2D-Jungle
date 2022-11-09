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
    sf::Vector2f escala = img->getEscala();
    
    img->atualizar(paraEsquerda, dt);
    corpo->setTextureRect(img->getTamanho());
    corpo->setTexture(img->getTextura());
    corpo->setScale(escala.x, escala.y);
}

void Jungle::Animador::Animacao::addAnimacao(const char* caminhoTextura, std::string nomeAnimacao, const unsigned int qtdImagem, const float tempoTroda, const sf::Vector2f escala){
    Imagem* img = new Imagem(caminhoTextura, qtdImagem, tempoTroda, escala);
    mapImagem.insert(std::pair<std::string, Imagem*>(nomeAnimacao, img));
}