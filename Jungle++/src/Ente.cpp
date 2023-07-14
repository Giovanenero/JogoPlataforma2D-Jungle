#include "../include/Ente.hpp"

namespace Jungle {

    Gerenciador::GerenciadorGrafico* Ente::pGrafico = Gerenciador::GerenciadorGrafico::getGerenciadorGrafico();

    Ente::Ente(const IDs::IDs ID):
        ID(ID)
    {

    }   

    Ente::~Ente(){

    }

    const IDs::IDs Ente::getID() const {
        return ID;
    }

}