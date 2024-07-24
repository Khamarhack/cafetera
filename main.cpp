#include <iostream>

using namespace std;

/* Tipo de Dato Abstracto para las Cafeteras */
class Cafetera {
public:
    virtual void Capuchino() = 0;
    virtual void Tinto() = 0;
    virtual void Aromatica() = 0;
    virtual void CafeLeche() = 0;
    
};
/* Implementación del TAD para PHILIPS */
class PHILIPS : public Cafetera {
public:
    void Capuchino() override {
        cout << "PHILIPS haciendo un philipcapuchino" << endl;
    }
    void Tinto() override {
        cout << "PHILIPS haciendo philiptinto" << endl;
    }
    void Aromatica() override {
        cout << "PHILIPS haciendo philiparomatica" << endl;
    }
    void CafeLeche() override {
        cout << "PHILIPS haciendo philipcafé con leche" << endl;
    }
};

/* Implementación del TAD para OSTER */
class Oster : public Cafetera {
public:
    void Capuchino() override {
        cout << "Oster haciendo el mejor capuchino" << endl;
    }
    void Tinto() override {
        cout << "Oster haciendo el mejor tinto" << endl;
    }
    void Aromatica() override {
        cout << "Oster haciendo la mejor aromatica" << endl;
    }
    void CafeLeche() override {
        cout << "Oster haciendo el mejro Café con leche" << endl;
    }
};

/* Implementación del TAD para HACEB */
class Haceb : public Cafetera {
public:
    void Capuchino() override {
        cout << "Haceb haciendo capuchino" << endl;
        cout << "¡FRESH!" << endl;
    }
    void Tinto() override {
        cout << "Haceb haciendo tinto" << endl;
        cout << "¡FRESH!" << endl;
    }
    void Aromatica() override {
        cout << "Haceb haciendo aromatica!!!" << endl;
        cout << "¡FRESH!" << endl;
    }
    void CafeLeche() override {
        cout << "Haceb haciendo café con leche!!!" << endl;
        cout << "¡FRESH!" << endl;
    }
};



int main() {
    /* Creación de objetos PHILIPS, OSTER, Haceb */
    Cafetera* c_Oster = new Oster();
    Cafetera* c_Haceb = new Haceb();
    Cafetera* c_PHILIPS = new PHILIPS();

    int eleccion = 0;

    while (true) {
        cout << "Qué cafetera quiere usar?" << endl;
        cout << "1. Oster" << endl << "2. Haceb" << endl << "3. PHILIPS" << endl << "4. Salir" << endl << endl;
        cin >> eleccion;

        if (eleccion == 4) {
            cout << "Bomboyash" << endl;
            break;
        }

        Cafetera* cafeteraSeleccionada = nullptr;
        int tipoCafe = 0;

        switch (eleccion) {
            case 1: cafeteraSeleccionada = c_Oster; break;
            case 2: cafeteraSeleccionada = c_Haceb; break;
            case 3: cafeteraSeleccionada = c_PHILIPS; break;
            default:
                cout << "Intente nuevamente error al colocar número" << endl;
                continue;
        }

        cout << endl << "Que tipo de café desea?" << endl;
        cout << "1. Capuchino" << endl << "2. Tinto" << endl << "3. Aromatica" << endl << "4. Café con Leche" << endl << endl;
        cin >> tipoCafe;

        bool opcionValida = false;
        for (int i = 1; i <= 4; ++i) {
            if (tipoCafe == i) {
                opcionValida = true;
                switch (i) {
                    case 1: cafeteraSeleccionada->Capuchino(); break;
                    case 2: cafeteraSeleccionada->Tinto(); break;
                    case 3: cafeteraSeleccionada->Aromatica(); break;
                    case 4: cafeteraSeleccionada->CafeLeche(); break;
                }
                break;
            }
        }

        if (!opcionValida) {
            cout << "Intente nuevamente error al colocar número" << endl;
        }
    }

    /* Liberar memoria */
    delete c_Oster;
    delete c_Haceb;
    delete c_PHILIPS;

    return 0;
}
