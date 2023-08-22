#pragma once

#include "Estado.hpp"

//Gerenciador
#include "../Gerenciador/GerenciadorGrafico.hpp"
#include "../Gerenciador/GerenciadorArquivo.hpp"

//Fases
#include "../Fase/FlorestaBranca.hpp"
#include "../Fase/FlorestaVermelha.hpp"

#include <map>

namespace Jungle {

    namespace Estado {

        class EstadoJogar : public Estado {
        private:
            std::map<IDs::IDs, Fase::Fase*> mapFase;
            IDs::IDs ID_FaseAtual;
            
        public:
            EstadoJogar(const IDs::IDs ID);
            ~EstadoJogar();
            void criarFase(const std::string arquivoEntidades, std::vector<std::string> vectorInfoFase);
            void criarFase();
            std::map<IDs::IDs, Fase::Fase*> getMapFase();
            const IDs::IDs getIDFaseAtual() const;
            Fase::Fase* getFase();
            void mudarFase(const IDs::IDs ID_Fase);
            void mudarEstadoObservador();
            void executar();
        };

    }

}
