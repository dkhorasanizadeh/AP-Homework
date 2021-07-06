#ifndef USER_MANAGER_HPP
#define USER_MANAGER_HPP

#include <QMap>

#include "user.hpp"
class UserManager {
 private:
  static UserManager *Instance;
  QMap<QString, User> Users;
  UserManager();

 public:
  static UserManager *getInstance();
  void addNewUser(QString firstName, QString lastName, QString username,
                  QString password, QString email, int age, QString gender);
  User *getUser(QString username);
};
#endif  // USER_MANAGER_HPP
