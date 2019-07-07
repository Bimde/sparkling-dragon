#include <memory>
#include <string>
#include <istream>
#include <queue>

#include "game.h"
#include "quadris.h"
#include "quadrisState.h"
#include "commandInterpreter.h"

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

void Quadris::runCommands() {
    while(!commands.empty()) {
        enum CMD command = commands.pop;
        
        switch(command) {
            case Left:
                break;
            case Right:
                break;
            case Down:
                break;
            case CW:
                break;
            case CCW:
                break;
            case Drop:
                break;
            case LevelUp:
                break;
            case LevelDown:
                break;
            case NoRandom:
                break;
            case Random:
                break;
            case Restart:
                break;
            case Hint: 
                break;
            case RemoveHint:
                break;
            case InvalidCommand:
                break;
            case AfterMoveTurn:
                break;
        }
    }
}

// Public functions
Quadris::Quadris(int seed, string scriptfile, int startLevel, std::unique_ptr<CommandInterpreter> cmdInterpreter) {}

void Quadris::sendCommand(string s) {}

void Quadris::runGame(istream & in) {
    string input;
    int multiplier;
    enum CMD command;
    while (!in.eof) {
        in >> input;
        curCommand = input;

        multiplier = parseMultiplier(input);
        command = commandInterpreter->processCommand(parseCommand(input));

        if (displayingHint) {
            displayingHint = false;
            commands.push(CMD::RemoveHint);
        }

        if (CMD::InvalidCommand != command) {
            displayingHint = (CMD::Hint == command);
            for( ;multiplier > 0; --multiplier) {
                commands.push(command);
            }
            if (command == CMD::Left || command == CMD::Right || command == CMD::Down ||
                command == CMD::CW || command == CMD::CCW || command == CMD::Drop ||
                command == CMD::LevelUp || command == CMD::LevelDown) {
                    commands.push(CMD::AfterMoveTurn);
            }
        } else {
            notifyObservers();
        }
    }
}

QuadrisState Quadris::getState() {
    return QuadrisState(highScore, curCommand, game->getState());
}

Quadris::~Quadris() {}