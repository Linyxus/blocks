#ifndef TRIGGER_HPP_
#define TRIGGER_HPP_

class Trigger
{
public:
    typedef bool (*Function)();
    Trigger(int, Function);
    ~Trigger();
    bool trigger(); //once the trigger function returned false, the loop will end.
    void setLast(int);
    bool needTrigger(int) const;
private:
    int interval; //ms
    Function onTrigger;
    int last; //ms
};

#endif
