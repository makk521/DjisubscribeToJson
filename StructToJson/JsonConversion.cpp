#include <iostream>
#include <chrono>
#include "nlohmann/json.hpp"
#include "myStructs.hpp"

using json = nlohmann::json;

json structToJson(const uint8_t& obj)
{
    json jsonObj;
    jsonObj["uint8_t"] = static_cast<int>(obj);
    return jsonObj;
}

json structToJson(const uint16_t& obj)
{
    json jsonObj;
    jsonObj["uint16_t"] = static_cast<int>(obj);
    return jsonObj;
}

json structToJson(const int16_t& obj)
{
    json jsonObj;
    jsonObj["int16_t"] = obj;
    return jsonObj;
}

json structToJson(const uint32_t& obj)
{
    json jsonObj;
    jsonObj["uint32_t"] = static_cast<unsigned long>(obj);
    return jsonObj;
}

json structToJson(const float32_t& obj)
{
    json jsonObj;
    jsonObj["float32_t"] = obj;
    return jsonObj;
}


json structToJson(const Quaternion& obj)
{
    json jsonObj;
    jsonObj["w"] = obj.q0;
    jsonObj["x"] = obj.q1;
    jsonObj["y"] = obj.q2;
    jsonObj["z"] = obj.q3;
    return jsonObj;
}

json structToJson(const Vector3f& obj)
{
    json jsonObj;
    jsonObj["x"] = obj.x;
    jsonObj["y"] = obj.y;
    jsonObj["z"] = obj.z;
    return jsonObj;
}

json structToJson(const VelocityInfo& obj)
{
    json jsonObj;
    jsonObj["health"] = obj.health;
    jsonObj["reserve"] = obj.reserve;
    return jsonObj;
}

json structToJson(const Velocity& obj)
{
    json jsonObj;
    jsonObj["data"] = structToJson(obj.data);
    jsonObj["info"] = structToJson(obj.info);
    return jsonObj;
}

json structToJson(const GPSFused& obj)
{
    json jsonObj;
    jsonObj["longitude"] = obj.longitude;
    jsonObj["latitude"] = obj.latitude;
    jsonObj["altitude"] = obj.altitude;
    jsonObj["visibleSatelliteNumber"] = obj.visibleSatelliteNumber;
    return jsonObj;
}

json structToJson(const Vector3d& obj)
{
    json jsonObj;
    jsonObj["x"] = obj.x;
    jsonObj["y"] = obj.y;
    jsonObj["z"] = obj.z;
    return jsonObj;
}

json structToJson(const GPSDetail& obj)
{
    json jsonObj;
    jsonObj["hdop"] = obj.hdop;
    jsonObj["pdop"] = obj.pdop;
    jsonObj["fix"] = obj.fix;
    jsonObj["gnssStatus"] = obj.gnssStatus;
    jsonObj["hacc"] = obj.hacc;
    jsonObj["sacc"] = obj.sacc;
    jsonObj["usedGPS"] = obj.usedGPS;
    jsonObj["usedGLN"] = obj.usedGLN;
    jsonObj["NSV"] = obj.NSV;
    jsonObj["GPScounter"] = obj.GPScounter;
    return jsonObj;
}

json structToJson(const PositionData& obj)
{
    json jsonObj;
    jsonObj["longitude"] = obj.longitude;
    jsonObj["latitude"] = obj.latitude;
    jsonObj["HFSL"] = obj.HFSL;
    return jsonObj;
}

json structToJson(const Mag& obj)
{
    json jsonObj;
    jsonObj["x"] = obj.x;
    jsonObj["y"] = obj.y;
    jsonObj["z"] = obj.z;
    return jsonObj;
}

json structToJson(const RC& obj)
{
    json jsonObj;
    jsonObj["roll"] = obj.roll;
    jsonObj["pitch"] = obj.pitch;
    jsonObj["yaw"] = obj.yaw;
    jsonObj["throttle"] = obj.throttle;
    jsonObj["mode"] = obj.mode;
    jsonObj["gear"] = obj.gear;
    return jsonObj;
}

