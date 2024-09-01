#include <iostream>
#include <thread>
#include <mutex>

std::mutex mtx;

void countUp() {

    mtx.lock();
    std::cout << "Count Up: " << std::endl;
    for(int i = 0; i <= 20; i++) {
        std::cout << i << " ";
    }
    std::cout << "" << std::endl;
    mtx.unlock();
}

void countDown() {

    mtx.lock();
    std::cout << "Count Down: " << std::endl;
    for(int j = 20; j >= 0; j--) {
        std::cout << j << " ";
    }
    std::cout << "" << std::endl;
    mtx.unlock();
}


int main() {

    std::thread t1(countUp);
    std::thread t2(countDown);

    t1.join();
    t2.join();

    return 0;
}