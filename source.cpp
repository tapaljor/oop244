#include <iostream>
#include <string>
#include <vector>
#include "Product.cpp"
#include "utility.cpp"

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::left;

int main() {

    /*instantiation product with parameters to be used in constructor using vector, which is flexible*/
    vector <Product> products;

    while (true) {

        /*calling menu function*/
        menu();

        int choice;
        cin >> choice;

        if (choice == 1) {

            string name {};
            double price {0.0};
            int quantity {0};

            cout << "Enter product name: ";
            cin.ignore();
            getline(std::cin, name);
            cout << "Enter price: ";
            cin >> price;
            cout << "Enter quantity: ";
            cin >> quantity;

            /*dynamically adding an object to vector which has other objects*/
            products.push_back (Product (
                    name, 
                    generateRandomNumber(), 
                    price, 
                    quantity, 
                    generateCurrentTimeStamp(),
                    0
                ));

        } else if (choice == 2) {
            cout << "Enter product ID to track: ";
            int trackId;
            cin >> trackId;

            displayHeader();
            for (const Product& product : products) {
                if (product.getId() == trackId) {
                    product.displayInfo();
                    break;
                }
            }
            displayFooter();
        } else if (choice == 3) {
            displayHeader();
            for (const Product& product : products) {
                product.displayInfo();
            }
            displayFooter();
        } else if (choice == 4) {
            cout << "Exiting the program." << endl;
            break;
        } else {
            cout << "Invalid choice. Please select a valid option." << endl;
        }
    }
    return 0;
}