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
