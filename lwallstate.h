#ifndef LWALLSTATE_H
#define LWALLSTATE_H

#include "state.h"

class LWallState : public State
{
    Q_OBJECT
public:
    LWallState(QString name, QMovie *movie,Widget *widget,StateMachine *stateMachine);
    virtual~LWallState();
    void  enter()override;
protected slots:
    void onMouseEvent(QMouseEvent*event,QPoint mousePoint,int eventType)override;
};

#endif // LWALLSTATE_H
