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
            Menu::Botao::Texto textoPontuacao;
        protected:
            Lista::ListaEntidade* listaPersonagens;
            Lista::ListaEntidade* listaObstaculos;
            Gerenciador::GerenciadorArquivo GArquivo;
            Gerenciador::GerenciadorColisao* pColisao;
            Parallax::Fundo fundo;
            Menu::Botao::Texto textoTempo;
            unsigned int pontuacaoJogador;
            static Jogador::Jogador* pJogador;

            void criarEsqueleto(const sf::Vector2f pos, const int nivel);
            void criarEsqueleto(const std::vector<std::string> atributos, const std::vector<std::string> atributosArma);
            void criarAlma(const sf::Vector2f pos, const int nivel);
            void criarAlma(const std::vector<std::string> atributos, const std::vector<std::string> atributosArma);
            void criarPlataforma(const sf::Vector2f pos, const sf::Vector2f tam, const bool ehFlutuante, const float distancia, const bool horizontal);
            void criarPlataforma(const std::vector<std::string> atributos, const IDs::IDs ID);
            void criarCaixa(const sf::Vector2f pos);
            void criarCaixa(const std::vector<std::string> atributos);
            void criarMoeda(const sf::Vector2f pos, const IDs::IDs ID);
            void criarMoeda(const std::vector<std::string> atributos, const IDs::IDs ID);
            void criarVida(const sf::Vector2f pos);
            void criarVida(const std::vector<std::string> atributos);
            void criarPorta(const sf::Vector2f posPorta, const sf::Vector2f tamPorta, const sf::Vector2f posChave, const sf::Vector2f tamChave);
            void criarPorta(const std::vector<std::string> atributosPorta, const std::vector<std::string> atributosChave);
            void criarJogador(const sf::Vector2f pos);
            void criarJogador(const std::vector<std::string> atributos, const std::vector<std::string> atributosArma);
            
            std::vector<std::string> getAtributosEntidade(std::string linha);
        public:
            Fase(const IDs::IDs ID_Fase, const IDs::IDs ID_Fundo);
            ~Fase();
            virtual void criarFundo() = 0;
            virtual void criarMapa(const int mapa) = 0;
            void executar();
            void desenhar();
            Entidade::Personagem::Jogador::Jogador* getJogador();
            void mudarEstadoObservador();
            void mudarFase();
            void removerJogadorLista();
            const unsigned int getPontuacaoJogador() const;
            virtual void recuperarJogada(const std::string arquivoEntidades, const std::vector<std::string> vectorInfoFase) = 0;
            void setPontuacao(const unsigned int pontuacaoJogador);
            void atualizarTempo();
            void atualizarPontuacao();
            const std::vector<std::string> salvarEntidades();
            const std::string salvar();
        };

    }

}