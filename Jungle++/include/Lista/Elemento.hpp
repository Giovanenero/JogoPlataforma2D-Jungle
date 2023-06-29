#pragma once

#include <iostream>

namespace Jungle {

    namespace Lista {

        template<class TE>
        class Elemento {
        private:
            Elemento<TE>* prox;
            TE* elemento;
        public:
            Elemento();
            ~Elemento();
            void setProx(Elemento<TE>* prox);
            void setElemento(TE* elemento);
            Elemento<TE>* getProx();
            TE* getElemento();
        };
        
        template<class TE>
        Elemento<TE>::Elemento():
            prox(nullptr), elemento(nullptr)
        {

        }
        template<class TE>
        Elemento<TE>::~Elemento(){
            
        }

        template<class TE>
        void Elemento<TE>::setProx(Elemento<TE>* prox){
            this->prox = prox;
        }

        template<class TE>
        void Elemento<TE>::setElemento(TE* elemento){
            this->elemento = elemento;
        }

        template<class TE>
        Elemento<TE>* Elemento<TE>::getProx(){
            return prox;
        }

        template<class TE>
        TE* Elemento<TE>::getElemento(){
            return elemento;
        }

    }

}