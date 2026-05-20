#include <iostream>
#include <thread>
#include <chrono>

void showLoadingBar(int totalDuration) {
    int barWidth = 40;
    float progress = 0.0;

    while (progress <= 1.0) {
        std::cout << "[";
        int pos = barWidth * progress;
        for (int i = 0; i < barWidth; ++i) {
            if (i < pos) std::cout << "=";
            else if (i == pos) std::cout << ">";
            else std::cout << " ";
        }
        std::cout << "] " << int(progress * 100.0) << " %\r";
        std::cout.flush();

        std::this_thread::sleep_for(std::chrono::milliseconds(totalDuration / 20)); 
        progress += 0.05;
    }
    std::cout << std::endl;
}

int main() {
    std::cout << "Starting download..." << std::endl;
    showLoadingBar(4000); // 2 seconds simulation
    std::cout << "Completed!" << std::endl;
    return 0;
}

