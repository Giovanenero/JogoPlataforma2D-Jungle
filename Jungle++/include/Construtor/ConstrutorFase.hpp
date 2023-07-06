#pragma once

//Fase
#include "../Fase/FlorestaBranca.hpp"
#include "../Fase/FlorestaVermelha.hpp"

namespace Jungle {

    namespace Construtor {

        class ConstrutorFase {
        public:
            ConstrutorFase();
            ~ConstrutorFase();
            Fase::Fase* criarFase(const IDs::IDs ID);
        private:
            Fase::Fase* criarFlorestaBranca();
            Fase::Fase* criarFlorestaVermelha();
        };

    } 

}