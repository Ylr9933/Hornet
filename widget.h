#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QMouseEvent>
#include<QApplication>
#include<QMenu>
#include<QDir>
#include<QMovie>
#include<QPropertyAnimation>
#include "jumpstate.h"
#include"statemachine.h"
#include"attackstate.h"
#include"duckstate.h"
#include"idlestate.h"
#include"dashstate.h"
#include"defencestate.h"
#include"lwalkstate.h"
#include"rwalkstate.h"
#include"lwallstate.h"
#include"rwallstate.h"
#include"backstate.h"
#include"trayicon.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    void initState();
    StateMachine *stateMachine;
    IdleState *idleState;
    LWalkState *lwalkState;
    RWalkState *rwalkState;
    LWallState *lwallState;
    RWallState* rwallState;
    DashState* dashState;
    DefenceState *defenceState;
    BackState *backState;
    AttackState *attackState;
    DuckState*duckState;
    JumpState*jumpState;
    bool mousePressed;//鼠标是否按下
protected slots:
    void on_enterState();
signals:
    void widgetLocation(QPoint);
    void mouseEvent(QMouseEvent *event, QPoint mousePoint, int eventType);
protected:
    /* 重写鼠标移动窗口事件 */
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void enterEvent(QEnterEvent *event) override;
    void leaveEvent(QEvent *event) override;
    void moveEvent(QMoveEvent *event) override;


    Ui::Widget *ui;
    TrayIcon *trayIcon;
    //应对部分动画播放后人物产生偏移
    QPoint lastPosition;//播放动画前的坐标

    QPoint mousePoint;//鼠标位置

    bool isdefending;//正在防御

};
#endif // WIDGET_H
