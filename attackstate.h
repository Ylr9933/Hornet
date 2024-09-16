#ifndef ATTACKSTATE_H
#define ATTACKSTATE_H

#include "state.h"

class AttackState : public State
{
    Q_OBJECT
public:
    AttackState(QString name,QMovie*movie,Widget *widget,StateMachine *stateMachine);
    void enter()override;
protected slots:
    void onMouseEvent(QMouseEvent*event,QPoint mousePoint,int eventType)override;
protected:
    QPoint lastPosition;
};

#endif // ATTACKSTATE_H
