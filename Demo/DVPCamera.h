#ifndef __DVPCAMERA_H__
#define __DVPCAMERA_H__

#define dvpPtr(ptr) ptr*

#ifndef __cplusplus
#define bool unsigned char
#define false (0)
#define true  (1)
#endif

#ifndef _WIN32
#ifndef __cplusplus
#define dvp2api extern
#else
#define dvp2api extern "C"
#endif
#else
#include <windows.h>
#ifndef __cplusplus
#define dvp2api extern     __declspec(dllimport)
#else
#define dvp2api extern "C" __declspec(dllimport)
#endif
#endif

dvp2api const unsigned int dvpVersion[4];


typedef enum dvpImageFormat
{
    FORMAT_MONO = 0,

    FORMAT_BAYER_BG = 1,

    FORMAT_BAYER_GB = 2,

    FORMAT_BAYER_GR = 3,

    FORMAT_BAYER_RG = 4,

    FORMAT_BGR24 = 10,

    FORMAT_BGR32 = 11,

    FORMAT_BGR48 = 12,

    FORMAT_BGR64 = 13,

    FORMAT_RGB24 = 14,

    FORMAT_RGB32 = 15,

    
    FORMAT_RGB48 = 16,

    
    FORMAT_YUV411 = 20,

    
    FORMAT_YUV422 = 21,

    
    FORMAT_YUV444 = 22,

    
    FORMAT_YUV420 = 23,

    
    FORMAT_B8_G8_R8 = 40,

    
    FORMAT_B16_G16_R16 = 44,

} dvpImageFormat;



typedef enum dvpStreamFormat
{
    
    S_RAW8 = 0,

    
    S_RAW10 = 1,

    
    S_RAW12 = 2,

    
    S_RAW14 = 3,

    
    S_RAW16 = 4,

    
    S_BGR24 = 10,

    
    S_BGR32 = 11,

    
    S_BGR48 = 12,

    
    S_BGR64 = 13,

    
    S_RGB24 = 14,

    
    S_RGB32 = 15,

    
    S_RGB48 = 16,

    
    S_RGB64 = 17,

    
    S_YUV411 = 20,

    
    S_YUV422 = 21,

    
    S_YUV444 = 22,

    
    S_YUV420 = 23,

    
    S_MONO8 = 30,

    
    S_MONO10 = 31,

    
    S_MONO12 = 32,

    
    S_MONO14 = 33,

    
    S_MONO16 = 34,

    
    S_B8_G8_R8 = 40,

    
    S_B16_G16_R16 = 44,

} dvpStreamFormat;



typedef enum dvpBits
{
    
    BITS_8 = 0,

    
    BITS_10 = 1,

    
    BITS_12 = 2,

    
    BITS_14 = 3,

    
    BITS_16 = 4,

} dvpBits;



typedef enum dvpAeMode
{
    
    AE_MODE_AE_AG = 0,

    
    AE_MODE_AG_AE = 1,

    
    AE_MODE_AE_ONLY = 2,

    
    AE_MODE_AG_ONLY = 3,

} dvpAeMode;



typedef enum dvpAeOperation
{
    
    AE_OP_OFF = 0,

    
    AE_OP_ONCE = 1,

    
    AE_OP_CONTINUOUS = 2,

} dvpAeOperation;



typedef enum dvpAwbOperation
{
    
    AWB_OP_OFF = 0,

    
    AWB_OP_ONCE = 1,

    
    AWB_OP_CONTINUOUS = 2,

} dvpAwbOperation;



typedef enum dvpAntiFlick
{
    
    ANTIFLICK_DISABLE = 0,

    
    ANTIFLICK_50HZ = 1,

    
    ANTIFLICK_60HZ = 2,

} dvpAntiFlick;



typedef enum dvpSensorType
{
    
    SENSOR_TYPE_CMOS = 0,

    
    SENSOR_TYPE_CCD = 1,

} dvpSensorType;



typedef enum dvpSensorPixel
{
    
    SENSOR_PIXEL_MONO = 0,

    
    SENSOR_PIXEL_BAYER_RG = 1,

    
    SENSOR_PIXEL_BAYER_GB = 2,

    
    SENSOR_PIXEL_BAYER_GR = 3,

    
    SENSOR_PIXEL_BAYER_BG = 4,

} dvpSensorPixel;



typedef enum dvpStreamEvent
{
    
    STREAM_EVENT_ARRIVED = 0,

    
    STREAM_EVENT_CORRECTED = 1,

    
    STREAM_EVENT_PROCESSED = 2,

    
    STREAM_EVENT_FRAME_THREAD = 3,

} dvpStreamEvent;



typedef enum dvpEvent
{
    
    EVENT_UNKNOW = 0,

    
    EVENT_CONNECTED = 1,

    
    EVENT_DISCONNECTED = 2,

    
    EVENT_STREAM_STARTRD = 3,

    
    EVENT_STREAM_STOPPED = 4,

    
    EVENT_FRAME_LOST = 5,

    
    EVENT_FRAME_TIMEOUT = 6,

    
    EVENT_LOST_CONNECTION = 7,

    
    EVENT_RECONNECTED = 8,

    
    EVENT_FRAME_START = 9,

    
    EVENT_FRAME_END = 10,

} dvpEvent;



typedef enum dvpTriggerInputType
{
    
    TRIGGER_IN_OFF = 0,

    
    TRIGGER_NEG_EDGE = 1,

    
    TRIGGER_LOW_LEVEL = 2,

    
    TRIGGER_POS_EDGE = 3,

    
    TRIGGER_HIGH_LEVEL = 4,

} dvpTriggerInputType;



typedef enum dvpStrobeOutputType
{
    
    STROBE_OUT_OFF = 0,

    
    STROBE_OUT_LOW = 1,

    
    STROBE_OUT_HIGH = 2,

} dvpStrobeOutputType;



typedef enum dvpStrobeDriver
{
    
    FRAME_DURATION = 0,

    
    TIMER_LOGIC = 1,

    
    SENSOR_STROBE = 2,

} dvpStrobeDriver;



typedef enum dvpOutputIoFunction
{
    
    OUTPUT_FUNCTION_NORMAL = 0x0000,

    
    OUTPUT_FUNCTION_STROBE = 0x0001,

} dvpOutputIoFunction;



typedef enum dvpInputIoFunction
{
    
    INPUT_FUNCTION_NORMAL = 0x8001,

    
    INPUT_FUNCTION_TRIGGER = 0x8002,

} dvpInputIoFunction;



typedef enum dvpOutputIo
{
    
    OUTPUT_IO_1 = 0x0001,

    
    OUTPUT_IO_2 = 0x0002,

    
    OUTPUT_IO_3 = 0x0003,

    
    OUTPUT_IO_4 = 0x0004,

    
    OUTPUT_IO_5 = 0x0005,

    
    OUTPUT_IO_6 = 0x0006,

    
    OUTPUT_IO_7 = 0x0007,

    
    OUTPUT_IO_8 = 0x0008,

} dvpOutputIo;



typedef enum dvpInputIo
{
    
    INPUT_IO_1 = 0x8001,

    
    INPUT_IO_2 = 0x8002,

    
    INPUT_IO_3 = 0x8003,

    
    INPUT_IO_4 = 0x8004,

    
    INPUT_IO_5 = 0x8005,

    
    INPUT_IO_6 = 0x8006,

    
    INPUT_IO_7 = 0x8007,

    
    INPUT_IO_8 = 0x8008,

} dvpInputIo;



