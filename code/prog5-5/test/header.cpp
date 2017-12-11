#include "square.h"  // square.h is included once here
 
int getSquarePerimeter(int sideLength)
{
    return sideLength * getSquareSides();
}
int getSquareSides()
{
    return 4;
}
