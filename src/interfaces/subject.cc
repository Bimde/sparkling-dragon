#include <memory>

#include "src/interfaces/subject.h"
#include "src/interfaces/observer.h"

Subject::Subject() {}

Subject::~Subject() {}

void Subject::attach(Observer* o) {
    if (o == nullptr) {
        return;
    }

	  for (auto it = observers.begin(); it != observers.end(); ++it) {
        if (*it == o) {
            return;
        }
    }

    observers.emplace_back(o);
}

void Subject::detach(Observer* o) {
    if (o == nullptr) {
        return;
    }

    for (auto it = observers.begin(); it != observers.end(); ++it) {
        if (*it == o) {
            observers.erase(it);
            return;
        }
    }
}

void Subject::notifyObservers() {
  for (auto ob : observers) {
      ob->notify();
  }
}