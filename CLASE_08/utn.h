#define TRUE 1
#define FALSE 0

int getString ( char* msg,
                char* msgError,
                int minimo,
                int maximo,
                int reintentos,
                char* resultado);
//-------------------------------------

int getName (   char* msg,
                char* msgError,
                int minimo,
                int maximo,
                int reintentos,
                char* resultado);


int isValidName (char* cadena);

int printArray (char arrayStr[][50],int limite);

int insertStr (char arrayStr[][50],int limite);

int compStr (char arrayStr[][50], int limite);




