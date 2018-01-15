void setup() {
  Sestial.begin(9600);
  //set all the pins we need to output pint
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  
  digitalWrite(12, HIGH);
  digitalWrite(11, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(8, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(6, HIGH);
 
}

void loop() {
  if (Serial.available()) {
    //read serial as character
    char ser = Serial.read();

    //NOTE becuase the serial is read as "char" and not "int", the read value must
    //hence the quotes around the numbers in the case statement

    switch (ser) {
      case '0':
      digitalWrite(12, LOW);
      break;
      case '1':
      digitalWrite(12, HIGH);
      break;
      case '2':
      digitalWrite(11, LOW);
      break;
      case '3':
      digitalWrite(11, HIGH);
      break;
      case '4':
      digitalWrite(10, LOW);
      break;
      case '5':
      digitalWrite(10, HIGH);
      break;
      case '6':
      digitalWrite(9, LOW);
      break;
      case '7':
      digitalWrite(9, HIGH);
      break;
      case '8':
      digitalWrite(8, LOW);
      break;
      case '9':
      digitalWrite(8, HIGH);
      break;
      case '10':
      digitalWrite(7, LOW);
      break;
      case '11':
      digitalWrite(7, HIGH);
      break;
      case '12':
      digitalWrite(6, LOW);
      break;
      case '13':
      digitalWrite(6, HIGH);
      break;     
    }
  }
}
