#include "..\..\include\Observador\Observador.hpp"
#include "..\..\include\Gerenciador\GerenciadorEvento.hpp"

namespace Jungle { 

    namespace Observador {

        Gerenciador::GerenciadorEvento* Observador::pEvento = Gerenciador::GerenciadorEvento::getGerenciadorEvento();

        Observador::Observador()
        {
            pEvento->addObservador(this);
        }

        Observador::~Observador(){

        }

    }

}