// GoSubStatement.cpp:
#include "GoSubStatement.h"
using namespace std;

GoSubStatement::GoSubStatement(int lineNum) : m_line(lineNum) { m_goTo = new GoToStatement(m_line); }

GoSubStatement::~GoSubStatement() { delete m_goTo; }

void GoSubStatement::execute(ProgramState* state, std::ostream& outf) {
    // pushes current line to stack and goes to next
    state->pushStack(state->valCounter());
    m_goTo->execute(state, outf);
}