#include <QApplication>

#include "login.hpp"
#include "signup.hpp"
#include "user_manager.hpp"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  Login *l = Login::getInstance();
  Signup *s = Signup::getInstance();
  UserManager::getInstance();
  QObject::connect(l, SIGNAL(openSignupPage()), s, SLOT(openSignup()));
  QObject::connect(s, SIGNAL(openLoginPage()), l, SLOT(openLogin()));
  l->show();
  return a.exec();
}
