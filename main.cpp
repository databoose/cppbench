#include <iostream>
#include <chrono>

#include <thread>

float num = 50.292351;
int primetest = 2041952;
unsigned long ms_passed;

bool is_prime(int n) {
    if (n <= 1)
        return false;
    for (int i = 2; i < n; i++)
        if (n % i == 0)
            return false;
    return true;
}
int main() {
    std::cout << "Running single threaded benchmark.." << std::endl;
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    for (long i = 0; i < 99999999; i++){
        if (num >= 340282346638528859811704183484516925000.0000000000000000) {
            num = num / 2.2;
        }
        num = num * 1.2;
    }

    for (int i = 0; i < 51200100; i++) {
        primetest = primetest * 2;
        if (is_prime(primetest) == true) { // compiler optimizes this out if we simply just call the function, adding condition check makes the compiler not remove this
            std::cout << ".";
        } 
        else {
            std::cout << "..";
        }
    }
    std::cout << "\n\n";
    std::cout << "Single threaded benchmark done\n";
    
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    ms_passed = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
    std::cout << "Score (milliseconds to compute, lower is better)\n "  << ms_passed << std::endl;
}
