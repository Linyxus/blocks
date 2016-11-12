#include "Trigger.hpp"

Trigger::Trigger(int interval, Function f)
{
    this->interval = interval;
    this->onTrigger = f;
}

Trigger::~Trigger()
{

}

bool Trigger::trigger()
{
    return onTrigger();
}

void Trigger::setLast(int now)
{
    last = now;
}
