#include "../../include/Fase/Fase.hpp"
#include "../../include/Observador/ObservadorFase.hpp"

namespace Jungle {

    namespace Fase {

        Fase::Fase(const IDs::IDs ID_Fase, const IDs::IDs ID_Fundo):
            Ente(ID_Fase), fundo(ID_Fundo), listaPersonagens(new Lista::ListaEntidade()), listaObstaculos(new Lista::ListaEntidade()),
            pColisao(new Gerenciador::GerenciadorColisao(listaPersonagens, listaObstaculos)),
            observadorFase(new Observador::ObservadorFase(this)), pontuacaoJogador(0), GArquivo(), tempo(0.0f),
            textoPontuacao(pGrafico->carregarFonte(CAMINHO_FONTE_FASE), "Pontos: 000", 32),
            textoTempo(pGrafico->carregarFonte(CAMINHO_FONTE_FASE), "Tempo 00:00", 32)
        {
            if(listaPersonagens == nullptr || listaObstaculos == nullptr){
                std::cout << "Jungle::Fase::nao foi possivel criar lista de entidades na fase" << std::endl;
                exit(1);
            }

            if(pColisao == nullptr){
                std::cout << "Jungle::Fase::nao foi possivel criar um Gerenciador de Colisao" << std::endl;
                exit(1);
            }
            textoPontuacao.setTamanhoBorda(2);
            textoTempo.setTamanhoBorda(2);
        }

        Fase::~Fase(){
            if(pColisao != nullptr){
                delete(pColisao);
                pColisao = nullptr;
            }
            if(observadorFase != nullptr){
                delete(observadorFase);
                observadorFase = nullptr;
            }

            if(listaPersonagens != nullptr){
                delete(listaPersonagens);
                listaPersonagens = nullptr;
            }

            if(listaObstaculos != nullptr){
                delete(listaObstaculos);
                listaObstaculos = nullptr;
            }
        }

        std::vector<std::string> Fase::getAtributosEntidade(std::string linha){
            std::string espaco = " ";
            size_t pos = 0;
            std::vector<std::string> atributos;
            while((pos = linha.find(espaco)) != std::string::npos){
                atributos.push_back(linha.substr(0, pos));
                linha.erase(0, pos + espaco.length());
            }
            return atributos;
        }

        void Fase::criarEsqueleto(const sf::Vector2f pos, const int nivel, Entidade::Personagem::Jogador::Jogador* pJogador){
            Entidade::Personagem::Inimigo::Esqueleto* esqueleto = new Entidade::Personagem::Inimigo::Esqueleto(pos, nivel, pJogador);
            if(esqueleto == nullptr){
                std::cout << "Fase::nao foi possivel criar esqueleto" << std::endl;
                exit(1);
            }
            Entidade::Item::Arma* espadaInimigo = new Entidade::Item::Arma(IDs::IDs::espada_inimigo);
            if(espadaInimigo == nullptr){
                std::cout << "Fase::nao foi possivel criar espada esqueleto" << std::endl;
                exit(1);
            }
            esqueleto->setArma(espadaInimigo);
            listaPersonagens->addEntidade(static_cast<Entidade::Entidade*>(esqueleto));
            listaPersonagens->addEntidade(static_cast<Entidade::Entidade*>(espadaInimigo));
        }

        void Fase::criarEsqueleto(const std::vector<std::string> atributos, const std::vector<std::string> atributosArma, Entidade::Personagem::Jogador::Jogador* pJogador){
            Entidade::Personagem::Inimigo::Esqueleto* esqueleto = new Entidade::Personagem::Inimigo::Esqueleto(atributos, pJogador);
            if(esqueleto == nullptr){
                std::cout << "Fase::esqueleto eh nullptr" << std::endl;
                exit(1);
            }
            Entidade::Item::Arma* espadaEsqueleto = new Entidade::Item::Arma(IDs::IDs::espada_inimigo, atributosArma);
            if(espadaEsqueleto == nullptr){
                std::cout << "Fase::nao foi possivel criar espada esqueleto" << std::endl;
                exit(1);
            }
            esqueleto->setArma(espadaEsqueleto);
            listaPersonagens->addEntidade(static_cast<Entidade::Entidade*>(esqueleto));
            listaPersonagens->addEntidade(static_cast<Entidade::Entidade*>(espadaEsqueleto));
        }

