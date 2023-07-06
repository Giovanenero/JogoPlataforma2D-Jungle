#include "../../../include/Entidade/Obstaculo/Obstaculo.hpp"

Jungle::Entidade::Obstaculo::Obstaculo::Obstaculo(const sf::Vector2f pos, const sf::Vector2f tam, const IDs::IDs ID, const char* caminhoTextura):
    Entidade(tam, ID, pos)
{
    textura = pGrafico->carregarTextura(caminhoTextura);
    corpo.setTexture(&textura);
}

Jungle::Entidade::Obstaculo::Obstaculo::~Obstaculo(){

}

void Jungle::Entidade::Obstaculo::Obstaculo::atualizar(){
    desenhar();
}

void Jungle::Entidade::Obstaculo::Obstaculo::colisaoObstaculo(sf::Vector2f ds, Personagem::Personagem* pPersonagem){
    sf::Vector2f posOutro = pPersonagem->getPos();
    sf::Vector2f tamOutro = pPersonagem->getTam();
    sf::Vector2f velFinal = pPersonagem->getVelFinal();
    if(ds.x < 0.0f && ds.y < 0.0f){ //houve colisao
        if(ds.x > ds.y){
            if(posOutro.x < pos.x){ //colisão em x
                posOutro.x += ds.x;
            } else {
                posOutro.x -= ds.x;
            }
            velFinal.x = 0.0f;
        } else {
            if(posOutro.y < pos.y){ //colisão em y
                posOutro.y += ds.y;
                if(pPersonagem->getID() == IDs::IDs::jogador){
                    Personagem::Jogador::Jogador* pJogador = static_cast<Personagem::Jogador::Jogador*>(pPersonagem);
                    pJogador->podePular();
                }
            } else {
                posOutro.y -= ds.y;
            }
            velFinal.y = 0.0f;
        }
    }
    pPersonagem->setPos(posOutro);
    pPersonagem->setVelFinal(velFinal);
}