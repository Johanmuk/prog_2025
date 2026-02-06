#include <iostream>
#include <fstream>
#include <string>

bool isVowel(char c) {
    if (c >= 'A' && c <= 'Z') c = c - 'A' + 'a';
    return c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='y';
}

std::string toUpper(std::string s) {
    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= 'a' && s[i] <= 'z') s[i] = s[i] - 'a' + 'A';
    }
    return s;
}

std::string findDoubleVowel(const std::string& s) {
    for (int i = 0; i < s.size() - 1; i++) {
        if (isVowel(s[i]) && (s[i] == s[i+1] || s[i] == s[i+1] + ('a'-'A') || s[i] == s[i+1] - ('a'-'A'))) { //малмал -- малбол -- болмал
            char c = s[i];
            if (c >= 'A' && c <= 'Z') c = c - 'A' + 'a';
            std::string r = "";
            r += c;
            r += c;
            return r;
        }
    }
    return "";
}

int main() {
    std::ifstream in("ex.txt");
    if (!in.is_open()) {
        std::cout << "File is not open" << std::endl;
        return -1;
    }

    std::ofstream out("output.txt");

    std::string word = "";
    char c;

    while (true) {
        c = in.get();
        if (in.eof()) break;

        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
            word += c;
        } else {

            if (!word.empty()) {
                std::string dv = findDoubleVowel(word);
                if (!dv.empty()) {
                    out << toUpper(word) << "(" << dv << ")";
                } else {
                    out << word;
                }
                word.clear();
            }

            out << c;
        }
    }

    if (!word.empty()) {
        std::string dv = findDoubleVowel(word);
        if (!dv.empty()) {
            out << toUpper(word) << "(" << dv << ")";
        } else {
            out << word;
        }
    }

    return 0;
}
