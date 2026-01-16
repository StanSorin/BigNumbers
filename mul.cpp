#include "header.h"

Number Number::operator*(const Number& other) const
{
    Number A, B, rez;

    if (this->digits.size() == 1 && this->digits[0] == 0)
    {
        return (*this);
    }
    if (other.digits.size() == 1 && other.digits[0] == 0)
    {
        return other;
    }

    // in A salvez numarul cu mai multe cifre, iar in B pe cel cu mai putine cifre
    if (this->digits.size() > other.digits.size()) 
    {
        A = (*this);
        B = other;
    }
    else
    {
        A = other;
        B = (*this);
    }

    int lA, lB = (int)B.digits.size() - 1;

    unsigned int shift = 0;
    while(lB >= 0)
    {     
        // in t calculez produsul primului numar cu fiecare cifra din al doilea si le adun in rez
        Number t;  
        unsigned int p = 0, s = 0, s1 = 0;      // p = produsul dintre cifre
                                    // in s pastrez cifra pe care o adaug in t
                                    // in s1 pastrez cifra zecilor care se aduna la urmatoarea unitate
        t.digits.insert(t.digits.end(), shift, 0);
        shift++;
        lA = A.digits.size() - 1;
        while(lA >= 0)
        {
            p = B.digits[lB] * A.digits[lA] + s1;
            s = p % 10;
            s1 = p / 10;
            t.digits.insert(t.digits.begin(), s);
            lA--;
        }
        if (s1)
        {
            t.digits.insert(t.digits.begin(), s1);
        }
        rez = rez + t;
        lB--;
    }

    rez.sign = this->sign * other.sign;
    rez.p = this->p + other.p;

    rez.Normalization();
    return rez;
}