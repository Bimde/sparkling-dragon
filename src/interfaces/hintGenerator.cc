#include <memory>
#include <iostream>

#include "src/interfaces/hintGenerator.h"
#include "src/interfaces/board.h"
#include "src/interfaces/unplacedBlock.h"

namespace {
class HintGeneratorImpl : public HintGenerator {
	UnplacedBlock generateHintImpl(
		const Board& board, const UnplacedBlock& currentBlock)
		override;

	UnplacedBlock blockMovedToPosition(
		const Board& board, 
		const UnplacedBlock& 
		currentBlock, int rights, 
		int rotations);

	int highestYPos(UnplacedBlock&);
};

UnplacedBlock HintGeneratorImpl::blockMovedToPosition(
	const Board& board, const UnplacedBlock& currentBlock, int rights, 
	int rotations) {
	UnplacedBlock b = currentBlock;
	for(int i = 0; i < rights; ++i) {
		b.moveRight();
	}
	for(int i = 0; i < rotations; ++i) {
		b.rotateRight();
	}
	UnplacedBlock temp = b;
	while(!board.isOverlapping(temp)) {
		b = temp;
		temp.moveDown();
	}
	return b;
}

UnplacedBlock HintGeneratorImpl::generateHintImpl(
	const Board& board, const UnplacedBlock& currentBlock) {
	
	int track = 0;
	int rights = 0;
	int rotations = 0;

	for (int i = 0; i < 4; ++i) {
		UnplacedBlock tempBlock = currentBlock;
		// Loop through all positions to drop from
		for (int ii = 0; ii < i; ++ii) {
			tempBlock.rotateRight();
		}

		// Use tRTB to check for out of bounds while we're moving the 
		// rotatedTempBlock right
		UnplacedBlock rotatedTempBlock = tempBlock;
		UnplacedBlock rtb = tempBlock;
		int rightCnt = 0;
		while(!board.isOverlapping(rtb)) {
			rotatedTempBlock = rtb;
			
			UnplacedBlock rightAndRotatedTempBlock = rotatedTempBlock;
			UnplacedBlock rrtb = rotatedTempBlock;
			while(!board.isOverlapping(rrtb)) {
				rightAndRotatedTempBlock = rrtb;
				
				int fullRows = board.numberOfFullRowsWithUnplacedBlock(
					rightAndRotatedTempBlock);
				if (track < fullRows) {
					track = fullRows;
					rights = rightCnt;
					rotations = i;
				}
				
				rrtb.moveDown();
			}

			rtb.moveRight();
			rightCnt++;
		}
	}

	if (track != 0) {
		return blockMovedToPosition(board, currentBlock, rights, rotations);
	} else {
		// Fill the lowest possible spot
		track = 0;
		// track = 18; // if using highestY
		int rights = 0;
		int rotations = 0;

		for (int i = 0; i < 4; ++i) {
			UnplacedBlock tempBlock = currentBlock;
			// Loop through all positions to drop from
			for (int ii = 0; ii < i; ++ii) {
				tempBlock.rotateRight();
			}

			// Use tRTB to check for out of bounds while we're moving the 
			// rotatedTempBlock right
			UnplacedBlock rotatedTempBlock = tempBlock;
			UnplacedBlock rtb = tempBlock;
			int rightCnt = 0;
			while(!board.isOverlapping(rtb)) {
				rotatedTempBlock = rtb;
				
				UnplacedBlock rightAndRotatedTempBlock = rotatedTempBlock;
				UnplacedBlock rrtb = rotatedTempBlock;
				while(!board.isOverlapping(rrtb)) {
					rightAndRotatedTempBlock = rrtb;
					
					int curEmptyRows = board.numberOfEmptyRowsWithUnplacedBlock(
						rightAndRotatedTempBlock);
					if (track < curEmptyRows) {
						track = curEmptyRows;
						rights = rightCnt;
						rotations = i;
					}

					// int highestY = highestYPos(rightAndRotatedTempBlock);
					// if (track > highestY) {
					// 	track = highestY;
					// 	rights = rightCnt;
					// 	rotations = i;
					// }

					rrtb.moveDown();
				}

				rtb.moveRight();
				rightCnt++;
			}
		}
		return blockMovedToPosition(board, currentBlock, rights, rotations);
	}
}
}  // namespace

HintGenerator::~HintGenerator() {}

UnplacedBlock HintGenerator::generateHint(
	const Board& board, const UnplacedBlock& currentBlock) {
	return generateHintImpl(board, currentBlock);
}

std::unique_ptr<HintGenerator> HintGenerator::create() {
	return std::make_unique<HintGeneratorImpl>();
}