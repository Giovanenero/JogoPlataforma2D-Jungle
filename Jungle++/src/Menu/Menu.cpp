#include "..\..\include\Menu\Menu.hpp"

namespace Jungle {

    namespace Menu {

        Menu::Menu(const IDs::IDs ID, const sf::Vector2f tamBotao, const std::string nome, const unsigned int tamFonte):
            Ente(ID), listaBotao(), it(), tamBotao(tamBotao), tamJanela(pGrafico->getTamJanela()), posFundo(sf::Vector2f(0.0f, 0.0f)),
            nomeMenu(pGrafico->carregarFonte("Jungle++/fonte/menu.ttf"), nome, tamFonte)
        {

        }

        Menu::~Menu(){
            if(!listaBotao.empty()){
                for(it = listaBotao.begin(); it != listaBotao.end(); it++){
                    delete(*it);
                    *it = nullptr;
                }
                listaBotao.clear();
            }
        }

        void Menu::addBotao(const std::string info, const sf::Vector2f pos, const IDs::IDs ID, const sf::Color corSelecionado){
            Botao::Botao* botao = new Botao::Botao(info, tamBotao, pos, ID, corSelecionado);
            if(botao == nullptr){
                throw("ERROR::Jungle::Menu::nao foi possivel criar um botao");
            }
            listaBotao.push_back(botao);
        }

        void Menu::atualizarPosicaoFundo(){
            posFundo = pGrafico->getCamera().getCenter();
        }

        void Menu::selecionaCima(){
            Botao::Botao* botao = *it;
            botao->setSelecionado(false);
            if(it == listaBotao.begin()){
                it = listaBotao.end();
            }
            it--;
            botao = *it;
            botao->setSelecionado(true);
        }

        void Menu::selecionaBaixo(){
            Botao::Botao* botao = *it;
            botao->setSelecionado(false);
            it++;
            if(it == listaBotao.end()){
                it = listaBotao.begin();
            }
            botao = *it;
            botao->setSelecionado(true);
        }

        const IDs::IDs Menu::getIDBotaoSelecionado(){
            return (*it)->getID();
        }

        void Menu::eventoMouse(const sf::Vector2f posMouse){
            std::list<Botao::Botao*>::iterator aux;
            mouseSelecionado = false;
            for(aux = listaBotao.begin(); aux != listaBotao.end(); aux++){
                Botao::Botao* botao = *aux;
                sf::Vector2f posBotao = botao->getPos();
                sf::Vector2f posCamera = pGrafico->getCamera().getCenter();
                if(posMouse.x + posCamera.x - tamJanela.x / 2.0f > posBotao.x && posMouse.x + posCamera.x - tamJanela.x / 2.0f < posBotao.x + tamBotao.x && 
                   posMouse.y + posCamera.y - tamJanela.y / 2.0f > posBotao.y && posMouse.y + posCamera.y - tamJanela.y / 2.0f < posBotao.y + tamBotao.y){
                    (*it)->setSelecionado(false);
                    it = aux;
                    (*it)->setSelecionado(true);
                    mouseSelecionado = true;
                    break;
                }
            }
        }

        const bool Menu::getMouseSelecionado() const{
            return mouseSelecionado;
        }

        void Menu::desenhar(){
            //desenha todos os botões na janela
            std::list<Botao::Botao*>::iterator aux;
            for(aux = listaBotao.begin(); aux != listaBotao.end(); aux++){
                Botao::Botao* botao = *aux;
                botao->desenhar();
                botao = nullptr;
            }
        }

    }

}