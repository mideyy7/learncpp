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
next() returns a new iterator
advance() modifies the passed iterator


*/

#include <iostream>
#include <algorithm>

using namespace std;

vector<char> solve(int arr1[], char arr2[], int n) {
    vector<pair<int,char>> temp;
    for (int i = 0; i < n; i++) {
        temp.push_back({arr1[i], arr2[i]});
    }
    sort(temp.begin(), temp.end());
    vector<char> result(n);
    for (int i = 0; i < n; i++) {
        result[i] = temp[i].second;
    }
    return result;

}

int main() {
    // vector<int> v = {10, 20, 30, 40, 50};
    // vector<int>::iterator i = v.begin();
    // cout << (*i) << " ";
    // i++;
    // cout << (*i) << " ";
    // i = v.end();
    // i--;
    // cout << (*i) << " ";
    // cout << endl;
    // return 0;
}



