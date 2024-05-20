#pragma once
#include <cmath>
#include <iostream>
#include <limits>

template <typename T>
struct Node
{
    T data;
    Node *prev;
    Node *next;
    Node(const T &value) : data(value), prev(nullptr), next(nullptr) {}
};

template <typename T>
class LinkedList
{
private:
    Node<T> *head;
    Node<T> *tail;
    size_t listSize;

public:
    class Iterator;
    class ConstIterator;

    LinkedList() : head(nullptr), tail(nullptr), listSize(0) {}

    LinkedList(const LinkedList &other) : head(nullptr), tail(nullptr), listSize(0)
    {
        Node<T> *temp = other.head;
        while (temp)
        {
            push_back(temp->data);
            temp = temp->next;
        }
    }

    LinkedList(LinkedList &&other) noexcept : head(other.head), tail(other.tail), listSize(other.listSize)
    {
        other.head = nullptr;
        other.tail = nullptr;
        other.listSize = 0;
    }

    LinkedList &operator=(const LinkedList &other)
    {
        if (this != &other)
        {
            LinkedList temp(other);
            swap(temp);
        }
        return *this;
    }

    LinkedList &operator=(LinkedList &&other) noexcept
    {
        if (this != &other)
        {
            clear();
            head = other.head;
            tail = other.tail;
            listSize = other.listSize;
            other.head = nullptr;
            other.tail = nullptr;
            other.listSize = 0;
        }
        return *this;
    }

    ~LinkedList()
    {
        clear();
    }

    void print()
    {
        Node<T> *curr = head;
        while (curr)
        {
            std::cout << curr->data << " ";
            curr = curr->next;
        }
    }

    void push_back(const T &value)
    {
        Node<T> *newNode = new Node<T>(value);
        if (!head)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        listSize++;
    }

    void clear()
    {
        Node<T> *temp = head;
        while (temp)
        {
            Node<T> *next = temp->next;
            delete temp;
            temp = next;
        }
        head = nullptr;
        tail = nullptr;
        listSize = 0;
    }

    Iterator begin()
    {
        return Iterator(head);
    }

    Iterator end()
    {
        return Iterator(nullptr);
    }

    ConstIterator begin() const
    {
        return ConstIterator(head);
    }

    ConstIterator end() const
    {
        return ConstIterator(nullptr);
    }

    ConstIterator cbegin() const
    {
        return begin();
    }

    ConstIterator cend() const
    {
        return end();
    }

    bool operator==(const LinkedList &other) const
    {
        return listSize == other.listSize &&
               std::equal(begin(), end(), other.begin());
    }

    bool operator!=(const LinkedList &other) const
    {
        return !(*this == other);
    }

    void swap(LinkedList &other)
    {
        std::swap(head, other.head);
        std::swap(tail, other.tail);
        std::swap(listSize, other.listSize);
    }

    size_t size() const
    {
        return listSize;
    }

    size_t max_size() const
    {
        return std::numeric_limits<size_t>::max();
    }

    bool empty() const
    {
        return listSize == 0;
    }

    class Iterator
    {
    private:
        Node<T> *current;
        float temp;

    public:
        Iterator(Node<T> *node) : current(node), temp(0) {}

        Iterator &operator++()
        {
            if (current)
            {
                if (current->prev)
                {
                    float value = std::sqrt(temp);
                    temp = current->data;
                    current->data += value;
                }
                else
                    temp = current->data;
                current = current->next;
            }
            return *this;
        }

        Iterator operator++(int)
        {
            Iterator old = *this;
            ++(*this);
            return old;
        }

        T &operator*() const
        {
            return current->data;
        }

        bool operator==(const Iterator &other) const
        {
            return current == other.current;
        }

        bool operator!=(const Iterator &other) const
        {
            return !(*this == other);
        }
    };

    class ConstIterator
    {
    private:
        const Node<T> *current;
        const Node<T> *prev;

    public:
        ConstIterator(const Node<T> *node) : current(node) {}

        ConstIterator &operator++()
        {
            current = current->next;
            return *this;
        }

        ConstIterator operator++(int)
        {
            Iterator old = *this;
            if (current)
            {
                if (current != begin())
                {
                    double prevValue = *(std::prev(current));
                    double newValue = prevValue + sqrt(prevValue);
                    current->next = new Node<T>(newValue);
                    current->next->prev = current;
                    current = current->next;
                }
                else
                {
                    ++current;
                }
            }
            return old;
        }

        const T &operator*() const
        {
            return current->data;
        }

        bool operator==(const ConstIterator &other) const
        {
            return current == other.current;
        }

        bool operator!=(const ConstIterator &other) const
        {
            return !(*this == other);
        }
    };
};