typedef enum dvpLine
{
    
    LINE_1 = 0x10001,

    
    LINE_2 = 0x10002,

    
    LINE_3 = 0x10003,

    
    LINE_4 = 0x10004,

    
    LINE_5 = 0x10005,

    
    LINE_6 = 0x10006,

    
    LINE_7 = 0x10007,

    
    LINE_8 = 0x10008,

} dvpLine;



typedef enum dvpLineMode
{
    
    LINE_MODE_INPUT = 0,

    
    LINE_MODE_OUTPUT = 1,

} dvpLineMode;



typedef enum dvpLineSource
{
    
    OUTPUT_SOURCE_NORMAL = 0,

    
    OUTPUT_SOURCE_STROBE = 1,

    
    OUTPUT_SOURCE_PWM = 2,

} dvpLineSource;



typedef enum dvpTriggerLineMode
{
    
    TRIGGER_LINE_MODE_NORMAL = 0,

    
    TRIGGER_LINE_MODE_BULB = 1,

} dvpTriggerLineMode;



typedef enum dvpTriggerSource
{
    
    TRIGGER_SOURCE_SOFTWARE = 0,

    
    TRIGGER_SOURCE_LINE1 = 1,

    
    TRIGGER_SOURCE_LINE2 = 2,

    
    TRIGGER_SOURCE_LINE3 = 3,

    
    TRIGGER_SOURCE_LINE4 = 4,

    
    TRIGGER_SOURCE_LINE5 = 5,

    
    TRIGGER_SOURCE_LINE6 = 6,

    
    TRIGGER_SOURCE_LINE7 = 7,

    
    TRIGGER_SOURCE_LINE8 = 8,

} dvpTriggerSource;



typedef enum dvpFirstPosition
{
    
    UP_LEFT = 0,

    
    UP_RIGHT = 1,

    
    BOTTOM_LEFT = 2,

    
    BOTTOM_RIGHT = 3,

} dvpFirstPosition;



typedef enum dvpOpenMode
{
    
    OPEN_OFFLINE = 0,

    
    OPEN_NORMAL = 1<<0,

    
    OPEN_DEBUG = 1<<3,

    
    HIGH_PRIORITY = 1<<4,

} dvpOpenMode;



typedef enum dvpStreamState
{
    
    STATE_STOPED = 0,

    
    STATE_STARTED = 2,

} dvpStreamState;



typedef enum dvpCurveStyle
{
    
    CURVE_STYLE_LINE = 0,

    
    CURVE_STYLE_WAVE = 1,

} dvpCurveStyle;



typedef enum dvpUserSet
{
    
    USER_SET_DEFAULT = 0,

    
    USER_SET_1 = 1,

    
    USER_SET_2 = 2,

} dvpUserSet;



typedef enum dvpBufferMode
{
    
    BUFFER_MODE_NEWEST = 0,

    
    BUFFER_MODE_FIFO = 1,

} dvpBufferMode;



typedef enum dvpDeviceType
{
    
    DEVICE_TYPE_UNKNOWN = 0,

    
    DEVICE_TYPE_USB2_CAMERA = 10,

    
    DEVICE_TYPE_USB3_CAMERA = 20,

    
    DEVICE_TYPE_GLAN_CAMERA = 30,

    
    DEVICE_TYPE_XGIGE_CAMERA = 40,

    
    DEVICE_TYPE_XGIGE_GRABBER = 100,

} dvpDeviceType;



typedef enum dvpReportPart
{
    
    PART_DEFAULT = 0x00,

    
    PART_LINK = 0x10,

    
    PART_CONTROL = 0x20,

    
    PART_STREAM = 0x30,

    
    PART_TRIG = 0x40,

    
    PART_GPIO = 0x50,

    
    PART_IMAGE = 0x60,

} dvpReportPart;



typedef enum dvpReportLevel
{
    
    LEVEL_INFO = 0x10,

    
    LEVEL_PROBLEM = 0x40,

} dvpReportLevel;



typedef enum dvpStatus
{
    
    DVP_STATUS_IGNORED = 7,

    
    DVP_STATUS_NEED_OTHER = 6,

    
    DVP_STATUS_NEXT_STAGE = 5,

    
    DVP_STATUS_BUSY = 4,

    
    DVP_STATUS_WAIT = 3,

    
    DVP_STATUS_IN_PROCESS = 2,

    
    DVP_STATUS_OK = 1,

    
    DVP_STATUS_FAILED = 0,

    
    DVP_STATUS_UNKNOW = -1,

    
    DVP_STATUS_NOT_SUPPORTED = -2,

    
    DVP_STATUS_NOT_INITIALIZED = -3,

    
    DVP_STATUS_PARAMETER_INVALID = -4,

    
    DVP_STATUS_PARAMETER_OUT_OF_BOUND = -5,

    
    DVP_STATUS_UNENABLED = -6,

    
    DVP_STATUS_UNCONNECTED = -7,

    
    DVP_STATUS_NOT_VALID = -8,

    
    DVP_STATUS_UNPLAY = -9,

    
    DVP_STATUS_NOT_STARTED = -10,

    
    DVP_STATUS_NOT_STOPPED = -11,

    
    DVP_STATUS_NOT_READY = -12,

    
    DVP_STATUS_INVALID_HANDLE = -13,

    
    DVP_STATUS_DESCR_FAULT = -20,

    
    DVP_STATUS_NAME_FAULT = -21,

    
    DVP_STATUS_VALUE_FAULT = -22,

    
    DVP_STATUS_LIMITED = -28,

    
    DVP_STATUS_FUNCTION_INVALID = -29,

    
    DVP_STATUS_IN_AUTO = -30,

    
    DVP_STATUS_DENIED = -31,

    
    DVP_STATUS_BAD_ALIGNMENT = -40,

    
    DVP_STATUS_ADDRESS_INVALID = -41,

    
    DVP_STATUS_SIZE_INVALID = -42,

    
    DVP_STATUS_OVER_LOAD = -43,

    
    DVP_STATUS_UNDER_LOAD = -44,

    
    DVP_STATUS_CHECKED_FAILED = -50,

    
    DVP_STATUS_UNUSABLE = -51,

    
    DVP_STATUS_BID_INVALID = -52,

    
    DVP_STATUS_IMPROPER = -53,

    
    DVP_STATUS_READ_ONLY = -54,

    
    DVP_STATUS_UNRECOGNIZED_DATA = -55,

    
    DVP_STATUS_TIME_OUT = -1000,

    
    DVP_STATUS_IO_ERROR = -1001,

    
    DVP_STATUS_COMM_ERROR = -1002,

    
    DVP_STATUS_BUS_ERROR = -1003,

    
    DVP_STATUS_FORMAT_INVALID = -1004,

    
    DVP_STATUS_CONTENT_INVALID = -1005,

    
    DVP_STATUS_I2C_FAULT = -1010,

    
    DVP_STATUS_I2C_ACK_TIMEOUT = -1011,

    
    DVP_STATUS_I2C_BUS_TIMEOUT = -1012,

    
    DVP_STATUS_SPI_FAULT = -1020,

    
    DVP_STATUS_UART_FAULT = -1030,

    
    DVP_STATUS_GPIO_FAULT = -1040,

    
    DVP_STATUS_USB_FAULT = -1050,

    
    DVP_STATUS_PCI_FAULT = -1060,

    
    DVP_STATUS_PHY_FAULT = -1070,

    
    DVP_STATUS_LINK_FAULT = -1080,

    
    DVP_STATUS_TRANS_FAULT = -1090,

    
    DVP_STATUS_NO_DEVICE_FOUND = -1100,

    
    DVP_STATUS_NO_LOGIC_DEVICE_FOUND = -1101,

    
    DVP_STATUS_DEVICE_IS_OPENED = -1102,

    
    DVP_STATUS_DEVICE_IS_CLOSED = -1103,

    
    DVP_STATUS_DEVICE_IS_DISCONNECTED = -1104,

    
    DVP_STATUS_DEVICE_IS_OPENED_BY_ANOTHER = -1105,

    
    DVP_STATUS_DEVICE_IS_STARTED = -1106,

    
    DVP_STATUS_DEVICE_IS_STOPPED = -1107,

    
    DVP_STATUS_INSUFFICIENT_MEMORY = -1200,

    
    DVP_STATUS_MEMORY_FAULT = -1201,

    
    DVP_STATUS_WRITE_PROTECTED = -1202,

    
    DVP_STATUS_FILE_CREATE_FAILED = -1300,

    
    DVP_STATUS_FILE_INVALID = -1301,

    
    DVP_STATUS_FILE_READ_FAILED = -1302,

    
    DVP_STATUS_FILE_WRITE_FAILED = -1303,

    
    DVP_STATUS_FILE_OPEN_FAILED = -1304,

    
    DVP_STATUS_FILE_CHECKSUM_FAILED = -1305,

    
    DVP_STATUS_GRAB_FAILED = -1600,

    
    DVP_STATUS_LOST_DATA = -1601,

    
    DVP_STATUS_EOF_ERROR = -1602,

    
    DVP_STATUS_GRAB_IS_OPENED = -1603,

    
    DVP_STATUS_GRAB_IS_CLOSED = -1604,

    
    DVP_STATUS_GRAB_IS_STARTED = -1605,

    
    DVP_STATUS_GRAB_IS_STOPPED = -1606,

    
    DVP_STATUS_GRAB_IS_RESTARTING = -1607,

    
    DVP_STATUS_ROI_PARAM_INVALID = -1610,

    
    DVP_STATUS_ROI_NOT_SUPPORTED = -1611,

} dvpStatus;



