#include "account_manager.h"
#include "zoo.h"
#include "animal.h"
#include "cage.h"
#include <iostream>

void showMenu(const std::string& role) {
    std::cout << "\n===== MENU (" << role << ") =====\n";
    if (role == "admin") {
        std::cout << "1. Tao tai khoan Manager\n";
        std::cout << "2. Xem tat ca tai khoan\n";
        std::cout << "3. Doi mat khau cua minh\n";
        std::cout << "4. Doi mat khau nguoi dung khac\n";
        std::cout << "5. Them dong vat\n";
        std::cout << "6. Xoa dong vat\n";
        std::cout << "7. Xem tat ca dong vat\n";
        std::cout << "8. Them chuong\n";
        std::cout << "9. Xoa chuong\n";
        std::cout << "10. Xem tat ca chuong\n";
        std::cout << "11. Them dong vat vao chuong\n";
        std::cout << "0. Dang xuat\n";
    } else if (role == "manager") {
        std::cout << "1. Them dong vat\n";
        std::cout << "2. Xoa dong vat\n";
        std::cout << "3. Xem tat ca dong vat\n";
        std::cout << "4. Them chuong\n";
        std::cout << "5. Xoa chuong\n";
        std::cout << "6. Xem tat ca chuong\n";
        std::cout << "7. Them dong vat vao chuong\n";
        std::cout << "0. Dang xuat\n";
    } else if (role == "guest") {
        std::cout << "1. Xem tat ca dong vat\n";
        std::cout << "2. Xem tat ca chuong\n";
        std::cout << "0. Thoat\n";
    }
    std::cout << "======================\n";
}

