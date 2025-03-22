#include "hospital.h"

int main() {
    Hospital hospital;
    hospital.loadFromFile();

    int choice, age, id;
    std::string name, disease;

    while (true) {
        std::cout << "\n--- Hospital Management System ---\n";
        std::cout << "1. Add Patient\n2. View Patients\n3. Delete Patient\n4. Exit\nEnter choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter Name: "; std::cin >> name;
                std::cout << "Enter Age: "; std::cin >> age;
                std::cout << "Enter Disease: "; std::cin >> disease;
                std::cout << "Enter ID: "; std::cin >> id;
                hospital.addPatient(name, age, disease, id);
                break;
            case 2:
                hospital.displayPatients();
                break;
            case 3:
                std::cout << "Enter Patient ID to Delete: "; std::cin >> id;
                hospital.deletePatient(id);
                break;
            case 4:
                std::cout << "Exiting system...\n";
                return 0;
            default:
                std::cout << "Invalid choice! Try again.\n";
        }
    }
}
