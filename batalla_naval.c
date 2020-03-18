#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>

// Posiciones: '0'=desocupado | '1'=Hay barco | '2'=Barco destruido

void wait(int seconds) // Funcion 'clock' para el tiempo de juego
{
    clock_t endwait;
    endwait = clock() + seconds * CLOCKS_PER_SEC;
    while( clock() < endwait )
    {}
}

void imprimir();
void iniciar();

int i, j, k, jugador[6][10], oponente[6][10], opcion1, opcion2, puntajejugador=0, puntajeoponente=0; // Variables globales
time_t start,end;
double dif, tiempototal=0;

//________________________________________________________________________________________________
void imprimir() // Funcion que imprime el tablero de juego
{  
    printf("\t\t\t\t\t    Tiempo transcurrido= %.1f segundos\n\n", tiempototal);
     
    for(i=1;i<=5;i++) // Imprime tablero del oponente
    {
        printf("\n\t");
        for(j=1;j<=9;j++)
        {
            if(oponente[i][j]==3)
            { 
                printf("  #"); 
            }
            else
            {
                if(oponente[i][j]==2) // Imprime 'X' si vale 2
                { 
                    printf("  X"); 
                }
                else
                { 
                    printf("  -"); 
                } 
            }                                     
        }
        if(i==3)
        { 
            printf("\tOPONENTE"); 
        }
        else
        {
            if(i==1)
            { 
                printf("\t\t\tPuntaje oponente: %d", puntajeoponente); 
            }
        }
    }
     
    printf("\n\n\t_____________________________\n\n");
     
    for(i=1;i<=5;i++) // Imprime el tablero del jugador
    {
        printf("\n\t");
        for(j=1;j<=9;j++)
        {
            if(jugador[i][j]==3)
            { 
                printf("  #"); 
            }
            else
            {
                if(jugador[i][j]==2) // Imprime 'X' si vale 2 || 'O' si vale 1
                { 
                    printf("  X"); 
                }
                else
                {
                    if(jugador[i][j]==1)
                    { 
                        printf("  O"); 
                    }
                    else
                    { 
                        printf("  -"); 
                    }
                }
            }                                     
        }
        if(i==3)
        { 
            printf("\tJUGADOR"); 
        }
        else
        {
            if(i==1)
            { 
                printf("\t\t\tPuntaje jugador: %d", puntajejugador); 
            }
        }
    }
  
    printf("\n\n");   
}
 //_______________________________________________________________________________________________

void iniciar() // Rellena con '0' el arreglo y coloca los barcos
{
          
    for(i=1;i<=5;i++) // Llena todo con '0'
    {
        for(j=1;j<=9;j++)
        {
            jugador[i][j]=0;
            oponente[i][j]=0;
        }
    }
     
    printf("\n\n Dame las coordenadas de tus barcos~\n\n");
     
    srand(time(NULL));
    for(k=1;k<=5;k++) // Distribuye los barcos
    {
        imprimir();
                       
        i=1+rand()%5; // Distribuye los barcos oponentes
        j=1+rand()%9; 
        while(oponente[i][j]==1)
        { 
            i=1+rand()%5; j=1+rand()%9; 
        }
        oponente[i][j]=1; // La posicion de los barcos valdra 1
                       
        printf("\n\tX%d = ", k);
        scanf("%d", &opcion2);
        while(opcion2<1 || opcion2>9)
        { 
            printf("    Escoje un valor valido ( 1 a 9 )\n\n\tX%d = ", k);
            scanf("%d", &opcion2);
        }
                         
        printf("\n\tY%d = ", k);
        scanf("%d", &opcion1);
        while(opcion1<1 || opcion1>5)
        { 
            printf("\n    Escoje un valor valido ( 1 a 5 )\n\n\tY%d = ", k);
            scanf("%d", &opcion1); 
        }
                         
        if(jugador[opcion1][opcion2]==1)
        {
            printf("\n Ese valor ya existe...");
            getche();
            k=k-1;
        }
        jugador[opcion1][opcion2]=1;
                       
        system("cls"); 
                                                          
    }   
     
}

//________________________________________________________________________________________________

