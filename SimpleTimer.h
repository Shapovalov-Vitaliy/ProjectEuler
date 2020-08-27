#pragma once

#include<chrono>
#include<iostream>

class SimpleTimer
{
private:
    std::chrono::time_point<std::chrono::steady_clock> start, end;

public:
    SimpleTimer()
    {
        start = std::chrono::high_resolution_clock::now();
    }

    ~SimpleTimer()
    {
        end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<float> duration = end - start;
        std::cout << "DURATION = " << duration.count() << " seconds" << std::endl;
    }
};

