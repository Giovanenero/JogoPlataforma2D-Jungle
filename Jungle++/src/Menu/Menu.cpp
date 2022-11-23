#include "..\..\include\Menu\Menu.hpp"

namespace Jungle {

    namespace Menu {

        Menu::Menu(const IDs::IDs ID, const sf::Vector2f tamBotao):
            Ente(ID), listaBotao(), it(), textura(), tamBotao(tamBotao), tamJanela(pGrafico->getTamJanela())
        {
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

        void Menu::addBotao(const std::string texto, const sf::Vector2f pos){
            Botao::Botao* botao = new Botao::Botao(texto, tamBotao, pos);
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