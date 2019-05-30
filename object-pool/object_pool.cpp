#include <iostream>
#include <list>

class Thread
{
    int threadID;

public:
    Thread(int thread_id)
    {
        threadID = thread_id;
    }

    int get_threadID()
    {
        return threadID;
    }
};

class ThreadPool
{
private:
    std::list<Thread*> threads;

    int threadCount;

    ThreadPool() 
    {
        threadCount = 0;
    }
    ~ThreadPool() {}
public:
    static ThreadPool* instance()
    {
        static ThreadPool instance;
        return &instance;
    }
    
    Thread* getThread()
    {
        if (threads.empty())
        {
            std::cout<< "Creating new Thread" << std::endl;
            return new Thread(++threadCount);
        }
        else
        {
            std::cout << "Reusing existing thread"<< std::endl;
            Thread* thread = threads.front();
            threads.pop_front();
            return thread;
        }
    }

    void returnThreadToPool(Thread* thread)
    {
        threads.push_back(thread);
    }
};

int main()
{
    Thread* t_one = ThreadPool::instance()->getThread();
    Thread* t_two = ThreadPool::instance()->getThread();
    
    std::cout<< "Thread ID of t_one = "<< t_one->get_threadID()<<std::endl;
    std::cout<< "Thread ID of t_two = "<< t_two->get_threadID()<<std::endl;

    std::cout<< "Returning t_one to pool"<<std::endl;
    ThreadPool::instance()->returnThreadToPool(t_one);
    
    Thread* t_three = ThreadPool::instance()->getThread();
    std::cout<< "Thread ID of t_three = "<< t_three->get_threadID()<<std::endl;
    return 1;
}
