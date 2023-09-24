// SubStatement.cpp:
#include "SubStatement.h"
using namespace std;

SubStatement::SubStatement(string variableName, string variableString)
        : m_variableName(variableName), m_variableString(variableString) {}

SubStatement::SubStatement(string variableName, int variableInt)
        : m_variableName(variableName), m_variableInt(variableInt) {}

SubStatement::~SubStatement() {}

void SubStatement::execute(ProgramState* state, std::ostream& outf) {
    // If not a string, sub value directly
    if (m_variableString.empty()) {
        state->addToVal(m_variableName, -(m_variableInt));
    }
    // else, retreive the variables value from the map
    else {
        int temp = -(state->getVal(m_variableString));
        state->addToVal(m_variableName, temp);
    }
    state->incCounter();
}