#include <QDateTime>

#include "die.h"

#include <QDebug>

Die::Die()
    : m_hasValue(false),m_displayStatus(false)
{
    uint seed = quintptr(this) + QDateTime::currentDateTime().toMSecsSinceEpoch();
    qsrand(seed);
}


void Die::setValue(qint64 r)
{
    m_value = r;
    m_hasValue = true;
}

void Die::insertRollValue(qint64 r)
{
    m_rollResult.append(r);
}

void Die::setSelected(bool b)
{
    m_selected = b;
}


bool Die::isSelected() const
{
    return m_selected;
}
qint64 Die::getValue() const
{
    if(m_hasValue)
        return m_value;
    else
    {
        qint64 value=0;
        foreach(qint64 tmp,m_rollResult)
        {
            value+=tmp;
        }
        return value;
    }
}
QList<qint64> Die::getListValue() const
{
    return m_rollResult;
}
bool Die::hasChildrenValue()
{
    return m_rollResult.size()>1?true:false;
}
void Die::replaceLastValue(qint64 value)
{
    m_rollResult.removeLast();
   insertRollValue(value);
}

void Die::roll(bool adding)
{
    quint64 value=(qrand()%m_faces)+1;

    if((adding)||(m_rollResult.isEmpty()))
    {
        insertRollValue(value);
    }
    else
    {
        replaceLastValue(value);
    }
}

quint64 Die::getFaces()
{
    return m_faces;
}

void Die::setFaces(quint64 face)
{
    m_faces=face;
}
qint64 Die::getLastRolledValue()
{
    if(!m_rollResult.isEmpty())
    {
        return m_rollResult.last();
    }
    else
        return 0;
}
bool Die::hasBeenDisplayed()
{
    return m_displayStatus;
}
void Die::displayed()
{
    m_displayStatus = true;
}
