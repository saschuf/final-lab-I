LiquidCrystal_I2C lcd(0x27, 16, 2);

/**
 *    VARIABLES GLOBALES
 */
const int led = 8;
const byte boton = 2;
unsigned long tiempoEscoria;
unsigned long estudio = 1;              // Minutos de estudio
unsigned long pausa = 1;                // Minutos de pausa
bool empezar;


/** 
 *    LED ASINCRONO
 *    @URL: https://www.arduino.cc/en/Tutorial/BuiltInExamples/BlinkWithoutDelay
 */
int ledState = LOW;
unsigned long previousMillis = 0;        // guarda la ultima vez que se actualizo el led
const long interval = 3000;              // intervalo de blinkeo (milliseconds)
