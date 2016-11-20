#include "ConsoleDisplayer.hpp"
#include <cstdio>

Displayer::Displayer(Manager* source)
{
    man = source;
}

void Displayer::paint()
{
    system("clear");
    Field f = man->getField();
    for (int r = 0; r < f.getR(); r++) {
        for (int c = 0; c < f.getC(); c++) {
            if (f[r][c] > 0)
                printf("*");
            else
                printf("-");
        }
        printf("\n");
    }
}
