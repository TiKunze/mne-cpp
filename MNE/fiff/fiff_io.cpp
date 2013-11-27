//=============================================================================================================
/**
* @file     fiff_obj.cpp
* @author   Christoph Dinh <chdinh@nmr.mgh.harvard.edu>;
*           Florian Schlembach <florian.schlembach@tu-ilmenau.de>;
*           Matti Hamalainen <msh@nmr.mgh.harvard.edu>
* @version  1.0
* @date     July, 2012
*
* @section  LICENSE
*
* Copyright (C) 2012, Christoph Dinh and Matti Hamalainen. All rights reserved.
*
* Redistribution and use in source and binary forms, with or without modification, are permitted provided that
* the following conditions are met:
*     * Redistributions of source code must retain the above copyright notice, this list of conditions and the
*       following disclaimer.
*     * Redistributions in binary form must reproduce the above copyright notice, this list of conditions and
*       the following disclaimer in the documentation and/or other materials provided with the distribution.
*     * Neither the name of the Massachusetts General Hospital nor the names of its contributors may be used
*       to endorse or promote products derived from this software without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED
* WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
* PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL MASSACHUSETTS GENERAL HOSPITAL BE LIABLE FOR ANY DIRECT,
* INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
* PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
* HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
* NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
* POSSIBILITY OF SUCH DAMAGE.
*
*
* @brief    Implementation of a generic Fiff IO interface
*
*/

//*************************************************************************************************************
//=============================================================================================================
// INCLUDES
//=============================================================================================================

#include "fiff_io.h"
#include "fiff_stream.h"

//*************************************************************************************************************
//=============================================================================================================
// USED NAMESPACES
//=============================================================================================================

using namespace FIFFLIB;

//*************************************************************************************************************
//=============================================================================================================
// DEFINE MEMBER METHODS
//=============================================================================================================

FiffIO::FiffIO()
{
}

//*************************************************************************************************************

FiffIO::~FiffIO()
{
}

//*************************************************************************************************************

FiffIO::FiffIO(QIODevice& p_IODevice)
{
    // execute read method
    FiffIO::read(p_IODevice);
}

//*************************************************************************************************************

//FiffIO::FiffIO(QList<QIODevice>& p_qlistIODevices)
//{
//    // execute read method..., iterate through QList
//}

//*************************************************************************************************************
bool FiffIO::read(QIODevice& p_IODevice)
{
    //perform read routines, all sort of types -> raw, evoked
    std::cout << "reading file..." << std::endl;

    FiffRawData raw(p_IODevice);
    QSharedPointer<FiffRawData*> tmpraw = &raw; //to be debugged

    //m_qlistRaw.push_back(tmpraw);
}

//*************************************************************************************************************

FiffIO::FiffIO(const FiffIO& p_FiffIO)
: m_qlistRaw(p_FiffIO.m_qlistRaw)
, m_qlistEvoked(p_FiffIO.m_qlistEvoked)
, m_qlistProj(p_FiffIO.m_qlistProj)
, m_qlistFwd(p_FiffIO.m_qlistFwd)
, m_qlistCov(p_FiffIO.m_qlistCov)
, m_qlistNMatrix(p_FiffIO.m_qlistNMatrix)
{

}

//*************************************************************************************************************
