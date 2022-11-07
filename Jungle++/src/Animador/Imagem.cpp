#include "..\..\include\Animador\Imagem.hpp"

Jungle::Animador::Imagem::Imagem(const char* caminhoTextura, unsigned int qtdImagem, const float tempoTroca):
    pGrafico(pGrafico->getGerenciadorGrafico()), qtdImagem(qtdImagem), 
    textura(pGrafico->carregarTextura(caminhoTextura)), tempoTroca(tempoTroca),
    tempoTotal(0.0f)
{
    tamanho.width = textura.getSize().x / qtdImagem;
    tamanho.height = textura.getSize().y;
}

Jungle::Animador::Imagem::~Imagem(){

}

void Jungle::Animador::Imagem::atualizar(const bool paraEsquerda, const float dt){
    tempoTotal += dt;
    if(tempoTotal >= tempoTroca){
        tempoTotal -= tempoTroca;
        imgAtual++;
        if(imgAtual >= qtdImagem){
            imgAtual = 0;
        }
        tamanho.left = imgAtual * tamanho.width;
    }
}

const sf::IntRect Jungle::Animador::Imagem::getTamanho() const{
    return tamanho;
}