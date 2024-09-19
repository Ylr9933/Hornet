#include "rwalkstate.h"
#include"widget.h"
#include"statemachine.h"
#include<QRandomGenerator>
RWalkState::RWalkState(QString name, QMovie *movie,Widget *widget,StateMachine *stateMachine)
    :State(name,movie,widget,stateMachine)
{
    connect(widget,&Widget::mouseEvent,this,&RWalkState::onMouseEvent);


    /* 初始化动画 */
    animation = new QPropertyAnimation(widget, "pos");
    animation->setDuration(1500); // 动画持续时间为100毫秒
    animation->setEasingCurve(QEasingCurve::OutQuad); // 设置动画曲线

    // 连接 finished 信号到槽函数
    connect(animation, &QPropertyAnimation::finished, this, [=]() {
        if(!stateMachine->getAutoSwitch()||stateMachine->getCurrentState()!=this)
            return ;
        qDebug() << "动画完成！";
        stateMachine->changeState(widget->idleState);

    });
}

RWalkState::~RWalkState()
{
State::~State();
}

void RWalkState::enter()
{
    if(widget->mousePressed==false)//不处于鼠标拖动状态
    {
        animation->setStartValue(widget->pos());
        animation->setEndValue(widget->pos()+QPoint(300,0));
        animation->start();
    }
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
