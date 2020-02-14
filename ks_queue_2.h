#ifndef KS_QUEUE_2_H
#define KS_QUEUE_2_H

#include<iostream>
#include<string.h>
using namespace std;

//顺序存储
template<typename T>
class Queue2
{
    private:
        T *Queue_space;
        int Capacity;
        int front;
        int rear;
        //Queue Q;

    public:
        ~Queue2();//析构函数
        Queue2(int Capacity);//构造函数
        int Insert(T item);//压入元素
        int DeleteQueue(int *dQ);//从头部弹出元素
        int print();
        int ClearQueue(); 	//清空队列
        bool Is_empty();
};

//构造函数
template<typename T>
Queue2<T>::Queue2(int Capacity)
{
    this->Queue_space = new T[Capacity];
    if( this->Queue_space == NULL){
        cout<<"创建队列失败！"<<endl;
    }else{
        this->front = this->rear = 0;
        this->Capacity = Capacity;
    }
}
//析构函数
template<typename T>
Queue2<T>::~Queue2()
{
    if(this->Queue_space != NULL){
        delete[] this->Queue_space;
    }
    this->front = this->rear = 0;
    this->Capacity = 0;
}

//判断队列是否满
template<typename T>
bool Queue2<T>::Is_empty()
{
    if(this->front==this->rear)
        return true;
    return false;
}

//入队
template<typename T>
int Queue2<T>::Insert(T item)
{
    int ret=0;
    if(this->Queue_space == NULL){
        cout << "空间尚未建立！--Push_2"<<endl;
        ret = -1;
        return ret;
    }

    if((rear+1) % Capacity == front){
        cout<<"队列已满！ --Push_2"<<endl;
        ret = -1;
        return ret;
    }
    this->Queue_space[rear%Capacity] = item;
    this->rear = (this->rear+1)%Capacity;
    return ret;
}

//头部弹出元素
template<typename T>
int Queue2<T>::DeleteQueue(int *dQ)
{
    int ret=0;
    if(this->Queue_space == NULL){
        cout << "空间尚未建立！--delete_2"<<endl;
        ret = -1;
        return ret;
    }
    if(Is_empty()){
        cout<<"队列长度为空！ --delete_2"<<endl;
        ret = -1;
        return ret;
    }
    *dQ = this->Queue_space[this->front];
    this->front = (this->front+1) % Capacity;

    return ret;
}

//输出
template<typename T>
int Queue2<T>::print()
{
    int ret=0;
    if(this->Queue_space == NULL){
        cout << "空间尚未建立！--Print_2"<<endl;
        ret = -1;
        return ret;
    }
    if(Is_empty()){
        cout<<"队列长度为空！ --Print_2"<<endl;
        ret = -1;
        return ret;
    }
    int p=front;
    int q=rear;
    while(p%Capacity != q){
        cout<<Queue_space[p]<<" ";
        p = (p+1)%Capacity;
    }
    return ret;
}

template<typename T>
int Queue2<T>::ClearQueue()
{
    int ret=0;
    if(this->Queue_space == NULL){
        cout<<"空间尚未建立！  --ClearQueue_2"<<endl;
        ret = -1;
        return ret;
    }
    int p=front;
    int q=rear;
    //数据类型转换
    while(p%Capacity != q){
        Queue_space[p]=0;
        p = (p+1)%Capacity;
    }
    cout<<"清空完成！  --ClearQueue_2"<<endl;
    return ret;
}
//=======================================
/*
int main()
{
    Queue<int> Q(6);
    int a[] = {1,2,3,4,5,6,7,8,9,10,11,12 };
    int ret = 0;
    int data;
    /*
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
    */
    /*
    for(int i=0; i<5; i++){
        ret = Q.Insert(a[i]);
    }
    cout<<endl;
    cout<<"入队后，队列中为："<<endl;
    Q.print();
    for(int i=0; i<2; i++){
        Q.DeleteQueue(&a[i]);
    }
    cout<<endl;
    cout<<"出队后，队列中为："<<endl;
    Q.print();
    Q.ClearQueue();
    Q.print();

    return 0;
}
*/




#endif // KS_QUEUE_2_H
