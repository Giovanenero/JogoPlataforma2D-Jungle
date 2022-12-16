#include "..\..\include\Observador\Observador.hpp"
#include "..\..\include\Gerenciador\GerenciadorEvento.hpp"
#include "..\..\include\Gerenciador\GerenciadorEstado.hpp"

namespace Jungle { 

    namespace Observador {

        Gerenciador::GerenciadorEvento* Observador::pEvento = Gerenciador::GerenciadorEvento::getGerenciadorEvento();
        Gerenciador::GerenciadorEstado* Observador::pGEstado = Gerenciador::GerenciadorEstado::getGerenciadorEstado();

        Observador::Observador():
            ativar(true)
        {
            pEvento->addObservador(this);
        }

        Observador::~Observador(){
            removerObservador();
        }

        void Observador::removerObservador(){
            pEvento->removerObservador(this);
        }

        void Observador::mudarEstadoAtivar(){
            ativar = (ativar) ? false : true;
        }

        const bool Observador::getAtivar() const {
            return ativar;
        }

    }

}