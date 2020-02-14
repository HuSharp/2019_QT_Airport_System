#ifndef KS_QUEUE_H
#define KS_QUEUE_H

#include<iostream>
#include<string.h>
using namespace std;

//顺序存储
template<typename T>
class Queue
{
    private:
        T *Queue_space;
        int Capacity;
        int QueueLen;
        //Queue Q;

    public:
        ~Queue();//析构函数
        Queue(int Capacity);//构造函数
        int Push(T item);//压入元素
        T Pop();//从头部弹出元素
        int print();
        int GetQueueNum();	//获取元素个数
        int ClearQueue(); 	//清空队列
};

//构造函数
template<typename T>
Queue<T>::Queue(int Capacity)
{
    this->Queue_space = new T[Capacity];
    if( this->Queue_space == NULL){
        cout<<"创建队列失败！"<<endl;
    }else{
        this->Capacity = Capacity;
        this->QueueLen = 0;
    }
}
//析构函数
template<typename T>
Queue<T>::~Queue()
{
    if(this->Queue_space != NULL){
        delete[] this->Queue_space;
    }
    this->QueueLen = 0;
    this->Capacity = 0;
}

//获取元素个数
template<typename T>
int Queue<T>::GetQueueNum()
{
    int ret=0;
    int len=0;
    if(this->Queue_space == NULL){
        cout << "空间尚未建立！--GetQueueNum"<<endl;
        ret = -1;
        return ret;
    }
    //转换数据类型
    return this->QueueLen;
}

//入队
template<typename T>
int Queue<T>::Push(T item)
{
    int ret=0;
    if(this->Queue_space == NULL){
        cout << "空间尚未建立！--Push"<<endl;
        ret = -1;
        return ret;
    }
    int len = GetQueueNum();
    if(len < 0){
        cout<<"队列长度为负！ --Push"<<endl;
        ret = -1;
        return ret;
    }
    if(len >= this->Capacity){
        cout<<"队列已满！ --Push"<<endl;
        ret = -1;
        return ret;
    }
    this->Queue_space[len] = item;
    this->QueueLen++;
    return ret;
}

//头部弹出元素
template<typename T>
T Queue<T>::Pop()
{
    T Pop_item;
    int ret=0;
    if(this->Queue_space == NULL){
        cout << "空间尚未建立！--Push"<<endl;
        ret = -1;
        return ret;
    }
    int len = GetQueueNum();
    if(len <= 0){
        cout<<"队列长度为空！ --Push"<<endl;
        ret = -1;
        return ret;
    }
    this->QueueLen--;
    Pop_item = this->Queue_space[0];
    //从后向前依次移动一位
    T t;
    for(int i=0; i<len-1; i++){
        t = this->Queue_space[i+1];
        this->Queue_space[i] = t;
    }

    return Pop_item;
}

//输出
template<typename T>
int Queue<T>::print()
{
    int ret=0;
    if(this->Queue_space == NULL){
        cout << "空间尚未建立！--Print"<<endl;
        ret = -1;
        return ret;
    }
    int len = GetQueueNum();
    if(len <= 0){
        cout<<"队列长度为空！ --Print"<<endl;
        ret = -1;
        return ret;
    }
    for(int i=0; i<len; i++){
        cout<<this->Queue_space[i]<<" ";
    }
    return ret;
}

template<typename T>
int Queue<T>::ClearQueue()
{
    int ret=0;
    int len=0;
    if(this->Queue_space == NULL){
        cout<<"空间尚未建立！  --ClearQueue"<<endl;
        ret = -1;
        return ret;
    }
    //数据类型转换
    memset(this->Queue_space, 0, sizeof(this->Queue_space));
    this->QueueLen = 0;
    cout<<"清空完成！  --ClearQueue"<<endl;
    return ret;
}
//=======================================
/*
int main()
{
    Queue<int> Q(5);
    int a[] = {1,2,3,4,5,6,7,8,9,10,11,12 };
    int ret = 0;
    int data;
    int capacity,value;

    //cout<<"请输入队列容量："<<endl;
    //cin>>capacity;
    //ret = Q.Queue(capacity);
    cout<<"请输入入队元素："<<endl;
    for(int i=0; i<capacity; i++){
        cin>>value;
        ret = Q.Push(value);
    }

    for(int i=0; i<capacity; i++){
        data = Q.Pop();
    }


    for(int i=0; i<5; i++){
        ret = Q.Push(a[i]);
    }
    cout<<endl;
    cout<<"入队后，队列中为："<<endl;
    Q.print();
    for(int i=0; i<2; i++){
        data = Q.Pop();
    }
    cout<<endl;
    cout<<"出队后，队列中为："<<endl;
    Q.print();
    Q.ClearQueue();
    Q.print();

    return 0;
}
*/






#endif // KS_QUEUE_H
