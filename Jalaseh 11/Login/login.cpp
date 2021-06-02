#include "login.hpp"

Login *Login::instance=nullptr;

Login::Login(QWidget *parent)
    : QMainWindow(parent)
{
    centralWidget=new QWidget();
    loginButton=new QPushButton();
    signupButton=new QPushButton();
    mainVerticalLayout=new QVBoxLayout();
    usernameLayout=new QHBoxLayout();
    passwordLayout=new QHBoxLayout();
    usernameLabel=new QLabel();
    usernameLineEdit=new QLineEdit();
    passwordLabel=new QLabel();
    passwordLineEdit=new QLineEdit();
    enterLogin = new QShortcut(QKeySequence(Qt::Key::Key_Enter),this,SLOT(LoginButtonPressed()));
    loginButton->setText("Login");
    signupButton->setText("Sign Up");
    usernameLabel->setText("Username: ");
    passwordLabel->setText("Password: ");
    passwordLineEdit->setEchoMode(QLineEdit::Password);
    usernameLayout->addWidget(usernameLabel);
    usernameLayout->addWidget(usernameLineEdit);
    passwordLayout->addWidget(passwordLabel);
    passwordLayout->addWidget(passwordLineEdit);
    mainVerticalLayout->addLayout(usernameLayout);
    mainVerticalLayout->addLayout(passwordLayout);
    mainVerticalLayout->addWidget(loginButton);
    mainVerticalLayout->addWidget(signupButton);
    centralWidget->setLayout(mainVerticalLayout);
    setCentralWidget(centralWidget);
    setWindowTitle("Login");
    connect(signupButton,SIGNAL(clicked()),this,SLOT(signupButtonPressed()));
    connect(loginButton,SIGNAL(clicked()),this,SLOT(LoginButtonPressed()));
    enterLogin->setAutoRepeat(false);
}

Login::~Login()
{
    delete centralWidget;
    delete loginButton;
    delete signupButton;
    delete mainVerticalLayout;
    delete usernameLayout;
    delete passwordLayout;
    delete usernameLabel;
    delete usernameLineEdit;
    delete passwordLabel;
    delete passwordLineEdit;
    delete enterLogin;
}

Login *Login::getInstance(void)
{
    if(instance==nullptr)
    {
        instance=new Login();
    }
    return instance;
}

void Login::signupButtonPressed(void)
{
    this->close();
    emit openSignupPage();
}

void Login::openLogin(void)
{
    this->show();
}

void Login::LoginButtonPressed(void)
{
    QString usernameLineEditText=usernameLineEdit->text();
    QString passwordLineEditText=passwordLineEdit->text();
    QMessageBox message;
    if(usernameLineEditText.length()==0 || passwordLineEditText.length()==0)
    {
        message.setText("Fields Can't Be Empty.");
        message.exec();
    }
    else
    {
        UserManager *userManager=UserManager::getInstance();
        User *user=userManager->getUser(usernameLineEditText);
        if(user!=nullptr){
            bool verify=user->checkPassword(passwordLineEditText);
            if(verify)
            {
                QString LoginText="Hello "+user->getFirstName()+" "+user->getLastName()+
                        "\nEmail: "+user->getEmail()+
                        "\nGender: "+user->getGender()+
                        "\nAge: "+QString::number(user->getAge());
                usernameLineEdit->setText("");
                passwordLineEdit->setText("");
                message.setText(LoginText);
                message.exec();
            }
            else
            {
                message.setText("Wrong Password.");
                passwordLineEdit->setText("");
                message.exec();
            }
        }
        else
        {
            message.setText("User Dosen't Exist.");
            usernameLineEdit->setText("");
            passwordLineEdit->setText("");
            message.exec();
        }

    }
}
