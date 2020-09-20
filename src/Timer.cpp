#include "Timer.h"

Timer::Timer() {
    setDefault();
}

Timer::Timer(Action fn, unsigned long interval)
{
    setDefault();

    OnTick(fn);
    SetInterval(interval);
}

Timer::~ Timer()
{
    Stop();
}

void Timer::setDefault(){
    onStart = NULL;
    onPause = NULL;
    onStop = NULL;
    onResume = NULL;
    onTick = NULL;

    SetInterval(0);
    Stop();
}

void Timer::SetInterval(unsigned long interval){
    _interval = interval;
}

unsigned long Timer::GetInterval(){
    return _interval;
}

TimerState Timer::GetState(){
    return state;
}

void Timer::Start(){
    state = TimerState::START;
    lapsed = millis();

    if(onStart != NULL) onStart();
}

void Timer::Pause(){
    state = TimerState::PAUSE;

    if(onPause != NULL) onPause();
}

void Timer::Resume(){
    state = TimerState::START;

    if(onResume != NULL) onResume();
}

void Timer::Stop(){
    state = TimerState::STOP;
    lapsed = 0;

    if(onStop != NULL) onStop();
}

void Timer::Loop(){
    if ( state == TimerState::START ) {
        unsigned long current = millis();
        if ( current - lapsed >= _interval ) {
            lapsed = current;

            if(onTick != NULL) onTick();
        }
    }
}
