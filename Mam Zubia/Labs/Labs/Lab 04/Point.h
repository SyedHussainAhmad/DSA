#ifndef POINT_H
#define POINT_H
#include <iostream>
using namespace std;

struct Point 
{
    int row, column;
    Point(int r, int c) : row(r), column(c) {}
};
#endif // !POINT_H
