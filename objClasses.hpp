#pragma once
#include <stdlib.h>

class Shop
{
private:
    string name = "Good Buy";
    string direction = "Schestakow Avenue 4566";
public:
    Shop(/* args */);
    ~Shop();
};

Shop::Shop()
{
}

class Vendor
{
private:
    string name;
    string lastName;
    int code;
    Invoice invList[20];
    unique_ptr<Invoice> invoiceExample = make_unique<Invoice>(code, 1, 7);
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
};

Invoice::Invoice(int vendorCode, int article, int quantity)
{
    this->id = rand() % 9999;
    this->vendorCode = vendorCode;
    this->article = article;
    this->quantity = quantity;
    string date = "example date";
}

class Clothing
{
protected:
    int quality;
    float unitPrice;
    int stockAmount; // Un objeto son todo es stock
};

class Shirts : public Clothing
{
private:
    int sleeve;
    int collar;
public:
    Shirts(int quality, float unitPrice, int stockAmount, int sleeve, int collar);
};

Shirts::Shirts(int quality, float unitPrice, int stockAmount, int sleeve, int collar)
{
    this->quality = quality;
    this->unitPrice = unitPrice;
    this->stockAmount = stockAmount;
    this->sleeve = sleeve;
    this->collar = collar;
}

class Pants : public Clothing
{
private:
    int type;
public:
    Pants(int quality, float unitPrice, int stockAmount, int type);
};

Pants::Pants(int quality, float unitPrice, int stockAmount, int type)
{
    this->quality = quality;
    this->unitPrice = unitPrice;
    this->stockAmount = stockAmount;
    this->type = type;
}
