#ifndef IDLESTATE_H
#define IDLESTATE_H

#include "state.h"

class IdleState:public State{
    Q_OBJECT
public:
    IdleState(QString name,QMovie *movie,Widget *widget,StateMachine *stateMachine);
    void enter()override;
protected slots:
    void onMouseEvent(QMouseEvent*event,QPoint mousePoint,int eventType)override;
protected:
    QMenu *menu;
    QAction* selectedAction;
    const QAction *action1;
    const QAction *action2;
    const QAction *action3;
    const QAction *action4;
    const QAction *action5;
};

#endif // IDLESTATE_H
