#include "FrameTimer.h"

FrameTimer::FrameTimer()
{
    start = std::chrono::steady_clock::now();
}

float FrameTimer::Mark()
{
    std::chrono::steady_clock::time_point endTime = start;
    start = std::chrono::steady_clock::now();
    const std::chrono::duration<float> fractionTime = start - endTime;
    return fractionTime.count();;
}
