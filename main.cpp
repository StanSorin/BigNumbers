#include <iostream>
#include <string>
#include "header.h"

int main()
{
    Number a("0"), b("0.002"), c;
    c = a - b;
    c.Afisare();

    Number aa("-12.34"), bb("0.1");
    c = aa * bb;
    c.Afisare();

    return 0;
}