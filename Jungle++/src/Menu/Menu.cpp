#include "../../include/Menu/Menu.hpp"
#include "../../include/Observador/ObservadorMenu.hpp"

namespace Jungle {

    namespace Menu {

        Menu::Menu(const IDs::IDs ID, const sf::Vector2f tamBotao, const std::string nome, const unsigned int tamFonte):
            Ente(ID), listaBotaoTexto(), it(), tamBotao(tamBotao), 
            tamJanela(pGrafico->getTamJanela()), posFundo(sf::Vector2f(0.0f, 0.0f)),
            titulo(pGrafico->carregarFonte("Jungle++/fonte/menu.ttf"), nome, tamFonte),
            observadorMenu(new Observador::ObservadorMenu(this)), mouseSelecionado(false)
        {
            if(observadorMenu == nullptr){
                std::cout << "ERROR::Jungle::Menu::MenuPrincipal::nao foi possivel criar um Observador Menu Principal" << std::endl;
                exit(1);
            }
        }

        Menu::~Menu(){
            if(!listaBotaoTexto.empty()){
                for(it = listaBotaoTexto.begin(); it != listaBotaoTexto.end(); it++){
                    delete(*it);
                    *it = nullptr;
                }
                listaBotaoTexto.clear();
            }
            if(observadorMenu){
                delete(observadorMenu);
                observadorMenu = nullptr;
            }
        }

        void Menu::mudarEstadoObservador(){
            observadorMenu->mudarEstadoAtivar();
        }

        void Menu::addBotao(const std::string info, const sf::Vector2f pos, const IDs::IDs ID, const sf::Color corSelecionado){
            Botao::BotaoTexto* botao = new Botao::BotaoTexto(info, tamBotao, pos, ID, corSelecionado);
            if(botao == nullptr){
                throw("ERROR::Jungle::Menu::nao foi possivel criar um botao");
            }
            listaBotaoTexto.push_back(botao);
        }

        void Menu::atualizarPosicaoFundo(){
            posFundo = pGrafico->getCamera().getCenter();
        }

        void Menu::inicializarIterator(){
            try {
                it = listaBotaoTexto.begin();
                (*it)->setSelecionado(true);
            } catch(const std::exception& e)
            {
                std::cerr << e.what() << std::endl;
                exit(1);
            }
        }

        void Menu::selecionaCima(){
            Botao::BotaoTexto* botao = *it;
            botao->setSelecionado(false);
            if(it == listaBotaoTexto.begin()){
                it = listaBotaoTexto.end();
            }
            it--;
            botao = *it;
            botao->setSelecionado(true);
        }

        void Menu::selecionaBaixo(){
            Botao::BotaoTexto* botao = *it;
            botao->setSelecionado(false);
            it++;
            if(it == listaBotaoTexto.end()){
                it = listaBotaoTexto.begin();
            }
            botao = *it;
            botao->setSelecionado(true);
        }

        const IDs::IDs Menu::getIDBotaoSelecionado() const{
            return (*it)->getID();
        }

        void Menu::eventoMouse(const sf::Vector2f posMouse){
            std::list<Botao::BotaoTexto*>::iterator aux;
            mouseSelecionado = false;
            for(aux = listaBotaoTexto.begin(); aux != listaBotaoTexto.end(); aux++){
                Botao::BotaoTexto* botao = *aux;
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
            std::list<Botao::BotaoTexto*>::iterator aux;
            for(aux = listaBotaoTexto.begin(); aux != listaBotaoTexto.end(); aux++){
                Botao::BotaoTexto* botao = *aux;
                botao->desenhar();
                botao = nullptr;
            }
        }

    }

}