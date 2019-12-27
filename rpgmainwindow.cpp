#include "rpgmainwindow.h"
#include "ui_rpgmainwindow.h"

RPG::RPG(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::RPG)
{
  ui->setupUi(this);

  QObject::connect(ui->addAttackPushButton, SIGNAL(clicked()), this, SLOT(addAttackNote()));
  QObject::connect(ui->attackListWidget, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(editCurrentItem(QListWidgetItem*)));
  QObject::connect(ui->attackListWidget, SIGNAL(itemChanged(QListWidgetItem*)), this, SLOT(deleteCurrentItem(QListWidgetItem*)));

  QObject::connect(ui->addOtherPushButton, SIGNAL(clicked()), this, SLOT(addOtherNote()));
  QObject::connect(ui->otherListWidget, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(editCurrentItem(QListWidgetItem*)));
  QObject::connect(ui->otherListWidget, SIGNAL(itemChanged(QListWidgetItem*)), this, SLOT(deleteCurrentItem(QListWidgetItem*)));

  QObject::connect(ui->addSkillPushButton, SIGNAL(clicked()), this, SLOT(addSkillsNote()));
  QObject::connect(ui->skillsListWidget, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(editCurrentItem(QListWidgetItem*)));
  QObject::connect(ui->skillsListWidget, SIGNAL(itemChanged(QListWidgetItem*)), this, SLOT(deleteCurrentItem(QListWidgetItem*)));

  QObject::connect(ui->addEquipmentPushButton, SIGNAL(clicked()), this, SLOT(addEquipmentNote()));
  QObject::connect(ui->equipmentListWidget, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(editCurrentItem(QListWidgetItem*)));
  QObject::connect(ui->equipmentListWidget, SIGNAL(itemChanged(QListWidgetItem*)), this, SLOT(deleteCurrentItem(QListWidgetItem*)));

  QObject::connect(ui->openButton, &QPushButton::clicked, [this](){
    currentAddress = QFileDialog::getOpenFileName().toUtf8().toStdString();
    open();
  });
  QObject::connect(ui->saveButton, SIGNAL(clicked()), this, SLOT(save()));
  QObject::connect(ui->saveAsButton, &QPushButton::clicked, [this](){
    std::string newAddress = QFileDialog::getOpenFileName().toUtf8().toStdString();
    if (!newAddress.empty())
    {
      ui->saveButton->setEnabled(true);
      currentAddress = newAddress;
      save();
    }
  });

  QObject::connect(ui->strSpinBox, static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged), [this](int i){ui->strLineEdit->setText(chooseModifier(i));});
  QObject::connect(ui->dexSpinBox, static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged), [this](int i){ui->dexLineEdit->setText(chooseModifier(i));});
  QObject::connect(ui->conSpinBox, static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged), [this](int i){ui->conLineEdit->setText(chooseModifier(i));});
  QObject::connect(ui->intSpinBox, static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged), [this](int i){ui->intLineEdit->setText(chooseModifier(i));});
  QObject::connect(ui->wisSpinBox, static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged), [this](int i){ui->wisLineEdit->setText(chooseModifier(i));});
  QObject::connect(ui->chaSpinBox, static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged), [this](int i){ui->chaLineEdit->setText(chooseModifier(i));});

  QObject::connect(ui->dhSpinBox, static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged), [this](int i){ui->dhLineEdit->setText(QString::fromStdString("к"+std::to_string(i)));});

  QObject::connect(ui->attainmentsPushButton, &QPushButton::clicked, [this](){
    a = new Attainments(currentAttainments,this);
    a->show();
  });
}

RPG::~RPG()
{
  delete ui;
}

Ui::RPG* RPG::getUi()
{
  return ui;
}

bool RPG::getCurrentAttainment(int numberAttainment)
{
  return currentAttainments[numberAttainment].status;
}

void RPG::setCurrentAddress(std::string newAddress)
{
  currentAddress = newAddress;
}

void RPG::readList(std::ifstream &input, QListWidget *currentListWidget)
{
  int bufSize;
  std::string bufString;
  QStringList bufList;

  std::getline(input,bufString);
  bufSize = std::stoi(bufString);
  bufList.clear();
  for(int i = 0; i < bufSize; i++)
  {
    std::getline(input,bufString,'}');
    bufList << QString::fromStdString(bufString);
    std::getline(input,bufString);
  }

  currentListWidget->clear();
  currentListWidget->addItems(bufList);
}

void RPG::writeList(std::ofstream &output, QListWidget *currentListWidget)
{
  output << currentListWidget->count() << "\n";

  for(int i=0; i<currentListWidget->count(); i++)
  {
    output << currentListWidget->item(i)->text().toStdString() << "}\n";
  }
}

