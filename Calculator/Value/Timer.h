#pragma once
#include <chrono>
#include <iostream>
#include <functional>
//Class计时器
class Timer {
public:
    Timer() : start_(std::chrono::high_resolution_clock::now()) {}
    
    // 重置计时器
    void reset() {
        start_ = std::chrono::high_resolution_clock::now();
    }
    
    // 返回经过的毫秒数
    double elapsed() const {
        auto end = std::chrono::high_resolution_clock::now();
        return std::chrono::duration_cast<std::chrono::milliseconds>(end - start_).count();
    }
    
    // 返回经过的微秒数
    double elapsedMicroseconds() const {
        auto end = std::chrono::high_resolution_clock::now();
        return std::chrono::duration_cast<std::chrono::microseconds>(end - start_).count();
    }
    
    // 返回经过的纳秒数
    double elapsedNanoseconds() const {
        auto end = std::chrono::high_resolution_clock::now();
        return std::chrono::duration_cast<std::chrono::nanoseconds>(end - start_).count();
    }
    
    // 返回经过的秒数
    double elapsedSeconds() const {
        return elapsed() / 1000.0;
    }

    // 自动计时并输出结果的RAII方式
    static void measure(const std::string& name, const std::function<void()>& func) {
        Timer t;
        func();
        std::cout << name << " took " << t.elapsed() << " ms\n";
    }

private:
    std::chrono::time_point<std::chrono::high_resolution_clock> start_;
};