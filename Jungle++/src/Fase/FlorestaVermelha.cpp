#include "..\..\include\Fase\FlorestaVermelha.hpp"

Jungle::Fase::FlorestaVermelha::FlorestaVermelha():
    Fase(IDs::IDs::fase_florestaVermelha, IDs::IDs::fundo_florestaVermelha)
{

}

Jungle::Fase::FlorestaVermelha::~FlorestaVermelha(){

}

void Jungle::Fase::FlorestaVermelha::criarFundo(){
    fundo.addCamada("Jungle++/img/Fase/FLorestaVermelha/camada1.png", 0.0f);
    fundo.addCamada("Jungle++/img/Fase/FLorestaVermelha/camada2.png", 0.1f);
    fundo.addCamada("Jungle++/img/Fase/FLorestaVermelha/camada3.png", 0.3f);
    fundo.addCamada("Jungle++/img/Fase/FLorestaVermelha/camada4.png", 0.5f);
}

void Jungle::Fase::FlorestaVermelha::criarMapa(){
    std::ifstream arquivo;
    std::string linha;
    arquivo.open("Jungle++/arquivo/Mapa_FlorestaVermelha.txt");
    if(!arquivo.is_open()){
        std::cout << "Jungle::Fase::FlorestaVermelha::nao foi possivel abrir o arquivo" << std::endl;
        exit(1);
    }
    int j = 0;
    while(std::getline(arquivo, linha)){
        for(int i = 0; i < linha.size(); i++){
            if(linha[i] != ' '){
                criarEntidade(linha[i], sf::Vector2i(i, j));
            }
        }
        j++;
    }
    arquivo.close();
}