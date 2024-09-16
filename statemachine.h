#ifndef STATEMACHINE_H
#define STATEMACHINE_H
#include"state.h"
class StateMachine : public QObject
{
    Q_OBJECT
public:
    explicit StateMachine(QObject *parent = nullptr);
    void changeState(State *newState);
    State*getCurrentState();
protected:
    State *currentState;//当前状态
};

#endif // STATEMACHINE_H
