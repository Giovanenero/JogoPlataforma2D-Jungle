#include "../../../../include/Entidade/Personagem/Jogador/Jogador.hpp"
#include "../../../../include/Observador/ObservadorJogador.hpp"
#include "../../../../include/Entidade/Personagem/Inimigo/Inimigo.hpp"
#include "../../../../include/Entidade/Item/Vida.hpp"
#include "../../../../include/Entidade/Item/Projetil.hpp"
#include "../../../../include/Entidade/Item/Moeda.hpp"
#include "../../../../include/Entidade/Obstaculo/Porta.hpp"
#include "../../../../include/Entidade/Obstaculo/Espinho.hpp"

#include <cmath>

namespace Jungle {

    namespace Entidade {

        namespace Personagem {

            namespace Jogador {

                Jogador::Jogador(const sf::Vector2f pos, Item::Arma* arma):
                    Personagem(pos, sf::Vector2f(TAMANHO_JOGADOR_X, TAMANHO_JOGADOR_Y), VELOCIDADE_JOGADOR, IDs::IDs::jogador, TEMPO_JOGADOR_MORRER, TEMPO_JOGADOR_TOMARDANO), 
                    noChao(false), observadorJogador(new Observador::ObservadorJogador(this)),
                    textoExp(pGrafico->carregarFonte("Jungle++/fonte/menuColocacao.ttf"), "", 20),
                    vectorChaves(), colidindoPorta(false), abrirPorta(false)
                {
                    this->pontos = 0;
                    if(observadorJogador == nullptr){
                        std::cout << "ERROR::Entidade::Personagem::Jogador::Jogador::nao foi possivel criar um observador para o jogador" << std::endl;
                        exit(1);
                    }
                    inicializarAnimacao();
                    inicializarBarraVida();
                    inicializarBarraXP();
                    inicializarNivel();
                    inicializarExp();
                    
                    if(arma != nullptr){
                        setArma(arma);
                        arma->setDano(nivel.getForca());
                    }

                    pGrafico->setLimiteObjeto(sf::IntRect(pos.x, pos.y, tam.x, tam.y));
                }

                Jogador::Jogador(const std::vector<std::string> atributos):
                    Personagem(pos, sf::Vector2f(TAMANHO_JOGADOR_X, TAMANHO_JOGADOR_Y), VELOCIDADE_JOGADOR, IDs::IDs::jogador, TEMPO_JOGADOR_MORRER, TEMPO_JOGADOR_TOMARDANO), 
                    noChao(false), observadorJogador(new Observador::ObservadorJogador(this)),
                    textoExp(pGrafico->carregarFonte("Jungle++/fonte/menuColocacao.ttf"), "", 20),
                    vectorChaves()
                {
                    try {
                        const sf::Vector2f posAtual = sf::Vector2f(std::stof(atributos[1]), std::stof(atributos[2]));
                        const sf::Vector2f tamAtual = sf::Vector2f(std::stof(atributos[3]), std::stof(atributos[4]));
                        const sf::Vector2f velFinalAtual = sf::Vector2f(std::stof(atributos[5]), std::stof(atributos[6]));
                        const bool andandoAtual = atributos[7] == "1";
                        const bool paraEsquerdaAtual = atributos[8] == "1";
                        const bool levandoDanoAtual = atributos[9] == "1";
                        const bool atacandoAtual = atributos[10] == "1";
                        const bool morrendoAtual = atributos[11] == "1";
                        const float vidaAtual = std::stof(atributos[12]);
                        const float tempoDanoAtual = std::stof(atributos[13]);
                        const float tempoMorrerAtual = std::stof(atributos[14]);
                        const float dtAtual = std::stof(atributos[15]);
                        const float nivelAtual = std::stoi(atributos[16]);
                        const float experienciaAtual = std::stof(atributos[17]);
                        const bool noChaoAtual = atributos[18] == "1";
                        const bool colidindoPortaAtual = atributos[19] == "1";
                        const bool abrirPortaAtual = atributos[20] == "1";
                        const std::string imgAtual = atributos[21];
                        const unsigned int quadroAtual = std::stoi(atributos[22]);
                        const float tempoTotalAtual = std::stof(atributos[23]);
                        const unsigned int pontosAtual = std::stoi(atributos[24]);

                        setPos(posAtual);
                        setTam(tamAtual);
                        setVelFinal(velFinalAtual);
                        this->andando = andandoAtual;
                        this->paraEsquerda = paraEsquerdaAtual;
                        this->levandoDano = levandoDanoAtual;
                        this->atacando = atacandoAtual;
                        this->morrendo = morrendoAtual;
                        this->vida = vidaAtual;
                        this->tempoDano = tempoDanoAtual;
                        this->tempoMorrer = tempoMorrerAtual;
                        this->dt = dtAtual;
                        this->pontos = pontosAtual;
                        nivel.setNivel(nivelAtual);
                        nivel.addExp(experienciaAtual);
                        inicializarNivel();
                        this->noChao = noChaoAtual;
                        this->colidindoPorta = colidindoPortaAtual;
                        this->abrirPorta = abrirPortaAtual;

                        inicializarAnimacao();
                        inicializarBarraVida();
                        inicializarBarraXP();
                        inicializarExp();
                        animacao.setImgAtual(imgAtual);
                        animacao.setQuadroAtual(quadroAtual);
                        animacao.setTempoTotal(tempoTotalAtual);

                        pGrafico->setLimiteObjeto(sf::IntRect(pos.x, pos.y, tam.x, tam.y));
                    }
                    catch(const std::exception& e) {
                        std::cerr << e.what() << std::endl;
                        podeRemover = true;
                    }
                }

