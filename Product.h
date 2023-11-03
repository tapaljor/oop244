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
    int id;
    string name;
    double price;
    int shelf;
    long addDate;
    int expiryYear;
    int expiryMonth;
    int expiryDay;
    Utils *u;
public:
    // Constructors 
    Product(int id = 0, string name = "NA", double price = 0.0, 
            int shelf = 0, long addDate = 0, int expiryYear = 0, 
            int expiryMonth = 0, int expiryDay = 0) 
            : id(id), name(std::move(name)), price(price), 
            shelf(shelf), addDate(addDate), expiryYear(expiryYear), 
            expiryMonth(expiryMonth), expiryDay(expiryDay) {}

    virtual ~Product() {}

    virtual double calculateTotalPrice() const {
        return price;
    }
    // virtual functions
    virtual void addProduct() {
        id = u->generateRandomNumber();
        addDate = u->generateCurrentTimeStamp();
             
        cout << "Enter product name: ";
        cin.ignore();
        getline(std::cin, name);
        cout << "Enter shelf (number only): ";
        cin >> shelf;

        do {
            cout << "Enter expiry date (yyyy mm dd): ";
            cin >> expiryYear >> expiryMonth >> expiryDay;
        } while (!u->checkDate(expiryYear, expiryMonth, expiryDay));

        cout << "Enter price (only number or decimal): ";
        cin >> price;
    }
    virtual void displayProductInfo() const {
        
        string eD = std::to_string(expiryYear) + "-" + 
                    std::to_string(expiryMonth) + "-" + 
                    std::to_string(expiryDay);
        cout << left << setw(13) << id 
         << left << setw(20) << name.substr(0, 18)   
         << left << setw(10) << calculateTotalPrice() 
         << left << setw(6) << shelf  
         << left << setw(15) << u->displayFormattedDate(addDate)
         << left << setw(15) << eD;
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
};
/*derive class/inheritance class*/
class Vegetable : public Product {
private:
    double weight; // Weight of the vegetable in kilograms
public: 
    // Constructor with initializer list
    Vegetable(int id = 0, string name = "NA", double price = 0.0, int shelf = 0, 
              long addDate = 0, int expiryYear = 0, int expiryMonth = 0, int expiryDay = 0,
              double weight = 0.0)
    : Product(id, std::move(name), price, shelf, addDate, expiryYear, expiryMonth, expiryDay),
      weight(weight) {}

    // Overridden method to include new behavior or attributes for Vegetable
    double calculateTotalPrice() const override {
        return price * weight;
    }
    void addProduct() override {
        Product::addProduct(); // Call the base class method to reuse functionality
        std::cout << "Enter weight (KG): ";
        std::cin >> weight;
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
              long addDate = 0, int expiryYear = 0, int 
              expiryMonth = 0, int expiryDay = 0, int quantity = 0)
    : Product(id, std::move(name), price, shelf, addDate, expiryYear, expiryMonth, expiryDay),
      quantity(quantity) {}

    // Overridden method to include new behavior or attributes for Vegetable
    double calculateTotalPrice() const override {
        return price * quantity;
    }
    void addProduct() override {
        Product::addProduct(); // Call the base class method to reuse functionality
        std::cout << "Enter quantity (number only): ";
        std::cin >> quantity;
    }
    // Overridden method to display Vegetable-specific information
    void displayProductInfo() const override {
        Product::displayProductInfo(); // Call the base class method to display common product info
        std::cout << std::left << std::setw(6) << quantity << "PS" << endl;
    }
};

