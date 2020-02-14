#ifndef KS_LINKLIST_H
#define KS_LINKLIST_H

#include<iostream>
using namespace std;

struct Node{
    int data;
    Node * pNext;
};

class LinkList
{
    private:
        Node *PHead;
    public:
        LinkList(){
            PHead = new Node;
            PHead->pNext = NULL;
        }//构造函数
        ~LinkList(){
            delete PHead;
        }//析构函数
        void create(int n);//按顺序插入
        //void create2(int n);//头部插入
        int Delete(int pos);//删除
        void print();
        void insert(int pos,int value);
        void sort_list(int len);
        bool Is_Empty(){//判断是否为空链表
            return (PHead->pNext==NULL);
        }
};

void LinkList::create(int n)
{
    Node *p, *q;
    q = PHead;
    for(int i=0; i<n; i++){
        p = new Node;
        cin>>p->data;
        q->pNext = p;
        q = p;
    }
    q->pNext = NULL;
}
/*
头部插入
void LinkList::create(int n)
{
    Node *p;
    for(int i=n; i>0; i--){
        p = new Node;
        cin>>p->data;
        p->pNext = PHead->pNext;
        PHead->pNext = p;
    }
}
*/
void LinkList::insert(int pos,int value)
{
    Node *p = PHead;
    int len = 0;
    while(p && len<pos-1){
        p = p->pNext;
        len++;
    }
    if(!p || len>pos-1){
        cout<<"第"<<pos-1<<"个元素不存在！"<<endl;
        exit(0);
    }
    Node *s = new Node;
    if(!s){
        cout<<"空间分配失败！"<<endl;
        exit(0);
    }
    s->data = value;
    s->pNext = p->pNext;
    p->pNext = s;
}


int LinkList::Delete(int pos)
{
    Node *p = PHead;
    int len = 0;
    while(p && len<pos-1){
        p = p->pNext;
        len++;
    }
    if(!p || p->pNext==NULL){
        cout<<"删除位置不存在！"<<endl;
        exit(0);
    }
    Node *q = p->pNext;
    p->pNext = q->pNext;
    int d = q->data;
    delete q;
    return d;
}

void LinkList::print()
{
    Node *p;
    p = PHead->pNext;
    while(p != NULL){
        cout<<p->data<<" ";
        p = p->pNext;
    }
    cout<<endl;
}

void LinkList::sort_list(int len)
{
    Node *p, *q;
    int i, j, t;
    for( i=0,p=PHead->pNext; i<len-1; ++i,p=p->pNext){
        for(j=i+1,q=p->pNext; j<len; ++j,q=q->pNext){
            if(p->data < q->data){
                t = p->data;
                p->data = q->data;
                q->data = t;
            }
        }
    }

}

//*******************************************************
/*
int main()
{
    LinkList L;
    int len,value,pos;
    cout<<"请输入链表长度：";
    cin>>len;
    cout<<"请输入链表元素的值：";
    L.create(len);
    cout<<"输出链表元素：";
    L.print();
    cout<<"对链表进行递减排序：";
    L.sort_list(len);
    L.print();
    cout<<"请选择删除元素位置：";
    cin>>pos;
    L.Delete(pos);
    cout<<"删除后：";
    L.print();
    cout<<"请选择插入元素位置和值：";
    cin>>pos>>value;
    L.insert(pos,value);
    cout<<"插入后：";
    L.print();

    return 0;
}

*/





#endif // KS_LINKLIST_H
