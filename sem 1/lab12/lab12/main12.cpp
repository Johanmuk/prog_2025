#include <iostream>
#include <string>

int countVowels(const std::string& s, int i) {
    if (i == s.size()) return 0;

    int add = 0;
    char c = s[i];

    if (c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || c=='y' || c=='A' || c=='E' || c=='I' || c=='O' || c=='U' || c=='Y') {
        add = 1;
    }

    return add + countVowels(s, i + 1);
}

int main() {
    std::string s;
    std::getline(std::cin, s);

    std::cout << countVowels(s, 0);
    return 0;
}
