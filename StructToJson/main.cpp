#include "myStructs.hpp"
#include "JsonConversion.cpp"
#include <iostream>

using namespace std;

int main(){
    // 定义结构体
    Vector3f myVector = {1.0f, 2.0f, 3.0f};
    Person person = {"John", 30};
    // 调用函数
    json vectorJson = structToJson(myVector);
    json personJson = structToJson(person);

    cout << "vectorJson" << vectorJson.dump(4) << endl;
    cout << "vectorJson" << vectorJson.dump(4) << endl;

    return 0;
}