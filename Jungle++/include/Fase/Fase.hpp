#pragma once

//Classe Base
#include "../Ente.hpp"

//Fundo efeito Parallax
#include "../Parallax/Fundo.hpp"

//Gerenciadores
#include "../Gerenciador/GerenciadorColisao.hpp"
#include "../Gerenciador/GerenciadorArquivo.hpp"

//Listas
#include "../Lista/ListaEntidade.hpp"

#include "../Entidade/Personagem/Inimigo/Esqueleto.hpp"
#include "../Entidade/Personagem/Inimigo/Alma.hpp"
#include "../Entidade/Item/Projetil.hpp"
#include "../Entidade/Item/Moeda.hpp"
#include "../Entidade/Item/Vida.hpp"
#include "../Entidade/Obstaculo/PlataformaMovel.hpp"
#include "../Entidade/Obstaculo/Caixa.hpp"
#include "../Entidade/Obstaculo/Porta.hpp"
#include "../Entidade/Item/Chave.hpp"
#include "../Entidade/Personagem/Jogador/Jogador.hpp"
#include "../Observador/ObservadorFase.hpp"
#include "../Entidade/Obstaculo/Espinho.hpp"
#include "../Entidade/Personagem/Inimigo/Carniceiro.hpp"

#include "../Menu/Botao/Texto.hpp"

#include <fstream>

#define CAMINHO_FONTE_FASE "Jungle++/fonte/menuColocacao.ttf"

namespace Jungle {

    using namespace Entidade;
    using namespace Entidade::Personagem;

    namespace Fase {

        class Fase : public Ente {
        private:
            static Observador::ObservadorFase* observadorFase;
            float tempo;
        protected:
            sf::IntRect limiteCamera;
            Lista::ListaEntidade* listaPersonagens;
            Lista::ListaEntidade* listaObstaculos;
            Gerenciador::GerenciadorArquivo GArquivo;
            Gerenciador::GerenciadorColisao* pColisao;
            Parallax::Fundo fundo;
            static Menu::Botao::Texto textoTempo;
            static unsigned int pontuacaoJogador;
            static Menu::Botao::Texto textoPontuacao;
            static Jogador::Jogador* pJogador;

            void criarPlataforma(const sf::Vector2f pos, const sf::Vector2f tam, const std::string type, const sf::Vector2f escala = sf::Vector2f(1.0f, 1.0f));
            void criarPlataforma(const sf::Vector2f pos, const sf::Vector2f tam, const float distancia, const bool horizontal);
            void criarCaixa(const sf::Vector2f pos);
            void criarMoeda(const sf::Vector2f pos, const IDs::IDs ID);
            void criarVida(const sf::Vector2f pos);
            void criarPorta(const sf::Vector2f posPorta, const sf::Vector2f tamPorta, const sf::Vector2f posChave, const sf::Vector2f tamChave, const IDs::IDs ID_Fase);
            void criarEspinho(const sf::Vector2f pos, const sf::Vector2f tam);
            
            void criarPersonagem(const IDs::IDs ID, const sf::Vector2f pos, const int nivel = 1);
            void criarEntidade(const IDs::IDs ID, const std::vector<std::string> primeiro, const std::vector<std::string> segundo, const bool ehPersonagem);
            
            std::vector<std::string> getAtributosEntidade(std::string linha);
        public:
            Fase(const IDs::IDs ID_Fase, const IDs::IDs ID_Fundo);
            ~Fase();
            virtual void criarFundo() = 0;
            virtual void criarMapa(const IDs::IDs ID_Mapa) = 0;
            Entidade::Personagem::Jogador::Jogador* getJogador();
            void mudarEstadoObservador();
            void mudarFase(const IDs::IDs ID_Fase = IDs::IDs::vazio);
            void removerJogadorLista();
            const unsigned int getPontuacaoJogador() const;
            virtual void recuperarJogada(const std::vector<std::string> vectorEntidades, const std::vector<std::string> vectorInfoFase) = 0;
            void setPontuacao(const unsigned int pontuacaoJogador);
            void atualizarTempo();
            void atualizarPontuacao();
            const std::vector<std::string> salvarEntidades();
            void setLimiteCamera(sf::IntRect limiteCamera);
            const sf::IntRect getLimiteCamera() const;
            const std::string salvar();
            void executar();
            void desenhar();
        };

    }

}