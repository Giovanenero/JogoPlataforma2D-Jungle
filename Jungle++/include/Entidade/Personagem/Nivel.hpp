#pragma once

#include <iostream>
#include <math.h>
#include <iomanip>

namespace Jungle {

    namespace Entidade {

        namespace Personagem {

            class Nivel {
                private:
                    int nivel;
                    float experiencia;
                    float proximoNivel;
                    float forca;
                    float defesa;
                    float vitalidade;
                public:
                    Nivel();
                    Nivel(const float forca, const float defesa, const float vitalidade);
                    ~Nivel();
                    void setNivel(const int nivel);
                    const int getNivel() const;
                    void addExp(const float experiencia);
                    const float getExp() const;
                    const float getExpProxNivel() const;
                    const float getForca() const;
                    const float getDefesa() const;
                    const float getVitalidade() const;
                    void setForca(const float forca);
                    void setDefesa(const float defesa);
                    void setVitalidade(const float vitalidade);
            };

        }

    }

}