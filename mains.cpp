#include <iostream>
#include "animal.h"
#include "cage.h"
#include "zoo.h"

void showMenu() {
    std::cout << "\n===== MENU =====\n";
    std::cout << "1. Them dong vat\n";
    std::cout << "2. Xoa dong vat theo ID\n";
    std::cout << "3. Tim dong vat theo ID\n";
    std::cout << "4. Hien thi tat ca dong vat\n";
    std::cout << "5. Them chuong\n";
    std::cout << "6. Hien thi dong vat trong chuong\n";
    std::cout << "7. Them dong vat vao chuong\n";
    std::cout << "0. Thoat\n";
    std::cout << "================\n";
    std::cout << "Chon chuc nang: ";
}

int main() {
    Zoo zoo;
    int choice;

    do {
        showMenu();
        std::cin >> choice;
        std::cin.ignore(); // Xóa '\n'

        if (choice == 1) {
            std::string id, name, gender;
            int birthYear, age;
            std::cout << "Nhap ID: ";
            std::getline(std::cin, id);
            std::cout << "Nhap ten: ";
            std::getline(std::cin, name);
            std::cout << "Nhap gioi tinh: ";
            std::getline(std::cin, gender);
            std::cout << "Nhap nam sinh: ";
            std::cin >> birthYear;
            std::cout << "Nhap tuoi: ";
            std::cin >> age;
            std::cin.ignore();

            Animal* animal = new Animal(id, name, gender, birthYear, age);
            zoo.addAnimal(animal);
        }

        else if (choice == 2) {
            std::string id;
            std::cout << "Nhap ID dong vat muon xoa: ";
            std::getline(std::cin, id);
            zoo.removeAnimalById(id);
        }

        else if (choice == 3) {
            std::string id;
            std::cout << "Nhap ID dong vat can tim: ";
            std::getline(std::cin, id);
            Animal* found = zoo.findAnimalById(id);
            if (found) {
                std::cout << "Tim thay dong vat:\n";
                found->printInfo();
            } else {
                std::cout << "Khong tim thay dong vat!\n";
            }
        }

        else if (choice == 4) {
            zoo.printAllAnimal();
        }

        else if (choice == 5) {
            std::string cageId;
            int capacity;
            std::cout << "Nhap ID chuong: ";
            std::getline(std::cin, cageId);
            std::cout << "Nhap suc chua chuong: ";
            std::cin >> capacity;
            std::cin.ignore();
            Cage* cage = new Cage(cageId, capacity);
            zoo.addCage(cage);
        }

        else if (choice == 6) {
            std::string cageId;
            std::cout << "Nhap ID chuong can hien thi: ";
            std::getline(std::cin, cageId);
            Cage* cage = zoo.findCageById(cageId);
            if (cage) {
                cage->printAnimals();
            } else {
                std::cout << "Khong tim thay chuong!\n";
            }
        }

        else if (choice == 7) {
            std::string animalId, cageId;
            std::cout << "Nhap ID dong vat: ";
            std::getline(std::cin, animalId);
            std::cout << "Nhap ID chuong: ";
            std::getline(std::cin, cageId);
            zoo.addAnimalToCage(animalId, cageId);
        }

        else if (choice == 0) {
            std::cout << "Tam biet!\n";
        }

        else {
            std::cout << "Lua chon khong hop le!\n";
        }

    } while (choice != 0);

    return 0;
}
