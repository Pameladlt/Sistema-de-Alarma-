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

unsigned int valor = 0;
float voltaje = 0;
float re = 0;
char datos[20];

char xd[20];
unsigned int value;
float luz;

void initADC(){
    TRISAbits.RA1 = 1; // Puerto A como entrada
    TRISBbits.RB4 = 1; 
    ADCON1 = 0b00001101; //TODOS LOS PUERTOS ANALÓGICOS PONIENDO TODO EL PUERTO EN 0
    ADCON0 = 0; //ADCON --> Escoge las fuentes de voltaje
    ADCON2 = 0b10100110; 
}

// Programa que lee temperatura, luminosidad y voltaje con ADCON

//void main(void) {
//    
//    config_Pic();
//    iniLCD();
//    initADC();
//    Clear_Display();
//    __delay_ms(100);
//    
//    while(1){
//  
//        Clear_Display();
//        
//        // Lee Voltaje
//        
//        Return_home();
//        print_in_LCD ("Voltaje:");
//        __delay_ms(100);   
//        valor = ADC_read(1);
//        voltaje = ((valor*4.4)/1023); 
//        sprintf(datos,"%.2f",voltaje);
//        print_in_LCD (datos);
//        __delay_ms(500);
//        
//        // Lee Temperatura
//        
//        Return_home();
//        print_in_LCD ("Temp:");
//        __delay_ms(100);   
//        valor = ADC_read(0);
//        voltaje = ((valor*4.875)/1023); 
//        sprintf(datos,"%.2f",voltaje);
//        print_in_LCD (datos);
//        __delay_ms(100);
        
//        Write_in_pos_LCD(2,0); // posicion (0,1)
//        
        // Lee Luminosidad

//        print_in_LCD ("Lumi:");
//        __delay_ms(100);   
//        value = ADC_read(0);
//        luz = ((value*4.875*100)/1023); 
//        sprintf(xd,"%.2f",luz);
//        print_in_LCD (xd);
//        __delay_ms(100);
//    }
//}


// Programa para cambiar la iluminacion del LCD con el PWM gracias a un LDR

//void main(void) {
//    
//    config_Pic();
//    iniLCD();
//    initADC();
//    ini_PWM ();
//    config_TMR2(16);
//    
//    Clear_Display();
//    __delay_ms(100);
//    
//    
//    while(1){
//
//
//        // Lee Luminosidad
//
//    
//        Return_home();
//        Clear_Display();
//        value = ADC_read(0);
//        luz = ((value*4.875*100)/1023); 
//        sprintf(xd,"%.2f",luz);
//        __delay_ms(500);
//        print_in_LCD (xd);
//
//
//        if((luz>0) && (luz<60)){
//            PWM_Frec_and_DC(1000,10,16);
//        }
//
//        if((luz>61) && (luz<120)){
//            PWM_Frec_and_DC(1000,60,16);
//        }
//
//        if(luz>121){
//            PWM_Frec_and_DC(1000,95,16);
//        }
//    
//    }
//}
    
