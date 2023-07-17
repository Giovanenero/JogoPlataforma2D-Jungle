#include "../../../include/Entidade/Obstaculo/Plataforma.hpp"
#include "../../../include/Entidade/Item/Projetil.hpp"


namespace Jungle {

    namespace Entidade {

        namespace Obstaculo {

            Plataforma::Plataforma(sf::Vector2f pos):
                Obstaculo(pos, sf::Vector2f(TAMANHO_PLATAFORMA_X, TAMANHO_PLATAFORMA_Y), IDs::IDs::plataforma, CAMINHO_TEXTURA_PLATAFORMA)
            {
                //textura = pGrafico->carregarTextura(CAMINHO_TEXTURA_PLATAFORMA);
                //corpo.setTexture(&textura);
                //corpo.setFillColor(sf::Color::Green);
            }

            Plataforma::Plataforma(const std::vector<std::string> atributos):
                Obstaculo(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(TAMANHO_PLATAFORMA_X, TAMANHO_PLATAFORMA_Y), IDs::IDs::plataforma, CAMINHO_TEXTURA_PLATAFORMA)
            {
                try {
                    sf::Vector2f posAtual = sf::Vector2f(std::stof(atributos[1]), std::stof(atributos[2]));
                    sf::Vector2f tamAtual = sf::Vector2f(std::stof(atributos[3]), std::stof(atributos[4]));

                    setPos(posAtual);
                    setTam(tamAtual);
                }
                catch(const std::exception& e) {
                    std::cerr << e.what() << std::endl;
                    podeRemover = true;
                }
                
            }

            Plataforma::~Plataforma(){

            }

            void Plataforma::colisao(Entidade* outraEntidade, sf::Vector2f ds){
                //sf::Vector2f posOutro = outraEntidade->getPos();
                //sf::Vector2f tamOutro = outraEntidade->getTam();

                if(outraEntidade->getID() == IDs::IDs::jogador || outraEntidade->getID() == IDs::IDs::esqueleto ||
                    outraEntidade->getID() == IDs::IDs::minotauro || outraEntidade->getID() == IDs::IDs::alma
                ){
                    colisaoObstaculo(ds, static_cast<Personagem::Personagem*>(outraEntidade));
                } else if(outraEntidade->getID() == IDs::IDs::projetil_inimigo){
                    Item::Projetil* projetil = dynamic_cast<Item::Projetil*>(outraEntidade);
                    projetil->setColidiu(true);
                    projetil->setVelocidade(sf::Vector2f(0.0f, 0.0f));
                }
                //colisaoObstaculo(ds, static_cast<Personagem::Personagem*>(outraEntidade));
            }

        }

    }

}