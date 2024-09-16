#include "idlestate.h"
#include"widget.h"
#include"statemachine.h"
IdleState::IdleState(QString name, QMovie *movie,Widget *widget,StateMachine *stateMachine)
    :State(name,movie,widget,stateMachine)
{
    menu=new QMenu;
    //初始化菜单栏
    action1 = menu->addAction("摸摸头");
    action2 = menu->addAction("攻击");
    action3 = menu->addAction("冲刺");
    action4 = menu->addAction("防御");
    action5 = menu->addAction("退出");
    connect(widget,&Widget::mouseEvent,this,&IdleState::onMouseEvent);
}

void IdleState::enter(){
    State::enter();

}

void IdleState::onMouseEvent(QMouseEvent *event, QPoint mousePoint,int eventType)
{    //如果状态机不处于本状态则不管
    if(stateMachine->getCurrentState()!=this)
        return ;
    State::onMouseEvent(event,mousePoint,eventType);
    if(eventType==State::MY_MOUSE_MOVE){
        if(widget->pos().x()>(event->globalPos() - mousePoint).x())
            stateMachine->changeState(widget->lwalkState);
        else
            stateMachine->changeState(widget->rwalkState);
    }
    else if(eventType==State::MY_MOUSE_PRESS&&event->button()==Qt::RightButton){//打开菜单
        // 显示菜单，并获取用户的选择
        selectedAction = menu->exec(event->globalPos());
        // 根据用户的选项执行相应的动作
        if (selectedAction == action1)
        {
            stateMachine->changeState(widget->duckState); // 更改状态
        }
        else if (selectedAction == action2)
        {
            stateMachine->changeState(widget->attackState); // 更改状态
        }
        else if (selectedAction == action3)
        {
            stateMachine->changeState(widget->dashState); // 更改状态
        }
        else if (selectedAction == action4)
        {
            stateMachine->changeState(widget->defenceState);
        }
        else if(selectedAction == action5)
        {
            QApplication::exit();
        }
    }
}
