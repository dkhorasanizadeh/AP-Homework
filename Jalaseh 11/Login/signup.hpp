#ifndef SIGNUP_HPP
#define SIGNUP_HPP

#include <QMainWindow>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QSpinBox>
#include <QComboBox>
#include <QMessageBox>
#include <QShortcut>

#include "user_manager.hpp"

class Signup : public QMainWindow
{
private:
    Q_OBJECT
    static Signup *instance;
    QWidget *centralWidget;
    QPushButton *signupButton;
    QPushButton *loginButton;
    QHBoxLayout *firstNameLayout;
    QLabel *firstNameLabel;
    QLineEdit *firstNameLineEdit;
    QHBoxLayout *lastNameLayout;
    QLabel *lastNameLabel;
    QLineEdit *lastNameLineEdit;
    QHBoxLayout *usernameLayout;
    QLabel *usernameLabel;
    QLineEdit *usernameLineEdit;
    QHBoxLayout *passwordLayout;
    QLabel *passwordLabel;
    QLineEdit *passwordLineEdit;
    QHBoxLayout *passwordRepeatLayout;
    QLabel *passwordRepeatLabel;
    QLineEdit *passwordRepeatLineEdit;
    QHBoxLayout *emailLayout;
    QLabel *emailLabel;
    QLineEdit *emailLineEdit;
    QHBoxLayout *ageLayout;
    QLabel *ageLabel;
    QSpinBox *ageSpinBox;
    QHBoxLayout *genderLayout;
    QLabel *genderLabel;
    QComboBox *genderComboBox;
    QVBoxLayout *mainVerticalLayout;
    QShortcut * enterSignup;
    explicit Signup(QWidget *parent = nullptr);
    ~Signup(void);

public:
    static Signup *getInstance();

public slots:
    void loginButtonPressed(void);
    void openSignup(void);
    void signupButtonPressed(void);
signals:
    void openLoginPage(void);

};

#endif // SIGNUP_HPP
