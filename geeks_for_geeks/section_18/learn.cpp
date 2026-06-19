/*

STL Introduction

A. Containers: 
use the concept of templates
- Simple: Pair, Vector, Forward_list, list
- Container Adapters: stack, queue, priority_queue
-Associative: set, map, unordered_set, unordered_map

B. Algorithms:
use the concept of iterators (address -> begin(), end())
- binary-search, find, reverse, sort ...

ITERATORS
begin()
end()
prev()
next()
advance()


*/

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    vector<int> v = {10, 20, 30, 40, 50};
    vector<int>::iterator i = v.begin();
    cout << (*i) << " ";
    i++;
    cout << (*i) << " ";
    i = v.end();
    i--;
    cout << (*i) << " ";
    cout << endl;
    return 0;
}