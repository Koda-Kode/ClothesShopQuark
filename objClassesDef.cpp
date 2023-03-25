#include "objClasses.hpp"

    // Clothes
Shirts::Shirts(float sleeve, float quality, float collar, int stockAmount)
{
    this->quality = quality;
    this->stockAmount = stockAmount;
    this->sleeve = sleeve;
    this->collar = collar;
}

int Shirts::priceCalculator(int unit, int quan){
    if (stockAmount - quan < 0)
    {
        cout << "No hay suficiente stock de este producto";
        return 0;
    }
    int total;
    total = (unit * sleeve * collar * quan) * quality;
    stockAmount -= quan;
    return total;
}

Pants::Pants(float type, float quality, int stockAmount)
{
    this->quality = quality;
    this->stockAmount = stockAmount;
    this->type = type;
}

int Pants::priceCalculator(int unit, int quan){
    if (stockAmount - quan < 0)
    {
        cout << "No hay suficiente stock de este producto";
        return 0;
    }
    int total;
    total = (unit * type * quan) * quality;
    stockAmount -= quan;
    return total;
}

    // Invoice
Invoice::Invoice(int vendorCode)
{
    this->id = rand() % 9999;
    this->vendorCode = vendorCode;
    string date = "example date";
}

void Invoice::setAttributes(int quantity, string artName, int unitPrice, int totalPrice){
    cout << quantity << endl;
    cout << artName << endl;
    cout << unitPrice << endl;
    cout << totalPrice << endl;
    this->quantity = quantity;
    cout << "Hasta ahora si" << endl;
    this->invArticle = artName;
    this->unitPrice = unitPrice;
    this->totalPrice = totalPrice;
}

void Invoice::printSelf(){
    cout << "ID Number: " << id << endl;
    cout << "Date of Creation: " << date << endl;
    cout << "Vendor code: " << vendorCode << endl;
    cout << "Product info: " << invArticle << endl;
    cout << "Price per unit: " << "$" << unitPrice << endl;
    cout << "Quantity: " << quantity << endl;
    cout << "Total: " << "$" << totalPrice << endl << endl;
}

    // Vendor
Vendor::Vendor(string name, string lastName)
{
    this->name = name;
    this->lastName = lastName;
    this->code = rand() % 99999;
}

void Vendor::createInvoice(int quan, string artName, int unitPrice, int totalPrice){
    invList[invoiceQuantity]->setAttributes(quan, artName, unitPrice, totalPrice);
    invoiceQuantity++;
}

void Vendor::printInvoices(){
    if (invoiceQuantity == 0)
    {
        cout << "You have not created an invoice yet." << endl;
    }
    for (int i = 0; i < invoiceQuantity; i++)
    {
        invList[i]->printSelf();
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
        vendorPtr->createInvoice(quan,"Standard Normal Short Shirt",unit,shortStandardNormal->priceCalculator(unit,quan));
        break;
    case 2:
        vendorPtr->createInvoice(quan,"Premium Normal Short Shirt",unit,shortPremiumNormal->priceCalculator(unit,quan));
        break;
    case 3:
        vendorPtr->createInvoice(quan,"Standard Mao Short Shirt",unit,shortStandardMao->priceCalculator(unit,quan));
        break;
    case 4:
        vendorPtr->createInvoice(quan,"Premium Mao Short Shirt",unit,shortPremiumMao->priceCalculator(unit,quan));
        break;
    case 5:
        vendorPtr->createInvoice(quan,"Standard Normal Large Shirt",unit,largeStandardNormal->priceCalculator(unit,quan));
        break;
    case 6:
        vendorPtr->createInvoice(quan,"Premium Normal Large Shirt",unit,largePremiumNormal->priceCalculator(unit,quan));
        break;
    case 7:
        vendorPtr->createInvoice(quan,"Standard Mao Large Shirt",unit,largeStandardMao->priceCalculator(unit,quan));
        break;
    case 8:
        vendorPtr->createInvoice(quan,"Premium Mao Large Shirt",unit,largePremiumMao->priceCalculator(unit,quan));
        break;
        
        // Pants
    case 9:
        vendorPtr->createInvoice(quan,"Standard Normal Pant",unit,normalStandard->priceCalculator(unit,quan));
        break;
    case 10:
        vendorPtr->createInvoice(quan,"Premium Normal Pant",unit,normalPremium->priceCalculator(unit,quan));
        break;
    case 11:
        vendorPtr->createInvoice(quan,"Standard Skinny Pant",unit,skinnyStandard->priceCalculator(unit,quan));
        break;
    case 12:
        vendorPtr->createInvoice(quan,"Premium Skinny Pant",unit,skinnyPremium->priceCalculator(unit,quan));
        break;
    
    default:
        break;
    }
}