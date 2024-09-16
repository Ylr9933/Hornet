#include "rwalkstate.h"
#include"widget.h"
#include"statemachine.h"

RWalkState::RWalkState(QString name, QMovie *movie,Widget *widget,StateMachine *stateMachine)
    :State(name,movie,widget,stateMachine)
{
    connect(widget,&Widget::mouseEvent,this,&RWalkState::onMouseEvent);
}

void RWalkState::enter()
{
    State::enter();


}

void RWalkState::onMouseEvent(QMouseEvent *event, QPoint mousePoint, int eventType)
{    //如果状态机不处于本状态则不管
    if(stateMachine->getCurrentState()!=this)
        return ;
    State::onMouseEvent(event,mousePoint,eventType);
    if(eventType==State::MY_MOUSE_MOVE){
        //超出屏幕右侧
        if (widget->pos().x() >= widget->screen()->availableGeometry().right()-widget->width())
            stateMachine->changeState(widget->rwallState);
        else if(widget->pos().x()>(event->globalPos() - mousePoint).x())
            stateMachine->changeState(widget->lwalkState);

    }
    else if(eventType==State::MY_MOUSE_RELEASE){
        stateMachine->changeState(widget->idleState);
    }
}
