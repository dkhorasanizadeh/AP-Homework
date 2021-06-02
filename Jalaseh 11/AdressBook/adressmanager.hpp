#ifndef ADRESSMANAGER_HPP
#define ADRESSMANAGER_HPP

#include <QObject>
#include <QMap>
#include <QPair>
#include <QTextStream>
#include <QRegularExpression>

class AdressManager : public QObject
{
private:
    Q_OBJECT
    QMap<QString,QString> Adresses;
    QMap<QString,QString>::const_iterator Iterator;
    static AdressManager *instance;
    explicit AdressManager(QObject *parent = nullptr);
public:
    static AdressManager *getInstance(void);
    void addAdress(QString name,QString adress);
    void editAdress(QString adress);
    void findAdress(QString name);
    void removeAdress(void);
    void nextAdress(void);
    void previousAdress(void);
    QPair<QString,QString> getCurrent(void);
    void exportToFile(QTextStream out);
    void importFromFile(QTextStream in);
signals:
    void nameAlreadyExist(void);
    void nameDosentExist(void);
};

#endif // ADRESSMANAGER_HPP
