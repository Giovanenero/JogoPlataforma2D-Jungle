#pragma once

#include <winsock2.h>
#include <windows.h>
#include <iostream>

class Cliente
{
    private:
        sockaddr_in serv_end; 
        sockaddr_in meu_end; // OBS: na verdade, nao precisa ser definido o endereço do cliente
        SOCKET meu_sockt;
        int bytes_recebidos; // bytes recebidos, armazena o valor de retorno de recv
    
    public:
        Cliente(){
            WSADATA tst;
            if ( WSAStartup ( MAKEWORD ( 2 , 2 ) , &tst ) ) // teste para ver se o computador suporta e versão de winsocks utilizada
            { // não deve dar problemas, já que todos os windows superiores ao 95 a suportam.
                std::cout << "O computador nao possui a versao 2.0 do Winsocks.";
                std::cout << " Nao sera possivel criar o servidor." << std::endl;
                return;
            }

            meu_sockt = socket ( AF_INET, SOCK_STREAM, IPPROTO_TCP ); // cria o socket.
            if ( meu_sockt == SOCKET_ERROR )
            {
                std::cout << "Nao foi possivel criar o socket." << std::endl;
            }
            // define o endereço do cliente.
            // existem funções que recuperam os ips reais de uma máquina nas respectivas redes das quais participa
            meu_end.sin_family = AF_INET;
            meu_end.sin_port = htons ( 50001 );
            meu_end.sin_addr.s_addr = inet_addr ( "127.0.0.1" );

            conectar();
        }

        ~Cliente(){
            closesocket(meu_sockt);
        }

        void conectar(){ // A função que não recebe parâmetros pergunta ao usuario a porta e o ip do server
            char msg[38];
            char ip[16];
            std::cout << "Digite o ip do servidor ao qual quer se conectar." << std::endl;
            std::cout << "obs: 127.0.0.1 para o local host" << std::endl;
            fflush (stdin);
            gets(ip);
            
            conectar(ip, 3077);
        }

        void conectar(const char *ip, unsigned short porta){
            char msg [38] ;
            serv_end.sin_family = AF_INET; // define o endereço do servidor.
            serv_end.sin_addr.s_addr = inet_addr ( ip );
            serv_end.sin_port = htons ( porta );
            int result = 0;
            result = connect ( meu_sockt, reinterpret_cast < SOCKADDR * > ( &serv_end ), sizeof ( serv_end ) );
            if ( result == -1 ){
                std::cout << "Nao foi possivel conectar ao servidor, tente de novo." << std::endl;
                return;
            }
            std::cout << "Conexao estabelecida." << std::endl;
            while (1){
                result = recv ( meu_sockt, msg, 38, 0 );
                if(result != -1){
                    std::cout << msg << std::endl << std::endl;
                    break;
                }
            }

            char teste[500];
            std::cout << "Digite a msg que deseja enviar: " << std::endl;
            fflush (stdin);
            gets (teste);

            send(meu_sockt, teste, strlen(teste) + 1, 0);

            bool sair = false;
            while(!sair){
                bytes_recebidos = recv(meu_sockt, teste, 500, 0);
                if(strlen(teste) > 0){
                    std::cout << teste << std::endl;
                    strcpy(teste, "");
                    sair = !sair;
                }
            }
            //rotinaPrincipal();
        }
};