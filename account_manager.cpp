#include "account_manager.h"
#include <iostream>

AccountManager::AccountManager() : currentUser(nullptr) {}

void AccountManager::registerAdmin(const std::string& username, const std::string& password) {
    currentUser = new Admin(username, password);
    users.push_back(currentUser);
    std::cout << "Tai khoan admin duoc tao.\n";
}

bool AccountManager::login(const std::string& username, const std::string& password) {
    for (auto& user : users) {
        if (user->login(username, password)) {
            currentUser = user;
            return true;
        }
    }
    currentUser = nullptr;
    return false;
}

void AccountManager::showCurrentUserInfo() const {
    if (currentUser) {
        currentUser->printInfo();
    } else {
        std::cout << "Khong nguoi dung nao dang nhap.\n";
    }
}

void AccountManager::logout() {
    currentUser = nullptr;
    std::cout << "Da dang xuat.\n";
}

void AccountManager::createManagerAccount(const std::string& username, const std::string& password) {
    if (currentUser && currentUser->getRole() == "admin") {
        static_cast<Admin*>(currentUser)->createManagerAccount(users, username, password);
    } else {
        std::cout << "Chi admin moi co quyen tao tai khoan.\n";
    }
}

void AccountManager::viewAllAccounts() const {
    if (currentUser && currentUser->getRole() == "admin") {
        static_cast<Admin*>(currentUser)->viewAllAccounts(users);
    } else {
        std::cout << "Chi admin moi co quyen xem tai khoan.\n";
    }
}

void AccountManager::changePassword(const std::string& newPassword) {
    if (currentUser) {
        currentUser->changePassword(newPassword);
    } else {
        std::cout << "Khong co nguoi dung nao dang nhap.\n";
    }
}

void AccountManager::adminChangeUserPassword(const std::string& username, const std::string& newPassword) {
    if (currentUser && currentUser->getRole() == "admin") {
        static_cast<Admin*>(currentUser)->changeUserPassword(users, username, newPassword);
    } else {
        std::cout << "Chi admin moi co quyen thay doi mat khau.\n";
    }
}

User* AccountManager::getCurrentUser() const { 
    return currentUser;
}

AccountManager::~AccountManager() {
    for (auto user : users) {
        delete user;
    }
}
