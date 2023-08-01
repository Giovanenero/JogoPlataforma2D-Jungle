#include "../../include/Menu/Card.hpp"
#include "../../include/Gerenciador/GerenciadorArquivo.hpp"

namespace Jungle {

    namespace Menu {

        Gerenciador::GerenciadorGrafico* Card::pGrafico = Gerenciador::GerenciadorGrafico::getGerenciadorGrafico();
            
        Card::Card(const sf::Vector2f pos, const std::string caminhoArquivoEntidades, const std::string caminhoArquivoFase, const std::string caminhoImage):
            caminhoArquivoEntidades(caminhoArquivoEntidades), caminhoArquivoFase(caminhoArquivoFase),
            textoInfo(pGrafico->carregarFonte(CAMINHO_FONTE_CARD), "", 25), caminhoImage(caminhoImage),
            textura(nullptr), corpo(nullptr), selecionado(false),
            cor(sf::Color(0, 255, 0)), existe(false)
        {
            sf::Vector2f tamJanela = pGrafico->getTamJanela();
            corpo = new sf::RectangleShape(sf::Vector2f(tamJanela.x / 5.0f, tamJanela.x / 5.0f - 20.0f));
            textura = new sf::Texture();
            if(textura->loadFromFile(caminhoImage)){
                corpo->setTexture(textura);
                existe = true;
                Gerenciador::GerenciadorArquivo GArquivo;
                std::vector<std::string> vectorInfoFase = GArquivo.lerArquivo(caminhoArquivoFase.c_str());
                std::string pontos = vectorInfoFase[1];
                while(pontos.size() < 5){
                    std::string aux = pontos;
                    pontos = '0' + pontos;
                }
                std::string textoInfoAux = "Pontos: " + pontos;
                textoInfoAux += 10;
                textoInfoAux +=  vectorInfoFase[2];
                textoInfo.setString(textoInfoAux);
                textoInfo.setPos(sf::Vector2f(
                    pos.x + corpo->getSize().x / 2.0f - textoInfo.getTam().x / 2.0f, 
                    pos.y + corpo->getSize().y + 10.0f
                ));
                textoInfo.setTamanhoBorda(2);
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

        const std::string Card::getCaminhoArquivoEntidades() const{
            return caminhoArquivoEntidades;
        }

        const std::string Card::getCaminhoArquivoFase() const{
            return caminhoArquivoFase;
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

        void Card::deletar(){
            if(textura){
                delete(textura);
                textura = nullptr;
            }
            corpo->setTexture(nullptr);
            corpo->setFillColor(sf::Color::Black);
            textoInfo.setString("");
            existe = false;
        }

        void Card::desenhar(){
            pGrafico->desenhaElemento(*corpo);
            if(selecionado){
                pGrafico->desenhaElemento(textoInfo.getTexto());
            }
        }

    }

}