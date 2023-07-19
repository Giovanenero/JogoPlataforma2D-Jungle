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
#include "../Entidade/Obstaculo/Plataforma.hpp"
#include "../Entidade/Obstaculo/Caixa.hpp"

#include <fstream>

namespace Jungle {

    namespace Observador {
        class ObservadorFase;
    }

    namespace Fase {

        class Fase : public Ente {
        private:
            Observador::ObservadorFase* observadorFase; 
        protected:
            Lista::ListaEntidade* listaPersonagens;
            Lista::ListaEntidade* listaObstaculos;
            Gerenciador::GerenciadorArquivo GArquivo;
            Gerenciador::GerenciadorColisao* pColisao;
            Parallax::Fundo fundo;
            unsigned int pontuacaoJogador;

            void criarEsqueleto(const sf::Vector2f pos, Entidade::Personagem::Jogador::Jogador* pJogador);
            void criarEsqueleto(const std::vector<std::string> atributos, const std::vector<std::string> atributosArma, Entidade::Personagem::Jogador::Jogador* pJogador);
            void criarAlma(const sf::Vector2f pos, Entidade::Personagem::Jogador::Jogador* pJogador);
            void criarAlma(const std::vector<std::string> atributos, const std::vector<std::string> atributosArma, Entidade::Personagem::Jogador::Jogador* pJogador);
            void criarPlataforma(const sf::Vector2f pos);
            void criarPlataforma(const std::vector<std::string> atributos);
            void criarCaixa(const sf::Vector2f pos);
            void criarCaixa(const std::vector<std::string> atributos);
            void criarMoeda(const sf::Vector2f pos, const IDs::IDs ID);
            void criarMoeda(const std::vector<std::string> atributos, const IDs::IDs ID);
            void criarVida(const sf::Vector2f pos);
            void criarVida(const std::vector<std::string> atributos);
            Entidade::Personagem::Jogador::Jogador* criarJogador(const sf::Vector2f pos);
            Entidade::Personagem::Jogador::Jogador* criarJogador(const std::vector<std::string> atributos, const std::vector<std::string> atributosArma);
            
            std::vector<std::string> getAtributosEntidade(std::string linha);
        public:
            Fase(const IDs::IDs ID_Fase, const IDs::IDs ID_Fundo);
            ~Fase();
            virtual void criarFundo() = 0;
            virtual void criarMapa() = 0;
            void criarEntidade(char letra, const sf::Vector2i pos);
            void executar();
            void desenhar();
            Entidade::Personagem::Jogador::Jogador* getJogador();
            void mudarEstadoObservador();
            const unsigned int getPontuacaoJogador() const;
            virtual void recuperarJogada(const std::string caminhoArquivo) = 0;
            Lista::ListaEntidade* getListaPersonagem();
            Lista::ListaEntidade* getListaObstaculo();
        };

    }

}