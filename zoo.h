#ifndef ZOO_H
#define ZOO_H

#include <vector>
#include "animal.h"
#include "cage.h"

class Zoo {
private:
    std::vector<Animal*> animals;
    std::vector<Cage*> cages;

public:
    Zoo();

    // Quản lý động vật
    void addAnimal(Animal* animal);
    void removeAnimalById(const std::string& id);
    void printAllAnimal() const;
    Animal* findAnimalById(const std::string& id) const;
    int getAnimalCount() const;

    // Quản lý chuồng
    void addCage(Cage* cage);
    void removeCageById(const std::string& cageId);
    void printAllCages() const;
    Cage* findCageById(const std::string& cageId) const;
    int getCageCount() const;

    // Thêm động vật vào chuồng
    void addAnimalToCage(const std::string& animalId, const std::string& cageId);

    ~Zoo();
};

#endif