                Jogador::~Jogador(){
                    if(observadorJogador){
                        delete(observadorJogador);
                        observadorJogador = nullptr;
                    }
                    if(tuboBarraVida.getTexture()){
                        delete(tuboBarraVida.getTexture());
                    }

                    if(barraVida.getTexture()){
                        delete(barraVida.getTexture());
                    }

                    if(tuboBarraXP.getTexture()){
                        delete(tuboBarraXP.getTexture());
                    }

                    if(barraXP.getTexture()){
                        delete(barraXP.getTexture());
                    }
                }

                void Jogador::inicializarBarraVida(){
                    sf::Vector2f tamTubo = sf::Vector2f(BARRA_VIDA_JOGADOR_X, BARRA_VIDA_JOGADOR_Y);
                    tuboBarraVida.setSize(tamTubo);
                    barraVida.setSize(tamTubo);
                    sf::Texture* texturaVida = new sf::Texture(); 
                    sf::Texture* texturaBarra = new sf::Texture();
                    texturaVida->loadFromFile("Jungle++/img/Personagem/Vida/VidaJogador.png");
                    texturaBarra->loadFromFile("Jungle++/img/Personagem/Vida/BarraVida.png");
                    barraVida.setTexture(texturaVida);
                    tuboBarraVida.setTexture(texturaBarra);
                }

                void Jogador::inicializarBarraXP(){
                    sf::Vector2f tamTubo = sf::Vector2f(BARRA_VIDA_JOGADOR_X, BARRA_VIDA_JOGADOR_Y);
                    tuboBarraXP.setSize(tamTubo);
                    sf::Texture* texturaXP = new sf::Texture(); 
                    sf::Texture* texturaBarra = new sf::Texture();
                    texturaXP->loadFromFile("Jungle++/img/Personagem/Vida/XPJogador.png");
                    texturaBarra->loadFromFile("Jungle++/img/Personagem/Vida/BarraXP.png");
                    barraXP.setTexture(texturaXP);
                    tuboBarraXP.setTexture(texturaBarra);
                }

                void Jogador::inicializarExp(){
                    std::string expAtual = std::to_string(nivel.getExp());
                    expAtual = expAtual.substr(0, expAtual.find(".") + 2);
                    std::string expProxNivel = std::to_string(nivel.getExpProxNivel());
                    expProxNivel = expProxNivel.substr(0, expProxNivel.find(".") + 2);
                    textoExp.setString(expAtual + "/" + expProxNivel);
                    textoExp.setTamanhoBorda(2);
                }


