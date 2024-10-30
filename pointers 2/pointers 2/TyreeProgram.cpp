/*
Cameron Tyree
CIS 1202 101
Feb 2 2024
*/

#include "personalLibrary.h"

    int getMenuItem();
    void enterRents(float[], int&);
    void displayRents(float*, int);
    void displayMemoryLocations(float*, int);
    void selectionSort(float[], int);
    float sumRents(float*, int);

    int main() {

        const int SIZE = 5;
        float rentAmount[SIZE];
        int numberOfRents = 0;
        int userChoice;
        do {
            userChoice = getMenuItem();

            switch (userChoice) {
            case 1:
                enterRents(rentAmount, numberOfRents);
                break;
            case 2:
                displayRents(rentAmount, numberOfRents);
                break;
            case 3:
                selectionSort(rentAmount, numberOfRents);
                displayRents(rentAmount, numberOfRents);
                break;
            case 4:
                cout << sumRents(rentAmount, numberOfRents) << endl;
                break;
            case 5:
                displayMemoryLocations(rentAmount, numberOfRents);
                break;
            }
        } while (userChoice != 6);

        endProgram();
    }

    int getMenuItem() {
        int choice;
        cout << "Menu:" << endl;
        cout << "1. Enter rent amounts" << endl;
        cout << "2. Display rent amounts" << endl;
        cout << "3. Sort rent amounts from low to high" << endl;
        cout << "4. Total all of the rents" << endl;
        cout << "5. Display memory locations" << endl;
        cout << "6. Exit the program";
        choice = validateIntRange("Enter your choice: ", 1, 6);
        return choice;
    }
    void enterRents(float* rentAmount, int& numberOfRents) {

        for (int i = numberOfRents; i < 5; i++) {
            cout << "Enter rent amount " << numberOfRents + 1 << ": ";
            cin >> *(rentAmount + i);
            numberOfRents++;
        }
    }
    void displayRents(float* rentAmount, int numberOfRents) {
        cout << "Rents: " << endl;
        for (int i = 0; i < numberOfRents; i++) {
            cout << fixed << setprecision(2) << *(rentAmount + i) << endl;
        }
    }
    void selectionSort(float* rentAmount, int numberOfRents) {

        for (int i = 0; i < numberOfRents - 1; i++) {
            for (int j = 0; j < numberOfRents - i - 1; j++) {
                if (*(rentAmount + j) > *(rentAmount + j + 1)) {

                    float tempPrice = *(rentAmount + j);
                    *(rentAmount + j) = *(rentAmount + j + 1);
                    *(rentAmount + j + 1) = tempPrice;
                }
            }
        }
        cout << "Prices from low to high:" << endl;
    }
    void displayMemoryLocations(float* rentAmount, int numberOfRents) {
        cout << "Memory locations: " << endl;
        for (int i = 0; i < numberOfRents; i++) {
            cout << (rentAmount + i) << endl;
        }
    }
    float sumRents(float* rentAmount, int numberOfRents) {
        float sum = 0.0;
        cout << "Total rent: " << endl;
        for (int i = 0; i < numberOfRents; i++) {
            sum += *(rentAmount + i);
          
        }
        
        return sum;
    }
