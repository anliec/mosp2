#include "ConsoleClient.h"
#include "ui_BasicClientUI.h"

#include <iostream>
#include <QString>
#include <unordered_set>
#include <map>

#include "MonsterTeam.h"
#include "Point.h"
#include "MapManager.h"
#include "Player.h"

ConsoleClient::ConsoleClient(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::BasicClientUI)
{
    ui->setupUi(this);

    mapRefreshTimer.setSingleShot(false);
    mapRefreshTimer.start(500);

    connect(&mapRefreshTimer, SIGNAL(timeout()), this, SLOT(sendFullMap()));
}

ConsoleClient::~ConsoleClient()
{
    delete ui;
}

void ConsoleClient::setPlayer(std::shared_ptr<Player> &newPlayer)
{
    if(player != nullptr){
        disconnect(&(*player), SIGNAL(mapChanged(std::shared_ptr<MapManager>)), this, SLOT(setMapManager(std::shared_ptr<MapManager>)));
        disconnect(ui->pb_move, SIGNAL(clicked()), this, SLOT(onMoveButtonClicked));
    }
    player = newPlayer;
    connect(&(*player), SIGNAL(mapChanged(std::shared_ptr<MapManager>)), this, SLOT(setMapManager(std::shared_ptr<MapManager>)));
    connect(ui->pb_move, SIGNAL(clicked()), this, SLOT(onMoveButtonClicked()));

    setMapManager(player->getMapManager());
}

void ConsoleClient::setMapManager(std::shared_ptr<MapManager> manager)
{
    if(mapManager != nullptr){
        // disconnect
        disconnect(&(*mapManager), SIGNAL(move(const int&, const std::vector<Point>&)), this, SLOT(sendLivingMove(const int&, const std::vector<Point>&)));
        disconnect(&(*mapManager), SIGNAL(newLiving(std::shared_ptr<Living>)), this, SLOT(sendFullMap()));
        disconnect(&(*mapManager), SIGNAL(livingLeaved(const int&)), this, SLOT(sendFullMap()));
    }
    mapManager = manager;
    connect(&(*mapManager), SIGNAL(move(const int&, const std::vector<Point>&)), this, SLOT(sendLivingMove(const int&, const std::vector<Point>&)));
    connect(&(*mapManager), SIGNAL(newLiving(std::shared_ptr<Living>)), this, SLOT(sendFullMap()));
    connect(&(*mapManager), SIGNAL(livingLeaved(const int&)), this, SLOT(sendFullMap()));
    // make sure the update is displayed
    sendFullMap();
}

void ConsoleClient::getEndOfFightResult(const FightEndResult &result)
{

}

void ConsoleClient::sendFullMap()
{
    QString map = "";
    const auto& tiles = player->getMapManager()->getTiles();
    for(unsigned y=0 ; y<tiles->getWidth() ; y++){
        map.append("  ");
        for(unsigned x=0 ; x<tiles->getHeight() ; x++){
            map.append(QString::number(int(tiles->getTile(x, y))));
        }
        map.append("\n");
    }
    ui->te_map->setText(map);
    QString living = "";
    const QString livingTemplate = "  %1 (%2,%3)\n";
    living.append("Players:\n");
    for(const auto& p : player->getMapManager()->getPlayers()){
        const Pos& pos = p.second->getPos();
        living.append(livingTemplate.arg(p.first).arg(int(pos.x)).arg(int(pos.y)));
    }
    living.append("Monsters:\n");
    for(const auto& p : player->getMapManager()->getMonsters()){
        const Pos& pos = p.second->getPos();
        living.append(livingTemplate.arg(p.first).arg(int(pos.x)).arg(int(pos.y)));
    }
    ui->te_living->setText(living);
}

void ConsoleClient::sendLivingMove(const int &livingId, const std::vector<Point> &path)
{
    QString moves = ui->te_moves->toPlainText();
    const QString pointTemplate = "(%2,%3) ";
    moves.append(QString("%1 path: ").arg(livingId));
    for(const Point& p : path){
        moves.append(pointTemplate.arg(int(p.x)).arg(int(p.y)));
    }
    moves.append("\n");
    ui->te_moves->setText(moves);
//    sendFullMap();
}

void ConsoleClient::sendNewMapObject(const std::shared_ptr<MapObject> &object)
{

}

void ConsoleClient::sendAttack(const std::shared_ptr<Living> &living, const AttackDamage &attack)
{

}

void ConsoleClient::onMoveRequest(const std::vector<Point> &path)
{

}

void ConsoleClient::onAttackRequest(const int &attackId)
{

}

void ConsoleClient::onMoveButtonClicked()
{
    Point dest(char(ui->sb_x->value()), char(ui->sb_y->value()));
    std::cout << "Going to : " << dest << std::endl;
    goTo(dest);
}

void ConsoleClient::goTo(const Point &p)
{
    const auto& tiles = player->getMapManager()->getTiles();
    const Point& start = player->getPos();
    const std::vector<Point> nexts = {Point(0,1), Point(1,0), Point(0,-1), Point(-1,0)};
    std::unordered_set<Point> grey;
    std::unordered_set<Point> next_grey;
    std::unordered_set<Point> black;
    std::map<Point,Point> pred;

    if(p == start) return;

    grey.insert(start);

    while((grey.find(p) == grey.end()) && (grey.size() > 0)){
        auto cur = grey.begin();
        black.insert(*cur);
        for(const Point& m : nexts){
            Point n = *cur + m;
            if(tiles->getTile(n) == TileType::Free){
                if(grey.find(n) == grey.end() && black.find(n) == black.end()){
                    pred[n] = *cur;
                    next_grey.insert(n);
                }
            }
        }
        grey.erase(cur);

        if(grey.size() == 0){
            grey = next_grey;
            next_grey.clear();
        }
        std::cout << grey.size() << std::endl;
    }
    if(grey.find(p) != grey.end()){
        std::cout << "Path: ";
        Point cur = p;
        std::list<Point> path;
        while(cur != start){
            std::cout << cur << ", ";
            path.push_front(cur);
            cur = pred[cur];
        }
        std::cout << cur << std::endl;
        path.push_front(cur);
        std::vector<Point> vecPath(path.begin(), path.end());
        player->RequestMove(vecPath);
    }
    else{
        std::cout << "No path found" << std::endl;
        return;
    }

}

void ConsoleClient::goTo(const int &x, const int &y)
{
    goTo(Point(char(x),char(y)));
}

