#ifndef _WIN32

#include <stdint.h>


typedef uint8_t dvpByte;


typedef int32_t dvpInt32;


typedef uint32_t dvpUint32;


typedef int64_t dvpInt64;


typedef uint64_t dvpUint64;

#else

typedef BYTE dvpByte;


typedef INT32 dvpInt32;


typedef UINT32 dvpUint32;


typedef INT64 dvpInt64;


typedef UINT64 dvpUint64;

#endif // _WIN32

typedef dvpUint32 dvpReserved[32];


typedef char dvpString64[64];


typedef char dvpString128[128];


typedef bool dvpBool32[32];


typedef float dvpMatrix[4][3];


typedef float dvpFloat3c[3];


typedef dvpUint32 dvpSize3c[3];


typedef dvpUint32 dvpHandle;


typedef dvpUint32 dvpRecordHandle;


typedef const char* dvpStr;


typedef struct dvpColorMatrix
{
    
    dvpMatrix matrix;

    
    dvpReserved reserved;
} dvpColorMatrix;



typedef struct dvpColorCorrection
{
    
    dvpFloat3c bgr;

    
    dvpReserved reserved;
} dvpColorCorrection;



typedef struct dvpPoint2f
{
    
    float X;

    
    float Y;

} dvpPoint2f;



typedef struct dvpPoint2f dvpPoint3c[3][256];


typedef struct dvpCurveArray
{
    
    dvpPoint3c point;

    
    dvpUint32 rows;

    
    dvpSize3c cols;

} dvpCurveArray;



typedef struct dvpCurveLut
{
    
    bool enable;

    
    dvpCurveStyle style;

    
    dvpCurveArray array;

    
    dvpReserved reserved;
} dvpCurveLut;



typedef struct dvpCameraInfo
{
    
    dvpString64 Vendor;

    
    dvpString64 Manufacturer;

    
    dvpString64 Model;

    
    dvpString64 Family;

    
    dvpString64 LinkName;

    
    dvpString64 SensorInfo;

    
    dvpString64 HardwareVersion;

    
    dvpString64 FirmwareVersion;

    
    dvpString64 KernelVersion;

    
    dvpString64 DscamVersion;

    
    dvpString64 FriendlyName;

    
    dvpString64 PortInfo;

    
    dvpString64 SerialNumber;

    
    dvpString128 CameraInfo;

    
    dvpString128 UserID;

    
    dvpString64 OriginalSerialNumber;

    
    dvpString64 reserved;
} dvpCameraInfo;



typedef struct dvpRegionDescr
{
    
    dvpInt32 iMinW;

    
    dvpInt32 iMinH;

    
    dvpInt32 iMaxW;

    
    dvpInt32 iMaxH;

    
    dvpInt32 iStepW;

    
    dvpInt32 iStepH;

    
    dvpReserved reserved;
} dvpRegionDescr;



typedef struct dvpRegion
{
    
    dvpInt32 X;

    
    dvpInt32 Y;

    
    dvpInt32 W;

    
    dvpInt32 H;

    
    dvpReserved reserved;
} dvpRegion;



typedef struct dvpFrame
{
    
    enum dvpImageFormat format;

    
    enum dvpBits bits;

    
    dvpUint32 uBytes;

    
    dvpInt32 iWidth;

    
    dvpInt32 iHeight;

    
    dvpUint64 uFrameID;

    
    dvpUint64 uTimestamp;

    
    double fExposure;

    
    float fAGain;

    
    enum dvpFirstPosition position;

    
    bool bFlipHorizontalState;

    
    bool bFlipVerticalState;

    
    bool bRotateState;

    
    bool bRotateOpposite;

    
    dvpUint32 internalFlags;

    
    dvpUint32 internalValue;

    
    dvpUint64 uTriggerId;

    
    dvpUint64 userValue;

    
    dvpUint32 reserved[24];
} dvpFrame;



typedef struct dvpFrameBuffer
{
    
    struct dvpFrame frame;

    
    dvpPtr(dvpByte) pBuffer;

} dvpFrameBuffer;



typedef struct dvpVariant
{
    
    dvpPtr(dvpByte) pData;

    
    dvpUint32 uSize;

    
    dvpString64 name;

} dvpVariant;



typedef struct dvpIntDescr
{
    
    dvpInt32 iStep;

    
    dvpInt32 iMin;

    
    dvpInt32 iMax;

    
    dvpInt32 iDefault;

    
    dvpReserved reserved;
} dvpIntDescr;



typedef struct dvpFloatDescr
{
    
    float fStep;

    
    float fMin;

    
    float fMax;

    
    float fDefault;

    
    dvpReserved reserved;
} dvpFloatDescr;



typedef struct dvpDoubleDescr
{
    
    double fStep;

    
    double fMin;

    
    double fMax;

    
    double fDefault;

    
    dvpReserved reserved;
} dvpDoubleDescr;



typedef struct dvpUint64Descr
{
    
    dvpUint64 uStep;

    
    dvpUint64 uMin;

    
    dvpUint64 uMax;

    
    dvpUint64 uDefault;

    
    dvpReserved reserved;
} dvpUint64Descr;



typedef struct dvpSelectionDescr
{
    
    dvpUint32 uDefault;

    
    dvpUint32 uCount;

    
    bool bNeedStop;

    
    dvpReserved reserved;
} dvpSelectionDescr;



typedef struct dvpSelection
{
    
    dvpString64 string;

    
    dvpInt32 iIndex;

    
    dvpReserved reserved;
} dvpSelection;



typedef struct dvpResolutionMode
{
    
    struct dvpSelection selection;

    
    struct dvpRegionDescr region;

    
    dvpReserved reserved;
} dvpResolutionMode;



