#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "enemy.h"
#include "weapons.h"
#include "player.h"
#include "battle.h"


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
    ui->currentPotionsLabel->setText(QString::fromStdString(std::to_string(player.getHealthPotions())));
    ui->currentHealthLabel->setText(QString::fromStdString(std::to_string(player.getPlayerHealth())));
};

void MainWindow::on_beginButton_clicked()
{

    current = gameMap.getAreaById("2"); // Base camp is Area "2"
    journal.push_back(current.getText().c_str());
    renderScene(current);

    ui->stackedWidget->setCurrentIndex(1); // Index 1 will always be the location scene

    // dont mind me
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
    if(current.getSearchItem().getName() != "No item" && !current.hasBeenSearched()){
        player.giveItem(current.getSearchItem());
        journal.push_back(QString::fromStdString("You found a " + current.getSearchItem().getName() + ". You put it in your backpack."));
        current.setSearched(true);
        gameMap.setAreaSearched(current.getId());
    }
    if(current.getId() == "16"){
        player.setHealthPotions(player.getHealthPotions() + 4);
    }
}


void MainWindow::on_pushButton_8_clicked()
{
    QString camp = "You setup camp for the night and awake in the morning feeling refreshed!";
    ui->descLabel->setText(camp);
    ui->descLabel->adjustSize();
    journal.push_back(camp);
    player.setPlayerHealth(100);
    ui->currentHealthLabel->setText(QString::fromStdString(std::to_string(player.getPlayerHealth())));
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


void MainWindow::on_useBtn_clicked()
{
    // If no item is selected, do nothing
    if (!ui->invList->selectedItems().empty()){
        QString selectedItemName = ui->invList->selectedItems()[0]->text();
        ui->stackedWidget->setCurrentIndex(1);
        if (selectedItemName == "Fishing rod" && current.getId() == "7"){
            player.giveItem(Item("Raw fish","An uncooked fish.","NoImage",true,5));
            current.setText("You fish for a while and catch something!");
            journal.push_back(QString::fromStdString(current.getText()));
            renderScene(current);
            return;
        }
        if (selectedItemName == "Raw fish" && current.getId() == "16"){
            player.setHealthPotions(player.getHealthPotions() + 1);
            player.takeItem("Raw fish");
            current.setText("You use materials you find in the cottage and the fish to craft a disgusting but effective health potion.");
            journal.push_back(QString::fromStdString(current.getText()));
            renderScene(current);
            return;
        }
        if (selectedItemName == "Woodcutter's axe"){
            if (current.getId() == "1" || current.getId() == "3" || current.getId() == "6" || current.getId() == "12" ||
                    current.getId() == "13" || current.getId() == "14" || current.getId() == "18"){
                for(auto item : player.getInventory()){
                    if(item.getName() == "Cut log"){
                        player.takeItem("Cut log");
                    }
                }
                player.giveItem(Item("Cut log","A log cut from a tree.","NoImage",true,5));
                current.setText("You cut down a nearby tree a get a log.");
                journal.push_back(QString::fromStdString(current.getText()));
                renderScene(current);
                return;
            }
        }
        if (selectedItemName == "Cut log" && current.getId() == "10"){
            player.takeItem("Cut log");
            player.giveItem(Item("Cooked steak","A cooked steak, medium-rare.","NoImage",false,0));
            current.setText("You give the man a log and ask him to make you a stake. He takes it and goes into his hut. He returns a while later and hands you a big, mouth-watering steak.");
            journal.push_back(QString::fromStdString(current.getText()));
            renderScene(current);
            return;
        }
        if (selectedItemName == "Cooked steak" && current.getId() == "10"){
            player.takeItem("Cooked steak");
            player.giveItem(Item("Wooden stake","A stake, useful for killing vampires or pitching a tent.","NoImage",false,0));
            current.setText("You explain to the man that you meant a wooden stake. He apologizes for his miSTAKE and goes back into his hut. He returns with a carved wooden stake.");
            journal.push_back(QString::fromStdString(current.getText()));
            renderScene(current);
            return;
        }


        // If the item cannot be used, give default message
        current.setText("Nothing interesting happens.");
        renderScene(current);
    }

}

Battle ex;

void MainWindow::on_startBattle_clicked()
{

    ui->stackedWidget->setCurrentIndex(5);
    QPixmap bkg(current.getBackgroundFile().c_str());
    ui->bkgLabel_2->setPixmap(bkg);

    if (current.getId() == "39") {

        Enemy boss;
        Weapon bossWeapon;
        boss.pushBoss();
        bossWeapon.pushBossWeapon();
        ex.setEnemies(boss.enemyVector);
        ex.setWeapons(bossWeapon.weaponVector);
        ui->progressBar_3->setMaximum(400);

    }
    else {

        Enemy testE;
        testE.pushEnemies();
        Weapon testW;
        testW.pushWeapons();
        ex.setEnemies(testE.enemyVector);
        ex.setWeapons(testW.weaponVector);
        if (ui->progressBar_3->maximum() != 100) {

            ui->progressBar_3->setMaximum(100);

        }

    }

    //ex.createPlayer(); boss room id is 39
    ex.setEnemy();
    ex.setWeapon();
    ex.setPlayerTemp();
    ex.setEnemyTemp();
    ex.setEnemyType();
    ex.setEnemyWeaponType();
    ex.playerTempHP = player.getPlayerHealth();

    ui->progressBar_3->setValue(ex.enemyTempHP);

    std::string eName = ex.enemyType;
    std::string wName = ex.enemyWeaponType;

    QString openingText;

    if (current.getId() == "39") {

        openingText = QString::fromStdString("In the darkness of the throne room, the torch light seems to highlight the elongated canines of the man's wicked smile. A vampire. Noticing your realization, the man's smile only grows and his right hand starts to glow a ghastly crimson hue.");

    }
    else {

        openingText = QString::fromStdString("Before you stands a " + eName + " readying their " + wName + ". You only have a moment to react, what do you do?");

    }

    ui->label_6->setText(openingText);
    ui->progressBar_2->setValue(ex.playerTempHP);
}

void MainWindow::on_attack_clicked()
{
    bool testDef = ex.isEnemyDefending();
    ex.playerAttack();
    int val = ui->progressBar_3->value();
    int dmg = val - ex.enemyTempHP;
    int hpRem = val - dmg;
    ui->progressBar_3->setValue(hpRem);

    ex.enemyTurn();
    int val2 = ui->progressBar_2->value();
    int dmg2 = val2 - ex.playerTempHP;
    int hpRem2 = val2 - dmg2;
    ui->progressBar_2->setValue(hpRem2);
    bool testDef2 = ex.isEnemyDefending();

    QString text;

    if (hpRem <= 0) {
        ui->progressBar_3->setValue(0);

        if (current.getId() == "39" && player.hasItemWithName("Hammer") && player.hasItemWithName("Wooden stake")) {

            text = QString::fromStdString("Your aim is true, the vampire collapses to the ground, unmoving. Keeping your weapon raised, you walk to the side of the downed vampire. You notice the flesh of the vampire regenerating and the wounds closing. With no hesitation you take the wooden stake and hammer from your pack, and hammer the stake into his heart. With a cry and a twitch, the vampire begins to wither and turn to dust...");

        }
        else if (current.getId() == "39") {

            text = QString::fromStdString("Your aim is true, the vampire collapses to the ground, unmoving. Keeping your weapon raised, you walk to the side of the downed vampire. You notice the flesh of the vampire regenerating and the wounds closing. You stab the vampire again, but the wound closes in seconds. You realize that you do not have what it needs to kill the vampire for good.");

        }
        else {

            text = QString::fromStdString("Your aim is true, your foe falls to the ground lifeless. This battle is won...(Use the leave button to exit the battle)");

        }



    }
    else if (hpRem2 <= 0) {
        ui->progressBar_2->setValue(0);

        if (current.getId() == "39") {

            text = QString::fromStdString("You collapse to the ground, on the verge of death from your wounds. You are slowly surrounded by a red mist, and you begin to feel dizzy. You realize that this strange magic is slowly draining you of your blood, killing you. You try to move, but find yourself too weak. In your last moments, you see the vampire standing over you, the red mist returning to him and his wounds healing.");

        }
        else {

            text = QString::fromStdString("Your foe strikes...hitting your heart. As your body falls to the ground lifeless, you see your foe standing triumphantly...(Use the leave button to exit the battle)");

        }

    }
    else {

        if (current.getId() == "39") {

            if (hpRem < val) {
                text = QString::fromStdString("Your sword races towards the vampire and connects, leaving a large wound. The vampire flinches from the pain, stepping backwards. ");
            }
            else if (testDef == true && hpRem == val) {
                text = QString::fromStdString("Your sword races towards the vampire and is blocked by the crimson barrier surrounding him. The barrier disappears after your attack and you see the vampire smirking. ");
            }
            else {
                text = QString::fromStdString("Your sword races towards the vampire, however, at the last moment the vampire steps to the side, perfectly dodging your blade. ");
            }

            if (hpRem2 < val2) {
                text = text + QString::fromStdString("The vampire's crimson mist changes shape, into a spear. The blood spear races towards you, piercing your midsection.");
            }
            else if (testDef2 == true) {
                text = text + QString::fromStdString("The vampire's crimson mist moves to surround him and slowly solidifies, creating a barrier.");
            }
            else {
                text = text + QString::fromStdString("The vampire's crimson mist moves to his hand, forming a sword. The vampire swings at you, missing by the width of a hair.");
            }

        }
        else {

            if (hpRem < val) {
                text = QString::fromStdString("You attempt to strike your foe. You are successful. ");
            }
            else if (testDef == true && hpRem == val) {
                text = QString::fromStdString("You attempt to strike your foe, they parry the incoming attack with finesse. ");
            }
            else {
                text = QString::fromStdString("You attempt to strike your foe, they move slightly and the attack goes wide. ");
            }

            if (hpRem2 < val2) {
                text = text + QString::fromStdString("Your foe responds with a counterattack. It hits you before you can react.");
            }
            else if (testDef2 == true) {
                text = text + QString::fromStdString("Your foe braces for impact, waiting for an attack.");
            }
            else {
                text = text + QString::fromStdString("Your foe responds with a counterattack. The sharp metal misses by a hairs width.");
            }

        }




    }


    ui->label_6->setText(text);

}

void MainWindow::on_heavyAttack_clicked()
{

    ex.enemyTurn();
    int val = ui->progressBar_2->value();
    int dmg = val - ex.playerTempHP;
    int hpRem = val - dmg;
    ui->progressBar_2->setValue(hpRem);
    bool testDef = ex.isEnemyDefending();

    ex.playerHeavyAttack();
    int val2 = ui->progressBar_3->value();
    int dmg2 = val2 - ex.enemyTempHP;
    int hpRem2 = val2 - dmg2;
    ui->progressBar_3->setValue(hpRem2);

    QString text;
    if (hpRem2 <= 0) {
        ui->progressBar_3->setValue(0);

        if (current.getId() == "39" && player.hasItemWithName("Hammer") && player.hasItemWithName("Wooden stake")) {

            text = QString::fromStdString("Your aim is true, the vampire collapses to the ground, unmoving. Keeping your weapon raised, you walk to the side of the downed vampire. You notice the flesh of the vampire regenerating and the wounds closing. With no hesitation you take the wooden stake and hammer from your pack, and hammer the stake into his heart. With a cry and a twitch, the vampire begins to wither and turn to dust...");

        }
        else if (current.getId() == "39") {

            text = QString::fromStdString("Your aim is true, the vampire collapses to the ground, unmoving. Keeping your weapon raised, you walk to the side of the downed vampire. You notice the flesh of the vampire regenerating and the wounds closing. You stab the vampire again, but the wound closes in seconds. You realize that you do not have what it needs to kill the vampire for good.");

        }
        else {

            text = QString::fromStdString("Your aim is true, your foe falls to the ground lifeless. This battle is won...(Use the leave button to exit the battle)");

        }


    }
    else if (hpRem <= 0) {
        ui->progressBar_2->setValue(0);

        if (current.getId() == "39") {

            text = QString::fromStdString("You collapse to the ground, on the verge of death from your wounds. You are slowly surrounded by a red mist, and you begin to feel dizzy. You realize that this strange magic is slowly draining you of your blood, killing you. You try to move, but find yourself too weak. In your last moments, you see the vampire standing over you, the red mist returning to him and his wounds healing.");

        }
        else {

            text = QString::fromStdString("Your foe strikes...hitting your heart. As your body falls to the ground lifeless, you see your foe standing triumphantly...(Use the leave button to exit the battle)");

        }
    }
    else {

        if (current.getId() == "39") {

            text = QString::fromStdString("You begin to wind up for a powerful attack, hoping to cripple the vampire with one blow. ");
            if (testDef == true) {
                text = text + QString::fromStdString("The vampire notices the wind up and brings the crimson mist close to himself, it slowly solidifies and forms a barrier. ");
            }
            else if (hpRem < val) {
                text = text + QString::fromStdString("The vampire notices the wind up and decides to strike first, the crimson mist forms into a sword and he swings, drawing blood. ");
            }
            else {
                text = text + QString::fromStdString("The vampire notices the wind up and decides to strike first, the crimson mist forms into a spear and it races towards you, you barely manage to dodge. ");
            }

            if (hpRem2 < val2) {
                text = text + QString::fromStdString("Your sword swings downwards with extreme force, cleaving flesh from bone and taking a part of the vampire with it.");
            }
            else if (testDef == true && hpRem2 == val2) {
                text = text + QString::fromStdString("Your sword swings downwards with extreme force, however, it is unable to pierce the crimson barrier of the vampire. The barrier dissipates.");
            }
            else {
                text = text + QString::fromStdString("Your sword swings downwards with extreme force, however, the vampire moves at the last second. This causes your attack to barely miss its mark.");
            }

        }
        else {

            text = QString::fromStdString("You begin to wind up for a powerful attack. ");
            if (testDef == true) {
                text = text + QString::fromStdString("Your foe notices the wind up and braces for the impact. ");
            }
            else if (hpRem < val) {
                text = text + QString::fromStdString("Your foe notices an opening and attempts to strike you, they are successful. ");
            }
            else {
                text = text + QString::fromStdString("Your foe notices an opening and attempts to strike you, they miss. ");
            }

            if (hpRem2 < val2) {
                text = text + QString::fromStdString("Your attack is ready and strikes its target, taking a part of your foe with it.");
            }
            else if (testDef == true && hpRem2 == val2) {
                text = text + QString::fromStdString("Your attack is ready and strikes its target, however, your foe parries the blow.");
            }
            else {
                text = text + QString::fromStdString("Your attack is ready and moves with extreme force, barely missing its mark.");
            }

        }



    }


    ui->label_6->setText(text);

}

void MainWindow::on_defend_clicked()
{
    ex.playerDefend();

    ex.enemyTurn();
    int val = ui->progressBar_2->value();
    int dmg = val - ex.playerTempHP;
    int hpRem = val - dmg;
    ui->progressBar_2->setValue(hpRem);

    QString text;
    if (ex.enemyTempHP <= 0) {
        ui->progressBar_3->setValue(0);

        if (current.getId() == "39" && player.hasItemWithName("Hammer") && player.hasItemWithName("Wooden stake")) {

            text = QString::fromStdString("Your aim is true, the vampire collapses to the ground, unmoving. Keeping your weapon raised, you walk to the side of the downed vampire. You notice the flesh of the vampire regenerating and the wounds closing. With no hesitation you take the wooden stake and hammer from your pack, and hammer the stake into his heart. With a cry and a twitch, the vampire begins to wither and turn to dust...");

        }
        else if (current.getId() == "39") {

            text = QString::fromStdString("Your aim is true, the vampire collapses to the ground, unmoving. Keeping your weapon raised, you walk to the side of the downed vampire. You notice the flesh of the vampire regenerating and the wounds closing. You stab the vampire again, but the wound closes in seconds. You realize that you do not have what it needs to kill the vampire for good.");

        }
        else {

            text = QString::fromStdString("Your aim is true, your foe falls to the ground lifeless. This battle is won...(Use the leave button to exit the battle)");

        }

    }
    else if (hpRem <= 0) {
        ui->progressBar_2->setValue(0);

        if (current.getId() == "39") {

            text = QString::fromStdString("You collapse to the ground, on the verge of death from your wounds. You are slowly surrounded by a red mist, and you begin to feel dizzy. You realize that this strange magic is slowly draining you of your blood, killing you. You try to move, but find yourself too weak. In your last moments, you see the vampire standing over you, the red mist returning to him and his wounds healing.");

        }
        else {

            text = QString::fromStdString("Your foe strikes...hitting your heart. As your body falls to the ground lifeless, you see your foe standing triumphantly...(Use the leave button to exit the battle)");

        }
    }
    else {

        if (current.getId() == "39") {

            text = QString::fromStdString("You brace yourself, anticipating an attack. ");
            if (hpRem < val) {
                text = text + QString::fromStdString("The vampire's crimson mist forms a spear and races towards you, breaking your guard and giving you a fresh wound.");
            }
            else if (ex.isEnemyDefending() == true) {
                text = text + QString::fromStdString("The vampire's crimson mist is pulled close and turns into a barrier, the vampire waits for your attack. ");
            }
            else {
                text = text + QString::fromStdString("The vampire's crimson mist takes the shape of a sword and he swings at you, you barely manage to block the incoming attack.");
            }

        }
        else {

            text = QString::fromStdString("You brace yourself, anticipating an attack. ");
            if (hpRem < val) {
                text = text + QString::fromStdString("Your foe attacks, slipping past your guard and drawing blood.");
            }
            else if (ex.isEnemyDefending() == true) {
                text = text + QString::fromStdString("Your foe braces for an attack, waiting out your guard.");
            }
            else {
                text = text + QString::fromStdString("Your foe attacks, you manage to block the incoming blow with ease.");
            }

        }

    }

    ui->label_6->setText(text);

}

void MainWindow::on_usePotion_clicked()
{

    QString text;
    if (ex.enemyTempHP <= 0) {
        ui->progressBar_3->setValue(0);

        if (current.getId() == "39" && player.hasItemWithName("Hammer") && player.hasItemWithName("Wooden stake")) {

            text = QString::fromStdString("Your aim is true, the vampire collapses to the ground, unmoving. Keeping your weapon raised, you walk to the side of the downed vampire. You notice the flesh of the vampire regenerating and the wounds closing. With no hesitation you take the wooden stake and hammer from your pack, and hammer the stake into his heart. With a cry and a twitch, the vampire begins to wither and turn to dust...");

        }
        else if (current.getId() == "39") {

            text = QString::fromStdString("Your aim is true, the vampire collapses to the ground, unmoving. Keeping your weapon raised, you walk to the side of the downed vampire. You notice the flesh of the vampire regenerating and the wounds closing. You stab the vampire again, but the wound closes in seconds. You realize that you do not have what it needs to kill the vampire for good.");

        }
        else {

            text = QString::fromStdString("Your aim is true, your foe falls to the ground lifeless. This battle is won...(Use the leave button to exit the battle)");

        }

    }
    else if (ex.playerTempHP <= 0) {
        ui->progressBar_2->setValue(0);

        if (current.getId() == "39") {

            text = QString::fromStdString("You collapse to the ground, on the verge of death from your wounds. You are slowly surrounded by a red mist, and you begin to feel dizzy. You realize that this strange magic is slowly draining you of your blood, killing you. You try to move, but find yourself too weak. In your last moments, you see the vampire standing over you, the red mist returning to him and his wounds healing.");

        }
        else {

            text = QString::fromStdString("Your foe strikes...hitting your heart. As your body falls to the ground lifeless, you see your foe standing triumphantly...(Use the leave button to exit the battle)");

        }
    }
    else {

        ex.playerTempHP = ex.playerTempHP + 50;
        if (ex.playerTempHP > 100) {
            ex.playerTempHP = 100;
        }
        ui->progressBar_2->setValue(ex.playerTempHP);
        player.setHealthPotions(player.getHealthPotions() - 1);
        std::string numPots = std::to_string(player.getHealthPotions());

        text = QString::fromStdString("You reach into your pack and pull out a potion, drinking down the bitter liquid. You feel revitalized, and some of your wounds begin to close. You only have " + numPots + " left.");

    }


    ui->label_6->setText(text);
}

void MainWindow::on_leaveBattle_clicked()
{

    if (ex.enemyTempHP <= 0 && current.getId() == "39" && player.hasItemWithName("Hammer") && player.hasItemWithName("Wooden stake")) {
        ui->stackedWidget->setCurrentIndex(3);
        ui->endSceneText->setText("With your pack stuffed to the brim with gold coins looted from the room, and the vampire menace destroyed, your adventure is over and you have made enough money to live out the rest of your days comfortably...");
    }
    else if (ex.enemyTempHP <= 0 && current.getId() == "39") {
        ui->stackedWidget->setCurrentIndex(1);
        ui->descLabel->setText("Stepping away from the vampire and towards the door of the room, you think deeply about what would be needed to permanently kill a vampire. What are their weaknesses...");
    }
    else if (ex.playerTempHP <= 0) {
        ui->stackedWidget->setCurrentIndex(3);
        ui->endSceneText->setText("Unfortunately, you have met an untimely demise, and your adventure is over.");
    }
    else {
        ui->stackedWidget->setCurrentIndex(1);
    }
    int max = ui->progressBar_3->maximum();
    ui->progressBar_3->setValue(max);
    player.setPlayerHealth(ex.playerTempHP);
    ui->currentHealthLabel->setText(QString::fromStdString(std::to_string(player.getPlayerHealth())));
    ui->currentPotionsLabel->setText(QString::fromStdString(std::to_string(player.getHealthPotions())));

}

