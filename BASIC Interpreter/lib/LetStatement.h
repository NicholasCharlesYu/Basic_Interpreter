#ifndef LET_STATEMENT_INCLUDED
#define LET_STATEMENT_INCLUDED

#include "ProgramState.h"
#include "Statement.h"

class LetStatement : public Statement {
private:
    std::string m_variableName;
    int m_value;

public:
    ~LetStatement();
    LetStatement(std::string variableName, int value);

    virtual void execute(ProgramState* state, std::ostream& outf);
};

#endif
