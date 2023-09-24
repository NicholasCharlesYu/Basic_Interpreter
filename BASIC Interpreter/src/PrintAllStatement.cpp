// PrintAllStatement.cpp:
#include "PrintAllStatement.h"
using namespace std;

PrintAllStatement::PrintAllStatement() {}

PrintAllStatement::~PrintAllStatement() {}

void PrintAllStatement::execute(ProgramState* state, std::ostream& outf) {
    // prints pair for each value in map
    for (auto it = state->getMap()->begin(); it != state->getMap()->end(); ++it) {
        outf << it->first << " " << it->second << endl;
    }
    state->incCounter();
}
