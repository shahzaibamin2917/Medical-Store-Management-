#include <iostream>
#include <cstdlib>   // For system("pause")

using namespace std;

// ================= MEDICINE CLASS =================
class Medicine {
public:
    int id;
    string name;
    int price;
    int quantity;

    // Function to input medicine data
    void input() {

        cout << "Enter Medicine ID: ";
        cin >> id;

        cout << "Enter Medicine Name: ";
        cin >> name;

        cout << "Enter Medicine Price: ";
        cin >> price;

        cout << "Enter Medicine Quantity: ";
        cin >> quantity;
    }

    // Function to display medicine
    void show() {

        cout << "\nID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Price: " << price << endl;
        cout << "Quantity: " << quantity << endl;
    }
};

// ================= ADMIN CLASS =================
class Admin {
public:

    string username = "admin";
    string password = "123";

    // Login Function
    bool login(string u, string p) {

        return (u == username && p == password);
    }
};

// ================= CUSTOMER CLASS =================
class Customer {
public:

    string customerName;

    // Function to buy medicine
    void buyMedicine(Medicine &m) {

        int buyQty;

        cout << "Enter Quantity to Buy: ";
        cin >> buyQty;

        // Check stock
        if (m.quantity >= buyQty) {

            // Reduce stock
            m.quantity = m.quantity - buyQty;

            // Calculate bill
            int total = buyQty * m.price;

            // Invoice
            cout << "\n===== INVOICE =====\n";

            cout << "Customer Name: "
                 << customerName << endl;

            cout << "Medicine: "
                 << m.name << endl;

            cout << "Quantity: "
                 << buyQty << endl;

            cout << "Price Per Item: "
                 << m.price << endl;

            cout << "Total Bill: "
                 << total << endl;
        }

        else {

            cout << "Out of Stock!\n";
        }
    }
};

// ================= MAIN FUNCTION =================
int main() {

    // Array to store medicines
    Medicine med[5];

    // Objects
    Admin a;
    Customer c;

    // Variables
    int count = 0;
    int mainChoice;

    // Main Menu Loop
    do {

        cout << "\n========== MEDICAL STORE MANAGEMENT SYSTEM ==========\n";

        cout << "1. Admin Login\n";
        cout << "2. Customer Mode\n";
        cout << "3. Exit\n";

        cout << "Enter Choice: ";
        cin >> mainChoice;

        // ================= ADMIN MODE =================
        if (mainChoice == 1) {

            string u, p;

            cout << "\nEnter Username: ";
            cin >> u;

            cout << "Enter Password: ";
            cin >> p;

            // Login Check
            if (a.login(u, p)) {

                cout << "\nLogin Successful!\n";

                int adminChoice;

                do {

                    cout << "\n===== ADMIN MENU =====\n";

                    cout << "1. Add Medicine\n";
                    cout << "2. View Stock\n";
                    cout << "3. Remove Medicine\n";
                    cout << "4. Logout\n";

                    cout << "Enter Choice: ";
                    cin >> adminChoice;

                    // Add Medicine
                    if (adminChoice == 1) {

                        med[count].input();

                        count++;

                        cout << "Medicine Added Successfully!\n";
                    }

                    // View Stock
                    else if (adminChoice == 2) {

                        cout << "\n===== MEDICINE STOCK =====\n";

                        for (int i = 0; i < count; i++) {

                            med[i].show();
                        }
                    }

                    // Remove Medicine
                    else if (adminChoice == 3) {

                        int removeId;

                        cout << "Enter Medicine ID to Remove: ";
                        cin >> removeId;

                        for (int i = 0; i < count; i++) {

                            if (med[i].id == removeId) {

                                med[i].name = "Removed";
                                med[i].price = 0;
                                med[i].quantity = 0;

                                cout << "Medicine Removed!\n";
                            }
                        }
                    }

                } while (adminChoice != 4);
            }

            else {

                cout << "Access Denied!\n";
            }
        }

        // ================= CUSTOMER MODE =================
        else if (mainChoice == 2) {

            int searchId;
            bool found = false;

            cout << "\nEnter Customer Name: ";
            cin >> c.customerName;

            cout << "Enter Medicine ID: ";
            cin >> searchId;

            // Search Medicine
            for (int i = 0; i < count; i++) {

                if (med[i].id == searchId &&
                    med[i].name != "Removed") {

                    found = true;

                    // Show medicine
                    med[i].show();

                    // Buy medicine
                    c.buyMedicine(med[i]);
                }
            }

            // Medicine not found
            if (!found) {

                cout << "Medicine Not Found!\n";
            }
        }

        // ================= EXIT =================
        else if (mainChoice == 3) {

            cout << "\nProgram Closed Successfully!\n";
        }

        else {

            cout << "Invalid Choice!\n";
        }

    } while (mainChoice != 3);

    // Pause screen before closing
    system("pause");

    return 0;
}