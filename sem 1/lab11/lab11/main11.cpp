#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

void DELETE_MARKS(std::string& s) {
    if (s.empty()) return;
    char lastChar = s.back();
    if ( lastChar >= 32 && lastChar <=63 ) {
        s = s.erase(s.length() - 1, 1);
    }
}

void CORR_WORD(std::string& s, char x1, char x2, char x3) {
    if (s.find(x1) != std::string::npos || s.find(x2) != std::string::npos || s.find(x3) != std::string::npos) {
        s.clear();
    }
}

/* void DUPL_DEL(std::string& s, std::string& ss) {
    if (s==ss) {
        ss.clear();
    }
}
*/

/* void SORT_ALPH(std::vector<std::string>& v) {
    for (int i = 0; i < v.size(); i++) {
        for (int j = i + 1; j < v.size(); j++) {
            if (v[j] < v[i]) {
                std::string temp = v[i];
                v[i] = v[j];
                v[j] = temp;
            }

        }
    }
}
    */

std::string TO_LOWER(const std::string& s) {
    std::string res = s;
    for (int i = 0; i < (int)res.size(); i++) {
        if (res[i] >= 'A' && res[i] <= 'Z') {
            res[i] = res[i] - 'A' + 'a';
        }
    }
    return res;
}

void SORT_BY_LENGTH_AND_ALPH(std::vector<std::string>& v) {
    for (int i = 0; i < (int)v.size(); i++) {
        for (int j = i + 1; j < (int)v.size(); j++) {
            if (v[j].size() > v[i].size() || (v[j].size() == v[i].size() && TO_LOWER(v[j]) < TO_LOWER(v[i]))) {
                std::string temp = v[i];
                v[i] = v[j];
                v[j] = temp;
            }
        }
    }
}

void DELETE_DUPLICATES(std::vector<std::string>& v) {
    for (int i = 0; i < (int)v.size(); i++) {
        for (int j = i + 1; j < (int)v.size(); j++) {
            if (TO_LOWER(v[i]) == TO_LOWER(v[j])) {
                for (int k = j; k < (int)v.size() - 1; k++) {
                    v[k] = v[k + 1];
                }
                v.pop_back();
                j--;
            }
        }
    }
}



int main() {
    int n = 3;
    char a, x1, x2, x3;

    for (int i = 0; i < n; ++i) {
        std::cin >> a; 

        if (i == 0) {
            x1 = a;
        } else if (i == 1) {
            x2 = a;
        } else if (i == 2) {
            x3 = a;
        }
    }
    std::ifstream in("ex.txt");
    if (!in.is_open()) {
        std::cout << "File is not open" << std::endl;
        return -1;
    }

    std::ofstream out("output.txt");

    std::vector<std::string> processed_words;

    std::string s;

    while (!in.eof()) {
        in >> s;
        DELETE_MARKS(s);
        CORR_WORD(s, x1, x2, x3);

        if (!s.empty()) {
            processed_words.push_back(s);
        }
        //std::cout << ss << " ";
    }
    //SORT_ALPH(processed_words);
    DELETE_DUPLICATES(processed_words);
    SORT_BY_LENGTH_AND_ALPH(processed_words);
    int N = 2000;
    int limit = (processed_words.size() < N) ? processed_words.size() : N;

    for (int i = 0; i < limit; i++) {
        out << processed_words[i] << std::endl;
    }

    //out << s << std::endl;

    return 0;
}

// 1. 	Дан файл, содержащий английский текст. Найти в тексте N<=2000 самых длинных слов, 
//не содержащих ни одной из трех заданных букв. 
//Записать найденные слова в текстовый файл в порядке невозрастания длины. 
//Все найденные слова должны быть разными!