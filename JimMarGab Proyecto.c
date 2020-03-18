//Autor: Jimenez Martinez Gabriel Geovanni
//Escuela: Universidad Nacional Autonoma De Mexico
//Fecha: 27/05/2012
//Programa: Juego de Batalla Naval

#include <stdio.h>

void matriz_usuario(char mu[5][4],char apuntador[3])
{
    int i,j,asignacion_a=65;
    for (i=0; i<5; i++)
    {
        for (j=0; j<4; j++)
        {
            mu[i][j]=asignacion_a++;
            if (apuntador[0]==mu[i][j]) mu[i][j]=42;
            if (apuntador[1]==mu[i][j]) mu[i][j]=42;
            if (apuntador[2]==mu[i][j]) mu[i][j]=42;
        }
    }
}

void imprime(char mu[5][4])
{
    int i,j;

    for (i=0; i<5; i++)
    {
        for (j=0; j<4; j++)
        {
            printf("|%c|\t",mu[i][j]);


        }
        printf("\n\n");
    }
}

void matriz_virtual(char mv[5][4])
{
    int i,j,asignacion_a=65;
    for (i=0; i<5; i++)
    {
        for (j=0; j<4; j++)
        {
            mv[i][j]=asignacion_a++;
        }
    }

}
void m_letras(char m_p[5][4])
{
    int i,j,asignacion_a=65;
    for (i=0; i<5; i++)
    {
        for (j=0; j<4; j++)
        {
            m_p[i][j]=asignacion_a++;
        }
    }

}

void nombre(char name[20])
{
    printf("INGRESA TU NICKNAME: ");
    gets(name);
    system("cls");
    printf("*****************************\nNICKNAME: %s \n*****************************\n",name);
}

void barcos(char b[3])
{
    int i,anterior,a=1;
    for(i=0; i<3;)
    {
        printf("INGRESA LA UBICACION DE TU BARCO %i: ",a);
        scanf("%c",&b[i]);
        fflush(stdin);
        if (b[i]>=65 && b[i]<=84)
        {
            if(b[i]>= 65 && b[i]<=90);
            else b[i]=b[i]-32;
            if (b[i]!=anterior)
            {
                anterior=b[i];
                i++;
                a++;
            }
            else printf("INGRESO UN BARCO EN OTRA POSICION \n");
        }
        else printf("OPCION INCORRECTA INGRESA UNA LETRA QUE SE ENCUENTRE DENTRO DEL TABLERO\n");
    }
}

void Maquina_tiro_aleatorio(char mu[5][4],int *x, int *j)
{
    int i,y;
    srand (time(NULL));
    do
    {
        *x=rand ()  %  5;
        *j=rand () %  4;
    }
    while(  mu[*x][*j] == 5 || mu[*x][*j] == 1 );

}


int tabla()
{
    int fallo=5;
    int asterisco=42;
    int carita=1;
    printf("***************************************\n%c=BARCO  %c=BARCO HUNDIDO %c=TIRO FALLADO\n***************************************\n\n",asterisco,carita,fallo);
}

void aleatorio(char ale[3])
{
    int i,numero;
    srand (time(NULL));
    do
    {
        i=0;
        for (; i<3; i++)
        {
            numero = rand () % 20 + 65;
            ale[i]=numero;
        }
    }
    while(ale[0]==ale[1] || ale[0]==ale[2] || ale[1] == ale[2]);
}

int menu()
{
    int p;
    printf("Bienvenido\n*****************************\n");
    printf("***************************\nAl Juego de Batalla Naval\n*****************************\n");
    printf("1.- <<<<<<<Jugar>>>>>>>>>>>>\n");
    printf("2.- <<<<<Como Jugar>>>>>>>>>>>>\n");
    printf("3.-<<<<<<<Salir>>>>>>>>>>>>>>\n");
    printf("Por favor ingrese una opcion: ");
    scanf("%i",&p);
    fflush(stdin);
    return p;
}

void como_jugar()
{
    printf("");
    printf("*****************************\n\n\t\t\t<<<<MODO DE JUGAR>>>>\n\n1<<COLOCA TRES BARCOS EN DIFERENTES POSICIONES\nTU TABLERO SE ENCUENTRA EN LA PARTE DE ARRIBA>>\n");
    printf("\n2<<DERRIBA LOS BARCOS DE LA MAQUINA [-TABLERO DE ABAJO-]\nATACANDO UNA POSICION [-LETRA-]\nDONDE CREAS QUE SE ENCUENTRE UN BARCO>>\n");
    printf("\n3<<EL JUEGO TERMINA HASTA QUE ALGUNO DE LOS DOS HALLA \nHUNDIDO TRES BARCOS>>\n");
    printf("\n\t\t    NOTA: OBSERVA QUE LA TECLA BLOQ MAYUS SE ENCUENTRE ENCENDIDA\n");
    tabla();
}

