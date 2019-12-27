#include "test_rpg.h"

void Test_RPG::open()
{
  RPG testingRPG;

  testingRPG.setCurrentAddress("./test_data.txt");
  testingRPG.open();

  QCOMPARE(testingRPG.getUi()->nameLineEdit->text(), QString("Тестингов"));
  QCOMPARE(testingRPG.getUi()->classLineEdit->text(), QString("Кодер"));
  QCOMPARE(testingRPG.getUi()->levelSpinBox->value(), 2);
  QCOMPARE(testingRPG.getUi()->raceLineEdit->text(), QString("Сеньор"));
  QCOMPARE(testingRPG.getUi()->prehistoryLineEdit->text(), QString("Грузчик"));
  QCOMPARE(testingRPG.getUi()->ideologyLineEdit->text(), QString("Злой"));
  QCOMPARE(testingRPG.getUi()->playerNameLineEdit->text(), QString("Линус"));
  QCOMPARE(testingRPG.getUi()->experienceSpinBox->value(), 5000);
  QCOMPARE(testingRPG.getUi()->ageSpinBox->value(), 49);
  QCOMPARE(testingRPG.getUi()->eyesLineEdit->text(), QString("Синие"));
  QCOMPARE(testingRPG.getUi()->heightSpinBox->value(), 183);
  QCOMPARE(testingRPG.getUi()->skinLineEdit->text(), QString("Белая"));
  QCOMPARE(testingRPG.getUi()->weightSpinBox->value(), 94);
  QCOMPARE(testingRPG.getUi()->hairLineEdit->text(), QString("Русые"));

  QCOMPARE(testingRPG.getUi()->strSpinBox->value(), 2);
  QCOMPARE(testingRPG.getUi()->dexSpinBox->value(), 7);
  QCOMPARE(testingRPG.getUi()->conSpinBox->value(), 4);
  QCOMPARE(testingRPG.getUi()->intSpinBox->value(), 19);
  QCOMPARE(testingRPG.getUi()->wisSpinBox->value(), 14);
  QCOMPARE(testingRPG.getUi()->chaSpinBox->value(), 9);

  QCOMPARE(testingRPG.getUi()->proficiencyBonusSpinBox->value(), 8);
  QCOMPARE(testingRPG.getUi()->passiveWisdomSpinBox->value(), 15);

  QCOMPARE(testingRPG.getUi()->armorClassSpinBox->value(), 50);
  QCOMPARE(testingRPG.getUi()->initiativeSpinBox->value(), 12);
  QCOMPARE(testingRPG.getUi()->speedSpinBox->value(), 35);
  QCOMPARE(testingRPG.getUi()->maxhpSpinBox->value(), 30);
  QCOMPARE(testingRPG.getUi()->currenthpSpinBox->value(), 30);
  QCOMPARE(testingRPG.getUi()->temporaryhpSpinBox->value(), 20);

  QCOMPARE(testingRPG.getUi()->dhSpinBox->value(), 7);
  QCOMPARE(testingRPG.getUi()->dhcSpinBox->value(), 3);

  QCOMPARE(testingRPG.getUi()->personalityTraitsTextEdit->toPlainText(), QString("Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua."));
  QCOMPARE(testingRPG.getUi()->idealsTextEdit->toPlainText(), QString("Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur."));
  QCOMPARE(testingRPG.getUi()->bondsTextEdit->toPlainText(), QString("Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat."));
  QCOMPARE(testingRPG.getUi()->flawsTextEdit->toPlainText(), QString("Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum."));

  QCOMPARE(testingRPG.getUi()->copperSpinBox->value(), 5);
  QCOMPARE(testingRPG.getUi()->silverSpinBox->value(), 7);
  QCOMPARE(testingRPG.getUi()->electrumSpinBox->value(), 0);
  QCOMPARE(testingRPG.getUi()->goldenSpinBox->value(), 67);
  QCOMPARE(testingRPG.getUi()->platinumSpinBox->value(), 0);

  QCOMPARE(testingRPG.getCurrentAttainment(0), false);
  QCOMPARE(testingRPG.getCurrentAttainment(1), false);
  QCOMPARE(testingRPG.getCurrentAttainment(2), false);
  QCOMPARE(testingRPG.getCurrentAttainment(3), true);
  QCOMPARE(testingRPG.getCurrentAttainment(4), false);
  QCOMPARE(testingRPG.getCurrentAttainment(5), false);
  QCOMPARE(testingRPG.getCurrentAttainment(6), false);
  QCOMPARE(testingRPG.getCurrentAttainment(7), true);
  QCOMPARE(testingRPG.getCurrentAttainment(8), false);
  QCOMPARE(testingRPG.getCurrentAttainment(9), false);
  QCOMPARE(testingRPG.getCurrentAttainment(10), false);
  QCOMPARE(testingRPG.getCurrentAttainment(11), false);
  QCOMPARE(testingRPG.getCurrentAttainment(12), false);
  QCOMPARE(testingRPG.getCurrentAttainment(13), false);
  QCOMPARE(testingRPG.getCurrentAttainment(14), false);
  QCOMPARE(testingRPG.getCurrentAttainment(15), false);
  QCOMPARE(testingRPG.getCurrentAttainment(16), false);
  QCOMPARE(testingRPG.getCurrentAttainment(17), false);

  QCOMPARE(testingRPG.getUi()->attackListWidget->item(0)->text(), QString("Ударить клавиатурой"));
  QCOMPARE(testingRPG.getUi()->attackListWidget->item(1)->text(), QString("Удалить исходники"));
  QCOMPARE(testingRPG.getUi()->attackListWidget->item(2)->text(), QString("Функция magic"));

  QCOMPARE(testingRPG.getUi()->otherListWidget->item(0)->text(), QString("Два монитора"));
  QCOMPARE(testingRPG.getUi()->otherListWidget->item(1)->text(), QString("C++"));
  QCOMPARE(testingRPG.getUi()->otherListWidget->item(2)->text(), QString("Java"));
  QCOMPARE(testingRPG.getUi()->otherListWidget->item(3)->text(), QString("Ada"));
  QCOMPARE(testingRPG.getUi()->otherListWidget->item(4)->text(), QString("Шумерский"));
  QCOMPARE(testingRPG.getUi()->otherListWidget->item(5)->text(), QString("Линейное письмо А"));

  QCOMPARE(testingRPG.getUi()->skillsListWidget->item(0)->text(), QString("С кофе сотрудник может работать 48 часов подряд"));
  QCOMPARE(testingRPG.getUi()->skillsListWidget->item(1)->text(), QString("Самоучка"));
  QCOMPARE(testingRPG.getUi()->skillsListWidget->item(2)->text(), QString("Задушил таракана шнуром от мыши"));

  QCOMPARE(testingRPG.getUi()->equipmentListWidget->item(0)->text(), QString("Рюкзак"));
  QCOMPARE(testingRPG.getUi()->equipmentListWidget->item(1)->text(), QString("Ноутбук"));
}