                void Jogador::inicializarAnimacao(){
                    const sf::Vector2f origin = sf::Vector2f(tam.x / 2.5f, tam.y / 2.1f);
                    animacao.addAnimacao("Jungle++/img/Personagem/Jogador/Anda.png", "ANDA", 10, 0.12f, sf::Vector2f(6,2), origin);
                    animacao.addAnimacao("Jungle++/img/Personagem/Jogador/Ataca.png", "ATACA", 10, 0.065f, sf::Vector2f(6,2), origin);
                    animacao.addAnimacao("Jungle++/img/Personagem/Jogador/Parado.png", "PARADO", 10, 0.15f, sf::Vector2f(6,2), origin);
                    animacao.addAnimacao("Jungle++/img/Personagem/Jogador/Pula.png", "PULA", 3, 0.15f, sf::Vector2f(6,2), origin);
                    animacao.addAnimacao("Jungle++/img/Personagem/Jogador/Cai.png", "CAI", 3, 0.15f, sf::Vector2f(6,2), origin);
                    animacao.addAnimacao("Jungle++/img/Personagem/Jogador/Morre.png", "MORRE", 10, 0.10f, sf::Vector2f(5,2), origin);
                    animacao.addAnimacao("Jungle++/img/Personagem/Jogador/tomaDano.png", "TOMADANO", 1, 0.5f, sf::Vector2f(6,2), origin);
                }

                void Jogador::atualizarBarraVida(){
                    sf::Vector2f posJanela = pGrafico->getCamera().getCenter();
                    sf::Vector2f tamJanela = pGrafico->getTamJanela();
                    sf::Vector2f posBarra = sf::Vector2f(posJanela.x - tamJanela.x / 2.0f + 10.0f, posJanela.y + tamJanela.y / 2.0f - 30.0f);
                    tuboBarraVida.setPosition(posBarra);
                    barraVida.setSize(sf::Vector2f((BARRA_VIDA_JOGADOR_X - 40.0f) * (vida / 100.0f), BARRA_VIDA_JOGADOR_Y - 13.0f));
                    barraVida.setPosition(sf::Vector2f(posBarra.x + 7.0f, posBarra.y + tuboBarraVida.getSize().y / 2.0f - barraVida.getSize().y / 2.0f));
                }

                void Jogador::atualizarBarraXP(){
                    sf::Vector2f posJanela = pGrafico->getCamera().getCenter();
                    sf::Vector2f tamJanela = pGrafico->getTamJanela();
                    sf::Vector2f posBarra = sf::Vector2f(posJanela.x + tamJanela.x / 2.0f - tuboBarraXP.getSize().x - 10.0f, posJanela.y + tamJanela.y / 2.0f - 30.0f);
                    tuboBarraXP.setPosition(posBarra);
                    barraXP.setSize(sf::Vector2f((BARRA_VIDA_JOGADOR_X - 40.0f) * (nivel.getExp() / nivel.getExpProxNivel()), BARRA_VIDA_JOGADOR_Y - 13.0f));
                    barraXP.setPosition(sf::Vector2f(posBarra.x + tuboBarraXP.getSize().x - barraXP.getSize().x - 7.0f, posBarra.y + tuboBarraXP.getSize().y / 2.0f - barraXP.getSize().y / 2.0f));
                }

                void Jogador::atualizarExp(){
                    sf::Vector2f posBarraXP(tuboBarraXP.getPosition());
                    textoExp.setPos(sf::Vector2f(posBarraXP.x + tuboBarraXP.getSize().x - textoExp.getTam().x - 5.0f, posBarraXP.y - textoExp.getTam().y - 12.0f));
                }

                void Jogador::atualizarChaves(){
                    sf::Vector2f posFundo = pGrafico->getCamera().getCenter();
                    sf::Vector2f tamJanela = pGrafico->getTamJanela();
                    posFundo.x += (tamJanela.x / 2.0f - 20.0f);
                    posFundo.y += (-tamJanela.y / 2.0f + 20.0f);
                    for(int i = 0; i < vectorChaves.size(); i++){
                        Item::Chave* chave = vectorChaves[i];
                        chave->setPos(sf::Vector2f(posFundo.x - (chave->getTam().x + 15.0f) * (i + 1), posFundo.y));
                    }
                }

                void Jogador::atualizarAnimacao(){
                    if(morrendo){
                        animacao.atualizar(paraEsquerda, "MORRE");
                        tempoMorrer += pGrafico->getTempo();
                        if(tempoMorrer > tempoAnimacaoMorrer){
                            podeRemover = true;
                            tempoMorrer = 0.0f;
                        }
                    } else if(!noChao && velFinal.y > 0.0f){
                        animacao.atualizar(paraEsquerda, "CAI");
                    } else if(!noChao){
                        animacao.atualizar(paraEsquerda, "PULA");
                    } else if(levandoDano){
                        animacao.atualizar(paraEsquerda, "TOMADANO");
                    } else if(atacando){
                        animacao.atualizar(paraEsquerda, "ATACA");
                    } else if(andando){
                        animacao.atualizar(paraEsquerda, "ANDA");
                    } else {
                        animacao.atualizar(paraEsquerda, "PARADO");
                    }
                }

