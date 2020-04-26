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
        std::cout << __func__ << std::this_thread::get_id() << "\n";
        th = std::thread(run, this);
        alive = true;
        ready = false;
    }

    ~MockCompositorController() {
        std::cout << __func__ << std::this_thread::get_id() << "\n";
        alive = false;
        th.join();
    }

private:
    std::thread th;
    std::mutex m;
    std::condition_variable cv;
    bool alive;
    bool ready;

    MockCompositor *mc;

    static void *run(void *data) {
        MockCompositorController *mcc = static_cast<MockCompositorController *>(data);
        MockCompositor mc;
        std::cout << __func__ << std::this_thread::get_id() << "\n";

        mcc->mc = &mc;

        while (mcc->alive) {
            std::cout << __func__ << std::this_thread::get_id() << "\n";
            
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }
    }
};

int main(int, char**) {
    MockCompositorController mcc;

    std::this_thread::sleep_for(std::chrono::milliseconds(100));
}
