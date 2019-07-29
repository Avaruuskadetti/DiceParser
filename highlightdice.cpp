/***************************************************************************
 *   Copyright (C) 2016 by Renaud Guezennec                                *
 *   http:://www.rolisteam.org/contact                                     *
 *                                                                         *
 *   rolisteam is free software; you can redistribute it and/or modify     *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/
#include "include/highlightdice.h"

HighLightDice::HighLightDice(QList<qint64> result, bool isHighlighted, QString color, bool displayed, quint64 faces)
    : m_result(result), m_hasHighlight(isHighlighted), m_color(color), m_displayed(displayed), m_faces(faces)
{
}

HighLightDice::~HighLightDice() {}

QList<qint64> HighLightDice::getResult() const
{
    return m_result;
}

void HighLightDice::setResult(const QList<qint64>& result)
{
    m_result= result;
}

bool HighLightDice::isHighlighted() const
{
    return m_hasHighlight;
}

void HighLightDice::setHighlight(bool hasHighlight)
{
    m_hasHighlight= hasHighlight;
}

QString HighLightDice::getColor() const
{
    return m_color;
}

void HighLightDice::setColor(const QString& color)
{
    m_color= color;
}

bool HighLightDice::getDisplayed() const
{
    return m_displayed;
}

void HighLightDice::setDisplayed(bool displayed)
{
    m_displayed= displayed;
}

quint64 HighLightDice::getFaces() const
{
    return m_faces;
}

void HighLightDice::setFaces(const quint64& faces)
{
    m_faces= faces;
}
