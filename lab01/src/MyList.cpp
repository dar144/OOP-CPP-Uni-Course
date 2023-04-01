#include "MyList.h"

MyList::MyList(int data): MyList()
{
    std::cout << "KONST: Jednoargumentowy" << std::endl;
    _size = data;

    if(_size != 0)
        _head =  new MyNode(0);

    MyNode* tmp = _head;

    for(int i = 1; i < data; i++)
    {
        tmp->_next = new MyNode(i);
        tmp = tmp->_next;
    }
}


MyList::MyList(std::initializer_list<int> list)
{
    std::cout << "KONST: std::initializer_list" << std::endl;
    _size = list.size();   
    _head = nullptr;

    const int * beg = list.begin();

    if(_size != 0)
        _head = new MyNode(*beg);

    MyNode* tmp = _head;

    for(int i = 1; i < _size; i++)
    {
        beg++;
        tmp->_next = new MyNode(*beg);
        tmp = tmp->_next;
    }    
}


MyList::MyList(std::function<int(MyNode*)> fun, int size)
{
    std::cout << "KONST: funkcja generujaca" << std::endl;
    _size = size;
    _head = nullptr;

    if (_size != 0)
        _head = new MyNode(fun(_head));  

    MyNode* tmp = _head;

    for(int i = 1; i < _size; i++)
    {
        tmp->_next = new MyNode(fun(tmp));
        tmp = tmp->_next;
    }       
}


MyList::MyList(const MyList& list): MyList(list._size)
{
    std::cout << "KONST: kopiujacy" << std::endl;
}


MyList::MyList(MyList&& list): _size(std::exchange(list._size, 0)), _head(std::exchange(list._head, nullptr))
{
    std::cout << "KONST: przenoszacy" << std::endl;
}


MyList::~MyList()
{
    std::cout << "DESTRUKTOR (rozmiar = " << _size << ")" << std::endl;
}


void MyList::clear()
{
    MyNode* tmp = _head;
    MyNode* next;

    while (tmp != nullptr)
    {
        next = tmp->_next;
        delete tmp;
        tmp = next;
    }

    _head = nullptr;
    _size = 0;
}


void MyList::add(int i)
{
    if(_head == nullptr)
        _head = new MyNode(i);
    else
    {
        MyNode* tmp = _head;

        while (tmp->_next != nullptr)
            tmp = tmp->_next;
        tmp->_next = new MyNode(i);
    }

    _size++;
}


void MyList::print() const
{
    std::cout << '[';
    MyNode* tmp = _head;

    if(_head != nullptr)
    {
        while(tmp->_next != nullptr)
        {
            std::cout << tmp->_data << ", ";
            tmp = tmp->_next;
        }
        std::cout << tmp->_data;
    }
    std::cout << "]\n";
}