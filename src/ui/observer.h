#ifndef UI_OBSERVER_H
#define UI_OBSERVER_H

class Observer {
  public:
    virtual void notify() = 0;
    virtual ~Observer();
};

#endif