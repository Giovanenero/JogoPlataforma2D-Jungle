#include "Observador.hpp"
#include "..\Menu\MenuPausa.hpp"

namespace Jungle {

    namespace Observador {

        class ObservadorMenuPausa : public Observador {
        private:
            Menu::MenuPausa* menuPausa;
        public:
            ObservadorMenuPausa(Menu::MenuPausa* menuPausa);
            ~ObservadorMenuPausa();
            void teclaPressionada(const sf::Keyboard::Key tecla);
            void teclaSolta(const sf::Keyboard::Key tecla);
        };

    }

}