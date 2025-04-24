// TA TE TI
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void loop(char tablero[3][3]);
void iniciar_tablero(char tablero [3][3]);
void hacer_jugada(char tabler[3][3]);
void jugada_ia(char tablero [3][3]);
int buscar_ganador(char tablero[3][3]);
void pintar_tablero(char tablero [3][3]);

int main()
{
    char tablero [3][3];

    loop(tablero);

    printf("GAME OVER\n\n");
    system("pause");
    return 0;
}

void loop(char tablero[3][3]){
    int cont = 0; //contador de tiradas

    iniciar_tablero(tablero);

    do{
        system("cls"); // limpiar pantalla
        pintar_tablero(tablero);

        if (cont%2 == 0){ // si es jugada para, juego yo, sino la ia
            hacer_jugada(tablero);
        }
        else{
            jugada_ia(tablero);
        }

        if(buscar_ganador(tablero) == 1){
            system("cls"); // limpiar pantalla
            pintar_tablero(tablero);
            printf("GANASTES! :D\n\n");
            return;
        }
        else if(buscar_ganador(tablero) == 0){
            system("cls"); // limpiar pantalla
            pintar_tablero(tablero);
            printf("Perdistes :(\n\n");
            return;
        }

        cont++;
    }while(cont <= 9);
}

void iniciar_tablero(char tablero [3][3]){
    int i, j;
    char nro = '1';

    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            tablero[i][j] = nro;
            nro++;
        }
    }
}

void hacer_jugada(char tablero[3][3]){
    int i, j;
    char pos;
    int error = 0;

    do{
        printf("Ingrese la posicion de su jugada: ");
        fflush(stdin);
        scanf("%c", &pos);

        switch(pos){
            case '1' :{
                i = 0;
                j = 0;
                break;
            }
            case '2' :{
                i = 0;
                j = 1;
                break;
            }
            case '3' :{
                i = 0;
                j = 2;
                break;
            }
            case '4' :{
                i = 1;
                j = 0;
                break;
            }
            case '5' :{
                i = 1;
                j = 1;
                break;
            }
            case '6' :{
                i = 1;
                j = 2;
                break;
            }
            case '7' :{
                i = 2;
                j = 0;
                break;
            }
            case '8' :{
                i = 2;
                j = 1;
                break;
            }
            case '9' :{
                i = 2;
                j = 2;
                break;
            }
            default : {
                printf("Te haces el vivo salame? Ingresa una posicion valida...\n\n");
                break;
            }

        }
        if(tablero[i][j] == 'X' || tablero[i][j] == 'O'){
            error = 1;
            printf("La casilla esta ocupada! Hace otra jugada...\n\n");
        }
        else{
            error = 0;
        }
    }while(error == 1);

    tablero[i][j] = 'X';
}

void jugada_ia(char tablero[3][3]){
    int i, j;
    int error = 0;

    srand(time(NULL));
    do{
        i = rand() % 3; // da un nro entre 0 y 2
        j = rand() % 3;

        if(tablero[i][j] == 'X' || tablero[i][j] == 'O'){
            error = 1;
        }
        else{
            error = 0;
        }
    }while(error == 1);

    tablero[i][j]='O';
}

int buscar_ganador(char tablero[3][3]){
    if(tablero[0][0] == 'X' || tablero[0][0] == 'O'){
        if(tablero[0][1] ==  tablero[0][0] && tablero [0][2] == tablero[0][0]){
            if(tablero[0][0] == 'X'){
                return 1;
            }
            else{
                return 0;
            }
        }
        if(tablero[1][0] ==  tablero[0][0] && tablero [2][0] == tablero[0][0]){
            if(tablero[0][0] == 'X'){
                return 1;
            }
            else{
                return 0;
            }
        }
        if(tablero[1][1] ==  tablero[0][0] && tablero [2][2] == tablero[0][0]){
            if(tablero[0][0] == 'X'){
                return 1;
            }
            else{
                return 0;
            }
        }
    }
    if(tablero[0][2] == 'X' || tablero[0][2] == 'O'){
        if(tablero[1][1] ==  tablero[0][2] && tablero [2][0] == tablero[0][2]){
            if(tablero[0][2] == 'X'){
                return 1;
            }
            else{
                return 0;
            }
        }
        if(tablero[1][2] ==  tablero[0][2] && tablero [2][2] == tablero[0][2]){
            if(tablero[0][2] == 'X'){
                return 1;
            }
            else{
                return 0;
            }
        }
    }
    if(tablero[0][1] == 'X' || tablero[0][1] == 'O'){
        if(tablero[1][1] ==  tablero[0][1] && tablero [2][1] == tablero[0][1]){
            if(tablero[0][1] == 'X'){
                return 1;
            }
            else{
                return 0;
            }
        }
    }
    if(tablero[1][0] == 'X' || tablero[1][0] == 'O'){
        if(tablero[1][1] ==  tablero[1][0] && tablero [1][2] == tablero[1][0]){
            if(tablero[1][0] == 'X'){
                return 1;
            }
            else{
                return 0;
            }
        }
    }
    if(tablero[2][0] == 'X' || tablero[2][0] == 'O'){
        if(tablero[2][1] ==  tablero[2][0] && tablero [2][2] == tablero[2][0]){
            if(tablero[2][0] == 'X'){
                return 1;
            }
            else{
                return 0;
            }
        }
    }
}

void pintar_tablero(char tablero [3][3]){
    int i, j;

    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            if(j<2){
                printf(" %c |", tablero[i][j]);
            }
            else{
                printf(" %c ", tablero[i][j]);
            }
        }
        printf("\n-----------\n");
    }
    printf("\n\n");
}
