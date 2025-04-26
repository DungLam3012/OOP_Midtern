#include "cage.h"
#include <iostream>

Cage::Cage(const std::string& cageId, int capacity)
    : cageId(cageId), capacity(capacity) {}

std::string Cage::getCageId() const {
    return cageId;
}

bool Cage::isFull() const {
    return animals.size() >= capacity;
}

bool Cage::addAnimal(Animal* animal){
    if(isFull()){
        std::cout << "Chuong co id " << cageId << " day" << std::endl;
        return false;
    }
    animals.push_back(animal);
    std::cout << "Da them dong vat co ma so " << animal->getId() << " vao chuong!" << std::endl;
    return true;
}

void Cage::printAnimals() const {
    std::cout << "Cac dong vat trong chuong co ma so " << cageId << " la" << std::endl;
    for(const auto& animal : animals){
        animal->printInfo();
        std::cout << "----------------------" << std::endl;
    }
}

// Hàm printInfo sẽ in thông tin chi tiết về chuồng
void Cage::printInfo() const {
    std::cout << "Thong tin chuong:\n";
    std::cout << "Ma chuong: " << cageId << "\n";
    std::cout << "Dung luong: " << capacity << "\n";
    std::cout << "So dong vat hien co: " << animals.size() << "\n";
    if (animals.empty()) {
        std::cout << "Chuong hien tai khong co dong vat." << std::endl;
    } else {
        std::cout << "Cac dong vat trong chuong:" << std::endl;
        printAnimals();
    }
}
