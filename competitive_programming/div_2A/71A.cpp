#include <iostream>
#include <string>
using namespace std;

/*
if the word > 10: then process else leave as it is
*/

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    string word;
    cin >> n;
    while (n--) {
        cin >> word;
        if (word.size() > 10) {
            cout << word[0] << word.size() - 2 << word[word.size() - 1] << "\n";
        } else {
            cout << word << "\n";
        }
    }

    
    return 0;
}