#include "user.hpp"

User::User() {}

User::User(QString firstName, QString lastName, QString username,
           QString password, QString email, int age, QString gender) {
  setFirstName(firstName);
  setLastName(lastName);
  setUsername(username);
  setPassword(password);
  setEmail(email);
  setAge(age);
  setGender(gender);
}

const QString &User::getFirstName() const { return FirstName; }

void User::setFirstName(const QString &newFirstName) {
  FirstName = newFirstName;
}

const QString &User::getLastName() const { return LastName; }

void User::setLastName(const QString &newLastName) { LastName = newLastName; }

const QString &User::getUsername() const { return Username; }

void User::setUsername(const QString &newUsername) { Username = newUsername; }

void User::setPassword(const QString &newPassword) {
  QByteArray passwordByte = newPassword.toUtf8();
  Password = QString(
      QCryptographicHash::hash((passwordByte), QCryptographicHash::Sha256)
          .toHex());
}

const QString &User::getEmail() const { return Email; }

void User::setEmail(const QString &newEmail) { Email = newEmail; }

int User::getAge() const { return Age; }

void User::setAge(int newAge) { Age = newAge; }

const QString &User::getGender() const { return Gender; }

void User::setGender(const QString &newGender) { Gender = newGender; }

bool User::checkPassword(QString password) {
  QByteArray passwordByte = password.toUtf8();
  password = QString(
      QCryptographicHash::hash((passwordByte), QCryptographicHash::Sha256)
          .toHex());
  return password == Password;
}
