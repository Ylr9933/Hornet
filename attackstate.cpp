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
            stateMachine->changeState(widget->idleState);
            widget->move(lastPosition);
        }
    });
}

void AttackState::enter()
{
    //获取动画前的位置
    lastPosition=widget->pos();
    widget->move(widget->pos()+QPoint(-50,-25));
    State::enter();
}

void AttackState::onMouseEvent(QMouseEvent *event, QPoint mousePoint,  int eventType)
{
    //如果状态机不处于本状态则不管
    if(stateMachine->getCurrentState()!=this)
        return ;
    State::onMouseEvent(event,mousePoint,eventType);

}
