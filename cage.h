#ifndef CAGE_H
#define CAGE_H

#include <string>
#include <vector>
#include "animal.h"

class Cage {
private:
    std::string cageId;
    int capacity;
    std::vector<Animal*> animals;

public:
    Cage(const std::string& cageId, int capacity);

    std::string getCageId() const;
    bool isFull() const;
    bool addAnimal(Animal* animal);
    void printAnimals() const;

    // Thêm phương thức printInfo để in thông tin chuồng
    void printInfo() const;
};

#endif
