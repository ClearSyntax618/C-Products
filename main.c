#include<stdio.h>

void ponerMatrizCero(float[][12], int, int);
void cargarMatriz(float[][12], int, int);
void productoMayor(float[][12], float[], int, int);
void trimMenor(float[][12], int, int);
int validarDato(int,int);

int main() {
    float ventas[20][12];
    float recaudacion[20];

    ponerMatrizCero(ventas, 20, 12);
    cargarMatriz(ventas, 20, 12);
    productoMayor(ventas, recaudacion, 20, 12);
    trimMenor(ventas, 20, 12);

    return 0;
}

void ponerMatrizCero(float ventas[][12], int cf, int cc) {
    int f, c;

    for(f = 0; f <= cf - 1; f++){
        for(c = 0; c <= cc - 1; c++) {
            ventas[f][c] = 0;
        }
    }
}

int validarDato(int lim1, int lim2) {
    int dato = 0;
    int band1, band2 = 0;

    if(lim1 == 1  && lim2 == 20) {
        do {
            if(band1 == 1) {
                printf("Ingrese otra vez\n");
            }
            scanf("%d", &dato);
            band1 = 1;
        } while(dato < lim1 && dato != 0 || dato > lim2);
    } else {
        do {
            if(band2 == 1) {
                printf("Ingrese otra vez\n");
            }
            scanf("%d", &dato);
            band2 == 1;
        } while(dato < lim1 || dato > lim2);
    }

    return dato;
}

void productoMayor(float ventas[][12], float recaudacion[], int cf, int cc) {
    int f, c;
    float mayor2 = 0;
    int mayor = 1;
    int fila = 0;

    for(f = 0; f <= cf - 1; f++) {
        recaudacion[f] = 0;
        for(c = 0; c <= cc - 1; c++) {
            recaudacion[f] += ventas[f][c];
        }

        if(mayor == 1 || mayor2 < recaudacion[f]) {
            mayor = 0;
            mayor2 = recaudacion[f];
            fila = f + 1;
        }
    }
    printf("El producto con mayor recaudacion es %d \n", fila);
}

void trimMenor(float ventas[][12], int cf, int cc) {
    int i, f, c;
    int esMenor = 1;
    float menor = 0;
    float trim[4];
    int numTrim = 0;

    for(f = 0; f <= cf - 1; f++){
        for(c = 0; c <= cc - 1; c++) {
            if(c <= 2 ) {
                trim[0] += ventas[f][c];
            } else if(c > 2 && c <= 5) {
                trim[1] += ventas[f][c];
            } else if( c > 5 && c <= 8) {
                trim[2] += ventas[f][c];
            } else {
                trim[3] += ventas[f][c];
            }
        }
    }

    for(i = 0; i <= 3; i++) {
        if(esMenor == 1 || menor > trim[i]){
            esMenor = 0;
            menor = trim[i];
            numTrim = i + 1;
        }
    }
    printf("El trimestre con menor recaudacion es %d \n", numTrim);
}


void cargarMatriz(float ventas[][12], int cf, int cc) {
    printf("Ingrese el cod de producto: ");
    int cod = validarDato(1, 20);
    float precio = 0;

    while(cod != 0) {
        printf("Ingrese el dia: ");
        int dia = validarDato(1, 31);

        printf("Ingrese el mes: ");
        int mes = validarDato(1, 12);

        do {
            printf("Ingrese el precio: ");
            scanf("%d", &precio);
        } while(precio < 0);

        ventas[cod - 1][mes - 1] = precio;

        printf("Ingrese el cod de producto: ");
        cod = validarDato(1, 20);
    }
}
