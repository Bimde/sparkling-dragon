#include <memory>
#include <string>
#include <istream>
#include <queue>
#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <fstream>

#include "src/interfaces/game.h"
#include "src/interfaces/quadris.h"
#include "src/interfaces/quadrisState.h"
#include "src/interfaces/commandInterpreter.h"
#include "src/interfaces/subject.h"

using namespace std;


namespace {
    const int kMaxTimeLoopMillis = 1500;
    const int kMinTimeLoopMillis = 300;
    const int kTimeDecreasePerBlock = 50;

    std::mutex mtx;

    int shouldSleepForMillis(int numBlocksSpawned) {
        int shouldSleepFor = kMaxTimeLoopMillis - 
            numBlocksSpawned*kTimeDecreasePerBlock;
        return kMinTimeLoopMillis > shouldSleepFor ? 
            kMinTimeLoopMillis : shouldSleepFor;
    }
}

void loopDown(Quadris* q) {
    while (q->shouldUseTimeDowns) {
        if (q == nullptr || q->game == nullptr) {
            return;
        }
        if (q->game->isGameOver()) {
            return;
        }

        q->runCommand(CMD::Down);

        std::this_thread::sleep_for(std::chrono::milliseconds(
            shouldSleepForMillis(q->game->getNumBlocksSpawned())));
    }
}

Quadris::Quadris(GameConfig cfg) : highScore{0}, displayingHint{false}, 
    curCommand{""}, shouldUseTimeDowns{false}, gameCfg{cfg}, 
    game{Game::create(gameCfg)},
    commandInterpreter{make_unique<CommandInterpreter>()} {}

// Private helper functions

int Quadris::parseMultiplier(string command) {
    int idx = 0;
    while(idx < command.length() && command.at(idx) >= '0' && command.at(idx) <= '9') {
        ++idx;
    }

    if (idx == 0) {
        return 1;
    }

    return stoi(command.substr(0, idx));
}

string Quadris::parseCommand(string command) {
    int idx = 0;
    while (idx < command.length() && command.at(idx) >= '0' && command.at(idx) <= '9') ++idx;
    if (idx >= command.length()) {
        return "invalidCommand";
    }
    return command.substr(idx, command.length()-idx);
}

void Quadris::runCommand(CMD command) {
    if (game == nullptr) {
        return;
    }

    highScore = highScore > game->getScore() ? highScore : game->getScore();

    // Perform game related commands
    if (!game->isGameOver()) {
        // Lock game
        mtx.lock();
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
                game->useFileForLevel(gameCfg.getLevelConfig().filename());
                break;
            case Random:
                game->randomizeLevels();
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
            case SpawnIBlock:
                game->changeBlockType(SpawnIBlock);
                break;
            case SpawnJBlock:
                game->changeBlockType(SpawnJBlock);
                break;
            case SpawnLBlock:
                game->changeBlockType(SpawnLBlock);
                break;
            case SpawnOBlock:
                game->changeBlockType(SpawnOBlock);
                break;
            case SpawnSBlock:
                game->changeBlockType(SpawnSBlock);
                break;
            case SpawnZBlock:
                game->changeBlockType(SpawnZBlock);
                break;
            case SpawnTBlock:
                game->changeBlockType(SpawnTBlock);
                break;      
            default:
                break;
        }
        // Unlock game
        mtx.unlock();
    }

    switch(command) {
        case Restart:
            shouldUseTimeDowns = false;
            game = Game::create(gameCfg);
            break;
        case AutoDown:
            if (shouldUseTimeDowns) {
                break;
            }
            shouldUseTimeDowns = true;
            autoDown = make_unique<std::thread>(loopDown, this);
            break;
        case StopAutoDown:
            shouldUseTimeDowns = false;
            if (autoDown != nullptr) {
                autoDown->join();
            }
            break;
        case InvalidCommand:
            break;
        default:
            break;
    }

    if (game != nullptr) {
        highScore = highScore > game->getScore() ? highScore : game->getScore();
    }

    notifyObservers();
}

// Public functions

void Quadris::runGame(istream & in) {
    string input;
    int multiplier;
    enum CMD command;
    while (!in.eof()) {
        in >> input;
        // Convert to lowercase
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
            string filename;
            in >> filename;
            gameCfg.setFilename(filename);
            runCommand(CMD::NoRandom);
        } else if (CMD::SpawnIBlock == command || CMD::SpawnJBlock == command || CMD::SpawnLBlock == command || 
                   CMD::SpawnOBlock == command || CMD::SpawnSBlock == command || CMD::SpawnZBlock == command || 
                   CMD::SpawnTBlock == command) {
            runCommand(command);
        } else if (CMD::UseSequenceFile == command) {
            string file;
            in >> file;
            std::ifstream fin = ifstream(file);
            if(!file.empty() && fin.good()) {
                runGame(fin);
                fin.close();
            }
        } else {
            for( ;multiplier > 0; --multiplier) {
                runCommand(command);
            }
            if (command == CMD::Left || command == CMD::Right || 
                command == CMD::Down || command == CMD::RotateLeft || 
                command == CMD::RotateRight || command == CMD::Drop ||
                command == CMD::LevelUp || command == CMD::LevelDown) {
                    runCommand(CMD::AfterMoveTurn);
            }
        }
    }
}

QuadrisState Quadris::getState() {
    return QuadrisState(highScore, curCommand, game->getState());
}

Quadris::~Quadris() {
    if (shouldUseTimeDowns && autoDown != nullptr) {
        autoDown->join();
    }
}