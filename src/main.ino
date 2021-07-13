#include <Rc5Renderer.h>
#include <IrSenderPwm.h>

IrSender *sender;
int but_input = 2;
int but_pwr = 4;
int but_vol_up = 19; // A5
int but_vol_down = 18; //A4

void setup() {
  // Input button setup
  pinMode(but_input, INPUT);
  digitalWrite(but_input, HIGH);
  // Power button setup
  pinMode(but_pwr, INPUT);
  digitalWrite(but_pwr, HIGH);
  // Vol Up button setup
  pinMode(but_vol_up, INPUT);
  digitalWrite(but_vol_up, HIGH);
 // Vol Down button setup
  pinMode(but_vol_down, INPUT);
  digitalWrite(but_vol_down, HIGH);

  sender = IrSenderPwm::getInstance(true);
}

void loop() {
  if (digitalRead(but_input) == LOW) {
    const IrSignal *signal = Rc5Renderer::newIrSignal(0, 56);
    sender->sendIrSignal(*signal);
    delay(1000);
  }
  if (digitalRead(but_pwr) == LOW) {
    const IrSignal *signal = Rc5Renderer::newIrSignal(0,12);
    sender->sendIrSignal(*signal);
    delay(1000);
  }
  if (digitalRead(but_vol_up) == LOW) {
    const IrSignal *signal = Rc5Renderer::newIrSignal(0,16);
    sender->sendIrSignal(*signal);
    delay(1000);
  }
    if (digitalRead(but_vol_down) == LOW) {
    const IrSignal *signal = Rc5Renderer::newIrSignal(0,17);
    sender->sendIrSignal(*signal);
    delay(1000);
  }
}