json structToJson(const GimbalStatus& obj)
{
    json jsonObj;
    jsonObj["mountStatus"] = obj.mountStatus;
    jsonObj["isBusy"] = obj.isBusy;
    jsonObj["pitchLimited"] = obj.pitchLimited;
    jsonObj["rollLimited"] = obj.rollLimited;
    jsonObj["yawLimited"] = obj.yawLimited;
    jsonObj["calibrating"] = obj.calibrating;
    jsonObj["prevCalibrationgResult"] = obj.prevCalibrationgResult;
    jsonObj["installedDirection"] = obj.installedDirection;
    jsonObj["disabled_mvo"] = obj.disabled_mvo;
    jsonObj["gear_show_unable"] = obj.gear_show_unable;
    jsonObj["gyroFalut"] = obj.gyroFalut;
    jsonObj["escPitchStatus"] = obj.escPitchStatus;
    jsonObj["escRollStatus"] = obj.escRollStatus;
    jsonObj["escYawStatus"] = obj.escYawStatus;
    jsonObj["droneDataRecv"] = obj.droneDataRecv;
    jsonObj["initUnfinished"] = obj.initUnfinished;
    jsonObj["FWUpdating"] = obj.FWUpdating;
    jsonObj["reserved2"] = obj.reserved2;
    return jsonObj;
}

json structToJson(const Battery& obj)
{
    json jsonObj;
    jsonObj["capacity"] = obj.capacity;
    jsonObj["voltage"] = obj.voltage;
    jsonObj["current"] = obj.current;
    jsonObj["percentage"] = obj.percentage;
    return jsonObj;
}

json structToJson(const SDKInfo& obj)
{
    json jsonObj;
    jsonObj["controlMode"] = obj.controlMode;
    jsonObj["deviceStatus"] = obj.deviceStatus;
    jsonObj["flightStatus"] = obj.flightStatus;
    jsonObj["vrcStatus"] = obj.vrcStatus;
    jsonObj["reserved"] = obj.reserved;
    return jsonObj;
}

json structToJson(const SyncTimestamp& obj)
{
    json jsonObj;
    jsonObj["time2p5ms"] = obj.time2p5ms;
    jsonObj["time1ns"] = obj.time1ns;
    jsonObj["resetTime2p5ms"] = obj.resetTime2p5ms;
    jsonObj["index"] = obj.index;
    jsonObj["flag"] = obj.flag;
    return jsonObj;
}


json structToJson(const HardSyncData& obj)
{
    json jsonObj;
    jsonObj["ts"] = structToJson(obj.ts);
    jsonObj["q"] = structToJson(obj.q);
    jsonObj["a"] = structToJson(obj.a);
    jsonObj["w"] = structToJson(obj.w);
    return jsonObj;
}


json structToJson(const LB2RcFullRawData& obj)
{
    json jsonObj;
    jsonObj["roll"] = obj.roll;
    jsonObj["pitch"] = obj.pitch;
    jsonObj["yaw"] = obj.yaw;
    jsonObj["throttle"] = obj.throttle;
    jsonObj["mode"] = obj.mode;
    jsonObj["gear"] = obj.gear;
    jsonObj["camera"] = obj.camera;
    jsonObj["video"] = obj.video;
    jsonObj["videoPause"] = obj.videoPause;
    jsonObj["goHome"] = obj.goHome;
    jsonObj["leftWheel"] = obj.leftWheel;
    jsonObj["rightWheelButton"] = obj.rightWheelButton;
    jsonObj["rcC1"] = obj.rcC1;
    jsonObj["rcC2"] = obj.rcC2;
    jsonObj["rcD1"] = obj.rcD1;
    jsonObj["rcD2"] = obj.rcD2;
    jsonObj["rcD3"] = obj.rcD3;
    jsonObj["rcD4"] = obj.rcD4;
    jsonObj["rcD5"] = obj.rcD5;
    jsonObj["rcD6"] = obj.rcD6;
    jsonObj["rcD7"] = obj.rcD7;
    jsonObj["rcD8"] = obj.rcD8;
    return jsonObj;
}

json structToJson(const SBUSFullRawData& obj)
{
    json jsonObj;
    for (int i = 0; i < SDK_SBUS_CHANNEL_NUM; ++i)
    {
        jsonObj["data"].push_back(obj.data[i]);
    }
    for (int i = 0; i < (SDK_LB2_CHANNEL_NUM - SDK_SBUS_CHANNEL_NUM); ++i)
    {
        jsonObj["reserved"].push_back(obj.reserved[i]);
    }
    return jsonObj;
}

json structToJson(const RCFullRawData& obj)
{
    json jsonObj;
    jsonObj["lb2"] = structToJson(obj.lb2);
    jsonObj["sbus"] = structToJson(obj.sbus);
    return jsonObj;
}


