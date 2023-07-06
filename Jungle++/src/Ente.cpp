#include "../include/Ente.hpp"

namespace Jungle {

    Gerenciador::GerenciadorGrafico* Ente::pGrafico = Gerenciador::GerenciadorGrafico::getGerenciadorGrafico();

    Ente::Ente(const IDs::IDs ID):
        ID(ID)
    {

    }   

Jungle::Ente::~Ente(){

}

const IDs::IDs Jungle::Ente::getID() const {
    return ID;
}

}