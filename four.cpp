#include <string>
#include <cstdint>
#include <cstring>
#include <cmath>
#include "four.h"

Four::Four() : _size(0), _four{nullptr}                         
{
    std::cout << "default constructing" << std::endl;
}

Four::Four(const size_t &n)
{   
    std::cout << "filling constructor" << std::endl;
    _four = decimal_To_Four(n);
    _size = arr_size(_four);
}

Four::Four(const std::initializer_list<unsigned char> &t)
{
    std::cout << "constructing initializer list" << std::endl;
    _four = new unsigned char[t.size()];
    size_t i{0};
    for (auto c : t)
        _four[i++] = c;
    _size = t.size();
    reverseArray(_four, _size);
    const std::string str = std::string(reinterpret_cast<const char*>(_four), _size);
    if (!correct(str)) {
        throw std::invalid_argument("input error: invalid characters");
    }
}

Four::Four(const Four &other)                     //copy constructor
{
    std::cout << "Copy constructor" << std::endl;
    _size  = other._size;
    _four = new unsigned char[_size];

    for(size_t i = 0;i<_size;++i) _four[i] = other._four[i];
}

Four::Four(const std::string &t)                                          //copy
{
    std::cout << "Copy string constructor" << std::endl;
    _four = new unsigned char[t.size()];
    _size  = t.size();
    for(size_t i{0};i<_size;++i) _four[i] = t[i];
    reverseArray(_four, _size);
    if (!correct(t)) {
        throw std::invalid_argument("wrong symblos in constructor strings");
    }

}


Four::Four(Four &&other) noexcept                        //move costructor
{
    std::cout << "Move constructor" << std::endl;
    _size = other._size;
    _four = other._four;

    other._size = 0;
    other._four = nullptr;
}

Four Four::operator+(const Four& other) {       //+ operation
    Four result;
    size_t first_number = four_To_Decimal(this->_four, this->_size);
    size_t second_number =  four_To_Decimal(other._four, other._size);

    size_t sum = first_number + second_number;

    result._four = decimal_To_Four(sum);
    result._size = arr_size(result._four);

    return result;
}

Four Four::operator-(const Four& other) {          //- operation
    Four result;
    size_t first_number = four_To_Decimal(this->_four, this->_size);
    size_t second_number =  four_To_Decimal(other._four, other._size);

    size_t sum = first_number - second_number;

    result._four = decimal_To_Four(sum);
    result._size = arr_size(result._four);

    return result;
}

bool Four::operator==(const Four& other) {      // == operation
    if (this->_size == other._size) {
        for (int i = 0; i < this->_size; i++) {
            if (this->_four[i] != other._four[i])
                return false;
        }
        return true;
    }
    return false;
}


bool Four::operator>(const Four& other) {        // > operation
    size_t first_number = four_To_Decimal(this->_four, this->_size);
    size_t second_number =  four_To_Decimal(other._four, other._size);

    return first_number > second_number;
}

bool Four::operator<(const Four& other) {        // < operation
    size_t first_number = four_To_Decimal(this->_four, this->_size);
    size_t second_number =  four_To_Decimal(other._four, other._size);

    return first_number < second_number;
}

int Four::getSize() {                // gets size of number 
    return this->_size;
}

std::ostream &Four::print(std::ostream &output)      // prints number
{
    for (long int i = _size; i >= 0; i--) {
        output << _four[i];
    }
    return output;
}


Four::~Four() noexcept                        // removes number
{
    _size = 0;
    delete[] _four;
    _four = nullptr;
}

bool Four::correct(const std::string &t) {           //check if the number is correct
    for (int i = 0; i < t.length(); i++) {
        char a = t[i];
        if (!((t[i] == '0') or (t[i] == '1') or (t[i] == '2') or (t[i] == '3')))
            return false;
    }
    return true;
}

size_t Four::arr_size(unsigned char* t) {                     // size of number
    size_t n = 0;
    while (t[n] != '\0') {
        n++;
    }
    return n;
}


unsigned char* Four::getFourArray() {                     // returns array of fours
    return this->_four;
}


void Four::reverseArray(unsigned char* t, size_t len) {                 // array reverse 
    if (len <= 1) {
        return;
    }
    unsigned char* start = t;
    unsigned char* end = t + len - 1;

    while (start < end) {
        unsigned char temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

size_t Four::four_To_Decimal(unsigned char* t, size_t len) {                 // transfer from four to decimal for arithmetic and comparison operations
    unsigned int decimalNumber = 0;

    for (int i = 0; i < len; ++i) {
        long long elem = t[i] - '0';
        decimalNumber += elem * std::pow(4, i);
    }

    return decimalNumber;
}

unsigned char* Four::decimal_To_Four(const size_t &n) {                 // transfer from decimal to four for arithmetic and comparison operation
    unsigned char * number;
    size_t len = 0;
    if (n == 0) {
        number = new unsigned char[1];
        number[0] = '0';
        len = 1;
        number[len] = '\0';
    }
    else {
        size_t check_len = n;
        while (check_len > 0) {
            size_t remainder = check_len % 4;
            check_len /= 4;
            len += 1;
        }
        number = new unsigned char[len];
        number[len] = '\0';
        size_t n_1 = n;
        
        size_t counter = 0;
        while (n_1 > 0) {
            size_t remainder = n_1 % 4;
            number[counter] = char(remainder + 48);
            counter += 1;
            n_1 /= 4;
        }
    }
    return number;
}







