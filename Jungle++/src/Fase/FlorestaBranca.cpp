#include "../../include/Fase/FlorestaBranca.hpp"

namespace Jungle {

    namespace Fase {

        FlorestaBranca::FlorestaBranca(const char* caminhoArquivo):
            Fase(IDs::IDs::fase_florestaBranca, IDs::IDs::fundo_florestaBranca)
        {
            if(caminhoArquivo != ""){
                recuperarJogada(caminhoArquivo);
            }
        }

        FlorestaBranca::~FlorestaBranca(){

        }

        void FlorestaBranca::recuperarJogada(const char* caminhoArquivo){
            std::vector<std::string> linhas = GArquivo.lerArquivo(caminhoArquivo);
            int i = 2;
            Entidade::Personagem::Jogador::Jogador* pJogador = criarJogador(getAtributosEntidade(linhas[0]), getAtributosEntidade(linhas[1]));
            while(i < linhas.size()){
                std::string linha = linhas[i];
                int id =  std::stoi(linha.substr(0, linha.find(" ")));
                const std::vector<std::string> atributos = getAtributosEntidade(linhas[i]);
                switch (id)
                {
                    case (5):
                    {
                        //criar esqueleto com espada
                        criarEsqueleto(atributos, getAtributosEntidade(linhas[i + 1]), pJogador);
                        i++;
                    }
                        break;
                    case (7):
                    {
                        //criar alma com projetil
                        criarAlma(atributos, getAtributosEntidade(linhas[i + 1]), pJogador);
                        i++;
                    }
                        break;
                    case (8):
                    {
                        //cria plataforma
                        criarPlataforma(atributos);
                    }
                        break;
                    case (9):
                    {
                        //criar caixa
                        criarCaixa(atributos);
                    }
                        break;
                    case (10):
                    {
                        //criar moeda amarela
                        criarMoeda(atributos, IDs::IDs::moeda_amarela);
                    }
                        break;
                    case (11):
                    {
                        //criar moeda cinza
                        criarMoeda(atributos, IDs::IDs::moeda_cinza);
                    }
                        break;
                    case (12):
                    {
                        //criar vida
                        criarVida(atributos);
                    }
                        break;
                }
                i++;
            }
        }

        void FlorestaBranca::criarFundo(){
            fundo.addCamada("Jungle++/img/Fase/FlorestaBranca/camada1.png", 0.0f);
            fundo.addCamada("Jungle++/img/Fase/FlorestaBranca/camada2.png", 0.1f);
            fundo.addCamada("Jungle++/img/Fase/FlorestaBranca/camada3.png", 0.3f);
            fundo.addCamada("Jungle++/img/Fase/FlorestaBranca/camada4.png", 0.5f);
            fundo.addCamada("Jungle++/img/Fase/FlorestaBranca/camada5.png", 1.0f);
        }

        void FlorestaBranca::criarMapa(){
            Entidade::Personagem::Jogador::Jogador* pJogador = criarJogador(sf::Vector2f(100.0f, 400.0f));
            criarMoeda(sf::Vector2f(300.0f, 500.0f), IDs::IDs::moeda_amarela);
            criarMoeda(sf::Vector2f(1200.0f, 80.0f), IDs::IDs::moeda_cinza);
            criarVida(sf::Vector2f(1400.0f, 350.0f));

            for(int i = 0; i < 6; i++){
                criarEsqueleto(sf::Vector2f(400.0f * (i + 0.5f), 0.0f), pJogador);
            }
            criarAlma(sf::Vector2f(200.0f, 500.0f), pJogador);

            for(int i = -2; i < 8; i++){
                listaObstaculos->addEntidade(construtorEntidade.criarPlataforma(sf::Vector2f(i * 300.0f, 550.0f)));
            }
        }

    }

}

