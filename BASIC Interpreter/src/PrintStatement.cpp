// PrintStatement.cpp:
#include "PrintStatement.h"
using namespace std;

PrintStatement::PrintStatement(std::string variableName) : m_variableName(variableName) {}

PrintStatement::~PrintStatement() {}

void PrintStatement::execute(ProgramState* state, std::ostream& outf) {
    outf << state->getVal(m_variableName) << endl;
    state->incCounter();
}
