#include "signup.hpp"

Signup *Signup::instance=nullptr;

Signup::Signup(QWidget *parent) : QMainWindow(parent)
{
    centralWidget=new QWidget();
    signupButton=new QPushButton();
    loginButton=new QPushButton();
    firstNameLabel=new QLabel();
    lastNameLabel=new QLabel();
    usernameLabel=new QLabel();
    passwordLabel=new QLabel();
    passwordRepeatLabel=new QLabel();
    emailLabel=new QLabel();
    ageLabel=new QLabel();
    genderLabel=new QLabel();
    firstNameLineEdit=new QLineEdit();
    lastNameLineEdit=new QLineEdit();
    usernameLineEdit=new QLineEdit();
    passwordLineEdit=new QLineEdit();
    passwordRepeatLineEdit=new QLineEdit();
    emailLineEdit=new QLineEdit();
    ageSpinBox=new QSpinBox();
    genderComboBox=new QComboBox();
    firstNameLayout=new QHBoxLayout();
    lastNameLayout=new QHBoxLayout();
    usernameLayout=new QHBoxLayout();
    passwordLayout=new QHBoxLayout();
    passwordRepeatLayout=new QHBoxLayout();
    emailLayout=new QHBoxLayout();
    ageLayout=new QHBoxLayout();
    genderLayout=new QHBoxLayout();
    mainVerticalLayout=new QVBoxLayout();
    enterSignup = new QShortcut(QKeySequence(Qt::Key::Key_Enter),this,SLOT(signupButtonPressed()));
    signupButton->setText("Signup");
    loginButton->setText("Login");
    firstNameLabel->setText("First Name: ");
    lastNameLabel->setText("Last Name: ");
    usernameLabel->setText("Username: ");
    passwordLabel->setText("Password: ");
    passwordRepeatLabel->setText("Password repeat: ");
    emailLabel->setText("Email: ");
    ageLabel->setText("Age: ");
    genderLabel->setText("Gender: ");
    passwordLineEdit->setEchoMode(QLineEdit::Password);
    passwordRepeatLineEdit->setEchoMode(QLineEdit::Password);
    ageSpinBox->setMinimum(18);
    genderComboBox->addItem("Male");
    genderComboBox->addItem("Female");
    firstNameLayout->addWidget(firstNameLabel);
    firstNameLayout->addWidget(firstNameLineEdit);
    lastNameLayout->addWidget(lastNameLabel);
    lastNameLayout->addWidget(lastNameLineEdit);
    usernameLayout->addWidget(usernameLabel);
    usernameLayout->addWidget(usernameLineEdit);
    passwordLayout->addWidget(passwordLabel);
    passwordLayout->addWidget(passwordLineEdit);
    passwordRepeatLayout->addWidget(passwordRepeatLabel);
    passwordRepeatLayout->addWidget(passwordRepeatLineEdit);
    emailLayout->addWidget(emailLabel);
    emailLayout->addWidget(emailLineEdit);
    ageLayout->addWidget(ageLabel);
    ageLayout->addWidget(ageSpinBox);
    genderLayout->addWidget(genderLabel);
    genderLayout->addWidget(genderComboBox);
    mainVerticalLayout->addLayout(firstNameLayout);
    mainVerticalLayout->addLayout(lastNameLayout);
    mainVerticalLayout->addLayout(usernameLayout);
    mainVerticalLayout->addLayout(passwordLayout);
    mainVerticalLayout->addLayout(passwordRepeatLayout);
    mainVerticalLayout->addLayout(emailLayout);
    mainVerticalLayout->addLayout(ageLayout);
    mainVerticalLayout->addLayout(genderLayout);
    mainVerticalLayout->addWidget(signupButton);
    mainVerticalLayout->addWidget(loginButton);
    centralWidget->setLayout(mainVerticalLayout);
    setCentralWidget(centralWidget);
    setWindowTitle("Signup");
    connect(loginButton,SIGNAL(clicked()),this,SLOT(loginButtonPressed()));
    connect(signupButton,SIGNAL(clicked()),this,SLOT(signupButtonPressed()));
    enterSignup->setAutoRepeat(false);
}

Signup::~Signup()
{
    delete centralWidget;
    delete signupButton;
    delete loginButton;
    delete firstNameLabel;
    delete lastNameLabel;
    delete usernameLabel;
    delete passwordLabel;
    delete passwordRepeatLabel;
    delete emailLabel;
    delete ageLabel;
    delete genderLabel;
    delete firstNameLineEdit;
    delete lastNameLineEdit;
    delete usernameLineEdit;
    delete passwordLineEdit;
    delete passwordRepeatLineEdit;
    delete emailLineEdit;
    delete ageSpinBox;
    delete genderComboBox;
    delete firstNameLayout;
    delete lastNameLayout;
    delete usernameLayout;
    delete passwordLayout;
    delete passwordRepeatLayout;
    delete emailLayout;
    delete ageLayout;
    delete genderLayout;
    delete mainVerticalLayout;
    delete enterSignup;
}

Signup *Signup::getInstance(void)
{
    if(instance==nullptr)
    {
        instance=new Signup();
    }
    return instance;
}

void Signup::loginButtonPressed(void)
{
    this->close();
    emit openLoginPage();
}

void Signup::openSignup(void)
{
    this->show();
}

void Signup::signupButtonPressed()
{
    QMessageBox message;
    if(
       firstNameLineEdit->text().length()==0||
       lastNameLineEdit->text().length()==0||
       usernameLineEdit->text().length()==0||
       passwordLineEdit->text().length()==0||
       passwordRepeatLineEdit->text().length()==0||
       emailLineEdit->text().length()==0)
    {
        message.setText("All Fields Should Be Filled.");
        message.exec();
    }
    else
    {
        UserManager *userManager=UserManager::getInstance();
        if(passwordLineEdit->text()!=passwordRepeatLineEdit->text())
        {
            message.setText("Password Repeat Dosen't Match.");
            passwordLineEdit->setText("");
            passwordRepeatLineEdit->setText("");
            message.exec();
        }
        else if(userManager->getUser(usernameLineEdit->text())!=nullptr)
        {
            message.setText("A User Already Exists With This Username.");
            usernameLineEdit->setText("");
            message.exec();
        }
        else
        {
            userManager->addNewUser(
                        firstNameLineEdit->text(),
                        lastNameLineEdit->text(),
                        usernameLineEdit->text(),
                        passwordLineEdit->text(),
                        emailLineEdit->text(),
                        ageSpinBox->value(),
                        genderComboBox->currentText());
            firstNameLineEdit->setText("");
            lastNameLineEdit->setText("");
            usernameLineEdit->setText("");
            passwordLineEdit->setText("");
            passwordRepeatLineEdit->setText("");
            emailLineEdit->setText("");
            ageSpinBox->setValue(19);
            message.setText("Signup Successful!");
            message.exec();
        }
    }
}
