#include "..\..\include\Gerenciador\GerenciadorGrafico.hpp"

Jungle::Gerenciador::GerenciadorGrafico* Jungle::Gerenciador::GerenciadorGrafico::pGrafico = nullptr;

Jungle::Gerenciador::GerenciadorGrafico::GerenciadorGrafico():
    window(new sf::RenderWindow(sf::VideoMode(TELA_X, TELA_Y), "Jungle++")),
    camera(sf::Vector2f(TELA_X / 2.0f, TELA_Y / 2.0f), sf::Vector2f(TELA_X, TELA_Y))
{
    if(window == nullptr){
        std::cout << "ERROR::Jungle::Gerenciador::GerenciadorGrafico nao foi possivel criar uma janela grafica" << std::endl;
        exit(1);
    }
}

Jungle::Gerenciador::GerenciadorGrafico::~GerenciadorGrafico(){
    if(window){
        delete(window);
        window = nullptr;
    }
}

Jungle::Gerenciador::GerenciadorGrafico* Jungle::Gerenciador::GerenciadorGrafico::getGerenciadorGrafico(){
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

sf::RenderWindow* Jungle::Gerenciador::GerenciadorGrafico::getWindow(){
    return window;
}

sf::Texture Jungle::Gerenciador::GerenciadorGrafico::carregarTextura(const char* caminhoTextura){
    sf::Texture textura;
    if(!textura.loadFromFile(caminhoTextura)){
        std::cout << "ERRO::Jungle::Gerenciador::GerenciadorGrafico::nao foi possivel encontrar o caminho da textura - " << caminhoTextura << std::endl;
        exit(1); 
    }
    return textura;
}

void Jungle::Gerenciador::GerenciadorGrafico::limpaJanela(){
    window->clear();
}

void Jungle::Gerenciador::GerenciadorGrafico::desenhaElemento(sf::RectangleShape corpo){
    window->draw(corpo);
}

void Jungle::Gerenciador::GerenciadorGrafico::mostraElementos(){
    window->display();
}

void Jungle::Gerenciador::GerenciadorGrafico::fecharJanela(){
    window->close();
}

const bool Jungle::Gerenciador::GerenciadorGrafico::verificaJanelaAberta(){
    return window->isOpen();
}

void Jungle::Gerenciador::GerenciadorGrafico::atualizarCamera(const sf::Vector2f posJogador){
    camera.setCenter(posJogador.x, 300.0f);
    window->setView(camera);
}

const sf::View Jungle::Gerenciador::GerenciadorGrafico::getCamera(){
    return camera;
}