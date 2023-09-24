// AddStatement.cpp:
#include "AddStatement.h"
using namespace std;

AddStatement::AddStatement(string variableName, string variableString)
        : m_variableName(variableName), m_variableString(variableString) {}

AddStatement::AddStatement(string variableName, int variableInt)
        : m_variableName(variableName), m_variableInt(variableInt) {}

AddStatement::~AddStatement() {}

void AddStatement::execute(ProgramState* state, std::ostream& outf) {
    // If not a string, add value directly
    if (m_variableString.empty()) {
        state->addToVal(m_variableName, m_variableInt);
    }
    // else, retreive the variables value from the map
    else {
        int temp = state->getVal(m_variableString);
        state->addToVal(m_variableName, temp);
    }
    state->incCounter();
}