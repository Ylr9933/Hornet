#include "statemachine.h"

StateMachine::StateMachine(QObject *parent)
    :QObject(parent)
{
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
