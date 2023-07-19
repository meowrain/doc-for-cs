#include <iostream>
struct Node {
    int data;
    Node* next;
};
void Insert(int);
void Print();
Node* head = NULL;
int main(void) {
    std::cout << "请输入你要存的数字个数：" << std::endl;
    int n;
    std::cin >> n;
    int arr[n+1];
    std::cout << "请输入你存的数字： " << std::endl;
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
    std::cout << "链表内容如下； " << std::endl;
    Node* cur = head;
    while(cur!=NULL){
        std::cout << cur->data << " ";
        cur = cur->next;
    }
}