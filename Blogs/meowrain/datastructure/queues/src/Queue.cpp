#include <iostream>
class Queue
{

public:
    Queue(int capacity) : capacity_(capacity), size_(0), front_(-1), rear_(-1)
    {
        data_ = new int[capacity_];
    }
    ~Queue()
    {
        delete[] data_;
    }
    bool empty()
    {
        if (size_ == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void push_back(int value) //入队操作
    {
        if (size_ == capacity_) // 队列已满
        {
            std::cout << "Queue is full!" << std::endl;
            return;
        }
        else if (empty()) // 如果是空的，直接让front_和rear_指向第一个元素
        {
            front_ = 0;
            rear_ = 0; // 队列中已有元素，front_ 和 rear_ 都指向第一个元素
        }
        else // 如果没有满，就让rear_指向下一个元素，然后把元素放进去
        {
            rear_ = (rear_ + 1) % capacity_; //循环队列，可以重复利用空间
        }
        data_[rear_] = value;
        size_++;
    }
    void pop() //出队操作
    {
        if (size_ == 0)
        {
            std::cout << "Queue is empty!" << std::endl;
            return;
        }
        else if (front_ == rear_) // 如果只有一个元素，那么就把front_和rear_都置为-1
        {
            front_ = -1;
            rear_ = -1;
            size_ = 0;
        }
        else
        {
            front_++;
            size_--;
        }
    }
    int front() //返回队头元素
    {
        if (size_ == 0)
        {
            std::cout << "Queue is empty!" << std::endl;
            return -1;
        }
        else
        {
            return data_[front_];
        }
    }
    int back() //返回队尾元素
    {
        if (size_ == 0)
        {
            std::cout << "Queue is empty!" << std::endl;
            return -1;
        }
        else
        {
            return data_[rear_];
        }
    }
    int size() {
        return size_;
    }
    //遍历队列
    void print() {
        if (size_ == 0) {
            std::cout << "Queue is empty!" << std::endl;
            return;
        }
        else {
            for (int i = front_; i != rear_; i = (i + 1) % capacity_) {
                std::cout << data_[i] << " ";
            }
            std::cout << data_[rear_] << std::endl;
        }
    }
private:
    int *data_;
    int capacity_;
    int size_;
    int front_;
    int rear_;
    /* 
    
    data_：一个整型数组，用于保存队列中的元素。
    capacity_：队列的容量。
    size_：队列中元素的个数。
    front_：队列头部元素的下标。
    rear_：队列尾部元素的下标。
    
     */
};
int main(void) {
    Queue q(5);
    q.push_back(1);
    q.push_back(2);
    q.push_back(3);
    q.push_back(4);
    q.push_back(5);
    std::cout << "front: " << q.front() << std::endl;
    std::cout << "back: " << q.back() << std::endl;
    std::cout << "size: " << q.size() << std::endl;
    std::cout << "Pop the first element of the queue: " << std::endl; // "出队操作
    q.pop();
    std::cout << "front: " << q.front() << std::endl;
    std::cout << "back: " << q.back() << std::endl;
    std::cout << "size: " << q.size() << std::endl;
    std::cout << "**************************" << std::endl;
    std::cout << "Print the queue: " << std::endl;
    q.print();
    return 0;
}