typedef struct dvpQuickRoi
{
    
    struct dvpSelection selection;

    
    struct dvpRegion roi;

    
    struct dvpResolutionMode mode;

    
    dvpReserved reserved;
} dvpQuickRoi;



typedef struct dvpFormatSelection
{
    
    struct dvpSelection selection;

    
    enum dvpStreamFormat format;

    
    dvpReserved reserved;
} dvpFormatSelection;



typedef struct dvpFrameCount
{
    
    dvpUint32 uFrameCount;

    
    dvpUint32 uFrameDrop;

    
    dvpUint32 uFrameIgnore;

    
    dvpUint32 uFrameError;

    
    dvpUint32 uFrameOK;

    
    dvpUint32 uFrameOut;

    
    dvpUint32 uFrameResend;

    
    dvpUint32 uFrameProc;

    
    float fFrameRate;

    
    float fProcRate;

    
    dvpReserved reserved;
} dvpFrameCount;



typedef struct dvpUserIoInfo
{
    
    dvpBool32 inputValid;

    
    dvpBool32 outputValid;

    
    dvpReserved reserved;
} dvpUserIoInfo;



typedef struct dvpLineInfo
{
    
    dvpBool32 valid;

    
    dvpBool32 bidir;

    
    dvpBool32 inverter;

    
    dvpBool32 user;

    
    dvpBool32 strobe;

    
    dvpBool32 pwm;

    
    dvpBool32 timer;

    
    dvpBool32 uart;

    
    dvpReserved reserved;
} dvpLineInfo;



typedef struct dvpAeConfig
{
    
    double fExposureMin;

    
    double fExposureMax;

    
    double reserved1;

    
    float fGainMin;

    
    float fGainMax;

    
    float reserved2;

    
    dvpReserved reserved;
} dvpAeConfig;



typedef struct dvpSensorInfo
{
    
    dvpString64 descr;

    
    enum dvpSensorType sensor;

    
    enum dvpSensorPixel pixel;

    
    struct dvpRegionDescr region;

    
    dvpReserved reserved;
} dvpSensorInfo;



typedef struct dvpFunctionInfo
{
    
    bool bTrigger;

    
    bool bHardwareIsp;

    
    bool bUserSet;

    
    bool bHflip;

    
    bool bVflip;

    
    bool bInverse;

    
    bool bLine;

    
    bool bCooler;

    
    bool bTemperature;

    
    bool bReserved3;

    
    dvpUint32 reserved[30];
} dvpFunctionInfo;



typedef struct dvpTemperatureInfo
{
    
    float fDevice;

    
    float fSensor;

    
    float fChip1;

    
    float fChip2;

    
    dvpReserved reserved;
} dvpTemperatureInfo;



typedef struct dvpBufferConfig
{
    
    enum dvpBufferMode mode;

    
    dvpUint32 uQueueSize;

    
    bool bDropNew;

    
    bool bLite;

    
    dvpReserved reserved;
} dvpBufferConfig;





dvp2api dvpStatus dvpGetCameraInfo(dvpHandle handle, dvpCameraInfo *pCameraInfo);



dvp2api dvpStatus dvpGetSensorInfo(dvpHandle handle, dvpSensorInfo *pSensorInfo);



dvp2api dvpStatus dvpGetFrameCount(dvpHandle handle, dvpFrameCount *pFrameCount);



dvp2api dvpStatus dvpGetUserIoInfo(dvpHandle handle, dvpUserIoInfo *pUserIoInfo);



dvp2api dvpStatus dvpGetLineInfo(dvpHandle handle, dvpLineInfo *pLineInfo);



dvp2api dvpStatus dvpGetFirstPosition(dvpHandle handle, dvpFirstPosition *pFirstPosition);



dvp2api dvpStatus dvpGetFunctionInfo(dvpHandle handle, dvpFunctionInfo *pFunctionInfo);



dvp2api dvpStatus dvpGetDeviceType(dvpHandle handle, dvpDeviceType *pDeviceType);



dvp2api dvpStatus dvpGetTemperatureInfo(dvpHandle handle, dvpTemperatureInfo *pTemperatureInfo);



dvp2api dvpStatus dvpTriggerFire(dvpHandle handle);



dvp2api dvpStatus dvpCreateDefectFixInfo(dvpHandle handle);



dvp2api dvpStatus dvpCreateFlatFieldInfo(dvpHandle handle);



dvp2api dvpStatus dvpResetDevice(dvpHandle handle);



dvp2api dvpStatus dvpRestart(dvpHandle handle);



dvp2api dvpStatus dvpHold(dvpHandle handle);



dvp2api dvpStatus dvpGetGamma(dvpHandle handle, dvpInt32 *pGamma);



dvp2api dvpStatus dvpSetGamma(dvpHandle handle, dvpInt32 Gamma);



dvp2api dvpStatus dvpGetGammaDescr(dvpHandle handle, dvpIntDescr *pGammaDescr);



dvp2api dvpStatus dvpGetGammaState(dvpHandle handle, bool *pGammaState);



dvp2api dvpStatus dvpSetGammaState(dvpHandle handle, bool GammaState);



dvp2api dvpStatus dvpGetContrast(dvpHandle handle, dvpInt32 *pContrast);



dvp2api dvpStatus dvpSetContrast(dvpHandle handle, dvpInt32 Contrast);



dvp2api dvpStatus dvpGetContrastDescr(dvpHandle handle, dvpIntDescr *pContrastDescr);



dvp2api dvpStatus dvpGetContrastState(dvpHandle handle, bool *pContrastState);



dvp2api dvpStatus dvpSetContrastState(dvpHandle handle, bool ContrastState);



dvp2api dvpStatus dvpGetRoi(dvpHandle handle, dvpRegion *pRoi);



dvp2api dvpStatus dvpSetRoi(dvpHandle handle, dvpRegion Roi);



dvp2api dvpStatus dvpGetRoiDescr(dvpHandle handle, dvpRegionDescr *pRoiDescr);



dvp2api dvpStatus dvpGetRoiState(dvpHandle handle, bool *pRoiState);



dvp2api dvpStatus dvpSetRoiState(dvpHandle handle, bool RoiState);



dvp2api dvpStatus dvpGetColorTemperature(dvpHandle handle, dvpInt32 *pColorTemperature);



dvp2api dvpStatus dvpSetColorTemperature(dvpHandle handle, dvpInt32 ColorTemperature);



dvp2api dvpStatus dvpGetColorTemperatureDescr(dvpHandle handle, dvpIntDescr *pColorTemperatureDescr);



dvp2api dvpStatus dvpGetColorTemperatureState(dvpHandle handle, bool *pColorTemperatureState);



dvp2api dvpStatus dvpSetColorTemperatureState(dvpHandle handle, bool ColorTemperatureState);



dvp2api dvpStatus dvpGetSharpness(dvpHandle handle, dvpInt32 *pSharpness);



dvp2api dvpStatus dvpSetSharpness(dvpHandle handle, dvpInt32 Sharpness);



dvp2api dvpStatus dvpGetSharpnessDescr(dvpHandle handle, dvpIntDescr *pSharpnessDescr);



dvp2api dvpStatus dvpGetSharpnessState(dvpHandle handle, bool *pSharpnessState);



dvp2api dvpStatus dvpSetSharpnessState(dvpHandle handle, bool SharpnessState);



dvp2api dvpStatus dvpGetSaturation(dvpHandle handle, dvpInt32 *pSaturation);



dvp2api dvpStatus dvpSetSaturation(dvpHandle handle, dvpInt32 Saturation);



