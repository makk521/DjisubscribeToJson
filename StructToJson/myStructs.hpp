#include <iostream>
#pragma once

typedef unsigned char   uint8_t;
typedef unsigned short  uint16_t;
typedef short  int16_t;
typedef unsigned   uint32_t;
typedef float  float32_t;
typedef float  float32_t;
typedef double float64_t;
typedef int  int32_t;

typedef struct Quaternion
{
  float32_t q0; /*!< w */
  float32_t q1; /*!< x */
  float32_t q2; /*!< y */
  float32_t q3; /*!< z */
} Quaternion;   // pack(1)
typedef struct Vector3f
{
  float32_t x;
  float32_t y;
  float32_t z;
} Vector3f; // pack(1)
typedef struct GPSFused
{
  float64_t longitude;              /*!< unit: rad */
  float64_t latitude;               /*!< unit: rad */
  float32_t altitude;               /*!< WGS 84 reference ellipsoid */
  uint16_t  visibleSatelliteNumber; /*!< number of visible satellite */
} GPSFused;                         // pack(1)
typedef struct Vector3d
{
  int32_t x;
  int32_t y;
  int32_t z;
} Vector3d; // pack(1)
typedef struct VelocityInfo
{
  uint8_t health : 1; /*!< 1 - using GPS, 0 - not using GPS */
  uint8_t reserve : 7;
} VelocityInfo; // pack(1)
typedef struct Velocity
{
  Vector3f data;
  VelocityInfo info;
} Velocity; // pack(1)
typedef struct GPSDetail
{
  float32_t hdop;       /*!< horizontal dilution of precision */
  float32_t pdop;       /*!< position dilution of precision */
  float32_t fix;        /*!< the state of GPS fix */
  float32_t gnssStatus; /*!< vertical position accuracy (mm) */
  float32_t hacc;       /*!< horizontal position accuracy (mm) */
  float32_t sacc;       /*!< the speed accuracy (cm/s) */
  uint32_t  usedGPS;    /*!< the number of GPS satellites used for pos fix */
  uint32_t  usedGLN; /*!< the number of GLONASS satellites used for pos fix */
  uint16_t  NSV;     /*!< the total number of satellites used for pos fix */
  uint16_t  GPScounter; /*!< the accumulated times of sending GPS data  */
} GPSDetail;  
typedef struct PositionData
{
  float64_t longitude; /*!< deg */
  float64_t latitude;  /*!< deg */
  float32_t HFSL;      /*!< height above mean sea level (m) */
} PositionData;        // pack(1)
typedef struct Mag
{
  int16_t x;
  int16_t y;
  int16_t z;
} Mag; // pack(1)
typedef struct RC
{
  int16_t roll;     /*!< [-10000,10000] */
  int16_t pitch;    /*!< [-10000,10000] */
  int16_t yaw;      /*!< [-10000,10000] */
  int16_t throttle; /*!< [-10000,10000] */
  int16_t mode;     /*!< [-10000,10000] */
                    /*!< M100 [P: -8000, A: 0, F: 8000] */
  int16_t gear;     /*!< [-10000,10000] */
                    /*!< M100 [Up: -10000, Down: -4545] */
} RC;               // pack(1)

