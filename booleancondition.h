#ifndef BOOLEANCONDITION_H
#define BOOLEANCONDITION_H

#include <Qt>
#include "validator.h"

class BooleanCondition : public Validator
{
public:
    enum LogicOperator { Equal, GreaterThan, LesserThan, GreaterOrEqual, LesserOrEqual};
    BooleanCondition();

    virtual qint64 hasValid(Die* b,bool recursive) const;

    void setOperator(LogicOperator m);
    void setValue(qint64);

private:
    LogicOperator m_operator;
    qint64 m_value;
};

#endif // BOOLEANCONDITION_H
