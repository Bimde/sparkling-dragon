#include <memory>
#include <string>
#include <istream>
#include <queue>
#include <iostream>

#include "src/interfaces/game.h"
#include "src/interfaces/quadris.h"
#include "src/interfaces/quadrisState.h"
#include "src/interfaces/commandInterpreter.h"

using namespace std;

// Private helper functions

// Todo: throw exception for multipliers which are too large
int Quadris::parseMultiplier(string command) {
    int idx = 0;
    while(command.at(idx) >= '0' && command.at(idx) <= '9') ++idx;
    if (idx == 0) return 1;
    return stoi(command.substr(0, idx));
}

string Quadris::parseCommand(string command) {
    int idx = 0;
    while(command.at(idx) >= '0' && command.at(idx) <= '9') ++idx;
    return command.substr(idx, command.length()-idx);
}

void Quadris::runCommand(CMD command) {
    switch(command) {
        case Left:
            game->moveCurrentBlockLeft();
            break;
        case Right:
            game->moveCurrentBlockRight();
            break;
        case Down:
            game->moveCurrentBlockDown();
            break;
        case RotateLeft:
            game->rotateCurrentBlockLeft();
            break;
        case RotateRight:
            game->rotateCurrentBlockRight();
            break;
        case Drop:
            game->dropCurrentBlock();
            break;
        case LevelUp:
            game->increaseLevel();
            break;
        case LevelDown:
            game->decreaseLevel();
            break;
        case NoRandom:
            game->useFileForLevel(levelFile);
            break;
        case Random:
            break;
        case Restart:
            game->reset();
            break;
        case Hint: 
            game->enableHint();
            displayingHint = true;
            break;
        case RemoveHint:
            game->disableHint();
            displayingHint = false;
            break;
        case AfterMoveTurn:
            game->doLevelActionAfterMove();
            break;
        case InvalidCommand:
            notifyObservers();
            break;
    }
}

// Public functions
// Quadris::Quadris(int seed, string scriptfile, int startLevel, std::unique_ptr<CommandInterpreter> cmdInterpreter) {}
Quadris::Quadris(): highScore{0}, displayingHint{false}, curCommand{""}, levelFile{""}, commandInterpreter{make_unique<CommandInterpreter>()} {}

void Quadris::runGame(istream & in) {
    string input;
    int multiplier;
    enum CMD command;
    while (!in.eof()) {
        in >> input;
        curCommand = input;

        multiplier = parseMultiplier(input);
        command = commandInterpreter->processCommand(parseCommand(input));

        if (displayingHint) {
            runCommand(CMD::RemoveHint);
        }

        // not valid to apply a multiplier to the restart, hint, norandom, or random
        if (CMD::InvalidCommand == command) {
            runCommand(CMD::InvalidCommand);
        } else if (CMD::Restart == command) {
            runCommand(CMD::Restart);
        } else if (CMD::Hint == command) {
            runCommand(CMD::Hint);
        } else if (CMD::Random == command) {
            runCommand(CMD::Random);
        } else if (CMD::NoRandom == command) {
            in >> levelFile;
            runCommand(CMD::NoRandom);
        } else {
            for( ;multiplier > 0; --multiplier) {
                runCommand(command);
            }
            if (command == CMD::Left || command == CMD::Right || command == CMD::Down ||
                command == CMD::RotateLeft || command == CMD::RotateRight || command == CMD::Drop ||
                command == CMD::LevelUp || command == CMD::LevelDown) {
                    runCommand(CMD::AfterMoveTurn);
            }
        }
    }
}

QuadrisState Quadris::getState() {
    return QuadrisState(highScore, curCommand, game->getState());
}

Quadris::~Quadris() {}