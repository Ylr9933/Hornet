#ifndef BACKSTATE_H
#define BACKSTATE_H

#include "state.h"

class BackState : public State
{
    Q_OBJECT
public:
    BackState(QString name, QMovie *movie,Widget *widget,StateMachine *stateMachine);
    virtual~BackState();
    void  enter()override;
protected slots:
    void onMouseEvent(QMouseEvent*event,QPoint mousePoint,int eventType)override;
protected:
    //gif大小不同导致的位移
    const int deltaX=-165;
    const int deltaY=-60;
};

#endif // BACKSTATE_H
