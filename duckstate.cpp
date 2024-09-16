#include "duckstate.h"
#include"widget.h"
#include"statemachine.h"

DuckState::DuckState(QString name, QMovie *movie,Widget *widget,StateMachine *stateMachine)
    :State(name,movie,widget,stateMachine)
{
    connect(widget,&Widget::mouseEvent,this,&DuckState::onMouseEvent);

    connect(movie, &QMovie::frameChanged, [=](int frameNumber) {
        if (frameNumber == movie->frameCount()-1) {//若此时为最后一帧
            movie->stop();
            stateMachine->changeState(widget->idleState);
        }
    });
    /* 初始化动画 */
    animation = new QPropertyAnimation(widget, "pos");
    animation->setDuration(100); // 动画持续时间为100毫秒
    animation->setEasingCurve(QEasingCurve::OutQuad); // 设置动画曲线

    /* 初始化延迟定时器 */
    delayTimer = new QTimer(this);
    delayTimer->setSingleShot(true);
    connect(delayTimer, &QTimer::timeout, [this]() {
        animation->start();
    });
}

void DuckState::enter()
{
    State::enter();    
    animation->setStartValue(widget->pos());
    animation->setEndValue(widget->pos()+QPoint(100,0));
    delayTimer->start(250); // 延迟500毫秒开始动画
}

void DuckState::onMouseEvent(QMouseEvent *event, QPoint mousePoint, int eventType)
{    //如果状态机不处于本状态则不管
    if(stateMachine->getCurrentState()!=this)
        return ;
    State::onMouseEvent(event,mousePoint,eventType);
}
