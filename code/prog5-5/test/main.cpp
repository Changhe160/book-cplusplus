#include <iostream>
#include "square.h" // square.h is also included once here
 
int main()
{
    std::cout << "a square has " << getSquareSides() << " sides" << std::endl;
    std::cout << "a square of length 5 has perimeter length " << getSquarePerimeter(5) << std::endl;
 
    return 0;
}
