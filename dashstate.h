#ifndef DASHSTATE_H
#define DASHSTATE_H

#include "state.h"

class DashState : public State
{
    Q_OBJECT
public:
    DashState(QString name, QMovie *movie,Widget *widget,StateMachine *stateMachine);
    void  enter()override;
protected slots:
    void onMouseEvent(QMouseEvent*event,QPoint mousePoint,int eventType)override;
};

#endif // DASHSTATE_H
