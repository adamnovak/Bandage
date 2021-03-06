//Copyright 2015 Ryan Wick

//This file is part of Bandage

//Bandage is free software: you can redistribute it and/or modify
//it under the terms of the GNU General Public License as published by
//the Free Software Foundation, either version 3 of the License, or
//(at your option) any later version.

//Bandage is distributed in the hope that it will be useful,
//but WITHOUT ANY WARRANTY; without even the implied warranty of
//MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//GNU General Public License for more details.

//You should have received a copy of the GNU General Public License
//along with Bandage.  If not, see <http://www.gnu.org/licenses/>.


#ifndef BLASTHIT_H
#define BLASTHIT_H

class DeBruijnNode;
class BlastQuery;

#include <QString>
#include "blasthitpart.h"

class BlastHit
{
public:
    BlastHit(DeBruijnNode * node, int nodeStart, int nodeEnd,
             BlastQuery * query, int queryStart, int queryEnd,
             QString eValue);
    BlastHit();
    ~BlastHit();

    DeBruijnNode * m_node;
    int m_nodeStart;
    int m_nodeEnd;
    BlastQuery * m_query;
    int m_queryStart;
    int m_queryEnd;
    QString m_eValue;

    double m_nodeStartFraction;
    double m_nodeEndFraction;
    double m_queryStartFraction;
    double m_queryEndFraction;

    std::vector<BlastHitPart> getBlastHitParts(bool reverse);
    bool onForwardStrand() {return m_queryStart < m_queryEnd;}
};

#endif // BLASTHIT_H
