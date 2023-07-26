#include "../../include/Fase/Fase.hpp"

namespace Jungle {

    using namespace Entidade;
    using namespace Entidade::Personagem;

    namespace Fase {

        Jogador::Jogador* Fase::pJogador = nullptr;
        Observador::ObservadorFase* Fase::observadorFase = new Observador::ObservadorFase();

        Fase::Fase(const IDs::IDs ID_Fase, const IDs::IDs ID_Fundo):
            Ente(ID_Fase), fundo(ID_Fundo), listaPersonagens(new Lista::ListaEntidade()), listaObstaculos(new Lista::ListaEntidade()),
            pColisao(new Gerenciador::GerenciadorColisao(listaPersonagens, listaObstaculos)),
            pontuacaoJogador(0), GArquivo(), tempo(0.0f),
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
            observadorFase->setFase(this);
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
                pJogador = nullptr;
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

        void Fase::criarEsqueleto(const sf::Vector2f pos, const int nivel){
            Inimigo::Esqueleto* esqueleto = new Inimigo::Esqueleto(pos, nivel, pJogador);
            if(esqueleto == nullptr){
                std::cout << "Fase::nao foi possivel criar esqueleto" << std::endl;
                exit(1);
            }
            Item::Arma* espadaInimigo = new Item::Arma(IDs::IDs::espada_inimigo);
            if(espadaInimigo == nullptr){
                std::cout << "Fase::nao foi possivel criar espada esqueleto" << std::endl;
                exit(1);
            }
            esqueleto->setArma(espadaInimigo);
            listaPersonagens->addEntidade(static_cast<Entidade::Entidade*>(esqueleto));
            listaPersonagens->addEntidade(static_cast<Entidade::Entidade*>(espadaInimigo));
        }

        void Fase::criarEsqueleto(const std::vector<std::string> atributos, const std::vector<std::string> atributosArma){
            Inimigo::Esqueleto* esqueleto = new Inimigo::Esqueleto(atributos, pJogador);
            if(esqueleto == nullptr){
                std::cout << "Fase::esqueleto eh nullptr" << std::endl;
                exit(1);
            }
            Item::Arma* espadaEsqueleto = new Item::Arma(IDs::IDs::espada_inimigo, atributosArma);
            if(espadaEsqueleto == nullptr){
                std::cout << "Fase::nao foi possivel criar espada esqueleto" << std::endl;
                exit(1);
            }
            esqueleto->setArma(espadaEsqueleto);
            listaPersonagens->addEntidade(static_cast<Entidade::Entidade*>(esqueleto));
            listaPersonagens->addEntidade(static_cast<Entidade::Entidade*>(espadaEsqueleto));
        }

        void Fase::criarAlma(const sf::Vector2f pos, const int nivel){
            Inimigo::Alma* alma = new Inimigo::Alma(pos, nivel, pJogador);
            Item::Projetil* projetil = new Item::Projetil();
            //projetil->setPersonagem(static_cast<Personagem*>(alma));
            alma->setArma(static_cast<Item::Projetil*>(projetil));
            projetil->inicializarAnimacao();
            listaPersonagens->addEntidade(static_cast<Entidade::Entidade*>(alma));
            listaPersonagens->addEntidade(static_cast<Entidade::Entidade*>(projetil));
        }

        void Fase::criarAlma(const std::vector<std::string> atributos, const std::vector<std::string> atributosArma){
            Inimigo::Alma* alma = new Inimigo::Alma(atributos, pJogador);
            if(alma == nullptr){
                std::cout << "Fase::alma eh nullptr" << std::endl;
                exit(1);
            }
            Item::Projetil* projetil = new Item::Projetil(atributosArma, static_cast<Entidade::Personagem::Personagem*>(alma));
            if(projetil == nullptr){
                std::cout << "Fase::projetil eh nullptr" << std::endl;
                exit(1);
            }

            //alma->setArma(static_cast<Item::Arma*>(projetil));
            listaPersonagens->addEntidade(static_cast<Entidade::Entidade*>(alma));
            listaPersonagens->addEntidade(static_cast<Entidade::Entidade*>(projetil));
        }

