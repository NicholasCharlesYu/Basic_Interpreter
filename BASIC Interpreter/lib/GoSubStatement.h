#ifndef GOSUB_STATEMENT_INCLUDED
#define GOSUB_STATEMENT_INCLUDED

#include "GoToStatement.h"
#include "Statement.h"

class GoSubStatement : public Statement {
private:
    int m_line;
    // has-a GoTo
    GoToStatement* m_goTo;

public:
    ~GoSubStatement();
    GoSubStatement(int lineNum);

    virtual void execute(ProgramState* state, std::ostream& outf);
};

#endif