#include "..\..\include\Menu\Menu.hpp"

namespace Jungle {

    namespace Menu {

        Menu::Menu(const IDs::IDs ID):
            Ente(ID), listaBotao(), it(), textura()
        {
            const sf::Vector2f tamJanela =(sf::Vector2f)pGrafico->getWindow()->getSize();
            fundo = sf::RectangleShape(tamJanela);
            fundo.setPosition(0.0f, 0.0f);
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

        void Menu::addBotao(const std::string texto){
            Botao::Botao* botao = new Botao::Botao(texto);
            if(botao == nullptr){
                throw("ERROR::Jungle::Menu::nao foi possivel criar um botao");
            }
            listaBotao.push_back(botao);
        }

        void Menu::desenhar(){
            //desenha fundo e todos os botões e textos na janela gráfica
            pGrafico->resetarJanela();
            pGrafico->desenhaElemento(fundo);
            for(it = listaBotao.begin(); it != listaBotao.end(); it++){
                Botao::Botao* botao = *it;
                botao->desenhar();
                botao = nullptr;
            }
        }

    }

}