//
// Created by yaoxp on 2023/10/4.
//

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int five() {
    return 5;
}

constexpr int six() {
    return 6;
}

struct ListNode {
    int val;
    ListNode *next;
    ListNode(): val(0), next(nullptr) {}
    explicit ListNode(int x): val(x), next(nullptr) {}
    ListNode(int x, ListNode* next): val(x), next(next) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode *node{};
    ListNode *tailNode{};
    int sum = 0;
    while (l1 || l2) {
        sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + sum;
        auto tmpNode = new ListNode(sum % 10);
        if (tailNode) {
            tailNode->next = tmpNode;
        } else {
            node = tmpNode;
        }
        tailNode = tmpNode;
        if (l1) l1 = l1->next;
        if (l2) l2 = l2->next;
        sum = sum / 10;
    }
    if (sum != 0) {
        auto tmpNode = new ListNode(sum);
        tailNode->next = tmpNode;
    }
    return node;
}

int main() {
    constexpr double gravity = 9.8;     // ok: 9.8 is a constant expression
    constexpr int sum{4 + 5};           // ok: 4 + 5 is a constant expression
    constexpr int something{sum};       // ok: sum is a constant expression

    cout << "Enter you age: ";
    int age{};
    cin >> age;

    // constexpr int myAge {age};          // compile error: age is not a constant expression
    // constexpr int f {five()};           // compile error: five is not a constant expression
    constexpr int s{six()};             // ok: six() is a constant expression
    return 0;
}