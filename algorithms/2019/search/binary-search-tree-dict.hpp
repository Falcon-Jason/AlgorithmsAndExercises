/**
 * @file: binary-search-tree-dict.hpp
 * @brief: 符号表之 二叉搜索树 实现
 */
#pragma once
#include <vector>

template <class K, class V>
class BinarySearchTreeDict
{
private:
    struct Node;
    Node *root; /* 根节点 */
    int sz;     /* 容器中元素个数 */

public:
    BinarySearchTreeDict();
    ~BinarySearchTreeDict();
    int size() const;
    bool empty() const;
    void clear();

    V &operator[](const K &key);
    void insert(const K &key, const V &value);
    bool remove(const K &key);
    const V get(const K &key, const V &defaultValue = V()) const;
    bool contains(const K &key) const;
    std::vector<std::pair<K, V>> toStdVector() const;

private:
    struct Node
    {
        K key;
        V value;
        Node *left;
        Node *right;
        Node(const K &key, const V &value)
        {
            this->key = key;
            this->value = value;
            left = right = nullptr;
        }
        void clear()
        {
            if(left != nullptr)
            {
                left->clear();
            }
            if(right != nullptr)
            {
                right->clear();
            }
            delete this;
        }
    };

    /* 根据键寻找节点 */
    Node *getNode(const K &key) const
    {
        Node *current = root;
        while (current != nullptr && current->key != key)
        {
            if (key < current->key)
            {
                current = current->left;
            }
            else
            {
                current = current->right;
            }
        }
        return current;
    }

    /* 根据键寻找节点所在位置 */
    Node *&getNode(const K &key)
    {
        Node *node = root;
        Node **pnode = &root;
        while (node != nullptr && node->key != key)
        {
            if (key < node->key)
            {
                pnode = &(node->left);
                node = node->left;
            }
            else
            {
                pnode = &(node->right);
                node = node->right;
            }
        }
        return *pnode;
    }

    /* node节点的最小子节点的位置 */
    Node *&minNode(Node *&node)
    {
        Node *min = node;
        Node **pmin = &node;
        while (min->left != nullptr)
        {
            pmin = &(min->left);
            min = min->left;
        }
        return *pmin;
    }

    /* 递归将树中内容放入表中 */
    void toStdVector(Node *node, std::vector<std::pair<K, V>> &target) const
    {
        if (node == nullptr)
            return;
        toStdVector(node->left, target);
        target.push_back(std::make_pair(node->key, node->value));
        toStdVector(node->right, target);
    }

    /* 交换两节点位置 */
    void swapNode(Node *&a, Node *&b)
    {
        Node *t = a;
        a = b;
        b = t;

        t = a->left;
        a->left = b->left;
        b->left = t->left;

        t = a->right;
        a->right = b->right;
        b->right = t->right;
    }
};

template <class K, class V>
BinarySearchTreeDict<K,V>::BinarySearchTreeDict()
{
    root = nullptr;
    sz = 0;
}

template <class K, class V>
BinarySearchTreeDict<K,V>::~BinarySearchTreeDict()
{
    clear();
}

template <class K, class V>
inline int BinarySearchTreeDict<K,V>::size() const
{
    return sz;
}

template <class K, class V>
inline bool BinarySearchTreeDict<K,V>::empty() const
{
    return sz == 0;
}

template <class K, class V>
inline void BinarySearchTreeDict<K,V>::clear()
{
    root->clear();
    sz = 0;
    root = nullptr;
}

template <class K, class V>
inline bool BinarySearchTreeDict<K,V>::contains(const K &key) const
{
    return getNode(key) != nullptr;
}

template <class K, class V>
inline const V BinarySearchTreeDict<K,V>::get(const K &key, const V &defaultValue) const
{
    Node *target = getNode(key);
    return target == nullptr ? defaultValue : target->value;
}

template <class K, class V>
inline V &BinarySearchTreeDict<K,V>::operator[](const K &key)
{
    if (!contains(key))
        insert(key, V());

    return getNode(key)->value;
}

template <class K, class V>
void BinarySearchTreeDict<K,V>::insert(const K &key, const V &value)
{
    if (root == nullptr)
    {
        sz++;
        root = new Node(key, value);
        return;
    }
    Node *current = root;
    Node *parent = nullptr;
    bool goleft;
    while (current != nullptr)
    {
        if (key < current->key)
        {
            parent = current;
            current = current->left;
            goleft = true;
        }
        else if (key > current->key)
        {
            parent = current;
            current = current->right;
            goleft = false;
        }
        else
        {
            current->value = value;
            return;
        }
    }

    auto new_node = new Node(key, value);
    if (goleft)
    {
        parent->left = new_node;
    }
    else
    {
        parent->right = new_node;
    }
    sz++;
}

template <class K, class V>
bool BinarySearchTreeDict<K,V>::remove(const K &key)
{
    Node *&node = getNode(key);
    if (node == nullptr)
        return false;

    if (node->left == nullptr && node->right == nullptr)
    {
        delete node;
        node = nullptr;
    }
    else if (node->left == nullptr)
    {
        node = node->right;
        delete node;
    }
    else if (node->right == nullptr)
    {
        node = node->left;
        delete node;
    }
    else
    {
        Node *&min = minNode(node->right);
        swapNode(min, node);
        delete min;
        min = nullptr;
    }
    return true;
}

template <class K, class V>
inline std::vector<std::pair<K, V>> BinarySearchTreeDict<K,V>::toStdVector() const
{
    std::vector<std::pair<K, V>> result;
    toStdVector(root, result);
    return result;
}