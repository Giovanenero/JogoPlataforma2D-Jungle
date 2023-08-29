#include "../../../include/Entidade/Obstaculo/Plataforma.hpp"
#include "../../../include/Entidade/Item/Projetil.hpp"


namespace Jungle {

    namespace Entidade {

        namespace Obstaculo {

            Plataforma::Plataforma(const IDs::IDs ID, sf::Vector2f pos, const sf::Vector2f tam, const std::string type):
                Obstaculo(pos, tam, ID), type(type), escala(sf::Vector2f(1.0f, 1.0f))
            {
                inicializarAnimacao();
            }

            Plataforma::Plataforma(const std::vector<std::string> atributos):
                Obstaculo(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(0.0f, 0.0f), IDs::IDs::plataforma)
            {
                try {
                    const sf::Vector2f posAtual = sf::Vector2f(std::stof(atributos[1]), std::stof(atributos[2]));
                    const sf::Vector2f tamAtual = sf::Vector2f(std::stof(atributos[3]), std::stof(atributos[4]));
                    const sf::Vector2f escalaAtual = sf::Vector2f(std::stof(atributos[5]), std::stof(atributos[6]));
                    const std::string typeAtual = atributos[7];

                    setPos(posAtual);
                    setTam(tamAtual);
                    setEscala(escalaAtual);
                    this->type = typeAtual;

                    inicializarAnimacao();
                }
                catch(const std::exception& e) {
                    std::cerr << e.what() << std::endl;
                    podeRemover = true;
                }
                
            }

            Plataforma::~Plataforma(){

            }

            const std::string Plataforma::salvarPlataforma(){
                std::string linha = salvarObstaculo();
                linha += std::to_string(escala.x) + ' ';
                linha += std::to_string(escala.y) + ' ';
                linha += type + ' ';
                return linha;
            }

            void Plataforma::inicializarAnimacao(){
                if(type == "padrao"){
                    textura = pGrafico->carregarTextura(CAMINHO_TEXTURA_PLATAFORMA_PADRAO);
                } else if(type == "flutuante1"){
                    textura = pGrafico->carregarTextura(CAMINHO_TEXTURA_PLATAFORMA_FLUTUANTE_1);
                } else if(type == "flutuante2"){
                    textura = pGrafico->carregarTextura(CAMINHO_TEXTURA_PLATAFORMA_FLUTUANTE_2);
                } else if(type == "flutuante_maior"){
                    textura = pGrafico->carregarTextura(CAMINHO_TEXTURA_PLATAFORMA_FLUTUANTE_MAIOR);
                } else if(type == "madeira"){
                    textura = pGrafico->carregarTextura(CAMINHO_TEXTURA_PLATAFORMA_MADEIRA);
                } else if(type == "parede"){
                    textura = pGrafico->carregarTextura(CAMINHO_TEXTURA_PAREDE);
                } else if(type == "parede_flutuante"){
                    textura = pGrafico->carregarTextura(CAMINHO_TEXTURA_PAREDE_FLUTUANTE);
                } else if(type == "ponte_direita"){
                    textura = pGrafico->carregarTextura(CAMINHO_TEXTURA_PLATAFORMA_PONTE_DIREITA);
                } else if(type == "ponte_esquerda"){
                    textura = pGrafico->carregarTextura(CAMINHO_TEXTURA_PLATAFORMA_PONTE_ESQUERDA);
                } else {
                    std::cout << "ERRO::Plataforma type eh invalido" << std::endl;
                    exit(1);
                }
                corpo.setTexture(&textura);
                corpo.setScale(escala);
            }

            void Plataforma::setEscala(const sf::Vector2f escala){
                this->escala = escala;
                corpo.setScale(this->escala);
            }

            const std::string Plataforma::salvar(){
                std::string linha = salvarObstaculo();
                linha += std::to_string(escala.x) + ' ';
                linha += std::to_string(escala.y) + ' ';
                linha += type;
                return linha;
            }

            void Plataforma::colisao(Entidade* outraEntidade, sf::Vector2f ds){
                if(
                    outraEntidade->getID() == IDs::IDs::esqueleto   ||
                    outraEntidade->getID() == IDs::IDs::minotauro   || 
                    outraEntidade->getID() == IDs::IDs::alma        ||
                    outraEntidade->getID() == IDs::IDs::jogador     ||
                    outraEntidade->getID() == IDs::IDs::carniceiro
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