// DivStatement.cpp:
#include "DivStatement.h"
using namespace std;

DivStatement::DivStatement(string variableName, string variableString)
        : m_variableName(variableName), m_variableString(variableString) {}

DivStatement::DivStatement(string variableName, int variableInt)
        : m_variableName(variableName), m_variableInt(variableInt) {}

DivStatement::~DivStatement() {}

void DivStatement::execute(ProgramState* state, std::ostream& outf) {
    // Test for divide by 0
    try {
        // If not a string, div value directly
        if (m_variableString.empty()) {
            state->divVal(m_variableName, m_variableInt);
        }
        // else, retreive the variables value from the map
        else {
            int temp = state->getVal(m_variableString);
            state->divVal(m_variableName, temp);
        }
    } catch (range_error& e) {
        outf << e.what() << endl;
        state->setTerminate();
    }
    state->incCounter();
}