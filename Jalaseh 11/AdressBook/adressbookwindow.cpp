#include "adressbookwindow.hpp"
AdressBookWindow *AdressBookWindow::Instance=nullptr;

AdressBookWindow::AdressBookWindow(QWidget *parent)
    : QMainWindow(parent)
{
    CentralWidget=new QWidget();
    Grid=new QGridLayout();
    NameLabel=new QLabel();
    AdressLabel=new QLabel();
    NameLineEdit=new QLineEdit();
    AdressTextEdit=new QTextEdit();
    AddButton=new QPushButton();
    EditButton=new QPushButton();
    SaveButton=new QPushButton();
    RemoveButton=new QPushButton();
    FindButton=new QPushButton();
    ImportButton=new QPushButton();
    ExportButton=new QPushButton();
    NextButton=new QPushButton();
    PreviousButton=new QPushButton();
    NameLabel->setText("Name: ");
    AdressLabel->setText("Adress: ");
    AddButton->setText("Add");
    EditButton->setText("Edit");
    SaveButton->setText("Save");
    RemoveButton->setText("Remove");
    FindButton->setText("Find");
    ImportButton->setText("Import");
    ExportButton->setText("Export");
    NextButton->setText("Next");
    PreviousButton->setText("Previous");
    NameLineEdit->setDisabled(true);
    AdressTextEdit->setDisabled(true);
    Grid->addWidget(NameLabel,0,0,1,1);
    Grid->addWidget(AdressLabel,1,0,1,1);
    Grid->addWidget(NameLineEdit,0,1,1,4);
    Grid->addWidget(AdressTextEdit,1,1,7,4);
    Grid->addWidget(AddButton,1,5,1,1);
    Grid->addWidget(EditButton,2,5,1,1);
    Grid->addWidget(SaveButton,3,5,1,1);
    Grid->addWidget(FindButton,4,5,1,1);
    Grid->addWidget(RemoveButton,5,5,1,1);
    Grid->addWidget(ImportButton,6,5,1,1);
    Grid->addWidget(ExportButton,7,5,1,1);
    Grid->addWidget(PreviousButton,8,1,1,2);
    Grid->addWidget(NextButton,8,3,1,2);
    CentralWidget->setLayout(Grid);
    setCentralWidget(CentralWidget);
    state=State::View;
    connect(AddButton,SIGNAL(clicked()),this,SLOT(AddButtonPressed()));
    connect(EditButton,SIGNAL(clicked()),this,SLOT(EditButtonPressed()));
    connect(SaveButton,SIGNAL(clicked()),this,SLOT(SaveButtonPressed()));
    connect(RemoveButton,SIGNAL(clicked()),this,SLOT(RemoveButtonPressed()));
    connect(FindButton,SIGNAL(clicked()),this,SLOT(FindButtonPressed()));
    connect(ImportButton,SIGNAL(clicked()),this,SLOT(ImportButtonPressed()));
    connect(ExportButton,SIGNAL(clicked()),this,SLOT(ExportButtonPressed()));
    connect(PreviousButton,SIGNAL(clicked()),this,SLOT(NextButtonPressed()));
    connect(NextButton,SIGNAL(clicked()),this,SLOT(PreviousButtonPressed()));
}

AdressBookWindow *AdressBookWindow::getInstance()
{
    if(Instance==nullptr)
    {
        Instance=new AdressBookWindow();
    }
    return Instance;
}
AdressBookWindow::~AdressBookWindow()
{
    delete NameLabel;
    delete AdressLabel;
    delete NameLineEdit;
    delete AdressTextEdit;
    delete AddButton;
    delete EditButton;
    delete SaveButton;
    delete RemoveButton;
    delete FindButton;
    delete ImportButton;
    delete ExportButton;
    delete NextButton;
    delete PreviousButton;
    delete Grid;
    delete CentralWidget;
}
void AdressBookWindow::showCurrent(void)
{
    QPair<QString,QString> name_adress=manager->getCurrent();
    NameLineEdit->setText(name_adress.first);
    AdressTextEdit->setText(name_adress.second);
}
void AdressBookWindow::AddButtonPressed(void)
{
    if(state!=State::View)
    {
        QMessageBox message;
        message.setText("You have to save before editing.");
        message.exec();
        return;
    }
    NameLineEdit->setText("");
    AdressTextEdit->setText("");
    NameLineEdit->setDisabled(false);
    AdressTextEdit->setDisabled(false);
    state=State::Add;
}
void AdressBookWindow::SaveButtonPressed(void)
{
    if(state==State::View)
    {
        QMessageBox message;
        message.setText("You have to be in Add or Edit mode before saving.");
        message.exec();
        return;
    }
    if(state==State::Add)
    {
        QString name=NameLineEdit->text();
        QString adress=AdressTextEdit->toPlainText();
        manager->addAdress(name,adress);
    }
    else if(state==State::Edit)
    {
        QString adress=AdressTextEdit->toPlainText();
        manager->editAdress(adress);
    }
    showCurrent();
    NameLineEdit->setDisabled(true);
    AdressTextEdit->setDisabled(true);
    state=State::View;
}
void AdressBookWindow::EditButtonPressed(void)
{
    if(state!=State::View)
    {
        QMessageBox message;
        message.setText("You have to save before editing.");
        message.exec();
        return;
    }
    AdressTextEdit->setDisabled(false);
    state=State::Edit;
}
void AdressBookWindow::RemoveButtonPressed(void)
{
    if(state!=State::View)
    {
        QMessageBox message;
        message.setText("You have to save before removing.");
        message.exec();
        return;
    }
    manager->removeAdress();
    showCurrent();
}
void AdressBookWindow::FindButtonPressed(void)
{
    if(state!=State::View)
    {
        QMessageBox message;
        message.setText("You have to save before finding.");
        message.exec();
        return;
    }
    bool ok;
    QString name=QInputDialog::getText(this,"Name","Name:",QLineEdit::Normal,"",&ok);
    if (ok && !name.isEmpty())
    {
        manager->findAdress(name);
        showCurrent();
    }
    else
    {
        QMessageBox message;
        message.setText("Please input a valid name.");
        message.exec();
        return;
    }
}
void AdressBookWindow::ImportButtonPressed(void)
{
   QString fileName = QFileDialog::getOpenFileName(this,"Open PhoneBook","./", "PhoneBook File (*.phonebook)");
   QFile file(fileName);
   if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
   {
       return;
   }
   manager->importFromFile(QTextStream(&file));
   showCurrent();
}
void AdressBookWindow::ExportButtonPressed(void)
{
   QString fileName = QFileDialog::getSaveFileName(this,"Save File","./","PhoneBook File (*.phonebook)");
   QFile file(fileName);
   if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
   {
        return;
   }
   manager->exportToFile(QTextStream(&file));
}
void AdressBookWindow::PreviousButtonPressed(void)
{
    manager->previousAdress();
    showCurrent();
}
void AdressBookWindow::NextButtonPressed(void)
{
    manager->nextAdress();
    showCurrent();
}

void AdressBookWindow::alertNameDosentExist(void)
{
    QMessageBox message;
    message.setText("Name dosen't exist.");
    message.exec();
}

void AdressBookWindow::alertNameExist(void)
{
    QMessageBox message;
    message.setText("Name already exists.");
    message.exec();
}
