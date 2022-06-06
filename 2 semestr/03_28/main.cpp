#include "pqueue.hpp"

int main()
{
    PQueue<std::string> kolejka;
    kolejka.enqueue("Jeden", 1);
    kolejka.enqueue("Dwa", 1);
    kolejka.enqueue("Trzy", 1);
    kolejka.enqueue("Cztery", 1);
    kolejka.enqueue("Piec", 1);
    kolejka.enqueue("Szesc", 1);
    kolejka.enqueue("Siedem", 1);
    // kolejka.printQueue();
    std::cout << kolejka.dequeue() << std::endl;
    // kolejka.printQueue();
    std::cout << kolejka.dequeue() << std::endl;
    // kolejka.printQueue();
    std::cout << kolejka.dequeue() << std::endl;
    // kolejka.printQueue();
    std::cout << kolejka.dequeue() << std::endl;
    // kolejka.printQueue();
    std::cout << kolejka.dequeue() << std::endl;
    // kolejka.printQueue();
    std::cout << kolejka.dequeue() << std::endl;
    // kolejka.printQueue();
    std::cout << kolejka.dequeue() << std::endl;
    // kolejka.printQueue();
}