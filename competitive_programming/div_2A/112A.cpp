#include <iostream>
#include <string>

using namespace std;

/*
two pointers .. if char are nut equal and lower(a) < lower(b) 
process -> If the first string is less than the second one, print "-1". If the second string is less than the first one, print "1". 
*/

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    string word1, word2;
    int pointer{0};

    cin >> word1; 
    cin >> word2;

    while (pointer < word1.size()) {
        char char1 = tolower(word1[pointer]);
        char char2 = tolower(word2[pointer]);
        if (char1 != char2) {
            if (char1 < char2) {
                cout << -1 << "\n";
            } else {
                cout << 1 << "\n";

            }
            return 0;
        }
        pointer++;
    }
    cout << 0 << "\n";
    return 0;
}