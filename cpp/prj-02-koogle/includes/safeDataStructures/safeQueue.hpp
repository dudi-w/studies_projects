#ifndef SAFE_QUEUE_HPP
#define SAFE_QUEUE_HPP

#include <queue>
#include <condition_variable>
#include <functional>

namespace se{

template<typename T>
class SafeQueue
{
public:
    SafeQueue();
    explicit SafeQueue(std::function<void(void)> sleep, std::function<void(void)> waekup);
    SafeQueue(SafeQueue const& other) = delete;
    SafeQueue& operator=(SafeQueue const& other) = delete;
    ~SafeQueue() = default;

public:
    void deQueue(T& element);
    void inQueue(const T& element);
    void shutdown();
    // void unsafeInQueue(const T& elements);//!
    void inQueue(std::vector<T> const& elements);

private:
    std::queue<T> m_queue;
    std::mutex m_mutex;
    // std::atomic<size_t> m_waiting;
    std::condition_variable m_cv;
    // const size_t m_maxThreads;
    std::function<void(void)> m_sleep;
    std::function<void(void)> m_waekup;
    std::atomic<bool> m_shutdown;
};

}// namespace se

#include "../src/safeDataStructures/safeQueue.inl"

#endif
