#include <iostream>
#include <string>
#include <chrono>
#include <random>
#include <iomanip>
#include "Product.h"

using std::string;
using std::cout;
using std::endl;
using std::setw;
using std::left;

/*main/base class definition or implementation*/
/*adding a stock, mainly by staff*/
void Product::addQuantity(int qty) {
    quantity = quantity - qty;
}
/*selling a stock, mainly by staff and self service*/
void Product::minusQuantity(int qty) {
    quantity = quantity - qty;
}
/*Basic product info*/
void Product::displayInfo() const {

    cout << left << setw(13) << id 
        << left << setw(20) << name.substr(0, 18)   
        << left << setw(10) << price 
        << left << setw(10) << quantity
        << left << setw(20) << displayFormattedDate(1)
        /*displayFormattedDate 1 for add date and 2 for sold date*/
        << left << setw(20) << displayFormattedDate(2) << endl;
}
string Product::displayFormattedDate(int type) const {

    long int timeStamp {0};

    if ( type == 1) {
        timeStamp = addDate;
    } else {
        timeStamp = soldDate;
    }

    // Convert the timestamp to a std::chrono::system_clock::time_point
    std::chrono::system_clock::time_point timePoint = std::chrono::system_clock::from_time_t(timeStamp);

    // Format the time using strftime
    std::time_t time = std::chrono::system_clock::to_time_t(timePoint);

    char buffer[80];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M", std::localtime(&time));

    if ( timeStamp < 1) {
        return "NA";
    } else {
        return buffer;
    }
}
int Product::getId() const {
    return id;
}
