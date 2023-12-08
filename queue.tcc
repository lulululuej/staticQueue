#include <iostream>
template<typename T, size_t N>
void Queue<T,N>::enqueue(T value) {
    queue[tail%N] = value;
    ++tail;
}

template<typename T, size_t N>
T Queue<T,N>::dequeue() {
    int idx = head%N;
    ++head;
    return queue[idx];
}

template<typename T, size_t N>
bool Queue<T,N>::empty() const{
    if(head == tail)
        return true;
    else
        return false;
}

template<typename T, size_t N>
bool Queue<T,N>::full() const{
    if((tail - head) >= N)
        return true;
    else
        return false;
}

template<typename T, size_t N>
T& Queue<T,N>::front() {
    return queue[head%N];
}

template<typename T, size_t N>
const T& Queue<T,N>::front() const{
    return queue[head%N];
}

template<typename T, size_t N>
template<size_t M>
Queue<T, N+M> Queue<T,N>::copy_and_expand() {
    Queue<T, N+M> result;

    for(size_t i{0}; i < N; ++i) {
        result.queue[i] = queue[i];
    }
    result.tail = tail - head;
    return result;
}