#include <iostream>
#include <string>
#include <vector>
#include <sstream>

int main() {
    std::string word, val, result;
    std::cin >> word;
    std::stringstream s(word);

    std::vector<std::string> temp;
    while (std::getline(s, val, '+')) {
        temp.push_back(val);
    }
    sort(temp.begin(), temp.end());

    for (int i = 0; i < temp.size(); ++i) {
        if (i > 0) result += "+";
        result += temp[i];
    }
    std::cout << result << "\n"; 
    return 0;
}