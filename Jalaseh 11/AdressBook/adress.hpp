#ifndef ADRESS_HPP
#define ADRESS_HPP

#include <QObject>

class Adress : public QObject
{
private:
    Q_OBJECT
    QString Name;
    QString AdressText;
public:
    explicit Adress(QString name,QString adress,QObject *parent = nullptr);
    const QString &getName() const;
    void setName(const QString &newName);
    const QString &getAdressText() const;
    void setAdressText(const QString &newAdressText);
};

#endif // ADRESS_HPP
