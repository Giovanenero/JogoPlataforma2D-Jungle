#include "../../../include/Entidade/Item/Moeda.hpp"
#include "../../../include/Entidade/Personagem/Jogador/Jogador.hpp"

namespace Jungle {

    namespace Entidade {

        namespace Item {

            Moeda::Moeda(const sf::Vector2f pos, const IDs::IDs ID):
                Entidade(sf::Vector2f(TAMANHO_MOEDA, TAMANHO_MOEDA), ID, pos), 
                pontos(ID == IDs::IDs::moeda_amarela ? PONTOS_MOEDA_AMARELA : PONTOS_MOEDA_CINZA),
                animacao(&corpo), tipo(ID == IDs::IDs::moeda_amarela ? "MOEDA_AMARELA" : "MOEDA_CINZA")
            {
                inicializarAnimacao();
            }

            Moeda::Moeda(const std::vector<std::string> atributos, const IDs::IDs ID):
                Entidade(sf::Vector2f(TAMANHO_MOEDA, TAMANHO_MOEDA), ID, sf::Vector2f(0.0f, 0.0f)), 
                pontos(ID == IDs::IDs::moeda_amarela ? PONTOS_MOEDA_AMARELA : PONTOS_MOEDA_CINZA),
                animacao(&corpo), tipo(ID == IDs::IDs::moeda_amarela ? "MOEDA_AMARELA" : "MOEDA_CINZA")
            {
                try {
                    sf::Vector2f posAtual = sf::Vector2f(std::stof(atributos[1]), std::stof(atributos[2]));
                    sf::Vector2f tamAtual = sf::Vector2f(std::stof(atributos[3]), std::stof(atributos[4]));
                    const std::string imgAtual = atributos[5];
                    const unsigned int quadroAtual = std::stoi(atributos[6]);
                    const float tempoTotalAtual = std::stof(atributos[7]);

                    setPos(posAtual);
                    setTam(tamAtual);

                    inicializarAnimacao();
                    animacao.setImgAtual(imgAtual);
                    animacao.setQuadroAtual(quadroAtual);
                    animacao.setTempoTotal(tempoTotalAtual);
                } catch(const std::exception& e) {
                    std::cerr << "ERRO::Moeda::" << e.what() << std::endl;
                    podeRemover = true;
                }   
            }

            Moeda::~Moeda(){

            }

            void Moeda::inicializarAnimacao(){
                const char* caminhoTextura = ID == IDs::IDs::moeda_amarela ? CAMINHO_MOEDA_AMARELA : CAMINHO_MOEDA_CINZA; 
                animacao.addAnimacao(caminhoTextura , tipo, 8, 0.12f, sf::Vector2f(1.0f, 1.0f));
                animacao.setImgAtual(tipo);
            }

            void Moeda::colisao(Entidade* outraEntidade, sf::Vector2f ds){
                if(outraEntidade->getID() == IDs::IDs::jogador){
                    Personagem::Jogador::Jogador* pJogador = dynamic_cast<Personagem::Jogador::Jogador*>(outraEntidade);
                    pJogador->addPontuacao(this->pontos);
                    podeRemover = true;
                }
            }

            const unsigned int Moeda::getPontos() const{
                return pontos;
            }

            const std::string Moeda::salvar(){
                std::string linha = salvarEntidade();
                linha += animacao.getImgAtual() + ' ';
                linha += std::to_string(animacao.getQuadroAtual()) + ' ';
                linha += std::to_string(animacao.getTempoTotal());
                return linha;
            }

            void Moeda::atualizar(){
                animacao.atualizar(false, tipo);
                desenhar();
            }

        }

    }

}