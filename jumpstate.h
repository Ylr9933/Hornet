#ifndef JUMPSTATE_H
#define JUMPSTATE_H

#include "state.h"

class JumpState : public State
{
    Q_OBJECT
public:
    JumpState(QString name,QMovie*movie,Widget *widget,StateMachine *stateMachine);
    virtual ~JumpState();
    void enter()override;
protected slots:
    void onMouseEvent(QMouseEvent*event,QPoint mousePoint,int eventType)override;
};

#endif // JUMPSTATE_H
