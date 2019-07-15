#include "src/interfaces/game.h"
#include "src/interfaces/quadris.h"
#include "src/interfaces/observer.h"
#include "src/ui/display.h"

class Out : public Observer {
	std::shared_ptr<Quadris> q_;
  public:
  	Out(std::shared_ptr<Quadris> q);
  	void notify() override;
};

Out::Out(std::shared_ptr<Quadris> q) : q_{q} {}

void Out::notify() {
	std::cout << "notify called" << std::endl;
	if (q_ == nullptr) {
		return;
	}

	std::cout << "running state retrieval" << std::endl;

	auto qstate = q_->getState();
	auto& gstate = qstate.gameState;
	std::cout << "high score: " << qstate.highScore << std::endl;
	std::cout << "curr score: " << gstate.score << std::endl;
	std::cout << "curr level: " << gstate.currentLevel << std::endl;
	std::cout << "next level: " << gstate.nextLevel << std::endl;

	std::cout << "next block: ";
	if (gstate.nextBlock != nullptr) {
		std::cout << gstate.nextBlock->getType();
	}
	std::cout << std::endl;

	if (gstate.isGameOver) {
		std::cout << "Game Over!!!!! Please restart" << std::endl;
	}

	std::cout << "-------------------------" << std::endl;


	int cntr = gstate.board.size();

	for (auto& row : gstate.board) {
		for (char& col : row) {
			std::cout << col;
		}
		std::cout << " :: " << cntr << std::endl;
		--cntr;
	}
}


int main(int argc, char *argv[]) {
	// TODO parse flags

	GameConfig cfg;
	cfg.setStartLevel(0);
	cfg.setSeed(0);
	cfg.setSeed(0);

	std::cout << "objects not yet created" << std::endl;
	auto quadris = std::make_shared<Quadris>(cfg);
	auto out = std::make_shared<Out>(quadris);
	std::cout << "objects created" << std::endl;

	quadris->attach(out);

	auto ui = std::make_shared<XDisplay>(quadris);

	quadris->attach(ui);

	quadris->runGame(std::cin);
	quadris->detach(out);

	return 0;
}