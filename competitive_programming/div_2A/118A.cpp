#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
build a new string so init empty string
process as i traverse
convert eacjh to lower
vowels = "A", "O", "Y", "E", "U", "I"

[26]..... char[lower(letter) - 'a']

*/

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    string word;
    cin >> word;
    string result = "";
    vector<bool> is_vowel(26, false);
    vector<char> vowels = {'A', 'O', 'Y', 'E', 'U', 'I'};
    for (char vowel: vowels) {
        is_vowel[tolower(vowel) - 'a'] = true;
    }
    for (char letter: word) {
        letter = tolower(letter);
        if (!is_vowel[letter - 'a']) {
            result += '.';
            result += letter;
        }
    }
    cout << result << "\n";
   
   




    
    return 0;
}