#include "../../include/Observador/ObservadorMenu.hpp"
#include "../../include/Gerenciador/GerenciadorEstado.hpp"
#include "../../include/Menu/Card.hpp"

namespace Jungle {

    namespace Observador {

        ObservadorMenu::ObservadorMenu(Menu::Menu* menu):
            Observador(), menu(menu)
        {
            
        }

        ObservadorMenu::~ObservadorMenu(){
            
        }
        
        void ObservadorMenu::teclaPressionada(const sf::Keyboard::Key tecla){
            if(tecladoEspecial[tecla] == "Enter"){
                IDs::IDs IDEstadoAtual = pGEstado->getEstadoAtual()->getID();
                switch (menu->getIDBotaoSelecionado())
                {
                    case (IDs::IDs::botao_sair):
                    {  
                        pGEstado->removerEstado(2);
                    }
                        break;
                    case (IDs::IDs::botao_voltar):
                    {
                        pGEstado->removerEstado();
                    }
                        break;
                    case (IDs::IDs::botao_novoJogo):
                    {
                        pGEstado->addEstado(IDs::IDs::jogar_florestaBranca);
                        Estado::EstadoJogar* estadoJogar = dynamic_cast<Estado::EstadoJogar*>(pGEstado->getEstadoAtual());
                        estadoJogar->criarFase();
                    }
                        break;
                    case (IDs::IDs::botao_opcao):
                    {
                        if(IDEstadoAtual == IDs::IDs::estado_menu_principal){
                            pGEstado->addEstado(IDs::IDs::estado_menu_opcaoPrincipal);
                        } else {
                            //só pode ser o menu_pausar
                        }
                    }
                        break;
                    case (IDs::IDs::botao_salvar_colocacao):
                    {
                        Estado::Estado* estado = pGEstado->getEstadoAtual();
                        if(estado->getID() == IDs::IDs::estado_menu_game_over){
                            Estado::EstadoMenu* estadoMenuFase = dynamic_cast<Estado::EstadoMenu*>(estado);
                            Menu::MenuGameOver* menuGameOver = dynamic_cast<Menu::MenuGameOver*>(estadoMenuFase->getMenu());
                            menuGameOver->salvarColocacao();
                        }
                        pGEstado->removerEstado(2);
                    }
                        break;
                    case (IDs::IDs::botao_colocacao):
                    {
                        //adiciona 2 vezes por conta do botao_voltar;
                        pGEstado->addEstado(IDs::IDs::estado_menu_colocacao);
                        //arrumar o bug do evento
                        pGEstado->addEstado(IDs::IDs::estado_menu_colocacao);
                    }
                        break;
                    case(IDs::IDs::botao_salvar_jogada):
                    {
                        pGEstado->addEstado(IDs::IDs::estado_menu_salvar_jogada);
                        //arrumar o bug do evento
                        pGEstado->addEstado(IDs::IDs::estado_menu_colocacao);
                    }
                        break;
                    case(IDs::IDs::botao_salvar):
                    {
                        Estado::Estado* estado = pGEstado->getEstadoAtual();
                        if(estado->getID() == IDs::IDs::estado_menu_salvar_jogada){
                            Estado::EstadoMenu* estadoMenu = dynamic_cast<Estado::EstadoMenu*>(estado);
                            Menu::MenuSalvarJogada* menuSalvarJogada = dynamic_cast<Menu::MenuSalvarJogada*>(estadoMenu->getMenu());
                            menuSalvarJogada->salvarJogada();
                            pGEstado->removerEstado();
                        }
                    }
                        break;
                    case (IDs::IDs::botao_carregar_jogo):
                    {
                        pGEstado->addEstado(IDs::IDs::estado_menu_carregar_jogo);
                        //arrumar bug do evento
                        pGEstado->addEstado(IDs::IDs::estado_menu_colocacao);
                    }
                        break;
                    case (IDs::IDs::botao_carregar):
                    {
                        Estado::Estado* estado = pGEstado->getEstadoAtual();
                        if(estado->getID() == IDs::IDs::estado_menu_carregar_jogo){
                            Estado::EstadoMenu* estadoMenu = dynamic_cast<Estado::EstadoMenu*>(estado);
                            Menu::MenuCarregarJogo* menuCarregarJogo = dynamic_cast<Menu::MenuCarregarJogo*>(estadoMenu->getMenu());
                            Menu::Card* card = menuCarregarJogo->getCardSelecionado();
                            if(card->getExiste()){
                                pGEstado->removerEstado();
                                const  std::string caminhoArquivoEntidades = card->getCaminhoArquivoEntidades();
                                const std::string caminhoArquivoFase = card->getCaminhoArquivoFase();
                                Gerenciador::GerenciadorArquivo GArquivo;
                                std::vector<std::string> vectorInfoFase = GArquivo.lerArquivo(caminhoArquivoFase.c_str());
                                int id = std::stoi(vectorInfoFase[0]);
                                if(id >= 53 && id <= 55){
                                    pGEstado->addEstado(IDs::IDs::jogar_florestaBranca);
                                } else {
                                    std::cout << "ObservadorMenu::nao foi possivel criar uma fase" << std::endl;
                                    exit(1);
                                }
                                Estado::EstadoJogar* estadoJogar = dynamic_cast<Estado::EstadoJogar*>(pGEstado->getEstadoAtual());
                                estadoJogar->criarFase(caminhoArquivoEntidades, vectorInfoFase);
                            }
                        }
                    }
                        break;
                    case(IDs::IDs::botao_remover):
                    {
                        Estado::Estado* estado = pGEstado->getEstadoAtual();
                        if(estado->getID() == IDs::IDs::estado_menu_carregar_jogo){
                            Estado::EstadoMenu* estadoMenu = dynamic_cast<Estado::EstadoMenu*>(estado);
                            Menu::MenuCarregarJogo* menuCarregarJogo = dynamic_cast<Menu::MenuCarregarJogo*>(estadoMenu->getMenu());
                            menuCarregarJogo->deletarArquivos();
                        }
                    }
                        break;
                }
            } else if(tecladoEspecial[tecla] == "Left"){
                menu->selecionaEsquerda();
            } else if(tecladoEspecial[tecla] == "Right"){
                menu->selecionaDireita();
            }
        }
        
