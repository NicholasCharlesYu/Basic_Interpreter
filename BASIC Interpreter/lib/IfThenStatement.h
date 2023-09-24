#ifndef IF_THEN_STATEMENT_INCLUDED
#define IF_THEN_STATEMENT_INCLUDED

#include "GoToStatement.h"
#include "Statement.h"

class IfThenStatement : public Statement {
private:
    std::string m_variableName;
    std::string m_operator;
    int m_value;
    int m_lineNum;
    // has-a GoTo
    GoToStatement* m_goTo;

public:
    ~IfThenStatement();
    IfThenStatement(std::string variableName, std::string op, int value, int lineNum);

    virtual void execute(ProgramState* state, std::ostream& outf);
};

#endif