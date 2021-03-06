//=============================================================================================================
/**
* @file     rtsss.h
* @author   Christoph Dinh <chdinh@nmr.mgh.harvard.edu>;
*           Matti Hamalainen <msh@nmr.mgh.harvard.edu>
* @version  1.0
* @date     February, 2013
*
* @section  LICENSE
*
* Copyright (C) 2013, Christoph Dinh and Matti Hamalainen. All rights reserved.
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
* @brief    Contains the declaration of the RTSSS class.
*
*/

#ifndef RTSSS_H
#define RTSSS_H


//*************************************************************************************************************
//=============================================================================================================
// INCLUDES
//=============================================================================================================

#include "rtsss_global.h"

#include <mne_x/Interfaces/IAlgorithm.h>
#include <generics/circularbuffer.h>
#include <xMeas/newrealtimesamplearray.h>


//*************************************************************************************************************
//=============================================================================================================
// QT INCLUDES
//=============================================================================================================

#include <QtWidgets>


//*************************************************************************************************************
//=============================================================================================================
// DEFINE NAMESPACE RTSSSPlugin
//=============================================================================================================

namespace RtSssPlugin
{


//*************************************************************************************************************
//=============================================================================================================
// USED NAMESPACES
//=============================================================================================================

using namespace MNEX;
using namespace XMEASLIB;
using namespace IOBuffer;


//*************************************************************************************************************
//=============================================================================================================
// FORWARD DECLARATIONS
//=============================================================================================================


//=============================================================================================================
/**
* DECLARE CLASS RTSSS
*
* @brief The RtSss class provides a rtsss algorithm structure.
*/
//class DUMMYTOOLBOXSHARED_EXPORT DummyToolbox : public IAlgorithm
class RTSSSSHARED_EXPORT RtSss : public IAlgorithm
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "mne_x/1.0" FILE "rtsss.json") //NEW Qt5 Plugin system replaces Q_EXPORT_PLUGIN2 macro
    // Use the Q_INTERFACES() macro to tell Qt's meta-object system about the interfaces
    Q_INTERFACES(MNEX::IAlgorithm)

public:
    //=========================================================================================================
    /**
    * Constructs a RtSss.
    */
//    DummyToolbox();
    RtSss();

    //=========================================================================================================
    /**
    * Destroys the RtSss.
    */
//    ~DummyToolbox();
    ~RtSss();

    //=========================================================================================================
    /**
    * Initialise input and output connectors.
    */
    void init();

    //=========================================================================================================
    /**
    * Clone the plugin
    */
    virtual QSharedPointer<IPlugin> clone() const;

    virtual bool start();
    virtual bool stop();

    virtual IPlugin::PluginType getType() const;
    virtual QString getName() const;

    virtual QWidget* setupWidget();

    void update(XMEASLIB::NewMeasurement::SPtr pMeasurement);

protected:
    virtual void run();

private:
//    PluginInputData<NewRealTimeSampleArray>::SPtr   m_pDummyInput;      /**< The RealTimeSampleArray of the DummyToolbox input.*/
//    PluginOutputData<NewRealTimeSampleArray>::SPtr  m_pDummyOutput;    /**< The RealTimeSampleArray of the DummyToolbox output.*/
    PluginInputData<NewRealTimeSampleArray>::SPtr   m_pRTSAInput;      /**< The RealTimeSampleArray of the RtSss input.*/
    PluginOutputData<NewRealTimeSampleArray>::SPtr  m_pRTSAOutput;    /**< The RealTimeSampleArray of the RtSss output.*/

    //  from sourcelab.h
//    PluginInputData<NewRealTimeMultiSampleArray>::SPtr  m_pRTMSAInput;  /**< The RealTimeMultiSampleArray input.*/
//    PluginOutputData<RealTimeSourceEstimate>::SPtr      m_pRTSEOutput;  /**< The RealTimeSourceEstimate output.*/

//    dBuffer::SPtr   m_pDummyBuffer;      /**< Holds incoming data.*/
    dBuffer::SPtr   m_pRtSssBuffer;      /**< Holds incoming data.*/
};

} // NAMESPACE

#endif // RTSSS_H
