#ifndef USER_HPP
#define USER_HPP

#include <QCryptographicHash>
#include <QString>
class User {
 private:
  QString FirstName;
  QString LastName;
  QString Username;
  QString Password;
  QString Email;
  int Age;
  QString Gender;

 public:
  User(void);
  User(QString firstName, QString lastName, QString username, QString password,
       QString email, int age, QString gender);
  bool checkPassword(QString password);
  const QString &getFirstName() const;
  void setFirstName(const QString &newFirstName);
  const QString &getLastName() const;
  void setLastName(const QString &newLastName);
  const QString &getUsername() const;
  void setUsername(const QString &newUsername);
  void setPassword(const QString &newPassword);
  const QString &getEmail() const;
  void setEmail(const QString &newEmail);
  int getAge() const;
  void setAge(int newAge);
  const QString &getGender() const;
  void setGender(const QString &newGender);
};

#endif  // USER_HPP
