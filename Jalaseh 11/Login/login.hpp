#ifndef LOGIN_HPP
#define LOGIN_HPP

#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QMainWindow>
#include <QMessageBox>
#include <QPushButton>
#include <QShortcut>
#include <QVBoxLayout>

#include "user_manager.hpp"

class Login : public QMainWindow {
 private:
  Q_OBJECT
  static Login *instance;
  QWidget *centralWidget;
  QPushButton *loginButton;
  QPushButton *signupButton;
  QVBoxLayout *mainVerticalLayout;
  QHBoxLayout *usernameLayout;
  QHBoxLayout *passwordLayout;
  QLabel *usernameLabel;
  QLineEdit *usernameLineEdit;
  QLabel *passwordLabel;
  QLineEdit *passwordLineEdit;
  QShortcut *enterLogin;
  Login(QWidget *parent = nullptr);

 public:
  static Login *getInstance(void);
  ~Login();
 public slots:
  void signupButtonPressed(void);
  void openLogin(void);
  void LoginButtonPressed(void);
 signals:
  void openSignupPage(void);
};
#endif  // LOGIN_HPP
