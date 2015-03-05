/***************************************************************************
* Copyright (C) 2014 by Renaud Guezennec                                   *
* http://renaudguezennec.homelinux.org/accueil,3.html                      *
*                                                                          *
*  This file is part of DiceParser                                         *
*                                                                          *
* DiceParser is free software; you can redistribute it and/or modify       *
* it under the terms of the GNU General Public License as published by     *
* the Free Software Foundation; either version 2 of the License, or        *
* (at your option) any later version.                                      *
*                                                                          *
* This program is distributed in the hope that it will be useful,          *
* but WITHOUT ANY WARRANTY; without even the implied warranty of           *
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the             *
* GNU General Public License for more details.                             *
*                                                                          *
* You should have received a copy of the GNU General Public License        *
* along with this program; if not, write to the                            *
* Free Software Foundation, Inc.,                                          *
* 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.                 *
***************************************************************************/
#ifndef DICERESULT_H
#define DICERESULT_H
#include <QList>

#include "die.h"
#include "result.h"
/**
 * @brief The DiceResult class
 */
class DiceResult : public Result
{
public:
    /**
     * @brief DiceResult
     */
    DiceResult();

    /**
     * @brief getResultList
     * @return
     */
    QList<Die*>& getResultList();
    /**
     * @brief insertResult
     */
    void insertResult(Die*);

    /**
     * @brief setResultList
     * @param list
     */
    void setResultList(QList<Die*> list);

    /**
     * @brief getScalar
     * @return
     */
    virtual QVariant getResult(RESULT_TYPE);

private:
    qreal getScalarResult();
private:
    QList<Die*> m_diceValues;
};

#endif // DICERESULT_H
