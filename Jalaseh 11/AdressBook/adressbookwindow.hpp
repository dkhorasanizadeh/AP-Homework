#ifndef ADRESSBOOKWINDOW_HPP
#define ADRESSBOOKWINDOW_HPP

#include <QMainWindow>
#include <QGridLayout>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QTextEdit>
#include <QFileDialog>
#include <QFile>
#include <QMessageBox>
#include <QInputDialog>
#include <QTextStream>
#include "adressmanager.hpp"

class AdressBookWindow : public QMainWindow
{
private:
    Q_OBJECT
    enum State{
        View,
        Add,
        Edit
    };
    QWidget *CentralWidget;
    QGridLayout *Grid;
    QLabel *NameLabel;
    QLabel *AdressLabel;
    QLineEdit *NameLineEdit;
    QTextEdit *AdressTextEdit;
    QPushButton *AddButton;
    QPushButton *EditButton;
    QPushButton *SaveButton;
    QPushButton *RemoveButton;
    QPushButton *FindButton;
    QPushButton *ImportButton;
    QPushButton *ExportButton;
    QPushButton *NextButton;
    QPushButton *PreviousButton;
    void showCurrent(void);
    AdressManager *manager=AdressManager::getInstance();
    State state;
    AdressBookWindow(QWidget *parent = nullptr);
    static AdressBookWindow *Instance;
public:
    static AdressBookWindow *getInstance();
    ~AdressBookWindow();
public slots:
    void AddButtonPressed(void);
    void SaveButtonPressed(void);
    void EditButtonPressed(void);
    void RemoveButtonPressed(void);
    void FindButtonPressed(void);
    void ImportButtonPressed(void);
    void ExportButtonPressed(void);
    void NextButtonPressed(void);
    void PreviousButtonPressed(void);
    void alertNameDosentExist(void);
    void alertNameExist(void);
};
#endif // ADRESSBOOKWINDOW_HPP
