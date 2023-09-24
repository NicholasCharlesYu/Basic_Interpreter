// ReturnStatement.cpp:
#include "ReturnStatement.h"
using namespace std;

ReturnStatement::ReturnStatement() { m_goTo = new GoToStatement(); }

ReturnStatement::~ReturnStatement() { delete m_goTo; }

void ReturnStatement::execute(ProgramState* state, std::ostream& outf) {
    // if stack is not empty, goes to line after the previous goSub
    if (!state->stackEmpty()) {
        int returnLine = state->peekStack() + 1;
        m_goTo->setLine(returnLine);
        state->popStack();
        m_goTo->execute(state, outf);
    } else {
        state->setTerminate();
    }
}