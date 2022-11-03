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
    renderScene(areas.at(0));
    ui->stackedWidget->setCurrentIndex(1); // Index 1 will always be the location scene
}

void MainWindow::createScene(){ // This is tempary to test
    Area temp;
    temp.setText("Dude, you have awoken in the middle of the night, startled by noise in the distance. You wait for a moment but there seems to be nothing there. Daylight is fast approaching. What is your command?");
    temp.setBackgroundFile(":/assests/bkg-camp.png");
    temp.setSearchResult("You have search all around and found nothing");
    areas.push_back(temp);
};

void MainWindow::renderScene(Area current){
    QPixmap bkg(current.getBackgroundFile().c_str());
    ui->bkgLabel->setPixmap(bkg);
    ui->descLabel->setText(current.getText().c_str());
};
