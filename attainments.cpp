#include "attainments.h"
#include "ui_attainments.h"

Attainments::UiAttainment::UiAttainment()
{
}

Attainments::UiAttainment::UiAttainment(QWidget *currentWidget, std::string &currentAttainmentName, Attainment &currentAttainment, int x, int y)
{
  QFont currentFont;

  label = new QLabel(currentWidget);
  label->setGeometry(x,y,191,21);
  label->setText(QString::fromStdString(currentAttainmentName));
  currentFont = label->font();
  currentFont.setPointSize(11);
  label->setFont(currentFont);
  checkBox = new QCheckBox(currentWidget);
  checkBox->setGeometry(x+200,y,16,21);
  checkBox->setText("");
  spinBox = new QSpinBox(currentWidget);
  spinBox->setGeometry(x+220,y,41,21);
  spinBox->setValue(0);
  currentFont = spinBox->font();
  currentFont.setPointSize(11);
  spinBox->setFont(currentFont);
  if (currentAttainment.status)
  {
    checkBox->setChecked(true);
    spinBox->setEnabled(true);
    spinBox->setValue(currentAttainment.level);
  } else {
    checkBox->setChecked(false);
    spinBox->setEnabled(false);
    spinBox->setValue(currentAttainment.level);
  }
  QObject::connect(checkBox, &QCheckBox::stateChanged, spinBox, &QSpinBox::setEnabled);
  QObject::connect(checkBox, &QCheckBox::stateChanged, [&currentAttainment](){currentAttainment.status = !currentAttainment.status;});
  QObject::connect(spinBox, static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged), [&currentAttainment](int i){currentAttainment.level = i;});
}

Attainments::Attainments(Attainment attainments[Ui::numberAttainments], QWidget *parent) :
  QDialog(parent),
  ui(new Ui::Attainments)
{
  ui->setupUi(this);
  for(int i=0; i < Ui::numberAttainments; i++)
  {
    uiAttainments[i] = UiAttainment(this, attainmentsNames[i], attainments[i], 10+270*(i/9), 10+30*(i%9));
  }
}

Attainments::~Attainments()
{
  delete ui;
}
