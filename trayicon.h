#ifndef TRAYICON_H
#define TRAYICON_H

#include <QSystemTrayIcon>
#include <QMenu>

class TrayIcon : public QSystemTrayIcon
{
    Q_OBJECT
public:
    explicit TrayIcon(QObject *parent = nullptr);

private slots:
    void quitApp();

private:
    QMenu *createTrayIconMenu();
};

#endif // TRAYICON_H