//char password[5] = {1,2,3,4,5};
//char intento[5];
//char num1 = 0;
//char num2 = 0;
//char num3 = 0;
//char num4 = 0;
//char num5 = 0;
//int cont = 0;
//int cont2 = 0;
//int sino[5];
//int oscar = 0;
//int i, compare = 1;
//char p[20];
//
//void asignar(){
//    
//    if(voltaje > 1.9){
//         
//        num1 = 1;
//    }
//    if(voltaje > 1.3 && voltaje < 1.89){
//
//        num2 = 2;
//    }
//    if(voltaje > 0.95 && voltaje < 1.29){
//
//        num3 = 3;
//    }
//    if(voltaje > 0.77 && voltaje < 0.94){
//
//        num4 = 4;
//    }
//    if(voltaje > 0.6 && voltaje <0.76){
//
//        num5 = 5;
//    }
//}
//
//void reinicio(){
//    num1 = 0;
//    num2 = 0;
//    num3 = 0;
//    num4 = 0;
//    num5 = 0;
//}
//
//void regresiva(){
//    
//    char z[3];
//    for(int x = 20;x>0;x--){
//        Clear_Display();
//        Return_home();
//        sprintf(z,"%.2f",x);
//        print_in_LCD (z);
//        __delay_ms(1000);
//        
//    }
//}
//
//
//void main(void) {
//    
//    config_Pic();
//    iniLCD();
//    initADC();
//    Clear_Display();
//    __delay_ms(100);
//    Return_home();
//    print_in_LCD ("Ingresar pssw:");
//    
//    while(1){
//        
//        __delay_ms(100);
//        valor = ADC_read(1);
//        voltaje = ((valor*4.4)/1023); 
//        
//        if(voltaje > 0.5){
//            
//            __delay_ms(500);
//            reinicio();
//            cont++;
//            asignar();
//            
//            switch (cont){
//               
//                case 1: 
//                    if(num1 != 0){
//                        intento[0] = num1;
//                    }
//                    if(num2 != 0){
//                        intento[0] = num2;
//                    }
//                    if(num3 != 0){
//                        intento[0] = num3;
//                    }
//                    if(num4 != 0){
//                        intento[0] = num4;
//                    }
//                    if(num5 != 0){
//                        intento[0] = num5;
//                    }
//                    Write_in_pos_LCD(2,0);
//                    print_in_LCD ("*");
//                    break;
//                
//                case 2: 
//                    if(num1 != 0){
//                        intento[1] = num1;
//                    }
//                    if(num2 != 0){
//                        intento[1] = num2;
//                    }
//                    if(num3 != 0){
//                        intento[1] = num3;
//                    }
//                    if(num4 != 0){
//                        intento[1] = num4;
//                    }
//                    if(num5 != 0){
//                        intento[1] = num5;
//                    }
//                    print_in_LCD ("*");
//                    break;
//                case 3: 
//                    if(num1 != 0){
//                        intento[2] = num1;
//                    }
//                    if(num2 != 0){
//                        intento[2] = num2;
//                    }
//                    if(num3 != 0){
//                        intento[2] = num3;
//                    }
//                    if(num4 != 0){
//                        intento[2] = num4;
//                    }
//                    if(num5 != 0){
//                        intento[2] = num5;
//                    }
//                    print_in_LCD ("*");
//                    break; //******
//                case 4: 
//                    if(num1 != 0){
//                        intento[3] = num1;
//                    }
//                    if(num2 != 0){
//                        intento[3] = num2;
//                    }
//                    if(num3 != 0){
//                        intento[3] = num3;
//                    }
//                    if(num4 != 0){
//                        intento[3] = num4;
//                    }
//                    if(num5 != 0){
//                        intento[3] = num5;
//                    }
//                    print_in_LCD ("*");
//                    break;
//                case 5: 
//                    if(num1 != 0){
//                        intento[4] = num1;
//                    }
//                    if(num2 != 0){
//                        intento[4] = num2;
//                    }
//                    if(num3 != 0){
//                        intento[4] = num3;
//                    }
//                    if(num4 != 0){
//                        intento[4] = num4;
//                    }
//                    if(num5 != 0){
//                        intento[4] = num5;
//                    }
//                    print_in_LCD (intento[4]);
//                    break;
//                case 6:
//                    cont = 0;
//                    Clear_Display();
//                default:
//                    cont = 0;
//                    Clear_Display();
//                    break;
//            }
//        }
//        
//        if (cont == 5){
//            
//            cont = 0;
//            
//            for(i; i < 5 && compare; i++){
//                if(intento[i] != password[i]){
//                    compare = 0;
//                }
//            }
//            
//            if(compare == 0){
//                
//                cont2++;
//
//                PORTAbits.RA4 = 1; // BUZZER
//                __delay_ms(50);
//                PORTAbits.RA4 = 0;
//                __delay_ms(50);
//                PORTAbits.RA4 = 1;
//                __delay_ms(50);
//                PORTAbits.RA4 = 0;
//                __delay_ms(50);
//                PORTAbits.RA4 = 1;
//                __delay_ms(50);
//                PORTAbits.RA4 = 0;
//                __delay_ms(50);
//                Clear_Display();
//                print_in_LCD ("No");
//
//            }
//            else{
//                
//                Clear_Display();
//                sprintf(p,"%.2f",intento);
//                print_in_LCD(p);
//                        
//                PORTAbits.RA3 = _ON; // FOCO
//                __delay_ms(5000);
//                PORTAbits.RA3 = _OFF;;
//            
//            }  
//        }
//        if (cont2 == 6){
//            
//            cont2 = 0;
//            cont = 0;
//            regresiva();
//            
//        }
//        
//    }        
//}


//int a = 0;
//int b = 0;
//int c = 0;
//
//void bip(){
//    
//    BZZ = _ON;
//    __delay_ms(100);
//    BZZ = _OFF;
//    
////    PWM_Frec_and_DC(1000,50,16);
////    __delay_ms(100);
////    TMR2 = 0;
////    
//}
//
//void main(void) {
//    
//    config_Pic();
//    iniLCD();
//    initADC();
//    config_TMR2(16);
//    ini_PWM ();
//    Clear_Display();
//    __delay_ms(100);
//    
//    while(1){
//        
//        Return_home();
//        Clear_Display();
//        print_in_LCD ("Select mode");
//        
//        if(B1 == 1){
//            
//            bip();
//            a = 1;
//            
//            while ( a == 1){ // 0-5v
//                
//                valor = ADC_read(11);
//                Return_home();
//                Clear_Display();
//                print_in_LCD ("Modo 1:");
//                __delay_ms(100);
//                voltaje = ((valor*4.4)/1023); 
//                sprintf(datos,"%.2f",voltaje);
//                print_in_LCD (datos);
//                __delay_ms(300);
//                if (B2 == 1 || B3 == 1) a = 0;
//            
//            }
//        }
//        
//        if(B2 == 1){
//            
//            bip();
//            b = 1;
//            
//            while ( b == 1){ // 0-20
//                
//                valor = ADC_read(11);
//                Return_home();
//                Clear_Display();
//                print_in_LCD ("Modo 2:");
//                __delay_ms(100);
//                voltaje = ((valor*17.6)/1023); // Por 4
//                sprintf(datos,"%.2f",voltaje);
//                print_in_LCD (datos);
//                __delay_ms(300);
//                if (B1 == 1 || B3 == 1) b = 0;
//            
//            }
//        }
//        
//        if(B3 == 1){
//            
//            bip();
//            c = 1;
//            
//            while ( c == 1){ // Resistencia
//                
//                valor = ADC_read(1);
//                Return_home();
//                Clear_Display();
//                print_in_LCD ("Modo 3:");
//                __delay_ms(100);
//                voltaje = ((valor*4.4)/1023);
//                re = ((voltaje*1000)/(4.4-voltaje));
//                sprintf(datos,"%.2f",re);
//                print_in_LCD (datos);
//                __delay_ms(300);
//                if (B1 == 1 || B2 == 1) c = 0;
//            
//            }
//        }
//    }
//}

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

