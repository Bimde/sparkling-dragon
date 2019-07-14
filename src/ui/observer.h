#ifndef OBSERVER_H
#define OBSERVER_H

class Observer {
  protected:
    Observer();
  public:
    virtual void notify() = 0;
    virtual ~Observer() {}
};

#endif