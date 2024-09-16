#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
    , stateMachine(new StateMachine)
    , trayIcon(new TrayIcon(this))
{
    ui->setupUi(this);

    /* 设置窗口名称 */
    setWindowTitle("Hornet Protector");

    /* 设置窗口属性 */
    setAttribute(Qt::WA_TranslucentBackground, true);
    setWindowFlags(windowFlags() | Qt::FramelessWindowHint| Qt::WindowStaysOnTopHint|Qt::Tool);
    /* 初始化所有状态 */
    initState();

    /* 初状态设为idle */
    stateMachine->changeState(idleState);
}

Widget::~Widget()
{
    delete ui;
    delete stateMachine;
    delete trayIcon;
}

void Widget::initState()
{
    idleState = new IdleState("idle",new QMovie(":/gifs/idle.gif"),this,stateMachine);
    connect(idleState,&IdleState::enterState,this,&Widget::on_enterState);

    attackState = new AttackState("attack",new QMovie(":/gifs/attack.gif"),this,stateMachine);
    connect(attackState,&AttackState::enterState,this,&Widget::on_enterState);

    lwalkState = new LWalkState("lwalk",new QMovie(":/gifs/lwalk.gif"),this,stateMachine);
    connect(lwalkState,&LWalkState::enterState,this,&Widget::on_enterState);

    rwalkState = new RWalkState("rwalk",new QMovie(":/gifs/rwalk.gif"),this,stateMachine);
    connect(rwalkState,&RWalkState::enterState,this,&Widget::on_enterState);

    lwallState = new LWallState("lwall",new QMovie(":/gifs/lwall.gif"),this,stateMachine);
    connect(lwallState,&LWallState::enterState,this,&Widget::on_enterState);

    rwallState = new RWallState("rwall",new QMovie(":/gifs/rwall.gif"),this,stateMachine);
    connect(rwallState,&RWallState::enterState,this,&Widget::on_enterState);

    dashState = new DashState("dash",new QMovie(":/gifs/dash.gif"),this,stateMachine);
    connect(dashState,&DashState::enterState,this,&Widget::on_enterState);


    defenceState = new DefenceState("defence",new QMovie(":/gifs/defence.gif"),this,stateMachine);
    connect(defenceState,&DefenceState::enterState,this,&Widget::on_enterState);

    defencingState = new DefencingState("defencing",new QMovie(":/gifs/defencing.gif"),this,stateMachine);
    connect(defencingState,&DefencingState::enterState,this,&Widget::on_enterState);

    backState = new BackState("back",new QMovie(":/gifs/back.gif"),this,stateMachine);
    connect(backState,&BackState::enterState,this,&Widget::on_enterState);

    duckState = new DuckState("duck",new QMovie(":/gifs/duck.gif"),this,stateMachine);
    connect(duckState,&DuckState::enterState,this,&Widget::on_enterState);
}

void Widget::on_enterState(){

    /* 设置动画 */
    QMovie *movie=stateMachine->getCurrentState()->getMovie();
    ui->label->setMovie(movie);

    /* 设置窗口和QLabel的尺寸 */
    this->setFixedSize(movie->frameRect().size());
    ui->label->setFixedSize(movie->frameRect().size());

    /* 设置居中显示 */
    ui->label->setAlignment(Qt::AlignCenter);
}
void Widget::mousePressEvent(QMouseEvent *event){
    emit mouseEvent(event,mousePoint,State::MY_MOUSE_PRESS);
    if (event->button() == Qt::LeftButton)
    {
        mousePoint = event->globalPos() - frameGeometry().topLeft();
        mousePressed=true;
    }
    QWidget::mousePressEvent(event);
}
void Widget::mouseMoveEvent(QMouseEvent *event){
    if (mousePressed)
    {
        emit mouseEvent(event,mousePoint,State::MY_MOUSE_MOVE);
        move((event->globalPos() - mousePoint));
    }

    QWidget::mouseMoveEvent(event);
}
void Widget::mouseReleaseEvent(QMouseEvent *event){
    mousePressed=false;
    emit mouseEvent(event,mousePoint,State::MY_MOUSE_RELEASE);
    QWidget::mouseReleaseEvent(event);
}
void Widget::enterEvent(QEnterEvent *event){
    /* 当鼠标进入窗口时，改变鼠标指针为手型 */
    QApplication::setOverrideCursor(Qt::ClosedHandCursor);
    QWidget::enterEvent(event);
}
void Widget::leaveEvent(QEvent *event){
    /* 当鼠标离开窗口时，恢复默认指针 */
    QApplication::restoreOverrideCursor();
    QWidget::leaveEvent(event);
}
void Widget::moveEvent(QMoveEvent *event){
    // 调用基类的 moveEvent 方法
    QWidget::moveEvent(event);

    // 获取屏幕可用区域
    QRect screenRect = screen()->availableGeometry();
    int leftBoundary = screenRect.left();
    int rightBoundary = screenRect.right() - width();
    int upBoundary = screenRect.top();
    int bottomBoundary = screenRect.bottom() - height();

    // 获取窗口的新位置
    QPoint position = pos();

    // 鼠标位置
    int x=position.x();
    if(x<leftBoundary)
        x=leftBoundary;
    else if(x>rightBoundary)
        x=rightBoundary;
    int y=position.y();
    if(y<upBoundary)
        y=upBoundary;
    else if(y>bottomBoundary)
        y=bottomBoundary;

    if (position.x() < leftBoundary) {
       // stateMachine->changeState(lwallState);
        move(leftBoundary, y);
    }
    if (position.x() > rightBoundary) {
        //stateMachine->changeState(rwallState);
        move(rightBoundary, y);
    }
    if (position.y() <upBoundary ) {
        move(x, screenRect.top());
    }
    if (position.y() > bottomBoundary) {
        move(x, bottomBoundary);
    }
}
