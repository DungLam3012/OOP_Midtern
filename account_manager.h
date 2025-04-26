#ifndef ACCOUNT_MANAGER_H
#define ACCOUNT_MANAGER_H

#include "user.h"
#include "admin.h"
#include "manager.h"
#include "guest.h"
#include <vector>

class AccountManager {
private:
    std::vector<User*> users;
    User* currentUser;

public:
    AccountManager();   
    void registerAdmin(const std::string& username, const std::string& password);
    bool login(const std::string& username, const std::string& password);
    void showCurrentUserInfo() const;
    void logout();
    
    // Tạo tài khoản Manager cho admin
    void createManagerAccount(const std::string& username, const std::string& password);
    
    // Xem tất cả tài khoản
    void viewAllAccounts() const;

    // Thay đổi mật khẩu cho người dùng
    void changePassword(const std::string& newPassword);
    
    // Admin thay đổi mật khẩu cho người dùng khác
    void adminChangeUserPassword(const std::string& username, const std::string& newPassword);
    
    User* getCurrentUser() const;  
    ~AccountManager();
};

#endif
