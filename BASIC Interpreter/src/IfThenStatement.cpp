// IfThenStatement.cpp:
#include "IfThenStatement.h"
using namespace std;

IfThenStatement::IfThenStatement(string variableName, string op, int value, int lineNum)
        : m_variableName(variableName), m_operator(op), m_value(value), m_lineNum(lineNum) {
    m_goTo = new GoToStatement(m_lineNum);
}

IfThenStatement::~IfThenStatement() { delete m_goTo; }

void IfThenStatement::execute(ProgramState* state, ostream& outf) {
    // checks for each operator, and if true goes to line
    if (m_operator == "<") {
        if (state->getVal(m_variableName) < m_value) {
            m_goTo->execute(state, outf);
        } else {
            state->incCounter();
        }
    } else if (m_operator == "<=") {
        if (state->getVal(m_variableName) <= m_value) {
            m_goTo->execute(state, outf);
        } else {
            state->incCounter();
        }
    } else if (m_operator == ">") {
        if (state->getVal(m_variableName) > m_value) {
            m_goTo->execute(state, outf);
        } else {
            state->incCounter();
        }
    } else if (m_operator == ">=") {
        if (state->getVal(m_variableName) >= m_value) {
            m_goTo->execute(state, outf);
        } else {
            state->incCounter();
        }
    } else if (m_operator == "=") {
        if (state->getVal(m_variableName) == m_value) {
            m_goTo->execute(state, outf);
        } else {
            state->incCounter();
        }
    } else if (m_operator == "<>") {
        if (state->getVal(m_variableName) != m_value) {
            m_goTo->execute(state, outf);
        } else {
            state->incCounter();
        }
    } else {
        state->setTerminate();
    }
}
