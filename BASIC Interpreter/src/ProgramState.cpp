#include "ProgramState.h"

#include <map>
#include <stack>
#include <string>
using namespace std;

ProgramState::ProgramState(int numLines) : m_numLines(numLines) {}

// Update the value or insert new pair in the map if not found
void ProgramState::updateVal(std::string variableName, int val) {
    std::map<std::string, int>::iterator it = m_varList.find(variableName);
    if (it != m_varList.end()) {
        it->second = val;
    } else {
        m_varList.insert(std::make_pair(variableName, val));
    }
    return;
}

// Add to the variables value
void ProgramState::addToVal(std::string variableName, int val) {
    std::map<std::string, int>::iterator it = m_varList.find(variableName);
    if (it != m_varList.end()) {
        it->second += val;
    } else {
        m_varList.insert(std::make_pair(variableName, val));
    }
    return;
}

// Multiply the variables value and input value
void ProgramState::multVal(std::string variableName, int val) {
    std::map<std::string, int>::iterator it = m_varList.find(variableName);
    if (it != m_varList.end()) {
        it->second *= val;
    } else {
        m_varList.insert(std::make_pair(variableName, 0));
    }
    return;
}

// Divide the variable value by input value
void ProgramState::divVal(std::string variableName, int val) {
    std::map<std::string, int>::iterator it = m_varList.find(variableName);
    if (val == 0) {
        throw std::range_error("Divide by 0 exception");
    }
    if (it != m_varList.end()) {
        it->second /= val;
    } else {
        m_varList.insert(std::make_pair(variableName, 0));
    }
    return;
}

// Find the value based on the variable
int ProgramState::getVal(std::string variableName) {
    std::map<std::string, int>::iterator it = m_varList.find(variableName);
    if (it != m_varList.end()) {
        return it->second;
    }
    // if not found, create new variable and assign it value 0
    else {
        updateVal(variableName, 0);
        return 0;
    }
}

// Increment counter
void ProgramState::incCounter() {

    if (m_counter >= m_numLines) {
        return;
    }
    m_counter++;
}

// Return counter value
int ProgramState::valCounter() { return m_counter; }

// return status of terminate
bool ProgramState::getTerminate() { return terminate; }

// terminate the loop
void ProgramState::setTerminate() { terminate = true; }

// provides pointer to private map
const std::map<std::string, int>* ProgramState::getMap() {
    const map<string, int>* temp = &m_varList;
    return temp;
}

// returns total number of lines
int ProgramState::getNumLines() { return m_numLines; }

// sets counter equal to val
void ProgramState::updateCounter(int val) { m_counter = val; }

// pushes val onto stack
void ProgramState::pushStack(int val) { m_stack.push(val); }

// pops top value on staack
void ProgramState::popStack() { m_stack.pop(); }

// looks and returns top value on stack
int ProgramState::peekStack() { return m_stack.top(); }

// returns if stack is empty
bool ProgramState::stackEmpty() { return m_stack.empty(); }