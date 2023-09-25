#include "../../include/Fase/Fase.hpp"

namespace Jungle {

    using namespace Entidade;
    using namespace Entidade::Personagem;

    namespace Fase {

        Jogador::Jogador* Fase::pJogador = nullptr;
        Observador::ObservadorFase* Fase::observadorFase = nullptr;
        unsigned int Fase::pontuacaoJogador = 0;
        Menu::Botao::Texto Fase::textoPontuacao = Menu::Botao::Texto(pGrafico->carregarFonte(CAMINHO_FONTE_FASE), "", 32);
        Menu::Botao::Texto Fase::textoTempo = Menu::Botao::Texto(pGrafico->carregarFonte(CAMINHO_FONTE_FASE), "", 32);

        Fase::Fase(const IDs::IDs ID_Fase, const IDs::IDs ID_Fundo):
            Ente(ID_Fase), fundo(ID_Fundo), listaPersonagens(new Lista::ListaEntidade()), listaObstaculos(new Lista::ListaEntidade()),
            pColisao(new Gerenciador::GerenciadorColisao(listaPersonagens, listaObstaculos)),
            GArquivo(), tempo(0.0f)
        {
            if(listaPersonagens == nullptr || listaObstaculos == nullptr){
                std::cout << "Jungle::Fase::nao foi possivel criar lista de entidades na fase" << std::endl;
                exit(1);
            }

            if(pColisao == nullptr){
                std::cout << "Jungle::Fase::nao foi possivel criar um Gerenciador de Colisao" << std::endl;
                exit(1);
            }

            if(observadorFase == nullptr){
                observadorFase = new Observador::ObservadorFase();
            }

            observadorFase->setFase(this);
            if(textoPontuacao.getString() == "" && textoTempo.getString() == ""){
                textoPontuacao.setString("Pontos: 00000");
                textoPontuacao.setTamanhoBorda(2);
                textoTempo.setString("Tempo 00:00");
                textoTempo.setTamanhoBorda(2);
            }
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
                if(getJogador() != nullptr && pJogador != nullptr){
                    delete(listaPersonagens);
                    pJogador = nullptr;
                } else {
                    delete(listaPersonagens);
                }
                listaPersonagens = nullptr;
            }

            if(listaObstaculos != nullptr){
                delete(listaObstaculos);
                listaObstaculos = nullptr;
            }

