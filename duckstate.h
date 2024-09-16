#ifndef DUCKSTATE_H
#define DUCKSTATE_H

#include "state.h"

class DuckState : public State
{
    Q_OBJECT
public:
    DuckState(QString name, QMovie *movie,Widget *widget,StateMachine *stateMachine);
    void enter()override;
protected slots:
    void onMouseEvent(QMouseEvent*event,QPoint mousePoint,int eventType)override;
};

#endif // DUCKSTATE_H
