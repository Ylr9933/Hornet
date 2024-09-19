#ifndef RWALKSTATE_H
#define RWALKSTATE_H

#include "state.h"

class RWalkState : public State
{
    Q_OBJECT
public:
    RWalkState(QString name, QMovie *movie,Widget *widget,StateMachine *stateMachine);
    virtual~RWalkState();
    void  enter()override;
protected slots:
    void onMouseEvent(QMouseEvent*event,QPoint mousePoint,int eventType)override;
};

#endif // RWALKSTATE_H