            if(pontuacaoJogador > 0){
                pontuacaoJogador = 0;
                textoPontuacao.setString("");
                textoTempo.setString("");
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

        void Fase::criarPlataforma(const sf::Vector2f pos, const sf::Vector2f tam, const std::string type, const sf::Vector2f escala){
            Obstaculo::Plataforma* plataforma = new Obstaculo::Plataforma(IDs::IDs::plataforma, pos, tam, type);
            if(plataforma == nullptr){
                std::cout << "Fase::nao foi possivel criar plataforma" << std::endl;
                exit(1);
            }
            plataforma->setEscala(escala);
            listaObstaculos->addEntidade(static_cast<Entidade::Entidade*>(plataforma));
        }

        void Fase::criarPlataforma(const sf::Vector2f pos, const sf::Vector2f tam, const float distancia, const bool horizontal){
            Obstaculo::PlataformaMovel* plataformaMovel = new Obstaculo::PlataformaMovel(pos, distancia, tam, horizontal);
            if(plataformaMovel == nullptr){
                std::cout << "Fase::nao foi possivel criar plataformaMovel" << std::endl;
                exit(1);
            }
            listaObstaculos->addEntidade(static_cast<Entidade::Entidade*>(plataformaMovel));
        }

        void Fase::criarCaixa(const sf::Vector2f pos){
            Obstaculo::Caixa* caixa = new Obstaculo::Caixa(pos);
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
        
        void Fase::criarVida(const sf::Vector2f pos){
            Item::Vida* vida = new Item::Vida(pos);
            if(vida == nullptr){
                std::cout << "Fase::nao foi possivel criar vida" << std::endl;
                exit(1);
            }
            listaPersonagens->addEntidade(static_cast<Entidade::Entidade*>(vida));
        }

        void Fase::criarPorta(const sf::Vector2f posPorta, const sf::Vector2f tamPorta, const sf::Vector2f posChave, const sf::Vector2f tamChave, const IDs::IDs ID_Fase){
            Item::Chave* chave = nullptr;
            if(posChave != sf::Vector2f(-1000.0f, -1000.0f)){
                chave = new Item::Chave(posChave, tamChave);
                if(chave == nullptr){
                    std::cout << "Fase::nao foi possivel criar uma chave" << std::endl;
                    exit(1);
                }
            }
            Obstaculo::Porta* porta = new Obstaculo::Porta(posPorta, tamPorta, chave, ID_Fase);
            if(porta == nullptr){
                std::cout << "Fase::nao foi possivel criar uma porta" << std::endl;
                exit(1);
            }
            listaObstaculos->addEntidade(static_cast<Entidade::Entidade*>(porta));
            if(chave != nullptr){
                chave->setPorta(porta);
                listaObstaculos->addEntidade(static_cast<Entidade::Entidade*>(chave));
            }
        }

        void Fase::criarEspinho(const sf::Vector2f pos, const sf::Vector2f tam){
            Obstaculo::Espinho* espinho = new Obstaculo::Espinho(pos, tam);
            if(espinho == nullptr){
                std::cout << "Fase::nao foi possivel criar espinhos" << std::endl;
                exit(1);
            }
            listaObstaculos->addEntidade(static_cast<Entidade::Entidade*>(espinho));
        }

        void Fase::criarPersonagem(const IDs::IDs ID, const sf::Vector2f pos, const int nivel){
            Entidade::Entidade* personagem = nullptr;
            Entidade::Entidade* arma = nullptr;
            if(ID == IDs::IDs::jogador){
                if(pJogador != nullptr){
                    std::cout << "ERRO::pJogador ja existe" << std::endl;
                    exit(1);
                }
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
                personagem = static_cast<Entidade::Entidade*>(pJogador);
                arma = static_cast<Entidade::Entidade*>(espadaJogador);
            } else {
                if(pJogador == nullptr){
                    std::cout << "ERRO::Fase o ponteiro do jogador eh nullptr" << std::endl;
                    exit(1);
                }
                if(ID == IDs::IDs::esqueleto){
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
                    personagem = static_cast<Entidade::Entidade*>(esqueleto);
                    arma = static_cast<Entidade::Entidade*>(espadaInimigo);
                } else if(ID == IDs::IDs::alma){
                    Inimigo::Alma* alma = new Inimigo::Alma(pos, nivel, pJogador);
                    if(alma == nullptr){
                        std::cout << "Fase::nao foi possivel criar alma" << std::endl;
                        exit(1);
                    }
                    Item::Projetil* projetil = new Item::Projetil();
                    if(projetil == nullptr){
                        std::cout << "Fase::nao foi possivel criar projetil" << std::endl;
                        exit(1);
                    }
                    alma->setArma(static_cast<Item::Projetil*>(projetil));
                    projetil->inicializarAnimacao();
                    personagem = static_cast<Entidade::Entidade*>(alma);
                    arma = static_cast<Entidade::Entidade*>(projetil);
                } else if(ID == IDs::IDs::carniceiro){
                    Inimigo::Carniceiro* carniceiro = new Inimigo::Carniceiro(pos, nivel, pJogador);
                    if(carniceiro == nullptr){
                        std::cout << "Fase::nao foi possive criar carniceiro" << std::endl;
                        exit(1);
                    }
                    personagem = static_cast<Entidade::Entidade*>(carniceiro);
                }
            }
            if(personagem != nullptr){
                listaPersonagens->addEntidade(personagem);
                if(arma != nullptr){
                    listaPersonagens->addEntidade(arma);
                }
            }
        }

        void Fase::criarEntidade(const IDs::IDs ID, const std::vector<std::string> primeiro, const std::vector<std::string> segundo, const bool ehPersonagem){
            if(ehPersonagem){
                Entidade::Entidade* personagem = nullptr;
                Entidade::Entidade* arma = nullptr;
                if(ID == IDs::IDs::jogador){
                    if(pJogador != nullptr){
                        std::cout << "ERRO::pJogador ja existe" << std::endl;
                        exit(1);
                    }
                    pJogador = new Jogador::Jogador(primeiro);
                    if(pJogador == nullptr){
                        std::cout << "ERRO::Fase nao foi possivel criar jogador" << std::endl;
                        exit(1);
                    }
                    Item::Arma* espadaJogador = new Item::Arma(IDs::IDs::espada_jogador, segundo);
                    if(espadaJogador == nullptr){
                        std::cout << "Fase::nao foi possivel criar espada do jogador" << std::endl;
                        exit(1);
                    }
                    pJogador->setArma(espadaJogador);
                    personagem = static_cast<Entidade::Entidade*>(this->pJogador);
                    arma = static_cast<Entidade::Entidade*>(espadaJogador);
                } else {
                    if(pJogador == nullptr){
                        std::cout << "ERRO::Fase o ponteiro do jogador eh nullptr" << std::endl;
                        exit(1);
                    }
                    if(ID == IDs::IDs::esqueleto){
                        Inimigo::Esqueleto* esqueleto = new Inimigo::Esqueleto(primeiro, this->pJogador);
                        if(esqueleto == nullptr){
                            std::cout << "Fase::esqueleto eh nullptr" << std::endl;
                            exit(1);
                        }
                        Item::Arma* espadaEsqueleto = new Item::Arma(IDs::IDs::espada_inimigo, segundo);
                        if(espadaEsqueleto == nullptr){
                            std::cout << "Fase::nao foi possivel criar espada esqueleto" << std::endl;
                            exit(1);
                        }
                        esqueleto->setArma(espadaEsqueleto);
                        personagem = static_cast<Entidade::Entidade*>(esqueleto);
                        arma = static_cast<Entidade::Entidade*>(espadaEsqueleto);
                    } else if(ID == IDs::IDs::alma){
                        Inimigo::Alma* alma = new Inimigo::Alma(primeiro, this->pJogador);
                        if(alma == nullptr){
                            std::cout << "Fase::alma eh nullptr" << std::endl;
                            exit(1);
                        }
                        Item::Projetil* projetil = new Item::Projetil(segundo, static_cast<Entidade::Personagem::Personagem*>(alma));
                        if(projetil == nullptr){
                            std::cout << "Fase::projetil eh nullptr" << std::endl;
                            exit(1);
                        }
                        personagem = static_cast<Entidade::Entidade*>(alma);
                        arma = static_cast<Entidade::Entidade*>(projetil);
                    } else if(ID == IDs::IDs::carniceiro){
                        Inimigo::Carniceiro* carniceiro = new Inimigo::Carniceiro(primeiro, pJogador);
                        if(carniceiro == nullptr){
                            std::cout << "Fase::carniceiro eh nullptr" << std::endl;
                            exit(1);
                        }
                        personagem = static_cast<Entidade::Entidade*>(carniceiro);
                    } else {
                        std::cout << "Fase::o ID da entidade eh invalido" << std::endl;
                        exit(1);
                    }
                }
                if(personagem != nullptr){
                    listaPersonagens->addEntidade(personagem);
                    if(arma != nullptr){
                        listaPersonagens->addEntidade(arma);
                    }
                }
            } else if(ID == IDs::IDs::plataforma){
                Obstaculo::Plataforma* plataforma = new Obstaculo::Plataforma(primeiro);
                if(plataforma == nullptr){
                    std::cout << "Fase::nao foi possivel criar plataforma" << std::endl;
                    exit(1);
                }
                listaObstaculos->addEntidade(static_cast<Entidade::Entidade*>(plataforma));
            } else if(ID == IDs::IDs::plataforma_movel){
                Obstaculo::PlataformaMovel* plataformaMovel = new Obstaculo::PlataformaMovel(primeiro);
                if(plataformaMovel == nullptr){
                    std::cout << "Fase::nao foi possivel criar plataforma movel, pois o ponteiro eh invalido" << std::endl;
                    exit(1);
                }
                listaObstaculos->addEntidade(static_cast<Entidade::Entidade*>(plataformaMovel));
            } else if(ID == IDs::IDs::caixa){
                Obstaculo::Caixa* caixa = new Obstaculo::Caixa(primeiro);
                if(caixa == nullptr){
                    std::cout << "Fase::nao foi possivel criar caixa" << std::endl;
                    exit(1);
                }
                listaObstaculos->addEntidade(static_cast<Entidade::Entidade*>(caixa));
            } else if(ID == IDs::IDs::moeda_amarela || ID == IDs::IDs::moeda_cinza){
                Item::Moeda* moeda = new Item::Moeda(primeiro, ID);
                if(moeda == nullptr){
                    std::cout << "Fase::nao foi possivel criar moeda" << std::endl;
                    exit(1);
                }
                listaPersonagens->addEntidade(static_cast<Entidade::Entidade*>(moeda));
            } else if(ID == IDs::IDs::vida){
                Item::Vida* vida = new Item::Vida(primeiro);
                if(vida == nullptr){
                    std::cout << "Fase::nao foi possivel criar vida" << std::endl;
                    exit(1);
                }
                listaPersonagens->addEntidade(static_cast<Entidade::Entidade*>(vida));
            } else if(ID == IDs::IDs::porta){
                Item::Chave* chave = nullptr;
                if(segundo.size() > 0){
                    chave = new Item::Chave(segundo);
                    if(chave == nullptr){
                        std::cout << "Fase::nao foi possivel criar uma chave" << std::endl;
                        exit(1);
                    }
                }
                Obstaculo::Porta* porta = new Obstaculo::Porta(primeiro, chave);
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
            } else if(ID == IDs::IDs::espinho){
                Obstaculo::Espinho* espinho = new Obstaculo::Espinho(primeiro);
                if(espinho == nullptr){
                    std::cout << "Fase::nao foi possivel criar espinhos" << std::endl;
                    exit(1);
                }
                listaObstaculos->addEntidade(static_cast<Entidade::Entidade*>(espinho));
            } else {
                std::cout << "ERRO::nao foi possivel criar entidade, pois o id eh invalido" << std::endl;
                exit(1);
            }
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

        void Fase::mudarFase(const IDs::IDs ID_Fase){
            observadorFase->setFase(this);
            if(getJogador() == nullptr && pJogador != nullptr){
                listaPersonagens->addEntidade(static_cast<Entidade::Entidade*>(pJogador), 0);
                listaPersonagens->addEntidade(static_cast<Entidade::Entidade*>(pJogador->getArma()), 1);
                if(ID_Fase != IDs::IDs::vazio){
                    std::vector<Entidade::Entidade*> entidades = listaObstaculos->getEntidades(IDs::IDs::porta);
                    if(entidades.size() <= 0){
                        std::cout << "ERRO::mudar fase, pois nao ha portas nesta fase" << std::endl;
                        exit(1);
                    }
                    for(int i = 0; i < entidades.size(); i++){
                        Entidade::Obstaculo::Porta* porta = dynamic_cast<Entidade::Obstaculo::Porta*>(entidades[i]);
                        if(porta->getIDFase() == ID_Fase){
                            sf::Vector2f pos(porta->getPos());
                            sf::Vector2f tam(porta->getTam());
                            pJogador->setPos(sf::Vector2f(pos.x + tam.x / 2.0f - pJogador->getTam().x / 2.0f, pos.y));
                            pGrafico->atualizarCamera(pJogador->getPos(), pJogador->getTam());
                            fundo.atualizarPosicao();
                            pGrafico->setLimiteCamera(limiteCamera);
                            return;
                        }
                    }
                }
            }
        }

        void Fase::removerJogadorLista(){
            if(getJogador() != nullptr && pJogador != nullptr){
                listaPersonagens->removerEntidade(static_cast<Entidade::Entidade*>(pJogador), false);
                listaPersonagens->removerEntidade(static_cast<Entidade::Entidade*>(pJogador->getArma()), false);
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

        void Fase::setPontuacao(const unsigned int pontuacaoJogador){
            this->pontuacaoJogador = pontuacaoJogador;
            std::string pontos = std::to_string(this->pontuacaoJogador);
            while(pontos.size() < 5){
                std::string aux = pontos;
                pontos = '0' + aux;
            }
            textoPontuacao.setString("Pontos: " + pontos);
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
            linha += 10;
            linha += std::to_string(this->pontuacaoJogador) + ' ';
            linha += 10;
            linha += textoTempo.getString();
            return linha;
        }

        const std::vector<std::string> Fase::salvarEntidades(){
            std::vector<std::string> linhas;
            for(int i = 0; i < listaPersonagens->getTam(); i++){
                Entidade::Entidade* entidade = listaPersonagens->operator[](i);
                if(entidade != nullptr){
                    std::string linha = entidade->salvar();
                    linhas.push_back(linha);
                }
            }
            for(int i = 0; i < listaObstaculos->getTam(); i++){
                Entidade::Entidade* entidade = listaObstaculos->operator[](i);
                if(entidade != nullptr){
                    std::string linha = entidade->salvar();
                    linhas.push_back(linha);
                }
            }
            return linhas;
        }

        void Fase::setLimiteCamera(sf::IntRect limiteCamera){
            this->limiteCamera = limiteCamera;
        }

        const sf::IntRect Fase::getLimiteCamera() const{
            return limiteCamera;
        }

        void Fase::executar(){
            pJogador = getJogador();
            if(pJogador){
                //atualiza fundo
                fundo.executar();

                //atualizar camera
                pGrafico->atualizarCamera(pJogador->getPos(), pJogador->getTam());

                //atualiza e desenha entidades
                listaObstaculos->executar();
                listaPersonagens->executar();

                atualizarTempo();
                atualizarPontuacao();

                //verifica colisão
                pColisao->executar();
            } else {
                observadorFase->notificarJogadorMorreu();
                pJogador = nullptr;
            }
        }

    }

}