typedef struct GimbalStatus
{
  uint32_t mountStatus : 1; /*!< 1 - gimbal mounted, 0 - gimbal not mounted*/
  uint32_t isBusy : 1;
  uint32_t pitchLimited : 1;           /*!< 1 - axis reached limit, 0 - no */
  uint32_t rollLimited : 1;            /*!< 1 - axis reached limit, 0 - no */
  uint32_t yawLimited : 1;             /*!< 1 - axis reached limit, 0 - no */
  uint32_t calibrating : 1;            /*!< 1 - calibrating, 0 - no */
  uint32_t prevCalibrationgResult : 1; /*!< 1 - success, 0 - fail */
  uint32_t installedDirection : 1;     /*!< 1 - reversed for OSMO, 0 - normal */
  uint32_t disabled_mvo : 1;
  uint32_t gear_show_unable : 1;
  uint32_t gyroFalut : 1;       /*!< 1 - fault, 0 - normal */
  uint32_t escPitchStatus : 1;  /*!< 1 - Pitch data is normal, 0 - fault */
  uint32_t escRollStatus : 1;   /*!< 1 - Roll data is normal, 0 - fault */
  uint32_t escYawStatus : 1;    /*!< 1 - Yaw data is normal , 0 - fault */
  uint32_t droneDataRecv : 1;   /*!< 1 - normal , 0 - at fault */
  uint32_t initUnfinished : 1;  /*!< 1 - init complete, 0 - not complete */
  uint32_t FWUpdating : 1;      /*!< 1 - updating, 0 - not updating */
  uint32_t reserved2 : 15;
} GimbalStatus; // pack(1)
typedef struct Battery
{
  uint32_t capacity;
  int32_t  voltage;
  int32_t  current;
  uint8_t  percentage;
} Battery; // pack(1)
typedef struct SDKInfo
{
  uint8_t controlMode;      /*!< See CtlrMode in dji_status.hpp*/
  uint8_t deviceStatus : 3; /*!< For M300 and M210V2(firmware version V01.00.0690 and later):0->rc  1->app  4->serial; 
                                 Other: 0->rc  1->app  2->serial*/
  uint8_t flightStatus : 1; /*!< 1->opensd  0->close */
  uint8_t vrcStatus : 1;
  uint8_t reserved : 3;
} SDKInfo; // pack(1)
typedef struct SyncTimestamp
{
  uint32_t time2p5ms; /*!< clock time in multiples of 2.5ms. Sync timer runs at
                         400Hz, this field increments in integer steps */
  uint32_t time1ns;   /*!< nanosecond time offset from the 2.5ms pulse */
  uint32_t resetTime2p5ms; /*!< clock time in multiple of 2.5ms elapsed since the
                              hardware sync started */
  uint16_t index;   /*!< This is the tag field you filled out when using the
                       setSyncFreq API above; use it to identify the packets that
                       have sync data. This is useful when you call the
                       setSyncFreq API with freqInHz = 0, so you get a single
                       pulse that can be uniquely identified with a tag - allowing
                       you to create your own pulse train with uniquely
                       identifiable pulses. */
  uint8_t flag;     /*!< This is true when the packet corresponds to a hardware
                       pulse and false otherwise. This is useful because you can
                       request the software packet to be sent at a higher frequency
                       that the hardware line.*/
} SyncTimestamp;    // pack(1)
typedef struct HardSyncData
{
  SyncTimestamp ts; /*!< time stamp for the incoming data */
  Quaternion    q;  /*!< quaternion */
  Vector3f      a;  /*!< accelerometer reading unit: g */
  Vector3f      w;  /*!< gyro reading unit: rad/sec */
} HardSyncData;     // pack(1)

#define SDK_LB2_CHANNEL_NUM (sizeof(LB2RcFullRawData)/sizeof(int16_t))
#define SDK_SBUS_CHANNEL_NUM (16)
typedef struct LB2RcFullRawData
{
  int16_t roll;             /*!< left = 364, middle = 1024, right=1684 */
  int16_t pitch;            /*!< down = 364, middle = 1024, up=1684 */
  int16_t yaw;              /*!< left = 364, middle = 1024, right=1684 */
  int16_t throttle;         /*!< down = 364, middle = 1024, up=1684 */
  int16_t mode;             /*!< right(P) = 364, middle(A) = 1024, left(F)=1684 */
  int16_t gear;             /*!< up = 1684,  down = 1354 */
  int16_t camera;           /*!< press_down = 1684, release = 364 */
  int16_t video;            /*!< press_down = 1684, release = 364 */
  int16_t videoPause;       /*!< press_down = 1684, release = 364 */
  int16_t goHome;           /*!< Always 364 */
  int16_t leftWheel;        /*!< left = 364, middle = 1024, right=16844 */
  int16_t rightWheelButton; /*!< press_down = 1684, release = 364 */
  int16_t rcC1;             /*!< press_down = 1684, release = 364 */
  int16_t rcC2;             /*!< press_down = 1684, release = 364 */
  int16_t rcD1;             /*!< rcD1 - 8 is used by sbus */
  int16_t rcD2;
  int16_t rcD3;
  int16_t rcD4;
  int16_t rcD5;
  int16_t rcD6;
  int16_t rcD7;
  int16_t rcD8;
} LB2RcFullRawData;
typedef struct SBUSFullRawData
{
  int16_t data[SDK_SBUS_CHANNEL_NUM];
  int16_t reserved[SDK_LB2_CHANNEL_NUM - SDK_SBUS_CHANNEL_NUM];
} SBUSFullRawData;

typedef union
{
  LB2RcFullRawData lb2;
  SBUSFullRawData  sbus;
} RCFullRawData;
typedef struct RCWithFlagData
{
  float32_t pitch;       /*!< down = -0.999, middle = 0.000, up   =0.999 */
  float32_t roll;        /*!< left = -0.999, middle = 0.000, right=0.999 */
  float32_t yaw;         /*!< left = -0.999, middle = 0.000, right=0.999 */
  float32_t throttle;    /*!< down = -0.999, middle = 0.000, up   =0.999 */
  struct
  {
    uint8_t logicConnected  :1;  /*!< 0 if sky or ground side is disconnected for 3 seconds   */
    uint8_t skyConnected    :1;  /*!< Sky side is connected, i.e., receiver is connected to FC */
    uint8_t groundConnected :1;  /*!< Ground side is connected, i.e., RC is on and connected to FC */
    uint8_t appConnected    :1;  /*!< Mobile App is connected to RC */
    uint8_t reserved        :4;
  } flag;
} RCWithFlagData;

