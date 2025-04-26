#include "guest.h"
#include <iostream>

Guest::Guest() : User("", "", "guest") {}

void Guest::printAllAnimalsInZoo(const Zoo& zoo) const {
    zoo.printAllAnimal();
}

void Guest::printAllCagesInZoo(const Zoo& zoo) const {
    zoo.printAllCages();
}
