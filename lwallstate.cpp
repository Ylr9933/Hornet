#include "lwallstate.h"
#include"widget.h"
#include"statemachine.h"

LWallState::LWallState(QString name, QMovie *movie,Widget *widget,StateMachine *stateMachine)
    :State(name,movie,widget,stateMachine)
{
    connect(widget,&Widget::mouseEvent,this,&LWallState::onMouseEvent);
}

void LWallState::enter()
{
    State::enter();


}

void LWallState::onMouseEvent(QMouseEvent *event, QPoint mousePoint, int eventType)
{    //如果状态机不处于本状态则不管
    if(stateMachine->getCurrentState()!=this)
        return ;
    State::onMouseEvent(event,mousePoint,eventType);
    if(eventType==State::MY_MOUSE_MOVE){
        if(widget->pos().x()<(event->globalPos() - mousePoint).x())
            stateMachine->changeState(widget->rwalkState);
    }
}
