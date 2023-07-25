#include "../../../include/Entidade/Obstaculo/PlataformaMovel.hpp"
#include "../../../include/Entidade/Item/Projetil.hpp"

namespace Jungle {

    namespace Entidade {

        namespace Obstaculo {

            PlataformaMovel::PlataformaMovel(const sf::Vector2f pos, const float distancia, const sf::Vector2f tam, const bool ehFlutuante, const bool horizontal):
                Plataforma(IDs::IDs::plataforma_movel, pos, tam, ehFlutuante), horizontal(horizontal), posFinal(pos.x + distancia),
                posInicial(pos.x), paraEsquerda(pos.x > posFinal), paraBaixo(pos.y > posFinal),
                velocidade(sf::Vector2f(VELOCIDADE_PLATAFORMA, VELOCIDADE_PLATAFORMA)), tempo(0.0f),
                ds(sf::Vector2f(0.0f, 0.0f))
            {

            }

            PlataformaMovel::PlataformaMovel(const std::vector<std::string> atributos):
                Plataforma(IDs::IDs::plataforma_movel, sf::Vector2f(0.0f, 0.0f), sf::Vector2f(0.0f, 0.0f), false),
                velocidade(sf::Vector2f(VELOCIDADE_PLATAFORMA, VELOCIDADE_PLATAFORMA))
            {
                try {
                    sf::Vector2f posAtual = sf::Vector2f(std::stof(atributos[1]), std::stof(atributos[2]));
                    sf::Vector2f tamAtual = sf::Vector2f(std::stof(atributos[3]), std::stof(atributos[4]));
                    const bool ehFlutuanteAtual = atributos[5] == "1";
                    const bool horizontalAtual = atributos[6] == "1";
                    const float posFinalAtual = std::stof(atributos[7]);
                    const float posInicialAtual = std::stof(atributos[8]);
                    const bool paraEsquerdaAtual = atributos[9] == "1";
                    const bool paraBaixoAtual = atributos[10] == "1";
                    const sf::Vector2f dsAtual(std::stof(atributos[11]), std::stof(atributos[12]));
                    const float tempoAtual = std::stof(atributos[13]);

                    setPos(posAtual);
                    setTam(tamAtual);
                    ehFlutuante = ehFlutuanteAtual;
                    this->horizontal = horizontalAtual;
                    this->posFinal = posFinalAtual;
                    this->posInicial = posInicialAtual;
                    this->paraEsquerda = paraEsquerdaAtual;
                    this->paraBaixo = paraBaixoAtual;
                    this->ds = dsAtual;
                    this->tempo = tempoAtual;

                    inicializarAnimacao();
                }
                catch(const std::exception& e) {
                    std::cerr << e.what() << std::endl;
                    podeRemover = true;
                }
            }
            
            PlataformaMovel::~PlataformaMovel(){

            }

            void PlataformaMovel::inicializarAnimacao(){
                textura = pGrafico->carregarTextura(CAMINHO_TEXTURA_PLATAFORMA_FLUTUANTE);
                corpo.setTexture(&textura);
            }

            void PlataformaMovel::atualizarPosicao(){
                if(horizontal){
                    if(pos.x >= posFinal || pos.x <= posInicial){
                        paraEsquerda = !paraEsquerda;
                    }
                    ds = sf::Vector2f((paraEsquerda ? -velocidade.x : velocidade.x) * tempo, 0.0f);
                } else {
                    if(pos.y >= posFinal || pos.y <= posInicial){
                        paraBaixo = !paraBaixo;
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
                std::string linha = "";
                //salvando atributos da entidade
                linha += std::to_string(static_cast<int>(ID)) + ' ';
                linha += std::to_string(pos.x) + ' ';
                linha += std::to_string(pos.y) + ' ';
                linha += std::to_string(tam.x) + ' ';
                linha += std::to_string(tam.y) + ' ';
                //salvando atributos da Plataforma
                linha += std::to_string(ehFlutuante) + ' ';
                //salvando atributos da PlataformaMovel
                linha += std::to_string(horizontal) + ' ';
                linha += std::to_string(posFinal) + ' ';
                linha += std::to_string(posInicial) + ' ';
                linha += std::to_string(paraEsquerda) + ' ';
                linha += std::to_string(paraBaixo) + ' ';
                linha += std::to_string(ds.x) + ' ';
                linha += std::to_string(ds.y) + ' ';
                linha += std::to_string(tempo);
                return linha;
            }
            
            void PlataformaMovel::atualizar(){
                tempo = pGrafico->getTempo();
                atualizarPosicao();
                desenhar();
            }

        }

    }

}