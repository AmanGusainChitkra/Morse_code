
// the setup function runs once when you press reset or power the board
const int same_delay = 1000;
int letter_delay = 3000;  
int next_line = 5000; 
//1 = dot, 2 = dash, 3 = empty;
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
 
}

// the loop function runs over and over again forever
void loop() {
  dot();
  delay(same_delay);  //A
  dash();
  delay(letter_delay);

  dash();
  delay(same_delay);    //M
  dash();
  delay(letter_delay);

    dot();
  delay(same_delay);  //A
  dash();
  delay(letter_delay);

  dash();
  delay(same_delay);  //N
  dot();
  
  
  delay(next_line);
}


void dot()
{
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(same_delay);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
}


void dash()
{
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(letter_delay);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
 }

