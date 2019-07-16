#ifndef UI_TEXTDISPLAY_H
#define UI_TEXTDISPLAY_H

#include <iostream>
#include <memory>

#include "src/interfaces/observer.h"
#include "src/interfaces/quadris.h"

class TextDisplay : public Observer {
	std::ostream& out;
	Quadris* quadris;
  public:
  	TextDisplay(std::ostream& out, Quadris* quadris);
  	void notify() override;
};

#endif