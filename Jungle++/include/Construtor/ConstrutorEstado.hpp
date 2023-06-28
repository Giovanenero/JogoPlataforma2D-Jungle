#pragma once 

#include "..\Estado\EstadoJogar.hpp"
#include "..\Estado\EstadoMenuPrincipal.hpp"
#include "..\Estado\EstadoMenuPausa.hpp"
#include "..\Estado\EstadoMenuOpcaoPrincipal.hpp"
#include "..\Estado\EstadoMenuCarregarJogo.hpp"
#include "..\Estado\EstadoMenuColocacao.hpp"

#include "..\Construtor\ConstrutorFase.hpp"

namespace Jungle {

    namespace Construtor {

        class ConstrutorEstado {
        public:
            ConstrutorEstado();
            ~ConstrutorEstado();
            Estado::Estado* criarEstado(const IDs::IDs ID);
        private:
            Estado::Estado* criarEstadoJogar(const IDs::IDs ID);
            Estado::Estado* criarMenuPrinciapal();
            Estado::Estado* criarMenuPausar();
            Estado::Estado* criarMenuOpcaoPrincipal();
            Estado::Estado* criarEstadoMenuCarregarJogo();
            Estado::Estado* criarEstadoMenuColocacao();
            //Estado::Estado* criarMenuSalvar();
            //Estado::Estado* criarColocao();
        };

    }

}