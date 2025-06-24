
#include <thread>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <chrono>
#include <semaphore.h>
#include <semaphore>
    // class ProducerConsu
// {
// private:
    // std::queue<int> dataQueue;  // Shared queue
    // std::mutex mtx;             // Mutex to protect the shared queue
    // std::condition_variable cv; // Condition variable for synchronization
    // bool done = false;          // Flag to indicate when production is done
// 
// public:
    // Producer function to add items to the queue
    // void producer()
    // {
        // for (int i = 0; i < 5; ++i)
        // {
            // std::this_thread::sleep_for(std::chrono::milliseconds(200)); // Simulate work
            // {
                // std::lock_guard<std::mutex> lock(mtx); // Lock the mutex
                // dataQueue.push(i);                     // Add an item to the queue
                // std::cout << "Produced: " << i << std::endl;
            // }
            // cv.notify_one(); // Notify the consumer thread
        // }
// 
        // Mark production as done and notify the consumer
        // done = true;
        // cv.notify_one(); // Notify consumer to stop if the queue is empty
    // }
// 
    // Consumer function to consume items from the queue
    // void consumer()
    // {
        // while (true)
        // {
            // std::unique_lock<std::mutex> lock(mtx); // Lock the mutex
// 
            // Wait until there is data in the queue or production is done
            // cv.wait(lock, [this]
                    // { return !dataQueue.empty() || done; });
// 
            // If there are items in the queue, consume them
            // while (!dataQueue.empty())
            // {
                // int item = dataQueue.front();
                // dataQueue.pop(); // Remove the item from the queue
                // std::cout << "Consumed: " << item << std::endl;
            // }
// 
            // Exit the loop if production is done and queue is empty
            // if (done && dataQueue.empty())
            // {
                // break;
            // }
        // 
    // }
// };
class ProducerConsumer{ 
private:
std::queue<int> dataQueue;                      // Shared queue
std::binary_semaphore mutex{1};                 // Mutex semaphore (1 allows only one thread at a time)
std::counting_semaphore<10> availableItems{0};  // Semaphore to track available items
std::counting_semaphore<10> availableSpace{10}; // Semaphore to track available space in the queue
bool done = false;
// 
// / Producer function to add items to the queue
public:
void producer()
{
    for (int i = 0; i < 5; ++i)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(200)); // Simulate work

        availableSpace.acquire(); // Wait for space in the queue
        mutex.acquire();          // Lock the queue

        dataQueue.push(i); // Add an item to the queue
        std::cout << "Produced: " << i << std::endl;

        mutex.release();          // Unlock the queue
        availableItems.release(); // Signal that an item is available
    }

    availableItems.release(10); // Ensure consumer can exit gracefully
    done = true;
}

void consumer()
{
    while (true)
    {
        availableItems.acquire(); // Wait for an available item

        mutex.acquire(); // Lock the queue
        if (done && dataQueue.empty())
        {
            mutex.release();
            break; // Exit if production is done and queue is empty
        }

        if (!dataQueue.empty())
        {
            int item = dataQueue.front();
            dataQueue.pop(); // Remove the item from the queue
            std::cout << "Consumed: " << item << std::endl;
        }
        mutex.release();          // Unlock the queue
        availableSpace.release(); // Signal that space is available
    }
}
};