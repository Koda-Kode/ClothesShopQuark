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
        if (state!=3)
        {
            // This function retrieves a pressed key in ASCII code
            // 1 = 49 / 2 = 50 / spacebar = 32
            key=getch();
        }
            // Different menus
            // 0 = main menu / 1 = invoice history / 2 = create invoice / 3 = close the program
        if(state==0){
            // Reset the Invoice creator values
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
                    state=3;
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
            // I tried comparing "invState" with a switch case, but it kept failing so I used else if, if you can tell me why I would be grateful

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
                        confirm(itemID);
                        unitPrice(&price);
                        unitQuantity(&quan,itemID);
                        dotLine();
                        creating();
                        pres->createInvoice(itemID,price,quan);
                        break;
                    case 50:
                        itemID += 1;
                        invState = 5;
                        confirm(itemID);
                        unitPrice(&price);
                        unitQuantity(&quan,itemID);
                        dotLine();
                        creating();
                        pres->createInvoice(itemID,price,quan);
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
        // Close the program
        else if(state==3){break;}
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
    cout << "(The maximum number of invoices is 20)" << endl;
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

void View::confirm(int itemID){
    int aux;
    topInvoicePart();
    cout << "The item selected is: " << pres->returnNames(itemID) << "\nEnter Anything to Continue" << endl;
    cin >> aux;
}

void View::unitPrice(int *price){
    int aux=0;
    topInvoicePart();
        // This while checks if the input is an integer
    do
    {
            // Clear the fail check
        cin.clear();
        cin.ignore( numeric_limits<streamsize>::max(), '\n' );
            // If you enter a negative number, it will be converted to positive, and if you enter 0, it will transform to a 1 by defect.
        cout << "What is the unit price?\n(Input an integer)" << endl << endl;
        cin >> aux;
        if (aux < 0)
        {
            aux *= -1;
        }
        else if (aux == 0)
        {
            aux = 1;
        }
        
    } while (cin.fail());

    *price = aux;
}

void View::unitQuantity(int *quantity, int itemID){
    int aux=0;
    topInvoicePart();
    cout << "There are " << pres->returnUnits(itemID) << " units available." << endl;
    dotLine();
        // This while checks if the input is an integer
    do
    {
            // Clear the fail check
        cin.clear();
        cin.ignore( numeric_limits<streamsize>::max(), '\n' );
            // If you enter a negative number, it will be converted to positive, and if you enter 0, it will transform to a 1 by defect.
        cout << "How many units do you want to add?\n(Input an integer)" << endl << endl;
        cin >> aux;
        if (aux < 0)
        {
            aux *= -1;
        }
        else if (aux == 0)
        {
            aux = 1;
        }
        
    } while (cin.fail());
    
    *quantity = aux;
}

void View::creating(){
    cout << "Creating invoice..." << endl;
}

void View::topInvoicePart(){
    topPart();
    cout << "INVOICE CREATOR" << endl;
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
