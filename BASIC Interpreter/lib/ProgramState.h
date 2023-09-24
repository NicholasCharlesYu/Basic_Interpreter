#ifndef PROGRAM_STATE_INCLUDED
#define PROGRAM_STATE_INCLUDED

#include <map>
#include <stack>

class ProgramState {
public:
    ProgramState(int numLines);

    void updateVal(std::string variableName, int val);  // update values in map

    void incCounter();  // increment counter

    int valCounter();  // returns current value of counter

    int getVal(std::string variableName);  // gets value associated with variable

    void endCounter();  // set counter to override while statement

    bool getTerminate();  // gets value of terminate

    void setTerminate();  // sets terminate value to true

    const std::map<std::string, int>* getMap();  // returns pointer to map

    void addToVal(std::string variableName, int val);  // adds val to current variable value

    void multVal(std::string variableName, int val);  // multiplies current variable value by val

    void divVal(std::string variableName, int val);  // divides current variable value by val

    int getNumLines();  // returns number of lines

    void updateCounter(int val);  // updates the counter to val

    void pushStack(int val);  // pushes val into the stack

    void popStack();  // pops stack

    int peekStack();  // gets top variable on stack

    bool stackEmpty();  // checks if stack is empty

private:
    int m_numLines;

    // keeps track of line number
    int m_counter = 1;

    // map of variables
    std::map<std::string, int> m_varList;

    // stack for GOSUB
    std::stack<int> m_stack;

    // indicate the end of the interpret program
    bool terminate = false;
};

#endif
