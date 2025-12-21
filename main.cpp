#include <iostream>
#include <string>
#include "header.h"

int main()
{
    Number a("0.999"), b("0.002"), c;
    c = a + b;
    c.Afisare();

    return 0;
}