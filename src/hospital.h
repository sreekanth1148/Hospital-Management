#ifndef HOSPITAL_H
#define HOSPITAL_H

#include <iostream>
#include <fstream>

class Patient {
public:
    std::string name, disease;
    int age, id;
    Patient* next;

    Patient(std::string n, int a, std::string d, int i);
};

class Hospital {
private:
    Patient* head;

public:
    Hospital();
    void addPatient(std::string name, int age, std::string disease, int id);
    void displayPatients();
    void deletePatient(int id);
    void saveToFile();
    void loadFromFile();
};

#endif
