#pragma once
#include <stdlib.h>
#include <string.h>
#include <memory>
using namespace std;
    // Clothing classes

class Clothing
{
protected:
    float quality;
    int stockAmount; // Un objeto son todo es stock
public:
    void addStock(int st) {stockAmount += st;}
};

class Shirts : public Clothing
{
private:
    float sleeve;
    float collar;
public:
    Shirts(float sleeve, float quality, float collar, int stockAmount);
};

class Pants : public Clothing
{
private:
    float type;
public:
    Pants(float type, float quality, int stockAmount);
};

// Vendor and Invoice classes
class Invoice
{
private:
    int id;
    string date;
    int vendorCode;
    string invArticle;
    int totalPrice;
    int unitPrice;
    int quantity;
public:
    Invoice(int vendorCode);
    void setAttributes(int quantity, string article, int unitPrice, int totalPrice);
    void printSelf();
};

class Vendor
{
private:
    string name;
    string lastName;
    int code;
    int invoiceQuantity = 0;
    Invoice* invList[20];
public:
    Vendor(string name, string lastName);
    void createInvoice(int quan, string art, int unitPrice, int totalPrice);
    void printInvoices();
    void printInfo();
};

// Shop class
class Shop
{
private:
    string name;
    string direction;
        // Define objects as smart pointers
    // Vendor
    unique_ptr<Vendor> vendorPtr = make_unique<Vendor>("Ana", "Lebowski");
    // Shirts
        // Short sleeve mao collar
    unique_ptr<Shirts> shortStandardMao = make_unique<Shirts>(0.90, 1.0, 1.03, 100);
    unique_ptr<Shirts> shortPremiumMao = make_unique<Shirts>(0.90, 1.30, 1.03, 100);
        // Short sleeve normal collar
    unique_ptr<Shirts> shortStandardNormal = make_unique<Shirts>(0.90, 1.0, 0, 150);
    unique_ptr<Shirts> shortPremiumNormal = make_unique<Shirts>(0.90, 1.30, 0, 150);
        // Large sleeve mao collar
    unique_ptr<Shirts> largeStandardMao = make_unique<Shirts>(1, 1.0, 1.03, 75);
    unique_ptr<Shirts> largePremiumMao = make_unique<Shirts>(1, 1.30, 1.03, 75);
        // Large sleeve normal collar
    unique_ptr<Shirts> largeStandardNormal = make_unique<Shirts>(1, 1.0, 0, 175);
    unique_ptr<Shirts> largePremiumNormal = make_unique<Shirts>(1, 1.30, 0, 175);

    // Pants
        // Skinny
    unique_ptr<Pants> skinnyStandard = make_unique<Pants>(0.88, 1.0, 750);
    unique_ptr<Pants> skinnyPremium = make_unique<Pants>(0.88, 1.30, 750);
        // Not skinny
    unique_ptr<Pants> normalStandard = make_unique<Pants>(1, 1.0, 250);
    unique_ptr<Pants> normalPremium = make_unique<Pants>(1, 1.30, 250);

        // Get normal pointers to use them in functions
    Vendor* vendor = vendorPtr.get();
    
public:
    Shop(string name, string direction);
    void printInfo();
    void printVendInfo();
    void printVendInvoices();
};

