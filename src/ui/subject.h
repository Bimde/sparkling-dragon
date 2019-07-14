#ifndef SUBJECT_H
#define SUBJECT_H

#include <vector>
#include <memory>
#include "observer.h"

class Subject {
    std::vector<std::shared_ptr<Observer>> observers;
  protected:
    Subject();
  public:
    void attach(std::shared_ptr<Observer> o);
    void detach(std::shared_ptr<Observer> o);
    void notifyObservers();
    virtual ~Subject() = 0;
};

#endif