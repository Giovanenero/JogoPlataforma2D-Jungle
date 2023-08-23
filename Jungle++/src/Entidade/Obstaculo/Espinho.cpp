#include "../../../include/Entidade/Obstaculo/Espinho.hpp"

namespace Jungle {

    namespace Entidade {

        namespace Obstaculo {

            Espinho::Espinho(const sf::Vector2f pos, const sf::Vector2f tam):
                Obstaculo(pos, tam, IDs::IDs::espinho), dano(DANO_ESPINHO_PADRAO)
            {
                inicializarAnimacao();
            }

            Espinho::Espinho(const std::vector<std::string> atributos):
                Obstaculo(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(0.0f, 0.0f), IDs::IDs::espinho), dano(DANO_ESPINHO_PADRAO)
            {
                try {
                    const sf::Vector2f posAtual = sf::Vector2f(std::stof(atributos[1]), std::stof(atributos[2]));
                    const sf::Vector2f tamAtual = sf::Vector2f(std::stof(atributos[3]), std::stof(atributos[4]));
                    const float danoAtual = std::stof(atributos[5]);

                    setPos(posAtual);
                    setTam(tamAtual);
                    this->dano = danoAtual;
                    inicializarAnimacao();
                }
                catch(const std::exception& e){
                    std::cerr << e.what() << std::endl;
                    podeRemover = true;
                }
                
            }
            
            Espinho::~Espinho(){

            }

            void Espinho::inicializarAnimacao(){
                textura = pGrafico->carregarTextura(CAMINHO_TEXTURA_ESPINHO);
                corpo.setTexture(&textura);
            }
            
            void Espinho::setDano(const float dano){
                this->dano = dano;
            }
            
            const float Espinho::getDano() const {
                return dano;
            }

            void Espinho::colisao(Entidade* outraEntidade, sf::Vector2f ds){
                if(outraEntidade->getID() == IDs::IDs::jogador){
                    Personagem::Jogador::Jogador* pJogador = dynamic_cast<Personagem::Jogador::Jogador*>(outraEntidade);
                    pJogador->tomarDano(dano);
                    if(!pJogador->getMorrer()){
                        const float gravidade = 1200.0f;
                        const float tamPulo = 120.0f;
                        pJogador->setVelFinal(sf::Vector2f(pJogador->getVelFinal().x, -sqrt(2.0f * gravidade * tamPulo)));
                    }
                }
            }

            const std::string Espinho::salvar(){
                std::string linha = salvarObstaculo();
                linha += std::to_string(dano);
                return linha;
            }

        }

    }

}