        void ObservadorMenu::teclaSolta(const sf::Keyboard::Key tecla){
            if(tecladoEspecial[tecla] == "Up"){
                menu->selecionaCima();
            } else if(tecladoEspecial[tecla] == "Down"){
                menu->selecionaBaixo();
            } else if(menu->getID() == IDs::IDs::menu_game_over){
                if(tecladoEspecial[tecla] == "BackSpace"){
                    Menu::MenuGameOver* menuGameOver = dynamic_cast<Menu::MenuGameOver*>(menu);
                    menuGameOver->removerCaracter();
                } else {
                    for(int i = 97; i < 123; i++){
                        if(teclado[tecla] == i){
                            Menu::MenuGameOver* menuGameOver = dynamic_cast<Menu::MenuGameOver*>(menu);
                            menuGameOver->addCaracter(teclado[tecla]);
                            break;
                        }
                    }
                    for(int i = 48; i < 58; i++){
                        if(teclado[tecla] == i){
                            Menu::MenuGameOver* menuGameOver = dynamic_cast<Menu::MenuGameOver*>(menu);
                            menuGameOver->addCaracter(teclado[tecla]);
                            break;
                        }
                    }
                }
            }
        }

        void ObservadorMenu::moveMouse(const sf::Vector2f posMouse){
            menu->eventoMouse(posMouse);
        }