                void Jogador::inicializarNivel(){
                    textoNivel.setTamFonte(20);
                    textoNivel.setString("Lv." + std::to_string(nivel.getNivel()));
                    textoNivel.setTamanhoBorda(2);
                    nivel.setForca(FORCA_JOGADOR);
                    nivel.setDefesa(DEFESA_JOGADOR);
                    nivel.setVitalidade(VITALIDADE_JOGADOR);
                }
                
                void Jogador::atualizarNivel(){
                    sf::Vector2f posBarra = tuboBarraVida.getPosition();
                    textoNivel.setPos(sf::Vector2f(posBarra.x + 5.0f, posBarra.y - textoNivel.getTam().y - 12.0f));
                }

                void Jogador::colisao(Entidade* outraEntidade, sf::Vector2f ds){
                    switch(outraEntidade->getID()){
                        case(IDs::IDs::plataforma):
                        {
                            
                        }
                            break;
                        case(IDs::IDs::espada_inimigo):
                        {
                            //std::cout << "Tomar dano do inimigo" << std::endl;
                            Item::Arma* arma = dynamic_cast<Item::Arma*>(outraEntidade);
                            tomarDano(arma->getDano());
                        }
                            break;
                        case(IDs::IDs::esqueleto):
                        {
                            //empura inimigo
                            sf::Vector2f posInimigo = outraEntidade->getPos();
                            Inimigo::Inimigo* inimigo = dynamic_cast<Inimigo::Inimigo*>(outraEntidade);
                            if(pos.x < posInimigo.x){
                                ds.x *= -1;
                            }
                            //bate no jogador
                            inimigo->parar();
                            inimigo->atacar(true);
                        }
                            break;
                        case (IDs::IDs::vida):
                        {
                            Item::Vida* vida = dynamic_cast<Item::Vida*>(outraEntidade);
                            setVida(vida->getVida());
                            vida->remover();
                        }
                            break;
                        case(IDs::IDs::projetil_inimigo):
                        {
                            Item::Projetil* projetil = dynamic_cast<Item::Projetil*>(outraEntidade);
                            tomarDano(projetil->getDano());
                            projetil->setColidiu(true);
                        }
                            break;
                        case(IDs::IDs::moeda_amarela):
                        {
                            Item::Moeda* moeda = dynamic_cast<Item::Moeda*>(outraEntidade);
                            addPontuacao(moeda->getPontos());
                            moeda->remover();
                        }
                            break;
                        case(IDs::IDs::moeda_cinza):
                        {
                            Item::Moeda* moeda = dynamic_cast<Item::Moeda*>(outraEntidade);
                            addPontuacao(moeda->getPontos());
                            moeda->remover();
                        }
                            break;
                        case(IDs::IDs::porta):
                        {
                            Obstaculo::Porta* porta = dynamic_cast<Obstaculo::Porta*>(outraEntidade);
                            porta->colidindoJogador(this);
                        }
                            break;
                        case(IDs::IDs::chave):
                        {
                            Item::Chave* chave = dynamic_cast<Item::Chave*>(outraEntidade);
                            if(!chave->getColetou()){
                                addChave(chave);
                            }
                            colidindoPorta = true;
                        }
                            break;
                        case (IDs::IDs::espinho):
                        {
                            Obstaculo::Espinho* espinho = dynamic_cast<Obstaculo::Espinho*>(outraEntidade);
                            tomarDano(espinho->getDano());
                            if(!morrendo){
                                velFinal.y = -sqrt(2.0f * GRAVIDADE * TAMANHO_PULO);
                            }
                        }
                            break;

                    }   
                }

                void Jogador::pular(){
                    if(noChao){
                        velFinal.y = -sqrt(2.0f * GRAVIDADE * TAMANHO_PULO);
                        noChao = false;
                        atacando = false;
                    }
                }

                const bool Jogador::getNoChao() const {
                    return noChao;
                }

                const bool Jogador::getAndando() const{
                    return andando;
                }

