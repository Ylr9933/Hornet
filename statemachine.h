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
    bool getAutoSwitch();
    void setAutoSwitch(bool flag);
protected:
    State *currentState;//当前状态
    bool autoSwitch;//自动切换
};

#endif // STATEMACHINE_H
