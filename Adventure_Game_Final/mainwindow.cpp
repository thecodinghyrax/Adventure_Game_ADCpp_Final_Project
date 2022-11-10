#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::createScene(){ // This is tempary to test
    Area temp;
    temp.setId("0");
    temp.setText("Dude, you have awoken in the middle of the night, startled by noise in the distance. You wait for a moment but there seems to be nothing there. Daylight is fast approaching. What is your command?");
    temp.setBackgroundFile(":/assets/bkg-camp.png");
    temp.setSearchResult("You have search all around and found nothing");
    gameMap.setArea(temp);
};

void MainWindow::renderScene(Area current){
    QPixmap bkg(current.getBackgroundFile().c_str());
    ui->bkgLabel->setPixmap(bkg);
    ui->descLabel->setText(current.getText().c_str());

};

void MainWindow::on_beginButton_clicked()
{
    //createScene(gameMap.getAreaById("0")); /// Testing
    current = gameMap.getAreaById("0"); // This is still a work in progress. Having some issue with loading the text file I believe //TODO fix

    renderScene(current);

    ui->stackedWidget->setCurrentIndex(1); // Index 1 will always be the location scene
}

