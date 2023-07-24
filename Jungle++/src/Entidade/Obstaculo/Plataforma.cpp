#include "../../../include/Entidade/Obstaculo/Plataforma.hpp"
#include "../../../include/Entidade/Item/Projetil.hpp"


namespace Jungle {

    namespace Entidade {

        namespace Obstaculo {

            Plataforma::Plataforma(const IDs::IDs ID, sf::Vector2f pos, const sf::Vector2f tam, const bool ehFlutuante):
                Obstaculo(pos, tam, ID), ehFlutuante(ehFlutuante)
            {
                //inicializarAnimacao();
            }

            Plataforma::Plataforma(const std::vector<std::string> atributos):
                Obstaculo(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(0.0f, 0.0f), IDs::IDs::plataforma)
            {
                try {
                    sf::Vector2f posAtual = sf::Vector2f(std::stof(atributos[1]), std::stof(atributos[2]));
                    sf::Vector2f tamAtual = sf::Vector2f(std::stof(atributos[3]), std::stof(atributos[4]));

                    setPos(posAtual);
                    setTam(tamAtual);

                    //inicializarAnimacao();
                }
                catch(const std::exception& e) {
                    std::cerr << e.what() << std::endl;
                    podeRemover = true;
                }
                
            }

            Plataforma::~Plataforma(){

            }

            void Plataforma::inicializarAnimacao(){
                textura = pGrafico->carregarTextura(ehFlutuante ? CAMINHO_TEXTURA_PLATAFORMA_FLUTUANTE : CAMINHO_TEXTURA_PLATAFORMA);
                corpo.setTexture(&textura);
            }

            void Plataforma::colisao(Entidade* outraEntidade, sf::Vector2f ds){
                if(
                    outraEntidade->getID() == IDs::IDs::esqueleto   ||
                    outraEntidade->getID() == IDs::IDs::minotauro   || 
                    outraEntidade->getID() == IDs::IDs::alma        ||
                    outraEntidade->getID() == IDs::IDs::jogador
                ){
                    colisaoObstaculo(ds, static_cast<Personagem::Personagem*>(outraEntidade));
                } else if(outraEntidade->getID() == IDs::IDs::projetil_inimigo){
                    Item::Projetil* projetil = dynamic_cast<Item::Projetil*>(outraEntidade);
                    projetil->setColidiu(true);
                    projetil->setVelocidade(sf::Vector2f(0.0f, 0.0f));
                }
            }

        }

    }

}