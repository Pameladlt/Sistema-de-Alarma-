/*
 * File:   main.c
 * Author: 1027578400
 *
 * Created on 11 de octubre de 2019, 02:31 PM
 */

#pragma config PLLDIV = 1       // PLL Prescaler Selection bits (No prescale (4 MHz oscillator input drives PLL directly))
#pragma config CPUDIV = OSC1_PLL2// System Clock Postscaler Selection bits ([Primary Oscillator Src: /2][96 MHz PLL Src: /3])


// CONFIG1H
#pragma config FOSC = HSPLL_HS  // Oscillator Selection bits (HS oscillator, PLL enabled (HSPLL))
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enable bit (Fail-Safe Clock Monitor disabled)


// CONFIG2H
#pragma config WDT = OFF        // Watchdog Timer Enable bit (WDT disabled (control is placed on the SWDTEN bit))

// CONFIG3H
#pragma config MCLRE = ON       // MCLR Pin Enable bit (MCLR pin enabled; RE3 input pin disabled)

// CONFIG4L
#pragma config LVP = OFF        // Single-Supply ICSP Enable bit (Single-Supply ICSP disabled)


// CONFIG5H
#pragma config CPB = OFF        // Boot Block Code Protection bit (Boot block (000000-0007FFh) is not code-protected)
#pragma config CPD = OFF        // Data EEPROM Code Protection bit (Data EEPROM is not code-protected)

#include "LCD.h" 
#include <xc.h>
#include <stdio.h>

//Asignamos valor a las variables de los numeros
char num1 = '1';
char num2 = '2';
char num3 = '3';
char num4 = '4';
char num5 = '5';

//Variable para saber si las contraseñas son iguales 
int cor = 0;

//Arreglos en donde almacenaremos la contraseña y la contraseña temporal
char pwd[5] = {'1','2','3','4','5'};
char intento[5];

//Contador 
int cont = 1;
int next = 0;
int er = 0;
int despues = 0;
int xx = 0;
int listo = 0;
int ppp = 0;

//edo1

int guanta = 0;

void reinicio(){
    num1 = 0;
    num2 = 0;
    num3 = 0;
    num4 = 0;
    num5 = 0;
}

//FUNCION PARA HACER SONAR EL BUZZER MEDIO SEGUNDO
void bip_m(){
   
    BZZ = 1;
    __delay_ms(200);
    BZZ = 0;
    __delay_ms(200);
}
    
void regresiva(){
   
    Clear_Display();
    Return_home();
    print_in_LCD ("8");
    bip_m();
    bip_m();
    
    Clear_Display();
    Return_home();
    print_in_LCD ("7");
    bip_m();
    bip_m();
    
    Clear_Display();
    Return_home();
    print_in_LCD ("6");
    bip_m();
    bip_m();
    
    Clear_Display();
    Return_home();
    print_in_LCD ("5");
    bip_m();
    bip_m();
    
    Clear_Display();
    Return_home();
    print_in_LCD ("4");
    bip_m();
    bip_m();
    
    Clear_Display();
    Return_home();
    print_in_LCD ("3");
    bip_m();
    bip_m();
    
    Clear_Display();
    Return_home();
    print_in_LCD ("2");
    bip_m();
    bip_m();
    
    Clear_Display();
    Return_home();
    print_in_LCD ("1");
    bip_m();
    bip_m();
    
    Clear_Display();
    Return_home();
    print_in_LCD ("0");
    bip_m();
    bip_m();
    
    Return_home();
    Clear_Display();
   
    print_in_LCD ("Alarma activa");
    Write_in_pos_LCD(2,0);
    print_in_LCD ("(1)(2)(3)(4)(5)");
    __delay_ms(600);
   
}

void edo1(){
    
    Return_home();
    Clear_Display();
    print_in_LCD ("Activar: press 1");
    Write_in_pos_LCD(2,0);
    print_in_LCD ("(1)(2)(3)(4)(5)"); 
}

void edo2()
{
     //Estado 2: Escribir en el LCD
    if (B1 == 1 && next == 0){
        
        next = 1;
        guanta = 1;
        Clear_Display();
        Return_home();
        bip_m();
        print_in_LCD ("Ingresar psswd");
        Write_in_pos_LCD(2,0);
        print_in_LCD ("(1)(2)(3)(4)(5)");
        __delay_ms(800);
        Clear_Display();
        Return_home();   
    }
}

