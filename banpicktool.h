#ifndef BANpickTOOL_H
#define BANpickTOOL_H
#include <QMainWindow>
#include <QListWidget>
#include <QPushButton>
#include <QLabel>
#include <vector>
#include <QMessageBox>

class Champion {
public:
    QString name;
    bool isBanned;
    bool isPicked;
    QString bannedBy;
    QString pickedBy;

    Champion(QString n) : name(n), isBanned(false), isPicked(false), bannedBy(""), pickedBy("") {}
};

class BanPickTool : public QMainWindow {
    Q_OBJECT

public:
    BanPickTool(QWidget* parent = nullptr);
    ~BanPickTool();

private slots:
    void banChampion();
    void pickChampion();

private:
    void updateChampionList();
    void showFinalResults();
    QStringList operationSequence;
    int currentOperationIndex;

    std::vector<Champion> champions;

    QListWidget* championListWidget;
    QLabel* statusLabel;
    QPushButton* banButton;
    QPushButton* pickButton;
    QPushButton* showButton;
    QString currentTeam; // 当前选中的队伍
};


#endif // BANpickTOOL_H
