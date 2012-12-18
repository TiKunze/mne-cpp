#ifndef SOURCELAB_H
#define SOURCELAB_H


//*************************************************************************************************************
//=============================================================================================================
// INCLUDES
//=============================================================================================================


//*************************************************************************************************************
//=============================================================================================================
// INVRT INCLUDES
//=============================================================================================================

#include "../MNE/invrt/covrt.h"


//*************************************************************************************************************
//=============================================================================================================
// FIFF INCLUDES
//=============================================================================================================

#include "../MNE/fiff/fiff_info.h"


//*************************************************************************************************************
//=============================================================================================================
// MNE INCLUDES
//=============================================================================================================

#include "../MNE/mne/mne_rt_client.h"


//*************************************************************************************************************
//=============================================================================================================
// Generics INCLUDES
//=============================================================================================================

#include "../MNE/generics/circularmatrixbuffer.h"


//*************************************************************************************************************
//=============================================================================================================
// QT INCLUDES
//=============================================================================================================

#include <QThread>
#include <QMutex>


//*************************************************************************************************************
//=============================================================================================================
// USED NAMESPACES
//=============================================================================================================

using namespace IOBuffer;
using namespace FIFFLIB;
using namespace MNELIB;
using namespace INVRTLIB;


class SourceLab : public QThread
{
    Q_OBJECT
public:
//    friend class RtDataManager;

    explicit SourceLab(QObject *parent = 0);

    //=========================================================================================================
    /**
    * Destroys the SourceLab.
    */
    ~SourceLab();


    virtual bool start();

    virtual bool stop();

    void receiveRawBuffer(MatrixXf p_rawBuffer);

protected:
    //=========================================================================================================
    /**
    * The starting point for the thread. After calling start(), the newly created thread calls this function.
    * Returning from this method will end the execution of the thread.
    * Pure virtual method inherited by QThread.
    */
    virtual void run();

signals:
    void closeSourceLab();

private:
    MNERtClient*    m_pRtClient;
    CovRt*          m_pCovRt;



    FiffInfo*       m_pFiffInfo;         /**< Holds the fiff raw measurement information. */
    RawMatrixBuffer* m_pRawMatrixBuffer;    /**< The Circular Raw Matrix Buffer. */

    bool    m_bIsRunning;
    bool    m_bIsRawBufferInit;

    QMutex mutex;

};

#endif // SOURCELAB_H
