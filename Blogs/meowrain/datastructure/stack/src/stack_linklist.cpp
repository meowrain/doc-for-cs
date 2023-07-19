#include <iostream>
struct Node {
    int data;
    Node *next;
};
class Stack {
private:
    Node *top;
public:
    Stack() {
        top = nullptr;
    }
    void push(int val) {
        Node *node = new Node();
        node->data = val;
        node->next = top;
        top = node;
    }
    void pop() {
        if(top != nullptr) {
            Node *node = top;
            top = top->next;
            delete node;
        }
    }
    int topVal() {
        if(top != nullptr) {
            return top->data;
        }else {
            return -1;
        }
    }
    bool isEmpty() {
        return top == nullptr;
    }
};
int main(void) {
    Stack s;
    for(int i = 0; i < 200; i++) {
        s.push(i);
    }
    while(!s.isEmpty()) {
        std::cout << s.topVal() << std::endl;
        s.pop();
    }
}