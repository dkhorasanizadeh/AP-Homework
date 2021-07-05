#include "adressmanager.hpp"
AdressManager *AdressManager::instance = nullptr;
AdressManager::AdressManager(QObject *parent) : QObject(parent) {
  Iterator = Adresses.cbegin();
  importFromFile("./data.json");
}

AdressManager *AdressManager::getInstance() {
  if (instance == nullptr) {
    instance = new AdressManager();
  }
  return instance;
}

void AdressManager::addAdress(QString name, QString adress) {
  if (Adresses.contains(name)) {
    emit nameAlreadyExist();
    return;
  }
  Adresses.insert(Adresses.cend(), name, adress);
  Iterator = Adresses.cend();
  Iterator--;
  exportToFile("./data.phonebook");
}

void AdressManager::editAdress(QString adress) {
  Adresses[Iterator.key()] = adress;
  exportToFile("./data.phonebook");
}

void AdressManager::findAdress(QString name) {
  if (!Adresses.contains(name)) {
    emit nameDosentExist();
    return;
  }
  Iterator = Adresses.find(name);
}

void AdressManager::removeAdress(void) {
  if (Adresses.cbegin() != Adresses.cend()) {
    QMap<QString, QString>::const_iterator toRemove = Iterator;
    nextAdress();
    Adresses.remove(toRemove.key());
  }
  exportToFile("./data.phonebook");
}

void AdressManager::nextAdress() {
  if (Adresses.cbegin() != Adresses.cend()) {
    QMap<QString, QString>::const_iterator current = Iterator;
    if (current == Adresses.cbegin()) {
      Iterator = Adresses.cend();
    }
    Iterator--;
  }
}

void AdressManager::previousAdress() {
  if (Adresses.cbegin() != Adresses.cend()) {
    QMap<QString, QString>::const_iterator current = Iterator;
    if (++current == Adresses.cend()) {
      Iterator = Adresses.cbegin();
      return;
    }
    Iterator++;
  }
}

QPair<QString, QString> AdressManager::getCurrent() {
  if (Adresses.cbegin() != Adresses.cend()) {
    QPair<QString, QString> name_adress;
    name_adress.first = Iterator.key();
    name_adress.second = Iterator.value();
    return name_adress;
  } else {
    QPair<QString, QString> name_adress;
    name_adress.first = "";
    name_adress.second = "";
    return name_adress;
  }
}

void AdressManager::exportToFile(QString fileName) {
  QFile file(fileName);
  if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
    return;
  }
  QMap<QString, QString>::const_iterator current = Adresses.cbegin();
  QJsonArray adresses;
  while (current != Adresses.cend()) {
    QJsonObject adress;
    adress["name"] = current.key();
    adress["adress"] = current.value();
    adresses.append(adress);
    current++;
  }
  QJsonObject json;
  json["adresses"] = adresses;
  QJsonDocument saveJson(json);
  file.write(saveJson.toJson());
  file.close();
}

void AdressManager::importFromFile(QString fileName) {
  QFile file(fileName);
  if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
    return;
  }
  QJsonArray adresses =
      QJsonDocument::fromJson(file.readAll()).object()["adresses"].toArray();
  Adresses.clear();
  foreach (QJsonValue value, adresses) {
    QJsonObject adress = value.toObject();
    addAdress(adress["name"].toString(), adress["adress"].toString());
  }
  previousAdress();
  file.close();
}
