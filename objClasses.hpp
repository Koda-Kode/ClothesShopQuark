#pragma once
#include <iostream> 
#include <stdlib.h>
#include <ctime>
using namespace std;

class Shop
{
private:
    string name = "Good Buy";
    string direction = "Schestakow Avenue 4566";
public:
    Shop(/* args */);
    ~Shop();
};

Shop::Shop(/* args */)
{
}


class Vendor
{
private:
    string name;
    string lastName;
    int code;
    Invoice invList[20];
    unique_ptr<Invoice> invoiceExample = make_unique<Invoice>();
public:
    Vendor(string name, string lastName);
    ~Vendor();
    void createInvoice();
};

Vendor::Vendor(string name, string lastName)
{
    invList[0] = invoiceExample;
    this->name = name;
    this->lastName = lastName;
    this->code = rand() % 99999;
}

class Invoice
{
private:
    int id;
    string date;
    int vendorCode;
    int article;
    int quantity;
public:
    Invoice(int vendorCode, int article, int quantity);
    ~Invoice();
};

Invoice::Invoice(int vendorCode, int article, int quantity)
{
    this->id = rand() % 9999;
    this->vendorCode = vendorCode;
    this->article = article;
    this->quantity = quantity;
}

