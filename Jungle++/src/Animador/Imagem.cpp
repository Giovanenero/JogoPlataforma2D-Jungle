#include "../../include/Animador/Imagem.hpp"

namespace Jungle {

    namespace Animador {

        Imagem::Imagem(const char* caminhoTextura, unsigned int qtdImagem, const float tempoTroca, const sf::Vector2f escala, const sf::Vector2f origin, const bool horizontal):
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

        Imagem::~Imagem(){

        }

        void Imagem::atualizar(const bool paraEsquerda, const float dt){
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

        void Imagem::resetar(){
            imgAtual = 0;
            tempoTotal = 0.0f;
        }

        const unsigned int Imagem::getQuadroAtual() const{
            return imgAtual;
        }
        
        void Imagem::setQuadroAtual(const unsigned int imgAtual){
            this->imgAtual = imgAtual;
        }
        
        const float Imagem::getTempoTotal() const{
            return tempoTotal;
        }
        
        void Imagem::setTempoTotal(const float tempoTotal){
            this->tempoTotal = tempoTotal;
        }

        const sf::IntRect Imagem::getTamanho() const {
            return tamanho;
        }

        const sf::Texture* Imagem::getTextura() const {
            return &textura;
        }

        const sf::Vector2f Imagem::getEscala() const {
            return escala;
        }

        const sf::Vector2f Imagem::getOrigin() const {
            return origin;
        }

    }

}