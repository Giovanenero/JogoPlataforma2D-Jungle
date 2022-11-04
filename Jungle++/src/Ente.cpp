#include "..\include\Ente.hpp"

Jungle::Ente::Ente(const IDs::IDs ID):
    ID(ID), pGrafico(pGrafico->getGerenciadorGrafico())
{

}

Jungle::Ente::~Ente(){

}

const IDs::IDs Jungle::Ente::getID() const {
    return ID;
}