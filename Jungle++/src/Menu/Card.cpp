#include "../../include/Menu/Card.hpp"

namespace Jungle {

    namespace Menu {

        Gerenciador::GerenciadorGrafico* Card::pGrafico = Gerenciador::GerenciadorGrafico::getGerenciadorGrafico();
            
        Card::Card(const sf::Vector2f pos, const std::string caminhoArquivo, const std::string caminhoImage):
            caminhoArquivo(caminhoArquivo), caminhoImage(caminhoImage), textura(nullptr), corpo(nullptr),
            cor(sf::Color(0, 255, 0)), existe(false)
        {
            sf::Vector2f tamJanela = pGrafico->getTamJanela();
            corpo = new sf::RectangleShape(sf::Vector2f(tamJanela.x / 5.0f, tamJanela.x / 5.0f - 20.0f));
            textura = new sf::Texture();
            if(textura->loadFromFile(caminhoImage)){
                //std::cout << "MenuSalvarJogada::nao foi possivel encontrar o caminho da textura " << caminhoImage << std::endl;
                //exit(1);
                //caminho de textura auxliar
                corpo->setTexture(textura);
                existe = true;
            } else {
                corpo->setFillColor(sf::Color::Black);
            }
            corpo->setPosition(pos);
            corpo->setOutlineThickness(8);
            corpo->setOutlineColor(sf::Color::Transparent);
        }

        Card::~Card(){
            if(textura != nullptr){
                delete(textura);
                textura = nullptr;
            }
            if(corpo != nullptr){
                delete(corpo);
                corpo = nullptr;
            }
        }

        const std::string Card::getCaminhoArquivo() const{
            return caminhoArquivo;
        }
            
        const std::string Card::getCaminhoImage() const{
            return caminhoImage;
        }

        void Card::setColor(const sf::Color cor){
            this->cor = cor;
        }

        void Card::setSelecionado(const bool selecionado){
            this->selecionado = selecionado;
            corpo->setOutlineColor(selecionado ? cor : sf::Color::Transparent);
        }
            
        const bool Card::getSelecionado() const{
            return selecionado;
        }

        const bool Card::getExiste() const{
            return existe;
        }

        void Card::desenhar(){
            pGrafico->desenhaElemento(*corpo);
        }

    }

}