QString RPG::chooseModifier(int i)
{
  int currentModifier = (i/2-5);
  if (currentModifier > 0)
    return QString::fromStdString("+" + std::to_string(i/2-5));
  else
    return QString::fromStdString(std::to_string(i/2-5));
}

void RPG::addAttackNote()
{
  if (!(ui->attackTextEdit->toPlainText().trimmed().isEmpty()))
    ui->attackListWidget->addItem(ui->attackTextEdit->toPlainText().trimmed());
  ui->attackTextEdit->setText("");
}

void RPG::addOtherNote()
{
  if (!(ui->otherTextEdit->toPlainText().trimmed().isEmpty()))
    ui->otherListWidget->addItem(ui->otherTextEdit->toPlainText().trimmed());
  ui->otherTextEdit->setText("");
}

void RPG::addSkillsNote()
{
  if (!(ui->skillsTextEdit->toPlainText().trimmed().isEmpty()))
    ui->skillsListWidget->addItem(ui->skillsTextEdit->toPlainText().trimmed());
  ui->skillsTextEdit->setText("");
}

void RPG::addEquipmentNote()
{
  if (!(ui->equipmentTextEdit->toPlainText().trimmed().isEmpty()))
    ui->equipmentListWidget->addItem(ui->equipmentTextEdit->toPlainText().trimmed());
  ui->equipmentTextEdit->setText("");
}

void RPG::editCurrentItem(QListWidgetItem* currentItem)
{
  currentItem->setFlags(Qt::ItemIsEditable | Qt::ItemIsEnabled);
}

void RPG::deleteCurrentItem(QListWidgetItem* currentItem)
{
  if (currentItem->text().trimmed().isEmpty())
    delete currentItem;
}

void RPG::open()
{
  if (!currentAddress.empty())
  {
    ui->saveButton->setEnabled(true);

    std::ifstream input(currentAddress);
    std::string bufString;

    std::getline(input,bufString);
    ui->nameLineEdit->setText(QString::fromStdString(bufString));
    std::getline(input,bufString);
    ui->classLineEdit->setText(QString::fromStdString(bufString));
    std::getline(input,bufString);
    ui->levelSpinBox->setValue(std::stoi(bufString));
    std::getline(input,bufString);
    ui->raceLineEdit->setText(QString::fromStdString(bufString));
    std::getline(input,bufString);
    ui->prehistoryLineEdit->setText(QString::fromStdString(bufString));
    std::getline(input,bufString);
    ui->ideologyLineEdit->setText(QString::fromStdString(bufString));
    std::getline(input,bufString);
    ui->playerNameLineEdit->setText(QString::fromStdString(bufString));
    std::getline(input,bufString);
    ui->experienceSpinBox->setValue(std::stoi(bufString));
    std::getline(input,bufString);
    ui->ageSpinBox->setValue(std::stoi(bufString));
    std::getline(input,bufString);
    ui->eyesLineEdit->setText(QString::fromStdString(bufString));
    std::getline(input,bufString);
    ui->heightSpinBox->setValue(std::stoi(bufString));
    std::getline(input,bufString);
    ui->skinLineEdit->setText(QString::fromStdString(bufString));
    std::getline(input,bufString);
    ui->weightSpinBox->setValue(std::stoi(bufString));
    std::getline(input,bufString);
    ui->hairLineEdit->setText(QString::fromStdString(bufString));

    std::getline(input,bufString);
    ui->strSpinBox->setValue(std::stoi(bufString));
    std::getline(input,bufString);
    ui->dexSpinBox->setValue(std::stoi(bufString));
    std::getline(input,bufString);
    ui->conSpinBox->setValue(std::stoi(bufString));
    std::getline(input,bufString);
    ui->intSpinBox->setValue(std::stoi(bufString));
    std::getline(input,bufString);
    ui->wisSpinBox->setValue(std::stoi(bufString));
    std::getline(input,bufString);
    ui->chaSpinBox->setValue(std::stoi(bufString));

    std::getline(input,bufString);
    ui->proficiencyBonusSpinBox->setValue(std::stoi(bufString));
    std::getline(input,bufString);
    ui->passiveWisdomSpinBox->setValue(std::stoi(bufString));

    std::getline(input,bufString);
    ui->armorClassSpinBox->setValue(std::stoi(bufString));
    std::getline(input,bufString);
    ui->initiativeSpinBox->setValue(std::stoi(bufString));
    std::getline(input,bufString);
    ui->speedSpinBox->setValue(std::stoi(bufString));
    std::getline(input,bufString);
    ui->maxhpSpinBox->setValue(std::stoi(bufString));
    std::getline(input,bufString);
    ui->currenthpSpinBox->setValue(std::stoi(bufString));
    std::getline(input,bufString);
    ui->temporaryhpSpinBox->setValue(std::stoi(bufString));

    std::getline(input,bufString);
    ui->dhSpinBox->setValue(std::stoi(bufString));
    std::getline(input,bufString);
    ui->dhcSpinBox->setValue(std::stoi(bufString));

    std::getline(input,bufString,'}');
    ui->personalityTraitsTextEdit->setText(QString::fromStdString(bufString));
    std::getline(input,bufString);
    std::getline(input,bufString,'}');
    ui->idealsTextEdit->setText(QString::fromStdString(bufString));
    std::getline(input,bufString);
    std::getline(input,bufString,'}');
    ui->bondsTextEdit->setText(QString::fromStdString(bufString));
    std::getline(input,bufString);
    std::getline(input,bufString,'}');
    ui->flawsTextEdit->setText(QString::fromStdString(bufString));
    std::getline(input,bufString);

    std::getline(input,bufString);
    ui->copperSpinBox->setValue(std::stoi(bufString));
    std::getline(input,bufString);
    ui->silverSpinBox->setValue(std::stoi(bufString));
    std::getline(input,bufString);
    ui->electrumSpinBox->setValue(std::stoi(bufString));
    std::getline(input,bufString);
    ui->goldenSpinBox->setValue(std::stoi(bufString));
    std::getline(input,bufString);
    ui->platinumSpinBox->setValue(std::stoi(bufString));

    for(int i=0; i < Ui::numberAttainments; i++)
    {
      std::getline(input,bufString);
      if (std::stoi(bufString) == 1){
        currentAttainments[i].status = true;
      } else {
        currentAttainments[i].status = false;
      }
      std::getline(input,bufString);
      currentAttainments[i].level = std::stoi(bufString);
    }

    readList(input, ui->attackListWidget);
    readList(input, ui->otherListWidget);
    readList(input, ui->skillsListWidget);
    readList(input, ui->equipmentListWidget);

    input.close();
  }
}

