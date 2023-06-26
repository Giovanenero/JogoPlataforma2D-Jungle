#include "..\..\include\Menu\MenuOpcao.hpp"

namespace Jungle {

    Gerenciador::GerenciadorMusica* Menu::MenuOpcao::pMusica = Gerenciador::GerenciadorMusica::getGerenciadorMusica();

    namespace Menu {

        MenuOpcao::MenuOpcao():
            Menu(IDs::IDs::menu_opcao, sf::Vector2f(TAMANHO_BOTAO_MENU_OPCAO_X, TAMANHO_BOTAO_MENU_OPCAO_Y), "Opcoes", 100),
            velocidadeBotao(VELOCIDADE_BOTAO_VOLUME)
        {

        }

        MenuOpcao::~MenuOpcao(){

        }

        void MenuOpcao::addBotao(const std::string info, const sf::Vector2f pos, const IDs::IDs ID, const sf::Color corSelecionado, const float posInicioFundo){
            Botao::BotaoVolume* botaoVolume = new Botao::BotaoVolume(info, tamBotao, pos, ID, corSelecionado, posInicioFundo);
            if(botaoVolume == nullptr){
                throw("ERROR::Jungle::Menu::nao foi possivel criar um botao");
            }
            listaBotaoTexto.push_back(static_cast<Botao::BotaoTexto*>(botaoVolume));
        }

        void MenuOpcao::alterarVolume(const bool aumentando){
            if(getIDBotaoSelecionado() != IDs::IDs::botao_voltar){
                std::list<Botao::BotaoTexto*>::iterator it_botao = listaBotaoTexto.begin();
                while((*it_botao)->getID() != getIDBotaoSelecionado()){
                    it_botao++;
                }
                Botao::BotaoVolume* botaoVolume = static_cast<Botao::BotaoVolume*>(*it_botao);
                short aux = 1;
                if(!aumentando){
                    aux = -1;
                }
                atualizarVolume(velocidadeBotao * aux, botaoVolume);
            }
        }

        void MenuOpcao::atualizarVolume(const float volume, Botao::BotaoVolume* botaoVolume){
            if(botaoVolume->getID() == IDs::IDs::botao_volume_geral){
                std::list<Botao::BotaoTexto*>::iterator aux = listaBotaoTexto.begin();
                while (aux != listaBotaoTexto.end())
                {
                    botaoVolume = static_cast<Botao::BotaoVolume*>(*aux);
                    botaoVolume->alterarVolume(volume);
                    aux++;
                }
            } else {
                botaoVolume->alterarVolume(volume);
            }
        }

    }

}