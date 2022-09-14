
/*
 Author: Aman Gusain
 Purpose: THis code recieves input from user and blinks it as a morse code.
          User can provide input at any instance when the code is running.
*/
// the setup function runs once when you press reset or power the board

const int same_delay = 1000;  //one unit delay
int letter_delay = 3000;  //three unit delay
int space_delay = 7000;   //seven unit delay
int next_line = 5000; 
const int arr_size = 50;
char nameString[arr_size];

//1 = dot, 2 = dash, 3 = empty;
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  letter_delay -= same_delay; //to account for delay in interpret function.
  //next_line -= same_delay;
}

// the loop function runs over and over again forever
void loop() {
  if(Serial.available() > 0) recieve_input(nameString);
  blink_array(nameString);

  delay(next_line);
}

void blink_array(char nameString[])   //blinks the array
{
  for(int i = 0; i < arr_size - 1; i++)
  {
    if(nameString[i + 1] != '\0')
    {
      write_letter(nameString[i]);
      delay(letter_delay);
    } else 
    {
      write_letter(nameString[i]);  //for the last letter
      break;
    }
  }

}
void recieve_input(char nameString[])   //recieves input from user
{
  char namechar;

  for(int i = 0; i < arr_size - 1; i++)
  {
    if(Serial.available() > 0)
    {
      namechar = Serial.read();
      nameString[i] = namechar;
    }
    else
    {
      nameString[i + 1] = '\0';
      break;
    }
  }
}
void dot()
{
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(same_delay);                       // wait for one unit time
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
}


void dash()
{
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(3*same_delay);                       // wait for three unit time
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
 }

 void letter(int a, int b, int c, int d)    //processes the morse code
 {
    interpret(a);
    interpret(b);
    interpret(c);
    interpret(d);
 }

 void interpret(int i)    //interprets the integer in the letter
 {
  if(i == 1) 
  {
    dot();
    delay(same_delay);
  }
  else if(i == 2) 
  {
    dash();
    delay(same_delay);
  }
  else if(i == 4)
  {
    delay(space_delay);    //for space between names;
  }
  else return;
 }

 void write_letter(char alpha)    //contains morse code for the letters.
 {
  switch(alpha)
  {
  case 'a': letter(1, 2, 3, 3);
  break;
  case 'b': letter(2, 1, 1, 1);
  break;
  case 'c': letter(2, 1, 2, 1);
  break;
  case 'd': letter(2, 1, 1, 3);
  break;
  case 'e': letter(1, 3, 3, 3);
  break;
  case 'f': letter(1, 1, 2, 1);
  break;
  case 'g': letter(2, 2, 1, 3);
  break;
  case 'h': letter(1, 1, 1, 1);
  break;
  case 'i': letter(1, 1, 3, 3);
  break;
  case 'j': letter(1, 2, 2, 2);
  break;
  case 'k': letter(2, 1, 2, 3);
  break;
  case 'l': letter(1, 2, 1, 1);
  break;
  case 'm': letter(2, 2, 3, 3);
  break;
  case 'n': letter(2, 1, 3, 3);
  break;
  case 'o': letter(2, 2, 2, 3);
  break;
  case 'p': letter(1, 2, 2, 1);
  break;
  case 'q': letter(2, 2, 1, 2);
  break;
  case 'r': letter(1, 2, 1, 3);
  break;
  case 's': letter(1, 1, 1, 3);
  break;
  case 't': letter(2, 3, 3, 3);
  break;
  case 'u': letter(1, 1, 2, 3);
  break;
  case 'v': letter(1, 1, 1, 2);
  break;
  case 'w': letter(1, 2, 2, 3);
  break;
  case 'x': letter(2, 1, 1, 2);
  break;
  case 'y': letter(2, 1, 2, 2);
  break;
  case 'z': letter(2, 2, 1, 1);
  break;
  case ' ': letter(4, 3, 3, 3);
  break;
  }
 }
