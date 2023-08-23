#include "../include/Ente.hpp"

namespace Jungle {

    Gerenciador::GerenciadorGrafico* Ente::pGrafico = Gerenciador::GerenciadorGrafico::getGerenciadorGrafico();

    Ente::Ente(const IDs::IDs ID):
        ID(ID)
    {

    }   

    Ente::~Ente(){

    }

    const std::string Ente::salvarEnte(){
        return std::to_string(static_cast<int>(ID)) + ' ';
    }

    const IDs::IDs Ente::getID() const {
        return ID;
    }

}