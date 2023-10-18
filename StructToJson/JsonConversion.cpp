#include <iostream>
#include <chrono>
#include "nlohmann/json.hpp"
#include "myStructs.hpp"

using json = nlohmann::json;

// 重载版本1：将 Vector3f 转换为 JSON
json structToJson(const Vector3f& obj) {
    json jsonObj;
    jsonObj["x"] = obj.x;
    jsonObj["y"] = obj.y;
    jsonObj["z"] = obj.z;
    return jsonObj;
}

// 重载版本2：将 Person 结构体转换为 JSON
json structToJson(const Person& obj) {
    json jsonObj;
    jsonObj["name"] = obj.name;
    jsonObj["age"] = obj.age;
    return jsonObj;
}