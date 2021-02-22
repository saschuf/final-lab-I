void setup() {
  // Abre el puerto serie en 9600 bps
  Serial.begin(9600);

  // LDC
  lcd.init();
  lcd.backlight();

  // LED
  pinMode(led, OUTPUT);

  // Interrupción botón
  interrupts();
  pinMode(boton, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(boton), botonPresionado, CHANGE);
}