dvp2api dvpStatus dvpGetSaturationDescr(dvpHandle handle, dvpIntDescr *pSaturationDescr);



dvp2api dvpStatus dvpGetSaturationState(dvpHandle handle, bool *pSaturationState);



dvp2api dvpStatus dvpSetSaturationState(dvpHandle handle, bool SaturationState);



dvp2api dvpStatus dvpGetNoiseReduct2d(dvpHandle handle, dvpInt32 *pNoiseReduct2d);



dvp2api dvpStatus dvpSetNoiseReduct2d(dvpHandle handle, dvpInt32 NoiseReduct2d);



dvp2api dvpStatus dvpGetNoiseReduct2dDescr(dvpHandle handle, dvpIntDescr *pNoiseReduct2dDescr);



dvp2api dvpStatus dvpGetNoiseReduct2dState(dvpHandle handle, bool *pNoiseReduct2dState);



dvp2api dvpStatus dvpSetNoiseReduct2dState(dvpHandle handle, bool NoiseReduct2dState);



dvp2api dvpStatus dvpGetNoiseReduct3d(dvpHandle handle, dvpInt32 *pNoiseReduct3d);



dvp2api dvpStatus dvpSetNoiseReduct3d(dvpHandle handle, dvpInt32 NoiseReduct3d);



dvp2api dvpStatus dvpGetNoiseReduct3dDescr(dvpHandle handle, dvpIntDescr *pNoiseReduct3dDescr);



dvp2api dvpStatus dvpGetNoiseReduct3dState(dvpHandle handle, bool *pNoiseReduct3dState);



dvp2api dvpStatus dvpSetNoiseReduct3dState(dvpHandle handle, bool NoiseReduct3dState);



dvp2api dvpStatus dvpGetBlackLevel(dvpHandle handle, float *pBlackLevel);



dvp2api dvpStatus dvpSetBlackLevel(dvpHandle handle, float BlackLevel);



dvp2api dvpStatus dvpGetBlackLevelDescr(dvpHandle handle, dvpFloatDescr *pBlackLevelDescr);



dvp2api dvpStatus dvpGetBlackLevelState(dvpHandle handle, bool *pBlackLevelState);



dvp2api dvpStatus dvpSetBlackLevelState(dvpHandle handle, bool BlackLevelState);



dvp2api dvpStatus dvpGetSoftTriggerLoop(dvpHandle handle, double *pSoftTriggerLoop);



dvp2api dvpStatus dvpSetSoftTriggerLoop(dvpHandle handle, double SoftTriggerLoop);



dvp2api dvpStatus dvpGetSoftTriggerLoopDescr(dvpHandle handle, dvpDoubleDescr *pSoftTriggerLoopDescr);



dvp2api dvpStatus dvpGetSoftTriggerLoopState(dvpHandle handle, bool *pSoftTriggerLoopState);



dvp2api dvpStatus dvpSetSoftTriggerLoopState(dvpHandle handle, bool SoftTriggerLoopState);



dvp2api dvpStatus dvpGetMultiFrames(dvpHandle handle, dvpUint64 *pMultiFrames);



dvp2api dvpStatus dvpSetMultiFrames(dvpHandle handle, dvpUint64 MultiFrames);



dvp2api dvpStatus dvpGetMultiFramesDescr(dvpHandle handle, dvpUint64Descr *pMultiFramesDescr);



dvp2api dvpStatus dvpGetMultiFramesState(dvpHandle handle, bool *pMultiFramesState);



dvp2api dvpStatus dvpSetMultiFramesState(dvpHandle handle, bool MultiFramesState);



dvp2api dvpStatus dvpGetStreamPackInterval(dvpHandle handle, dvpInt32 *pStreamPackInterval);



dvp2api dvpStatus dvpSetStreamPackInterval(dvpHandle handle, dvpInt32 StreamPackInterval);



dvp2api dvpStatus dvpGetStreamPackIntervalDescr(dvpHandle handle, dvpIntDescr *pStreamPackIntervalDescr);



dvp2api dvpStatus dvpGetStreamPackSize(dvpHandle handle, dvpInt32 *pStreamPackSize);



dvp2api dvpStatus dvpSetStreamPackSize(dvpHandle handle, dvpInt32 StreamPackSize);



dvp2api dvpStatus dvpGetStreamPackSizeDescr(dvpHandle handle, dvpIntDescr *pStreamPackSizeDescr);



dvp2api dvpStatus dvpGetAeTarget(dvpHandle handle, dvpInt32 *pAeTarget);



dvp2api dvpStatus dvpSetAeTarget(dvpHandle handle, dvpInt32 AeTarget);



dvp2api dvpStatus dvpGetAeTargetDescr(dvpHandle handle, dvpIntDescr *pAeTargetDescr);



dvp2api dvpStatus dvpGetAnalogGain(dvpHandle handle, float *pAnalogGain);



dvp2api dvpStatus dvpSetAnalogGain(dvpHandle handle, float AnalogGain);



dvp2api dvpStatus dvpGetAnalogGainDescr(dvpHandle handle, dvpFloatDescr *pAnalogGainDescr);



dvp2api dvpStatus dvpGetExposure(dvpHandle handle, double *pExposure);



dvp2api dvpStatus dvpSetExposure(dvpHandle handle, double Exposure);



dvp2api dvpStatus dvpGetExposureDescr(dvpHandle handle, dvpDoubleDescr *pExposureDescr);



dvp2api dvpStatus dvpGetTriggerJitterFilter(dvpHandle handle, double *pTriggerJitterFilter);



dvp2api dvpStatus dvpSetTriggerJitterFilter(dvpHandle handle, double TriggerJitterFilter);



dvp2api dvpStatus dvpGetTriggerJitterFilterDescr(dvpHandle handle, dvpDoubleDescr *pTriggerJitterFilterDescr);



dvp2api dvpStatus dvpGetTriggerDelay(dvpHandle handle, double *pTriggerDelay);



dvp2api dvpStatus dvpSetTriggerDelay(dvpHandle handle, double TriggerDelay);



dvp2api dvpStatus dvpGetTriggerDelayDescr(dvpHandle handle, dvpDoubleDescr *pTriggerDelayDescr);



dvp2api dvpStatus dvpGetStrobeDelay(dvpHandle handle, double *pStrobeDelay);



dvp2api dvpStatus dvpSetStrobeDelay(dvpHandle handle, double StrobeDelay);



dvp2api dvpStatus dvpGetStrobeDelayDescr(dvpHandle handle, dvpDoubleDescr *pStrobeDelayDescr);



dvp2api dvpStatus dvpGetStrobeDuration(dvpHandle handle, double *pStrobeDuration);



dvp2api dvpStatus dvpSetStrobeDuration(dvpHandle handle, double StrobeDuration);



dvp2api dvpStatus dvpGetStrobeDurationDescr(dvpHandle handle, dvpDoubleDescr *pStrobeDurationDescr);



dvp2api dvpStatus dvpGetFramesPerTrigger(dvpHandle handle, dvpInt32 *pFramesPerTrigger);



dvp2api dvpStatus dvpSetFramesPerTrigger(dvpHandle handle, dvpInt32 FramesPerTrigger);



dvp2api dvpStatus dvpGetFramesPerTriggerDescr(dvpHandle handle, dvpIntDescr *pFramesPerTriggerDescr);



dvp2api dvpStatus dvpGetTimerValue(dvpHandle handle, double *pTimerValue);



dvp2api dvpStatus dvpSetTimerValue(dvpHandle handle, double TimerValue);



