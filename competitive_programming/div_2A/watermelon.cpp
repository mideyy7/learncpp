#include <iostream>
using namespace std;

/*
if w is even it means they can be split into even parts
if it is odd: they cannot be split into even parts
*/

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int w;
    cin >> w;
    if (w % 2 == 0) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }

    
    return 0;
}