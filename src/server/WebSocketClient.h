/**
 * \file WebSocketClient.h
 */

#ifndef WebSocketClient_h
#define WebSocketClient_h

#include <memory>
#include <vector>

#include <QWebSocket>

#include "Player.h"

class WebSocketClient: public Player {
    Q_OBJECT
private:
    QWebSocket client;
protected:
public:

public:
    WebSocketClient(QWebSocket& client)
    {
        // @todo
    }
    // Public methods

    /**
     */
    void sendFullMap() {
        // @todo
    }

    /**
     *  @param livingId TBD
     *  @param path TBD
     */
    virtual void sendLivingMove(const int& livingId, const std::vector<Point>& path) {
        // @todo
    }

    /**
     *  @param object TBD
     */
    virtual void sendNewMapObject(const std::shared_ptr<MapObject>& object) {
        // @todo
    }

    /**
     *  @param living TBD
     *  @param attack TBD
     */
    virtual void sendAttack(const std::shared_ptr<Living>& living, const AttackDamage& attack) {
        // @todo
    }

    /**
     *  @param path TBD
     */
    virtual void onMoveRequest(const std::vector<Point>& path) {
        // @todo
    }

    /**
     *  @param attackId TBD
     */
    virtual void onAttackRequest(const int& attackId) {
        // @todo
    }


    // Protected methods
protected:

    // Private methods
private:
};

#endif // WebSocketClient_h
