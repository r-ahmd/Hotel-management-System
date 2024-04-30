#include <bits/stdc++.h>
//#include <string>
#include <queue>

using namespace std;

//Node for Customer
struct Customer {
    int id;
    string name;
    int bookedRoomNumber; // Room number assigned to the customer
    Customer* next;

    Customer(int _id, const string& _name) : id(_id), name(_name), bookedRoomNumber(-1), next(nullptr) {}
};

// Function to insert a customer and assign the next available room
void insertCustomer(Customer*& head, int id, const string& name, queue<int>& availableRooms) {
    Customer* newCustomer = new Customer(id, name);

    if (head == nullptr) {
        head = newCustomer;
    } else {
        Customer* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newCustomer;
    }

    // Assign the next available room to the customer
    if (!availableRooms.empty()) {
        newCustomer->bookedRoomNumber = availableRooms.front();
        availableRooms.pop();
    }
}

// Function to delete a customer's booking and make the room available
void deleteBooking(Customer*& head, int id, queue<int>& availableRooms) {
    Customer* current = head;
    while (current != nullptr) {
        if (current->id == id && current->bookedRoomNumber != -1) {
            int roomNumber = current->bookedRoomNumber;
            current->bookedRoomNumber = -1; // Mark as deleted
            availableRooms.push(roomNumber); // Add the room back to available rooms
            return;
        }
        current = current->next;
    }
}

// Function to display customers with their booked rooms
void showCustomers(Customer* head) {
    if (head == nullptr) {
        cout << "No customers." << endl;
        return;
    }
    cout << "Customer Information:" << endl;
    while (head != nullptr) {
        if (head->bookedRoomNumber != -1) { // Ignore deleted customers
            cout << "Customer ID: " << head->id << ", Name: " << head->name << ", Booked Room: " << head->bookedRoomNumber << endl;
        }
        head = head->next;
    }
}

// Function to display available rooms
void showAvailableRooms(const queue<int>& availableRooms) {
    cout << "Available Rooms:" << endl;
    queue<int> tempRooms = availableRooms;
    while (!tempRooms.empty()) {
        cout << "Room Number: " << tempRooms.front() << endl;
        tempRooms.pop();
    }
}

int main() {
    Customer* customers = nullptr;
    queue<int> availableRooms;
    for (int roomNumber = 101; roomNumber <= 110; ++roomNumber) {
        availableRooms.push(roomNumber); // Initialize available rooms from 101 to 110
    }

    int choice, id;
    string name;

    while (true) {
        cout << "\nHotel Management System" << endl;
        cout << "1. Insert Customer" << endl;
        cout << "2. Delete Customer Booking" << endl;
        cout << "3. Show Customers" << endl;
        cout << "4. Show Available Rooms" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Customer ID: ";
                cin >> id;
                cout << "Enter Customer Name: ";
                cin >> name;
                insertCustomer(customers, id, name, availableRooms);
                cout << "Customer inserted." << endl;
                break;
            case 2:
                cout << "Enter Customer ID to Delete Booking: ";
                cin >> id;
                deleteBooking(customers, id, availableRooms);
                break;
            case 3:
                showCustomers(customers);
                break;
            case 4:
                showAvailableRooms(availableRooms);
                break;
            case 5:
                // Free memory and exit
                while (customers != nullptr) {
                    Customer* temp = customers;
                    customers = customers->next;
                    delete temp;
                }
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}


//-----------By TechTitans----------
