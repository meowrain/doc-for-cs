#include <iostream>
struct Node {
    int data;
    Node* next;
};
void Insert(int);
void Print();
Node* head = NULL;
int main(void) {
    std::cout << "��������Ҫ������ָ�����" << std::endl;
    int n;
    std::cin >> n;
    int arr[n+1];
    std::cout << "�������������֣� " << std::endl;
    for(int i = 1;i<=n;i++) {
        std::cin >> arr[i];
    }
    for(int i = n;i>=1;i--) {
        Insert(arr[i]);
    }
    Print();
    return 0;

}
void Insert(int x) {
    Node* temp = new Node();
    temp->data = x;
    temp->next = head;
    head = temp;
}
void Print() {
    std::cout << "�����������£� " << std::endl;
    Node* cur = head;
    while(cur!=NULL){
        std::cout << cur->data << " ";
        cur = cur->next;
    }
}