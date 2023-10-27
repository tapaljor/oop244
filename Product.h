#include <iostream>
#include <string>

using std::string;
using std::cout;

/*main/base class for grocery management*/
class Product {
protected:
    int id;
    string name;
    double price;
    long int addDate;
    long int soldDate;
public:
    /*default constructor*/
    Product() {
        id = 0;
        name = "NA";
        price = 0.0;
        addDate = 0;
        soldDate = 0;
    }
    /*constructor and initializing the protected data members attribute*/
    Product(int id, string name, double price, long int addDate, long int soldDate)
        :id(id), name(name), price(price), addDate(addDate), soldDate(soldDate) {}
    /*object destructor*/
    ~Product () {
        //cout << "Destroyer clearing the memory occupied by Product..";
    }

    /*virtual functions prototype*/
    virtual double calculateTotalPrice() {
        return price;
    }
    virtual void displayProductInfo() const {
        cout << left << setw(13) << id 
        << left << setw(20) << name.substr(0, 18)   
        << left << setw(10) << price
        << left << setw(10) << "1"  
        << left << setw(20) << displayFormattedDate(addDate)
        << left << setw(20) << displayFormattedDate(soldDate) << endl;
    }

    /*getters of attributes*/
    int getId() const {
        return id;
    }
    string getName() const {
        return name;
    }
    double getPrice() const {
        return price;
    }

    /*displaying timestamp in readable date time*/
    string displayFormattedDate(int type) const;
};
class Vegetable : public Product {
protected:
    double weight; //in kg
public: 
    Vegetable(int id, string name, double price, double weight, long int addDate, long int soldDate) 
        : Product(id, name, price, addDate, soldDate), weight(weight) {}

    /*derived class function overides virtual function*/
    double calculateTotalPrice() override;
    virtual void displayProductInfo() const {
        cout << left << setw(13) << id 
        << left << setw(20) << name.substr(0, 18)   
        << left << setw(10) << price
        << left << setw(10) << weight << " KG" 
        << left << setw(20) << displayFormattedDate(addDate)
        << left << setw(20) << displayFormattedDate(soldDate) << endl;
    }
};
class Oil : public Product {
protected:
    double volume; //in litres
public:
    Oil(int id, string name, double price)
        : Product(id, name, price), volume(volume) {}
    double calculateTotalPrice() override;
    void displayProductInfo() const;
};