void edo3b()
{
    while(next == 1)
        {
          
            switch(cont)
            {
                case 1: 
                   
                    if (B1 == 1 )
                    {
                        __delay_ms(500);
                        intento[0] = '1';
                         print_in_LCD ("*");
                         bip_m();
                          cont++;
                    }
                    if (B2 == 1 )
                    {
                        __delay_ms(500);
                        intento[0] = '2';
                         print_in_LCD ("*");
                         bip_m();
                          cont++;
                    }
                    if (B3 == 1 )
                    {
                        __delay_ms(500);
                        intento[0] = '3';
                         print_in_LCD ("*");
                          cont++;
                          bip_m();
                    }
                    if (B4 == 1 )
                    {
                        __delay_ms(500);
                        intento[0] = '4';
                         print_in_LCD ("*");
                          cont++;
                          bip_m();
                    }
                    if (B5 == 1 )
                        
                    {
                        __delay_ms(500);
                        intento[0] = '5';
                         print_in_LCD ("*");
                         cont++;
                         bip_m();
                    }
                  
                    break;
                    
                    
                    case 2: 
                    if (B1 == 1 )
                    {
                        __delay_ms(500);
                        intento[1] = '1';
                         print_in_LCD ("*");
                          cont++;
                          bip_m();
                    }
                    if (B2 == 1 )
                    {
                        __delay_ms(500);
                        intento[1] = '2';
                         print_in_LCD ("*");
                          cont++;
                          bip_m();
                    }
                    if (B3 == 1 )
                    {
                        __delay_ms(500);
                        intento[1] = '3';
                         print_in_LCD ("*");
                          cont++;
                          bip_m();
                        
                    }
                    if (B4 == 1 )
                    {
                        __delay_ms(500);
                        intento[1] = '4';
                         print_in_LCD ("*");
                          cont++;
                          bip_m();
                    }
                    if (B5 == 1 )
                    {
                        __delay_ms(500);
                        intento[1] = '5';
                         print_in_LCD ("*");
                          cont++;
                          bip_m();
                    }
                    
                    break;
                    
                    case 3: 
                    if (B1 == 1 )
                    {
                        __delay_ms(500);
                        intento[2] = '1';
                         print_in_LCD ("*");
                         cont++;
                         bip_m();
                    }
                    if (B2 == 1 )
                    {
                         __delay_ms(500);
                        intento[2] = '2';
                         print_in_LCD ("*");
                         cont++;
                         bip_m();
                    }
                    if (B3 == 1 )
                    {
                         __delay_ms(500);
                        intento[2] = '3';
                         print_in_LCD ("*");
                         cont++;
                         bip_m();
                    }
                    if (B4 == 1 )
                    {
                        __delay_ms(500);
                        intento[2] = '4';
                         print_in_LCD ("*");
                         cont++;
                         bip_m();
                    }
                    if (B5 == 1 )
                    {
                        __delay_ms(500);
                        intento[2] = '5';
                         print_in_LCD ("*");
                         cont++;
                         bip_m();
                    }
                    
                    break;
                    
                    case 4: 
                    if (B1 == 1 )
                    {
                        __delay_ms(500);
                        intento[3] = '1';
                         print_in_LCD ("*");
                         cont++;
                         bip_m();
                    }
                    if (B2 == 1 )
                    {
                        __delay_ms(500);
                        intento[3] = '2';
                         print_in_LCD ("*");
                         cont++;
                         bip_m();
                    }
                    if (B3 == 1 )
                    {
                        __delay_ms(500);
                        intento[3] = '3';
                         print_in_LCD ("*");
                         cont++;
                         bip_m();
                    }
                    if (B4 == 1 )
                    {
                        __delay_ms(500);
                        intento[3] = '4';
                         print_in_LCD ("*");
                          cont++;
                          bip_m();
                    }
                    if (B5 == 1 )
                    {
                        __delay_ms(500);
                        intento[3] = '5';
                         print_in_LCD ("*");
                          cont++;
                          bip_m();
                    }
                   
                    break;
                    
                    case 5: 
                    if (B1 == 1 )
                    {
                        __delay_ms(500);
                        intento[4] = '1';
                         print_in_LCD ("*");
                         cont++;
                         bip_m();
                    }
                    if (B2 == 1 )
                    {
                        __delay_ms(500);
                        intento[4] = '2';
                         print_in_LCD ("*");
                         cont++;
                         bip_m();
                    }
                    if (B3 == 1 )
                    {
                        __delay_ms(500);
                        intento[4] = '3';
                         print_in_LCD ("*");
                         cont++;
                         bip_m();
                    }
                    if (B4 == 1 )
                    {
                        __delay_ms(500);
                        intento[4] = '4';
                         print_in_LCD ("*");
                          cont++;
                          bip_m();
                    }
                    if (B5 == 1 )
                    {
                        __delay_ms(500);
                        intento[4] = '5';
                         print_in_LCD ("*");
                          cont++;
                          bip_m();
                    }
                   
                    break;
                    
                case 6: 
                    next = 0;
                    cont = 1;
                break;
            }
                  
            
        }
}


