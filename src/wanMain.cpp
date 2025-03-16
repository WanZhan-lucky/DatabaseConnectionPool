#include <iostream>
using namespace std;
#include "CommonConnectionPool.h"
#include "Connection.h"

// 压力测试
/*
int main() {
  clock_t begin = clock();
  // 模拟1000个人
  // 单线程-无连接池
  //   for (int i = 0; i < 10000; i++) {
  //     Connection conn;
  //     char sql[1024] = {0};
  //     sprintf(sql, "insert into user(name, age, sex) values('%s', %d, '%s')",
  //             "wanzhan", 25, "male");
  //     conn.connect("127.0.0.1", 3306, "root", "123456", "wanchat");

  //     conn.update(sql);
  //   }

  //   单线程-连接池
  ConnectionPool *cp = ConnectionPool::getConnectionPool();

  for (int i = 0; i < 10000; i++) {
    shared_ptr<Connection> sp = cp->getConnection();
    char sql[1024] = {0};
    sprintf(sql, "insert into user(name, age, sex) values('%s', %d, '%s')",
            "wanzhan", 25, "male");
    sp->update(sql);
  }

  clock_t end = clock();
  cout << (end - begin) * 1000 / CLOCKS_PER_SEC << "ms" << endl;
  return 0;
}
*/
// 多线程

int main() {
  // Connection conn;
  // conn.connect("127.0.0.1", 3306, "root", "123456", "wanchat");
  clock_t begin = clock();

  thread t1([]() {
    ConnectionPool *cp = ConnectionPool::getConnectionPool();
    for (int i = 0; i < 2500; ++i) {
      char sql[1024] = {0};
      sprintf(sql, "insert into user(name,age,sex) values('%s',%d,'%s')",
              "zhang san", 20, "male");
      shared_ptr<Connection> sp = cp->getConnection();
      sp->update(sql);
      //   Connection conn;
      //   char sql[1024] = {0};
      //   sprintf(sql, "insert into user(name,age,sex) values('%s',%d,'%s')",
      //           "zhang san", 20, "male");
      //   conn.connect("127.0.0.1", 3306, "root", "123456", "wanchat");
      //   conn.update(sql);
    }
  });
  thread t2([]() {
    ConnectionPool *cp = ConnectionPool::getConnectionPool();
    for (int i = 0; i < 2500; ++i) {
      char sql[1024] = {0};
      sprintf(sql, "insert into user(name,age,sex) values('%s',%d,'%s')",
              "zhang san", 20, "male");
      shared_ptr<Connection> sp = cp->getConnection();
      sp->update(sql);
      //   Connection conn;
      //   char sql[1024] = {0};
      //   sprintf(sql, "insert into user(name,age,sex) values('%s',%d,'%s')",
      //           "zhang san", 20, "male");
      //   conn.connect("127.0.0.1", 3306, "root", "123456", "wanchat");
      //   conn.update(sql);
    }
  });
  thread t3([]() {
    ConnectionPool *cp = ConnectionPool::getConnectionPool();
    for (int i = 0; i < 2500; ++i) {
      char sql[1024] = {0};
      sprintf(sql, "insert into user(name,age,sex) values('%s',%d,'%s')",
              "zhang san", 20, "male");
      shared_ptr<Connection> sp = cp->getConnection();
      sp->update(sql);
      //   Connection conn;
      //   char sql[1024] = {0};
      //   sprintf(sql, "insert into user(name,age,sex) values('%s',%d,'%s')",
      //           "zhang san", 20, "male");
      //   conn.connect("127.0.0.1", 3306, "root", "123456", "wanchat");
      //   conn.update(sql);
    }
  });
  thread t4([]() {
    ConnectionPool *cp = ConnectionPool::getConnectionPool();
    for (int i = 0; i < 2500; ++i) {
      char sql[1024] = {0};
      sprintf(sql, "insert into user(name,age,sex) values('%s',%d,'%s')",
              "zhang san", 20, "male");
      shared_ptr<Connection> sp = cp->getConnection();
      sp->update(sql);
      //   Connection conn;
      //   char sql[1024] = {0};
      //   sprintf(sql, "insert into user(name,age,sex) values('%s',%d,'%s')",
      //           "zhang san", 20, "male");
      //   conn.connect("127.0.0.1", 3306, "root", "123456", "wanchat");
      //   conn.update(sql);
    }
  });

  t1.join();
  t2.join();
  t3.join();
  t4.join();

  clock_t end = clock();
  cout << (end - begin) * 1000 / CLOCKS_PER_SEC << "ms" << endl;
}