void RPG::save()
{
  if (!currentAddress.empty())
  {
    std::ofstream output(currentAddress);

    output << ui->nameLineEdit->text().toStdString() << "\n";
    output << ui->classLineEdit->text().toStdString() << "\n";
    output << ui->levelSpinBox->value() << "\n";
    output << ui->raceLineEdit->text().toStdString() << "\n";
    output << ui->prehistoryLineEdit->text().toStdString() << "\n";
    output << ui->ideologyLineEdit->text().toStdString() << "\n";
    output << ui->playerNameLineEdit->text().toStdString() << "\n";
    output << ui->experienceSpinBox->value() << "\n";
    output << ui->ageSpinBox->value() << "\n";
    output << ui->eyesLineEdit->text().toStdString() << "\n";
    output << ui->heightSpinBox->value() << "\n";
    output << ui->skinLineEdit->text().toStdString() << "\n";
    output << ui->weightSpinBox->value() << "\n";
    output << ui->hairLineEdit->text().toStdString() << "\n";

    output << ui->strSpinBox->value() << "\n";
    output << ui->dexSpinBox->value() << "\n";
    output << ui->conSpinBox->value() << "\n";
    output << ui->intSpinBox->value() << "\n";
    output << ui->wisSpinBox->value() << "\n";
    output << ui->chaSpinBox->value() << "\n";

    output << ui->proficiencyBonusSpinBox->value() << "\n";
    output << ui->passiveWisdomSpinBox->value() << "\n";

    output << ui->armorClassSpinBox->value() << "\n";
    output << ui->initiativeSpinBox->value() << "\n";
    output << ui->speedSpinBox->value() << "\n";
    output << ui->maxhpSpinBox->value() << "\n";
    output << ui->currenthpSpinBox->value() << "\n";
    output << ui->temporaryhpSpinBox->value() << "\n";

    output << ui->dhSpinBox->value() << "\n";
    output << ui->dhcSpinBox->value() << "\n";

    output << ui->personalityTraitsTextEdit->toPlainText().toStdString() << "}\n";
    output << ui->idealsTextEdit->toPlainText().toStdString() << "}\n";
    output << ui->bondsTextEdit->toPlainText().toStdString() << "}\n";
    output << ui->flawsTextEdit->toPlainText().toStdString() << "}\n";

    output << ui->copperSpinBox->value() << "\n";
    output << ui->silverSpinBox->value() << "\n";
    output << ui->electrumSpinBox->value() << "\n";
    output << ui->goldenSpinBox->value() << "\n";
    output << ui->platinumSpinBox->value() << "\n";

    for(int i=0; i < Ui::numberAttainments; i++)
    {
      if (currentAttainments[i].status == true)
      {
        output << 1 << "\n";
      } else {
        output << 0 << "\n";
      }
      output << currentAttainments[i].level << "\n";
    }

    writeList(output, ui->attackListWidget);
    writeList(output, ui->otherListWidget);
    writeList(output, ui->skillsListWidget);
    writeList(output, ui->equipmentListWidget);

    output.close();
  }
}