main() // Inicia el programa (main)
{
    int res, auxiliar, probabilidadcpu, destruidosoponente=0, destruidosjugador=0, ganador;
    float dificultadcpu=0.5; 
      
    system("color 0B");

    printf("\n\n\t    ~BATALLA NAVAL~\n\n\t\t#\n\t\t#|\n\t\t#|#\n\t\t#|##\n\t\t#|###\n\t\t#|####");
    printf("\n\t\t#|#####\n\t\t#|######\n\t#########################\n\t _______________________");
    printf("\n\t  ####/)###############\n\t   ###(/##############\n\t    #################\n\t     ###############");
    printf("\n\n\n\t1- JUGAR\n\n\t2- SALIR\n\n\n\tDame tu opcion:");
    scanf("%d", &res);
    system("cls");
       
    switch(res)
    { // Eliges la opcion Jugar o Salir
       
       case 1:
       {
           iniciar(); // Llama a la funcion iniciar
           printf("\n\n\n\t\t Preparado?\n\n");
           wait(2);
           printf("\n\t\t AHORA!!!");
           wait(1);
                              
           do
           {
               time(&start);
               system("cls"); // Limpia la pantalla 
                                
               imprimir();
                                
               printf(" Es tu turno! Dame la posicion que deseas atacar~\n\n");
               printf("\tX = ");
               scanf("%d", &opcion2);
               while(opcion2<1 || opcion2>9)
               { 
                   printf("\n    Escoje un valor valido ( 1 a 9 )\n\n\tX = ");
                   scanf("%d", &opcion2); 
               }
                                
               printf("\tY = ");
               scanf("%d", &opcion1);
               while(opcion1<1 || opcion1>5)
               { 
                   printf("\n    Escoje un valor valido ( 1 a 5 )\n\n\tY = ");
                   scanf("%d", &opcion1); 
               }
                                
               auxiliar=oponente[opcion1][opcion2];
               oponente[opcion1][opcion2]=3;
               system("cls");
               imprimir();
               oponente[opcion1][opcion2]=auxiliar;                           
                                
               if(oponente[opcion1][opcion2]==1)
               {
                   oponente[opcion1][opcion2]=2;
                   destruidosoponente=destruidosoponente+1;
                   puntajejugador=puntajejugador+200;
                   printf("\n Haz acertado!!\n\n");
               }
               else
               {
                   printf("\n Haz fallado...\n\n");
               }
                                
               system("PAUSE");
               system("cls");
               if(destruidosoponente==5)
               { 
                   printf("\n\n\n\n\t\t\tHAZ GANADO!!");
                   getche();
               }                                                                
               imprimir();
                                
               printf(" Turno del oponente!~\n\n");
               wait(2);
                                
               dificultadcpu=dificultadcpu+0.1;
                                
               srand(time(NULL));
                                
               probabilidadcpu=rand()%5;
                                
               if(probabilidadcpu>dificultadcpu)
               {
                   i=1+rand()%5;
                   j=1+rand()%9;
                   while(jugador[i][j]==2)
                   { 
                       i=1+rand()%5; j=1+rand()%9; 
                   }
                   auxiliar=jugador[i][j];
               }
               else
               {
                   while(jugador[i][j]==2 || jugador[i][j]!=1)
                   { 
                       i=1+rand()%5; j=1+rand()%9; 
                   }
                   auxiliar=jugador[i][j]; 
               }              
                                
               jugador[i][j]=3;
               opcion1=i;
               opcion2=j;
               system("cls");
               imprimir();
               jugador[opcion1][opcion2]=auxiliar;
                                
               if(jugador[opcion1][opcion2]==1)
               {
                   printf("\n El oponente ha acertado!!\n\n");
                   jugador[opcion1][opcion2]=2;
                   destruidosjugador=destruidosjugador+1;
                   puntajeoponente=puntajeoponente+200;
               }
               else
               {
                   printf("\n El oponente ha fallado...\n\n");
               }
               if(destruidosjugador==5)
               {     
                   system("cls");                                                
                   printf("\n\n\n\n\t\t\tHAZ PERDIDO!!");
                   getche();
               } 
               system("PAUSE");
               if(destruidosoponente==5 || destruidosjugador==5)
               { 
                   destruidosoponente=5; destruidosjugador=5; 
               }
               time(&end);
               dif = difftime (end,start);
               tiempototal=tiempototal+dif;
               if(tiempototal>600)
               { 
                   system("cls");
                   printf("\n\n\n\t\tSe acabo el tiempo de juego... HAZ PERDIDO!!");
                   getche();
               }
           }
           while(destruidosoponente<5 || destruidosjugador<5);
       }
                                
    } // Termina switch(res)
                 
} // Termina el programa (main)


//________________________________________________________________________________________________