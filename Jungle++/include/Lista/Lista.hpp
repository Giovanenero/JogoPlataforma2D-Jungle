#pragma once

#include "Elemento.hpp"

namespace Jungle {

    namespace Lista {

        template<class TL>
        class Lista {
        private:
            Elemento<TL>* pInicio;
            Elemento<TL>* pUltimo;
            unsigned int tam;
        public:
            Lista();
            ~Lista();
            void addElemento(TL* elemento);
            void addElemento(TL* elemento, int pos);
            void removerElemento(TL* elemento, const bool deletar);
            void removerElemento(int pos, const bool deletar);
            int getTam();
            void limparLista();
            TL* operator[](int pos);
        };

        template<class TL>
        Lista<TL>::Lista():
            pInicio(nullptr), pUltimo(nullptr), tam(0)
        {

        }

        template<class TL>
        Lista<TL>::~Lista(){
            //limparLista();
        }

        template<class TL>
        void Lista<TL>::addElemento(TL* elemento){
            if(elemento == nullptr){
                std::cout << "ERROR::Lista elemento eh nullptr" << std::endl;
                exit(1);
            }
            Elemento<TL>* novoElemento = new Elemento<TL>();
            if(novoElemento == nullptr){
                std::cout << "ERROR::Lista aux eh nullptr" << std::endl;
                exit(1);
            }
            novoElemento->setElemento(elemento);
            if(pInicio == nullptr){
                pInicio = novoElemento;
                pUltimo = novoElemento;
            } else {
                pUltimo->setProx(novoElemento);
                pUltimo = novoElemento;
            }
            tam++;
        }

        template<class TL>
        void Lista<TL>::addElemento(TL* elemento, int pos){
            if(pos > tam || pos < 0){
                std::cout << "ERRO::Lista::posicao nao eh compativel com o tamanho da lista" << std::endl;
                exit(1);
            }
            if(elemento == nullptr){
                std::cout << "ERROR::Lista elemento eh nullptr" << std::endl;
                exit(1);
            }
            Elemento<TL>* novoElemento = new Elemento<TL>();
            if(novoElemento == nullptr){
                std::cout << "ERROR::Lista novoElemento eh nullptr" << std::endl;
                exit(1);
            }
            novoElemento->setElemento(elemento);
            if(pInicio == nullptr){
                pInicio = novoElemento;
                pUltimo = novoElemento;
            } else {
                Elemento<TL>* aux = pInicio;
                Elemento<TL>* aux2 = nullptr;
                for(int i = 0; i < pos; i++){
                    aux2 = aux;
                    aux = aux->getProx();
                }
                if(aux2 == nullptr){
                    novoElemento->setProx(aux);
                    pInicio = novoElemento;
                } else {
                    aux2->setProx(novoElemento);
                    novoElemento->setProx(aux);
                }
            }
            tam++;
        }

        template<class TL>
        void Lista<TL>::removerElemento(TL* elemento, const bool deletar){
            if(elemento == nullptr){
                std::cout << "ERROR::Lista elemento eh nullptr" << std::endl;
                exit(1);
            }
            Elemento<TL>* aux = pInicio;
            Elemento<TL>* aux2 = nullptr;
            while (aux != nullptr && aux->getElemento() != elemento){
                aux2 = aux;
                aux = aux->getProx();
            }
            if(aux->getElemento() == elemento){
                if(aux == pInicio){
                    pInicio = aux->getProx();
                } else if(aux == pUltimo){
                    pUltimo = aux2;
                } else {
                    aux2->setProx(aux->getProx());
                }
                if(deletar){
                    delete(aux);
                    aux = nullptr;
                    aux2 = nullptr;
                }
                tam--;
            }
            
        }

        template<class TL>
        void Lista<TL>::removerElemento(int pos, const bool deletar){
            TL* elemento = operator[](pos);
            return removerElemento(elemento, deletar);
        }

        template<class TL>
        int Lista<TL>::getTam(){
            return (int)tam;
        }

        template<class TL>
        TL* Lista<TL>::operator[](int pos){
            if(pos >= (int)tam || pos < 0){
                std::cout << "ERROR::Lista pos eh maior que o tamanho da lista" << std::endl;
                exit(1);
            }
            Elemento<TL>* aux = pInicio;
            for(int i = 0; i < pos; i++){
                aux = aux->getProx();
            }
            return aux->getElemento();
        }

        template<class TL>
        void Lista<TL>::limparLista(){
            if(pInicio != nullptr){
                Elemento<TL>* aux = pInicio;
                Elemento<TL>* aux2 = nullptr;
                int i = 0;
                while(aux != nullptr && i < tam){
                    TL* elemento = aux->getElemento();
                    if(elemento != nullptr){
                        delete(elemento);
                        elemento = nullptr;
                    }
                    aux2 = aux->getProx();
                    delete(aux);
                    aux = nullptr;
                    aux = aux2;
                    i++;
                }
            }
            pInicio = nullptr;
            pUltimo = nullptr;
            tam = 0;
        }

    }

}