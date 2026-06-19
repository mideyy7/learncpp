#include <iostream>
#include <bitset>
#include <format>

using namespace std;

// number conversions

int main() {

    cout << 10 << "\n";
    cout <<  std::oct << 010 << "\n";
    cout << std::hex << 0x10 << "\n";

    std::bitset<4> my {0b1010};
    cout << my << "\n";

    cout << std::format("{:#b}\n", 0b1010);
    std::cout << std::format("{:#b}\n", 0b1010);  


    return 0;



    //  A program called a profiler can be used to see how long various parts of the program are taking to run, and which are impacting overall performance

    
}