#include "user.h"
#include <iostream>

User::User(const std::string& username, const std::string& password, const std::string& role)
    : username(username), password(password), role(role) {}

// Getter
std::string User::getUsername() const { return username; }
std::string User::getPassword() const { return password; }

// Setter
void User::setUsername(const std::string& newUsername) { username = newUsername; }
void User::setPassword(const std::string& newPassword) { password = newPassword; }

// Phương thức login
bool User::login(const std::string& inputUsername, const std::string& inputPassword) {
    return (username == inputUsername && password == inputPassword);
}

// Trả về vai trò
std::string User::getRole() const { return role; }

// Hiển thị thông tin người dùng
void User::printInfo() const {
    std::cout << "Username: " << username << "\nRole: " << role << std::endl;
}

// Thay đổi mật khẩu
void User::changePassword(const std::string& newPassword) {
    password = newPassword;
    std::cout << "Mat khau duoc tao thanh cong.\n";
}

User::~User() {}
