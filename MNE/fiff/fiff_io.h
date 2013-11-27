//=============================================================================================================
/**
* @file     fiff_io.cpp
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

#ifndef FIFF_IO_H
#define FIFF_IO_H

//*************************************************************************************************************
//=============================================================================================================
// INCLUDES
//=============================================================================================================

#include "fiff_global.h"
#include "fiff_info.h"
#include "fiff_types.h"

#include "fiff_raw_data.h"
#include "fiff_evoked.h"
#include <mne/mne.h>

//*************************************************************************************************************
//=============================================================================================================
// Qt INCLUDES
//=============================================================================================================

#include <QList>
#include <QIODevice>
#include <QSharedPointer>

//*************************************************************************************************************
//=============================================================================================================
// DEFINE NAMESPACE FIFFLIB
//=============================================================================================================

namespace FIFFLIB
{

//*************************************************************************************************************
//=============================================================================================================
// USED NAMESPACES
//=============================================================================================================

using namespace MNELIB;

class FIFFSHARED_EXPORT FiffIO : public QObject
{
public:
    enum Type {
        _RAW = FIFFB_RAW_DATA, //102
        _EVOKED = FIFFB_EVOKED, //104
        _PROJ = FIFFB_PROJ, //313
        _FWD = FIFFB_MNE_FORWARD_SOLUTION, //352
        _COV = FIFFB_MNE_COV, //355
        _NAMED_MATRIX = FIFFB_MNE_NAMED_MATRIX //357
    };

    //=========================================================================================================
    /**
    * Constructs a FiffIO
    *
    */
    FiffIO();

    //=========================================================================================================
    /**
    * Destroys the FiffIO.
    */
    ~FiffIO();

    //=========================================================================================================
    /**
    * Constructs a FiffIO object by reading from a I/O device p_pIODevice.
    *
    * @param[in] p_pIODevice    A fiff IO device like a fiff QFile or QTCPSocket
    */
    FiffIO(QIODevice& p_IODevice);

    //=========================================================================================================
    /**
    * Constructs a FiffIO object that uses the I/O device p_pIODevice.
    *
    * @param[in] p_qlistIODevices    A QList of fiff IO devices like a fiff QFile or QTCPSocket
    */
    //FiffIO(QList<QIODevice>& p_qlistIODevices);

    //=========================================================================================================
    /**
    * Copy constructor.
    *
    * @param[in] p_FiffIO    FiffIO, which should be copied
    */
    FiffIO(const FiffIO& p_FiffIO);

    //=========================================================================================================
    /**
    * Read data from a p_IODevice.
    *
    * @param[in] p_pIODevice    A fiff IO device like a fiff QFile or QTCPSocket
    */
    bool read(QIODevice& p_IODevice);

    //=========================================================================================================
    /**
    * Read data from a QList of p_IODevices.
    *
    * @param[in] p_qlistIODevices    A QList of fiff IO devices like a fiff QFile or QTCPSocket
    */
    //bool read(QList<QIODevice> p_qlistIODevices);

    //=========================================================================================================
    /**
    * Write data to a p_IODevice.
    *
    * @param[in] p_pIODevice    A fiff IO device like a fiff QFile or QTCPSocket
    */
    //bool write(QIODevice p_IODevice, Type type, fiff_int_t idx);

    //=========================================================================================================
    /**
    * Write data to a p_IODevice.
    *
    * @param[in] p_pIODevice    A fiff IO device like a fiff QFile or QTCPSocket
    */
    //bool write(QString filename, QString folder = "./"); //including AutoFileNaming, e.g. -raw/evoked/fwd.fiff

private:
    QList<QSharedPointer<FiffRawData*> > m_qlistRaw;
    QList<QSharedPointer<FiffEvoked*> > m_qlistEvoked;
    QList<QSharedPointer<FiffProj*> > m_qlistProj;
    QList<QSharedPointer<MNEForwardSolution*> > m_qlistFwd;
    QList<QSharedPointer<FiffCov*> > m_qlistCov;
    QList<QSharedPointer<FiffNamedMatrix*> > m_qlistNMatrix;
};

//*************************************************************************************************************
//=============================================================================================================
// INLINE DEFINITIONS
//=============================================================================================================


} // NAMESPACE

#endif // FIFF_IO_H
