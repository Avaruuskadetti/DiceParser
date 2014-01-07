#ifndef NUMBERNODE_H
#define NUMBERNODE_H

#include "node/executionnode.h"
#include "scalarresult.h"

class NumberNode : public ExecutionNode
{
public:
    NumberNode();
    void run(ExecutionNode* previous);
    void setNumber(qint64);

private:
    qint64 m_number;
    ScalarResult* m_scalarResult;
};

#endif // NUMBERNODE_H
