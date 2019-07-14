#include <memory>

#include "src/interfaces/levels/blockGenerator.h"

#include "src/interfaces/blocks/iBlock.h"
#include "src/interfaces/blocks/jBlock.h"
#include "src/interfaces/blocks/lBlock.h"
#include "src/interfaces/blocks/oBlock.h"
#include "src/interfaces/blocks/sBlock.h"
#include "src/interfaces/blocks/zBlock.h"
#include "src/interfaces/blocks/tBlock.h"

std::unique_ptr<UnplacedBlock> createLetterBlock(
	char type, int score, Point bottomLeft) {
	switch (type) {
		case 'I' : return std::make_unique<IBlock>(score, bottomLeft);
		case 'J' : return std::make_unique<JBlock>(score, bottomLeft);
		case 'L' : return std::make_unique<LBlock>(score, bottomLeft);
		case 'O' : return std::make_unique<OBlock>(score, bottomLeft);
		case 'S' : return std::make_unique<SBlock>(score, bottomLeft);
		case 'Z' : return std::make_unique<ZBlock>(score, bottomLeft);
		case 'T' : return std::make_unique<TBlock>(score, bottomLeft);
	}
	return nullptr;
}