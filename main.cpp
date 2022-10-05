#include <iostream>
#include <chrono>

float num = 50.292351;
unsigned long ms_passed;

int main() {
    std::cout << "Running benchmark.." << std::endl;
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    for (long i = 0; i < 99999999; i++){
        if (num >= 340282346638528859811704183484516925000.0000000000000000) {
            num = num / 2.2;
        }
        num = num * 1.2;
    }
    std::cout << "Basic floating point arithmetic benchmark done\n";
    
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    ms_passed = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
    std::cout << "Score (milliseconds to compute, lower is better) : "  << ms_passed << std::endl;
}