                void Jogador::setColidindoPorta(const bool colidindoPorta){
                    this->colidindoPorta = colidindoPorta;
                }
                
                const bool Jogador::getColidindoPorta() const{
                    return colidindoPorta;
                }

                void Jogador::setAbrirPorta(const bool abrirPorta){
                    this->abrirPorta = abrirPorta;
                }
                
                const bool Jogador::getAbrirPorta() const{
                    return abrirPorta;
                }

                void Jogador::podePular(){
                    noChao = true;
                }

                void Jogador::mudarEstadoObservador(){
                    observadorJogador->mudarEstadoAtivar();
                }

                void Jogador::addChave(Item::Chave* chave){
                    vectorChaves.push_back(chave);
                    chave->setTam(sf::Vector2f(40.0f, 40.0f));
                    chave->setColetou(true);
                }

                void Jogador::removerChave(Item::Chave* chave){
                    for(int i = 0; i < vectorChaves.size(); i++){
                        Item::Chave* chaveAux = vectorChaves[i];
                        if(chaveAux == chave){
                            vectorChaves.erase(vectorChaves.begin() + i);
                            return;
                        }
                    }
                }

                std::vector<Item::Chave*> Jogador::getChaves(){
                    return vectorChaves;
                }

                void Jogador::addPontuacao(const unsigned int pontos){
                    this->pontos += pontos;
                    observadorJogador->atualizarPontuacao(this->pontos);
                }

                void Jogador::addExperiencia(const float experiencia){
                    nivel.addExp(experiencia);
                    textoNivel.setString("Lv." + std::to_string(nivel.getNivel()));
                    inicializarExp();      
                }

                void Jogador::setVida(const float vida){
                    this->vida += vida;
                    if(this->vida > 100.0f){
                        this->vida = 100.0f;
                    }
                }

                const std::string Jogador::salvar(){
                    std::string linha = salvarPersonagem();
                    linha += std::to_string(noChao) + ' ';
                    linha += std::to_string(colidindoPorta) + ' ';
                    linha += std::to_string(abrirPorta) + ' ';
                    linha += animacao.getImgAtual() + ' ';
                    linha += std::to_string(animacao.getQuadroAtual()) + ' ';
                    linha += std::to_string(animacao.getTempoTotal()) + ' ';
                    linha += std::to_string(pontos);
                    return linha;
                }

                void Jogador::desenhar(){
                    pGrafico->desenhaElemento(corpo);
                    pGrafico->desenhaElemento(tuboBarraVida);
                    pGrafico->desenhaElemento(barraVida);
                    pGrafico->desenhaElemento(textoNivel.getTexto());
                    pGrafico->desenhaElemento(tuboBarraXP);
                    pGrafico->desenhaElemento(barraXP);
                    pGrafico->desenhaElemento(textoExp.getTexto());
                }

                void Jogador::atualizar(){
                    /**
                        * @ return void 
                        * 
                        * Faz o movimeto do jogador e atualiza animação
                    */

                    //arrumar...
                    //sf::Vector2f posCamera(pos.x , 300.0f);
                    //sf::Vector2f tamJanela = pGrafico->getTamJanela();
                    //if(pos.x < -550.0f + tamJanela.x / 2.0f){
                    //    posCamera.x = -550.0f + tamJanela.x / 2.0f;
                    //} else if(pos.x > 11 * 500.0f + 50.0f - tamJanela.x / 2.0f){
                    //    posCamera.x = 11 * 500.0f + 50.0f - tamJanela.x / 2.0f;
                    //}
                    //pGrafico->atualizarCamera(posCamera);

                    atualizarPosicao();

                    if(atacando){
                        sf::Vector2f tamEspada = arma->getTam();
                        const float posY = pos.y;
                        sf::Vector2f posEspada = (paraEsquerda ? sf::Vector2f(pos.x - tamEspada.x, pos.y) : sf::Vector2f(pos.x + tam.x, pos.y));
                        arma->setPos(posEspada);
                    } else {
                        arma->setPos(sf::Vector2f(-1000.0f, -1000.0f));
                    }

                    atualizarAnimacao();

                    atualizarBarraVida();

                    atualizarBarraXP();

                    atualizarNivel();

                    atualizarExp();

                    atualizarChaves();

                    colidindoPorta = false;
                }

            }

        }

    }

}