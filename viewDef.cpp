// The "conio" library is used for a more fluid interaction with the program
#include <conio.h>
#include "view.hpp"

void View::programLoop(){
    int key = 0;
    // Change states for menus
    int state = 0;
    // States for the invoice creation menus
    int invState = 0;
    // Integer to call the function to calculate the invoice
    int itemID = 0;
    int price, quan;
    startMenu();

    while (1)
    {
        if (state!=4)
        {
            // This function retrieves a pressed key in ASCII code
            // 1 = 49 / 2 = 50 / spacebar = 32
            key=getch();
        }
            // Different menus
            // 0 = main menu / 1 = invoice history / 2 = create invoice / 3 = create invoice / 4 = close the program
        if(state==0){
            invState = 0;
            itemID = 0;
            switch (key)
            {
                case 49:
                    state = 1;
                    invoiceHistoryMenu();
                    break;
                case 50:
                    state = 2;
                    clothType();
                    break;
                case 32:
                    state=4;
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
        else if(state==2){
            // Menu for the various clothes options
            // (I doubt I did this the best way possible cause it's very confusing, but it works)
            // I tried comparing "invState" with a switch case, but it kept failing so I used else if

            // Choice between shirts and pants
            if (invState==0)
            {
                switch (key)
                {
                    case 49:
                        invState = 1;
                        itemID += 1;
                        shirtSleeve();
                        break;
                    case 50:
                        invState = 3;
                        itemID += 9;
                        pantSkinny();
                        break;
                    case 32:
                        state = 0;
                        startMenu();
                        break;
                    default:
                        break;
                }
            }
            // Choice for the sleeve size on shirts
            else if (invState==1){
                switch (key)
                {
                    case 49:
                        invState = 2;
                        shirtCollar();
                        break;
                    case 50:
                        invState = 2;
                        itemID += 4;
                        shirtCollar();
                        break;
                    case 32:
                        state = 0;
                        startMenu();
                        break;
                    default:
                        break;
                }
            }
            // Choice for the collar type on shirts
            else if (invState==2){
                switch (key)
                {
                    case 49:
                        invState = 4;
                        Premium();
                        break;
                    case 50:
                        invState = 4;
                        itemID += 2;
                        Premium();
                        break;
                    case 32:
                        state = 0;
                        startMenu();
                        break;
                    default:
                        break;
                }
            }
            // Choice for the type on pants
            else if (invState==3){
                switch (key)
                {
                    case 49:
                        invState = 4;
                        Premium();
                        break;
                    case 50:
                        itemID += 2;
                        invState = 4;
                        Premium();
                        break;
                    case 32:
                        state = 0;
                        startMenu();
                        break;
                    default:
                        break;
                }
            }
            // Choice for premium or not and the unit quantity and price
            else if (invState==4){
                switch (key)
                {
                    case 49:
                        invState = 5;
                        unitPrice(&price);
                        unitQuantity(&quan);
                        creating();
                        pres->createInvoice(itemID,price,quan);
                        invoiceCreated();
                        break;
                    case 50:
                        itemID += 1;
                        invState = 5;
                        unitPrice(&price);
                        unitQuantity(&quan);
                        creating();
                        pres->createInvoice(itemID,price,quan);
                        invoiceCreated();
                        break;
                    case 32:
                        state = 0;
                        startMenu();
                        break;
                    default:
                        break;
                }
            }
            // Invoice created screen
            else if (invState==5){
                switch (key)
                {
                    case 32:
                        state = 0;
                        startMenu();
                        break;
                }
            }
            
           
        }
        // Create the invoice
        else if(state==3){
            pres->createInvoice(itemID,price,quan);
        }
        // Close the program
        else if(state==4){break;}
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
    cout << "Press spacebar to close the calculator" << endl;
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

void View::clothType(){
    topInvoicePart();
    cout << "What kind of clothes?" << endl << endl;

    cout << "1) Shirts" << endl;
    cout << "2) Pants" << endl;
    bottomInvoicePart();
}


void View::shirtSleeve(){
    topInvoicePart();
    cout << "What kind of sleeve?" << endl << endl;

    cout << "1) Short" << endl;
    cout << "2) Large" << endl;
    bottomInvoicePart();
}

void View::shirtCollar(){
    topInvoicePart();
    cout << "What kind of collar?" << endl << endl;

    cout << "1) Normal" << endl;
    cout << "2) Mao" << endl;
    bottomInvoicePart();
}

void View::pantSkinny(){
    topInvoicePart();
    cout << "What type of pant?" << endl << endl;

    cout << "1) Normal" << endl;
    cout << "2) Skinny" << endl;
    bottomInvoicePart();
}

void View::Premium(){
    topInvoicePart();
    cout << "What kind of fabric?" << endl << endl;

    cout << "1) Standard" << endl;
    cout << "2) Premium" << endl;
    bottomInvoicePart();
}

void View::unitPrice(int *price){
    topInvoicePart();
    cout << "What is the unit price?" << endl << endl;
    cin >> *price;
}

void View::unitQuantity(int *quantity){
    topInvoicePart();
    cout << "How many units?" << endl << endl;
    cin >> *quantity;
}

void View::creating(){
    cout << "Creating invoice..." << endl;
}

void View::invoiceCreated(){
    cout << "Invoice created succesfully" << endl;
    dotLine();
    cout << "Press spacebar to go back to the main menu" << endl;
    dotLine();
}

void View::topInvoicePart(){
    topPart();
    cout << "INVOICE CREATOR" << endl;
    dotLine();
    cout << "Press spacebar to cancel" << endl;
    dotLine();
    cout << endl;
}

void View::bottomInvoicePart(){
    cout << endl;
    dotLine();
    cout << "Press spacebar to cancel" << endl;
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