        void Fase::criarAlma(const sf::Vector2f pos, const int nivel, Entidade::Personagem::Jogador::Jogador* pJogador){
            Entidade::Personagem::Inimigo::Alma* alma = new Entidade::Personagem::Inimigo::Alma(pos, nivel, pJogador);
            Entidade::Item::Projetil* projetil = new Entidade::Item::Projetil();
            //projetil->setPersonagem(static_cast<Entidade::Personagem::Personagem*>(alma));
            alma->setArma(static_cast<Entidade::Item::Projetil*>(projetil));
            projetil->inicializarAnimacao();
            listaPersonagens->addEntidade(static_cast<Entidade::Entidade*>(alma));
            listaPersonagens->addEntidade(static_cast<Entidade::Entidade*>(projetil));
        }

        void Fase::criarAlma(const std::vector<std::string> atributos, const std::vector<std::string> atributosArma, Entidade::Personagem::Jogador::Jogador* pJogador){
            Entidade::Personagem::Inimigo::Alma* alma = new Entidade::Personagem::Inimigo::Alma(atributos, pJogador);
            if(alma == nullptr){
                std::cout << "Fase::alma eh nullptr" << std::endl;
                exit(1);
            }
            Entidade::Item::Projetil* projetil = new Entidade::Item::Projetil(atributosArma, static_cast<Entidade::Personagem::Personagem*>(alma));
            if(projetil == nullptr){
                std::cout << "Fase::projetil eh nullptr" << std::endl;
                exit(1);
            }

            //alma->setArma(static_cast<Entidade::Item::Arma*>(projetil));
            listaPersonagens->addEntidade(static_cast<Entidade::Entidade*>(alma));
            listaPersonagens->addEntidade(static_cast<Entidade::Entidade*>(projetil));
        }

        void Fase::criarPlataforma(const sf::Vector2f pos){
            Entidade::Obstaculo::Plataforma* plataforma = new Entidade::Obstaculo::Plataforma(pos);
            if(plataforma == nullptr){
                std::cout << "Fase::nao foi possivel criar plataforma" << std::endl;
                exit(1);
            }
            listaObstaculos->addEntidade(static_cast<Entidade::Entidade*>(plataforma));
        }

        void Fase::criarPlataforma(const std::vector<std::string> atributos){
            Entidade::Obstaculo::Plataforma* plataforma = new Entidade::Obstaculo::Plataforma(atributos);
            if(plataforma == nullptr){
                std::cout << "Fase::nao foi possivel criar plataforma" << std::endl;
                exit(1);
            }
            listaObstaculos->addEntidade(static_cast<Entidade::Entidade*>(plataforma));
        }

        void Fase::criarCaixa(const sf::Vector2f pos){
            Entidade::Obstaculo::Caixa* caixa = new Entidade::Obstaculo::Caixa(pos);
            if(caixa == nullptr){
                std::cout << "Fase::nao foi possivel criar caixa" << std::endl;
                exit(1);
            }
            listaObstaculos->addEntidade(static_cast<Entidade::Entidade*>(caixa));
        }

        void Fase::criarCaixa(const std::vector<std::string> atributos){
            Entidade::Obstaculo::Caixa* caixa = new Entidade::Obstaculo::Caixa(atributos);
            if(caixa == nullptr){
                std::cout << "Fase::nao foi possivel criar caixa" << std::endl;
                exit(1);
            }
            listaObstaculos->addEntidade(static_cast<Entidade::Entidade*>(caixa));
        }

