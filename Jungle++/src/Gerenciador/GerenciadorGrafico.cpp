#include "..\..\include\Gerenciador\GerenciadorGrafico.hpp"


namespace Jungle {

    namespace Gerenciador {

        GerenciadorGrafico* GerenciadorGrafico::pGrafico = nullptr;

        GerenciadorGrafico::GerenciadorGrafico():
            window(new sf::RenderWindow(sf::VideoMode(TELA_X, TELA_Y), "Jungle++")),
            camera(sf::Vector2f(TELA_X / 2.0f, TELA_Y / 2.0f), sf::Vector2f(TELA_X, TELA_Y))
        {
            window->setFramerateLimit(0);
            if(window == nullptr){
                std::cout << "ERROR::Jungle::Gerenciador::GerenciadorGrafico nao foi possivel criar uma janela grafica" << std::endl;
                exit(1);
            }
        }

        GerenciadorGrafico::~GerenciadorGrafico(){
            if(window){
                delete(window);
                window = nullptr;
            }
        }

        GerenciadorGrafico* GerenciadorGrafico::getGerenciadorGrafico(){
            /**
             * @ return GerenciadorGrafico*
             * 
             * Padrão de Projeto Singleton: garante que eu tenha apenas uma instância no meu projeto como um todo, isto é,
             * não é possível criar dois objetos diferentes deste tipo.
             */

            if(pGrafico == nullptr){
                pGrafico =  new GerenciadorGrafico();
            }
            return pGrafico;
        }

        sf::RenderWindow* GerenciadorGrafico::getWindow(){
            return window;
        }

        sf::Texture GerenciadorGrafico::carregarTextura(const char* caminhoTextura){
            sf::Texture textura;
            if(!textura.loadFromFile(caminhoTextura)){
                std::cout << "ERRO::Jungle::Gerenciador::GerenciadorGrafico::nao foi possivel encontrar o caminho da textura - " << caminhoTextura << std::endl;
                exit(1); 
            }
            return textura;
        }

        sf::Font GerenciadorGrafico::carregarFonte(const char* caminhoFonte){
            sf::Font fonte;
            if(!fonte.loadFromFile(caminhoFonte)){
                throw("ERROR::Jungle::Gerenciador::GerenciadorGrafico::nao foi possivel encontrar o caminho da fonte");
            }
            return fonte;
        }

        void GerenciadorGrafico::limpaJanela(){
            window->clear();
        }

        void GerenciadorGrafico::desenhaElemento(sf::RectangleShape corpo){
            window->draw(corpo);
        }

        void GerenciadorGrafico::desenhaElemento(sf::Text texto){
            window->draw(texto);
        }

        void GerenciadorGrafico::mostraElementos(){
            window->display();
        }

        void GerenciadorGrafico::fecharJanela(){
            window->close();
        }

        const bool GerenciadorGrafico::verificaJanelaAberta(){
            return window->isOpen();
        }

        void GerenciadorGrafico::atualizarCamera(const sf::Vector2f pos){
            camera.setCenter(pos);
            window->setView(camera);
        }

        const sf::View GerenciadorGrafico::getCamera(){
            return camera;
        }

        void GerenciadorGrafico::resetarJanela(){
            camera.setCenter(TELA_X / 2.0f, TELA_Y / 2.0f);
            window->setView(camera);
        }

        const sf::Vector2f GerenciadorGrafico::getTamJanela() const{
            return (sf::Vector2f)window->getSize();
        }

    }

}