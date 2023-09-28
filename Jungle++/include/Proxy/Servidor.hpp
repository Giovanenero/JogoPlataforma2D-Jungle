#pragma once

#include <iostream>
#include <winsock2.h>
#include <windows.h>
#include <process.h>

class Servidor {
    private:
        sockaddr_in meu_end;
        long int cont_msg;
        SOCKET meu_Sockt;
        bool tem_Canal, tem_Sockt, tem_Conexao;
        int max_conexao, bytes_recebidos; // bytes recebidos, armazena o valor de retorno de recv
        char buffer[500];
        
    public:
        Servidor(const char* ip = "127.0.0.1", unsigned short porta = 3077, int max = 1):
            cont_msg(0)
        {
            WSADATA tst;
            if ( WSAStartup ( MAKEWORD ( 2 , 2 ) , &tst ) ) // teste para ver se o computador suporta e versão de winsocks utilizada
            { 
                std::cout << " O computador nao possui a versao 2.0 do Winsocks. " ;
                std::cout << " Nao sera possivel criar o servidor. " << std::endl;
            } else {
                max_conexao = max;
                // Atribui os valores passados pelo construtor ao ip e ao endereço de porta
                meu_end.sin_family = AF_INET;
                meu_end.sin_addr.s_addr = inet_addr ( ip ); // AdressFamily-Internet será usado como padrão nesse programa.
                meu_end.sin_port = htons ( porta );
                meu_Sockt = socket ( AF_INET, SOCK_STREAM, IPPROTO_TCP ); // cria o socket;
                if ( meu_Sockt == SOCKET_ERROR ) {
                    std::cout << " Erro na criacao do socket." << std::endl;
                    tem_Sockt = false;
                }
                else {
                    tem_Sockt = true;
                }
            }
            
            conectaSockt();
            aceitaSockt();

        }

        ~Servidor(){
            closesocket ( meu_Sockt );
        }

        void conectaSockt(){
            int result = -1;
            result = bind (meu_Sockt, reinterpret_cast < SOCKADDR* > ( &meu_end ), sizeof(meu_end));
            if (result == -1) {
                std::cout << "Bind nao pode ser efetuado." << std::endl ;
                tem_Canal = false ;
            }
            else {
                tem_Canal = true;
            }
        }

        void aceitaSockt(){
            SOCKET outroSockt;
            // listen define o estado da porta aberta pelo servidor.
            // a porta fica esperando ("escutando") pedidos de conexões
            if (listen(meu_Sockt, max_conexao) == -1 ){
                std::cout << "Erro ao entrar em modo de espera de conexoes" << std::endl;
                tem_Conexao = false;
                return;
            }
            std::cout << "Aguardando conexoes..." << std::endl;
            // loop infinito... 
            do {
                // função que aceita um pedido de conexão feito com "connect()" pelo cliente
                outroSockt = accept( meu_Sockt, NULL, NULL );
            } while (outroSockt == SOCKET_ERROR);
            
            meu_Sockt = outroSockt;
            std::cout << "Alguem conectou!" << std::endl;
            // envia uma mensagem confirmando a conexão para o cliente
            send(meu_Sockt, "Ola. Voce esta conectado ao servidor.", 38, 0 );

            int sair = 0;
            while(!sair){
                bytes_recebidos = recv(meu_Sockt, buffer, 500, 0);
                if(strlen(buffer) > 0){
                    std::cout << buffer << std::endl;
                    strcpy(buffer, "");
                    sair = !sair;
                }
            }

            std::cout << "Eu sou o servidor, agr eu quero enviar uma mensagem para o cliente... digite uma mensagem: ";
            fflush(stdin);
            gets(buffer);
            send(meu_Sockt, buffer, 38, 0 );
        }
};