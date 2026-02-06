#include <iostream>
#include <fstream>
#include <chrono>


// Сортировка обменом
void swapSort(int* a, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[i]) {
                std::swap(a[j], a[i]);
            }
        }
    }
}

//  Пузырьковая сортировка
void bubbleSort(int* a, int n) {
    for (int i = 0; i < n - 1; i++) {  
        bool t = true;        
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                t = false;
                std::swap(a[j], a[j + 1]);
            }
        }
        if (t) {
            break;
        }
    }
}


// Быстрая сортировка

void QuickSort(int a, int b, int* arr) {
    if (a>=b) return;

    int k = (rand()*rand()) % (b-a+1) + a;
    int m = arr[k];

    int l = a - 1;
    int r = b + 1;
    while(true) {
        do l++; while(arr[l] < m);
        do r--; while(arr[r] > m);
        if(l >= r) break;
        std::swap(arr[l], arr[r]);
    }
    l = r;
    r++;
    QuickSort(a, l, arr);
    QuickSort(r, b, arr);
}

// Сортировка подсчётом
void countingSort(int* a, int n) {
    const int OFFSET = 500000;
    const int K = 1000001;

    int* cnt = new int[K];
    for (int i = 0; i < K; i++) cnt[i] = 0;

    for (int i = 0; i < n; i++)
        cnt[a[i] + OFFSET]++;

    int pos = 0;
    for (int i = 0; i < K; i++) {
        while (cnt[i] > 0) {
            a[pos++] = i - OFFSET;
            cnt[i]--;
        }
    }

    delete[] cnt;
}

int main()
{
    std::ifstream in("output_250k_sorted.txt");
    if (!in.is_open()) {
        std::cout << "File is not open" << std::endl;
        return -1;
    }
    std::ofstream out("output.txt");

    std::vector<int> arr;
    int x;
    while (in >> x) {
        arr.push_back(x);
    }
    int n = arr.size();


    // Start Timer
    auto start = std::chrono::high_resolution_clock::now();

    //swapSort(arr.data(), n);
    bubbleSort(arr.data(), n);
    //QuickSort(0, n - 1, arr.data());
    //countingSort(arr.data(), n);

    // Stop Timer
    auto end = std::chrono::high_resolution_clock::now();

    auto duration = end - start;
    long long milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(duration).count();
    std::cout << "Time pass: " << milliseconds << " mil sec" <<std::endl;

    ///* 
    for (int i = 0; i < n; i++) {
        out << arr[i] << " ";
    }

    return 0;
    //*/
}
