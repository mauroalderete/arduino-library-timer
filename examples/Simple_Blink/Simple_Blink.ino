#include <Timer.h>
#include <Lolin3.h>

Timer timer;
bool status;

void setup() {

  pinMode(LED_BUILTIN, OUTPUT);
  status = false;

  timer.SetInterval(500);
  timer.OnTick(Blink);

  timer.Start();
}

void loop() {
  timer.Loop();
}

void Blink(){
  status = !status;
  if (status) {
    digitalWrite(LED_BUILTIN, HIGH);
  } else {
    digitalWrite(LED_BUILTIN, LOW);
  }
}
