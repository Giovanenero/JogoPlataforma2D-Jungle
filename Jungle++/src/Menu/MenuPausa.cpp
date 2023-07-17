#include "../../include/Menu/MenuPausa.hpp"
#include "../../include/Observador/ObservadorMenu.hpp"

namespace Jungle {

    namespace Menu {

        MenuPausa::MenuPausa(Fase::Fase* fase):
            Menu(IDs::IDs::menu_pausa, sf::Vector2f(TAMANHO_BOTAO_X, TAMANHO_BOTAO_Y), "PAUSA", 100),
            fase(fase), fundoEscuro(tamJanela), fundoPainel(sf::Vector2f(tamJanela.x / 2.0f, tamJanela.y))
        {
            atualizarPosicaoFundo();
            titulo.setCorTexto(sf::Color{255,0,0});
            fundoEscuro.setFillColor(sf::Color{0, 0, 0, 180});
            fundoPainel.setFillColor(sf::Color{0, 0, 0, 220});
            sf::Vector2f posFundoEscuro = sf::Vector2f(posFundo.x - tamJanela.x / 2.0f, posFundo.y - tamJanela.y / 2.0f);
            fundoEscuro.setPosition(posFundoEscuro);
            fundoPainel.setPosition(sf::Vector2f(posFundoEscuro.x + tamJanela.x / 4.0f, posFundoEscuro.y));
            titulo.setPos(sf::Vector2f(posFundo.x - titulo.getTam().x / 2.1f, posFundo.y - tamJanela.y / 2.0f));
        }

        MenuPausa::MenuPausa(const IDs::IDs ID, const std::string nome, Fase::Fase* fase): 
            Menu(ID, sf::Vector2f(TAMANHO_BOTAO_X, TAMANHO_BOTAO_Y), nome, 100), fase(fase),
            fundoEscuro(tamJanela)
        {
            titulo.setCorTexto(sf::Color{255,0,0});
            fundoEscuro.setFillColor(sf::Color{0, 0, 0, 180});
        }

        MenuPausa::~MenuPausa(){
            
        }

        void MenuPausa::criarBotoes(){
            addBotao("Voltar", sf::Vector2f(0.0f, 0.0f), IDs::IDs::botao_voltar, sf::Color{255, 0, 0});
            addBotao("Salvar Jogada", sf::Vector2f(0.0f, 0.0f), IDs::IDs::botao_salvar_jogada, sf::Color{255, 0, 0});
            addBotao("Opcao", sf::Vector2f(0.0f, 0.0f), IDs::IDs::botao_opcao, sf::Color{255, 0, 0});
            addBotao("Sair", sf::Vector2f(0.0f, 0.0f), IDs::IDs::botao_sair, sf::Color{255, 0, 0});
            posBotaoY = 1.5f;
            atualizarBotoes();
            inicializarIterator();
        }

        void MenuPausa::setFase(Fase::Fase* fase){
            this->fase = fase;
        }

        Fase::Fase* MenuPausa::getFase(){
            return fase;
        }

        void MenuPausa::atualizarBotoes(){
            std::list<Botao::BotaoTexto*>::iterator aux;
            int i = 1;
            for(aux = listaBotaoTexto.begin(); aux != listaBotaoTexto.end(); aux++, i++){
                Botao::BotaoTexto* botao = *aux;
                botao->atualizarPosicaoCaixa(sf::Vector2f(posFundo.x - tamBotao.x / 2.0f, posFundo.y / posBotaoY + (tamBotao.y + 20.f) * i));
                botao = nullptr;
            }

            desenhar();
        }

        void MenuPausa::executar(){
            //somente pinta as entidades
            fase->desenhar();

            //atualiza o menu pausar
            pGrafico->desenhaElemento(fundoEscuro);
            pGrafico->desenhaElemento(fundoPainel);


            pGrafico->desenhaElemento(titulo.getTexto());

            desenhar();
        }

    }

}