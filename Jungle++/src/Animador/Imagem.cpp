#include "../../include/Animador/Imagem.hpp"

Jungle::Animador::Imagem::Imagem(const char* caminhoTextura, unsigned int qtdImagem, const float tempoTroca, const sf::Vector2f escala, const sf::Vector2f origin, const bool horizontal):
    pGrafico(pGrafico->getGerenciadorGrafico()), qtdImagem(qtdImagem), tempoTroca(tempoTroca),
    tempoTotal(0.0f), tamanho(0,0,0,0), imgAtual(0), textura(pGrafico->carregarTextura(caminhoTextura)),
    escala(escala), origin(origin), horizontal(horizontal)
{
    if(horizontal){
        tamanho.width = textura.getSize().x / (float)qtdImagem;
        tamanho.height = textura.getSize().y;
    } else {
        tamanho.width = textura.getSize().x;
        tamanho.height = textura.getSize().y / (float)qtdImagem;
    }
}

Jungle::Animador::Imagem::~Imagem(){

}

void Jungle::Animador::Imagem::atualizar(const bool paraEsquerda, const float dt){
    tempoTotal = tempoTotal + dt;
    if(tempoTotal >= tempoTroca){
        tempoTotal -= tempoTroca;
        imgAtual++;
        if(imgAtual >= qtdImagem){
            imgAtual = 0;
        }
    }
    
    if(paraEsquerda){
        tamanho.width = -abs(tamanho.width);
        if(horizontal){
            tamanho.left = (imgAtual + 1) * abs(tamanho.width);
        } else {
            tamanho.top = imgAtual * tamanho.height;
            tamanho.left = abs(tamanho.width);
        }
    } else {
        tamanho.width = abs(tamanho.width);
        if(horizontal){
            tamanho.left = imgAtual * tamanho.width;
        } else {
            tamanho.top = imgAtual * tamanho.height;
            tamanho.left = 0.0f;
        }
    }
}

void Jungle::Animador::Imagem::resetar(){
    imgAtual = 0;
    tempoTotal = 0.0f;
}

const sf::IntRect Jungle::Animador::Imagem::getTamanho() const {
    return tamanho;
}

const sf::Texture* Jungle::Animador::Imagem::getTextura() const {
    return &textura;
}

const sf::Vector2f Jungle::Animador::Imagem::getEscala() const {
    return escala;
}

const sf::Vector2f Jungle::Animador::Imagem::getOrigin() const {
    return origin;
}