#include "../../include/Animador/Animacao.hpp"

namespace Jungle {

    namespace Animador {

        Animacao::Animacao(sf::RectangleShape* corpo):
            corpo(corpo), mapImagem(), imgAtual(""), relogio()
        {

        }

        Animacao::~Animacao(){
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

        const std::string Animacao::getImgAtual() const{
            return this->imgAtual;
        }

        const unsigned int Animacao::getQuadroAtual(){
            return mapImagem[this->imgAtual]->getQuadroAtual();
        }
        
        void Animacao::setQuadroAtual(const unsigned int imgAtual){
            mapImagem[this->imgAtual]->setQuadroAtual(imgAtual);
        }
        
        const float Animacao::getTempoTotal(){
            return mapImagem[this->imgAtual]->getTempoTotal();
        }
        
        void Animacao::setTempoTotal(const float tempoTotal){
            mapImagem[this->imgAtual]->setTempoTotal(tempoTotal);
        }
        
        void Animacao::setImgAtual(const std::string imgAtual){
            this->imgAtual = imgAtual;
        }

        void Animacao::atualizar(const bool paraEsquerda, std::string imgAtual){
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

        void Animacao::addAnimacao(const char* caminhoTextura, std::string nomeAnimacao, const unsigned int qtdImagem, const float tempoTroda, const sf::Vector2f escala, const sf::Vector2f origin, const bool horizontal){
            Imagem* img = new Imagem(caminhoTextura, qtdImagem, tempoTroda, escala, origin, horizontal);
            mapImagem.insert(std::pair<std::string, Imagem*>(nomeAnimacao, img));
        }

    }

}