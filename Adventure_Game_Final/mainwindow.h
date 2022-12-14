#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QStringListModel>
#include "map.h"
#include "area.h"
#include <vector>
#include "player.h"
#include "qlistwidget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void renderScene(Area);


private slots:
    void on_beginButton_clicked();

    void on_northBtn_clicked();

    void on_southBtn_clicked();

    void on_westBtn_clicked();

    void on_eastBtn_clicked();

    void on_quitBtn_clicked();

    void on_pushButton_9_clicked();

    void on_toGame_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_invBtn_clicked();

    void on_toGame_2_clicked();

    void on_invList_itemClicked(QListWidgetItem *item);

    void on_useBtn_clicked();

    void on_startBattle_clicked();

    void on_attack_clicked();

    void on_defend_clicked();

    void on_heavyAttack_clicked();

    void on_usePotion_clicked();

    void on_leaveBattle_clicked();

private:
    Ui::MainWindow *ui;
    Map gameMap;
    Area current;
    QVector<QString> journal;
    Player player;

    void accessArea(Area, Area);
};
#endif // MAINWINDOW_H
