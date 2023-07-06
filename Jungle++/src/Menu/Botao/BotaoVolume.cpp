#include "../../../include/Menu/Botao/BotaoVolume.hpp"

namespace Jungle {

    Gerenciador::GerenciadorMusica* Menu::Botao::BotaoVolume::pMusica = Gerenciador::GerenciadorMusica::getGerenciadorMusica();

    namespace Menu {

        namespace Botao {

            BotaoVolume::BotaoVolume(const std::string info, const sf::Vector2f tam,const sf::Vector2f pos, const IDs::IDs ID, const sf::Color corSelecionado, const float posInicioFundo):
                BotaoTexto(info, tam, pos, ID, corSelecionado), posInicioFundo(posInicioFundo),
                fundoVolume(sf::Vector2f(TAMANHO_BARRA_VOLUME_X, TAMANHO_BARRA_VOLUME_Y)),
                corpoVolume(sf::Vector2f(TAMANHO_BOTAO_VOLUME_X, TAMANHO_BOTAO_VOLUME_Y)),
                parametrizacao((TAMANHO_BARRA_VOLUME_X - TAMANHO_BOTAO_VOLUME_X) / 100.0f),
                posInicioBarra(pGrafico->getCamera().getCenter().x + posInicioFundo),
                posFimBarra(pGrafico->getCamera().getCenter().x + posInicioFundo + TAMANHO_BARRA_VOLUME_X)
            {
                fundoVolume.setFillColor(sf::Color::Black);
                fundoVolume.setPosition(sf::Vector2f(pGrafico->getCamera().getCenter().x + posInicioFundo, getPos().y + getTamTexto().y - 5.0f));
                
                corpoVolume.setFillColor(sf::Color{0,255,0,150});
                float volume = 0.0f;
                switch (ID)
                {
                    case (IDs::IDs::botao_volume_jogo):
                    {
                        volume = pMusica->getVolume(IDs::IDs::jogar_florestaBranca);
                    }
                        break;
                    case (IDs::IDs::botao_volume_menu):
                    {
                        volume = pMusica->getVolume(IDs::IDs::estado_menu_principal);
                    }
                        break;
                    case (IDs::IDs::botao_volume_geral):
                    {
                        volume = pMusica->getVolumeGeral();
                    }
                        break;
                }
                corpoVolume.setPosition(sf::Vector2f(volume * parametrizacao + pGrafico->getCamera().getCenter().x + posInicioFundo, getPos().y + getTamTexto().y - 5.0f));
            }

            BotaoVolume::~BotaoVolume(){

            }

            void BotaoVolume::alterarVolume(const float volume){
                sf::Vector2f posVolume = corpoVolume.getPosition();
                posVolume.x += volume;
                if(posVolume.x + TAMANHO_BOTAO_VOLUME_X > posFimBarra){
                    posVolume.x = posFimBarra - TAMANHO_BOTAO_VOLUME_X;
                } else if(posVolume.x < posInicioBarra){
                    posVolume.x = posInicioBarra;
                }
                corpoVolume.setPosition(posVolume);
                atualizarVolume();
            }

            void BotaoVolume::atualizarVolume(){
                const float vol = ((corpoVolume.getPosition().x - posFimBarra + TAMANHO_BOTAO_VOLUME_X) / parametrizacao) + 100.0f;
                switch (getID())
                {
                    case (IDs::IDs::botao_volume_jogo):
                    {
                        pMusica->setVolume(vol, IDs::IDs::jogar_florestaBranca);
                        pMusica->setVolume(vol, IDs::IDs::jogar_florestaVermelha);
                    }
                        break;
                    case (IDs::IDs::botao_volume_menu):
                    {
                        pMusica->setVolume(vol, IDs::IDs::estado_menu_principal);
                        pMusica->setVolume(vol, IDs::IDs::estado_menu_pausa);
                    }
                        break;
                    case (IDs::IDs::botao_volume_geral):
                    {
                        pMusica->setVolumeGeral(vol);
                    }
                        break;
                }
            }

            void BotaoVolume::desenhar(){
                atualizarAnimacao();
                //pGrafico->desenhaElemento(caixaTexto);
                pGrafico->desenhaElemento(fundoVolume);
                pGrafico->desenhaElemento(corpoVolume);
                pGrafico->desenhaElemento(texto.getTexto());
            }

        }

    }

}