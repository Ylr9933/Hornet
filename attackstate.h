#ifndef ATTACKSTATE_H
#define ATTACKSTATE_H

#include "state.h"

class AttackState : public State
{
    Q_OBJECT
public:
    AttackState(QString name,QMovie*movie,Widget *widget,StateMachine *stateMachine);
    virtual ~AttackState();
    void enter()override;
protected slots:
    void onMouseEvent(QMouseEvent*event,QPoint mousePoint,int eventType)override;
protected:
    //gif大小不同导致的位移
    const int deltaX=-72;
    const int deltaY=-26;
};

#endif // ATTACKSTATE_H
