#pragma once

//Entidade
#include "Entidade\Personagem\Inimigo\Inimigo.hpp"
#include "Entidade\Personagem\Jogador\Jogador.hpp"
#include "Entidade\Obstaculo\Plataforma.hpp"
#include "Entidade\Obstaculo\Caixa.hpp"

//Gerenciador
#include "Gerenciador\GerenciadorGrafico.hpp"
#include "Gerenciador\GerenciadorEvento.hpp"
#include "Gerenciador\GerenciadorColisao.hpp"

//Lista
#include "Lista\ListaEntidade.hpp"

namespace Jungle {

    class Principal {
        private:
            Gerenciador::GerenciadorGrafico* pGrafico;
            Gerenciador::GerenciadorEvento* pEvento;
            Gerenciador::GerenciadorColisao colisor;
            Lista::ListaEntidade listaPersonagem;
            Lista::ListaEntidade listaObstaculo;
        public:
            Principal();
            ~Principal();
            void executar();
            void instanciaEntidades();
    };

}