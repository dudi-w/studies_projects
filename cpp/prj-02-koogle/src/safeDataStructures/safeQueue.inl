#ifndef SAFE_QUEUE_INL
#define SAFE_QUEUE_INL

#include "safeQueue.hpp"

template<typename T>
se::SafeQueue<T>::SafeQueue(size_t maxThreads)
: m_waiting(0)
, m_maxThreads(maxThreads)
{}

template<typename T>
std::optional<T> se::SafeQueue<T>::deQueue()
{
    std::unique_lock<std::mutex> lock(m_mutex);
    while(true){
        if(!m_queue.empty()){
            T element = m_queue.front();
            m_queue.pop();
            return element;
        }else{
            ++m_waiting;
            if(m_waiting >= se::Configuration::maxThreads()){
                m_cv.notify_all();
                return std::nullopt;
            }
            m_cv.wait(lock);
            --m_waiting;
        }
    }
}

template<typename T>
void se::SafeQueue<T>::inQueue(const T& element)
{
    std::unique_lock lock(m_mutex);
    m_queue.push(element);
    m_cv.notify_all();
}

template<typename T>
void se::SafeQueue<T>::inQueue(std::vector<T> const& elements)
{
    std::unique_lock lock(m_mutex);
    for(auto const& element : elements){
        m_queue.push(element);
    }
    m_cv.notify_all();
}

#endif
