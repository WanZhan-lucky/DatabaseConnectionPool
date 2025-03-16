#include <iostream>

#include "CommonConnectionPool.h"
#include "Connection.h"
using namespace std;

// int main() {
// Connection conn;
// char sql[1024] = {0};
// sprintf(sql, "insert into user(name, age, sex) values('%s',%d,'%s')",
//         "wanzhan", 25, "male");

// conn.connect("127.0.0.1", 3306, "root", "123456", "wanchat");
// conn.update(sql);
// ConnectionPool *cp = ConnectionPool::getConnectionPool();
// cout << "second ";
// cp->loadConfigFile();

// 线程阻塞
// return 0;
// }

// g++ main.cpp Connection.cpp -o main -lmysqlclient
/*
如果有 CMakeLists.txt，CMake Tools 插件自动生成并覆盖该配置，VSCode 就能识别
#include "Connection.h"
*/

/*
lock_guard y

*/