        void Fase::criarMoeda(const sf::Vector2f pos, const IDs::IDs ID){
            Entidade::Item::Moeda* moeda = new Entidade::Item::Moeda(pos, ID);
            if(moeda == nullptr){
                std::cout << "Fase::nao foi possivel criar moeda" << std::endl;
                exit(1);
            }
            listaPersonagens->addEntidade(static_cast<Entidade::Entidade*>(moeda));
        }

        void Fase::criarMoeda(const std::vector<std::string> atributos, const IDs::IDs ID){
            Entidade::Item::Moeda* moeda = new Entidade::Item::Moeda(atributos, ID);
            if(moeda == nullptr){
                std::cout << "Fase::nao foi possivel criar moeda" << std::endl;
                exit(1);
            }
            listaPersonagens->addEntidade(static_cast<Entidade::Entidade*>(moeda));
        }
        
        void Fase::criarVida(const sf::Vector2f pos){
            Entidade::Item::Vida* vida = new Entidade::Item::Vida(pos);
            if(vida == nullptr){
                std::cout << "Fase::nao foi possivel criar vida" << std::endl;
                exit(1);
            }
            listaPersonagens->addEntidade(static_cast<Entidade::Entidade*>(vida));
        }

        void Fase::criarVida(const std::vector<std::string> atributos){
            Entidade::Item::Vida* vida = new Entidade::Item::Vida(atributos);
            if(vida == nullptr){
                std::cout << "Fase::nao foi possivel criar vida" << std::endl;
                exit(1);
            }
            listaPersonagens->addEntidade(static_cast<Entidade::Entidade*>(vida));
        }

        Entidade::Personagem::Jogador::Jogador*  Fase::criarJogador(const sf::Vector2f pos){
            Entidade::Item::Arma* espadaJogador = new Entidade::Item::Arma(IDs::IDs::espada_jogador);
            if(espadaJogador == nullptr){
                std::cout << "Fase::nao foi possivel criar espada do jogador" << std::endl;
                exit(1);
            }
            Entidade::Personagem::Jogador::Jogador* pJogador = new Entidade::Personagem::Jogador::Jogador(pos, espadaJogador);
            if(pJogador == nullptr){
                std::cout << "Fase::nao foi possivel criar jogador" << std::endl;
                exit(1);
            }
            listaPersonagens->addEntidade(static_cast<Entidade::Entidade*>(pJogador));
            listaPersonagens->addEntidade(static_cast<Entidade::Entidade*>(espadaJogador));
            return pJogador;
        }

        Entidade::Personagem::Jogador::Jogador* Fase::criarJogador(const std::vector<std::string> atributos, const std::vector<std::string> atributosArma){
            Entidade::Personagem::Jogador::Jogador* pJogador = new Entidade::Personagem::Jogador::Jogador(atributos);
            if(pJogador == nullptr){
                std::cout << "Fase::jogador eh nullptr" << std::endl;
                exit(1);
            }
            Entidade::Item::Arma* espadaJogador = new Entidade::Item::Arma(IDs::IDs::espada_jogador, atributosArma);
            if(espadaJogador == nullptr){
                std::cout << "Fase::nao foi possivel criar espada do jogador" << std::endl;
                exit(1);
            }
            pJogador->setArma(espadaJogador);
            listaPersonagens->addEntidade(static_cast<Entidade::Entidade*>(pJogador));
            listaPersonagens->addEntidade(static_cast<Entidade::Entidade*>(espadaJogador));
            return pJogador;
        }

        void Fase::criarEntidade(char letra, const sf::Vector2i pos){
            //terminar...
            sf::Vector2f posAux = sf::Vector2f(pos.x * 50.0f, pos.y * 50.0f);
        }

