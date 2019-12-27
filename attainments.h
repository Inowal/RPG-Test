#ifndef ATTAINMENTS_H
#define ATTAINMENTS_H

#include <QDialog>
#include <QCheckBox>
#include <QLabel>
#include <QSpinBox>

#include <string>

struct Attainment
{
  bool status = false;
  int level = 0;
};

namespace Ui {
const int numberAttainments = 18;
class Attainments;
}

class Attainments : public QDialog
{
  Q_OBJECT

public:
  class UiAttainment
  {
  public:
    QLabel *label;
    QCheckBox *checkBox;
    QSpinBox *spinBox;

    UiAttainment();
    UiAttainment(QWidget *currentWidget, std::string &currentAttainmentName, Attainment &currentAttainment, int x, int y);
  };

  explicit Attainments(Attainment attainments[Ui::numberAttainments], QWidget *parent = nullptr);
  ~Attainments();

  UiAttainment uiAttainments[Ui::numberAttainments];

private:
  Ui::Attainments *ui;
  std::string attainmentsNames[Ui::numberAttainments] = {"Акробатика (Лов)","Анализ (Инт)","Атлетика (Сил)",
                                                         "Внимательность (Мдр)","Выживание (Мдр)","Выступление (Хар)",
                                                         "Запугивание (Хар)","История (Инт)","Ловкость рук (Лов)",
                                                         "Магия (Инт)","Медицина (Мдр)","Обман (Хар)",
                                                         "Природа (Инт)","Проницательность (Мдр)","Религия (Инт)",
                                                         "Скрытность (Лов)","Убеждение (Хар)","Уход за животными (Мдр)"};

  void copyToUi();
  void copyFromUi();
};

#endif // ATTAINMENTS_H
