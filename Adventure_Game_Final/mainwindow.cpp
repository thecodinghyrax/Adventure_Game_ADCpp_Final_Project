#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "enemy.h"
#include "weapons.h"
#include "player.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // Setup stylesheet for widgets
    qApp->setStyleSheet("QListWidget::item:hover {color:red;}"
                        "QListWidget::item:selected {color:darkred;}"
                        "QListWidget::item {background-color:transparent; border:0px;}");
    ui->stackedWidget->setCurrentIndex(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::renderScene(Area current){
    QPixmap bkg(current.getBackgroundFile().c_str());
    ui->bkgLabel->setPixmap(bkg);
    ui->descLabel->setText(current.getText().c_str());
    ui->descLabel->adjustSize();
    ui->northBtn->setText("North");
    ui->southBtn->setText("South");
    ui->westBtn->setText("West");
    ui->eastBtn->setText("East");

};

void MainWindow::on_beginButton_clicked()
{

    current = gameMap.getAreaById("2"); // Base camp is Area "2"
    journal.push_back(current.getText().c_str());
    renderScene(current);

    ui->stackedWidget->setCurrentIndex(1); // Index 1 will always be the location scene

    // dont mind me
    Enemy testE;
    testE.pushEnemies();
    Weapon testW;
    testW.pushWeapons();
    Player testP;
    testP.pushPlayerStats();
}


void MainWindow::on_northBtn_clicked()
{
    std::string northId = current.getNorthArea();
    if(northId != "-1"){
        accessArea(current, gameMap.getAreaById(northId));
        journal.push_back(current.getText().c_str());
    } else {
        QString blocked = "Blocked";
        ui->northBtn->setText(blocked);
    }

}


void MainWindow::on_southBtn_clicked()
{
    std::string southId = current.getSouthArea();
    if(southId != "-1"){
        accessArea(current, gameMap.getAreaById(southId));
        journal.push_back(current.getText().c_str());
    } else {
        QString blocked = "Blocked";
        ui->southBtn->setText(blocked);
    }
}


void MainWindow::on_westBtn_clicked()
{
    std::string westId = current.getWestArea();
    if(westId != "-1"){
        accessArea(current, gameMap.getAreaById(westId));
        journal.push_back(current.getText().c_str());
    } else {
        QString blocked = "Blocked";
        ui->westBtn->setText(blocked);
    }
}


void MainWindow::on_eastBtn_clicked()
{
    std::string eastId = current.getEastArea();
    if(eastId != "-1"){
        accessArea(current, gameMap.getAreaById(eastId));
        journal.push_back(current.getText().c_str());
    } else {
        QString blocked = "Blocked";
        ui->eastBtn->setText(blocked);
    }
}


void MainWindow::on_quitBtn_clicked()
{
    QApplication::quit();
}


void MainWindow::on_pushButton_9_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}


void MainWindow::on_toGame_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_pushButton_6_clicked()
{
    ui->journalEntries->setModel(new QStringListModel(QList<QString>::fromVector(journal)));
    ui->stackedWidget->setCurrentIndex(2);
}


void MainWindow::on_pushButton_7_clicked()
{
    QString search = current.getSearchResult().c_str();
    ui->descLabel->setText(search);
    ui->descLabel->adjustSize();
    journal.push_back(search);
    if(current.getSearchItem().getName() != "No item"){
        player.giveItem(current.getSearchItem());
        journal.push_back(QString::fromStdString("You found a " + current.getSearchItem().getName() + ". You put it in your backpack."));
    }
}


void MainWindow::on_pushButton_8_clicked()
{
    QString camp = "You setup camp for the night and awake in the morning feeling refreshed!";
    ui->descLabel->setText(camp);
    ui->descLabel->adjustSize();
    journal.push_back(camp);
    // Health will be set back to 100
}

// Attempts to access an area
void MainWindow::accessArea(Area currentArea, Area destination)
{
    if (currentArea.getId() == "19" && destination.getId() == "24"){
        if(player.hasItemWithName("Old key")){
            current = destination;
            current.setText("You unlock the door using the key.\n" + current.getText());
            renderScene(current);
            return;
        } else {
            current.setText("You attempt to enter the castle, but the door is locked shut. You will need the key to open it.");
            renderScene(current);
            return;
        }
    }
    current = destination;
    renderScene(current);
    return;
}

void MainWindow::on_invBtn_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
    // Clear list and description label contents
    ui->invList->clear();
    ui->invItemDesc->setText("");
    // Create string list for list widget
    QStringList invStringList = QStringList();
    for (Item i : player.getInventory()){
        invStringList << QString::fromStdString(i.getName());
    }
    ui->invList->addItems(invStringList);
}


void MainWindow::on_toGame_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_invList_itemClicked(QListWidgetItem *item)
{
    QString descText = QString::fromStdString(player.getItemByName(item->text().toStdString()).getDescription());
    ui->invItemDesc->setText(descText);
}

