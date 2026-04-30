#include <iostream>

int main()
{
    #if 0
    std::cout << "Hello World \n";
    #endif 
    int x; // defining variable x
    int y, z;

    // Initialization = Definition + Assignment
    int width {5};
    /* 
    Types of initialization
    1. Direct list using {}
    2. Copy using =
    3. direct unsing ()
    4. value using {} and leaving it empty


    << insertion operator 
    >> extraction operator
    
    */

    [[maybe_unused]] double gravity = 9.8;

    return 0;
}