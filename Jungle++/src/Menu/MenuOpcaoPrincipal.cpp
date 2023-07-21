#include "../../include/Menu/MenuOpcaoPrincipal.hpp"
//#include "../../include/Observador/ObservadorMenuOpcao.hpp"

namespace Jungle {

    namespace Menu {

        MenuOpcaoPrincipal::MenuOpcaoPrincipal():
            MenuPrincipal(IDs::IDs::menu_opcao, "Opcoes", 100),
            velocidadeBotao(VELOCIDADE_BOTAO_VOLUME)
        {
            titulo.setCorTexto(sf::Color{0,255,0});
            titulo.setPos(sf::Vector2f(tamJanela.x / 2.0f - titulo.getTam().x / 2.0f, 25.0f));
        }

        MenuOpcaoPrincipal::~MenuOpcaoPrincipal(){
            
        }

        void MenuOpcaoPrincipal::addBotao(const std::string info, const sf::Vector2f pos, const IDs::IDs ID, const sf::Color corSelecionado, const float posInicioFundo){
            Botao::BotaoVolume* botaoVolume = new Botao::BotaoVolume(info, tamBotao, pos, ID, corSelecionado, posInicioFundo);
            if(botaoVolume == nullptr){
                throw("ERROR::Jungle::Menu::nao foi possivel criar um botao");
            }
            listaBotaoTexto.push_back(static_cast<Botao::BotaoTexto*>(botaoVolume));
        }

        void MenuOpcaoPrincipal::criarBotoes(){
            addBotao("Volume Menu", sf::Vector2f(25.0f, 250.0f), IDs::IDs::botao_volume_menu, sf::Color{0,255,0}, 20.0f);
            addBotao("Volume Jogo", sf::Vector2f(25.0f, 300.0f), IDs::IDs::botao_volume_jogo, sf::Color{0,255,0}, 20.0f);
            addBotao("Volume Geral", sf::Vector2f(25.0f, 350.0f), IDs::IDs::botao_volume_geral, sf::Color{0,255,0}, 20.0f);

            Menu::addBotao("Voltar", sf::Vector2f(tamJanela.x / 2.0f - tamBotao.x / 2.0f, 450.0f), IDs::IDs::botao_voltar, sf::Color{0,255,0});
            inicializarIterator();
        }

        void MenuOpcaoPrincipal::alterarVolume(const bool aumentando){
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

        void MenuOpcaoPrincipal::atualizarVolume(const float volume, Botao::BotaoVolume* botaoVolume){
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

        void MenuOpcaoPrincipal::selecionaEsquerda(){
            alterarVolume(false);
        }
        
        void MenuOpcaoPrincipal::selecionaDireita(){
            alterarVolume(true);
        }

        void MenuOpcaoPrincipal::executar(){
            //conteúdo do efeito Parallax
            posFundo = sf::Vector2f(posFundo.x + pGrafico->getTempo() * 80.0f, posFundo.y);
            pGrafico->atualizarCamera(sf::Vector2f(posFundo.x + tamJanela.x / 2.0f, posFundo.y + tamJanela.y / 2.0f));
            fundo.executar();
            pGrafico->resetarJanela();

            desenhar();
            pGrafico->desenhaElemento(titulo.getTexto());
        }

    }

}