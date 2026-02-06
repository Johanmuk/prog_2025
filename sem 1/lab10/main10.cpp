#include <iostream>
#include <algorithm>

struct Node {
    int data;
    Node* next;
};

Node* MAKE(int value) {
    Node* p = new Node;
    p->data = value;
    p->next = nullptr;
    return p;
}

void ADD(Node* head, int value) {
    Node* p = MAKE(value);
    p->next = head->next;
    head->next = p;
}

void PRINT(Node* head) {
    Node* p = head->next;
    while (p!=nullptr) {
        std::cout << p->data << std::endl;
        p = p->next;
    }
}

int first_digit(int x) {
    if (x < 0) x = -x;
    if (x == 0) return 0;
    while (x >= 10) x /= 10;
    return x;
}

void DELETE_EVEN(Node* head) {
    Node* p = head;
    while(p->next != nullptr) {
        if (p->next->data % 2 == 0) {
            Node* tmp = p->next;
            p->next = p->next->next;
            delete tmp;
        }
        else {
            p = p->next;
        }
    }
}

void FD_SWAP(Node* head, int n){ //сорт по возр 
    for (int i=0; i<n-1; i++){
        Node* p = head;
        while(p->next != nullptr && p->next->next != nullptr ) {
            if (first_digit(p->next->data) > first_digit(p->next->next->data)) {
                std::swap(p->next->data, p->next->next->data);
            }
            p = p->next;
        }
    }
}

void DUPLICATE_ODD(Node* head) {
    Node* p = head->next;
    while(p != nullptr) {
        if (p->data % 2 == 1) {
            ADD(p, p->data);
            p = p->next;
        }
        p = p->next;
    }
}


int main() {
    int n, value;
    std::cout<< "Enter: "<< std::endl;
    std::cin >> n;

    Node head;
    head.next = nullptr;

    for (int i = 0; i < n; ++i) {
        std::cin >> value;
        ADD(&head, value);
    }
    // сортировка
    ///*
    bool repeat = false;
    Node* cur = head.next;
    for (int i = 0; i < n && cur != nullptr; ++i) {
        int tmp = cur->data;
        bool digits[10] = { false };
        if (tmp == 0) {
            cur = cur->next;
            continue;
        }
        
        while (tmp > 0) {
            int digit = tmp % 10;
            if (digits[digit]) { 
                repeat = true; 
                break; 
            }
            digits[digit] = true;
            tmp /= 10;
        }
        cur = cur->next;
    }

    if (repeat) {
        FD_SWAP(&head, n);
    } else {
        DELETE_EVEN(&head);
        DUPLICATE_ODD(&head);
    }
    //*/

    PRINT(&head);
    
    return 0;
}

//доступ по индексу - лучше массив О(1), список - О(n)
// повторение - О(n^2)
// удаление-дублирование - массив - O(n) - список O(1)

//Односвязный список нужно реализовать самостоятельно. 
//Не использовать std::forward_list.

//Ввести последовательность натуральных чисел. Если в 
//последовательности есть хотя бы одно число, 
//содержащее две одинаковых цифры, упорядочить последовательность 
//по неубыванию первой цифры числа. В противном случае удалить из 
//последовательности четные числа и продублировать нечетные числа. 
//Последовательность хранить в односвязном списке.