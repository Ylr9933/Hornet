#include "rwallstate.h"
#include"widget.h"
#include"statemachine.h"

RWallState::RWallState(QString name, QMovie *movie,Widget *widget,StateMachine *stateMachine)
    :State(name,movie,widget,stateMachine)
{
    connect(widget,&Widget::mouseEvent,this,&RWallState::onMouseEvent);
}

void RWallState::enter()
{
    State::enter();


}

void RWallState::onMouseEvent(QMouseEvent *event, QPoint mousePoint, int eventType)
{    //如果状态机不处于本状态则不管
    if(stateMachine->getCurrentState()!=this)
        return ;
    State::onMouseEvent(event,mousePoint,eventType);
    if(eventType==State::MY_MOUSE_MOVE){
        if(widget->pos().x()>(event->globalPos() - mousePoint).x())
            stateMachine->changeState(widget->lwalkState);
    }
}
