#include <stdio.h>
#include <string.h>

// Función para codificar una cadena
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

// Función para decodificar una cadena
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
}

int main() {


    char texto[100000]; // Tamaño máximo del texto de entrada

    printf("Ingrese el texto: ");
    fgets(texto, sizeof(texto), stdin);
    texto[strcspn(texto, "\n")] = '\0'; // Eliminar el carácter de nueva línea

    printf("Texto original: %s\n", texto);

    codificar(texto);
    printf("Texto codificado: %s\n", texto);
 char textod[100000]; // Tamaño máximo del texto de entrada
    printf("Ingrese el texto a decodificar: ");
    fgets(textod, sizeof(textod), stdin);
    textod[strcspn(textod, "\n")] = '\0'; // Eliminar el carácter de nueva línea


    decodificar(textod);
    printf("Texto decodificado: %s\n", textod);



    return 0;
}
