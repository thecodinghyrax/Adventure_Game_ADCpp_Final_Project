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


void MainWindow::on_pushButton_clicked()
{
    createScene();
    renderScene(scenes.at(0));
    ui->stackedWidget->setCurrentIndex(1); // Index 1 will always be the location scene
}

void MainWindow::createScene(){ // This is tempary to test
    Scene temp;
    temp.setDescription("Dude, you have awoken in the middle of the night, startled by noise in the distance. You wait for a moment but there seems to be nothing there. Daylight is fast approaching. What is your command?");
    temp.setImage(":/assests/bkg-camp.png");
    temp.setSearchResult("You have search all around and found nothing");
    scenes.push_back(temp);
};

void MainWindow::renderScene(Scene current){
    QPixmap bkg(current.getImage().c_str());
    ui->bkgLabel->setPixmap(bkg);
    ui->descLabel->setText(current.getDescription().c_str());
};
