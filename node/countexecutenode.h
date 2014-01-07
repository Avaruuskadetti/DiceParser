#ifndef COUNTEXECUTENODE_H
#define COUNTEXECUTENODE_H

#include "executionnode.h"

#include "validator.h"
#include "scalarresult.h"

class CountExecuteNode : public ExecutionNode
{
public:
    CountExecuteNode();
    virtual void run(ExecutionNode* previous);


    virtual void setValidator(Validator* );

private:
    Validator* m_validator;
    ScalarResult* m_scalarResult;
};

#endif // COUNTEXECUTENODE_H
