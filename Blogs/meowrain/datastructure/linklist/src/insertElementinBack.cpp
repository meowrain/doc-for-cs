#include <iostream>

// ����һ���ṹ��Node����ʾ����Ľڵ�
struct Node
{
    int data;   // �洢�ڵ������
    Node *next; // ָ����һ���ڵ��ָ��
};

int main()
{
    Node *A = NULL;          // ����һ��ָ������ͷ�ڵ��ָ�룬��ʼֵΪNULL
    Node *temp = new Node(); // ����һ���µĽڵ�
    temp->data = 200;        // �����½ڵ������Ϊ200
    temp->next = NULL;       // �½ڵ����һ���ڵ�ΪNULL
    A = temp;                // ���½ڵ�����Ϊ�����ͷ�ڵ�

    temp = new Node(); // �ٴδ���һ���µĽڵ�
    temp->data = 4;    // �����½ڵ������Ϊ4
    temp->next = NULL; // �½ڵ����һ���ڵ�ΪNULL

    Node *temp1 = A; // ����һ��ָ��temp1����ʼֵָ������ͷ�ڵ�
    // ���������Ե����������һ���ڵ�
    while (temp1->next != NULL)
    {
        temp1 = temp1->next; // ��temp1ָ����һ���ڵ㣬ֱ�������������һ���ڵ�
    }
    temp1->next = temp; // ���½ڵ���ӵ���������һ���ڵ���棬ʵ�ֲ������

    std::cout << "����ɹ��������������" << std::endl; // �����ʾ��Ϣ

    while (A != NULL) // �������������������
    {
        std::cout << A->data << std::endl; // �����ǰ�ڵ������
        A = A->next;                       // ��ָ��Aָ����һ���ڵ㣬������������
    }
    delete temp;
    delete temp1;
    return 0;
}