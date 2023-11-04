#include <iostream>
#include <string>
#include <chrono>
#include <random>
#include <iomanip>
#include <vector>
#include "utility.h"

using std::string;
using std::cout;
using std::cin;
using std::left;
using std::setw;
using std::endl;
using std::vector;

//prototypes here

/*base class*/
class Product {
protected:
    long id;
    string name;
    double price;
    int shelf;
    long addDate;
    long expiryDate;
    Utils *u;
public:
    // Constructors 
    Product(int id = 0, string name = "NA", double price = 0.0, 
            int shelf = 0, long addDate = 0, long expiryDate = 0) 
            : id(id), name(std::move(name)), price(price), 
            shelf(shelf), addDate(addDate), expiryDate(expiryDate) {} 

    virtual ~Product() {}

    virtual double calculateTotalPrice() const {
        return price;
    }
    // virtual functions
    virtual void addProduct() {
        int y = 0;
        int m = 0;
        int d = 0;
        id = u->generateRandomNumber();
        addDate = u->generateCurrentTimeStamp();
             
        cout << "Enter product name: ";
        cin.ignore();
        getline(cin, name);
        do {
            cout << "Enter shelf (number only): ";
            cin >> shelf;
        } while( !u->validateInput());

        do {
            cout << "Enter expiry date (yyyy mm dd): ";
            cin >> y >> m >> d;
        } while (!u->checkDate(y, m, d));

        string eD = std::to_string(y)+"-"+std::to_string(m)+"-"+std::to_string(d);
        expiryDate = u->convertDateToTimestamp(eD);

        do {
            cout << "Enter price (only number or decimal): ";
            cin >> price;
        } while( !u->validateInput());
    }
    virtual void editProduct() {
        int y, m, d = 0;
        /*edits all the base attributes*/
        cout << "Enter name: ";
        cin.ignore();
        getline(cin, name);
                        
        do {
            cout << "Enter shelf (number only): ";
            cin >> shelf;
        } while( !u->validateInput());

        do {
            cout << "Enter expiry date (yyyy mm dd): ";
            cin >> y >> m >> d;
        } while (!u->checkDate(y, m, d));
        string eD = std::to_string(y)+"-"+std::to_string(m)+"-"+std::to_string(d);
        expiryDate = u->convertDateToTimestamp(eD);
                        
        do {
            cout << "Enter price (only number or decimal): ";
            cin >> price;
        } while( !u->validateInput());
    }
    virtual void displayProductInfo() const {
        
        cout << left << setw(10) << id 
         << left << setw(20) << name.substr(0, 18)   
         << left << setw(10) << calculateTotalPrice() 
         << left << setw(6) << shelf  
         << left << setw(15) << u->displayFormattedDate(addDate) 
         << left << setw(15) << u->displayFormattedDate(expiryDate);
    }

    /*setters*/
    void setName(const string str) {
        name = str;
    }
    void setShelf(const int s) {
        shelf = s;
    }
    void setExpiryDate(const long eD) {
        expiryDate = eD;
    }
    void setPrice(const double pr) {
        price = pr;
    }
    // Getters can be made const
    int getId() const {
        return id;
    }
    string getName() const {
        return name;
    }
    double getPrice() const {
        return price;
    }
    int getExpiryDate () const {
        return expiryDate;
    }
};
/*derive class/inheritance class*/
class Vegetable : public Product {
private:
    double weight; // Weight of the vegetable in kilograms
public: 
    // Constructor with initializer list
    Vegetable(int id = 0, string name = "NA", double price = 0.0, int shelf = 0, 
              long addDate = 0, long expiryDate = 0, double weight = 0.0)
    : Product(id, std::move(name), price, shelf, addDate, expiryDate),
      weight(weight) {}

    // Overridden method to include new behavior or attributes for Vegetable
    double calculateTotalPrice() const override {
        return price * weight;
    }
    void addProduct() override {
        Product::addProduct(); // Call the base class method to reuse functionality
        do {
            std::cout << "Enter weight (KG): ";
            std::cin >> weight;
        } while ( !u->validateInput());
    }
    void editProduct() override {
        Product::editProduct();
        do {
            cout << "Enter weight (number or decimal only): ";
            cin >> weight;
        } while( !u->validateInput());
    }
    // Overridden method to display Vegetable-specific information
    void displayProductInfo() const override {
        Product::displayProductInfo(); // Call the base class method to display common product info
        std::cout << std::left << std::setw(6) << weight << "KG" <<endl;
    }
};
/*derive class/inheritance class*/
class Fruit : public Product {
private:
    int quantity; // Weight of the vegetable in kilograms
public: 
    // Constructor with initializer list
    Fruit(int id = 0, string name = "NA", double price = 0.0, int shelf = 0, 
              long addDate = 0, long expiryDate = 0, int quantity = 0)
    : Product(id, std::move(name), price, shelf, addDate, expiryDate),
      quantity(quantity) {}

    // Overridden method to include new behavior or attributes for Vegetable
    double calculateTotalPrice() const override {
        return price * quantity;
    }
    void addProduct() override {
        Product::addProduct(); // Call the base class method to reuse functionality
        do {
            cout << "Enter quantity (number only): ";
            cin >> quantity;
        } while ( !u->validateInput());
    }
    void editProduct() override {
        Product::editProduct();
        do {
            cout << "Enter quantity (number only): ";
            cin >> quantity;
        } while ( !u->validateInput());
    }
    // Overridden method to display Vegetable-specific information
    void displayProductInfo() const override {
        Product::displayProductInfo(); // Call the base class method to display common product info
        std::cout << std::left << std::setw(6) << quantity << "PS" << endl;
    }
};