        void Fase::criarPlataforma(const sf::Vector2f pos, const sf::Vector2f tam, const bool ehFlutuante, const float distancia, const bool horizontal){
            Obstaculo::Plataforma* plataforma = nullptr;
            if(distancia != 0.0f){
                plataforma = static_cast<Obstaculo::Plataforma*>(new Obstaculo::PlataformaMovel(pos, distancia, tam, ehFlutuante, horizontal));
            } else {
                plataforma = new Obstaculo::Plataforma(IDs::IDs::plataforma, pos, tam, ehFlutuante);
            }
            if(plataforma == nullptr){
                std::cout << "Fase::nao foi possivel criar plataforma" << std::endl;
                exit(1);
            }
            plataforma->inicializarAnimacao();
            listaObstaculos->addEntidade(static_cast<Entidade::Entidade*>(plataforma));
        }

        void Fase::criarPlataforma(const std::vector<std::string> atributos, const IDs::IDs ID){
            Obstaculo::Plataforma* plataforma = nullptr;
            if(ID == IDs::IDs::plataforma){
                plataforma = new Obstaculo::Plataforma(atributos);
            } else {
                plataforma = static_cast<Obstaculo::Plataforma*>(new Obstaculo::PlataformaMovel(atributos));
            }
            if(plataforma == nullptr){
                std::cout << "Fase::nao foi possivel criar plataforma" << std::endl;
                exit(1);
            }
            listaObstaculos->addEntidade(static_cast<Entidade::Entidade*>(plataforma));
        }

        void Fase::criarCaixa(const sf::Vector2f pos){
            Obstaculo::Caixa* caixa = new Obstaculo::Caixa(pos);
            if(caixa == nullptr){
                std::cout << "Fase::nao foi possivel criar caixa" << std::endl;
                exit(1);
            }
            listaObstaculos->addEntidade(static_cast<Entidade::Entidade*>(caixa));
        }

        void Fase::criarCaixa(const std::vector<std::string> atributos){
            Obstaculo::Caixa* caixa = new Obstaculo::Caixa(atributos);
            if(caixa == nullptr){
                std::cout << "Fase::nao foi possivel criar caixa" << std::endl;
                exit(1);
            }
            listaObstaculos->addEntidade(static_cast<Entidade::Entidade*>(caixa));
        }

        void Fase::criarMoeda(const sf::Vector2f pos, const IDs::IDs ID){
            Item::Moeda* moeda = new Item::Moeda(pos, ID);
            if(moeda == nullptr){
                std::cout << "Fase::nao foi possivel criar moeda" << std::endl;
                exit(1);
            }
            listaPersonagens->addEntidade(static_cast<Entidade::Entidade*>(moeda));
        }

        void Fase::criarMoeda(const std::vector<std::string> atributos, const IDs::IDs ID){
            Item::Moeda* moeda = new Item::Moeda(atributos, ID);
            if(moeda == nullptr){
                std::cout << "Fase::nao foi possivel criar moeda" << std::endl;
                exit(1);
            }
            listaPersonagens->addEntidade(static_cast<Entidade::Entidade*>(moeda));
        }
        
        void Fase::criarVida(const sf::Vector2f pos){
            Item::Vida* vida = new Item::Vida(pos);
            if(vida == nullptr){
                std::cout << "Fase::nao foi possivel criar vida" << std::endl;
                exit(1);
            }
            listaPersonagens->addEntidade(static_cast<Entidade::Entidade*>(vida));
        }

        void Fase::criarVida(const std::vector<std::string> atributos){
            Item::Vida* vida = new Item::Vida(atributos);
            if(vida == nullptr){
                std::cout << "Fase::nao foi possivel criar vida" << std::endl;
                exit(1);
            }
            listaPersonagens->addEntidade(static_cast<Entidade::Entidade*>(vida));
        }