dvp2api dvpStatus dvpGetTimerValueDescr(dvpHandle handle, dvpDoubleDescr *pTimerValueDescr);



dvp2api dvpStatus dvpGetBufferQueueSize(dvpHandle handle, dvpInt32 *pBufferQueueSize);



dvp2api dvpStatus dvpSetBufferQueueSize(dvpHandle handle, dvpInt32 BufferQueueSize);



dvp2api dvpStatus dvpGetBufferQueueSizeDescr(dvpHandle handle, dvpIntDescr *pBufferQueueSizeDescr);



dvp2api dvpStatus dvpGetTriggerSource(dvpHandle handle, dvpTriggerSource *pTriggerSource);



dvp2api dvpStatus dvpSetTriggerSource(dvpHandle handle, dvpTriggerSource TriggerSource);



dvp2api dvpStatus dvpGetCurveLut(dvpHandle handle, dvpCurveLut *pCurveLut);



dvp2api dvpStatus dvpSetCurveLut(dvpHandle handle, dvpCurveLut CurveLut);



dvp2api dvpStatus dvpGetColorCorrection(dvpHandle handle, dvpColorCorrection *pColorCorrection);



dvp2api dvpStatus dvpSetColorCorrection(dvpHandle handle, dvpColorCorrection ColorCorrection);



dvp2api dvpStatus dvpGetStreamState(dvpHandle handle, dvpStreamState *pStreamState);



dvp2api dvpStatus dvpSetStreamState(dvpHandle handle, dvpStreamState StreamState);



dvp2api dvpStatus dvpGetHardwareIspState(dvpHandle handle, bool *pHardwareIspState);



dvp2api dvpStatus dvpSetHardwareIspState(dvpHandle handle, bool HardwareIspState);



dvp2api dvpStatus dvpGetTriggerState(dvpHandle handle, bool *pTriggerState);



dvp2api dvpStatus dvpSetTriggerState(dvpHandle handle, bool TriggerState);



dvp2api dvpStatus dvpGetMonoState(dvpHandle handle, bool *pMonoState);



dvp2api dvpStatus dvpSetMonoState(dvpHandle handle, bool MonoState);



dvp2api dvpStatus dvpGetInverseState(dvpHandle handle, bool *pInverseState);



dvp2api dvpStatus dvpSetInverseState(dvpHandle handle, bool InverseState);



dvp2api dvpStatus dvpGetFlipHorizontalState(dvpHandle handle, bool *pFlipHorizontalState);



dvp2api dvpStatus dvpSetFlipHorizontalState(dvpHandle handle, bool FlipHorizontalState);



dvp2api dvpStatus dvpGetFlipVerticalState(dvpHandle handle, bool *pFlipVerticalState);



dvp2api dvpStatus dvpSetFlipVerticalState(dvpHandle handle, bool FlipVerticalState);



dvp2api dvpStatus dvpGetFlatFieldState(dvpHandle handle, bool *pFlatFieldState);



dvp2api dvpStatus dvpSetFlatFieldState(dvpHandle handle, bool FlatFieldState);



dvp2api dvpStatus dvpGetDefectFixState(dvpHandle handle, bool *pDefectFixState);



dvp2api dvpStatus dvpSetDefectFixState(dvpHandle handle, bool DefectFixState);



dvp2api dvpStatus dvpGetAutoDefectFixState(dvpHandle handle, bool *pAutoDefectFixState);



dvp2api dvpStatus dvpSetAutoDefectFixState(dvpHandle handle, bool AutoDefectFixState);



dvp2api dvpStatus dvpGetRotateState(dvpHandle handle, bool *pRotateState);



dvp2api dvpStatus dvpSetRotateState(dvpHandle handle, bool RotateState);



dvp2api dvpStatus dvpGetRotateOpposite(dvpHandle handle, bool *pRotateOpposite);



dvp2api dvpStatus dvpSetRotateOpposite(dvpHandle handle, bool RotateOpposite);



dvp2api dvpStatus dvpGetCoolerState(dvpHandle handle, bool *pCoolerState);



dvp2api dvpStatus dvpSetCoolerState(dvpHandle handle, bool CoolerState);



dvp2api dvpStatus dvpGetAeRoi(dvpHandle handle, dvpRegion *pAeRoi);



dvp2api dvpStatus dvpSetAeRoi(dvpHandle handle, dvpRegion AeRoi);



dvp2api dvpStatus dvpGetAwbRoi(dvpHandle handle, dvpRegion *pAwbRoi);



dvp2api dvpStatus dvpSetAwbRoi(dvpHandle handle, dvpRegion AwbRoi);



dvp2api dvpStatus dvpGetAeMode(dvpHandle handle, dvpAeMode *pAeMode);



dvp2api dvpStatus dvpSetAeMode(dvpHandle handle, dvpAeMode AeMode);



dvp2api dvpStatus dvpGetAntiFlick(dvpHandle handle, dvpAntiFlick *pAntiFlick);



dvp2api dvpStatus dvpSetAntiFlick(dvpHandle handle, dvpAntiFlick AntiFlick);



dvp2api dvpStatus dvpGetAeOperation(dvpHandle handle, dvpAeOperation *pAeOperation);



dvp2api dvpStatus dvpSetAeOperation(dvpHandle handle, dvpAeOperation AeOperation);



dvp2api dvpStatus dvpGetAwbOperation(dvpHandle handle, dvpAwbOperation *pAwbOperation);



dvp2api dvpStatus dvpSetAwbOperation(dvpHandle handle, dvpAwbOperation AwbOperation);



dvp2api dvpStatus dvpGetStrobeDriver(dvpHandle handle, dvpStrobeDriver *pStrobeDriver);



dvp2api dvpStatus dvpSetStrobeDriver(dvpHandle handle, dvpStrobeDriver StrobeDriver);



dvp2api dvpStatus dvpGetStrobeOutputType(dvpHandle handle, dvpStrobeOutputType *pStrobeOutputType);



dvp2api dvpStatus dvpSetStrobeOutputType(dvpHandle handle, dvpStrobeOutputType StrobeOutputType);



dvp2api dvpStatus dvpGetTriggerInputType(dvpHandle handle, dvpTriggerInputType *pTriggerInputType);



dvp2api dvpStatus dvpSetTriggerInputType(dvpHandle handle, dvpTriggerInputType TriggerInputType);



dvp2api dvpStatus dvpGetSourceFormat(dvpHandle handle, dvpStreamFormat *pSourceFormat);



dvp2api dvpStatus dvpSetSourceFormat(dvpHandle handle, dvpStreamFormat SourceFormat);



dvp2api dvpStatus dvpGetTargetFormat(dvpHandle handle, dvpStreamFormat *pTargetFormat);



dvp2api dvpStatus dvpSetTargetFormat(dvpHandle handle, dvpStreamFormat TargetFormat);



dvp2api dvpStatus dvpGetUserColorMatrix(dvpHandle handle, dvpColorMatrix *pUserColorMatrix);



dvp2api dvpStatus dvpSetUserColorMatrix(dvpHandle handle, dvpColorMatrix UserColorMatrix);



dvp2api dvpStatus dvpGetLinkTimeout(dvpHandle handle, dvpUint32 *pLinkTimeout);



dvp2api dvpStatus dvpSetLinkTimeout(dvpHandle handle, dvpUint32 LinkTimeout);



dvp2api dvpStatus dvpGetAeConfig(dvpHandle handle, dvpAeConfig *pAeConfig);



dvp2api dvpStatus dvpSetAeConfig(dvpHandle handle, dvpAeConfig AeConfig);



