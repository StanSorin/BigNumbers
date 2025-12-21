#include "header.h"

bool Number::operator>(const Number& other) const   // compar in modul
{
    unsigned int d_size = digits.size(), o_d_size = other.digits.size();
    //prima data compar nr de cifre al partii intregi
    if (d_size - p > o_d_size - other.p)
    {
        return 1;
    }
    else
    {
        if (d_size - p < o_d_size - other.p)
        {
            return 0;
        }
        else
        {  
            // compar partea intreaga daca nr de cifre este la fel
            unsigned int i;
            for (i = 0; i < d_size - p; i++)
            {
                if (digits[i] > other.digits[i])
                {
                    return 1;
                }
                else
                {
                    if (digits[i] < other.digits[i])
                    {
                        return 0;
                    }
                }
            }
            
            // compar partea fractionara
            unsigned int min_p = (p < other.p) ? p : other.p;
            for (i = 0; i < min_p; i++)
            {
                if (digits[d_size - p + i] > other.digits[o_d_size - other.p + i])
                {
                    return 1;
                }
                else if (digits[d_size - p + i] < other.digits[o_d_size - other.p + i])
                {
                    return 0;
                }
            }

            // in cazul in care numarul are mai multe cifre in partea fractionara
            // iar pana atunci toate sunt egale, verific daca este vreuna nenula
            // altfel va fi mai mic sau egal caz in care returnez 0
            if (p > other.p)
            {
                for (i = o_d_size; i < d_size; i++)
                {
                    if (digits[i])
                        return 1;
                }
                return 0;
            }
            return 0;
        }
    }
}