#include "state.h"
#include"statemachine.h"
State::State(QString name, QMovie *movie,Widget *widget,StateMachine *stateMachine)
    :name(name)
    ,movie(movie)
    ,widget(widget)
    ,stateMachine(stateMachine)
{

}
State::~State(){
    if(movie)
        delete movie;
    if(animation)
        delete animation;
    if(delayTimer)
        delete delayTimer;
}
QString State::getName(){
    return name;
}

QMovie *State::getMovie(){
    return movie;
}
void State::enter(){
    qDebug()<<name<<movie;
    movie->start();
    emit enterState(this);
    qDebug()<<"enterState:"<<name;
}
void State::exit(){

}
void State::update(){

}
void State::onMouseEvent(QMouseEvent*event,QPoint mousePosition,int eventType)
{

}
