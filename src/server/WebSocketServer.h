/**
 * \file WebSocketServer.h
 */

#ifndef WebSocketServer_h
#define WebSocketServer_h

#include <list>
#include <QWebSocketServer>
#include <memory>
#include <QObject>

#include "WebSocketClient.h"


class WebSocketServer: public QObject{
    Q_OBJECT
private:
    std::list<std::shared_ptr<WebSocketClient>> clients;
    QWebSocketServer server;

    static std::shared_ptr<WebSocketServer> serverInstance;

private:
    WebSocketServer(): server("servername", QWebSocketServer::SslMode::SecureMode)
    {
        // @todo
    }
    // Public methods

public:
    /**
     *  @param parent TBD
     */
    static std::shared_ptr<WebSocketServer> getServer() {
        if(serverInstance == nullptr){
//            serverInstance = std::make_shared<WebSocketServer>();
        }
        return serverInstance;
    }


    // Protected methods
protected:

    // Private methods
private:
};

#endif // WebSocketServer_h