void Test_RPG::save()
{
  RPG testingRPG1;

  QTest::keyClicks(testingRPG1.getUi()->nameLineEdit, "Benchmarkov");

  QTest::keyClick(testingRPG1.getUi()->ageSpinBox, Qt::Key_Enter);
  QTest::keyClicks(testingRPG1.getUi()->ageSpinBox, "25");

  QTest::keyClick(testingRPG1.getUi()->chaSpinBox, Qt::Key_Enter);
  QTest::keyClicks(testingRPG1.getUi()->chaSpinBox, "16");

  QTest::keyClick(testingRPG1.getUi()->proficiencyBonusSpinBox, Qt::Key_Enter);
  QTest::keyClicks(testingRPG1.getUi()->proficiencyBonusSpinBox, "3");

  QTest::keyClick(testingRPG1.getUi()->speedSpinBox, Qt::Key_Enter);
  QTest::keyClicks(testingRPG1.getUi()->speedSpinBox, "20");

  QTest::keyClick(testingRPG1.getUi()->dhSpinBox, Qt::Key_Enter);
  QTest::keyClicks(testingRPG1.getUi()->dhSpinBox, "4");

  QTest::keyClicks(testingRPG1.getUi()->idealsTextEdit, QString("Manual test in ideals."));

  QTest::keyClick(testingRPG1.getUi()->silverSpinBox, Qt::Key_Enter);
  QTest::keyClicks(testingRPG1.getUi()->silverSpinBox, "4");

  QTest::mouseClick(testingRPG1.getUi()->attainmentsPushButton, Qt::LeftButton);
  QTest::mouseClick(testingRPG1.a->uiAttainments[9].checkBox, Qt::LeftButton);

  QTest::keyClicks(testingRPG1.getUi()->otherTextEdit, "Reinstalled Windows");
  QTest::mouseClick(testingRPG1.getUi()->addOtherPushButton, Qt::LeftButton);

  testingRPG1.setCurrentAddress("test_saving.txt");
  testingRPG1.save();

  RPG testingRPG2;

  testingRPG2.setCurrentAddress("test_saving.txt");
  testingRPG2.open();

  QCOMPARE(testingRPG2.getUi()->nameLineEdit->text(), QString("Benchmarkov"));

  QCOMPARE(testingRPG2.getUi()->ageSpinBox->value(), 25);

  QCOMPARE(testingRPG2.getUi()->chaSpinBox->value(), 16);

  QCOMPARE(testingRPG2.getUi()->proficiencyBonusSpinBox->value(), 3);

  QCOMPARE(testingRPG2.getUi()->speedSpinBox->value(), 20);

  QCOMPARE(testingRPG2.getUi()->dhSpinBox->value(), 4);

  QCOMPARE(testingRPG2.getUi()->idealsTextEdit->toPlainText(), QString("Manual test in ideals."));

  QCOMPARE(testingRPG2.getUi()->silverSpinBox->value(), 4);

  QCOMPARE(testingRPG2.getCurrentAttainment(9), true);

  QCOMPARE(testingRPG2.getUi()->otherListWidget->item(0)->text(), QString("Reinstalled Windows"));
}

