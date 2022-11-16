#include "..\..\include\Estado\EstadoJogar.hpp"

namespace Jungle {

    namespace Estado {

        EstadoJogar::EstadoJogar(Fase::Fase* fase):
            Estado(fase->getID()), fase(fase)
        {

        }

        EstadoJogar::~EstadoJogar(){

        }

         void EstadoJogar::executar(){
            fase->executar();
        }

    }

}