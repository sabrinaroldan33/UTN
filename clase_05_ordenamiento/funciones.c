#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "funciones.h"

int utn_getNumero(int* pResultado,const char *mensaje,const char *mensajeError,int minimo,int maximo,int reintentos)
{
    int ret;
    int num;

    while (reintentos>0)
    {
        printf("%s",mensaje);
        if (getInt(&num)==0)
        {
            if (num<=maximo && num>=minimo)
            {
                break;
            }
        }
                __fpurge(stdin);
                reintentos--;
                printf("%s\n",mensajeError);
    }
    if(reintentos==0)
    {
        ret=-1;
    }else
        {
            ret=0;
            *pResultado = num;
        }
    return ret;
}

int getInt(int *pResultado)
{
    char buffer[64];
    scanf("%s",buffer);

    *pResultado = atoi(buffer);
    return 0;
}

int utn_getFloat(float *pResultado,const char *mensaje,const char *mensajeError,int minimo,int maximo,int reintentos)
{
    int ret;
    float num;

    while (reintentos>0)
    {
        printf("%s",mensaje);
        if (getFloat(&num)==0)
        {
            if (num<=maximo && num>=minimo)
            {
                break;
            }
        }
                __fpurge(stdin);
                reintentos--;
                printf("%s\n",mensajeError);
    }
    if(reintentos==0)
    {
        ret=-1;
    }else
        {
            ret=0;
            *pResultado = num;
        }
    return ret;
}

int getFloat(float *pResultado)
{
    char buffer[64];
    scanf("%s",buffer);

    *pResultado = atof(buffer);
    return 0;
}

int utn_getChar(char* pResultado,const char *mensaje,const char *mensajeError,const char *minimo,const char *maximo,int reintentos)
{
    int ret = -1;
    char buffer[64];
    int i;

    do{
        printf("%s",mensaje);
        scanf("%s", buffer);
        i=0;
        while (buffer[i]!='\0' && i<2)
        {

            if (buffer[0]>=minimo[0] && buffer[0]<=maximo[0])
            {
                ret=0;
            }
            i++;
        }

        if (ret==0 && i==1)
        {
            pResultado = buffer;
            break;
        }
        reintentos--;
        printf("%s\n",mensajeError);
        ret = -1;
        __fpurge(stdin);

    }while (reintentos>0);
    return ret;
}

int getArrayInt(char* mensaje, char *mensajeError, int maximo, int minimo, int reintentos, int* arrayResultado, int limite)
{
    int error=-1;
    int buffer;
    int i;
    int cantidadNumeros;

    if( arrayResultado!=NULL &&
        mensaje!=NULL &&
        mensajeError!= NULL &&
        maximo<=minimo &&
        reintentos<0 &&
        limite>0)
    {
        /*printf("Cantidad de elementos que quiere ingresar");
        scanf("%d",&cantidadNumeros);
        int aNumeros[&cantidadNumeros];*/

        for(int i=0;i<limite;i++)
        {
            if(utn_getNumero(&buffer,mensaje,mensajeError,minimo,maximo,reintentos)==0)
            {
                arrayResultado[i]=buffer;
            }
            else
            {
                return error;
                break;
            }

        }
    }
    return 0;
}

void printArrayInt(int* arrayResultado,int limite)
{
    int i;
    for(i=0;i<limite;i++)
    {
        printf("%d\n",arrayResultado[i]);
    }
}