        Entidade::Personagem::Jogador::Jogador* Fase::getJogador(){
            for(int i = 0; i < listaPersonagens->getTam(); i++){
                Entidade::Entidade* ent = listaPersonagens->operator[](i);
                if(ent->getID() == IDs::IDs::jogador){
                    return dynamic_cast<Entidade::Personagem::Jogador::Jogador*>(ent);
                }
            }
            return nullptr;
        }

        void Fase::mudarEstadoObservador(){
            observadorFase->mudarEstadoAtivar();
        }

        void Fase::desenhar(){
            fundo.executar();
            pGrafico->desenhaElemento(textoPontuacao.getTexto());
            pGrafico->desenhaElemento(textoTempo.getTexto());
            listaObstaculos->desenharEntidades();
            listaPersonagens->desenharEntidades();
        }

         const unsigned int Fase::getPontuacaoJogador() const {
            return pontuacaoJogador;
         }

         Lista::ListaEntidade* Fase::getListaPersonagem(){
            return listaPersonagens;
         }

        Lista::ListaEntidade* Fase::getListaObstaculo(){
            return listaObstaculos;
        }

        void Fase::setPontuacao(const unsigned int pontuacaoJogador){
            this->pontuacaoJogador = pontuacaoJogador;
            textoPontuacao.setString("Pontos " + std::to_string(pontuacaoJogador));
        }

        void Fase::atualizarTempo(){
            //atualiza posição e o tempo
            tempo += pGrafico->getTempo();
            if(tempo >= 1.0f){
                tempo = 0.0f;
                std::string stringCortada = textoTempo.getString().substr(6);
                std::string novaString = "Tempo ";
                //int doisPontos = stringCortada.find(":");
                int minutos = std::stoi(stringCortada.substr(0, 2));
                int segundos = std::stoi(stringCortada.substr(3, 5));
                if(segundos >= 59){
                    minutos++;
                    segundos = 0;
                    //novaString += std::to_string(minutos)
                } else {
                    segundos++;
                }
                if(minutos < 10){
                    novaString += "0" + std::to_string(minutos);
                } else {
                    novaString += std::to_string(minutos);
                }
                if(segundos < 10){
                    novaString += ":0" + std::to_string(segundos);
                } else {
                    novaString += ":" + std::to_string(segundos);
                }
                textoTempo.setString(novaString);
            }
            sf::Vector2f posFundo(pGrafico->getCamera().getCenter());
            textoTempo.setPos(sf::Vector2f(posFundo.x - textoTempo.getTam().x / 2.0f + 20.0f, posFundo.y - pGrafico->getTamJanela().y / 2.0f + 10.0f));
            pGrafico->desenhaElemento(textoTempo.getTexto());
        }
        
        void Fase::atualizarPontuacao(){
            sf::Vector2f posFundo(pGrafico->getCamera().getCenter());
            sf::Vector2f tamJanela(pGrafico->getTamJanela());
            textoPontuacao.setPos(sf::Vector2f(posFundo.x - tamJanela.x / 2.0f + 20.0f , posFundo.y - tamJanela.y / 2.0f + 10.0f));
            pGrafico->desenhaElemento(textoPontuacao.getTexto());
        }

        const std::string Fase::salvar(){
            std::string linha = "";
            linha += std::to_string(static_cast<int>(ID)) + ' ';
            linha += '\n';
            linha += std::to_string(this->pontuacaoJogador) + ' ';
            linha += '\n';
            linha += textoTempo.getString();
            return linha;
        }

        void Fase::executar(){
            Entidade::Personagem::Jogador::Jogador* jogador = getJogador();
            if(jogador){
                //atualiza fundo
                fundo.executar();

                atualizarTempo();
                atualizarPontuacao();

                //atualiza e desenha entidades
                listaObstaculos->executar();
                listaPersonagens->executar();

                //verifica colisão
                pColisao->executar();
            } else {
                observadorFase->notificarJogadorMorreu();
            }
        }

    }

}