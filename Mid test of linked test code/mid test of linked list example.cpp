#include <iostream>
#include <string>

// Definition of a Node representing a contact
struct Contact {
    std::string name;
    std::string phoneNumber;
    Contact* next;

    Contact(std::string contactName, std::string phone)
        : name(contactName), phoneNumber(phone), next(nullptr) {}
};

// Class representing a Contact List
class ContactList {
public:
    ContactList() : head(nullptr) {}

    // Function to add a new contact to the list
    void addContact(std::string contactName, std::string phoneNumber) {
        Contact* newContact = new Contact(contactName, phoneNumber);
        newContact->next = head;
        head = newContact;
    }

    // Function to display all contacts in the list
    void displayContacts() {
        Contact* current = head;
        while (current != nullptr) {
            std::cout << "Name: " << current->name << ", Phone: " << current->phoneNumber << std::endl;
            current = current->next;
        }
        std::cout << std::endl;
    }

    // Destructor to release dynamically allocated memory
    ~ContactList() {
        Contact* current = head;
        while (current != nullptr) {
            Contact* next = current->next;
            delete current;
            current = next;
        }
    }

private:
    Contact* head;
};

int main() {
    ContactList contacts;

    char choice;
    do {
        std::string name, phone;
        std::cout << "Enter contact name: ";
        std::cin >> name;

        std::cout << "Enter contact phone number: ";
        std::cin >> phone;

        contacts.addContact(name, phone);

        std::cout << "Do you want to add another contact? (y/n): ";
        std::cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    // Displaying contacts
    std::cout << "Contact List:" << std::endl;
    contacts.displayContacts();

    // Destructor is automatically called when 'contacts' goes out of scope
    //linked list

    return 0;
}
