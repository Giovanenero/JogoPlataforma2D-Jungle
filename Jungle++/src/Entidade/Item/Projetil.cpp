#include "../../../include/Entidade/Item/Projetil.hpp"

namespace Jungle {

    namespace Entidade {

        namespace Item {

            Projetil::Projetil(Personagem::Personagem* personagem):
                Arma(IDs::IDs::projetil_inimigo, personagem), animacao(&corpo),
                velocidade(sf::Vector2f(0.0f, 0.0f)), colidiu(true), paraEsquerda(false)
            {
                setPos(sf::Vector2f(-1000.0f, -1000.0f));
                if(personagem != nullptr){
                    inicializarAnimacao();
                }
            }

            Projetil::Projetil(const std::vector<std::string> atributos, Personagem::Personagem* personagem):
                Arma(IDs::IDs::projetil_inimigo, personagem), animacao(&corpo),
                velocidade(sf::Vector2f(0.0f, 0.0f)), colidiu(true), paraEsquerda(false)
            {
                try {
                    const sf::Vector2f posAtual = sf::Vector2f(std::stof(atributos[1]), std::stof(atributos[2]));
                    const sf::Vector2f tamAtual = sf::Vector2f(std::stof(atributos[3]), std::stof(atributos[4]));
                    const float danoAtual = std::stof(atributos[5]);
                    const bool paraEsquerdaAtual = atributos[6] == "1";
                    const sf::Vector2f velocidadeAtual = sf::Vector2f(std::stof(atributos[7]), std::stof(atributos[8]));
                    const bool colidiuAtual = atributos[9] == "1";
                    const std::string imgAtual = atributos[10];
                    const unsigned int quadroAtual = std::stoi(atributos[11]);
                    const float tempoTotalAtual = std::stof(atributos[12]);

                    setPos(posAtual);
                    setTam(tamAtual);
                    this->dano = danoAtual;
                    this->paraEsquerda = paraEsquerdaAtual;
                    this->velocidade = velocidadeAtual;
                    this->colidiu = colidiuAtual;

                    if(personagem != nullptr){
                        personagem->setArma(static_cast<Arma*>(this));
                        inicializarAnimacao();
                        animacao.setImgAtual(imgAtual);
                        animacao.setQuadroAtual(quadroAtual);
                        animacao.setTempoTotal(tempoTotalAtual);
                    }
                } catch(const std::exception& e) {
                    std::cerr << "ERRO::projetil::" << e.what() << std::endl;
                    podeRemover = true;
                }
                
            }

            Projetil::~Projetil(){

            }

            void Projetil::inicializarAnimacao(){
                if(personagem != nullptr){
                    setTam(sf::Vector2f(TAMANHO_PROJETIL, TAMANHO_PROJETIL));
                    switch (personagem->getID())
                    {
                        case (IDs::IDs::alma):
                        {
                            animacao.addAnimacao("Jungle++/img/Personagem/Inimigo/Alma/ProjetilAlma.png" , "ATACA", 4, 0.12f, sf::Vector2f(5.0f, 5.0f), sf::Vector2f(tam.x / 2.0f, tam.y / 2.2f), false);
                            animacao.setImgAtual("ATACA");
                        }
                            break;
                    }
                }
            }

            void Projetil::setVelocidade(const sf::Vector2f velocidade){
                this->velocidade = velocidade;
            }

            void Projetil::setColidiu(const bool colidiu){
                this->colidiu = colidiu;
                if(colidiu){
                    setPos(sf::Vector2f(-1000.0f, -1000.0f));
                    velocidade = sf::Vector2f(0.0f, 0.0f);
                }
            }

            const bool Projetil::getColidiu() const{
                return colidiu;
            }

            void Projetil::setSentido(const bool paraEsquerda){
                this->paraEsquerda = paraEsquerda;
                velocidade = paraEsquerda ? sf::Vector2f(velocidade.x * -1, velocidade.y) : velocidade;
            }

            void Projetil::verificaSaiuTela(){
                sf::Vector2f posCentro = pGrafico->getCamera().getCenter();
                sf::Vector2f tamJanela = pGrafico->getTamJanela();
                if(pos.x < posCentro.x - tamJanela.x / 2.0f || pos.x > posCentro.x + tamJanela.x / 2.0f ||
                    pos.y < posCentro.y - tamJanela.y / 2.0f || pos.y > posCentro.y + tamJanela.y / 2.0f
                ){
                    setVelocidade(sf::Vector2f(0.0f, 0.0f));
                    setColidiu(true);
                }
            }

            void Projetil::atualizarPosicao(){
                const float tempo = pGrafico->getTempo();
                sf::Vector2f posFinal(0.0f, 0.0f);

                //MRU
                posFinal.x = pos.x + velocidade.x * tempo;

                //MRUV
                posFinal.y = pos.y + velocidade.y * tempo + (-GRAVIDADE * (tempo * tempo))/2;

                setPos(posFinal);
            }

            void Projetil::atualizarAnimacao(){
               animacao.atualizar(paraEsquerda, "ATACA");
            }

            void Projetil::desenhar(){
                pGrafico->desenhaElemento(corpo);
            }

            const std::string Projetil::salvar(){
                std::string linha = salvarArma();
                linha += std::to_string(paraEsquerda) + ' ';
                linha += std::to_string(velocidade.x) + ' ';
                linha += std::to_string(velocidade.y) + ' ';
                linha += std::to_string(colidiu) + ' ';
                linha += animacao.getImgAtual() + ' ';
                linha += std::to_string(animacao.getQuadroAtual()) + ' ';
                linha += std::to_string(animacao.getTempoTotal());
                return linha;
            }

            void Projetil::atualizar(){
                if(!colidiu){
                    atualizarPosicao();
                    verificaSaiuTela();
                    atualizarAnimacao();
                    desenhar();
                }
            }

        }

    }
    
}