dvp2api dvpStatus dvpGetBufferConfig(dvpHandle handle, dvpBufferConfig *pBufferConfig);



dvp2api dvpStatus dvpSetBufferConfig(dvpHandle handle, dvpBufferConfig BufferConfig);



dvp2api dvpStatus dvpGetUserSet(dvpHandle handle, dvpUserSet *pUserSet);



dvp2api dvpStatus dvpSetUserSet(dvpHandle handle, dvpUserSet UserSet);



dvp2api dvpStatus dvpGetInputIoLevel(dvpHandle handle, dvpInputIo inputIo, bool *pInputIoLevel);



dvp2api dvpStatus dvpGetLineLevel(dvpHandle handle, dvpLine line, bool *pLineLevel);



dvp2api dvpStatus dvpSetLineLevel(dvpHandle handle, dvpLine line, bool LineLevel);



dvp2api dvpStatus dvpGetLineInverter(dvpHandle handle, dvpLine line, bool *pLineInverter);



dvp2api dvpStatus dvpSetLineInverter(dvpHandle handle, dvpLine line, bool LineInverter);



dvp2api dvpStatus dvpGetLineMode(dvpHandle handle, dvpLine line, dvpLineMode *pLineMode);



dvp2api dvpStatus dvpSetLineMode(dvpHandle handle, dvpLine line, dvpLineMode LineMode);



dvp2api dvpStatus dvpGetLineSource(dvpHandle handle, dvpLine line, dvpLineSource *pLineSource);



dvp2api dvpStatus dvpSetLineSource(dvpHandle handle, dvpLine line, dvpLineSource LineSource);



dvp2api dvpStatus dvpGetLineStatus(dvpHandle handle, dvpLine line, bool *pLineStatus);



dvp2api dvpStatus dvpGetOutputIoLevel(dvpHandle handle, dvpOutputIo outputIo, bool *pOutputIoLevel);



dvp2api dvpStatus dvpSetOutputIoLevel(dvpHandle handle, dvpOutputIo outputIo, bool OutputIoLevel);



dvp2api dvpStatus dvpGetOutputIoFunction(dvpHandle handle, dvpOutputIo outputIo, dvpOutputIoFunction *pOutputIoFunction);



dvp2api dvpStatus dvpSetOutputIoFunction(dvpHandle handle, dvpOutputIo outputIo, dvpOutputIoFunction OutputIoFunction);



dvp2api dvpStatus dvpGetInputIoFunction(dvpHandle handle, dvpInputIo inputIo, dvpInputIoFunction *pInputIoFunction);



dvp2api dvpStatus dvpSetInputIoFunction(dvpHandle handle, dvpInputIo inputIo, dvpInputIoFunction InputIoFunction);



dvp2api dvpStatus dvpGetStreamFlowCtrlSel(dvpHandle handle, dvpUint32 *pStreamFlowCtrlSel);



dvp2api dvpStatus dvpSetStreamFlowCtrlSel(dvpHandle handle, dvpUint32 StreamFlowCtrlSel);



dvp2api dvpStatus dvpGetStreamFlowCtrlSelDescr(dvpHandle handle, dvpSelectionDescr *pStreamFlowCtrlSelDescr);



dvp2api dvpStatus dvpGetStreamFlowCtrlSelDetail(dvpHandle handle, dvpUint32 StreamFlowCtrlSel, dvpSelection *pStreamFlowCtrlSelDetail);



dvp2api dvpStatus dvpGetColorSolutionSel(dvpHandle handle, dvpUint32 *pColorSolutionSel);



dvp2api dvpStatus dvpSetColorSolutionSel(dvpHandle handle, dvpUint32 ColorSolutionSel);



dvp2api dvpStatus dvpGetColorSolutionSelDescr(dvpHandle handle, dvpSelectionDescr *pColorSolutionSelDescr);



dvp2api dvpStatus dvpGetColorSolutionSelDetail(dvpHandle handle, dvpUint32 ColorSolutionSel, dvpSelection *pColorSolutionSelDetail);



dvp2api dvpStatus dvpGetBayerDecodeSel(dvpHandle handle, dvpUint32 *pBayerDecodeSel);



dvp2api dvpStatus dvpSetBayerDecodeSel(dvpHandle handle, dvpUint32 BayerDecodeSel);



dvp2api dvpStatus dvpGetBayerDecodeSelDescr(dvpHandle handle, dvpSelectionDescr *pBayerDecodeSelDescr);



dvp2api dvpStatus dvpGetBayerDecodeSelDetail(dvpHandle handle, dvpUint32 BayerDecodeSel, dvpSelection *pBayerDecodeSelDetail);



dvp2api dvpStatus dvpGetSourceFormatSel(dvpHandle handle, dvpUint32 *pSourceFormatSel);



dvp2api dvpStatus dvpSetSourceFormatSel(dvpHandle handle, dvpUint32 SourceFormatSel);



dvp2api dvpStatus dvpGetSourceFormatSelDescr(dvpHandle handle, dvpSelectionDescr *pSourceFormatSelDescr);



dvp2api dvpStatus dvpGetSourceFormatSelDetail(dvpHandle handle, dvpUint32 SourceFormatSel, dvpFormatSelection *pSourceFormatSelDetail);



dvp2api dvpStatus dvpGetTargetFormatSel(dvpHandle handle, dvpUint32 *pTargetFormatSel);



dvp2api dvpStatus dvpSetTargetFormatSel(dvpHandle handle, dvpUint32 TargetFormatSel);



dvp2api dvpStatus dvpGetTargetFormatSelDescr(dvpHandle handle, dvpSelectionDescr *pTargetFormatSelDescr);



dvp2api dvpStatus dvpGetTargetFormatSelDetail(dvpHandle handle, dvpUint32 TargetFormatSel, dvpFormatSelection *pTargetFormatSelDetail);



dvp2api dvpStatus dvpGetResolutionModeSel(dvpHandle handle, dvpUint32 *pResolutionModeSel);



dvp2api dvpStatus dvpSetResolutionModeSel(dvpHandle handle, dvpUint32 ResolutionModeSel);



dvp2api dvpStatus dvpGetResolutionModeSelDescr(dvpHandle handle, dvpSelectionDescr *pResolutionModeSelDescr);



dvp2api dvpStatus dvpGetResolutionModeSelDetail(dvpHandle handle, dvpUint32 ResolutionModeSel, dvpResolutionMode *pResolutionModeSelDetail);



dvp2api dvpStatus dvpGetAeSchemeSel(dvpHandle handle, dvpUint32 *pAeSchemeSel);



dvp2api dvpStatus dvpSetAeSchemeSel(dvpHandle handle, dvpUint32 AeSchemeSel);



dvp2api dvpStatus dvpGetAeSchemeSelDescr(dvpHandle handle, dvpSelectionDescr *pAeSchemeSelDescr);



dvp2api dvpStatus dvpGetAeSchemeSelDetail(dvpHandle handle, dvpUint32 AeSchemeSel, dvpSelection *pAeSchemeSelDetail);



dvp2api dvpStatus dvpGetQuickRoiSel(dvpHandle handle, dvpUint32 *pQuickRoiSel);



dvp2api dvpStatus dvpSetQuickRoiSel(dvpHandle handle, dvpUint32 QuickRoiSel);



dvp2api dvpStatus dvpGetQuickRoiSelDescr(dvpHandle handle, dvpSelectionDescr *pQuickRoiSelDescr);



dvp2api dvpStatus dvpGetQuickRoiSelDetail(dvpHandle handle, dvpUint32 QuickRoiSel, dvpQuickRoi *pQuickRoiSelDetail);



