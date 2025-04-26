#ifndef GUEST_H
#define GUEST_H

#include "user.h"
#include "zoo.h"

class Guest : public User {
public:
    Guest();

    // Tìm kiếm và hiển thị động vật, chuồng
    void printAllAnimalsInZoo(const Zoo& zoo) const;
    void printAllCagesInZoo(const Zoo& zoo) const;
};

#endif
