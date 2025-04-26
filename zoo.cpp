#include "zoo.h"
#include <iostream>

Zoo::Zoo() {}

void Zoo::addAnimal(Animal* animal){
    animals.push_back(animal);
    std::cout << "Them mot con vat voi ID: " << animal->getId() << std::endl;
}

void Zoo::removeAnimalById(const std::string& id) {
    for (auto it = animals.begin(); it != animals.end(); ++it) {
        if ((*it)->getId() == id) {
            delete *it; // Giải phóng bộ nhớ
            animals.erase(it);
            std::cout << "Da xoa dong vat co ID: " << id << std::endl;
            return;
        }
    }
    std::cout << "Khong tim thay dong vat voi ID: " << id << std::endl;
}

void Zoo::printAllAnimal() const {
    std::cout << "Tat ca cac con vat trong so thu" << std::endl;
    for(const auto& animal : animals){
        animal->printInfo();
        std::cout << "----------------------" << std::endl;
    }
}

Animal* Zoo::findAnimalById(const std::string& id) const {
    for (const auto& animal : animals){
        if (animal->getId() == id){
            return animal;
        }
    }
    return nullptr;
}

int Zoo::getAnimalCount() const {
    return animals.size();
}

void Zoo::addCage(Cage* cage){
    cages.push_back(cage);
    std::cout << "Them thanh cong chuong voi id " << cage->getCageId() << std::endl;
}

Cage* Zoo::findCageById(const std::string& cageId) const{
    for(const auto& cage : cages){
        if(cage->getCageId() == cageId){
            return cage;
        }
    }
    return nullptr;
}

int Zoo::getCageCount() const {
    return cages.size();
}

void Zoo::removeCageById(const std::string& cageId) {
    for (auto it = cages.begin(); it != cages.end(); ++it) {
        if ((*it)->getCageId() == cageId) {
            delete *it;
            cages.erase(it);
            std::cout << "Da xoa chuong co ID: " << cageId << std::endl;
            return;
        }
    }
    std::cout << "Khong tim thay chuong co ID: " << cageId << std::endl;
}

void Zoo::addAnimalToCage(const std::string& animalId, const std::string& cageId){
    Animal* animal = findAnimalById(animalId);
    if (!animal) {
        std::cout << "Khong tim thay dong vat!" << std::endl;
        return;
    }
    Cage* cage = findCageById(cageId);
    if (!cage) {
        std::cout << "Khong tim thay chuong!" << std::endl;
        return;
    }
    cage->addAnimal(animal);
}

void Zoo::printAllCages() const {
    std::cout << "Tat ca cac chuong trong so thu" << std::endl;
    for (const auto& cage : cages) {
        cage->printInfo();
        std::cout << "----------------------" << std::endl;
    }
}

Zoo::~Zoo() {
    for (auto animal : animals){
        delete animal;
    }
    animals.clear();

    for (auto cage : cages) {
        delete cage;
    }
    cages.clear();
}
