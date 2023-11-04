/*
Assignment: Grocery Management
Group number: 3
- Kartik Jindal
- Meg Smith
- Sheba Birhanu
- Tashi Paljor
Course: OOP244V1A
*/
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "Product.h"

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::left;
using std::unique_ptr;
using std::make_unique;
using std::string;

int main() {

    Utils* u;
    /*initializeing base class as pointer*/
    vector<unique_ptr<Product>> products;

    while (true) {
        
        u->menu();

        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                unique_ptr<Vegetable> veg = make_unique<Vegetable>();
                veg->addProduct();
                products.push_back(std::move(veg));
                break;
            }
            case 2: {
                unique_ptr<Fruit> fruit = make_unique<Fruit>();
                fruit->addProduct();
                products.push_back(std::move(fruit));
                break;
            }
            case 13: {
                u->displayHeader();
                for (const unique_ptr<Product>& product : products) {
                    product->displayProductInfo();
                }
                u->displayFooter();
                break;
            }
            case 14: {
                u->displayHeader();
                for (const unique_ptr<Product>& product : products) {
                    if (u->generateCurrentTimeStamp() > product->getExpiryDate()) {
                        product->displayProductInfo();
                    } 
                }
                u->displayFooter();
                break;
            }
            case 15: {
                int id = 0;
                do {
                    cout << "Enter ID number you want to search: ";
                    cin >> id;
                } while( !u->validateInput());
                
                for (const unique_ptr<Product>& product : products) {
                    if (id == product->getId()) {
                        /*edits that prticular object, thanks to polymorphism*/
                        product->editProduct();
                    } 
                }
                u->displayFooter();
                break;
            }
            case 22: {
                /*destroying objects when program is finished*/
                cout << "Exiting the program..." << endl;
                products.clear();
                return 0;
            }
            default:
                cout << "Invalid choice. Please select a valid option." << endl;
                break;
        }
    }
}
