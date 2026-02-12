#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <dirent.h>

#define MAX_INPUT 256
#define BUFFER_SIZE 1024

/* ===== COMANDOS BÁSICOS ===== */

void comando_listar() {
    DIR *dir = opendir(".");
    struct dirent *entry;

    if (!dir) {
        perror("Error al abrir directorio");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        printf("%s\n", entry->d_name);
    }

    closedir(dir);
}

void comando_leer(char *archivo) {
    FILE *f = fopen(archivo, "r");
    char linea[BUFFER_SIZE];

    if (!f) {
        printf("No se pudo abrir el archivo: %s\n", archivo);
        return;
    }

    while (fgets(linea, sizeof(linea), f)) {
        printf("%s", linea);
    }

    fclose(f);
}

void comando_tiempo() {
    time_t t = time(NULL);
    struct tm *tm_info = localtime(&t);

    char buffer[80];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", tm_info);
    printf("Fecha y hora: %s\n", buffer);
}

void comando_calc(double a, char op, double b) {
    double r;

    switch (op) {
        case '+': r = a + b; break;
        case '-': r = a - b; break;
        case '*': r = a * b; break;
        case '/':
            if (b == 0) {
                printf("Error: división por cero\n");
                return;
            }
            r = a / b;
            break;
        default:
            printf("Operador no válido\n");
            return;
    }

    printf("Resultado: %.2f\n", r);
}

/* ===== COMANDOS AVANZADOS ===== */

void comando_crear(char *archivo) {
    FILE *f = fopen(archivo, "w");
    if (!f) {
        printf("No se pudo crear el archivo\n");
        return;
    }
    fclose(f);
    printf("Archivo '%s' creado\n", archivo);
}

void comando_eliminar(char *archivo) {
    char confirmacion;

    printf("¿Seguro que deseas eliminar '%s'? (s/n): ", archivo);
    scanf(" %c", &confirmacion);
    getchar(); // limpiar buffer

    if (confirmacion == 's' || confirmacion == 'S') {
        if (remove(archivo) == 0)
            printf("Archivo eliminado\n");
        else
            printf("No se pudo eliminar el archivo\n");
    } else {
        printf("Operación cancelada\n");
    }
}

void comando_renombrar(char *viejo, char *nuevo) {
    if (rename(viejo, nuevo) == 0)
        printf("Archivo renombrado correctamente\n");
    else
        printf("Error al renombrar el archivo\n");
}

void comando_copiar(char *origen, char *destino) {
    FILE *f1 = fopen(origen, "rb");
    FILE *f2 = fopen(destino, "wb");
    char buffer[BUFFER_SIZE];
    size_t bytes;

    if (!f1 || !f2) {
        printf("Error al abrir archivos\n");
        if (f1) fclose(f1);
        if (f2) fclose(f2);
        return;
    }

    while ((bytes = fread(buffer, 1, BUFFER_SIZE, f1)) > 0) {
        fwrite(buffer, 1, bytes, f2);
    }

    fclose(f1);
    fclose(f2);
    printf("Archivo copiado correctamente\n");
}

void comando_ayuda() {
    printf("\nComandos disponibles:\n");
    printf("  listar\n");
    printf("  leer <archivo>\n");
    printf("  tiempo\n");
    printf("  calc <n1> <op> <n2>\n");
    printf("  crear <archivo>\n");
    printf("  eliminar <archivo>\n");
    printf("  renombrar <viejo> <nuevo>\n");
    printf("  copiar <origen> <destino>\n");
    printf("  ayuda\n");
    printf("  salir\n\n");
}

/* ===== MAIN ===== */

int main() {
    char input[MAX_INPUT];

    printf("Bienvenido a MyShell educativa 🚀\n");
    printf("Escribe 'ayuda' para ver los comandos\n");

    while (1) {
        printf("myshell> ");
        fgets(input, MAX_INPUT, stdin);
        input[strcspn(input, "\n")] = 0;

        if (strcmp(input, "salir") == 0) break;

        else if (strcmp(input, "listar") == 0)
            comando_listar();

        else if (strncmp(input, "leer ", 5) == 0)
            comando_leer(input + 5);

        else if (strcmp(input, "tiempo") == 0)
            comando_tiempo();

        else if (strncmp(input, "calc ", 5) == 0) {
            double a, b;
            char op;
            if (sscanf(input + 5, "%lf %c %lf", &a, &op, &b) == 3)
                comando_calc(a, op, b);
            else
                printf("Uso: calc <n1> <op> <n2>\n");
        }

        else if (strncmp(input, "crear ", 6) == 0)
            comando_crear(input + 6);

        else if (strncmp(input, "eliminar ", 9) == 0)
            comando_eliminar(input + 9);

        else if (strncmp(input, "renombrar ", 10) == 0) {
            char viejo[100], nuevo[100];
            if (sscanf(input + 10, "%s %s", viejo, nuevo) == 2)
                comando_renombrar(viejo, nuevo);
            else
                printf("Uso: renombrar <viejo> <nuevo>\n");
        }

        else if (strncmp(input, "copiar ", 7) == 0) {
            char origen[100], destino[100];
            if (sscanf(input + 7, "%s %s", origen, destino) == 2)
                comando_copiar(origen, destino);
            else
                printf("Uso: copiar <origen> <destino>\n");
        }

        else if (strcmp(input, "ayuda") == 0)
            comando_ayuda();

        else if (strlen(input) == 0) {}

        else
            printf("Comando no reconocido. Usa 'ayuda'\n");
    }

    printf("Saliendo de la shell...\n");
    return 0;
}
