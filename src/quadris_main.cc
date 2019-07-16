#include <cstdlib>
#include <string>

#include "src/interfaces/game.h"
#include "src/interfaces/quadris.h"
#include "src/interfaces/observer.h"
#include "src/ui/display.h"
#include "src/ui/textDisplay.h"

struct MainCfg {
	GameConfig gameCfg;
	bool textOnly;

	MainCfg() : textOnly{false} {}
};

void parseFlags(MainCfg& cfg, int argc, char *argv[]) {
	for (int i = 0; i < argc; ++i) {
		std::string flg(argv[i]);

		if (flg == "-text") {
			cfg.textOnly = true; 
		}

		if (i >= argc-1) {
			continue;
		}

		if (flg == "-scriptfile") {
			cfg.gameCfg.setFilename(std::string(argv[i+1]));
		} else if (flg == "-seed") {
			int seed;
			seed = static_cast<int>(strtol(argv[i+1], /*endptr=*/nullptr,
				/*radix=*/10));

			cfg.gameCfg.setSeed(seed);
		} else if (flg == "-startlevel") {
			int level;
			level = static_cast<int>(strtol(argv[i+1], /*endptr=*/nullptr, 
				/*radix=*/10));

			cfg.gameCfg.setStartLevel(level);
		}
	}
}

int main(int argc, char *argv[]) {
	MainCfg cfg;
	parseFlags(cfg, argc, argv);

	auto quadris = std::make_shared<Quadris>(cfg.gameCfg);

	// Create text only output
	auto textUi = std::make_shared<TextDisplay>(std::cout, quadris);
	quadris->attach(textUi);
	textUi->notify();

	// UI display output
	std::shared_ptr<XDisplay> graphicUi;

	if (!cfg.textOnly) {
		graphicUi = std::make_shared<XDisplay>(quadris);
		quadris->attach(graphicUi);
	}

	quadris->runGame(std::cin);

	quadris->detach(textUi);
	quadris->detach(graphicUi);

	return 0;
}