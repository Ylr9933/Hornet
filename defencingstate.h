#ifndef DEFENCESingTATE_H
#define DEFENCESingTATE_H

#include "state.h"

class DefencingState : public State
{
    Q_OBJECT
public:
    DefencingState(QString name, QMovie *movie,Widget *widget,StateMachine *stateMachine);
    void  enter()override;
protected slots:
    void onMouseEvent(QMouseEvent*event,QPoint mousePoint,int eventType)override;
};

#endif // DEFENCESTATE_H
