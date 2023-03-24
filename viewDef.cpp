#include <iostream>
// The "conio" library is used for a more fluid interaction with the program
#include <conio.h>
using namespace std;
#include "view.hpp"

void View::programLoop(){
    int key = 0;
    // Change states for menus
    int state=0;
    startMenu();

    while (1)
    {
        if (state!=5)
        {
            // This function retrieves a pressed key in ASCII code
            key=getch();
        }
            // Different menus
            // 0 = main menu / 1 = invoice history / 2 = create invoice
        if(state==0){
            
            switch (key)
            {
                case 49:
                    state = 1;
                    invoiceHistoryMenu();
                    break;
                case 50:
                    // Create Invoice
                    break;
                case 32:
                    state=5;
                    break;
                default:
                    break;
            }
        }
        else if(state==1){
            switch (key)
            {
                case 32:
                    state = 0;
                    startMenu();
                    break;
                default:
                    break;
            }
        }
        
        else if(state==5){break;}
    }

}

void View::startMenu(){
    topPart();
    pres->printShopInfo();
    dotLine();
    pres->printVendorInfo();
    dotLine();
    cout << "SELECT AN OPTION:" << endl << endl;

    cout << "1) Invoice History" << endl;
    cout << "2) Create an Invoice" << endl;
    dotLine();
    cout << "Press spacebar twice to close calculator" << endl;
    dotLine();
}

void View::invoiceHistoryMenu(){
    topPart();
    cout << "HISTORY" << endl;
    dotLine();
    cout << "Press spacebar to go back" << endl;
    dotLine();
    cout << endl;
    pres->printVendorInvoices();
    cout << endl;
    dotLine();
    cout << "Press spacebar to go back" << endl;
    dotLine();
}

void View::topPart(){
    cout << "\e[1;1H\e[2J";
    cout << "---------------------------------------------------------" << endl;
    cout << "INVOICE CALCULATOR" << endl;
    cout << "---------------------------------------------------------" << endl;
}

void View::dotLine(){
    cout << "---------------------------------------------------------" << endl;
}