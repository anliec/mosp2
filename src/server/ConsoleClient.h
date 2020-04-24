#ifndef CONSOLECLIENT_H
#define CONSOLECLIENT_H

#include <memory>
#include <QMainWindow>
#include <QTimer>

#include "Player.h"


namespace Ui {
class BasicClientUI;
}

class ConsoleClient : public QMainWindow
{
    Q_OBJECT
private:
    Ui::BasicClientUI *ui;
    std::shared_ptr<Player> player;
    std::shared_ptr<MapManager> mapManager;

    QTimer mapRefreshTimer;

public:
    explicit ConsoleClient(QWidget *parent = nullptr);
    ~ConsoleClient();

public slots:
    void setPlayer(std::shared_ptr<Player>& player);
    void setMapManager(std::shared_ptr<MapManager> manager);

    virtual void getEndOfFightResult(const FightEndResult& result);
    virtual void sendFullMap();
    virtual void sendLivingMove(const int& livingId, const std::vector<Point>& path);
    virtual void sendNewMapObject(const std::shared_ptr<MapObject>& object);
    virtual void sendAttack(const std::shared_ptr<Living>& living, const AttackDamage& attack);
    virtual void onMoveRequest(const std::vector<Point>& path);
    virtual void onAttackRequest(const int& attackId);

    void onMoveButtonClicked();

    void goTo(const Point& p);
    void goTo(const int& x, const int& y);
};

#endif // CONSOLECLIENT_H
