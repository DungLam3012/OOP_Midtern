#include "manager.h"

Manager::Manager(const std::string& username, const std::string& password)
    : User(username, password, "manager") {}

void Manager::addAnimalToZoo(Zoo& zoo, Animal* animal) {
    zoo.addAnimal(animal);
}

void Manager::removeAnimalFromZoo(Zoo& zoo, const std::string& animalId) {
    zoo.removeAnimalById(animalId);
}

void Manager::printAllAnimalsInZoo(const Zoo& zoo) const {
    zoo.printAllAnimal();
}

void Manager::addCageToZoo(Zoo& zoo, Cage* cage) {
    zoo.addCage(cage);
}

void Manager::removeCageFromZoo(Zoo& zoo, const std::string& cageId) {
    zoo.removeCageById(cageId);
}

void Manager::printAllCagesInZoo(const Zoo& zoo) const {
    zoo.printAllCages();
}
