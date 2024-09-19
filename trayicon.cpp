#include "trayicon.h"
#include <QAction>
#include <QApplication>
#include <QMessageBox>

TrayIcon::TrayIcon(QObject *parent)
    : QSystemTrayIcon(parent)
{
    // 创建托盘图标的菜单
    QMenu *trayIconMenu = createTrayIconMenu();

    // 设置托盘图标
    QIcon icon;
    icon.addFile(":/img/icon.png");
    setIcon(icon); // 替换为你的图标路径
    qDebug()<<icon;
    // 将菜单关联到托盘图标
    setContextMenu(trayIconMenu);

    // 显示托盘图标
    setVisible(true);
}

QMenu *TrayIcon::createTrayIconMenu()
{
    QMenu *menu = new QMenu;
    // 添加退出应用的动作
    QAction *quitAction = new QAction(tr("Quit"), this);
    connect(quitAction, &QAction::triggered, this, &TrayIcon::quitApp);
    menu->addAction(quitAction);

    return menu;
}
void TrayIcon::quitApp()
{
    QApplication::quit();
}
