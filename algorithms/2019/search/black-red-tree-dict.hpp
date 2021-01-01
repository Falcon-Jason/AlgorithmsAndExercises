/**
 * @file: black-red-tree-dict.hpp
 * @brief: 符号表之 红黑树 实现
 */
#pragma once

#include <vector>
template <class K, class V>
class BlackRedTreeDict
{
private:
    struct Node;
    Node *root; /* 根节点 */
    int sz;     /* 容器中元素个数 */

public:
    BlackRedTreeDict();
    ~BlackRedTreeDict();
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
    enum class Color : bool
    {
        BLACK = false,
        RED = true,
    };

    struct Node
    {
        K key;
        V value;
        Node *left;
        Node *right;
        Color color;

        Node(const K &key, const V &value, Color color)
        {
            this->key = key;
            this->value = value;
            this->color = color;
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

    bool isRed(Node *node)
    {
        return node != nullptr && node->color == Color::RED;
    }

    void rotateLeft(Node *&node)
    {
        Node *r = node->right;
        node->right = r->left;
        r->left = node;
        r->color = node->color;
        node->color = Color::RED;
        node = r;
    }

    void rotateRight(Node *&node)
    {
        Node *l = node->left;
        node->left = l->right;
        l->right = node;
        l->color = node->color;
        node->color = Color::RED;
        node = l;
    }

    void flipColor(Node *node)
    {
        node->left->color = node->right->color = Color::BLACK;
        node->color = Color::RED;
    }

    void toStdVector(Node *node, std::vector<std::pair<K, V>> &target) const
    {
        if (node == nullptr)
            return;
        toStdVector(node->left, target);
        target.push_back(std::make_pair(node->key, node->value));
        toStdVector(node->right, target);
    }

    void insert(Node *&node, const K &key, const V &value)
    {
        if (node == nullptr)
        {
            node = new Node(key, value, Color::RED);
            sz++;
            return;
        }

        if (key < node->key)
        {
            insert(node->left, key, value);
        }
        else if (key > node->key)
        {
            insert(node->right, key, value);
        }
        else
        {
            node->value = value;
        }

        if (isRed(node->right) &&
            !isRed(node->left))
        {
            rotateLeft(node);
        }
        if (isRed(node->left) &&
            isRed(node->left->left))
        {
            rotateRight(node);
        }
        if (isRed(node->left) &&
            isRed(node->right))
        {
            flipColor(node);
        }
    }
};

template <class K, class V>
bool BlackRedTreeDict<K,V>::remove(const K& key)
{
    
}

template <class K, class V>
BlackRedTreeDict<K,V>::BlackRedTreeDict()
{
    root = nullptr;
    sz = 0;
}

template <class K, class V>
BlackRedTreeDict<K,V>::~BlackRedTreeDict()
{
    clear();
}

template <class K, class V>
inline int BlackRedTreeDict<K,V>::size() const
{
    return sz;
}

template <class K, class V>
inline bool BlackRedTreeDict<K,V>::empty() const
{
    return sz == 0;
}

template <class K, class V>
inline void BlackRedTreeDict<K,V>::clear()
{
    root->clear();
    sz = 0;
    root = nullptr;
}

template <class K, class V>
inline bool BlackRedTreeDict<K,V>::contains(const K &key) const
{
    return getNode(key) != nullptr;
}

template <class K, class V>
inline const V BlackRedTreeDict<K,V>::get(const K &key, const V &defaultValue) const
{
    Node *target = getNode(key);
    return target == nullptr ? defaultValue : target->value;
}

template <class K, class V>
inline V &BlackRedTreeDict<K,V>::operator[](const K &key)
{
    if (!contains(key))
        insert(key, V());

    return getNode(key)->value;
}

template <class K, class V>
void BlackRedTreeDict<K,V>::insert(const K &key, const V &value)
{
    insert(root, key, value);
    root->color = Color::BLACK;
}

template <class K, class V>
inline std::vector<std::pair<K, V>> BlackRedTreeDict<K,V>::toStdVector() const
{
    std::vector<std::pair<K, V>> result;
    toStdVector(root, result);
    return result;
}