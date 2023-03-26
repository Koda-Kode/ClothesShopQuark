#include <ctime>
#include "objClasses.hpp"

    // Clothes
Shirts::Shirts(float sleeve, float quality, float collar, int stockAmount)
{
    this->quality = quality;
    this->stockAmount = stockAmount;
    this->sleeve = sleeve;
    this->collar = collar;
}

int Shirts::priceCalculator(int unit, int quan, int substract){
    if (stockAmount - quan < 0)
    {
        return 0;
    }
    int total;
    total = (unit * sleeve * collar * quan) * quality;
    if (substract)
    {
        stockAmount -= quan;
    }
    return total;
}

Pants::Pants(float type, float quality, int stockAmount)
{
    this->quality = quality;
    this->stockAmount = stockAmount;
    this->type = type;
}

int Pants::priceCalculator(int unit, int quan, int substract){
    if (stockAmount - quan < 0)
    {
        return 0;
    }
    int total;
    total = (unit * type * quan) * quality;
    if (substract)
    {
        stockAmount -= quan;
    }
    return total;
}

    // Invoice
void Invoice::setAttributes(int quantit, string artName, int unitPrice, int totalPrice, int vendorCode){
    this->quantity = quantit;
    this->invArticle = artName;
    this->unitPrice = unitPrice;
    this->totalPrice = totalPrice;
    this->id = rand() % 9999;
    this->vendorCode = vendorCode;
    date = getCurrentDateTime();
    cout << "\nInvoice result: " << endl;
    printSelf();
}

void Invoice::printSelf(){
    cout << "ID Number: " << id << endl;
    cout << "Date and Time of Creation: " << date << endl;
    cout << "Vendor Code: " << vendorCode << endl;
    cout << "Product Info: " << invArticle << endl;
    cout << "Price Per Unit: " << "$" << unitPrice << endl;
    cout << "Quantity: " << quantity << endl;
    cout << "Total: " << "$" << totalPrice << endl << endl;
}

string Invoice::getCurrentDateTime() {
    time_t timeNow = time(nullptr);

    char temp[80];
    strftime(temp, 80, "%d-%m-%Y %H:%M:%S", localtime(&timeNow));
    string dateTimeStr(temp);

    return dateTimeStr;
}

    // Vendor
Vendor::Vendor(string name, string lastName)
{
    this->name = name;
    this->lastName = lastName;
    this->code = rand() % 99999;
}

void Vendor::createInvoice(int quan, string artName, int unitPrice, int totalPrice){
    invList[invoiceQuantity].setAttributes(quan, artName, unitPrice, totalPrice, code);
    invoiceQuantity++;
}

void Vendor::printInvoices(){
    if (invoiceQuantity == 0)
    {
        cout << "You have not created an invoice yet." << endl;
    }
    for (int i = 0; i < invoiceQuantity; i++)
    {
        invList[i].printSelf();
    }
}

void Vendor::printInfo(){
    cout << name << " " << lastName << " | " << code << endl;
}

    // Shop
Shop::Shop(string name, string direction){
    this->name = name;
    this->direction = direction;
}

void Shop::printInfo(){
    cout << direction << " | " << name << endl;
}

void Shop::printVendInfo(){
    vendorPtr->printInfo();
}

void Shop::printVendInvoices(){
    vendorPtr->printInvoices();
}

