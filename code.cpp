#include <iostream>
#include <fstream>
#include <limits>
using namespace std;

class Transport {
private:
    string customerName;
    double distance;
    double ratePerKm;
    double loadWeight;
    double totalBill;
    string paymentStatus;

public:
    void inputDetails() {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "\nEnter Customer Name: ";
        getline(cin, customerName);

        cout << "Enter Distance (in km): ";
        cin >> distance;

        cout << "Enter Rate per km: ";
        cin >> ratePerKm;

        cout << "Enter Load Weight (in tons): ";
        cin >> loadWeight;

        calculateBill();
        paymentStatus = "Pending";
    }

    void calculateBill() {
        double weightCharge = loadWeight * 50;
        totalBill = (distance * ratePerKm) + weightCharge;
    }

    void generateInvoice() {
        cout << "\n=========== TRANSPORT INVOICE ===========\n";
        cout << "Customer Name  : " << customerName << endl;
        cout << "Distance       : " << distance << " km" << endl;
        cout << "Rate per km    : Rs. " << ratePerKm << endl;
        cout << "Load Weight    : " << loadWeight << " tons" << endl;
        cout << "-----------------------------------------\n";
        cout << "Total Bill     : Rs. " << totalBill << endl;
        cout << "Payment Status : " << paymentStatus << endl;
        cout << "=========================================\n";
    }

    void makePayment() {
        paymentStatus = "Paid";
        cout << "\nPayment marked as PAID successfully.\n";
    }

    void saveToFile() {
        ofstream file("billing_records.txt", ios::app);

        if (file.is_open()) {
            file << "Customer Name: " << customerName << endl;
            file << "Distance: " << distance << " km" << endl;
            file << "Rate per km: " << ratePerKm << endl;
            file << "Load Weight: " << loadWeight << " tons" << endl;
            file << "Total Bill: Rs. " << totalBill << endl;
            file << "Payment Status: " << paymentStatus << endl;
            file << "--------------------------------------\n";
            file.close();
        } else {
            cout << "Error opening file!\n";
        }
    }
};

int main() {
    Transport t;
    int choice;

    do {
        cout << "\n===== Transport Billing & Invoice System =====\n";
        cout << "1. Enter Billing Details\n";
        cout << "2. Generate Invoice\n";
        cout << "3. Make Payment\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                t.inputDetails();
                t.saveToFile();
                break;

            case 2:
                t.generateInvoice();
                break;

            case 3:
                t.makePayment();
                break;

            case 4:
                cout << "Exiting system...\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }

    } while(choice != 4);

    return 0;
}