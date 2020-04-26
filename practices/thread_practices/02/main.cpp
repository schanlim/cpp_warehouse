#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

class MockCompositor
{
public:
    MockCompositor() {
        std::cout << __func__ << std::this_thread::get_id() << "\n";
    }
    ~MockCompositor() {
        std::cout << __func__ << std::this_thread::get_id() << "\n";
    }
};

class MockCompositorController {
public:
    MockCompositorController() {
        th = std::thread(run, this);
        std::cout << __func__ << std::this_thread::get_id() << "\n";
        alive = true;
        ready = false;
 
        {
            std::lock_guard<std::mutex> lock(m);
            ready = true;
            std::cout << "main() signals data ready for processing\n";
        }
        cv.notify_one();
   }

    ~MockCompositorController() {
        std::cout << __func__ << std::this_thread::get_id() << "\n";
        alive = false;
        process = true;
        cv.notify_one(); // wakeup thread for destroying it.
        th.join();
    }

private:
    std::thread th;
    std::mutex m;
    std::condition_variable cv;
    bool alive;
    bool ready;
    bool process;

    MockCompositor *mc;

    static void *run(void *data) {
        MockCompositorController *mcc = static_cast<MockCompositorController *>(data);
        MockCompositor mc;
        int cnt = 1;

        std::cout << __func__ << std::this_thread::get_id() << "\n";

        mcc->mc = &mc;

        std::cout << __func__ << cnt++ << "\n";

        {
            // wait until main() sends data
            std::unique_lock<std::mutex> lock(mcc->m);
            mcc->cv.wait(lock, [mcc]{return mcc->ready;});
        }

        std::cout << __func__ << cnt++ << "\n";

        while (mcc->alive) {
            {
                std::cout << __func__ << cnt++ << "\n";
                std::unique_lock<std::mutex> lock(mcc->m);
                mcc->cv.wait(lock, [mcc]{return mcc->process;});
            }

            mcc->process = false;
            
            std::cout << __func__ << cnt++ << "\n";
 
            std::cout << __func__ << std::this_thread::get_id() << "\n";
            std::this_thread::sleep_for(std::chrono::milliseconds(10));

            std::cout << __func__ << cnt++ << "\n";
       }
    }
};

int main(int, char**) {
    MockCompositorController mcc;

    std::this_thread::sleep_for(std::chrono::milliseconds(100));
}
