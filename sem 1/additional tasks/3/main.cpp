#include <iostream>
#include <cmath>

bool hasRepeatDigits(int x) {
    bool used[10] = {false};
    while (x > 0) {
        int d = x % 10;
        if (used[d]) {
            return true;
        }
        used[d] = true;
        x /= 10;
    }
    return false;
}

bool isCube(int x) {
    for (int i = 1; i <= 21; i++) {
        if (i * i * i == x)
            return true;
    }
    return false;
}

void removeElement(int a[], int &n, int pos) {
    for (int i = pos; i < n - 1; i++)
        a[i] = a[i + 1];
    n--;
}

void duplicateElement(int a[], int &n, int pos) {
    if (n >= 10000) return; 
    for (int i = n; i > pos; i--)
        a[i] = a[i - 1];
    a[pos + 1] = a[pos];
    n++;
}

int main() {
    
    std::cout << "3)" << std::endl;

    int n;
    std::cin >> n;

    int a[10000];
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    //с одинак цифр удал
    int i = 0;
    while (i < n) {
        if (hasRepeatDigits(a[i]))
            removeElement(a, n, i);
        else
            i++;
    }

    //Дублир-е
    i = 0;
    while (i < n) {
        if (isCube(a[i])) {
            duplicateElement(a, n, i);
            i += 2;
        } else {
            i++;
        }
    }

    for (int i = 0; i < n; i++)
        std::cout << a[i] << " ";

    return 0;
}

