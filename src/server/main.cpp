#include <QApplication>
#include <memory>

#include "World.h"
#include "ConsoleClient.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    World* world = World::makeWorld();

    ConsoleClient consolePlayer1;
    std::shared_ptr<Player> player1 = std::make_shared<Player>();
    ConsoleClient consolePlayer2;
    std::shared_ptr<Player> player2 = std::make_shared<Player>();

    auto map = world->getMap(0);

    map->addPlayer(player1);
    consolePlayer1.setPlayer(player1);

    map->addPlayer(player2);
    consolePlayer2.setPlayer(player2);

    consolePlayer1.show();
    consolePlayer2.show();

    return a.exec();
}
