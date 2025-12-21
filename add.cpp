#include "header.h"

Number Number::operator+(const Number& other) const
{
    Number sum(*this), add(other);
    unsigned int max_p = (sum.p > add.p) ? sum.p : add.p;

    // normalizez numerele pentru a avea acelasi numar de cifre dupa punct
    while (sum.p < max_p)
    {
        sum.digits.push_back(0);
        sum.p++;
    }
    while (add.p < max_p)
    {
        add.digits.push_back(0);
        add.p++;
    }

    // in sum pastrez numarul mai mare
    if (add > sum)
    {
        Number aux = sum;
        sum = add;
        add = aux;
    }
    int l1 = sum.digits.size() - 1, l2 = add.digits.size() - 1;    // l1 >= l2

    if (sum.sign == add.sign)     // adunare pentru numerele cu acelasi semn
    {
        unsigned char carry = 0, i;
        while (l1 >= 0 && l2 >= 0)
        {
            unsigned char s = sum.digits[l1] + add.digits[l2] + carry;
            carry = s / 10;
            sum.digits[l1] = s % 10;
            l1--;
            l2--;
        }

        // cazul 999...9 + 1
        while (l1 >= 0 && carry)
        {
            unsigned char s = sum.digits[l1] + carry;
            carry = s/10;
            sum.digits[l1] = s % 10;
            l1--;
        }
        if (carry)
        {
            sum.digits.insert(sum.digits.begin(), 1, 1);
        }
    }
    else            // adunare pentru numere cu semne diferite (scadere)
    {
        unsigned char borrow = 0;
        while (l1 >= 0 && l2 >= 0)
        {
            sum.digits[l1] -= borrow;
            char s = sum.digits[l1] - add.digits[l2];
            if (s < 0)
            {
                borrow = 1;
                s += 10;
            }
            else
            {
                borrow = 0;
            }
            sum.digits[l1] = s;
            l1--;
            l2--;
        }
        while (borrow && l1 >= 0)
        {
            char s = sum.digits[l1] - borrow;
            if (s < 0)
            {
                borrow = 1;
                s += 10;
            }
            else
            {
                borrow = 0;
            }
            sum.digits[l1] = s;
            l1--;
        }
    }
    sum.Normalization();
    
    return sum;
}