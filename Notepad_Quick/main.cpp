#include <QtGui/QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQml>
#include <documenthandler.h>
#include "qtquick2applicationviewer.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    qmlRegisterType<DocumentHandler>("documenthandler",1,0, "DocumentHandler");

    QQmlApplicationEngine engine;
    engine.load(QUrl("qml/Notepad_Quick/main.qml"));
    QObject *topLevel = engine.rootObjects().value(0);
    QQuickWindow *window = qobject_cast<QQuickWindow *>(topLevel);
    window->show();
    return app.exec();
//    QtQuick2ApplicationViewer viewer;
//    viewer.setMainQmlFile(QStringLiteral("qml/Notepad_Quick/main.qml"));
//    viewer.showExpanded();

//    return app.exec();
}
