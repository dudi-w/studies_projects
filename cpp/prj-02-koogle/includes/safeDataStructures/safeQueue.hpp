#ifndef SAFE_QUEUE_HPP
#define SAFE_QUEUE_HPP

#include <queue>
#include <condition_variable>
#include <atomic>
#include <optional>

namespace se{

template<typename T>
class SafeQueue
{
public:
    explicit SafeQueue(size_t maxThreads);
    SafeQueue(SafeQueue const& other) = delete;
    SafeQueue& operator=(SafeQueue const& other) = delete;
    ~SafeQueue() = default;

public:
    bool deQueue(T& element);
    void inQueue(const T& elements);
    void inQueue(std::vector<T> const& elements);

private:
    std::queue<T> m_queue;
    std::mutex m_mutex;
    std::atomic<size_t> m_waiting;
    std::condition_variable m_cv;
    size_t m_maxThreads;
};

}// namespace se

#include "../src/safeDataStructures/safeQueue.inl"

#endif
