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

        void Menu::atualizarPosicaoBotoes(sf::Vector2f pos){
            std::list<Botao::Botao*>::iterator aux;
            int i = 1;
            for(aux = listaBotao.begin(); aux != listaBotao.end(); aux++, i++){
                Botao::Botao* botao = *aux;
                pos = sf::Vector2f(pos.x, pos.y + (i * tamBotao.y * 0.6f));
                botao->atualizarPosicao(pos);
                botao = nullptr;
            }
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