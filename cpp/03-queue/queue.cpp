    #include "queue.hpp"

    Queue::Queue():
    m_inStack(),
    m_outStack()
    {}

    void Queue::inQueue(int n)
    {
        m_inStack.push(n);
    }

    int Queue::deQueue()
    {
        if(m_outStack.isEmpty()){
            m_inStack.pouring(m_outStack);
        }
        return m_outStack.pop();
    }

    inline bool Queue::isEmpty() const
    {
        return (m_inStack.isEmpty() && m_outStack.isEmpty());
    }

    int Queue::front()
    {
        if(m_outStack.isEmpty()){
            m_inStack.pouring(m_outStack);
        }
        return m_outStack.top();
    }

    int Queue::back()
    {   
        if(m_inStack.isEmpty()){
            m_outStack.pouring(m_inStack);

        }
        return m_inStack.top();
    }

    inline size_t Queue::getSize() const
    {
        return m_inStack.getSize() + m_outStack.getSize();
    }

    void Queue::display() const
    {
        m_outStack.display();
        m_inStack.revDisplay();
    }

    void Queue::revDisplay() const
        {
            m_inStack.display();
            m_outStack.revDisplay();
        }