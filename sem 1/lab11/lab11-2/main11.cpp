#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

void DELETE_MARKS(std::string& s) {
    if (s.empty()) return;
        for (int i = 0; i < s.length(); ) {
            if (s[i] >= 32 && s[i] <= 63) {
                s.erase(i, 1);
            } else {
                i++;
            }
        }
    while (!s.empty() && s.back() >= 32 && s.back() <= 63) {
        s.pop_back();
    }
    while (!s.empty() && s.front() >= 32 && s.front() <= 63) {
        s.erase(0, 1);
    }
}

bool IS_REPEAT(std::string& s){
    bool repeat[26] = {false}; 
    for (int i = 0 ; i< s.length(); i++) {
        int inx = s[i] - 'a';
        if (repeat[inx]) {
            return true;
        }
        repeat[inx] = true;
    }
    return false;
}

void DET_VOW(std::string& s) {
    std::string rest = "";
    std::string vow = "eyuioa";
    for (int i = 0; i< s.size(); i++) {
        if (vow.find(s[i]) == std::string::npos) {
            rest += s[i];
        }
    }
    s = rest;
}

std::string TO_LOWER(const std::string& s) {
    std::string res = s;
    for (int i = 0; i < (int)res.size(); i++) {
        if (res[i] >= 'A' && res[i] <= 'Z') {
            res[i] = res[i] - 'A' + 'a';
        }
    }
    return res;
}

void SORT_REV_ALPH(std::vector<std::string>& s) {
    for (int i = 0; i < s.size(); ++i) {
        for (int j = i + 1; j < s.size(); ++j) {  
            if (s[i] < s[j]) {  
                std::swap(s[i], s[j]); 
            }
        }
    }
}

int main() {
    std::ifstream in("ex.txt");
    if (!in.is_open()) {
        std::cout << "File is not open" << std::endl;
        return -1;
    }

    std::ofstream out("output.txt");

    std::vector<std::string> words_1;
    std::vector<std::string> words_2;
    std::string s;

    while (!in.eof()) {
        in >> s;
        DELETE_MARKS(s);
        s = TO_LOWER(s);
        if (!s.empty()) {
            if (IS_REPEAT(s)) {
                DET_VOW(s);
                words_2.push_back(s);
                std::cout<<s<<"   -2"<<std::endl;
            } else {
                words_1.push_back(s);
                std::cout<<s<<"   -1"<<std::endl;
            }
        }

    }
    
    SORT_REV_ALPH(words_1);

    for (size_t i = 0; i < words_1.size(); i++) {
        std::cout << words_1[i] << " ";
    }
    std::cout << "-----" << std::endl;

    for (size_t i = 0; i < words_2.size(); i++) {
        std::cout << words_2[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}
// It is ,,,told among the wise that the First War be-gan before Arda was full-shaped, and ere yet there was anything that grew!!! or walked upon earth. - строка
//Дана строка, содержащая английский текст. 
//Вывести в порядке, обратном к алфавитному, слова текста, 
//не содержащие повторяющихся букв, в остальных словах удалить гласные буквы.