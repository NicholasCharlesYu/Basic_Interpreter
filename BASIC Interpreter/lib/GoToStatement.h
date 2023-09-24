#ifndef GOTO_STATEMENT_INCLUDED
#define GOTO_STATEMENT_INCLUDED

#include "Statement.h"

class GoToStatement : public Statement {
private:
    int m_line;

public:
    ~GoToStatement();
    GoToStatement();
    GoToStatement(int lineNum);

    // manually sets m_line
    void setLine(int line);

    virtual void execute(ProgramState* state, std::ostream& outf);
};

#endif