dvp2api dvpStatus dvpGetPixelRateSel(dvpHandle handle, dvpUint32 *pPixelRateSel);



dvp2api dvpStatus dvpSetPixelRateSel(dvpHandle handle, dvpUint32 PixelRateSel);



dvp2api dvpStatus dvpGetPixelRateSelDescr(dvpHandle handle, dvpSelectionDescr *pPixelRateSelDescr);



dvp2api dvpStatus dvpGetPixelRateSelDetail(dvpHandle handle, dvpUint32 PixelRateSel, dvpSelection *pPixelRateSelDetail);



dvp2api dvpStatus dvpGetPacketSizeSel(dvpHandle handle, dvpUint32 *pPacketSizeSel);



dvp2api dvpStatus dvpSetPacketSizeSel(dvpHandle handle, dvpUint32 PacketSizeSel);



dvp2api dvpStatus dvpGetPacketSizeSelDescr(dvpHandle handle, dvpSelectionDescr *pPacketSizeSelDescr);



dvp2api dvpStatus dvpGetPacketSizeSelDetail(dvpHandle handle, dvpUint32 PacketSizeSel, dvpSelection *pPacketSizeSelDetail);



dvp2api dvpStatus dvpGetAccelerateSel(dvpHandle handle, dvpUint32 *pAccelerateSel);



dvp2api dvpStatus dvpSetAccelerateSel(dvpHandle handle, dvpUint32 AccelerateSel);



dvp2api dvpStatus dvpGetAccelerateSelDescr(dvpHandle handle, dvpSelectionDescr *pAccelerateSelDescr);



dvp2api dvpStatus dvpGetAccelerateSelDetail(dvpHandle handle, dvpUint32 AccelerateSel, dvpSelection *pAccelerateSelDetail);



dvp2api dvpStatus dvpSetRgbGain(dvpHandle handle, float rGain, float gGain, float bGain);



dvp2api dvpStatus dvpGetRgbGain(dvpHandle handle, float *prGain, float *pgGain, float *pbGain);



dvp2api dvpStatus dvpSetRgbGainState(dvpHandle handle, bool state);



dvp2api dvpStatus dvpGetRgbGainState(dvpHandle handle, bool *pState);





dvp2api dvpStatus dvpRefresh(dvpUint32 *pCount);



dvp2api dvpStatus dvpEnum(dvpUint32 index, dvpCameraInfo *pCameraInfo);



dvp2api dvpStatus dvpOpenByName(dvpStr friendlyName, dvpOpenMode mode, dvpHandle *pHandle);



dvp2api dvpStatus dvpOpenByUserId(dvpStr UserId, dvpOpenMode mode, dvpHandle *pHandle);



dvp2api dvpStatus dvpOpen(dvpUint32 index, dvpOpenMode mode, dvpHandle *pHandle);



dvp2api dvpStatus dvpIsValid(dvpHandle handle, bool *pIsValid);



dvp2api dvpStatus dvpIsOnline(dvpHandle handle, bool *pIsOnline);



dvp2api dvpStatus dvpStart(dvpHandle handle);



dvp2api dvpStatus dvpStop(dvpHandle handle);



dvp2api dvpStatus dvpIsHold(dvpHandle handle, bool *pIsHold);



dvp2api dvpStatus dvpGetFrame(dvpHandle handle, dvpFrame *pFrame, void **pBuffer, dvpUint32 timeout);



dvp2api dvpStatus dvpGetFrameBuffer(dvpHandle handle, dvpFrameBuffer *pRaw, dvpFrameBuffer *pOut, dvpUint32 timeout);



dvp2api dvpStatus dvpProcessImage(dvpHandle handle, const dvpFrame *pSourceFrame, const void *pSourceBuffer, dvpFrame *pTargetFrame, void *pTargetBuffer, dvpUint32 targetBufferSize, dvpStreamFormat targetFormat);



dvp2api dvpStatus dvpDebugReport(dvpHandle handle, dvpReportPart part, dvpReportLevel level, bool bForce, dvpStr text, dvpUint32 param);



dvp2api dvpStatus dvpClose(dvpHandle handle);





typedef dvpInt32(*dvpStreamCallback)(dvpHandle handle, dvpStreamEvent event, void *pContext, dvpFrame *pFrame, void *pBuffer);


dvp2api dvpStatus dvpRegisterStreamCallback(dvpHandle handle, dvpStreamCallback proc, dvpStreamEvent event, void *pContext);



dvp2api dvpStatus dvpUnregisterStreamCallback(dvpHandle handle, dvpStreamCallback proc, dvpStreamEvent event, void *pContext);



typedef dvpInt32(*dvpEventCallback)(dvpHandle handle, dvpEvent event, void *pContext, dvpInt32 param, struct dvpVariant *pVariant);


dvp2api dvpStatus dvpRegisterEventCallback(dvpHandle handle, dvpEventCallback proc, dvpEvent event, void *pContext);



dvp2api dvpStatus dvpUnregisterEventCallback(dvpHandle handle, dvpEventCallback proc, dvpEvent event, void *pContext);






dvp2api dvpStatus dvpLoadDefault(dvpHandle handle);



dvp2api dvpStatus dvpLoadConfig(dvpHandle handle, dvpStr path);



dvp2api dvpStatus dvpSaveConfig(dvpHandle handle, dvpStr path);



dvp2api dvpStatus dvpSaveUserSet(dvpHandle handle, dvpUserSet UserSet);



dvp2api dvpStatus dvpLoadUserSet(dvpHandle handle, dvpUserSet UserSet);







dvp2api dvpStatus dvpSavePicture(const dvpFrame *pFrame, const void *pBuffer, dvpStr file, dvpInt32 quality);



dvp2api dvpStatus dvpCaptureFile(dvpHandle handle, dvpUint32 ResoulutionModeSel, dvpRegion *roi, dvpUint32 timeout, dvpStr filePath, dvpInt32 quality);


#ifdef _WIN32

dvp2api dvpStatus dvpDrawPicture(const dvpFrame *pFrame, const void *pBuffer, HWND hWnd, LPRECT sRect, LPRECT dRect);



dvp2api dvpStatus dvpStartVideoRecord(dvpStr filePath, dvpUint32 width, dvpUint32 height, dvpInt32 quality, dvpRecordHandle *pHandle);



dvp2api dvpStatus dvpIsVideoRecorderValid(dvpRecordHandle handle, bool *pValid);



dvp2api dvpStatus dvpVideoRecordWrite(dvpRecordHandle handle, const dvpFrame *pFrame, const void *pBuffer);



dvp2api dvpStatus dvpStopVideoRecord(dvpRecordHandle handle);



dvp2api dvpStatus dvpShowPropertyModalDialog(dvpHandle handle, HWND hParent);


#endif

dvp2api dvpStatus dvpReadUserData(dvpHandle handle, dvpUint32 addr, void *pBuffer, dvpUint32 size);



dvp2api dvpStatus dvpWriteUserData(dvpHandle handle, dvpUint32 addr, const void *pBuffer, dvpUint32 size);



dvp2api dvpStatus dvpSetUserId(dvpHandle handle, dvpStr UserId, dvpUint32 *pLength);






dvp2api dvpStatus dvpGet(dvpHandle handle, dvpUint32 command, void *pParam, dvpUint32 *pSize);



dvp2api dvpStatus dvpSet(dvpHandle handle, dvpUint32 command, const void *pParam, dvpUint32 *pSize);



dvp2api dvpStatus dvpConfig(dvpUint32 command, dvpUint32 param, const void* pData);

#endif /* __DVPCAMERA_H__ */


