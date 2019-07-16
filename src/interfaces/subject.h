#ifndef SUBJECT_H
#define SUBJECT_H

#include <vector>
#include "src/interfaces/observer.h"

class Subject {
    std::vector<Observer*> observers;
  protected:
    Subject();
  public:
    void attach(Observer* o);
    void detach(Observer* o);
    void notifyObservers();
    virtual ~Subject() = 0;
};

#endif