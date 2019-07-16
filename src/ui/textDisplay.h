#ifndef UI_TEXTDISPLAY_H
#define UI_TEXTDISPLAY_H

#include <iostream>
#include <memory>

#include "src/interfaces/observer.h"
#include "src/interfaces/quadris.h"

class TextDisplay : public Observer {
	std::ostream& out;
	std::shared_ptr<Quadris> quadris;
  public:
  	TextDisplay(std::ostream& out, std::shared_ptr<Quadris> quadris);
  	void notify() override;
};

#endif