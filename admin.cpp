#include "admin.h"
#include <iostream>

Admin::Admin(const std::string& username, const std::string& password)
    : User(username, password, "admin") {}

void Admin::createManagerAccount(std::vector<User*>& users, const std::string& username, const std::string& password) {
    for (const auto& user : users) {
        if (user->getUsername() == username) {
            std::cout << "Username da ton tai.\n";
            return;
        }
    }    
    User* manager = new Manager(username, password); // tạo Manager thay vì User
    users.push_back(manager);
    std::cout << "Tai khoan quan li duoc tao: " << username << std::endl;
}

void Admin::viewAllAccounts(const std::vector<User*>& users) const {
    std::cout << "\nTat ca tai khoan:\n";
    for (const auto& user : users) {
        user->printInfo();
    }
}

void Admin::changeUserPassword(std::vector<User*>& users, const std::string& username, const std::string& newPassword) {
    for (auto& user : users) {
        if (user->getUsername() == username) {
            user->setPassword(newPassword);
            std::cout << "Mat khau duoc cap nhat cho " << username << ".\n";
            return;
        }
    }
    std::cout << "Khong tim thay nguoi dung.\n";
}

void Admin::addAnimalToZoo(Zoo& zoo, Animal* animal) {
    zoo.addAnimal(animal);
}

void Admin::removeAnimalFromZoo(Zoo& zoo, const std::string& animalId) {
    zoo.removeAnimalById(animalId);
}

void Admin::printAllAnimalsInZoo(const Zoo& zoo) const {
    zoo.printAllAnimal();
}

void Admin::addCageToZoo(Zoo& zoo, Cage* cage) {
    zoo.addCage(cage);
}

void Admin::removeCageFromZoo(Zoo& zoo, const std::string& cageId) {
    zoo.removeCageById(cageId);
}

void Admin::printAllCagesInZoo(const Zoo& zoo) const {
    zoo.printAllCages();
}
