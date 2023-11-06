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
#include <algorithm>
#include "Product.h"

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::left;
using std::unique_ptr;
using std::make_unique;
using std::string;
using std::move;

int main() {

    Utils* u;

    /*initializeing base class as pointer*/
    vector<unique_ptr<Product>> products;
    /*different class for sale of product*/
    vector< unique_ptr<saleProduct>> sales;

    /*temporary data populating*/
    for(size_t a = 0; a<5; a++) {
        products.push_back(make_unique<Vegetable>(a*2, "veg"+std::to_string(a), 2, 2, u->generateCurrentTimeStamp(), 23434, a+2.5));
        products.push_back(make_unique<Fruit>(a*5, "fruit"+to_string(a), a+2, a+4, u->generateCurrentTimeStamp(), 2374783,a+1.1));
    }

    while (true) {
        
        u->menu();

        int choice;
        do {
            cout << "Enter your choice (number only): ";
            cin >> choice;
        } while ( !u->validateInput());

        switch (choice) {
            case 1: {
                unique_ptr<Vegetable> veg = make_unique<Vegetable>();
                veg->addProduct();
                products.push_back(move(veg));
                break;
            }
            case 2: {
                unique_ptr<Fruit> fruit = make_unique<Fruit>();
                fruit->addProduct();
                products.push_back(move(fruit));
                break;
            }
            case 12: {
                double totalSale = 0.0;
                u->displayHeader();
                for (const unique_ptr<Product>& product : products) { 
                    product->displayProductInfo();
                    
                    for (const unique_ptr<saleProduct>& sale: sales) {
                        if ( product->getId() == sale->getId()) 
                            totalSale += sale->getQuantity(); //getting all sales
                    }
                    cout << left << setw(6) << totalSale;
                    cout << left << setw(6) << product->getQuantity() - totalSale;
                    cout << endl;
                }
                u->displayFooter();
                break;
            }
            case 13: {
                int counter = 0;
                int id = 0;
                double totalSale = 0.0;
                do {
                    cout << "Enter ID number (number only): ";
                    cin >> id;
                } while( !u->validateInput());
                
                cout << "------DETAIL--" << endl;
                for (const unique_ptr<Product>& product : products) {
                    if (id == product->getId()) {
                        cout << "ID: " << product->getId() << endl;
                        cout << "Name: " << product->getName() << endl;
                        cout << "Price: $" << product->getPrice() << endl;
                        cout << "Shelf: " << product->getShelf() << endl;
                        cout << "Add Date: " << u->displayFormattedDate(product->getAddDate()) << endl;
                        cout << "Expirty Date: " << u->displayFormattedDate(product->getExpiryDate()) << endl;
                        cout << "Qty: " << product->getQuantity() << endl;
                        for(const unique_ptr<saleProduct>& sale : sales) {
                            if ( id == sale->getId()) {
                                cout << "Sale Qty: " << sale->getQuantity() << endl;
                                cout << "Sold Date: " << u->displayFormattedDate(sale->getSoldDate()) << endl;
                                totalSale += sale->getQuantity();
                            }
                        }
                        cout << "Total stock left: " << product->getQuantity() - totalSale << endl;
                        counter++;
                        break;
                    } 
                }
                if (counter == 0) 
                    cout << "Record not found" << endl;
                break;
            }
            case 14: {
                u->displayHeader();
                for (const unique_ptr<Product>& product : products) {
                    if (u->generateCurrentTimeStamp() > product->getExpiryDate()) 
                        product->displayProductInfo();
                    cout << endl;
                }
                u->displayFooter();
                break;
            }
            case 15: {
                int counter = 0;
                int id = 0;
                do {
                    cout << "Enter ID number you want to edit: ";
                    cin >> id;
                } while( !u->validateInput());
                
                for (const unique_ptr<Product>& product : products) {
                    if (id == product->getId()) {
                        /*edits that prticular object, thanks to polymorphism*/
                        product->editProduct();
                        counter++;
                    } 
                }
                if (counter == 0) 
                    cout << "Record not found" << endl;
                break;
            }
            case 16: {
                int id = 0;
                do {
                    cout << "Enter ID number you want to delete: ";
                    cin >> id;
                } while( !u->validateInput());

                auto it = std::remove_if (
                    products.begin(), products.end(), [id] 
                    (const unique_ptr<Product>& product) {
                        return product->getId() == id;
                    }
                    );
                products.erase(it, products.end());
                break;
            }
            case 17: {
                int id = 0;
                double qty = 0.0;
                do {
                    cout << "Enter ID of product: ";
                    cin >> id;
                } while( !u->validateInput());

                for (const unique_ptr<Product>& product : products) {
                    if (id == product->getId()) {
                        do {
                            cout << "Enter the quantity: ";
                            cin >> qty; 
                        } while ( !u->validateInput());
                        sales.push_back( make_unique<saleProduct> (id, qty, u->generateCurrentTimeStamp()));
                    } 
                }
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
