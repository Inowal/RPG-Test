#ifndef TEST_RPG_H
#define TEST_RPG_H

#include <QtTest/QtTest>
#include <QtGui>
#include <QObject>
#include "rpgmainwindow.h"
#include "ui_rpgmainwindow.h"

class Test_RPG : public QObject
{
  Q_OBJECT
private slots:
  void open();
  void save();
  void recreateSaveFileIfFileNotFound();
  void correctModifier();
};

#endif // TEST_RPG_H
