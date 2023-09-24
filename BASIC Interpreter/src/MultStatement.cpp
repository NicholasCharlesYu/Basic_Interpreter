// MultStatement.cpp:
#include "MultStatement.h"
using namespace std;

MultStatement::MultStatement(string variableName, string variableString)
        : m_variableName(variableName), m_variableString(variableString) {}

MultStatement::MultStatement(string variableName, int variableInt)
        : m_variableName(variableName), m_variableInt(variableInt) {}

MultStatement::~MultStatement() {}

void MultStatement::execute(ProgramState* state, std::ostream& outf) {
    // If not a string, mult value directly
    if (m_variableString.empty()) {
        state->multVal(m_variableName, m_variableInt);
    }
    // else, retreive the variables value from the map
    else {
        int temp = state->getVal(m_variableString);
        state->multVal(m_variableName, temp);
    }
    state->incCounter();
}