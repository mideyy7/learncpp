#include <iostream>

void double_number (int num)
{
    std::cout << "Enter your number: ";
    int user_input{};
    std::cin >> user_input;
    std::cout << user_input * 2 << '\n';
}

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

    std::cout << sizeof(int) << '\n';
    double_number (50);


    return 0;

}