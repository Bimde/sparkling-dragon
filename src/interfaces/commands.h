#ifndef COMMANDS_H
#define COMMANDS_H


enum CMD{ 
			Left, Right, Down, RotateLeft, RotateRight, Drop, 
		  	LevelUp, LevelDown, NoRandom, Random, Restart, 
		  	Hint, RemoveHint, InvalidCommand, AfterMoveTurn,
		  	AutoDown, StopAutoDown,
			SpawnIBlock, SpawnJBlock, SpawnLBlock, SpawnOBlock,
			SpawnSBlock, SpawnZBlock, SpawnTBlock,
			UseSequenceFile
		};

#endif