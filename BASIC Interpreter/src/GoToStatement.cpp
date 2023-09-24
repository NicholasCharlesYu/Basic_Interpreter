// GoToStatement.cpp:
#include "GoToStatement.h"
using namespace std;

GoToStatement::GoToStatement() { m_line = 0; }

GoToStatement::GoToStatement(int lineNum) : m_line(lineNum) {}

GoToStatement::~GoToStatement() {}

void GoToStatement::setLine(int line) { m_line = line; }

void GoToStatement::execute(ProgramState* state, std::ostream& outf) {
    // Check if in bounds
    if (m_line > state->getNumLines() || m_line <= 0) {
        state->setTerminate();
        outf << "Illegal jump instruction" << endl;
        return;
    }
    // set counter to jump to line
    state->updateCounter(m_line);
}