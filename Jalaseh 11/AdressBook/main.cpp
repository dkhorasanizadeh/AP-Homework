#include "adressbookwindow.hpp"
#include "adressmanager.hpp"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    AdressBookWindow *w=AdressBookWindow::getInstance();
    AdressManager *m=AdressManager::getInstance();
    QObject::connect(m,SIGNAL(nameAlreadyExist()),w,SLOT(alertNameExist()));
    QObject::connect(m,SIGNAL(nameDosentExist()),w,SLOT(alertNameDosentExist()));
    w->show();
    return a.exec();
}
