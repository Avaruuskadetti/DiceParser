#ifndef SCALAROPERATORNODE_H
#define SCALAROPERATORNODE_H

#include <QMap>
#include <QChar>

#include "executionnode.h"
#include "scalarresult.h"

class ScalarOperatorNode : public ExecutionNode
{
public:
    enum ScalarOperator {PLUS,MINUS,DIVIDE,MULTIPLICATION};
    ScalarOperatorNode();
    virtual void run(ExecutionNode*);
    bool setOperatorChar(QChar c);
    void setInternalNode(ExecutionNode* node);

    virtual QString toString()const;
    virtual qint64 getPriority() const;


private:
    qint64 add(qint64,qint64);
    qint64 substract(qint64,qint64);
    qreal divide(qint64,qint64);
    qint64 multiple(qint64,qint64);

private:
    ScalarOperator m_myOperator;
    ExecutionNode* m_internalNode;
    QMap<QChar,ScalarOperator> m_scalarOperationList;
    ScalarResult* m_scalarResult;
};

#endif // SCALAROPERATORNODE_H

