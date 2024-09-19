#ifndef IDLESTATE_H
#define IDLESTATE_H

#include "state.h"

class IdleState:public State{
    Q_OBJECT
public:
    IdleState(QString name,QMovie *movie,Widget *widget,StateMachine *stateMachine);
    virtual ~IdleState();
    void enter()override;
protected slots:
    void onMouseEvent(QMouseEvent*event,QPoint mousePoint,int eventType)override;
protected:
    QMenu *menu;
    QMenu *subMenu;
    QAction* selectedAction;
    QAction *action1;
    QAction *action2;
    QAction *action3;
    QAction *action4;
    QAction *action5;
    QAction *action6;
    QAction *onAction;
    QAction *offAction;
    QActionGroup *switchGroup;
};

#endif // IDLESTATE_H