void Test_RPG::recreateSaveFileIfFileNotFound()
{
  RPG testingRPG1;

  testingRPG1.setCurrentAddress("./test_data.txt");
  testingRPG1.open();

  testingRPG1.setCurrentAddress("./test_data_not_found.txt");

  testingRPG1.save();

  RPG testingRPG2;
  testingRPG2.setCurrentAddress("./test_data_not_found.txt");
  testingRPG2.open();

  QCOMPARE(testingRPG2.getUi()->nameLineEdit->text(), QString("Тестингов"));
  QCOMPARE(testingRPG2.getUi()->classLineEdit->text(), QString("Кодер"));
  QCOMPARE(testingRPG2.getUi()->levelSpinBox->value(), 2);
  QCOMPARE(testingRPG2.getUi()->raceLineEdit->text(), QString("Сеньор"));
  QCOMPARE(testingRPG2.getUi()->prehistoryLineEdit->text(), QString("Грузчик"));
  QCOMPARE(testingRPG2.getUi()->ideologyLineEdit->text(), QString("Злой"));
  QCOMPARE(testingRPG2.getUi()->playerNameLineEdit->text(), QString("Линус"));
  QCOMPARE(testingRPG2.getUi()->experienceSpinBox->value(), 5000);
  QCOMPARE(testingRPG2.getUi()->ageSpinBox->value(), 49);
  QCOMPARE(testingRPG2.getUi()->eyesLineEdit->text(), QString("Синие"));
  QCOMPARE(testingRPG2.getUi()->heightSpinBox->value(), 183);
  QCOMPARE(testingRPG2.getUi()->skinLineEdit->text(), QString("Белая"));
  QCOMPARE(testingRPG2.getUi()->weightSpinBox->value(), 94);
  QCOMPARE(testingRPG2.getUi()->hairLineEdit->text(), QString("Русые"));

  QCOMPARE(testingRPG2.getUi()->strSpinBox->value(), 2);
  QCOMPARE(testingRPG2.getUi()->dexSpinBox->value(), 7);
  QCOMPARE(testingRPG2.getUi()->conSpinBox->value(), 4);
  QCOMPARE(testingRPG2.getUi()->intSpinBox->value(), 19);
  QCOMPARE(testingRPG2.getUi()->wisSpinBox->value(), 14);
  QCOMPARE(testingRPG2.getUi()->chaSpinBox->value(), 9);

  QCOMPARE(testingRPG2.getUi()->proficiencyBonusSpinBox->value(), 8);
  QCOMPARE(testingRPG2.getUi()->passiveWisdomSpinBox->value(), 15);

  QCOMPARE(testingRPG2.getUi()->armorClassSpinBox->value(), 50);
  QCOMPARE(testingRPG2.getUi()->initiativeSpinBox->value(), 12);
  QCOMPARE(testingRPG2.getUi()->speedSpinBox->value(), 35);
  QCOMPARE(testingRPG2.getUi()->maxhpSpinBox->value(), 30);
  QCOMPARE(testingRPG2.getUi()->currenthpSpinBox->value(), 30);
  QCOMPARE(testingRPG2.getUi()->temporaryhpSpinBox->value(), 20);

  QCOMPARE(testingRPG2.getUi()->dhSpinBox->value(), 7);
  QCOMPARE(testingRPG2.getUi()->dhcSpinBox->value(), 3);

  QCOMPARE(testingRPG2.getUi()->personalityTraitsTextEdit->toPlainText(), QString("Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua."));
  QCOMPARE(testingRPG2.getUi()->idealsTextEdit->toPlainText(), QString("Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur."));
  QCOMPARE(testingRPG2.getUi()->bondsTextEdit->toPlainText(), QString("Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat."));
  QCOMPARE(testingRPG2.getUi()->flawsTextEdit->toPlainText(), QString("Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum."));

  QCOMPARE(testingRPG2.getUi()->copperSpinBox->value(), 5);
  QCOMPARE(testingRPG2.getUi()->silverSpinBox->value(), 7);
  QCOMPARE(testingRPG2.getUi()->electrumSpinBox->value(), 0);
  QCOMPARE(testingRPG2.getUi()->goldenSpinBox->value(), 67);
  QCOMPARE(testingRPG2.getUi()->platinumSpinBox->value(), 0);

  QCOMPARE(testingRPG2.getCurrentAttainment(0), false);
  QCOMPARE(testingRPG2.getCurrentAttainment(1), false);
  QCOMPARE(testingRPG2.getCurrentAttainment(2), false);
  QCOMPARE(testingRPG2.getCurrentAttainment(3), true);
  QCOMPARE(testingRPG2.getCurrentAttainment(4), false);
  QCOMPARE(testingRPG2.getCurrentAttainment(5), false);
  QCOMPARE(testingRPG2.getCurrentAttainment(6), false);
  QCOMPARE(testingRPG2.getCurrentAttainment(7), true);
  QCOMPARE(testingRPG2.getCurrentAttainment(8), false);
  QCOMPARE(testingRPG2.getCurrentAttainment(9), false);
  QCOMPARE(testingRPG2.getCurrentAttainment(10), false);
  QCOMPARE(testingRPG2.getCurrentAttainment(11), false);
  QCOMPARE(testingRPG2.getCurrentAttainment(12), false);
  QCOMPARE(testingRPG2.getCurrentAttainment(13), false);
  QCOMPARE(testingRPG2.getCurrentAttainment(14), false);
  QCOMPARE(testingRPG2.getCurrentAttainment(15), false);
  QCOMPARE(testingRPG2.getCurrentAttainment(16), false);
  QCOMPARE(testingRPG2.getCurrentAttainment(17), false);

  QCOMPARE(testingRPG2.getUi()->attackListWidget->item(0)->text(), QString("Ударить клавиатурой"));
  QCOMPARE(testingRPG2.getUi()->attackListWidget->item(1)->text(), QString("Удалить исходники"));
  QCOMPARE(testingRPG2.getUi()->attackListWidget->item(2)->text(), QString("Функция magic"));

  QCOMPARE(testingRPG2.getUi()->otherListWidget->item(0)->text(), QString("Два монитора"));
  QCOMPARE(testingRPG2.getUi()->otherListWidget->item(1)->text(), QString("C++"));
  QCOMPARE(testingRPG2.getUi()->otherListWidget->item(2)->text(), QString("Java"));
  QCOMPARE(testingRPG2.getUi()->otherListWidget->item(3)->text(), QString("Ada"));
  QCOMPARE(testingRPG2.getUi()->otherListWidget->item(4)->text(), QString("Шумерский"));
  QCOMPARE(testingRPG2.getUi()->otherListWidget->item(5)->text(), QString("Линейное письмо А"));

  QCOMPARE(testingRPG2.getUi()->skillsListWidget->item(0)->text(), QString("С кофе сотрудник может работать 48 часов подряд"));
  QCOMPARE(testingRPG2.getUi()->skillsListWidget->item(1)->text(), QString("Самоучка"));
  QCOMPARE(testingRPG2.getUi()->skillsListWidget->item(2)->text(), QString("Задушил таракана шнуром от мыши"));

  QCOMPARE(testingRPG2.getUi()->equipmentListWidget->item(0)->text(), QString("Рюкзак"));
  QCOMPARE(testingRPG2.getUi()->equipmentListWidget->item(1)->text(), QString("Ноутбук"));
}

void Test_RPG::correctModifier()
{
  RPG testingRPG;

  QTest::keyClick(testingRPG.getUi()->dexSpinBox, Qt::Key_Enter);
  QTest::keyClicks(testingRPG.getUi()->dexSpinBox, "20");
  QCOMPARE(testingRPG.getUi()->dexLineEdit->text(), QString("+5"));

  QTest::keyClick(testingRPG.getUi()->chaSpinBox, Qt::Key_Enter);
  QTest::keyClicks(testingRPG.getUi()->chaSpinBox, "3");
  QCOMPARE(testingRPG.getUi()->chaLineEdit->text(), QString("-4"));

  QTest::keyClick(testingRPG.getUi()->strSpinBox, Qt::Key_Enter);
  QTest::keyClicks(testingRPG.getUi()->strSpinBox, "11");
  QCOMPARE(testingRPG.getUi()->strLineEdit->text(), QString("0"));

  QTest::keyClick(testingRPG.getUi()->chaSpinBox, Qt::Key_Enter);
  QTest::keyClicks(testingRPG.getUi()->chaSpinBox, "6");
  QCOMPARE(testingRPG.getUi()->chaLineEdit->text(), QString("-2"));
}

QTEST_MAIN(Test_RPG)
