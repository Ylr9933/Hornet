#include "idlestate.h"
#include"widget.h"
#include"statemachine.h"
#include<QRandomGenerator>
#include<QActionGroup>
IdleState::IdleState(QString name, QMovie *movie,Widget *widget,StateMachine *stateMachine)
    :State(name,movie,widget,stateMachine)
{
    menu=new QMenu;
    subMenu=new QMenu;
    //初始化菜单栏
    action1 = menu->addAction("摸摸头");
    action2 = menu->addAction("攻击");
    action3 = menu->addAction("冲刺");
    action4 = menu->addAction("防御");
    action5 = menu->addAction("跳跃");

    onAction = new QAction("开");
    onAction->setCheckable(true); // 设置为可选状态
    offAction = new QAction("关");
    offAction->setCheckable(true); // 设置为可选状态

    // 创建开关组
    switchGroup = new QActionGroup(this);
    switchGroup->setExclusive(true); // 设置为互斥组
    switchGroup->addAction(onAction);
    switchGroup->addAction(offAction);

    // 将开关选项添加到子菜单中

    subMenu->addAction(onAction);
    subMenu->addAction(offAction);

    // 将子菜单添加到主菜单中
    QAction *switchAction = new QAction("自动移动", this);
    switchAction->setMenu(subMenu);
    menu->addAction(switchAction);
    action6 = menu->addAction("退出");
    // 默认选择一个选项
    offAction->setChecked(true);

    connect(widget,&Widget::mouseEvent,this,&IdleState::onMouseEvent);
    switchTimer = new QTimer(this);
    switchTimer->setInterval(10000); // 每10秒检查一次
    switchTimer->start();
    connect(switchTimer, &QTimer::timeout, this, [=]() {

        if(!stateMachine->getAutoSwitch()||stateMachine->getCurrentState()!=this)
            return ;

        // 设置屏幕边界
        QRect screenRect = widget->screen()->availableGeometry();
        int screenWidth = screenRect.width();

        // 计算屏幕中心位置
        int centerX = screenWidth / 2;

        // 当前水平位置
        int currentX = widget->pos().x();

        // 计算当前水平位置与中心位置的距离
        int distanceFromCenter = qAbs(currentX - centerX);

        // 根据距离计算概率
        // 距离越远，向中心移动的概率越高
        int distanceThreshold = screenWidth / 4; // 距离阈值
        double probabilityTowardsCenter = 1.0 - static_cast<double>(distanceFromCenter) / distanceThreshold;
        probabilityTowardsCenter = qBound(0.0, probabilityTowardsCenter, 1.0); // 确保概率在0到1之间

        // 自动转换状态
        int random = QRandomGenerator::global()->bounded(100);
        if (random < probabilityTowardsCenter * 100) { // 根据概率向中心移动
            if (currentX < centerX) {
                stateMachine->changeState(widget->lwalkState);
            } else {
                stateMachine->changeState(widget->rwalkState);
            }
        } else {//随机移动
            random = QRandomGenerator::global()->bounded(100);
            if(random<20)
                stateMachine->changeState(widget->lwalkState);
            else if(random<50)
                stateMachine->changeState(widget->rwalkState);
            else if(random<70)
                stateMachine->changeState(widget->attackState);
            else if(random<80)
                stateMachine->changeState(widget->duckState);
            else if(random<90)
                stateMachine->changeState(widget->dashState);
            else if(random<100)
                stateMachine->changeState(widget->jumpState);
        }
    });
}
IdleState::~IdleState(){
    State::~State();
    if(menu)
        delete menu;
    if(subMenu)
        delete subMenu;
    if(action1)
        delete action1;
    if(action2)
        delete action2;
    if(action3)
        delete action3;
    if(action4)
        delete action4;
    if(action5)
        delete action5;
    if(action6)
        delete action6;
    if(onAction)
        delete onAction;
    if(offAction)
        delete offAction;
    if(switchGroup)
        delete switchGroup;
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
        else if (selectedAction == action5)
        {
            stateMachine->changeState(widget->jumpState);
        }
        else if(selectedAction == action6)
        {
            QApplication::exit();
        }
        else if(selectedAction==onAction)
        {
            stateMachine->setAutoSwitch(true);
        }
        else if(selectedAction==offAction)
        {
            stateMachine->setAutoSwitch(false);
        }
    }
}
