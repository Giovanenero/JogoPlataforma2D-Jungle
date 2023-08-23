#include "../../../include/Entidade/Obstaculo/PlataformaMovel.hpp"
#include "../../../include/Entidade/Item/Projetil.hpp"

namespace Jungle {

    namespace Entidade {

        namespace Obstaculo {

            PlataformaMovel::PlataformaMovel(const sf::Vector2f pos, const float distancia, const sf::Vector2f tam, const bool horizontal):
                Plataforma(IDs::IDs::plataforma_movel, pos, tam, "flutuante1"), horizontal(horizontal), 
                posFinal(horizontal ? pos.x + distancia : pos.y + distancia), posInicial(horizontal ? pos.x : pos.y),
                ds(sf::Vector2f(0.0f, 0.0f)), paraBaixo(false), paraEsquerda(false),
                velocidade(sf::Vector2f(VELOCIDADE_PLATAFORMA, VELOCIDADE_PLATAFORMA))
            {
                if(posInicial > posFinal){
                    paraEsquerda = true;
                    paraBaixo = true;
                }
            }

            PlataformaMovel::PlataformaMovel(const std::vector<std::string> atributos):
                Plataforma(IDs::IDs::plataforma_movel, sf::Vector2f(0.0f, 0.0f), sf::Vector2f(0.0f, 0.0f), "flutuante1"),
                velocidade(sf::Vector2f(VELOCIDADE_PLATAFORMA, VELOCIDADE_PLATAFORMA))
            {
                try {
                    sf::Vector2f posAtual = sf::Vector2f(std::stof(atributos[1]), std::stof(atributos[2]));
                    sf::Vector2f tamAtual = sf::Vector2f(std::stof(atributos[3]), std::stof(atributos[4]));
                    const sf::Vector2f escalaAtual = sf::Vector2f(std::stof(atributos[5]), std::stof(atributos[6]));
                    const std::string typeAtual = atributos[7];
                    const bool horizontalAtual = atributos[8] == "1";
                    const float posFinalAtual = std::stof(atributos[9]);
                    const float posInicialAtual = std::stof(atributos[10]);
                    const bool paraEsquerdaAtual = atributos[11] == "1";
                    const bool paraBaixoAtual = atributos[12] == "1";
                    const sf::Vector2f dsAtual(std::stof(atributos[13]), std::stof(atributos[14]));

                    setPos(posAtual);
                    setTam(tamAtual);
                    setEscala(escalaAtual);
                    this->type = typeAtual;
                    this->horizontal = horizontalAtual;
                    this->posFinal = posFinalAtual;
                    this->posInicial = posInicialAtual;
                    this->paraEsquerda = paraEsquerdaAtual;
                    this->paraBaixo = paraBaixoAtual;
                    this->ds = dsAtual;

                    inicializarAnimacao();
                }
                catch(const std::exception& e) {
                    std::cerr << e.what() << std::endl;
                    podeRemover = true;
                }
            }
            
            PlataformaMovel::~PlataformaMovel(){

            }

            void PlataformaMovel::atualizarPosicao(){
                const float tempo = pGrafico->getTempo();
                if(horizontal){
                    if(pos.x >= posFinal){
                        paraEsquerda = true;
                    } else if (pos.x < posInicial){
                        paraEsquerda = false;
                    }
                    ds = sf::Vector2f((paraEsquerda ? -velocidade.x : velocidade.x) * tempo, 0.0f);
                } else {
                    if(pos.y >= posFinal){
                        paraBaixo = true;
                    } else if(pos.y < posInicial){
                        paraBaixo = false;
                    }
                    ds = sf::Vector2f(0.0f, (paraBaixo ? -velocidade.y : velocidade.y) * tempo);
                }
                setPos(pos + ds);
            }

            void PlataformaMovel::colisao(Entidade* outraEntidade, sf::Vector2f ds){
                if(outraEntidade->getID() == IDs::IDs::jogador){
                    colisaoObstaculo(ds, static_cast<Personagem::Personagem*>(outraEntidade));
                    Personagem::Jogador::Jogador* pJogador = dynamic_cast<Personagem::Jogador::Jogador*>(outraEntidade);
                    if(!pJogador->getAndando()){
                        pJogador->setPos(pJogador->getPos() + this->ds);
                    }
                    //faz outra coisa
                } else if(
                    outraEntidade->getID() == IDs::IDs::esqueleto   ||
                    outraEntidade->getID() == IDs::IDs::minotauro   || 
                    outraEntidade->getID() == IDs::IDs::alma
                ){
                    colisaoObstaculo(ds, static_cast<Personagem::Personagem*>(outraEntidade));
                } else if(outraEntidade->getID() == IDs::IDs::projetil_inimigo){
                    Item::Projetil* projetil = dynamic_cast<Item::Projetil*>(outraEntidade);
                    projetil->setColidiu(true);
                    projetil->setVelocidade(sf::Vector2f(0.0f, 0.0f));
                }
            }

            const std::string PlataformaMovel::salvar(){
                std::string linha = salvarPlataforma();
                linha += std::to_string(horizontal) + ' ';
                linha += std::to_string(posFinal) + ' ';
                linha += std::to_string(posInicial) + ' ';
                linha += std::to_string(paraEsquerda) + ' ';
                linha += std::to_string(paraBaixo) + ' ';
                linha += std::to_string(ds.x) + ' ';
                linha += std::to_string(ds.y);
                return linha;
            }
            
            void PlataformaMovel::atualizar(){
                atualizarPosicao();
                desenhar();
            }

        }

    }

}