void edo3()
{
    while(next == 1)
        {
          
            switch(cont)
            {
                case 1: 
                   
                    if (B1 == 1 )
                    {
                        __delay_ms(500);
                        intento[0] = '1';
                         print_in_LCD ("*");
                          cont++;
                    }
                    if (B2 == 1 )
                    {
                        __delay_ms(500);
                        intento[0] = '2';
                         print_in_LCD ("*");
                          cont++;
                    }
                    if (B3 == 1 )
                    {
                        __delay_ms(500);
                        intento[0] = '3';
                         print_in_LCD ("*");
                          cont++;
                    }
                    if (B4 == 1 )
                    {
                        __delay_ms(500);
                        intento[0] = '4';
                         print_in_LCD ("*");
                          cont++;
                    }
                    if (B5 == 1 )
                    {
                        __delay_ms(500);
                        intento[0] = '5';
                         print_in_LCD ("*");
                         cont++;
                    }
                  
                    break;
                    
                    
                    case 2: 
                    if (B1 == 1 )
                    {
                        __delay_ms(500);
                        intento[1] = '1';
                         print_in_LCD ("*");
                          cont++;
                    }
                    if (B2 == 1 )
                    {
                        __delay_ms(500);
                        intento[1] = '2';
                         print_in_LCD ("*");
                          cont++;
                    }
                    if (B3 == 1 )
                    {
                        __delay_ms(500);
                        intento[1] = '3';
                         print_in_LCD ("*");
                          cont++;
                        
                    }
                    if (B4 == 1 )
                    {
                        __delay_ms(500);
                        intento[1] = '4';
                         print_in_LCD ("*");
                          cont++;
                    }
                    if (B5 == 1 )
                    {
                        __delay_ms(500);
                        intento[1] = '5';
                         print_in_LCD ("*");
                          cont++;
                    }
                    
                    break;
                    
                    case 3: 
                    if (B1 == 1 )
                    {
                        __delay_ms(500);
                        intento[2] = '1';
                         print_in_LCD ("*");
                         cont++;
                    }
                    if (B2 == 1 )
                    {
                         __delay_ms(500);
                        intento[2] = '2';
                         print_in_LCD ("*");
                         cont++;
                    }
                    if (B3 == 1 )
                    {
                         __delay_ms(500);
                        intento[2] = '3';
                         print_in_LCD ("*");
                         cont++;
                    }
                    if (B4 == 1 )
                    {
                        __delay_ms(500);
                        intento[2] = '4';
                         print_in_LCD ("*");
                         cont++;
                    }
                    if (B5 == 1 )
                    {
                        __delay_ms(500);
                        intento[2] = '5';
                         print_in_LCD ("*");
                         cont++;
                    }
                    
                    break;
                    
                    case 4: 
                    if (B1 == 1 )
                    {
                        __delay_ms(500);
                        intento[3] = '1';
                         print_in_LCD ("*");
                         cont++;
                    }
                    if (B2 == 1 )
                    {
                        __delay_ms(500);
                        intento[3] = '2';
                         print_in_LCD ("*");
                         cont++;
                    }
                    if (B3 == 1 )
                    {
                        __delay_ms(500);
                        intento[3] = '3';
                         print_in_LCD ("*");
                         cont++;
                    }
                    if (B4 == 1 )
                    {
                        __delay_ms(500);
                        intento[3] = '4';
                         print_in_LCD ("*");
                          cont++;
                    }
                    if (B5 == 1 )
                    {
                        __delay_ms(500);
                        intento[3] = '5';
                         print_in_LCD ("*");
                          cont++;
                    }
                   
                    break;
                    
                    case 5: 
                    if (B1 == 1 )
                    {
                        __delay_ms(500);
                        intento[4] = '1';
                         print_in_LCD ("*");
                         cont++;
                    }
                    if (B2 == 1 )
                    {
                        __delay_ms(500);
                        intento[4] = '2';
                         print_in_LCD ("*");
                         cont++;
                    }
                    if (B3 == 1 )
                    {
                        __delay_ms(500);
                        intento[4] = '3';
                         print_in_LCD ("*");
                         cont++;
                    }
                    if (B4 == 1 )
                    {
                        __delay_ms(500);
                        intento[4] = '4';
                         print_in_LCD ("*");
                          cont++;
                    }
                    if (B5 == 1 )
                    {
                        __delay_ms(500);
                        intento[4] = '5';
                         print_in_LCD ("*");
                          cont++;
                    }
                   
                    break;
                    
                case 6: 
                    next = 0;
                    cont = 1;
                break;
            }
                  
            
        }
}

