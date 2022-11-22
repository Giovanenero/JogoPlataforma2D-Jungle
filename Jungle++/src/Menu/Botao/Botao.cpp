#include "..\..\..\include\Menu\Botao\Botao.hpp"

namespace Jungle {

    namespace Menu {

        namespace Botao {

            Botao::Botao(const std::string texto):
                Ente(IDs::IDs::botao), caixaTexto(pGrafico->carregarFonte(CAMINHO_FONTE), texto),
                selecionado(false)
            {

            }

            Botao::~Botao(){

            }

            void Botao::desenhar(){
                pGrafico->desenhaElemento(caixa);
                pGrafico->desenhaElemento(caixaTexto.getTexto());
            }

        }

    }

}