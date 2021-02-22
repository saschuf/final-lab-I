//void intervalo(char* a, unsigned long i) {
//   log(a);
//    
//    // Definición de variables de tiempo para mostrar como log
//    const int hrs_en_dia = 24; 
//    const int min_en_hrs = 60; 
//    const int seg_en_min = 60; 
//    unsigned long seg,min,hrs;
//  
//    // Comienza en loop hasta que tiempo transcurrido = i
//    do {
//      lcd.setCursor(0, 1);
//  
//        // Descomponer millis() en seg y minutos desde que se presionó el botón
//       min=(((millis()-tiempoEscoria)/1000));
//       seg=(((millis()-tiempoEscoria)/1000)/60);
//  
//       seg = seg % seg_en_min; 
//       min = min % min_en_hrs;
//  //   hrs = seg/seg_en_min/min_en_hrs % hrs_en_dia; 
//  
//        // Imprime el tiempo en pantalla como log
//       (seg < 10) ? lcd.print("0") : NULL;
//       lcd.print(seg);
//       lcd.print(":");
//       (min< 10) ? lcd.print("0") : NULL;
//       lcd.print(min);  
//
//       Serial.println('a',i/1000);
//       Serial.println('b',millis()-tiempoEscoria/1000);
//    } while (i/1000!=(millis()-tiempoEscoria)/1000);
//}

void intervalo(char* a, unsigned long intervalo) {
  log(a);

  lcd.setCursor(0, 1);
  for (int i=0; i<intervalo; i++) {
    for (int j=0; j<60; j++) {
      lcd.setCursor(5, 1);

      /**
       *    Minutos
       */
      (i<10) ? lcd.print("0") : NULL; lcd.print(i);
      
      lcd.print(":");

      /** 
       *    Segundos
       */
      (j<10) ? lcd.print("0") : NULL; lcd.print(j);

      delay(1000);
    }
  }
}
