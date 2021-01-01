/**
 * @file: black-red-tree-dict.hpp
 * @brief: 符号表之 哈希表 实现, 使用拉链法解决哈希冲突
 */

#pragma once
#include <vector>

template <class K, class V>
class HashDict
{
private:
    struct Node;
    Node *bucket;
    int sz;     /* 容器中元素个数 */

public:
    HashDict(int bucket_count = 16);
    ~HashDict();
    int size() const;
    bool empty() const;
    void clear();

    V &operator[](const K &key);
    void insert(const K &key, const V &value);
    bool remove(const K &key);
    const V get(const K &key, const V &defaultValue = V()) const;
    bool contains(const K &key) const;
    std::vector<std::pair<K, V>> toStdVector() const;
};