        void ObservadorMenu::botaoMouseSolta(const sf::Mouse::Button botaoMouse){
            if(menu->getMouseSelecionado()){
                switch (botaoMouse)
                {
                    case (sf::Mouse::Left):
                    {
                        switch (menu->getIDBotaoSelecionado())
                        {
                            case (IDs::IDs::botao_novoJogo):
                            {
                                pGEstado->addEstado(IDs::IDs::jogar_florestaBranca);
                                Estado::EstadoJogar* estadoJogar = dynamic_cast<Estado::EstadoJogar*>(pGEstado->getEstadoAtual());
                                estadoJogar->criarFase();
                            }
                                break;
                            case (IDs::IDs::botao_sair):
                            {
                                pGEstado->removerEstado(2);
                            }
                                break;
                            case (IDs::IDs::botao_opcao):
                            {
                                Estado::Estado* estado = pGEstado->getEstadoAtual();
                                if(estado->getID() == IDs::IDs::estado_menu_principal){
                                    pGEstado->addEstado(IDs::IDs::estado_menu_opcaoPrincipal);
                                } else {
                                    //só pode ser o menu_pausar
                                }
                            }
                                break;
                            case (IDs::IDs::botao_colocacao):
                            {
                                pGEstado->addEstado(IDs::IDs::estado_menu_colocacao);
                            }
                                break;
                            case (IDs::IDs::botao_voltar):
                            {
                                pGEstado->removerEstado();
                            }
                                break;
                            case (IDs::IDs::botao_salvar_colocacao):
                            {
                                Estado::Estado* estado = pGEstado->getEstadoAtual();
                                if(estado->getID() == IDs::IDs::estado_menu_game_over){
                                    Estado::EstadoMenu* estadoMenuFase = dynamic_cast<Estado::EstadoMenu*>(estado);
                                    Menu::MenuGameOver* menuGameOver = dynamic_cast<Menu::MenuGameOver*>(estadoMenuFase->getMenu());
                                    menuGameOver->salvarColocacao();
                                }
                                pGEstado->removerEstado(2);
                            }
                                break;
                            case (IDs::IDs::botao_salvar_jogada):
                            {
                                pGEstado->addEstado(IDs::IDs::estado_menu_salvar_jogada);
                            }
                                break;
                            case (IDs::IDs::botao_salvar):
                            {
                                Estado::Estado* estado = pGEstado->getEstadoAtual();
                                if(estado->getID() == IDs::IDs::estado_menu_salvar_jogada){
                                    Estado::EstadoMenu* estadoMenu = dynamic_cast<Estado::EstadoMenu*>(estado);
                                    Menu::MenuSalvarJogada* menuSalvarJogada = dynamic_cast<Menu::MenuSalvarJogada*>(estadoMenu->getMenu());
                                    menuSalvarJogada->salvarJogada();
                                    pGEstado->removerEstado();
                                }
                            }
                                break;
                            case (IDs::IDs::botao_carregar_jogo):
                            {
                                pGEstado->addEstado(IDs::IDs::estado_menu_carregar_jogo);
                            }
                                break;
                            case (IDs::IDs::botao_carregar):
                            {
                                Estado::Estado* estado = pGEstado->getEstadoAtual();
                                if(estado->getID() == IDs::IDs::estado_menu_carregar_jogo){
                                    Estado::EstadoMenu* estadoMenu = dynamic_cast<Estado::EstadoMenu*>(estado);
                                    Menu::MenuCarregarJogo* menuCarregarJogo = dynamic_cast<Menu::MenuCarregarJogo*>(estadoMenu->getMenu());
                                    Menu::Card* card = menuCarregarJogo->getCardSelecionado();
                                    if(card->getExiste()){
                                        pGEstado->removerEstado();
                                        const std::string caminhoArquivoEntidades = card->getCaminhoArquivoEntidades();
                                        const std::string caminhoArquivoFase = card->getCaminhoArquivoFase();
                                        Gerenciador::GerenciadorArquivo GArquivo;
                                        std::vector<std::string> vectorInfoFase = GArquivo.lerArquivo(caminhoArquivoFase.c_str());
                                        int id = std::stoi(vectorInfoFase[0]);
                                        //criar estado
                                        if(id >= 53 && id <= 55){
                                            pGEstado->addEstado(IDs::IDs::jogar_florestaBranca);
                                        } else {
                                            std::cout << "ObservadorMenu::nao foi possivel criar uma fase" << std::endl;
                                            exit(1);
                                        }
                                        Estado::EstadoJogar* estadoJogar = dynamic_cast<Estado::EstadoJogar*>(pGEstado->getEstadoAtual());
                                        estadoJogar->criarFase(caminhoArquivoEntidades, vectorInfoFase);
                                    }
                                }
                            }
                                break;
                            case(IDs::IDs::botao_remover):
                            {
                                Estado::Estado* estado = pGEstado->getEstadoAtual();
                                if(estado->getID() == IDs::IDs::estado_menu_carregar_jogo){
                                    Estado::EstadoMenu* estadoMenu = dynamic_cast<Estado::EstadoMenu*>(estado);
                                    Menu::MenuCarregarJogo* menuCarregarJogo = dynamic_cast<Menu::MenuCarregarJogo*>(estadoMenu->getMenu());
                                    menuCarregarJogo->deletarArquivos();
                                }
                            }
                                break;
                        }
                            break;
                    }
                }
            }
        }

    }

}