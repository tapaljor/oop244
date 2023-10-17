#include <iostream>
#include <string>

using std::string;
using std::cout;

/*main/base class for grocery management*/
class Product {
private:
    int id;
    string name;
    double price;
    int quantity;
    long int addDate;
    long int soldDate;
public:
    /*constructor and initializing the private data members attribute*/
    Product(string name, int id, double price, int quantity, long int addDate, long int soldDate)
        :name(name), id(id), price(price), quantity(quantity), addDate(addDate), soldDate(soldDate) { }
    /*object destructor*/
    ~Product () {
        //cout << "Destroyer doing its thing..";
    }
    /*adding a stock*/
    void addQuantity(int qty);
    /*selling a stock*/
    void minusQuantity(int qty);
    /*getting ID*/
    int getId() const;
    /*Basic product info*/
    void displayInfo() const;
    /*displaying timestamp in readable date time*/
    string displayFormattedDate(int type) const;
};