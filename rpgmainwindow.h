#ifndef DND_H
#define DND_H

#include "attainments.h"

#include <QTextEdit>
#include <QPushButton>
#include <QListWidget>
#include <QSet>
#include <QStringList>
#include <QWidget>
#include <QFileDialog>

#include <iostream>
#include <fstream>
#include <string>

namespace Ui {
class RPG;
}

class RPG : public QWidget
{
  Q_OBJECT

public:
  explicit RPG(QWidget *parent = nullptr);
  ~RPG();

  Ui::RPG* getUi();
  Attainments *a;

  bool getCurrentAttainment(int numberAttainment);

  void setCurrentAddress(std::string newAddress);

private:
  Ui::RPG *ui;

  //CharacterInfo currentCharacter;
  QListWidgetItem currentItem;
  Attainment currentAttainments[Ui::numberAttainments];

  void readList(std::ifstream &input, QListWidget *currentListWidget);
  void writeList(std::ofstream &output, QListWidget *currentListWidget);

  std::string currentAddress = "";

  QString chooseModifier(int i);

public slots:
  void addAttackNote();
  void addOtherNote();
  void addSkillsNote();
  void addEquipmentNote();
  void editCurrentItem(QListWidgetItem* currentItem);
  void deleteCurrentItem(QListWidgetItem* currentItem);

  void open();
  void save();
};

#endif // DND_H
