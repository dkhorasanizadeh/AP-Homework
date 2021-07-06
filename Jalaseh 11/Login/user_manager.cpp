#include "user_manager.hpp"

UserManager *UserManager::Instance = nullptr;
UserManager::UserManager() {}

UserManager *UserManager::getInstance() {
  if (Instance == nullptr) {
    Instance = new UserManager();
  }
  return Instance;
}

void UserManager::addNewUser(QString firstName, QString lastName,
                             QString username, QString password, QString email,
                             int age, QString gender) {
  User user(firstName, lastName, username, password, email, age, gender);
  Users.insert(username, user);
}

User *UserManager::getUser(QString username) {
  if (Users.contains(username)) {
    return &Users[username];
  }
  return nullptr;
}
