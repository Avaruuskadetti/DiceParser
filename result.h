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
#ifndef RESULT_H
#define RESULT_H

#include <Qt>
#include <QString>

/**
 * @brief The Result class
 */
class Result
{
public:
    /**
     * @brief Result
     */
    Result();
    /**
     * @brief isScalar
     * @return
     */
    virtual bool isScalar() const = 0;
    /**
     * @brief getScalar
     * @return
     */
    virtual qreal getScalar() = 0;
    /**
     * @brief getPrevious
     * @return
     */
    virtual Result* getPrevious();
    /**
     * @brief setPrevious
     */
    virtual void setPrevious(Result*);

    virtual bool isStringResult();
    virtual QString getStringResult();

private:
    Result* m_previous;/// @brief
};

#endif // RESULT_H
