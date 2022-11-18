#include "..\..\include\Estado\EstadoJogar.hpp"

namespace Jungle {

    namespace Estado {

        EstadoJogar::EstadoJogar(const IDs::IDs ID, Fase::Fase* fase):
            Estado(ID), fase(fase)
        {

        }

        EstadoJogar::~EstadoJogar(){

        }

        Entidade::Personagem::Jogador::Jogador* EstadoJogar::getJogador(){
            return fase->getJogador();
        }

         void EstadoJogar::executar(){
            fase->executar();
        }

    }

}