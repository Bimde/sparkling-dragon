#include <memory>
#include <string>
#include <istream>
#include <queue>
#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

#include "src/interfaces/game.h"
#include "src/interfaces/quadris.h"
#include "src/interfaces/quadrisState.h"
#include "src/interfaces/commandInterpreter.h"
#include "src/interfaces/subject.h"

using namespace std;

std::mutex mtx;

namespace {
    const int kMaxTimeLoopMillis = 2000;
    const int kMinTimeLoopMillis = 500;

    int shouldSleepForMillis(int numBlocksSpawned) {
        int shouldSleepFor = kMaxTimeLoopMillis - numBlocksSpawned*10;
        return kMinTimeLoopMillis > shouldSleepFor ? 
            kMinTimeLoopMillis : shouldSleepFor;
    }
}

Quadris::Quadris(GameConfig cfg) : highScore{0}, displayingHint{false}, 
    curCommand{""}, shouldUseTimeDowns{false}, gameCfg{cfg}, 
    game{Game::create(gameCfg)},
    commandInterpreter{make_unique<CommandInterpreter>()} {
    std::cout << "quadris object created" << std::endl;
}

// Private helper functions

void Quadris::loopDown() {
    while (shouldUseTimeDowns) {
        if (game == nullptr) {
            return;
        }
        runCommand(CMD::Down);
        std::this_thread::sleep_for(std::chrono::milliseconds(
            shouldSleepForMillis(game->getNumBlocksSpawned())));
    }
}

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
    if (game == nullptr) {
        return;
    }

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
            shouldUseTimeDowns = true;
            autoDown = std::thread(Quadris::loopDown);
        case InvalidCommand:
            // TODO add new thing to relay error msgs
            notifyObservers();
            break;
        default:
            break;
    }

    cout << "Command: " << command << endl;
    notifyObservers();
}

// Public functions
// Quadris::Quadris(int seed, string scriptfile, int startLevel, std::unique_ptr<CommandInterpreter> cmdInterpreter) {}

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
            string filename;
            in >> filename;
            gameCfg.setFilename(filename);
            runCommand(CMD::NoRandom);
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
    std::cout << "getting quadris state" << std::endl;
    if (game == nullptr) {
        std::cout << "ERROR: game is nullptr" << std::endl;
    }
    return QuadrisState(highScore, curCommand, game->getState());
}

Quadris::~Quadris() {}