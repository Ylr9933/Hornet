#ifndef LWALKSTATE_H
#define LWALKSTATE_H

#include "state.h"

class LWalkState : public State
{
    Q_OBJECT
public:
    LWalkState(QString name, QMovie *movie,Widget *widget,StateMachine *stateMachine);
    void  enter()override;
protected slots:
    void onMouseEvent(QMouseEvent*event,QPoint mousePoint,int eventType)override;
};

#endif // LWALKSTATE_H
