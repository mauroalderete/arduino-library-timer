#ifndef _TIMER_HPP_
#define _TIMER_HPP_

#include "Arduino.h"

/* @brief Posibles estados del objeto Flicker
*/
enum class TimerState {
    STOP, 
    PAUSE, 
    START
}; 

/* @brief Una clase que permite controlar el parpadeo de una salida digital sin bloquear el flujo del programa.
*/
class Timer
{
private:
    unsigned long _interval;
    unsigned long lapsed;
    TimerState state;
    
    typedef void (*Action) (void);

    Action onStart;
    Action onPause;
    Action onStop;
    Action onResume;
    Action onTick;

    void setDefault();

public:
    Timer();
    Timer(Action fn, unsigned long interval);
    ~Timer();

    unsigned long GetInterval();
    
    /* @brief Configura el intervalo de tiempo que debe trasncurrir desde la ultima ejecución de la acción
    */
    void SetInterval(unsigned long interval);

    /* @brief Devuelve el estado del objeto: Detenido, pausado o iniciado.
    */
    TimerState GetState();

    /* @brief Inicia el parpadeo.
    */
    void Start();

    /* @brief Detiene el parpadeo sin reiniciar el estado de las variables de control.
    */
    void Pause();

    /* @brief Reinicia el parpadeo desde donde lo dejo.
    */
    void Resume();

    /* @brief Detiene y reinicia las varaibles asociadas al control del parpadeo.
    */
    void Stop();

    /* @brief Ejecuta un ciclo del parpadeo. Es obligatorio ubicarlo en la función loop.
    */
    void Loop();

    void OnStart( Action fn ){
        onStart = fn;
    }

    void OnPause( Action fn ){
        onPause = fn;
    }

    void OnStop( Action fn ){
        onStop = fn;
    }

    void OnResume( Action fn ){
        onResume = fn;
    }

    void OnTick( Action fn ){
        onTick = fn;
    }
};

#endif