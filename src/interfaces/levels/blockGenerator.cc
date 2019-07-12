#include <memory>

#include "blockGenerator.h"

#include "iBlock.h"
#include "jBlock.h"
#include "lBlock.h"
#include "oBlock.h"
#include "sBlock.h"
#include "zBlock.h"
#include "tBlock.h"

std::unique_ptr<UnplacedBlock> createLetterBlock(
	char type, int score, Point bottomLeft) {
	switch (type) {
		case 'I' : return make_unique(IBlock(score, bottomLeft));
		case 'J' : return make_unique(JBlock(score, bottomLeft));
		case 'L' : return make_unique(LBlock(score, bottomLeft));
		case 'O' : return make_unique(OBlock(score, bottomLeft));
		case 'S' : return make_unique(SBlock(score, bottomLeft));
		case 'Z' : return make_unique(ZBlock(score, bottomLeft));
		case 'T' : return make_unique(TBlock(score, bottomLeft));
	}
	return nullptr;
}