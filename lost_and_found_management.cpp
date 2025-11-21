#include <iostream>
using namespace std;

class Item {
public:
    string name, category, location, date, contact;
    bool isLost; // true for lost, false for found
    
    void inputItem() {
        cout << "Enter item name: ";
        cin >> name;
        cout << "Enter category: ";
        cin >> category;
        cout << "Enter location: ";
        cin >> location;
        cout << "Enter date (DD/MM/YYYY): ";
        cin >> date;
        cout << "Enter contact number: ";
        cin >> contact;
    }
    
    bool matches(Item other) {
        return (name == other.name || category == other.category);
    }
    
    void display() {
        cout << "Name: " << name << ", Category: " << category
             << ", Location: " << location << ", Date: " << date << "\n";
    }
};

class LostAndFound {
    Item lostItems[10];
    Item foundItems[10];
    int lostCount = 0, foundCount = 0;
    
public:
    void reportLost() {
        if (lostCount >= 10) {
            cout << "Lost list is full!\n";
            return;
        }
        
        Item newItem;
        cout << "\nReport a Lost Item:\n";
        newItem.inputItem();
        
        // Check for matching item in found list
        for (int i = 0; i < foundCount; i++) {
            if (newItem.matches(foundItems[i])) {
                cout << "\nPotential Match Found in Found List!\n";
                foundItems[i].display();
                char choice;
                cout << "Do you want to contact the finder? (y/n): ";
                cin >> choice;
                if (choice == 'y' || choice == 'Y') {
                    cout << "Contact Finder at: " << foundItems[i].contact << "\n";
                }
            }
        }
        
        lostItems[lostCount++] = newItem;
        cout << "\nItem added to the lost list.\n";
    }
    
    void reportFound() {
        if (foundCount >= 10) {
            cout << "Found list is full!\n";
            return;
        }
        
        Item newItem;
        cout << "\nReport a Found Item:\n";
        newItem.inputItem();
        
        // Check for matching item in lost list
        for (int i = 0; i < lostCount; i++) {
            if (newItem.matches(lostItems[i])) {
                cout << "\nPotential Match Found in Lost List!\n";
                lostItems[i].display();
                char choice;
                cout << "Do you want to contact the owner? (y/n): ";
                cin >> choice;
                if (choice == 'y' || choice == 'Y') {
                    cout << "Contact Owner at: " << lostItems[i].contact << "\n";
                }
            }
        }
        
        foundItems[foundCount++] = newItem;
        cout << "\nItem added to the found list.\n";
    }
    
    void displayLists() {
        cout << "\nLost Items:\n";
        for (int i = 0; i < lostCount; i++) {
            lostItems[i].display();
            cout << "Contact: " << lostItems[i].contact << "\n";
        }
        
        cout << "\nFound Items:\n";
        for (int i = 0; i < foundCount; i++) {
            foundItems[i].display();
            cout << "Contact: " << foundItems[i].contact << "\n";
        }
    }
};

int main() {
    LostAndFound system;
    int choice;
    
    while (true) {
        cout << "\n1. Report Lost Item\n2. Report Found Item\n3. Display All Items\n4. Exit\nEnter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1: system.reportLost(); break;
            case 2: system.reportFound(); break;
            case 3: system.displayLists(); break;
            case 4: return 0;
            default: cout << "Invalid choice. Try again."; 
        }
    }
}
