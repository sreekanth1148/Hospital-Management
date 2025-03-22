#include "hospital.h"

Patient::Patient(std::string n, int a, std::string d, int i) {
    name = n;
    age = a;
    disease = d;
    id = i;
    next = NULL;
}

Hospital::Hospital() { head = NULL; }

void Hospital::addPatient(std::string name, int age, std::string disease, int id) {
    Patient* newPatient = new Patient(name, age, disease, id);
    if (!head) {
        head = newPatient;
    } else {
        Patient* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newPatient;
    }
    saveToFile();
    std::cout << "Patient added successfully!\n";
}

void Hospital::displayPatients() {
    if (!head) {
        std::cout << "No patients admitted.\n";
        return;
    }
    Patient* temp = head;
    while (temp) {
        std::cout << "ID: " << temp->id << " | Name: " << temp->name << " | Age: " << temp->age << " | Disease: " << temp->disease << std::endl;
        temp = temp->next;
    }
}

void Hospital::deletePatient(int id) {
    if (!head) {
        std::cout << "No patients found.\n";
        return;
    }
    Patient *temp = head, *prev = NULL;

    if (temp->id == id) {
        head = temp->next;
        delete temp;
        saveToFile();
        std::cout << "Patient removed.\n";
        return;
    }

    while (temp && temp->id != id) {
        prev = temp;
        temp = temp->next;
    }

    if (!temp) {
        std::cout << "Patient ID not found.\n";
        return;
    }

    prev->next = temp->next;
    delete temp;
    saveToFile();
    std::cout << "Patient removed successfully.\n";
}

void Hospital::saveToFile() {
    std::ofstream file("../data/patients.txt");
    Patient* temp = head;
    while (temp) {
        file << temp->id << " " << temp->name << " " << temp->age << " " << temp->disease << std::endl;
        temp = temp->next;
    }
    file.close();
}

void Hospital::loadFromFile() {
    std::ifstream file("../data/patients.txt");
    std::string name, disease;
    int id, age;
    while (file >> id >> name >> age >> disease) {
        addPatient(name, age, disease, id);
    }
    file.close();
}
