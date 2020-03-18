#include <stdio.h>
#include <math.h>

const NMAX=10; //numero maximo de filas y de columnas
const NCASILLASBARCOS=4*1+3*2+2*3+1*4;// sumatoria de "cantidad de casillas de un barco" x "cantidad de barcos"


/*
GRAFICAR_TABLERO:
Dibuja cualquiera de los tableros segun su contenido grafica "@"=agua "X"= tocado etc.
el parametro que le llega puede ser cualquier Tablero que es una matriz de 10x10
*/
void GRAFICAR_TABLERO(int T[NMAX][NMAX])
{
  int i,j;  
  printf("\n\n  ");
  for (j=0;j<NMAX;j++)
  {
    printf("%d",j);
  }
  printf("\n\n");
  for (i=0;i<NMAX;i++)
  {
    printf("%d ",i);
    for (j=0;j<NMAX;j++)
    {
      switch(T[i][j])
      {
        case 0: printf(" "); break;//nada
        case 1: printf("#"); break;//barco
        case 2: printf("@"); break;//agua
        case 3: printf("X"); break;//tocado        
        case 5: printf("H"); break;//se dibuja con H los barcos hundidos
      }
    }
    printf("\n");
  }
  printf("\n\n");
}


/*
HAY_ROCE:
Segun la ubicacion(nf.nc), si es vertical u horizontal(op), el tablero (la matriz) y el tamaño del barco
hace el calculo si choca un barco con otro o si choca con los bordes
devuelve verdadero(1) si toca con algo y falso(0) en caso contrario
*/
int HAY_ROCE(int nf,int nc,char op,int T[NMAX][NMAX],int tamanioBarco)
{
  int roce,i,j;

  roce=0;
  if(op!='v')
  {
    if(nc+tamanioBarco>NMAX)
    {
      roce=1;
    }
    else
    {
      for (i=nf-1;((i<nf+2)&&(i<NMAX));i++)
      {
        for (j=nc-1;((j<tamanioBarco+nc+1)&&(j<NMAX));j++)
        {
          if(T[i][j]!=0)
          {
            roce=1;
          }
        }
      }
    }
  }
  else
  {
    if(nf+tamanioBarco>NMAX)
    {
      roce=1;
    }
    else
    {    
      for (i=nf-1;((i<tamanioBarco+nf+1)&&(i<NMAX));i++)
      {
        for (j=nc-1;((j<nc+2)&&(j<NMAX));j++)
        {
          if(T[i][j]!=0)
          {
            roce=1;
          }
        }
      }
    }
  }

  if(roce)
  {
    printf("\nEl Barco se ha superpuesto con otro o sobrepasa los bordes,\nIntentelo nuevamente\n");
    getch();
  }

  return roce;
}



/*
PONER_BARCO_EN_EL_TABLERO:
Segun el tamaño del barco(tamanioBarco) y el tablero que llega como parametro(T)
se agrega el barco ya sea vertical u horizontal siempre tomando como referencia el numero de filas
y numero de columnas
si es vertical  
OXXX 
si es horizontal
O
X
X
X
siendo O la posicion puesta con numero de filas(nf) y numero de columnas(nc)
*/
void PONER_BARCO_EN_EL_TABLERO(int tamanioBarco,int T[NMAX][NMAX],char jugador[NMAX])
{
  int nc,nf,k;
  char op;
  do
  {
    clrscr();
    printf("Tablero del %s",jugador);
    GRAFICAR_TABLERO(T);
    printf("Tama¤o del barco %d. Ingrese nro de fila y luego nro de columna\n",tamanioBarco);
    scanf("%d",&nf);
    scanf("%d",&nc);
    printf("Ingresar v=Vertical o cualquier otro valor para Horizontal\n");
    op=getch();
  }
}

/*
CARGAR_BARCOS
Solo llama varias veces a la funcion PONER_BARCO_EN_EL_TABLERO
llega como parametros el jugador y el tablero a llenar
*/
void CARGAR_BARCOS(char jugador[NMAX],int T[NMAX][NMAX])
{

  PONER_BARCO_EN_EL_TABLERO(4,T,jugador);//barco de 4 casillas
  PONER_BARCO_EN_EL_TABLERO(3,T,jugador);//barco de 3 casillas
  PONER_BARCO_EN_EL_TABLERO(3,T,jugador);//barco de 3 casillas
  PONER_BARCO_EN_EL_TABLERO(2,T,jugador);//barco de 2 casillas
  PONER_BARCO_EN_EL_TABLERO(2,T,jugador);//barco de 2 casillas
  PONER_BARCO_EN_EL_TABLERO(2,T,jugador);//barco de 2 casillas
  PONER_BARCO_EN_EL_TABLERO(1,T,jugador);//barco de 1 casillas
  PONER_BARCO_EN_EL_TABLERO(1,T,jugador);//barco de 1 casillas
  PONER_BARCO_EN_EL_TABLERO(1,T,jugador);//barco de 1 casillas
  PONER_BARCO_EN_EL_TABLERO(1,T,jugador);//barco de 1 casillas
}

