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
            while(!m_inStack.isEmpty()){
                m_outStack.push(m_inStack.pop());
            }
        }
        return m_outStack.pop();
    }

    bool Queue::isEmpty()
    {
        return (m_inStack.isEmpty() && m_outStack.isEmpty());
    }

    int Queue::front()
    {
        if(m_outStack.isEmpty()){
            while(!m_inStack.isEmpty()){
                m_outStack.push(m_inStack.pop());
            }
        }
        return m_outStack.top();
    }

    int Queue::back()
    {   
        if(m_inStack.isEmpty()){
            while(!m_outStack.isEmpty()){
                m_inStack.push(m_outStack.pop());
            }
        }
        return m_inStack.top();
    }

    int Queue::size()
    {
        return m_inStack.getSize() + m_outStack.getSize();
    }

    void Queue::display()
    {
        m_outStack.display();
        if(!m_inStack.isEmpty()){
            Stack temp;
            while(!m_inStack.isEmpty()){
                temp.push(m_inStack.pop());
            }
            temp.display();
            while(!temp.isEmpty()){
                m_inStack.push(temp.pop());
            }
        }
    }
