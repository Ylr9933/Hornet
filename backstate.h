#ifndef BACKSTATE_H
#define BACKSTATE_H

#include "state.h"

class BackState : public State
{
    Q_OBJECT
public:
    BackState(QString name, QMovie *movie,Widget *widget,StateMachine *stateMachine);
    void  enter()override;
protected slots:
    void onMouseEvent(QMouseEvent*event,QPoint mousePoint,int eventType)override;
};

#endif // BACKSTATE_H
