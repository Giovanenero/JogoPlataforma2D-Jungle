#include "../../include/Gerenciador/Camera.hpp"
#include "../../include/Gerenciador/GerenciadorGrafico.hpp"

namespace Jungle {

    namespace Gerenciador {

        Camera::Camera(const sf::Vector2f tamJanela):
            limiteCamera(sf::IntRect(-1, -1, -1, -1)), tamJanela(tamJanela),
            camera(sf::Vector2f(tamJanela.x / 2.0f, tamJanela.y / 2.0f), tamJanela),
            limiteObjeto(sf::IntRect(-1, -1, -1, -1))
        {
            
        }
        
        Camera::~Camera(){

        }
        
        void Camera::setLimiteCamera(const sf::IntRect limiteCamera){
            this->limiteCamera = limiteCamera;
        }

        sf::View Camera::getCamera(){
            return camera;
        }

        void Camera::resetar(const sf::Vector2f posCenter){
            camera.setCenter(posCenter);
        }

        void Camera::inicializarLimite(const sf::Vector2f pos, const sf::Vector2f tam){
            limiteObjeto.width = tamJanela.x / 5.0f;
            limiteObjeto.height = tamJanela.y / 2.8f;
            limiteObjeto.left = pos.x - limiteObjeto.width / 2.0f + tam.x / 2.0f;
            limiteObjeto.top = pos.y - limiteObjeto.height / 2.0f + tam.y / 2.0f;
        }
        
        void Camera::atualizar(const sf::Vector2f pos){
            camera.setCenter(pos);
        }

        void Camera::atualizar(const sf::Vector2f pos, sf::Vector2f tam){
            //seguit jogador
            sf::RectangleShape corpo2(sf::Vector2f(limiteCamera.width, limiteCamera.height));
            corpo2.setPosition(sf::Vector2f(limiteCamera.left, limiteCamera.top));
            corpo2.setFillColor(sf::Color::Blue);
            GerenciadorGrafico* pGrafico = GerenciadorGrafico::getGerenciadorGrafico();
            pGrafico->desenhaElemento(corpo2);

            sf::RectangleShape corpo(sf::Vector2f(limiteObjeto.width, limiteObjeto.height));
            corpo.setPosition(sf::Vector2f(limiteObjeto.left, limiteObjeto.top));
            corpo.setFillColor(sf::Color::Yellow);
            pGrafico->desenhaElemento(corpo);

            sf::Vector2f ds(0.0f, 0.0f);
            sf::Vector2f center = camera.getCenter();
            bool atualizarCamera = false;
            if(pos.x + tam.x > limiteObjeto.left + limiteObjeto.width){
                if(limiteObjeto.left + limiteObjeto.width < limiteCamera.left + limiteCamera.width){
                    ds.x = (pos.x + tam.x) - (limiteObjeto.left + limiteObjeto.width);
                    center.x = pos.x + tam.x - limiteObjeto.width / 2.0f;
                    atualizarCamera = true;
                }
            } else if(pos.x < limiteObjeto.left){
                if(limiteObjeto.left > limiteCamera.left){
                    ds.x = pos.x  - limiteObjeto.left;
                    center.x = pos.x + limiteObjeto.width / 2.0f;
                    atualizarCamera = true;
                }
            }
            if(pos.y + tam.y > limiteObjeto.top + limiteObjeto.height){
                if(limiteObjeto.top + limiteObjeto.height < limiteCamera.top + limiteCamera.height){
                    ds.y = (pos.y + tam.y) - (limiteObjeto.top + limiteObjeto.height);
                    center.y = pos.y + tam.y - limiteObjeto.height / 2.0f;
                    atualizarCamera = true;
                }
            } else if(pos.y < limiteObjeto.top){
                if(limiteObjeto.top > limiteCamera.top){
                    ds.y = pos.y - limiteObjeto.top;
                    center.y = pos.y + limiteObjeto.height / 2.0f;
                    atualizarCamera = true;
                }
            }
            if(atualizarCamera){
                limiteObjeto.left += ds.x;
                limiteObjeto.top += ds.y;
                camera.setCenter(center);
            }


        }

    }

}