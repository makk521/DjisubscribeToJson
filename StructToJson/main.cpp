#include "myStructs.hpp"
#include "JsonConversion.cpp"
#include <iostream>

using namespace std;

int main()
{
    // 示例用法
    RC rcObj = {5000, -3000, 2000, 7000, -2000, -5000};
    json result = structToJson(rcObj);
    std::cout << "RC: " << result.dump(4) << std::endl;

    VelocityInfo velocityInfoObj = {1, 63}; // 示例值，health为1，reserve为63
    json result_a = structToJson(velocityInfoObj);
    std::cout << "Velocity Info: " << result_a.dump(4) << std::endl;

    GPSFused gpsFusedObj = {1.234, 5.678, 100.0, 10};
    Vector3d vector3dObj = {100, 200, 300};
    GPSDetail gpsDetailObj = {1.2, 2.3, 3.4, 4.5, 5.6, 6.7, 8, 12, 20, 1000};
    PositionData positionDataObj = {1.234, 5.678, 100.0};
    Mag magObj = {50, -30, 70};

    json result1 = structToJson(gpsFusedObj);
    json result2 = structToJson(vector3dObj);
    json result3 = structToJson(gpsDetailObj);
    json result4 = structToJson(positionDataObj);
    json result5 = structToJson(magObj);

    std::cout << "GPSFused: " << result1.dump(4) << std::endl;
    std::cout << "Vector3d: " << result2.dump(4) << std::endl;
    std::cout << "GPSDetail: " << result3.dump(4) << std::endl;
    std::cout << "PositionData: " << result4.dump(4) << std::endl;
    std::cout << "Mag: " << result5.dump(4) << std::endl;

    RCWithFlagData rcWithFlagDataObj = {0.5, -0.3, 0.7, -0.8, {1, 1, 1, 0, 0}};
    ESCStatusIndividual escStatusObj = {500, 1500, 12000, 70, 0, 0, 1, 0, 0, 0};
    EscData escDataObj = {{escStatusObj, escStatusObj, escStatusObj, escStatusObj, escStatusObj, escStatusObj, escStatusObj, escStatusObj}};
    RTKConnectStatus rtkConnectStatusObj = {1, 1};

    json result11 = structToJson(rcWithFlagDataObj);
    json result22 = structToJson(escDataObj);
    json result33 = structToJson(rtkConnectStatusObj);

    std::cout << "RCWithFlagData: " << result11.dump(4) << std::endl;
    std::cout << "EscData: " << result22.dump(4) << std::endl;
    std::cout << "RTKConnectStatus: " << result33.dump(4) << std::endl;

    // LB2RcFullRawData lb2RcObj = {1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024};
    // SBUSFullRawData sbusObj = {{1000, 1100, 1200, 1300, 1400, 1500, 1600, 1700, 1800, 1900, 2000, 2100, 2200, 2300, 2400, 2500}, {0, 0, 0, 0, 0, 0}};
    // RCFullRawData rcFullRawDataObj = {lb2RcObj, sbusObj};

    // json result6 = structToJson(rcFullRawDataObj);
    // std::cout << "RCFullRawData: " << result6.dump(4) << std::endl;

    return 0;
}