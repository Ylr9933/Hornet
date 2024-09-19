#ifndef DEFENCESTATE_H
#define DEFENCESTATE_H

#include "state.h"

class DefenceState : public State
{
    Q_OBJECT
public:
    DefenceState(QString name, QMovie *movie,Widget *widget,StateMachine *stateMachine);
    virtual~DefenceState();
    void  enter()override;
protected slots:
    void onMouseEvent(QMouseEvent*event,QPoint mousePoint,int eventType)override;
protected:
    //gif大小不同导致的位移
    const int deltaX=-165;
    const int deltaY=-60;
};

#endif // DEFENCESTATE_H