////////////////////////////////////////////////////////
//////// COMIENZO DE LA SEGUNDA PARTE, J1 VS J2     ///
////////////////////////////////////////////////////////

/*
BARCOS_ALREDEDOR
Se le mandan las coordenadas del disparo y se serciora si alrededor hay alguna continuacion del barco
de ser asi devuelve verdadero si lo hay y falso de lo contrario
sirve mas que nada para saber si el barco se ha hundido
*/
int BARCOS_ALREDEDOR(int inicioFilas,int inicioColumnas,int Tablero[NMAX][NMAX],int TableroEnemigo[NMAX][NMAX])
{
  int i,j;
  int barcoAlrededor=0;
  int nFilas=inicioFilas+3;
  int nColumnas=inicioColumnas+3;

  if(inicioFilas<0)
    inicioFilas++;
  if(inicioColumnas<0)
    inicioColumnas++;
  for (i=inicioFilas;((i<nFilas)&&(i<NMAX));i++)
  {
    for (j=inicioColumnas;((j<nColumnas)&&(j<NMAX));j++)
      {
        if((TableroEnemigo[i][j]==1)&&(Tablero[i][j]!=3))
        {
          barcoAlrededor=1;
        }
      }
  }  
  return barcoAlrededor;
}


/*
GRAFICAR_REGLAS
Solo escribe los simbolos que se grafican en un tablero
*/
void GRAFICAR_REGLAS()
{
  printf("\n\n");
  printf("Simbologia\n");
  printf("#: mi casillero\n");
  printf("@: agua\n");
  printf("X: barco que fue tocado\n");
  printf("H: casilleros de barcos hundidos\n");
  printf("\n\n");
}


/*
PINTAR_ZONA_HUNDIDO
Esta funcion lo que hace es cambiar valores de la tabla para que al graficar el tablero escriba
una "H" en el lugar de las "X" cuando el barco esta hundido
*/
void PINTAR_ZONA_HUNDIDO(int inicioI,int inicioJ,int Tablero[NMAX][NMAX])
{
    
  //verificar a izquierda
  while ((inicioI-1>=0)&&(Tablero[inicioI-1][inicioJ]==3))
    inicioI--;
  //verificar hacia arriba
  while ((inicioJ-1>=0)&&(Tablero[inicioI][inicioJ-1]==3))
    inicioJ--;  
    
}



/*
TURNO_JUGADOR
Esta funcion se encarga de llamar al resto de las funciones para que se pinte una interfaz, de esa forma el jugador podra
ingresar las coordenadas de disparo, lleva el control de las balas y de los tableros
*/
void TURNO_JUGADOR(int &balas,int MiTablero[NMAX][NMAX],int TableroAnotador[NMAX][NMAX],int TableroEnemigo[NMAX][NMAX],
           char jugador[NMAX],char mensaje[50])
{
  int nf,nc;

  clrscr();
  printf("%s\n\n",jugador);
  GRAFICAR_REGLAS();
  printf("Mi Tablero\n");
  GRAFICAR_TABLERO(MiTablero);
  printf("Tablero Anotacion de Barcos enemigos\n");
  GRAFICAR_TABLERO(TableroAnotador);
  printf("Ingrese fila y columna a disparar\n");
  scanf("%d",&nf);
  scanf("%d",&nc);
  clrscr();
  if (TableroEnemigo[nf][nc]==1)
  {
    TableroAnotador[nf][nc]=3;
    if (!BARCOS_ALREDEDOR(nf-1,nc-1,TableroAnotador,TableroEnemigo))
    {
      printf("Barco Hundido!\n");
      PINTAR_ZONA_HUNDIDO(nf,nc,TableroAnotador);
    }
  }
  else
    TableroAnotador[nf][nc]=2;
  balas--;

  printf("Quedan %d balas",balas);
  GRAFICAR_TABLERO(MiTablero);
  GRAFICAR_TABLERO(TableroAnotador);
  printf("Presione una tecla para que juegue el siguiente jugador");
  getch();
  clrscr();
  printf("Presione una tecla para comenzar tu turno");
  getch();
}

