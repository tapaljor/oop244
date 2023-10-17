#include <iostream>
#include <chrono>
#include <random>
#include "utility.h"

/*random number generator*/
int generateRandomNumber() {
    /*get unique timestamp*/
    auto now = std::chrono::system_clock::now();
    std::time_t timestamp = std::chrono::system_clock::to_time_t(now);
    
    std::random_device rd;
    std::mt19937 gen(rd());

    // generate random no further 1-100
    std::uniform_int_distribution<int> distribution(1, 100); 
    int randomNum = distribution(gen);

    /*add timestamp and random number to make make duplicate-free*/
    return timestamp + randomNum;
}
/*current timestamp generator*/
int generateCurrentTimeStamp() {
    /*get unique timestamp*/
    auto now = std::chrono::system_clock::now();
    std::time_t timestamp = std::chrono::system_clock::to_time_t(now);
    
    return timestamp;
}
void menu() {
    cout << "Menu:" << endl;
    cout << "1. Add Product" << endl;
    cout << "2. Track Product" << endl;
    cout << "3. Generate Report" << endl;
    cout << "4. Exit" << endl;
    cout << "Enter your choice: ";
}
void displayHeader() {
    cout << endl << "Product Report:" << endl;
    cout << "----------------------------------------------------------------------------------" << endl;
    cout << left << setw(13) << "ID" 
    << left << setw(20) << "Product Name" 
    << left << setw(10) << "Price" 
    << left << setw(10) << "Qty" 
    << left << setw(20) << "Add Date" 
    << left << setw(20) << "Sold Date" << endl;
    cout << "----------------------------------------------------------------------------------" << endl;
}
void displayFooter() {
    cout << "----------------------------------------------------------------------------------" << endl;
}