#define MAX_ESC_NUM 8

typedef struct ESCStatusIndividual
{
  int16_t  current;              /*!< ESC current, unit: mA */
  int16_t  speed;                /*!< ESC speed, unit: rpm */
  uint16_t voltage;              /*!< Input power from battery to ESC, unit: mV */
  int16_t  temperature;          /*!< ESC temperature, unit: degree C */
  uint16_t stall            : 1; /*!< Motor is stall */
  uint16_t empty            : 1; /*!< Motor has no load */
  uint16_t unbalanced       : 1; /*!< Motor speed is unbalanced */
  uint16_t escDisconnected  : 1; /*!< ESC is disconnected */
  uint16_t temperatureHigh  : 1; /*!< Temperature is high */
  uint16_t reserved         : 11;
} ESCStatusIndividual;
typedef struct EscData
{
  ESCStatusIndividual esc[MAX_ESC_NUM];
} EscData;

typedef struct RTKConnectStatus
{
  uint16_t rtkConnected : 1;
  uint16_t reserve         : 15;
} RTKConnectStatus;

typedef uint8_t GimbalControlMode;

// json structToJson(const GimbalControlMode& obj) {
//     json jsonObj;
//     jsonObj["GimbalControlMode"] = obj;
//     return jsonObj;
// }

typedef struct FlightAnomaly
{
  uint32_t impactInAir               : 1;  /*!< 0: No impact,                      1: Impact happens in Air */
  uint32_t randomFly                 : 1;  /*!< 0: Normal,                         1: Randomly fly in GPS mode without stick input*/
  uint32_t heightCtrlFail            : 1;  /*!< 0: Height control normal,          1: Height control failed */
  uint32_t rollPitchCtrlFail         : 1;  /*!< 0: Tilt control normal,            1: Tilt control failed */
  uint32_t yawCtrlFail               : 1;  /*!< 0: Yaw control normal,             1: Yaw control failed */
  uint32_t aircraftIsFalling         : 1;  /*!< 0: Aircraft is not falling,        1: Aircraft is falling */
  uint32_t strongWindLevel1          : 1;  /*!< 0: Wind is under big wind level 1, 1: wind is stronger than  big wind level 1*/
  uint32_t strongWindLevel2          : 1;  /*!< 0: Wind is under big wind level 2, 1: wind is stronger than  big wind level 2*/
  uint32_t compassInstallationError  : 1;  /*!< 0: Compass install right,          1: Compass install error */
  uint32_t imuInstallationError      : 1;  /*!< 0: IMU install right,              1: IMU install error */
  uint32_t escTemperatureHigh        : 1;  /*!< 0: ESC temperature is normal,      1: ESC temperature is high */
  uint32_t atLeastOneEscDisconnected : 1;  /*!< 0: No ESC disconnected,            1: At least one ESC is disconnected */
  uint32_t gpsYawError               : 1;  /*!< 0: No GPS yaw error,               1: GPS yaw error */
  uint32_t reserved                  : 19;
} FlightAnomaly;
typedef struct LocalPositionVO
{
    float32_t x;              /*!< North (best effort), unit: m */
    float32_t y;              /*!< East (best effort),  unit: m */
    float32_t z;              /*!< Down,  unit: m */
    uint8_t   xHealth   : 1;
    uint8_t   yHealth   : 1;
    uint8_t   zHealth   : 1;
    uint8_t   reserved  : 5;
} LocalPositionVO;
typedef struct RelativePosition
{
  float32_t down;            /*!< distance from obstacle (m) */
  float32_t front;           /*!< distance from obstacle (m) */
  float32_t right;           /*!< distance from obstacle (m) */
  float32_t back;            /*!< distance from obstacle (m) */
  float32_t left;            /*!< distance from obstacle (m) */
  float32_t up;              /*!< distance from obstacle (m) */
  uint8_t   downHealth : 1;  /*!< Down sensor flag: 0 - not working, 1 - working */
  uint8_t   frontHealth : 1; /*!< Front sensor flag: 0 - not working, 1 - working */
  uint8_t   rightHealth : 1; /*!< Right sensor flag: 0 - not working, 1 - working */
  uint8_t   backHealth : 1;  /*!< Back sensor flag: 0 - not working, 1 - working */
  uint8_t   leftHealth : 1;  /*!< Left sensor flag: 0 - not working, 1 - working */
  uint8_t   upHealth : 1;    /*!< Up sensor health flag: 0 - not working, 1 - working */
  uint8_t   reserved : 2;    /*!< Reserved sensor health flag*/
} RelativePosition; // pack(1)

typedef struct HomeLocationSetStatus
{
  uint8_t status;     /*!<0:fail, 1:success*/
}HomeLocationSetStatus;// pack(1)
typedef struct HomeLocationData
{
  float64_t latitude;  /*!< unit: rad */
  float64_t longitude; /*!< unit: rad */
}HomeLocationData; // pack(1)
