#include "Timer.hpp"
#include <algorithm>

Timer::Timer()
{

}

void Timer::addTrigger(const Trigger & tri)
{
    triggers.push_back(tri);
}

void Timer::loop()
{
    bool ok = true;
    while (ok) {
        long now = clock() / CLOCKS_PER_MS;
        for_each(triggers.begin(), triggers.end(), [now, &ok](Trigger& tri) {
            if (tri.needTrigger(now)) {
                tri.setLast(now);
                ok = tri.trigger();
            }
        });
    }
}
