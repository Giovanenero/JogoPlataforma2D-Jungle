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
                    sf::Vector2f posAtual = sf::Vector2f(std::stof(atributos[1]), std::stof(atributos[2]));
                    sf::Vector2f tamAtual = sf::Vector2f(std::stof(atributos[3]), std::stof(atributos[4]));
                    const std::string typeAtual = atributos[5];

                    setPos(posAtual);
                    setTam(tamAtual);
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
                std::string linha = "";
                //salvando atributos da entidade
                linha += std::to_string(static_cast<int>(ID)) + ' ';
                linha += std::to_string(pos.x) + ' ';
                linha += std::to_string(pos.y) + ' ';
                linha += std::to_string(tam.x) + ' ';
                linha += std::to_string(tam.y) + ' ';
                //salvando atributos da Plataforma
                linha += type;
                return linha;
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