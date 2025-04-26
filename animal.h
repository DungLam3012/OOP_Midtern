#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>

class Animal {
protected:
    std::string id;
    std::string name;
    std::string gender;
    int birthYear;
    int age;
public:
    Animal();
    Animal(const std::string& id, const std::string name, const std::string& gender, int birthYear, int age);

    //getter
    std::string getId() const;
    std::string getName() const;
    std::string getGender() const;
    int getBirthYear() const;
    int getAge() const;

    //setter
    void setID(const std::string& id);
    void setName(const std::string& name);
    void setGender(const std::string& gender);
    void setBirthYear(int birthYear);
    void setAge(int age);

    void printInfo() const;

    ~Animal();
};

#endif