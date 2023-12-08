#ifndef QUEUE_H
#define QUEUE_H
#include <stdexcept>

template<typename T, size_t N>
class Queue
{
private:
    T queue[N]{};
    int head {};
    int tail {};
public:
    void enqueue(T value) ;
    T dequeue();
    bool empty() const;
    bool full() const;
    void clear();
    T& front();
    const T& front() const;
    template <size_t M>
    Queue<T, N+M> copy_and_expand();

    template<typename U, size_t Z>
    friend class Queue;
};

/*class queue_error : public std::runtime_error {

};*/
#include "queue.tcc"
#endif //QUEUE_H