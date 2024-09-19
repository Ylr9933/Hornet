#include "defencestate.h"

#include"widget.h"
#include"statemachine.h"
DefenceState::DefenceState(QString name, QMovie *movie,Widget *widget,StateMachine *stateMachine)
    :State(name,movie,widget,stateMachine)
{
    connect(widget,&Widget::mouseEvent,this,&DefenceState::onMouseEvent);

    connect(movie, &QMovie::frameChanged, [=](int frameNumber) {
        if (frameNumber == movie->frameCount()-1) {//若此时为最后一帧
            movie->stop();
            if(stateMachine->getCurrentState()==this)
            {
                stateMachine->changeState(widget->idleState);
                widget->move(widget->pos()-QPoint(deltaX,deltaY));
            }
        }
    });
}

DefenceState::~DefenceState()
{
    State::~State();
}

void DefenceState::enter()
{

    State::enter();
    widget->move(widget->pos()+QPoint(deltaX,deltaY));
}

void DefenceState::onMouseEvent(QMouseEvent *event, QPoint mousePoint, int eventType)
{
    //如果状态机不处于本状态则不管
    if(stateMachine->getCurrentState()!=this)
        return ;
    State::onMouseEvent(event,mousePoint,eventType);

    if(eventType==State::MY_MOUSE_PRESS&&event->button()== Qt::LeftButton)
        stateMachine->changeState(widget->backState);//反击
}
