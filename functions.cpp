#include <iostream>
#include <cstring>
#include "header.h"

    //constructori + destructor 
Number::Number()    // constructorul vid va initializa obiectul cu 0
{
    sign = 1;
    digits.clear();
    p = 0;
}

Number::Number(const char *n)
{
    p = 0;
    unsigned int i = 0;
    if (n[0] == '-')
    {
        sign = -1;
        i++;
    }
    else
    {
        sign = 1;
        if (n[0] == '+')
        {
            i++;
        }
    }
    
    unsigned int l = strlen(n);
    while (i < l && n[i] != '.')        // introduc cifrele in vector pana la punct
    {
        digits.push_back(n[i] - '0');
        i++;
    }

    i++;       //in cazul in care numarul este real, sare peste punct, iar daca e intreg, i++ nu afecteaza testul de la urmatorul while
    while (i < l)      // introduc cifrele de dupa punct in vector si salvez numarul lor in p
    {
        digits.push_back(n[i] - '0');
        i++;
        p++;
    }
}

Number::Number(const Number& other)
{
    sign = other.sign;
    digits = other.digits;
    p = other.p;
}

Number::~Number()
{}

    //operatori 
Number& Number::operator=(const Number& other)
{
    this->sign = other.sign;
    this->digits = other.digits;
    this->p = other.p;
    return *this;
}


    //metode
void Number::Normalization()
{
    while (digits.size() > p + 1 && digits[0] == 0)
        {
            digits.erase(digits.begin());
        }
    while (p && digits.back() == 0)
    {
        digits.pop_back();
        p --;
    }
}

void Number::Afisare()
{
    if (sign == -1)
    {
        std::cout << '-';
    }

    unsigned int i;
    if (!p)
    {
        for (int x : digits)
        {
            std::cout << x;
        }
    }
    else
    {
        for (i = 0; i < digits.size() - p; i++)
        {
            std::cout << digits[i];
        }
        std::cout << '.';
        for (i = digits.size() - p; i < digits.size(); i++)
        {
            std::cout << digits[i];
        }
    }
    std::cout << std::endl;
}