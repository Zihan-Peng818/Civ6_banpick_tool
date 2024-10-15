#include "banpicktool.h"
#include <QVBoxLayout>
#include <QHBoxLayout>

BanPickTool::BanPickTool(QWidget* parent)
    : QMainWindow(parent), currentTeam("Team1"), currentOperationIndex(0) {
    champions = {
        Champion("阿基坦的埃莉诺 法国(爱法)"),
        Champion("阿基坦的埃莉诺 英国(爱英)"),
        Champion("阿曼尼托尔(努比亚)"),
        Champion("安比奥里克斯(高卢)"),
        Champion("巴尔兹二世(男拜)"),
        Champion("北条时宗(旧日本)"),
        Champion("彼得(俄罗斯)"),
        Champion("伯里克利(男希腊)"),
        Champion("成吉思汗(武蒙古)"),
        Champion("德川家康(新日本)"),
        Champion("狄奥多拉(女拜)"),
        Champion("狄多(腓尼基)"),
        Champion("阇耶跋摩七世(高棉)"),
        Champion("恩津加 姆班德(女刚果)"),
        Champion("菲利普二世(西班牙)"),
        Champion("弗雷德里克 巴巴罗萨(武德)"),
        Champion("甘地(文印度)"),
        Champion("戈尔戈(女希腊)"),
        Champion("哈拉尔德 哈德拉达 北境王(旧挪威)"),
        Champion("哈拉尔德 哈德拉达 瓦良格(新挪威)"),
        Champion("汉谟拉比(巴比伦)"),
        Champion("忽必烈 蒙古(文蒙古)"),
        Champion("忽必烈 中国(忽中)"),
        Champion("吉尔伽美什(闪闪)"),
        Champion("居鲁士(旧波斯)"),
        Champion("凯瑟琳 德 美第奇 黑王后(黑法)"),
        Champion("凯瑟琳 德 美第奇 寻欢作乐(白法)"),
        Champion("克里斯蒂娜(瑞典)"),
        Champion("克里欧佩特拉 埃及(旧艳后)"),
        Champion("克里欧佩特拉 托勒密(新艳后)"),
        Champion("库佩(毛利)"),
        Champion("拉美西斯二世(拉二)"),
        Champion("莱夫扎茹(马普切)"),
        Champion("六日夫人(玛雅)"),
        Champion("路德维希二世(文德)"),
        Champion("罗伯特一世(苏格兰)"),
        Champion("曼沙 穆萨(钱马里)"),
        Champion("蒙特祖马(阿兹特克)"),
        Champion("孟尼利克二世(埃塞)"),
        Champion("姆本巴 恩津加(男刚果)"),
        Champion("纳迪尔沙阿(新波斯)"),
        Champion("帕查库特克(印加)"),
        Champion("庞德梅克(克里)"),
        Champion("佩德罗二世(巴西)"),
        Champion("恰卡(祖鲁)"),
        Champion("秦始皇 大统一(武秦)"),
        Champion("秦始皇 天命者(文秦)"),
        Champion("若昂三世(葡萄牙)"),
        Champion("萨拉丁 苏丹(武阿拉伯)"),
        Champion("萨拉丁 维齐尔(文阿拉伯)"),
        Champion("善德(女朝鲜)"),
        Champion("世宗大王(男朝鲜)"),
        Champion("松迪亚塔 凯塔(书马里)"),
        Champion("苏莱曼一世 大帝(大帝)"),
        Champion("苏莱曼一世 立法者(亲兵)"),
        Champion("塔玛丽(墙姐)"),
        Champion("泰迪 罗斯福 进步党(文美)"),
        Champion("泰迪 罗斯福 莽骑兵(武美)"),
        Champion("特丽布瓦娜(印尼)"),
        Champion("图拉真(旧罗马)"),
        Champion("托米丽斯(斯基泰）"),
        Champion("威尔弗里德 劳雷尔(加拿大)"),
        Champion("威廉明娜(荷兰)"),
        Champion("维多利亚 帝国时代(帝英)"),
        Champion("维多利亚 蒸汽时代(蒸英)"),
        Champion("武则天(武则天)"),
        Champion("西蒙 玻利瓦尔(大哥)"),
        Champion("匈雅提 马加什(匈牙利)"),
        Champion("雅德维加(波兰)"),
        Champion("维多利亚 蒸汽时代(蒸英)"),
        Champion("亚伯拉罕 林肯(林肯)"),
        Champion("亚历山大(马其顿)"),
        Champion("伊丽莎白一世(商英)"),
        Champion("永乐皇帝(朱棣)"),
        Champion("尤利乌斯 凯撒(新罗马)"),
        Champion("约翰 科廷(土澳)"),
        Champion("旃陀罗笈多(武印度)"),
        Champion("赵夫人(越南)")
    };

    operationSequence << "Team1BAN" << "Team1BAN" << "Team1BAN"
        << "Team2BAN" << "Team2BAN" << "Team2BAN"
        << "Team1PICK" << "Team1PICK"
        << "Team2PICK" << "Team2PICK"
        << "Team1PICK" << "Team2PICK"
        << "Team1BAN" << "Team1BAN"
        << "Team2BAN" << "Team2BAN"
        << "Team1PICK" << "Team2PICK"
        << "Team1PICK" << "Team2PICK"<<"END";


    QWidget* centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    championListWidget = new QListWidget(this);
    statusLabel = new QLabel(this);

    banButton = new QPushButton("Ban", this);
    pickButton = new QPushButton("Pick", this);
    showButton = new QPushButton("Over", this);
    statusLabel->setText("欢迎使用CN Civ Banpicktool!");

    QVBoxLayout* layout = new QVBoxLayout(centralWidget);
    layout->addWidget(new QLabel("Available Champions:"));
    layout->addWidget(championListWidget);
    layout->addWidget(banButton);
    layout->addWidget(pickButton);
    layout->addWidget(showButton);
    layout->addWidget(statusLabel);

    connect(banButton, &QPushButton::clicked, this, &BanPickTool::banChampion);
    connect(pickButton, &QPushButton::clicked, this, &BanPickTool::pickChampion);
    connect(showButton, &QPushButton::clicked, this, &BanPickTool::showFinalResults);

    updateChampionList();
}

