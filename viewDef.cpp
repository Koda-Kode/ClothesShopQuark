#include <iostream>
#include <conio.h>
using namespace std;
#include "view.hpp"

void View::programLoop(){
    int key = 0;
    // Change states for menus
    int estado=0;
    
    while (1)
    {
            // Interacción
        key=getch();
            // Menus
        if(estado==0){
            switch (key)
            {
                case 49:
                    menuArmas();
                    estado=1;
                    break;
                case 50:
                    pres->presDejar();
                    break;
                case 51:
                    pres->presDisparar();
                    break;
                case 52:
                    pres->presArmaActual();
                    break;
                case 32:
                estado=2;
                    break;
                default:
                    break;
            }
        }
        else if(estado==1){
            switch (key)
            {
                case 49:
                    pres->presRecojer(1);
                    break;
                case 50:
                    pres->presRecojer(2);
                    break;
                case 51:
                    pres->presRecojer(3);
                    break;
                case 32:
                    startMenu();
                    estado=0;
                    break;
                default:
                    break;
            }
        }
        // Salir del programa al presionar espacio
        else{break;}
    }

}

void View::startMenu(){
    cout << "\e[1;1H\e[2J";
    cout << "\n -== Bienvenido al campo de entrenamiento, soldado ==-\n" << endl;
    cout << "Que desea hacer?" << endl;
    cout << "(Presione el numero correspondiente a la opcion del menu)" << endl;

    cout << "1 - Recoger un arma" << endl;
    cout << "2 - Dejar el arma" << endl;
    cout << "3 - Disparar" << endl;
    cout << "4 - Ver arma actual" << endl;
    cout << "Espacio - Salir del programa" << endl << endl;
}

void View::menuArmas(){
    cout << "\e[1;1H\e[2J";
    cout << "Por favor, escoja el arma que desea utilizar:" << endl;

    cout << "1 - Revolver" << endl;
    cout << "2 - Escopeta" << endl;
    cout << "3 - Rifle" << endl;
    cout << "Espacio - Volver atras" << endl << endl;
}