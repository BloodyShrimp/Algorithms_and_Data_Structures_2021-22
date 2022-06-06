#ifndef PQUEUE
#define PQUEUE
#include <vector>
#include <iostream>

template <class T>
class PQueue
{
public:
    PQueue();
    void enqueue(T value, int priority);
    T front();
    T dequeue();
    void printQueue();

private:
    struct Element
    {
        int priority;
        T data;
    };
    std::vector<Element> array;
    unsigned int size;
    int parent(int i);
    int leftChild(int i);
    int rightChild(int i);
    void pushUp(int i);
    void pushDown(int i);
    void swap(int first, int second);
};

template <class T>
PQueue<T>::PQueue()
{
    size = 0;
}

template <class T>
void PQueue<T>::enqueue(T value, int priority)
{
    Element temp;
    temp.data = value;
    temp.priority = priority;
    array.push_back(temp);
    pushUp(size);
    size++;
}

template <class T>
T PQueue<T>::front()
{
    if (size == 0)
    {
        throw std::logic_error("Pusta kolejka\n");
    }

    return array[0].data;
}

template <class T>
T PQueue<T>::dequeue()
{
    if (size == 0)
    {
        throw std::logic_error("Pusta kolejka\n");
    }
    size--;
    T val = array[0].data;
    array[0] = array[size];
    array.pop_back();
    pushDown(0);
    return val;
}

template <class T>
int PQueue<T>::parent(int i)
{
    return (i - 1) / 2;
}

template <class T>
int PQueue<T>::leftChild(int i)
{
    return ((2 * i) + 1);
}

template <class T>
int PQueue<T>::rightChild(int i)
{
    return ((2 * i) + 2);
}

template <class T>
void PQueue<T>::pushUp(int i)
{
    while (i > 0 && array[parent(i)].priority < array[i].priority)
    {
        swap(parent(i), i);
        i = parent(i);
    }
}

template <class T>
void PQueue<T>::pushDown(int i)
{
    int max = i;
    unsigned int l = leftChild(i);
    unsigned int r = rightChild(i);
    if (l <= size && array[l].priority > array[max].priority)
    {
        max = l;
    }
    if (r <= size && array[r].priority > array[max].priority)
    {
        max = r;
    }

    if (i != max)
    {
        swap(i, max);
        pushDown(max);
    }
}

template <class T>
void PQueue<T>::swap(int first, int second)
{
    Element temp;
    temp.data = array[first].data;
    temp.priority = array[first].priority;
    array[first] = array[second];
    array[second] = temp;
}

template <class T>
void PQueue<T>::printQueue()
{
    std::cout << std::string(50, '=') << std::endl;
    for (unsigned int i = 0; i < size; i++)
    {
        std::cout << "index: " << i << " priority: " << array[i].priority << " data: " << array[i].data << std::endl;
    }
    std::cout << std::string(50, '=') << std::endl;
}

#endif // PQUEUE
