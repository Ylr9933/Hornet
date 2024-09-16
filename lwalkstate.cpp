#include "lwalkstate.h"
#include"widget.h"
#include"statemachine.h"

LWalkState::LWalkState(QString name, QMovie *movie,Widget *widget,StateMachine *stateMachine)
    :State(name,movie,widget,stateMachine)
{
    connect(widget,&Widget::mouseEvent,this,&LWalkState::onMouseEvent);
}

void LWalkState::enter()
{
    State::enter();


}

void LWalkState::onMouseEvent(QMouseEvent *event, QPoint mousePoint, int eventType)
{    //如果状态机不处于本状态则不管
    if(stateMachine->getCurrentState()!=this){
        return ;
    }
    State::onMouseEvent(event,mousePoint,eventType);
    if(eventType==State::MY_MOUSE_MOVE){
        //超出屏幕左侧
        if (widget->pos().x() <= widget->screen()->availableGeometry().left())
            stateMachine->changeState(widget->lwallState);
        else if(widget->pos().x()<(event->globalPos() - mousePoint).x())
            stateMachine->changeState(widget->rwalkState);
    }
    else if(eventType==State::MY_MOUSE_RELEASE){
        stateMachine->changeState(widget->idleState);
    }
}
