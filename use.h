// Cambiar el estado de led                                         // Probar agregar el led como argumento
void toggleLed(int led) {
  if (digitalRead(led) == HIGH) {
    digitalWrite(led, LOW);
  } else {
    digitalWrite(led, HIGH);
  }
}

void alertar(int led, char* mensaje) {

  lcd.clear();
  lcd.print(mensaje);
  
  for (int i=0; i<4; i++) {
    if (digitalRead(led) == HIGH) {
      digitalWrite(led, LOW);
      delay(200);
    } else {
      digitalWrite(led, HIGH);
      delay(200);
    }
  }
}

// Mostrar log en LCD
void log(char* a, char* b = "") {
  lcd.clear();
  lcd.print(a);
  lcd.setCursor(0, 1);
  lcd.print(b);
}

void playsong() {
    for (int thisNote = 0; thisNote < songLength; thisNote++){
      // determine the duration of the notes that the computer understands
      // divide 1000 by the value, so the first note lasts for 1000/8 milliseconds
      int duration = 1000/ durations[thisNote];
      tone(11, melody[thisNote], duration);
  
      // stop the tone
      noTone(11);
    }
    
    for (int i=0;i<203;i++){               //203 is the total number of music notes in the song
      int wait = duration[i] * songspeed;
      tone(buzzer,notes[i],wait);          //tone(pin,frequency,duration)
      delay(wait);                         //delay is used so it doesn't go to the next loop before tone is finished playing
    }
}

// INTERRUPCIÓN -> Cuando el usuario apreta el botón
void botonPresionado() {
  
  // Tiempo a restar para que el temporizado comience de cero
  tiempoEscoria = millis();

  // Cambia el estado del LED
  toggleLed(led);

  // Cambia variable bool para comenzar
  empezar = 1;

  delay(500);
}

/**
 *    LED ASINCRONO
 */
//void prenderLedAsincrono() {
//  digitalWrite(led, LOW);
//  unsigned long currentMillis = millis();
//  
//  if (currentMillis - previousMillis >= interval) {
//    // save the last time you blinked the LED
//    previousMillis = currentMillis;
//
//    // if the LED is off turn it on and vice-versa:
//    if (ledState == LOW) {
//      ledState = HIGH;
//    } else {
//      ledState = LOW;
//    }
//
//    // set the LED with the ledState of the variable:
//    digitalWrite(led, ledState);
//  }
//}
