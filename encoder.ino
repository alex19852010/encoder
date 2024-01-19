const int clk = 4;
const int dt = 3;
const int sw = 2;

int counter = 0;
int currentstateclk;
int laststateclk;
unsigned long lastbuttonpress = 0;

void setup() {
  Serial.begin(9600);
  pinMode(clk, INPUT);
  pinMode(dt, INPUT);
  pinMode(sw, INPUT_PULLUP);
  laststateclk = digitalRead(clk);
}

void loop() {
  currentstateclk = digitalRead(clk);
  if(currentstateclk != laststateclk && currentstateclk == 1 )
  {
     if(digitalRead(dt) != currentstateclk )
     {
       counter ++;
     }

     else
     {
      counter --;
     }
  

  Serial.print("counter: ");
  Serial.println(counter);

}
laststateclk = currentstateclk;


int btnstate = digitalRead(sw);
if(btnstate == LOW)
{
  if(millis() - lastbuttonpress  > 100 )
  {
    Serial.println("button pressed");
  }
  lastbuttonpress = millis();
}

}
    
