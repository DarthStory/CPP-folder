#include <iostream>
#include <thread>
#include <mutex>

void countUp() {
    for(int i = 0; i < 20; i++) {
        std::cout << i << std::endl;
    }
}

void countDown() {
    for(int j = 20; j != 0; j--) {
        std::cout << j << std::endl;
    }

}


int main() {

    std::thread t1(countUp);
    std::thread t2(countDown);

    t1.join();
    t2.join();

    return 0;
}