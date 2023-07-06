#include "../../include/Animador/Animacao.hpp"

Jungle::Animador::Animacao::Animacao(sf::RectangleShape* corpo):
    corpo(corpo), mapImagem(), imgAtual(""), relogio()
{

}

Jungle::Animador::Animacao::~Animacao(){
    std::map<std::string, Imagem*>::iterator it = mapImagem.begin();
    while(it != mapImagem.end()){
        if(it->second){
            delete(it->second);
            it->second = nullptr;
        }
        it++;
    }
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
    corpo->setOrigin(img->getOrigin());
    corpo->setScale(escala.x, escala.y);
}

void Jungle::Animador::Animacao::addAnimacao(const char* caminhoTextura, std::string nomeAnimacao, const unsigned int qtdImagem, const float tempoTroda, const sf::Vector2f escala, const sf::Vector2f origin){
    Imagem* img = new Imagem(caminhoTextura, qtdImagem, tempoTroda, escala, origin);
    mapImagem.insert(std::pair<std::string, Imagem*>(nomeAnimacao, img));
}