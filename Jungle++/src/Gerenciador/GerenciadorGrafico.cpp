#include "..\..\include\Gerenciador\GerenciadorGrafico.hpp"

Jungle::Gerenciador::GerenciadorGrafico* Jungle::Gerenciador::GerenciadorGrafico::pGrafico = nullptr;

Jungle::Gerenciador::GerenciadorGrafico::GerenciadorGrafico():
    window(new sf::RenderWindow(sf::VideoMode(800.0f, 600.0f), "Jungle++"))
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
        pGrafico = new GerenciadorGrafico();
    }
    return pGrafico;
}

sf::RenderWindow* Jungle::Gerenciador::GerenciadorGrafico::getWindow(){
    return window;
}

sf::Texture Jungle::Gerenciador::GerenciadorGrafico::carregarTextura(const char* caminhoTextura){
    //terminar...
    return sf::Texture();
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