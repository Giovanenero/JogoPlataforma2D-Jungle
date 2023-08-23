#include "../../../include/Entidade/Item/Vida.hpp"

namespace Jungle {

    namespace Entidade {

        namespace Item {

            Vida::Vida(const sf::Vector2f pos):
                Entidade(sf::Vector2f(TAMANHO_VIDA, TAMANHO_VIDA), IDs::IDs::vida, pos), animacao(&corpo)
            {
                srand(time(NULL));
                vida = rand()%VIDA_MAXIMA + VIDA_MINIMA; 
                if(vida < 50.0f){
                    setTam(sf::Vector2f(TAMANHO_VIDA / 1.7f , TAMANHO_VIDA / 1.7f));
                }
                inicializarAnimacao();
            }

            Vida::Vida(const std::vector<std::string> atributos):
                Entidade(sf::Vector2f(0.0f, 0.0f), IDs::IDs::vida, sf::Vector2f(0.0f, 0.0f)), animacao(&corpo)
            {
                try {
                    const sf::Vector2f posAtual = sf::Vector2f(std::stof(atributos[1]), std::stof(atributos[2]));
                    const sf::Vector2f tamAtual = sf::Vector2f(std::stof(atributos[3]), std::stof(atributos[4]));
                    const float vidaAtual = std::stof(atributos[5]);
                    const std::string imgAtual = atributos[6];
                    const unsigned int quadroAtual = std::stoi(atributos[7]);
                    const float tempoTotalAtual = std::stof(atributos[8]);

                    setPos(posAtual);
                    setTam(tamAtual);
                    this->vida = vidaAtual;

                    inicializarAnimacao();
                    animacao.setImgAtual(imgAtual);
                    animacao.setQuadroAtual(quadroAtual);
                    animacao.setTempoTotal(tempoTotalAtual);
                }
                catch(const std::exception& e) {
                    std::cerr << "ERRO::Vida::" << e.what() << std::endl;
                    podeRemover = true;
                }
            }

            Vida::~Vida(){

            }

            void Vida::inicializarAnimacao(){
                animacao.addAnimacao("Jungle++/img/Item/vida.png", "VIDA", 3, 0.20f, sf::Vector2f(1.0f, 1.0f));
            }
            
            void Vida::atualizarAnimacao(){
                animacao.atualizar(true, "VIDA");
            }

            void Vida::colisao(Entidade* outraEntidade, sf::Vector2f ds){
                const IDs::IDs ID_Outro = outraEntidade->getID();
                if(ID_Outro == IDs::IDs::jogador){
                    Personagem::Jogador::Jogador* jogador = dynamic_cast<Personagem::Jogador::Jogador*>(outraEntidade);
                    jogador->setVida(vida);
                    podeRemover = true;
                }
            }

            const std::string Vida::salvar(){
                std::string linha = salvarEntidade();
                linha += std::to_string(vida) + ' ';
                linha += animacao.getImgAtual() + ' ';
                linha += std::to_string(animacao.getQuadroAtual()) + ' ';
                linha += std::to_string(animacao.getTempoTotal());
                return linha;
            }

            void Vida::atualizar(){
                atualizarAnimacao();

                desenhar();
            }

            const float Vida::getVida() const{
                return vida;
            }

        }

    }

}