#include "../../include/Parallax/Camada.hpp"

namespace Jungle {

    namespace Parallax {

        Camada::Camada(const sf::Vector2f tamJanela, sf::Texture textura, const float vel):
            tamJanela(tamJanela), textura(textura), dimensao(0,0,0,0), vel(vel)
        {
            dimensao.width = -abs(textura.getSize().x);
            dimensao.height = textura.getSize().y;
            dimensao.left = textura.getSize().x;

            fundo.setSize(tamJanela);
            fundo.setTexture(&this->textura);
            fundo.setPosition(0.0f, 0.0f);
            
            fundoAuxiliar.setSize(tamJanela);
            fundoAuxiliar.setTexture(&this->textura);
            fundoAuxiliar.setPosition(tamJanela.x, 0.0f);
        }

        Camada::~Camada(){

        }

        void Camada::trocarTextura(){
            sf::RectangleShape trocar = fundo;
            fundo = fundoAuxiliar;
            fundoAuxiliar = trocar;
        }

        void Camada::desenharCamada(sf::RenderWindow* window){
            window->draw(fundo);
            if(vel != 0.0f){
                window->draw(fundoAuxiliar);
            }
        }

        void Camada::atualizar(const sf::Vector2f ds, const sf::Vector2f posCameraAtual){
            const float y = posCameraAtual.y - tamJanela.y / 2.0f;
            sf::Vector2f posFundo = fundo.getPosition();
            sf::Vector2f posFundoAux = fundoAuxiliar.getPosition();
            fundo.setPosition(sf::Vector2f(posFundo.x, y));
            fundoAuxiliar.setPosition(sf::Vector2f(posFundoAux.x, y));
            const float dx = ds.x * 0.5f;

            if(dx != 0.0f){
                const float posDireita = posCameraAtual.x + tamJanela.x / 2.0f;
                const float posEsquerda = posCameraAtual.x - tamJanela.x / 2.0f;

                if(vel != 0.0f){
                    //aplicando o movimento contrário para as camadas
                    fundo.move(dx * -vel, 0.0f);
                    fundoAuxiliar.move(dx * -vel, 0.0f);

                    if(ds.x > 0.0f){ // camera movendo para a direita
                        if(posFundo.x + tamJanela.x < posEsquerda){
                            trocarTextura();
                            fundo.setPosition(posEsquerda, posFundo.y);
                            fundoAuxiliar.setPosition(posDireita, posFundoAux.y);
                        }

                    } else { // camera movendo para a esquerda
                        if(posFundo.x > posEsquerda){
                            trocarTextura();
                            fundo.setPosition(posEsquerda - tamJanela.x, posFundo.y);
                            fundoAuxiliar.setPosition(posEsquerda, posFundoAux.y);
                        }
                    }
                } else {
                    fundo.setPosition(posEsquerda, posFundo.y);
                }
            }
        }

    }

}