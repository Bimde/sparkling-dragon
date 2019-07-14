#include <memory>

#include "src/interfaces/subject.h"
#include "src/interfaces/observer.h"

Subject::Subject() {}

Subject::~Subject() {}

void Subject::attach(std::shared_ptr<Observer> o) {
    observers.emplace_back(o);
}

void Subject::detach(std::shared_ptr<Observer> o) {
    for (auto it = observers.begin(); it < observers.end(); it++) {
        if ((*it).get() == o.get()) {
            observers.erase(it);
        }
    }
}

void Subject::notifyObservers() {
  for (auto ob : observers) {
      ob->notify();
  }
}