void main()
{
  int balasJ1=10;
  int balasJ2=10;
  int J1TMisBarcos[NMAX][NMAX]=    {0,0,0,0,0,0,0,0,0,0,
                                    0,0,0,0,0,0,0,0,0,0,
                                    0,0,0,0,0,0,0,0,0,0,
                                    0,0,0,0,0,0,0,0,0,0,
                                    0,0,0,0,0,0,0,0,0,0,
                                    0,0,0,0,0,0,0,0,0,0,
                                    0,0,0,0,0,0,0,0,0,0,
                                    0,0,0,0,0,0,0,0,0,0,
                                    0,0,0,0,0,0,0,0,0,0,
                                    0,0,0,0,0,0,0,0,0,0,};

  int J1TBarcosEnemigo[NMAX][NMAX]={0,0,0,0,0,0,0,0,0,0,
                                    0,0,0,0,0,0,0,0,0,0,
                                    0,0,0,0,0,0,0,0,0,0,
                                    0,0,0,0,0,0,0,0,0,0,
                                    0,0,0,0,0,0,0,0,0,0,
                                    0,0,0,0,0,0,0,0,0,0,
                                    0,0,0,0,0,0,0,0,0,0,
                                    0,0,0,0,0,0,0,0,0,0,
                                    0,0,0,0,0,0,0,0,0,0,
                                    0,0,0,0,0,0,0,0,0,0,};
  //Tablero del Jugador 2
  int J2TMisBarcos[NMAX][NMAX]=    {0,0,0,0,0,0,0,0,0,0,
                                    0,0,0,0,0,0,0,0,0,0,
                                    0,0,0,0,0,0,0,0,0,0,
                                    0,0,0,0,0,0,0,0,0,0,
                                    0,0,0,0,0,0,0,0,0,0,
                                    0,0,0,0,0,0,0,0,0,0,
                                    0,0,0,0,0,0,0,0,0,0,
                                    0,0,0,0,0,0,0,0,0,0,
                                    0,0,0,0,0,0,0,0,0,0,
                                    0,0,0,0,0,0,0,0,0,0,};
  int J2TBarcosEnemigo[NMAX][NMAX]={0,0,0,0,0,0,0,0,0,0,
                                    0,0,0,0,0,0,0,0,0,0,
                                    0,0,0,0,0,0,0,0,0,0,
                                    0,0,0,0,0,0,0,0,0,0,
                                    0,0,0,0,0,0,0,0,0,0,
                                    0,0,0,0,0,0,0,0,0,0,
                                    0,0,0,0,0,0,0,0,0,0,
                                    0,0,0,0,0,0,0,0,0,0,
                                    0,0,0,0,0,0,0,0,0,0,
                                    0,0,0,0,0,0,0,0,0,0,};

  char mensaje[20];

  
  int turnoAlternado=1;//cambia a 1 y a 2 dependiendo el turno de cada jugador
  CARGAR_BARCOS("Jugador 1",J1TMisBarcos);//llama a cargar para poner los barcos de jugador 1
  CARGAR_BARCOS("Jugador 2",J2TMisBarcos);//llama a cargar para poner los barcos de jugador 1

  while ((balasJ1!=0)&&(balasJ2!=0))
  {
    if (turnoAlternado==1)
    {
      //aca llama todo para que el jugador uno juegue una vez terminado cambia turnoAlternado para que la proxima le toque al jugador 2
      TURNO_JUGADOR(balasJ1,J1TMisBarcos,J1TBarcosEnemigo,J2TMisBarcos,"Jugador 1",mensaje);
      turnoAlternado=2;
      if(GANADOR(J1TBarcosEnemigo))
        balasJ2=0;
    }
    else
    {
      //aca llama todo para que el jugador dos juegue una vez terminado cambia turnoAlternado para que la proxima le toque al jugador 1
      TURNO_JUGADOR(balasJ2,J2TMisBarcos,J2TBarcosEnemigo,J1TMisBarcos,"Jugador 2",mensaje);
      turnoAlternado=1;
      if(GANADOR(J2TBarcosEnemigo))
        balasJ1=0;
    }
  }
  clrscr();
  if (balasJ1>balasJ2)
  {
    printf("EL GANADOR ES EL JUGADOR 1");
  }
  else
  {
    printf("EL GANADOR ES EL JUGADOR 2");
  }
  getch();
}
