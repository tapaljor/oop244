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
void displayTimeFromTimeStamp(long int timestampInSeconds) {

    // Convert the timestamp to a std::chrono::system_clock::time_point
    std::chrono::system_clock::time_point timePoint = std::chrono::system_clock::from_time_t(timestampInSeconds);

    // Format the time using strftime
    std::time_t time = std::chrono::system_clock::to_time_t(timePoint);
    char buffer[80];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", std::localtime(&time));

    std::cout << "Formatted date and time: " << buffer << std::endl;
}
