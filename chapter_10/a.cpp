/*

Overloading Functions :
Parameter Type and Parameter Count is used in determining which function to calll
RETURN TYPE IS NOT CONSIDERED IN OVERLOADING

Function signature include includes the function name, number of parameters, parameter type, and function-level qualifiers. It notably does not include the return type.

During compilation the compiler performs NAME MANGLING where it alters the name of functions based on their signature so while in the source code, the two overloaded functions share the name fcn(), in compiled code, the mangled names are unique

The process of matching function calls to a specific overloaded function is called overload resolution.

Method of Overloading Resolution (sequential)
1a.  The compiler tries to find an exact match. 
b. The compiler the tries to match with Trivial conversions which are: 
            lvalue to rvalue conversions
            qualification conversions (e.g. non-const to const)
            non-reference to reference conversions
2. Numeric Promotion
3. Numeric conversion
3. user defined conversions



Ambiguous matches happens when 2 results to the same function....compile error
Fix: explicitly define the signature in the function.. cast the argument to match what you want to call


*/

#include <iostream>
void printInt(int x) {
    std::cout << x << "\n";
}


// tO DELETE A FUNCTION
template<typename T>
void printInt(T c) = delete;

int main() {    
    printInt(5);
    // printInt(5.0);
    // printInt('a');
    return 0;
}


/*

============
TEMPLATES
============

Type template parameters (where the template parameter represents a type).
Non-type template parameters (where the template parameter represents a constexpr value).
Template template parameters (where the template parameter represents a template).


tHE DIFFERENCE OF USING A FUNCTION TEMLATE ->  the primary difference is the addition of the type in angled brackets (called a template argument)






*/