BanPickTool::~BanPickTool() {}

void BanPickTool::updateChampionList() {
    championListWidget->clear();
    for (const auto& champion : champions) {
        QString displayText;
        if (champion.isBanned) {
            displayText = '[' + champion.bannedBy + " Banned]: " + champion.name;
        }
        else if (champion.isPicked) {
            displayText = '[' + champion.pickedBy + " Picked]: " + champion.name;
        }
        else {
            displayText = "[Available] " + champion.name;
        }
        championListWidget->addItem(displayText);
    }
}


void BanPickTool::banChampion() {
    if (currentOperationIndex < operationSequence.size()-1) {
        QString currentOperation = operationSequence[currentOperationIndex];

        if (currentOperation.startsWith("Team1") && currentOperation.contains("BAN")) {
            currentTeam = "Team1";
            
            QListWidgetItem* selectedItem = championListWidget->currentItem();
            QString championName = selectedItem->text().mid(selectedItem->text().indexOf(' ') + 1);
            for (auto& champion : champions) {
                if (champion.name == championName && !champion.isBanned) {
                    champion.isBanned = true;
                    champion.bannedBy = currentTeam; // 设置禁用的队伍
                    statusLabel->setText(currentTeam + " BANNED: " + championName); // 更新状态
                    currentOperationIndex++; // 移动到下一个操作
                    updateChampionList(); // 更新列表

                    //文本框提示
                    currentOperation = operationSequence[currentOperationIndex];
                    if (currentOperation.startsWith("Team1") && currentOperation.contains("BAN")) {
                        statusLabel->setText("Please Team1 ban.");
                    }
                    else if (currentOperation.startsWith("Team2") && currentOperation.contains("BAN")) {
                        statusLabel->setText("Please Team2 ban.");
                    }
                    else if (currentOperation.startsWith("Team1") && currentOperation.contains("PICK")) {
                        statusLabel->setText("Please Team1 pick.");
                    }
                    else if (currentOperation.startsWith("Team2") && currentOperation.contains("PICK")) {
                        statusLabel->setText("Please Team2 pick.");
                    }
                    else {
                        statusLabel->setText("BAN PICK END!");
                    }
                    return;
                }
            }
            statusLabel->setText(championName + " is already banned.");
        }

        if (currentOperation.startsWith("Team2") && currentOperation.contains("BAN")) {
            currentTeam = "Team2";
            
            QListWidgetItem* selectedItem = championListWidget->currentItem();
            QString championName = selectedItem->text().mid(selectedItem->text().indexOf(' ') + 1);
            for (auto& champion : champions) {
                if (champion.name == championName && !champion.isBanned) {
                    champion.isBanned = true;
                    champion.bannedBy = currentTeam; // 设置禁用的队伍
                    statusLabel->setText(currentTeam + " BANNED: " + championName); // 更新状态
                    currentOperationIndex++; // 移动到下一个操作
                    updateChampionList(); // 更新列表

                    //文本框提示
                    currentOperation = operationSequence[currentOperationIndex];
                    if (currentOperation.startsWith("Team1") && currentOperation.contains("BAN")) {
                        statusLabel->setText("Please Team1 ban.");
                    }
                    else if (currentOperation.startsWith("Team2") && currentOperation.contains("BAN")) {
                        statusLabel->setText("Please Team2 ban.");
                    }
                    else if (currentOperation.startsWith("Team1") && currentOperation.contains("PICK")) {
                        statusLabel->setText("Please Team1 pick.");
                    }
                    else if (currentOperation.startsWith("Team2") && currentOperation.contains("PICK")) {
                        statusLabel->setText("Please Team2 pick.");
                    }
                    else {
                        statusLabel->setText("BAN PICK END!");
                    }
                    return;
                }
            }
            statusLabel->setText(championName + " is already banned.");
        }
    }
    else {
        statusLabel->setText("BAN PICK END.");
    }
}