void Shop::selectItem(int itemID, int unit, int quan){
    switch (itemID)
    {
        // Shirts
    case 1:
        if (shortStandardNormal->priceCalculator(unit,quan,0) == 0)
        {
            noStock();
            break;
        }
        vendorPtr->createInvoice(quan,"Standard Normal Short Shirt",unit,shortStandardNormal->priceCalculator(unit,quan,1));
        invoiceCreated();
        break;
    case 2:
        if (shortPremiumNormal->priceCalculator(unit,quan,0) == 0)
        {
            noStock();
            break;
        }
        vendorPtr->createInvoice(quan,"Premium Normal Short Shirt",unit,shortPremiumNormal->priceCalculator(unit,quan,1));
        invoiceCreated();
        break;
    case 3:
        if (shortStandardMao->priceCalculator(unit,quan,0) == 0)
        {
            noStock();
            break;
        }
        vendorPtr->createInvoice(quan,"Standard Mao Short Shirt",unit,shortStandardMao->priceCalculator(unit,quan,1));
        invoiceCreated();
        break;
    case 4:
        if (shortPremiumMao->priceCalculator(unit,quan,0) == 0)
        {
            noStock();
            break;
        }
        vendorPtr->createInvoice(quan,"Premium Mao Short Shirt",unit,shortPremiumMao->priceCalculator(unit,quan,1));
        invoiceCreated();
        break;
    case 5:
        if (largeStandardNormal->priceCalculator(unit,quan,0) == 0)
        {
            noStock();
            break;
        }
        vendorPtr->createInvoice(quan,"Standard Normal Large Shirt",unit,largeStandardNormal->priceCalculator(unit,quan,1));
        invoiceCreated();
        break;
    case 6:
        if (largePremiumNormal->priceCalculator(unit,quan,0) == 0)
        {
            noStock();
            break;
        }
        vendorPtr->createInvoice(quan,"Premium Normal Large Shirt",unit,largePremiumNormal->priceCalculator(unit,quan,1));
        invoiceCreated();
        break;
    case 7:
        if (largeStandardMao->priceCalculator(unit,quan,0) == 0)
        {
            noStock();
            break;
        }
        vendorPtr->createInvoice(quan,"Standard Mao Large Shirt",unit,largeStandardMao->priceCalculator(unit,quan,1));
        invoiceCreated();
        break;
    case 8:
        if (largePremiumMao->priceCalculator(unit,quan,0) == 0)
        {
            noStock();
            break;
        }
        vendorPtr->createInvoice(quan,"Premium Mao Large Shirt",unit,largePremiumMao->priceCalculator(unit,quan,1));
        invoiceCreated();
        break;
        
        // Pants
    case 9:
        if (normalStandard->priceCalculator(unit,quan,0) == 0)
        {
            noStock();
            break;
        }
        vendorPtr->createInvoice(quan,"Standard Normal Pant",unit,normalStandard->priceCalculator(unit,quan,1));
        invoiceCreated();
        break;
    case 10:
        if (normalPremium->priceCalculator(unit,quan,0) == 0)
        {
            noStock();
            break;
        }
        vendorPtr->createInvoice(quan,"Premium Normal Pant",unit,normalPremium->priceCalculator(unit,quan,1));
        invoiceCreated();
        break;
    case 11:
        if (skinnyStandard->priceCalculator(unit,quan,0) == 0)
        {
            noStock();
            break;
        }
        vendorPtr->createInvoice(quan,"Standard Skinny Pant",unit,skinnyStandard->priceCalculator(unit,quan,1));
        invoiceCreated();
        break;
    case 12:
        if (skinnyPremium->priceCalculator(unit,quan,0) == 0)
        {
            noStock();
            break;
        }
        vendorPtr->createInvoice(quan,"Premium Skinny Pant",unit,skinnyPremium->priceCalculator(unit,quan,1));
        invoiceCreated();
        break;
    
    default:
        break;
    }
}

int Shop::returnStock(int itemID){
    switch (itemID)
    {
        // Shirts
    case 1:
        return shortStandardNormal->stockReturn();
        break;
    case 2:
        return shortPremiumNormal->stockReturn();
        break;
    case 3:
        return shortStandardMao->stockReturn();
        break;
    case 4:
        return shortPremiumMao->stockReturn();
        break;
    case 5:
        return largeStandardNormal->stockReturn();
        break;
    case 6:
        return largePremiumNormal->stockReturn();
        break;
    case 7:
        return largeStandardMao->stockReturn();
        break;
    case 8:
        return largePremiumMao->stockReturn();
        break;
        
        // Pants
    case 9:
        return normalStandard->stockReturn();
        break;
    case 10:
        return normalPremium->stockReturn();
        break;
    case 11:
        return skinnyStandard->stockReturn();
        break;
    case 12:
        return skinnyPremium->stockReturn();
        break;
    default:
        break;
    }
}

void Shop::invoiceCreated(){
    cout << "Invoice created succesfully" << endl;
    cout << "---------------------------------------------------------" << endl;
    cout << "Press spacebar to go back to the main menu" << endl;
    cout << "---------------------------------------------------------" << endl;
}
void Shop::noStock(){
    cout << "There's not enough stock of this product" << endl;
    cout << "---------------------------------------------------------" << endl;
    cout << "Press spacebar to go back to the main menu" << endl;
    cout << "---------------------------------------------------------" << endl;
}