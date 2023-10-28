#include <stdio.h>

// Definici�n de la memoria ROM (32 palabras de 8 bits)
unsigned char rom[32] = {
    0x01, // Instrucci�n para NO operar (NOP)
    0x0A, // Instrucci�n para realizar codificaci�n
    0x33, // Instrucci�n para realizar decodificaci�n
    // ... Otras instrucciones ...
};
void codificar(char *cadena) {
    int i;
    for (i = 0; cadena[i] != '\0'; i++) {
        if (cadena[i] >= 'a' && cadena[i] <= 'z') {
            if (cadena[i] == 'z') {
                cadena[i] = 'a';
            } else {
                cadena[i]++;
            }
        } else if (cadena[i] >= 'A' && cadena[i] <= 'Z') {
            if (cadena[i] == 'Z') {
                cadena[i] = 'A';
            } else {
                cadena[i]++;
            }
        }
    }
}
void decodificar(char *cadena) {
    int i;
    for (i = 0; cadena[i] != '\0'; i++) {
        if (cadena[i] >= 'a' && cadena[i] <= 'z') {
            if (cadena[i] == 'a') {
                cadena[i] = 'z';
            } else {
                cadena[i]--;
            }
        } else if (cadena[i] >= 'A' && cadena[i] <= 'Z') {
            if (cadena[i] == 'A') {
                cadena[i] = 'Z';
            } else {
                cadena[i]--;
            }
        }
    }
void readFromROM(unsigned char address, char *cadena) {
    if (address < 32) {
        if (rom[address] == 0x0A) {
            codificar(cadena);
        } else if (rom[address] == 0x33) {
            decodificar(cadena);
        }
    } else {
        printf("Error: Direcci�n fuera de rango.\n");
    }
}

int main() {
    char texto[100000]; /
    printf("Ingrese el texto: ");
    fgets(texto, sizeof(texto), stdin);
    texto[strcspn(texto, "\n")] = '\0'; /
    unsigned char address = 1;
    printf("Texto original: %s\n", texto);

    readFromROM(address, texto);

    printf("Texto codificado/decodificado: %s\n", texto);

    return 0;
}
