#ifndef USER_H
#define USER_H

#include <string>

class User {
protected:
    std::string username;
    std::string password;
    std::string role;  // admin, manager, guest

public:
    User(const std::string& username, const std::string& password, const std::string& role);

    // Getter
    std::string getUsername() const;
    std::string getPassword() const;

    // Setter
    void setUsername(const std::string& newUsername);
    void setPassword(const std::string& newPassword);

    // Phương thức login để kiểm tra username và password
    virtual bool login(const std::string& inputUsername, const std::string& inputPassword);
    
    std::string getRole() const;
    
    // Hiển thị thông tin người dùng
    virtual void printInfo() const;
    
    // Hàm thay đổi mật khẩu
    virtual void changePassword(const std::string& newPassword);
    
    virtual ~User();
};

#endif
