#pragma once 

namespace IDs {

    enum class IDs {
        vazio = 0,
        jogador, //1
        espada_jogador, //2
        espada_inimigo, //3
        projetil_inimigo, //4
        esqueleto, //5
        minotauro, //6
        alma, //7
        plataforma, //8
        caixa, //9
        moeda_amarela, //10
        moeda_cinza, //11
        vida, //12
        fundo_florestaNegra, //13
        fundo_florestaBranca, //14
        fase_florestaBranca, //15
        fundo_florestaVermelha, //16
        fase_florestaVermelha, //17
        jogar_florestaVermelha, //18
        jogar_florestaBranca, //19
        botao_novoJogo,
        botao_carregar_jogo,
        botao_colocacao,
        botao_opcao,
        botao_sair,
        botao_voltar,
        botao_volume_geral,
        botao_volume_jogo,
        botao_volume_menu,
        botao_esquerda,
        botao_direita,
        botao_salvar_colocacao,
        botao_salvar_jogada,
        botao_salvar,
        botao_carregar,
        botao_remover,
        menu_principal,
        menu_pausa,
        menu_salvar_jogada,
        menu_opcao,
        menu_carregar_jogo,
        menu_colocacao,
        menu_game_over,
        estado_menu_principal,
        estado_menu_pausa,
        estado_menu_opcaoPrincipal,
        estado_menu_carregar_jogo,
        estado_menu_colocacao,
        estado_menu_game_over,
        estado_menu_salvar_jogada,
    };

}