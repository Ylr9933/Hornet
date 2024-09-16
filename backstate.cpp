#include "backstate.h"
#include"widget.h"
#include"statemachine.h"
BackState::BackState(QString name, QMovie *movie,Widget *widget,StateMachine *stateMachine)
    :State(name,movie,widget,stateMachine)
{
    connect(widget,&Widget::mouseEvent,this,&BackState::onMouseEvent);
    connect(movie, &QMovie::frameChanged, [=](int frameNumber) {
        if (frameNumber == movie->frameCount()-1) {//若此时为最后一帧
            movie->stop();
            stateMachine->changeState(widget->idleState);
        }
    });
}

void BackState::enter()
{
    State::enter();

}

void BackState::onMouseEvent(QMouseEvent *event, QPoint mousePoint,int eventType)
{
    //如果状态机不处于本状态则不管
    if(stateMachine->getCurrentState()!=this)
        return ;
    State::onMouseEvent(event,mousePoint,eventType);

}

