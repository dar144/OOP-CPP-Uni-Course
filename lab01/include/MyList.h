#pragma once

#include <string>
#include <iostream>
#include <initializer_list>
#include <functional>

class MyNode {
    friend class MyList;

    public:
        MyNode(const int data): _data(data), _next(nullptr) {}
        inline int val() { return _data; };

    private:
        int _data;
        MyNode* _next;
};

class MyList {
    public:
        MyList(): _head(nullptr), _size(0) { std::cout << "KONST: Domyslny" << std::endl; }
        MyList(int data);
        MyList(std::initializer_list<int> list);
        MyList(std::function<int(MyNode*)> fun, int size);
        MyList(const MyList& list);
        MyList(MyList&& list);
        ~MyList();

        void clear();
        void add(int i);
        inline bool empty() const { return _head == nullptr ? true : false; }
        inline int size() const { return _size; }
        void print() const;

    private:
        MyNode * _head;
        int _size;
};