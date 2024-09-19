#include "statemachine.h"

StateMachine::StateMachine(QObject *parent)
    :QObject(parent)
{
    autoSwitch=false;
}

void StateMachine::changeState(State *newState)
{
    qDebug()<<"ChangeState";
    currentState=newState;
    currentState->enter();
}

State *StateMachine::getCurrentState()
{
    return currentState;
}

bool StateMachine::getAutoSwitch()
{
    return autoSwitch;
}

void StateMachine::setAutoSwitch(bool flag)
{
    autoSwitch=flag;
}