void BanPickTool::pickChampion() {
    if (currentOperationIndex < operationSequence.size()-1) {
        QString currentOperation = operationSequence[currentOperationIndex];

        if (currentOperation.startsWith("Team1") && currentOperation.contains("PICK")) {
            currentTeam = "Team1";
            
            QListWidgetItem* selectedItem = championListWidget->currentItem();
            if (!selectedItem) {
                statusLabel->setText("Please select a champion to pick.");
                return;
            }

            QString championName = selectedItem->text().mid(selectedItem->text().indexOf(' ') + 1);
            for (auto& champion : champions) {
                if (champion.name == championName) {
                    if (champion.isBanned) {
                        statusLabel->setText(championName + " is banned and cannot be picked.");
                    }
                    else {
                        // 更新状态
                        champion.isPicked = true; 
                        champion.pickedBy = currentTeam;
                        // 更新为相应的picked状态
                        selectedItem->setText(currentTeam + " PICKED: " + champion.name); 
                        currentOperationIndex++; // 移动到下一个操作

                        //文本框提示
                        currentOperation = operationSequence[currentOperationIndex];
                        if (currentOperation.startsWith("Team1") && currentOperation.contains("BAN")) {
                            statusLabel->setText("Please Team1 ban.");
                        }
                        else if (currentOperation.startsWith("Team2") && currentOperation.contains("BAN")) {
                            statusLabel->setText("Please Team2 ban.");
                        }
                        else if (currentOperation.startsWith("Team1") && currentOperation.contains("PICK")) {
                            statusLabel->setText("Please Team1 pick.");
                        }
                        else if (currentOperation.startsWith("Team2") && currentOperation.contains("PICK")) {
                            statusLabel->setText("Please Team2 pick.");
                        }
                        else {
                            statusLabel->setText("BAN PICK END!");
                        }
                    }
                    return;
                }
            }
            statusLabel->setText("Champion " + championName + " not found.");
        }

        if (currentOperation.startsWith("Team2") && currentOperation.contains("PICK")) {
            currentTeam = "Team2";
            
            QListWidgetItem* selectedItem = championListWidget->currentItem();
            if (!selectedItem) {
                statusLabel->setText("Please select a champion to pick.");
                return;
            }

            QString championName = selectedItem->text().mid(selectedItem->text().indexOf(' ') + 1);
            for (auto& champion : champions) {
                if (champion.name == championName) {
                    if (champion.isBanned) {
                        statusLabel->setText(championName + " is banned and cannot be picked.");
                    }
                    else {
                        // 更新状态
                        champion.isPicked = true; 
                        champion.pickedBy = currentTeam;
                        // 更新为相应的picked状态
                        selectedItem->setText(currentTeam + " PICKED: " + champion.name); 
                        currentOperationIndex++; // 移动到下一个操作

                        currentOperation = operationSequence[currentOperationIndex];
                        if (currentOperation.startsWith("Team1") && currentOperation.contains("BAN")) {
                            statusLabel->setText("Please Team1 ban.");
                        }
                        else if (currentOperation.startsWith("Team2") && currentOperation.contains("BAN")) {
                            statusLabel->setText("Please Team2 ban.");
                        }
                        else if (currentOperation.startsWith("Team1") && currentOperation.contains("PICK")) {
                            statusLabel->setText("Please Team1 pick.");
                        }
                        else if (currentOperation.startsWith("Team2") && currentOperation.contains("PICK")) {
                            statusLabel->setText("Please Team2 pick.");
                        }
                        else {
                            statusLabel->setText("BAN PICK END!");
                        }
                    }
                    return;
                }
            }
            statusLabel->setText("Champion " + championName + " not found.");
        }
    }
    else {
        statusLabel->setText("BAN PICK END.");
    }
}

void BanPickTool::showFinalResults() {
    QString results;
    results += "Final Ban and Pick Results:\n\n";

    // 汇总 Team 1 的禁用和选择
    results += "Team 1 Bans:\n";
    for (const auto& champion : champions) {
        if (champion.isBanned && champion.bannedBy == "Team1") {
            results += "- " + champion.name + "\n";
        }
    }

    results += "Team 1 Picks:\n";
    for (const auto& champion : champions) {
        if (champion.isPicked && champion.pickedBy == "Team1") {
            results += "- " + champion.name + "\n";
        }
    }

    results += "\n";

    // 汇总 Team 2 的禁用和选择
    results += "Team 2 Bans:\n";
    for (const auto& champion : champions) {
        if (champion.isBanned && champion.bannedBy == "Team2") {
            results += "- " + champion.name + "\n";
        }
    }

    results += "Team 2 Picks:\n";
    for (const auto& champion : champions) {
        if (champion.isPicked && champion.pickedBy == "Team2") {
            results += "- " + champion.name + "\n";
        }
    }

    // 显示结果
    QMessageBox::information(this, "Ban and Pick Summary", results);
    return;
}
