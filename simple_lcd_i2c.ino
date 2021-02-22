/**
 *    Librerias
 */
#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

/**
 *    Variables Globales
 */
#include "config.h"

/**
 *    Musica
 */
#include "pitches.h"
#include "melodia.h"

/**
 *    Funciones
 */
#include "use.h"
#include "intervalo.h"

/** 
 *      SETUP
 */
#include "setup.h"

/**
 *      PROGRAMA
 */
void loop() {

  /**
   *    Mensaje de bienvenida && Espera interrupción
   *    
   *    @empezar
   */

  log("Bienvenido!");
  delay(1500);

  log("Apreta el boton", "para comenzar");

  do {
    delay(100);
  } while (empezar!=1);

  /*
   *   INICIO POMODORO: FASE ESTUDIO
   */
  intervalo("SESION INICIADA", estudio);
  toggleLed(led);

  /**
   *    FIN ESTUDIO: FASE PAUSA
   */
  alertar(led,"FIN ESTUDIO");
  intervalo("MOMENTO DE PAUSA", pausa);
  
  /**
   *    FIN PAUSA: FASE ESTUDIO
   */
  alertar(led, "FIN PAUSA");
  intervalo("A ESTUDIAR", estudio);
  
  /**
   *    FIN ESTUDIO: FASE PAUSA
   */
  alertar(led, "FIN ESTUDIO");
  intervalo("ULTIMA PAUSA", pausa);

  /**
   *      FIN SESIÓN
   */
  alertar(led, "FIN SESION");
  log("La sesion", "ha finalizado");
  
  // playsong();

  empezar = 0;
  
 }
