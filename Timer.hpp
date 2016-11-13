#ifndef TIMER_HPP_
#define TIMER_HPP_

#include "Trigger.hpp"
#include <ctime>
#include <vector>
using namespace std;

class Timer
{
public:
    Timer();
    void addTrigger(const Trigger&);
    void loop();
    const long CLOCKS_PER_MS = CLOCKS_PER_SEC / 1000;
private:
    vector<Trigger> triggers;
};

#endif
