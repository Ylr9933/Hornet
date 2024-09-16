#ifndef STATE_H
#define STATE_H
#include <QWidget>
#include <QMap>
#include <QMovie>
#include <QString>
#include <QTimer>
#include<QMouseEvent>
#include"QPropertyAnimation"
class Widget;
class StateMachine;
/* 状态基类 */
class State:public QObject{

    Q_OBJECT
protected:
    QString name;
    QMovie *movie;//该state对应的动画
    Widget *widget;
    StateMachine *stateMachine;
    /* 位移动画 */
    QPropertyAnimation *animation;
    QTimer *delayTimer;
public:
    State(QString name,QMovie *movie,Widget *widget,StateMachine *stateMachine);
    virtual ~State();
    QString getName();
    QMovie *getMovie();
    virtual void enter();
    virtual void exit();
    virtual void update();
    enum{
        MY_MOUSE_MOVE,
        MY_MOUSE_PRESS,
        MY_MOUSE_RELEASE,
        MY_MOUSE_ENTER,
        MY_MOUSE_EXIT
    };
signals:
    void enterState(State*);
    void changeState(QString state);
    void movieFinished(State *);

public slots:

    //处理鼠标事件(鼠标事件，鼠标位置，窗口位置，事件类型)
    virtual void onMouseEvent(QMouseEvent*event,QPoint mousePosition,int eventType);
};


#endif // STATE_H
