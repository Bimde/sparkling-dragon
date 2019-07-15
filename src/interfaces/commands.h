#ifndef COMMANDS_H
#define COMMANDS_H

// TODO add command for replacing the current block (e.g. I,J,T...)

enum CMD{ 
			Left, Right, Down, RotateLeft, RotateRight, Drop, 
		  	LevelUp, LevelDown, NoRandom, Random, Restart, 
		  	Hint, RemoveHint, InvalidCommand, AfterMoveTurn,
		  	AutoDown, StopAutoDown,
			SpawnIBlock, SpawnJBlock, SpawnLBlock, SpawnOBlock,
			SpawnSBlock, SpawnZBlock, SpawnTBlock, SpawnStarBlock,
			UseSequenceFile
		};

#endif