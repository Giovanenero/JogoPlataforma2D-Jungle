#include "../../../include/Entidade/Personagem/Nivel.hpp"

namespace Jungle {

    namespace Entidade {

        namespace Personagem {

            Nivel::Nivel():
                nivel(1), experiencia(0.0f), proximoNivel(100.0f), forca(20.0f),
                defesa(20.0f), vitalidade(20.0f)
            {
                
            }

            Nivel::Nivel(const float forca, const float defesa, const float vitalidade):
                forca(forca), defesa(defesa), vitalidade(vitalidade), nivel(1), experiencia(0.0f),
                proximoNivel(100)
            {

            }
            
            Nivel::~Nivel(){

            }
            
            void Nivel::setNivel(const int nivel){
                if(nivel <= 0){
                    std::cout << "Nivel::nivel eh menor que 0" << std::endl;
                    exit(1);
                }
                this->nivel = nivel;
                proximoNivel = 100.0f * pow(1.5f, nivel - 1);
                this->forca = forca * pow(1.5f, nivel - 1);
                this->defesa = defesa * pow(1.3f, nivel - 1);
                this->vitalidade = vitalidade * pow(1.1f, nivel - 1);
            }
            
            const int Nivel::getNivel() const{
                return nivel;
            }
            
            void Nivel::addExp(const float experiencia){
                this->experiencia += experiencia;
                while(this->experiencia >= proximoNivel){
                    const float restoExp = this->experiencia - proximoNivel;
                    setNivel(nivel + 1);
                    this->experiencia = restoExp;
                }
            }

            const float Nivel::getExpProxNivel() const{
                return proximoNivel;
            }
            
            const float Nivel::getExp() const{
                return experiencia;
            }
            
            const float Nivel::getForca() const{
                return forca;
            }
            
            const float Nivel::getDefesa() const{
                return defesa;
            }
            
            const float Nivel::getVitalidade() const{
                return vitalidade;
            }

            void Nivel::setForca(const float forca){
                this->forca = forca;
                this->forca *= pow(1.5f, nivel -1);
            }
            
            void Nivel::setDefesa(const float defesa){
                this->defesa = defesa;
                this->defesa *= pow(1.3f, nivel - 1);
            }
            
            void Nivel::setVitalidade(const float vitalidade){
                this->vitalidade = vitalidade;
                this->vitalidade *= pow(1.1f, nivel - 1);
            }

        }

    }

}