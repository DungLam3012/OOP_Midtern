#include "animal.h"
#include <iostream>

Animal::Animal()
    :id("trong"), name("trong"), gender("trong"), birthYear(0), age(0) {}
Animal::Animal(const std::string& id, const std::string name, const std::string& gender, int birthYear, int age)
    :id(id), name(name), gender(gender), birthYear(birthYear), age(age) {}

//getter
std::string Animal::getId() const {return id;}
std::string Animal::getName() const {return name;}
std::string Animal::getGender() const {return gender;}
int Animal::getBirthYear() const {return birthYear;}
int Animal::getAge() const {return age;}

//setter
void Animal::setID(const std::string& id) {this->id = id;}
void Animal::setName(const std::string& name) {this->name = name;}
void Animal::setGender(const std::string& gender) {this->gender = gender;}
void Animal::setBirthYear(int birthYear) {this->birthYear = birthYear;}
void Animal::setAge(int age) {this->age = age;}

void Animal::printInfo() const{
    std::cout << "Id: " << id << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Gender: " << gender << std::endl;
    std::cout << "Birth Year: " << birthYear << std::endl;
    std::cout << "Age: " << age << std::endl;
}

Animal::~Animal() {}