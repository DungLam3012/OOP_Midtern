#ifndef ADMIN_H
#define ADMIN_H

#include "user.h"
#include "manager.h"
#include "zoo.h"
#include <vector>

class Admin : public User {
public:
    Admin(const std::string& username, const std::string& password);

    // Tạo tài khoản Manager mới
    void createManagerAccount(std::vector<User*>& users, const std::string& username, const std::string& password);

    // Xem tất cả các tài khoản
    void viewAllAccounts(const std::vector<User*>& users) const;

    // Thay đổi mật khẩu của người dùng khác
    void changeUserPassword(std::vector<User*>& users, const std::string& username, const std::string& newPassword);

    // Quản lý động vật và chuồng
    void addAnimalToZoo(Zoo& zoo, Animal* animal);
    void removeAnimalFromZoo(Zoo& zoo, const std::string& animalId);
    void printAllAnimalsInZoo(const Zoo& zoo) const;
    void addCageToZoo(Zoo& zoo, Cage* cage);
    void removeCageFromZoo(Zoo& zoo, const std::string& cageId);
    void printAllCagesInZoo(const Zoo& zoo) const;
};

#endif
