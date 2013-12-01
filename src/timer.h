#include <chrono>
#include <iostream>

class Timer {
public:
    explicit Timer(const char *descr_)
     : start{Clock::now()}, descr{descr_}
    {}

    ~Timer() {
        using Sec = std::chrono::duration<double>;
        Sec elapsed {std::chrono::duration_cast<Sec>(Clock::now() - start)};
        std::cout.precision(5);
        std::cout << std::fixed << elapsed.count() << ": " << descr << std::endl;
    }

private:
    using Clock = std::chrono::high_resolution_clock;
    const Clock::time_point start;
    const char *descr;
};
