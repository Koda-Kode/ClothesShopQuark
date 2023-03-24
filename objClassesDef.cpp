#include <iostream>
#include <string.h>
#include "objClasses.hpp"

    // Clothes
Shirts::Shirts(float sleeve, float quality, float collar, int stockAmount)
{
    this->quality = quality;
    this->stockAmount = stockAmount;
    this->sleeve = sleeve;
    this->collar = collar;
}

Pants::Pants(float type, float quality, int stockAmount)
{
    this->quality = quality;
    this->stockAmount = stockAmount;
    this->type = type;
}

    // Invoice
Invoice::Invoice(int vendorCode)
{
    this->id = rand() % 9999;
    this->vendorCode = vendorCode;
    string date = "example date";
}

void Invoice::setAttributes(int quantity, string article, int unitPrice, int totalPrice){
    this->quantity = quantity;
    this->invArticle = article;
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

void Vendor::createInvoice(int quan, string art, int unitPrice, int totalPrice){
    invList[invoiceQuantity]->setAttributes(quan, art, unitPrice, totalPrice);
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
    vendor->printInfo();
}

void Shop::printVendInvoices(){
    vendor->printInvoices();
}

