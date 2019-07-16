#include <iostream>
#include <memory>

#include "src/ui/textDisplay.h"
#include "src/interfaces/gameState.h"
#include "src/interfaces/quadris.h"

TextDisplay::TextDisplay(std::ostream& out, std::shared_ptr<Quadris> quadris) : 
	out{out}, quadris{quadris} {}

void TextDisplay::notify() {
	if (quadris == nullptr) {
		return;
	}

	auto qstate = quadris->getState();
	auto& gstate = qstate.gameState;
	
	out << "high score: " << qstate.highScore << std::endl;
	out << "curr score: " << gstate.score << std::endl;
	out << "curr level: " << gstate.currentLevel << std::endl;
	out << "next level: " << gstate.nextLevel << std::endl;

	out << "next block: ";
	if (gstate.nextBlock != nullptr) {
		out << gstate.nextBlock->getType();
	}
	out << std::endl;

	if (gstate.isGameOver) {
		out << "Game Over!!!!! Please restart" << std::endl;
	}

	out << "-------------------------" << std::endl;

	int cntr = gstate.board.size();

	for (auto& row : gstate.board) {
		for (char& col : row) {
			out << col;
		}
		out << " :: " << cntr << std::endl;
		--cntr;
	}

	out << "-------------------------" << std::endl;
}