        void Fase::criarPorta(const sf::Vector2f posPorta, const sf::Vector2f tamPorta, const sf::Vector2f posChave, const sf::Vector2f tamChave){
            Item::Chave* chave = new Item::Chave(posChave, tamChave);
            if(chave == nullptr){
                std::cout << "Fase::nao foi possivel criar uma chave" << std::endl;
                exit(1);
            }
            Obstaculo::Porta* porta = new Obstaculo::Porta(posPorta, tamPorta, chave);
            if(porta == nullptr){
                std::cout << "Fase::nao foi possivel criar uma porta" << std::endl;
                exit(1);
            }
            chave->setPorta(porta);
            listaObstaculos->addEntidade(static_cast<Entidade::Entidade*>(porta));
            listaObstaculos->addEntidade(static_cast<Entidade::Entidade*>(chave));
        }

        void Fase::criarPorta(const std::vector<std::string> atributosPorta, const std::vector<std::string> atributosChave){
            Item::Chave* chave = nullptr;
            if(atributosChave.size() > 0){
                chave = new Item::Chave(atributosChave);
                if(chave == nullptr){
                    std::cout << "Fase::nao foi possivel criar uma chave" << std::endl;
                    exit(1);
                }
            }
            Obstaculo::Porta* porta = new Obstaculo::Porta(atributosPorta, chave);
            if(porta == nullptr){
                std::cout << "Fase::nao foi possivel criar uma porta" << std::endl;
                exit(1);
            }
            listaObstaculos->addEntidade(static_cast<Entidade::Entidade*>(porta));
            if(chave != nullptr){
                chave->setPorta(porta);
                if(chave->getColetou()){
                    pJogador->addChave(chave);
                }
                listaObstaculos->addEntidade(static_cast<Entidade::Entidade*>(chave));
            }
        }

        void Fase::criarJogador(const sf::Vector2f pos){
            Item::Arma* espadaJogador = new Item::Arma(IDs::IDs::espada_jogador);
            if(espadaJogador == nullptr){
                std::cout << "Fase::nao foi possivel criar espada do jogador" << std::endl;
                exit(1);
            }
            pJogador = new Jogador::Jogador(pos, espadaJogador);
            if(pJogador == nullptr){
                std::cout << "Fase::nao foi possivel criar jogador" << std::endl;
                exit(1);
            }
            listaPersonagens->addEntidade(static_cast<Entidade::Entidade*>(pJogador));
            listaPersonagens->addEntidade(static_cast<Entidade::Entidade*>(espadaJogador));
        }

        void Fase::criarJogador(const std::vector<std::string> atributos, const std::vector<std::string> atributosArma){
            pJogador = new Jogador::Jogador(atributos);
            if(pJogador == nullptr){
                std::cout << "Fase::jogador eh nullptr" << std::endl;
                exit(1);
            }
            Item::Arma* espadaJogador = new Item::Arma(IDs::IDs::espada_jogador, atributosArma);
            if(espadaJogador == nullptr){
                std::cout << "Fase::nao foi possivel criar espada do jogador" << std::endl;
                exit(1);
            }
            pJogador->setArma(espadaJogador);
            listaPersonagens->addEntidade(static_cast<Entidade::Entidade*>(pJogador));
            listaPersonagens->addEntidade(static_cast<Entidade::Entidade*>(espadaJogador));
        }

        Jogador::Jogador* Fase::getJogador(){
            for(int i = 0; i < listaPersonagens->getTam(); i++){
                Entidade::Entidade* ent = listaPersonagens->operator[](i);
                if(ent->getID() == IDs::IDs::jogador){
                    return dynamic_cast<Jogador::Jogador*>(ent);
                }
            }
            return nullptr;
        }

        void Fase::mudarEstadoObservador(){
            observadorFase->mudarEstadoAtivar();
        }

        void Fase::mudarFase(){
            observadorFase->setFase(this);
            if(getJogador() == nullptr && pJogador != nullptr){
                pJogador->setPos(sf::Vector2f(200.0f, 400.0f));
                listaPersonagens->addEntidade(static_cast<Entidade::Entidade*>(pJogador));
                listaPersonagens->addEntidade(static_cast<Entidade::Entidade*>(pJogador->getArma()));
            }
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
            pJogador = getJogador();
            if(pJogador){
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