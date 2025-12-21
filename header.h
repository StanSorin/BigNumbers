#pragma once
#include <vector>

class Number
{
private:
    int sign;                   // semn
    std::vector <int> digits;     // vectorul cu cifrele numarului
    unsigned int p;             // numarul de cifre al partii fractionare

public:
    Number();
    Number(const char *n);
    Number(const Number& other);
    ~Number();

    Number& operator=(const Number& other);
    bool operator>(const Number& other) const;
    Number operator+(const Number& other) const;

    void Normalization();
    void Afisare();
};