json structToJson(const RCWithFlagData& obj)
{
    json jsonObj;
    jsonObj["pitch"] = obj.pitch;
    jsonObj["roll"] = obj.roll;
    jsonObj["yaw"] = obj.yaw;
    jsonObj["throttle"] = obj.throttle;
    jsonObj["flag"]["logicConnected"] = obj.flag.logicConnected;
    jsonObj["flag"]["skyConnected"] = obj.flag.skyConnected;
    jsonObj["flag"]["groundConnected"] = obj.flag.groundConnected;
    jsonObj["flag"]["appConnected"] = obj.flag.appConnected;
    jsonObj["flag"]["reserved"] = obj.flag.reserved;
    return jsonObj;
}

json structToJson(const ESCStatusIndividual& obj)
{
    json jsonObj;
    jsonObj["current"] = obj.current;
    jsonObj["speed"] = obj.speed;
    jsonObj["voltage"] = obj.voltage;
    jsonObj["temperature"] = obj.temperature;
    jsonObj["stall"] = obj.stall;
    jsonObj["empty"] = obj.empty;
    jsonObj["unbalanced"] = obj.unbalanced;
    jsonObj["escDisconnected"] = obj.escDisconnected;
    jsonObj["temperatureHigh"] = obj.temperatureHigh;
    jsonObj["reserved"] = obj.reserved;
    return jsonObj;
}

json structToJson(const EscData& obj)
{
    json jsonObj;
    for (int i = 0; i < MAX_ESC_NUM; ++i)
    {
        jsonObj["esc"].push_back(structToJson(obj.esc[i]));
    }
    return jsonObj;
}

json structToJson(const RTKConnectStatus& obj)
{
    json jsonObj;
    jsonObj["rtkConnected"] = obj.rtkConnected;
    jsonObj["reserve"] = obj.reserve;
    return jsonObj;
}


// json structToJson(const GimbalControlMode& obj) {
//     json jsonObj;
//     jsonObj["GimbalControlMode"] = obj;
//     return jsonObj;
// }



json structToJson(const FlightAnomaly& obj)
{
    json jsonObj;
    jsonObj["impactInAir"] = obj.impactInAir;
    jsonObj["randomFly"] = obj.randomFly;
    jsonObj["heightCtrlFail"] = obj.heightCtrlFail;
    jsonObj["rollPitchCtrlFail"] = obj.rollPitchCtrlFail;
    jsonObj["yawCtrlFail"] = obj.yawCtrlFail;
    jsonObj["aircraftIsFalling"] = obj.aircraftIsFalling;
    jsonObj["strongWindLevel1"] = obj.strongWindLevel1;
    jsonObj["strongWindLevel2"] = obj.strongWindLevel2;
    jsonObj["compassInstallationError"] = obj.compassInstallationError;
    jsonObj["imuInstallationError"] = obj.imuInstallationError;
    jsonObj["escTemperatureHigh"] = obj.escTemperatureHigh;
    jsonObj["atLeastOneEscDisconnected"] = obj.atLeastOneEscDisconnected;
    jsonObj["gpsYawError"] = obj.gpsYawError;
    jsonObj["reserved"] = obj.reserved;
    return jsonObj;
}

json structToJson(const LocalPositionVO& obj)
{
    json jsonObj;
    jsonObj["x"] = obj.x;
    jsonObj["y"] = obj.y;
    jsonObj["z"] = obj.z;
    jsonObj["xHealth"] = obj.xHealth;
    jsonObj["yHealth"] = obj.yHealth;
    jsonObj["zHealth"] = obj.zHealth;
    jsonObj["reserved"] = obj.reserved;
    return jsonObj;
}

json structToJson(const RelativePosition& obj)
{
    json jsonObj;
    jsonObj["down"] = obj.down;
    jsonObj["front"] = obj.front;
    jsonObj["right"] = obj.right;
    jsonObj["back"] = obj.back;
    jsonObj["left"] = obj.left;
    jsonObj["up"] = obj.up;
    jsonObj["downHealth"] = obj.downHealth;
    jsonObj["frontHealth"] = obj.frontHealth;
    jsonObj["rightHealth"] = obj.rightHealth;
    jsonObj["backHealth"] = obj.backHealth;
    jsonObj["leftHealth"] = obj.leftHealth;
    jsonObj["upHealth"] = obj.upHealth;
    jsonObj["reserved"] = obj.reserved;
    return jsonObj;
}


json structToJson(const HomeLocationSetStatus& obj)
{
    json jsonObj;
    jsonObj["status"] = obj.status;
    return jsonObj;
}

json structToJson(const HomeLocationData& obj)
{
    json jsonObj;
    jsonObj["latitude"] = obj.latitude;
    jsonObj["longitude"] = obj.longitude;
    return jsonObj;
}
