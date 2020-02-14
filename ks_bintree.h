#ifndef KS_BINTREE_H
#define KS_BINTREE_H

#define _BSTREE_H

#include <iostream>
#include <assert.h>
using namespace std;

template <typename T>
class BSTree;

template <typename T>
class TreeNode{
    friend class BSTree<T>;
public:
    TreeNode() : m_data(T()), leftChild(NULL), rightChild(NULL)
    {}
    TreeNode(T data, TreeNode<T> *left = NULL, TreeNode<T> *right = NULL)
            : m_data(data), leftChild(left), rightChild(right)
    {}
    //~TreeNode() = default;
private:
    T m_data;
    TreeNode<T> *leftChild;
    TreeNode<T> *rightChild;
};

template <typename T>
class BSTree{
    typedef TreeNode<T> node_type;
public:
    BSTree() :root(NULL)
    {}
    ~BSTree();
public:
    BSTree<T>& operator=(const BSTree<T>&);

    void insert_elem(const T&);
    bool remove_elem(const T&);
    void inorder_traverse()const;

    T find_max()const;
    T find_min()const;
    node_type *search_elem(const T&)const;
protected:

    void insert_elem(node_type *&, const T&);
    bool remove_elem(node_type *&, const T&);
    void inorder_traverse(node_type *)const;
    void destroy_tree(node_type *&);

    T find_max(node_type *)const;
    T find_min(node_type *)const;
    node_type *search_elem(node_type *, const T&)const;
private:
    node_type *root;
};

//public interface

template <typename T>
BSTree<T>& BSTree<T>::operator=(const BSTree<T>& bst)
{
    if(this != &bst){
        root = copy_tree(bst.root);
    }
    return *this;
}

template <typename T>
BSTree<T>::~BSTree()
{
    destroy_tree(root);
}

template <typename T>
void BSTree<T>::insert_elem(const T& val)
{
    insert_elem(root, val);
}

template <typename T>
bool BSTree<T>::remove_elem(const T& val)
{
    remove_elem(root, val);
    return 0;
}

template <typename T>
void BSTree<T>::inorder_traverse()const
{
    inorder_traverse(root);
}

template <typename T>
T BSTree<T>::find_max()const
{
    return find_max(root);
}

template <typename T>
T BSTree<T>::find_min()const
{
    return find_min(root);
}

template <typename T>
TreeNode<T>* BSTree<T>::search_elem(const T& target)const
{
    search_elem(root, target);
    return 0;
}

//protected interface

template <typename T>
void BSTree<T>::insert_elem(node_type *&t, const T& val)
{
    if(t == NULL){
        t = new node_type(val);
        return ;
    }

    if(t->m_data > val)
        insert_elem(t->leftChild, val);
    else if(t->m_data < val)
        insert_elem(t->rightChild, val);
    else
        return ;
}

template <typename T>
void BSTree<T>::inorder_traverse(node_type *t)const
{
    if(t != NULL){
        inorder_traverse(t->leftChild);
        cout << t->m_data << " ";
        inorder_traverse(t->rightChild);
    }
}

template <typename T>
bool BSTree<T>::remove_elem(node_type *&t, const T& val)
{
    if(t == NULL)
        return false;

    if(t->m_data > val)
        remove_elem(t->leftChild, val);
    else if(t->m_data < val)
        remove_elem(t->rightChild, val);
    else{
        if(t->leftChild != NULL && t->rightChild != NULL){
            node_type *tmp = t;
            tmp = t->rightChild;
            while(tmp->leftChild != NULL)
                tmp = tmp->leftChild; //选择右子树的最左边叶子结点替换方式
            t->m_data = tmp->m_data;
            remove_elem(t->rightChild, t->m_data);
            //delete tmp；           //error，此处不能直接delete，否则只能释放该节点，但该节点仍旧链接在二叉树上，需通过t指针释放并更改二叉树，另外一个原因是如果tmp元素有一个孩子，Remove递归会调用删除有一个孩子节点的情况，下面的else。例:上面图中38元素若存在一个右孩子39元素，就属于此类情况
        }
        else{
            node_type *tmp = t;
            if(t->leftChild != NULL)
                t = t->leftChild;
            else
                t = t->rightChild;
            delete tmp;
        }
        return true;
    }
}

template <typename T>
void BSTree<T>::destroy_tree(node_type *&t)
{
    if(t != NULL){
        destroy_tree(t->rightChild);
        destroy_tree(t->leftChild);
        delete t;
    }
}

template <typename T>
T BSTree<T>::find_max(node_type *t)const
{
    while(t->leftChild != NULL)
        t = t->leftChild;
    return t->m_data;
}

template <typename T>
T BSTree<T>::find_min(node_type *t)const
{
    while(t->rightChild != NULL)
        t = t->rightChild;
    return t->m_data;
}

template <typename T>
TreeNode<T>* BSTree<T>::search_elem(node_type *t, const T& target)const
{
    if(t == NULL)
        return NULL;
    else if(t->m_data > target)
        search_elem(t->leftChild, target);
    else if(t->m_data < target)
        search_elem(t->rightChild, target);
    else
        return t;
}

//*******************************************************************
/*
int main()
{
    int array[] = {32, 43, 1, 76, 54, 13, 42, 18, 139, 4};
    BSTree<int> bst;

    int len = sizeof(array) / sizeof (int);
    for(int i=0; i<len; ++i){
        bst.insert_elem(array[i]);
    }

    bst.inorder_traverse();
    cout << endl;

    cout << bst.find_max() << endl;
    cout << bst.find_min() << endl;

    cout << bst.search_elem(139) << endl;

    bst.remove_elem(32);
    bst.inorder_traverse();
    cout << endl;


    return 0;
}
*/



#endif // KS_BINTREE_H
