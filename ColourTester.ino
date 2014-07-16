// ---------- INCLUDES
#include<TN.h>

int r = 0, g=0, b=0;

int button = 0;
int prevButton = 0;
int knob = 0;
int prevKnob = 0;
int state = 0;

TN Tn = TN(-1.0,1.0);

void setup () {
  Serial.begin(115200);
}


void loop () {
  prevButton = button;
  button = Tn.sw();
  prevKnob = knob;
  knob = floor(255.0*Tn.pot());
  if (button & !prevButton) state = (state + 1) % 3;
  switch (state) {
    case 0:
      if (knob != prevKnob) r = knob;
      break;
    case 1:
      if (knob != prevKnob) g = knob;
      break;
    default:
      if (knob != prevKnob) b = knob;
      break;
  }
  Serial.print(r);
  Serial.print(", ");
  Serial.print(g);
  Serial.print(", ");
  Serial.println(b);
  Tn.colour(r,g,b);
  
  delay(10);
}

