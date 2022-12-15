#include "..\..\include\Menu\Menu.hpp"

namespace Jungle {

    namespace Menu {

        Menu::Menu(const IDs::IDs ID, const sf::Vector2f tamBotao):
            Ente(ID), listaBotao(), it(), tamBotao(tamBotao)
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

        void Menu::addBotao(const std::string info, const sf::Vector2f pos, const IDs::IDs ID){
            Botao::Botao* botao = new Botao::Botao(info, tamBotao, pos, ID);
            if(botao == nullptr){
                throw("ERROR::Jungle::Menu::nao foi possivel criar um botao");
            }
            listaBotao.push_back(botao);
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