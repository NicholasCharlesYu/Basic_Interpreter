#ifndef RETURN_STATEMENT_INCLUDED
#define RETURN_STATEMENT_INCLUDED

#include "GoToStatement.h"
#include "Statement.h"

class ReturnStatement : public Statement {
private:
    GoToStatement* m_goTo;

public:
    ~ReturnStatement();
    ReturnStatement();

    virtual void execute(ProgramState* state, std::ostream& outf);
};

#endif