void check()
{
      for (int z = 0; z<5; z++){
        if (pwd[z] == intento[z])
        {
         cor++;
        }
        
    }
}


void saycheck(int listo)
{
    if (listo == 0)
        {
             if (cor == 5)
        {
         
         cor = 0;
         regresiva(); 
         listo = 1;
        }
        else
            if (cor > 0 && cor <5)
            {
                listo = 1;
                cor = 0;
                Clear_Display();
                Return_home();
                print_in_LCD("Error");
                guanta = 1;
            }
        
        }
}

void saycheck2(int listo2)
{
    if (listo2 == 0)
        {
             if (cor == 5)
        {
         listo2 = 1;
         cor = 0;
         regresiva(); 
         
        }
        else
            if (cor > 0 && cor <5)
            {
                
                listo2 = 1;
                 cor = 0;
                 Clear_Display();
                  Return_home();
                  print_in_LCD("Error");
                  
                  while(xx == 0){
                  LUZ = 1;
                  BZZ = 1;
                  edo2();
                  edo3();
                  
                  }
            }
        
        }
}

//FUNCION PARA HACER SONAR EL BUZZER 10 SEGUNDOS
void bip10(){
    
    BZZ = _ON;
    edo2();
    edo3();
    saycheck(0);
    __delay_ms(10000);
    
    BZZ = _OFF;
}

void main(void) {
    
    config_Pic();
    iniLCD();
    Clear_Display();
    __delay_ms(100);
    Return_home();
 
    while(1){
        
    // Estado 1: La alarma está desactivada o en modo espera. 
       //En ese momento se muestra en la pantalla
        if (guanta == 0)
        {
            edo1();
            BZZ = 0;
        }   
      
        edo2();
        edo3b();
        check();
        
        
        if (listo == 0 || ppp == 1){
        
            if (cor == 5){
        
            listo = 1;
            cor = 0;
            regresiva(); 
            ppp = 0;
            while(ppp == 0){
              if (ventana == 1 || MOV == 1 || BP == 1)
        {
           BZZ = _ON;
           Clear_Display();
           Return_home();
            __delay_ms(500);
           edo3();
           check();
           saycheck2(0);
           BZZ = 0;
           __delay_ms(8000);
              }
        }
            
           }
        else
            if (cor > 0 && cor <5)
            {
                listo = 1;
                cor = 0;
                Clear_Display();
                Return_home();
                print_in_LCD("Error");
                guanta = 0;
                ppp = 1;
            }
        }
       
        //Si el PWD de 5 dígitos es correcto, pasar a estado 3, si no, Mostrar ?error? en LCD y
    //regresar a Estado 1.
    //Estado 3: Hacer sonar un BIP de 1Khz cada medio segundo, durante 8 segundos y mientras
    //tanto mostrar la cuenta regresiva en el LCD. ?X segundos para activar? donde X es la
    //cuenta regresiva 8,7,6?.0. 
//        
//        
      
    
      
    
    }
}

