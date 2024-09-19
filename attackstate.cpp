#include "attackstate.h"
#include"widget.h"
#include"statemachine.h"
AttackState::AttackState(QString name, QMovie *movie,Widget *widget,StateMachine *stateMachine)
    :State(name,movie,widget,stateMachine)
{
    connect(widget,&Widget::mouseEvent,this,&AttackState::onMouseEvent);
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

AttackState::~AttackState()
{
    State::~State();
}

void AttackState::enter()
{
    State::enter();
    widget->move(widget->pos()+QPoint(deltaX,deltaY));
}

void AttackState::onMouseEvent(QMouseEvent *event, QPoint mousePoint,  int eventType)
{
    //如果状态机不处于本状态则不管
    if(stateMachine->getCurrentState()!=this)
        return ;
    State::onMouseEvent(event,mousePoint,eventType);

}