int main() {
    AccountManager accountManager;
    Zoo zoo;

    std::string username, password;

    // Tạo tài khoản admin đầu tiên
    std::cout << "Tao tai khoan admin dau tien:\n";
    std::cout << "Nhap username: ";
    std::cin >> username;
    std::cout << "Nhap password: ";
    std::cin >> password;
    accountManager.registerAdmin(username, password);

    int choice;
    while (true) {
        std::cout << "\n===== Dang nhap =====\n";
        std::cout << "1. Dang nhap\n";
        std::cout << "2. Dang nhap voi tu cach khach (Guest)\n";
        std::cout << "0. Thoat\n";
        std::cout << "Chon: ";
        std::cin >> choice;

        if (choice == 1) {
            std::cout << "Username: ";
            std::cin >> username;
            std::cout << "Password: ";
            std::cin >> password;
            if (accountManager.login(username, password)) {
                std::cout << "Dang nhap thanh cong.\n";
            } else {
                std::cout << "Dang nhap that bai.\n";
                continue;
            }
        } else if (choice == 2) {
            accountManager.logout(); // tránh giữ tài khoản cũ
            std::cout << "Ban dang su dung voi tu cach khach.\n";
            User* guestUser = new Guest();
            std::string role = guestUser->getRole();

            while (true) {
                showMenu(role);
                std::cout << "Chon chuc nang: ";
                std::cin >> choice;

                if (choice == 0) break;
                switch (choice) {
                    case 1:
                        guestUser->printInfo();
                        zoo.printAllAnimal();
                        break;
                    case 2:
                        zoo.printAllCages();
                        break;
                }
            }
            delete guestUser;
            continue;
        } else {
            break;
        }

        User* user = accountManager.getCurrentUser();
        if (!user) continue;
        std::string role = user->getRole();

        while (true) {
            showMenu(role);
            std::cout << "Chon chuc nang: ";
            std::cin >> choice;
            if (choice == 0) {
                accountManager.logout();
                break;
            }

            if (role == "admin") {
                Admin* admin = static_cast<Admin*>(user);
                switch (choice) {
                    case 1:
                        std::cout << "Nhap username moi: "; std::cin >> username;
                        std::cout << "Nhap password: "; std::cin >> password;
                        accountManager.createManagerAccount(username, password);
                        break;
                    case 2:
                        accountManager.viewAllAccounts();
                        break;
                    case 3:
                        std::cout << "Nhap mat khau moi: ";
                        std::cin >> password;
                        accountManager.changePassword(password);
                        break;
                    case 4:
                        std::cout << "Nhap ten nguoi dung muon doi mat khau: ";
                        std::cin >> username;
                        std::cout << "Mat khau moi: ";
                        std::cin >> password;
                        accountManager.adminChangeUserPassword(username, password);
                        break;
                    case 5: {
                        std::string id, name, gender;
                        int birthYear, age;
                        std::cout << "Nhap id: "; std::cin >> id;
                        std::cout << "Nhap ten: "; std::cin >> name;
                        std::cout << "Nhap gioi tinh: "; std::cin >> gender;
                        std::cout << "Nhap nam sinh: "; std::cin >> birthYear;
                        std::cout << "Nhap tuoi: "; std::cin >> age;
                        admin->addAnimalToZoo(zoo, new Animal(id, name, gender, birthYear, age));
                        break;
                    }
                    case 6:
                        std::cout << "Nhap ID dong vat muon xoa: ";
                        std::cin >> username;
                        admin->removeAnimalFromZoo(zoo, username);
                        break;
                    case 7:
                        admin->printAllAnimalsInZoo(zoo);
                        break;
                    case 8: {
                        std::string id;
                        int limit;
                        std::cout << "Nhap ID chuong: ";
                        std::cin >> id;
                        std::cout << "Nhap gioi han dong vat: ";
                        std::cin >> limit;
                        admin->addCageToZoo(zoo, new Cage(id, limit));
                        break;
                    }
                    case 9:
                        std::cout << "Nhap ID chuong muon xoa: ";
                        std::cin >> username;
                        admin->removeCageFromZoo(zoo, username);
                        break;
                    case 10:
                        admin->printAllCagesInZoo(zoo);
                        break;
                    case 11:
                        std::string animalId, cageId;
                        std::cout << "Nhap ID dong vat: "; std::cin >> animalId;
                        std::cout << "Nhap ID chuong: "; std::cin >> cageId;
                        zoo.addAnimalToCage(animalId, cageId);
                        break;
                }
            } else if (role == "manager") {
                Manager* manager = static_cast<Manager*>(user);
                switch (choice) {
                    case 1: {
                        std::string id, name, gender;
                        int birthYear, age;
                        std::cout << "Nhap id: "; std::cin >> id;
                        std::cout << "Nhap ten: "; std::cin >> name;
                        std::cout << "Nhap gioi tinh: "; std::cin >> gender;
                        std::cout << "Nhap nam sinh: "; std::cin >> birthYear;
                        std::cout << "Nhap tuoi: "; std::cin >> age;
                        manager->addAnimalToZoo(zoo, new Animal(id, name, gender, birthYear, age));
                        break;
                    }
                    case 2:
                        std::cout << "Nhap ID dong vat muon xoa: ";
                        std::cin >> username;
                        manager->removeAnimalFromZoo(zoo, username);
                        break;
                    case 3:
                        manager->printAllAnimalsInZoo(zoo);
                        break;
                    case 4: {
                        std::string id;
                        int limit;
                        std::cout << "Nhap ID chuong: ";
                        std::cin >> id;
                        std::cout << "Nhap gioi han dong vat: ";
                        std::cin >> limit;
                        manager->addCageToZoo(zoo, new Cage(id, limit));
                        break;
                    }
                    case 5:
                        std::cout << "Nhap ID chuong muon xoa: ";
                        std::cin >> username;
                        manager->removeCageFromZoo(zoo, username);
                        break;
                    case 6:
                        manager->printAllCagesInZoo(zoo);
                        break;
                    case 7:
                        std::string animalId, cageId;
                        std::cout << "Nhap ID dong vat: "; std::cin >> animalId;
                        std::cout << "Nhap ID chuong: "; std::cin >> cageId;
                        zoo.addAnimalToCage(animalId, cageId);
                        break;
                }
            }
        }
    }

    std::cout << "Thoat chuong trinh.\n";
    return 0;
}
