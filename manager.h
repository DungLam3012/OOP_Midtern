#ifndef MANAGER_H
#define MANAGER_H

#include "user.h"
#include "zoo.h"

class Manager : public User {
public:
    Manager(const std::string& username, const std::string& password);

    // Quản lý động vật và chuồng
    void addAnimalToZoo(Zoo& zoo, Animal* animal);
    void removeAnimalFromZoo(Zoo& zoo, const std::string& animalId);
    void printAllAnimalsInZoo(const Zoo& zoo) const;
    void addCageToZoo(Zoo& zoo, Cage* cage);
    void removeCageFromZoo(Zoo& zoo, const std::string& cageId);
    void printAllCagesInZoo(const Zoo& zoo) const;
};

#endif
