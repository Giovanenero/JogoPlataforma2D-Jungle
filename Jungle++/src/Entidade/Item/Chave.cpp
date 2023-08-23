#include "../../../include/Entidade/Item/Chave.hpp"
#include "../../../include/Entidade/Obstaculo/Porta.hpp"
#include "../../../include/Entidade/Personagem/Jogador/Jogador.hpp"

namespace Jungle {

    namespace Entidade {

        namespace Item {

            Chave::Chave(const sf::Vector2f pos, const sf::Vector2f tam):
                Entidade(tam, IDs::IDs::chave, pos), animacao(&corpo), porta(nullptr),
                coletou(false)
            {
                animacao.addAnimacao("Jungle++/img/Item/chave.png", "CHAVE", 5, 0.3f, sf::Vector2f(1.2f, 1.2f), sf::Vector2f(tam.x / 4.0f, tam.y / 5.5f));
            }

            Chave::Chave(const std::vector<std::string> atributos):
                Entidade(sf::Vector2f(0.0f, 0.0f), IDs::IDs::chave, sf::Vector2f(0.0f, 0.0f)),
                animacao(&corpo), porta(nullptr)
            {
                try {
                    const sf::Vector2f posAtual = sf::Vector2f(std::stof(atributos[1]), std::stof(atributos[2]));
                    const sf::Vector2f tamAtual = sf::Vector2f(std::stof(atributos[3]), std::stof(atributos[4]));
                    const std::string imgAtual = atributos[5];
                    const unsigned int quadroAtual = std::stoi(atributos[6]);
                    const float tempoTotalAtual = std::stof(atributos[7]);
                    const bool coletouAtual = atributos[8] == "1";

                    setPos(posAtual);
                    setTam(tamAtual);
                    animacao.addAnimacao("Jungle++/img/Item/chave.png", "CHAVE", 5, 0.3f, sf::Vector2f(1.2f, 1.2f), sf::Vector2f(tam.x / 4.0f, tam.y / 5.5f));
                    animacao.setImgAtual(imgAtual);
                    animacao.setQuadroAtual(quadroAtual);
                    animacao.setTempoTotal(tempoTotalAtual);
                    this->coletou = coletouAtual;
                } catch(const std::exception& e){
                    std::cerr << e.what() << std::endl;
                    podeRemover = true;
                }
                
            }
            
            Chave::~Chave(){

            }
            
            void Chave::setPorta(Obstaculo::Porta* porta){
                this->porta = porta;
            }

            Obstaculo::Porta* Chave::getPorta(){
                return porta;
            }

            void Chave::setColetou(const bool coletou){
                this->coletou = coletou; 
            }

            const bool Chave::getColetou() const{
                return coletou;
            }

            void Chave::colisao(Entidade* outraEntidade, sf::Vector2f ds){
                if(!coletou){
                    if(outraEntidade->getID() == IDs::IDs::jogador){
                        Personagem::Jogador::Jogador* pJogador = dynamic_cast<Personagem::Jogador::Jogador*>(outraEntidade);
                        pJogador->addChave(this);
                    }
                }
            }

            const std::string Chave::salvar(){
                std::string linha = salvarEntidade();
                linha += animacao.getImgAtual() + ' ';
                linha += std::to_string(animacao.getQuadroAtual()) + ' ';
                linha += std::to_string(animacao.getTempoTotal()) + ' ';
                linha += std::to_string(coletou);
                return linha;
            }

            void Chave::atualizar(){
                animacao.atualizar(true, "CHAVE");
                desenhar();
            }

        }

    }

}