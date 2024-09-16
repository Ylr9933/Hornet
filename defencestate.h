#ifndef DEFENCESTATE_H
#define DEFENCESTATE_H

#include "state.h"

class DefenceState : public State
{
    Q_OBJECT
public:
    DefenceState(QString name, QMovie *movie,Widget *widget,StateMachine *stateMachine);
    void  enter()override;
protected slots:
    void onMouseEvent(QMouseEvent*event,QPoint mousePoint,int eventType)override;
};

#endif // DEFENCESTATE_H
