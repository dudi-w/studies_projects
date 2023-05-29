#ifndef SAFE_QUEUE_INL
#define SAFE_QUEUE_INL

#include "safeQueue.hpp"

template<typename T>
se::SafeQueue<T>::SafeQueue()
: SafeQueue([](){;}, [](){;})
{}

template<typename T>
se::SafeQueue<T>::SafeQueue(std::function<void(void)> sleep, std::function<void(void)> waekup)
: m_sleep(sleep)
, m_waekup(waekup)
, m_shutdown(false)
{}

#include <iostream>//?
template<typename T>
void se::SafeQueue<T>::deQueue(T& element)
{
    std::cout<<"deQueue  m_queue.size()"<<m_queue.size()<<" m_shutdown = "<<std::boolalpha<<m_shutdown<<std::endl;
    std::unique_lock<std::mutex> lock(m_mutex);
    while(true){
        if(m_shutdown){
            return;
        }
        if(!m_queue.empty()){
            element = m_queue.front();
            m_queue.pop();
            return;
        }else{
            m_sleep();
            m_cv.wait(lock ,[this](){return m_shutdown ? true : false;});
            m_waekup();
        }
    }
}

template<typename T>
void se::SafeQueue<T>::shutdown()
{
    if(m_queue.empty()){
        m_shutdown = true;
        m_cv.notify_all();
        std::cout<<"\033[1:33mshutdown\033[0m\n";
    }
}

// template<typename T>
// bool se::SafeQueue<T>::deQueue(T& element)
// {
//     std::unique_lock<std::recursive_mutex> lock(m_mutex);
//     while(true){
//         if(!m_queue.empty()){
//             element = m_queue.front();
//             m_queue.pop();
//             return true;
//         }else{
//             ++m_waiting;
//             if(m_waiting >= m_maxThreads){
//                 m_cv.notify_all();
//                 return false;
//             }
//             m_cv.wait(lock);
//             --m_waiting;
//         }
//     }
// }

template<typename T>
void se::SafeQueue<T>::inQueue(const T& element)
{
    std::unique_lock lock(m_mutex);
    // std::cout<<"se::SafeQueue<T>::inQueue "<<element<<std::endl;
    m_queue.push(element);
    m_cv.notify_one();
}

// template<typename T>
// void se::SafeQueue<T>::unsafeInQueue(const T& element)//?
// {
//     m_queue.push(element);
//     m_cv.notify_one();
// }

template<typename T>//Container
void se::SafeQueue<T>::inQueue(std::vector<T> const& elements)
{
    std::unique_lock lock(m_mutex);
    for(auto const& element : elements){
        // std::cout<<"se::SafeQueue<T>::inQueue(std::vector<T> "<<element<<std::endl;
        m_queue.push(element);
    }
    m_cv.notify_all();
}

#endif
