#ifndef RWALLSTATE_H
#define RWALLSTATE_H

#include "state.h"

class RWallState : public State
{
    Q_OBJECT
public:
    RWallState(QString name, QMovie *movie,Widget *widget,StateMachine *stateMachine);
    virtual~RWallState();
    void  enter()override;
protected slots:
    void onMouseEvent(QMouseEvent*event,QPoint mousePoint,int eventType)override;
};

#endif // RWALLSTATE_H
