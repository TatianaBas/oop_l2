#pragma once

#include <string>
#include <iostream>

#define MAX_LEN 1000

class Four
{ 
public:
    Four();
    Four(const size_t &n);
    Four(const std::initializer_list<unsigned char> &t);
    Four(const std::string &t);
    Four(const Four& other);
    Four(Four&& other) noexcept;

    Four operator+(const Four& other);
    Four operator-(const Four& other);
    bool operator==(const Four& other);
    bool operator!=(const Four& other);
    bool operator>(const Four& other);
    bool operator<(const Four& other);

    int getSize();
    unsigned char* getFourArray();

    std::ostream& print(std::ostream& os);
    virtual ~Four() noexcept;
private:
    bool correct(const std::string &t);
    void reverseArray(unsigned char* t, size_t length);
    unsigned char* decimal_To_Four(const size_t &n);
    size_t four_To_Decimal(unsigned char* t, size_t length);
    size_t arr_size(unsigned char* t);
private:
    size_t _size;
    unsigned char *_four;
};