void lanzamiento_usuario(char mv[5][4],char mu[5][4],char m_op[5][4],char name[20],char ale[3])
{
    char k,t,m,i,anterior;
    int p=0,c=0,x=0,j=0,C=0,ne=0;
    do
    {
        if (p==0 )
        {
            printf("INGRESE EL PUNTO DONDE DESEA ATACAR: ");
            scanf("%s",&k);
            if (k>=65 && k<=84)
            {
                if(k==ale[0] || k==ale[1] || k==ale[2] )
                {
                    if(k!=anterior)
                    {
                        printf("Barco Hundido\n");
                        C++;
                        anterior=k;
                        system("pause");
                        system("cls");
                        printf("\n*****************************\nNICKNAME: %s \n***************************** \n\n",name);
                        imprime(mu);
                        tabla();
                        for (i=0; i<5; i++)
                        {
                            for (m=0; m<4; m++)
                            {
                                if(k==mv[i][m]) mv[i][m]=1;
                                printf("|%c|\t",mv[i][m]);
                            }
                            printf("\n\n");
                        }
                        printf("*****************************\nMAQUINA\n*****************************\n\n");
                    }
                    else printf("YA UTILIZO ESTA CORDENADA INTENTE OTRA 1 \n");
                }

                else
                {

                    if(k!=anterior)
                    {
                        printf("No dio en el blanco\n");
                        p++;
                        anterior=k;
                        system("pause");
                        system("cls");
                        printf("\n*****************************\nNICKNAME: %s \n***************************** \n\n",name);
                        imprime(mu);
                        tabla();
                        for (i=0; i<5; i++)
                        {
                            for (m=0; m<4; m++)
                            {
                                if (k==mv[i][m]) mv[i][m]=5;
                                printf("|%c|\t",mv[i][m]);
                            }
                            printf("\n\n");
                        }
                        printf("*****************************\nMAQUINA\n*****************************\n\n");
                    }
                    else printf("YA UTILIZO ESTA CORDENADA INTENTE OTRA \n");
                }
            } else printf("OPCION INCORRECTA INGRESA UNA LETRA QUE SE ENCUENTRE DENTRO DEL TABLERO\n");
        }
        if(p==1)
        {
            Maquina_tiro_aleatorio(mu,&x,&j);
            printf("MAQUINA ATACO LA POSICION %c\n",m_op[x][j]);
            t=mu[x][j];
            if(t=='*')
            {
                printf("Dio en el blanco\n");
                c++;
                system("pause");
                system("cls");
                printf("\n*****************************\nNICKNAME: %s \n***************************** \n\n",name);
                for (i=0; i<5; i++)
                {
                    for (m=0; m<4; m++)
                    {
                        if (t==mu[i][m]) mu[x][j]=1;
                        printf("|%c|\t",mu[i][m]);
                    }
                    printf("\n\n");
                }
                tabla();
                imprime(mv);
                printf("*****************************\nMAQUINA\n*****************************\n\n");
            }
            else
            {
                printf("No dio en el blanco\n");
                p=0;
                system("pause");
                system("cls");
                printf("\n*****************************\nNICKNAME: %s \n***************************** \n\n",name);
                for (i=0; i<5; i++)
                {
                    for (m=0; m<4; m++)
                    {
                        if (mu[i][m]==mu[x][j]) mu[i][m]=5;
                        printf("|%c|\t",mu[i][m]);
                    }
                    printf("\n\n");
                }
                tabla();
                imprime(mv);
                printf("*****************************\nMAQUINA\n*****************************\n\n");
            }
        }

        while (c==3)
        {
            for (i=0; i<10; i++)
            {
                printf("PERDISTEE !!! PERDEDORR !! :D :D :D \n");
            }
            printf("SUERTE PARA LA PROXIMA\nTE RETO A UNA NUEVA PARTIDA :P :P :P\n");
            c=0;
            p=3;
        }
        while (C==3)
        {
            for (i=0; i<10; i++)
            {
                printf("GANASTE !!! ERES UN TETISIMOOO !! :D :D :D \n");

            }
            printf("PRESIONA SALIR ERES BASTANTE BUENO GUAPETON :D :D \n");
            C=0;
            p=3;
        }

    }
    while(p !=3 );
    system("pause");
    system("cls");
}

main()
{
    char mu[5][4],mv[5][4],name[20],m_op[5][4],barc[3],ale[3];
    int op;
    nombre(name);
    do
    {
        op=menu();
        if (op==1)
        {
            printf("Observe que la tecla BLOQ MAYUS se encuentre encendida\n.............Listo...........\nComenzamos\n");
            system("pause");
            system("cls");
            printf("\n*****************************\nNICKNAME: %s \n***************************** \n\n",name);
            m_letras(mu);
            imprime(mu);
            matriz_usuario(mu,barc);
            tabla();

            matriz_virtual(mv);
            imprime(mv);
            printf("*****************************\nMAQUINA\n*****************************\n\n");

            barcos(barc);
            system("pause");
            system("cls");
            aleatorio(ale);
            printf("\n*****************************\nNICKNAME: %s \n***************************** \n\n",name);

            matriz_usuario(mu,barc);
            imprime(mu);
            tabla();

            matriz_virtual(mv);
            imprime(mv);
            printf("*****************************\nMAQUINA\n*****************************\n\n");

            m_letras(m_op);
            lanzamiento_usuario(mv,mu,m_op,name,ale);
        }
        else if (op==2)
        {
            como_jugar();
             system("pause");
    system("cls");
       printf("*****************************\nNICKNAME: %s \n***************************** \n",name);
        }
        else if (op!=3)
        {
            printf("Opcion Incorrecta\n");
            system("pause");
            system("cls");
            printf("*****************************\nNICKNAME: %s \n***************************** \n",name);
        }
    }
    while(op!=3);
    printf("******************************************\nGRACIAS POR PARTICIPAR\nHASTA PRONTO <<ADIOS>> \n******************************************\n");
    printf("Autor: Jimenez Martinez Gabriel Geovanni\n******************************************\n");
    system ("pause");
}
