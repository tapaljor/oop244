#include <iostream>
#include <chrono>
#include <random>
#include <iomanip>
#include <cctype>

// Rather than using the entire namespace, specify using declarations for individual entities.
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::left;
using std::setw;
using std::to_string;

// Utility functions and data are encapsulated in a class for better organization and encapsulation.
class Utils {
public:
    static void displayHeader() {
        cout << endl << "Product Report:" << endl;
        cout << string(80, '-') << endl;
        cout << left << setw(14) << "ID"
             << left << setw(20) << "Name"
             << left << setw(10) << "Total"
             << left << setw(4)  << "Sh"
             << left << setw(6) << "Qty" 
             << left << setw(5) << "Unit"
             << left << setw(6) << "Sale" 
             << left << setw(15) << "Avai" << endl;
        cout << string(80, '-') << endl;
    }
    static void displayFooter() {
        cout << string(80, '-') << endl;
    }
    static void menu() {
        cout << string(30, '-') << endl;
        cout << "MENU" << endl;
        cout << string(30, '-') << endl;
        cout << "1. Add Vegetable" << endl
             << "2. Add Fruit" << endl
             << "12. View All" << endl
             << "13. View Detail" << endl
             << "14. Generate Expired Product" << endl
             << "15. Edit Data" << endl
             << "16. Delete Data" << endl
             << "17. Add Sales" << endl
             << "22. Exit" << endl;
        cout << string(30, '-') << endl;
    }
      /*displaying timestamp in readable date time*/
    string displayFormattedDate(long int const timeStamp) const {

        // Convert the timestamp to a chrono::system_clock::time_point
        std::chrono::system_clock::time_point timePoint = std::chrono::system_clock::from_time_t(timeStamp);

        // Format the time using strftime
        std::time_t time = std::chrono::system_clock::to_time_t(timePoint);

        char buffer[80];
        strftime(buffer, sizeof(buffer), "%Y-%m-%d", std::localtime(&time));

        return timeStamp < 1 ? "NA" : buffer;
    }
    /*random number generator*/
    static long generateRandomNumber() {
        /*get unique timestamp*/
        auto now = std::chrono::system_clock::now();
        std::time_t timestamp = std::chrono::system_clock::to_time_t(now);
    
        /*std::random_device rd;
        std::mt19937 gen(rd());

        std::uniform_int_distribution<int> distribution(100, 500); 
        int randomNum = distribution(gen);

        /*add timestamp and random number to make make duplicate-free*/
        return timestamp;
        // / randomNum;
    }
    /*current timestamp generator*/
    static long int generateCurrentTimeStamp() {
        /*get unique timestamp*/
        auto now = std::chrono::system_clock::now();
        std::time_t timestamp = std::chrono::system_clock::to_time_t(now);
    
        return timestamp;
    }
    bool checkDate(int year, int month, int day) {
        if (year < getCurrentYear() || year > 2100) {
            cout << "Year incorrect" << endl;
            return false;
        }
        if (month < 1 || month > 12) {
            cout << "Month incorrect" << endl;
            return false;
        }
        if (day < 1 || day > 31) {
            cout << "Day incorrect" << endl; 
            return false; 
        }
        return true;
    }
    int getCurrentYear() {
        auto now = std::chrono::system_clock::now();
        auto currentTime = std::chrono::system_clock::to_time_t(now);
        tm* localTime = std::localtime(&currentTime);
        return 1900 + localTime->tm_year;
    }
    long convertDateToTimestamp(const std::string& date) {
        std::tm tm = {};
        std::istringstream ss(date);

        // Use std::get_time to parse the date string into a std::tm object
        ss >> std::get_time(&tm, "%Y-%m-%d");

        // Check if the date is valid
        if(ss.fail()) {
            std::cerr << "Failed to parse date: " << date << std::endl;
            return -1;
        }

        // Convert tm to time_t and then to a timestamp
        time_t time = mktime(&tm);
        return static_cast<long>(time);
    }
    /*checking value n is valid or not*/
    bool validateInput() {
        
        if (cin.fail() || cin.peek() != '\n') {
            cin.clear();            // Clear the error state
            cin.ignore(1000, '\n'); // Ignore the rest of the input line
            return false;
        }
        return true;
    }
};
