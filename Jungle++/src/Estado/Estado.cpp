#include "../../include/Estado/Estado.hpp"

namespace Jungle {

    namespace Estado {

        Estado::Estado(const IDs::IDs ID):
            Ente(ID), remover(false)
        {

        }

        Estado::~Estado(){
            
        }

        void Estado::desenhar(){

        }

        void Estado::setRemover(const bool remover){
            this->remover = remover;
        }

        const bool Estado::getRemover() const {
            return remover;
        }

    }

}