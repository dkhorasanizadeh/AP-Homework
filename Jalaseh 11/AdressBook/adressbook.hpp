#ifndef ADRESSBOOK_HPP
#define ADRESSBOOK_HPP

#include <QObject>

class AdressBook : public QObject
{
    Q_OBJECT
public:
    explicit AdressBook(QObject *parent = nullptr);

signals:

};

#endif // ADRESSBOOK_HPP
