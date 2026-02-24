# MyShell - Shell Educativa 🚀

Una shell interactiva educativa implementada en C que permite ejecutar comandos básicos del sistema operativo y operaciones con archivos.

## 📋 Características

- **Comandos de exploración**: Listar archivos y directorios
- **Operaciones con archivos**: Leer, crear, eliminar, renombrar y copiar archivos
- **Herramientas útiles**: Calculadora básica y visualización de fecha/hora
- **Interfaz interactiva**: Prompt de comando amigable
- **Sistema de ayuda**: Comando `ayuda` para ver todos los comandos disponibles

## 🔧 Requisitos

- Compilador C (GCC, Clang, MSVC)
- Librería estándar de C (stdlib.h, stdio.h, string.h, time.h, dirent.h)
- Sistema operativo: Windows, Linux o macOS

## 📦 Compilación e Instalación

### En Linux/macOS:
```bash
gcc main.c -o programa
```

### En Windows (MinGW):
```bash
gcc main.c -o programa.exe
```

## 🚀 Uso

Ejecuta el programa:
```bash
./programa          # Linux/macOS
programa.exe        # Windows
```

Deberías ver el mensaje de bienvenida:
```
Bienvenido a MyShell educativa 🚀
Escribe 'ayuda' para ver los comandos
myshell>
```

## 📖 Comandos Disponibles

| Comando | Descripción | Ejemplo |
|---------|-------------|---------|
| `listar` | Lista todos los archivos y carpetas del directorio actual | `myshell> listar` |
| `leer <archivo>` | Muestra el contenido de un archivo | `myshell> leer prueba.txt` |
| `tiempo` | Muestra la fecha y hora actual | `myshell> tiempo` |
| `calc <n1> <op> <n2>` | Realiza operaciones matemáticas | `myshell> calc 10 + 5` |
| `crear <archivo>` | Crea un nuevo archivo vacío | `myshell> crear nuevo.txt` |
| `eliminar <archivo>` | Elimina un archivo (con confirmación) | `myshell> eliminar viejo.txt` |
| `renombrar <viejo> <nuevo>` | Renombra un archivo | `myshell> renombrar fichero.txt documento.txt` |
| `copiar <origen> <destino>` | Copia un archivo | `myshell> copiar original.txt copia.txt` |
| `ayuda` | Muestra la lista de comandos | `myshell> ayuda` |
| `salir` | Sale de la shell | `myshell> salir` |

## 💡 Ejemplos de Uso

### Listar archivos
```
myshell> listar
.
..
main.c
programa
prueba.txt
README.md
```

### Leer un archivo
```
myshell> leer prueba.txt
Contenido del archivo...
```

### Realizar cálculos
```
myshell> calc 15 * 3
Resultado: 45.00
```

### Crear y copiar archivos
```
myshell> crear miarchivo.txt
Archivo 'miarchivo.txt' creado
myshell> copiar miarchivo.txt miarchivo_copia.txt
Archivo copiado correctamente
```

## 🏗️ Estructura del Código

El proyecto está organizado en dos secciones principales:

### Comandos Básicos
- `comando_listar()` - Lista archivos del directorio actual
- `comando_leer()` - Lee y muestra contenido de archivos
- `comando_tiempo()` - Obtiene fecha y hora actual
- `comando_calc()` - Realiza operaciones aritméticas

### Comandos Avanzados
- `comando_crear()` - Crea archivos nuevos
- `comando_eliminar()` - Elimina archivos con confirmación
- `comando_renombrar()` - Renombra archivos
- `comando_copiar()` - Copia archivos usando buffers

## ⚙️ Detalles Técnicos

- **MAX_INPUT**: 256 caracteres máximo por línea de entrada
- **BUFFER_SIZE**: 1024 bytes para lectura/escritura de archivos
- **Operadores soportados**: `+`, `-`, `*`, `/`
- Protección contra división por cero
- Confirmación de usuario antes de eliminar archivos

## 🎓 Propósito Educativo

Este proyecto es ideal para aprender:
- Manejo de entrada/salida en C
- Operaciones con archivos (FILE*)
- Directorios (opendir/readdir)
- Gestión de strings
- Entradas del usuario
- Estructuras de control de flujo
- Buenas prácticas de programación

## 📝 Notas

- El programa se ejecuta en un bucle infinito hasta que se ejecuta el comando `salir`
- Los errores se manejan con mensajes de perror() apropiados
- La shell no soporta redirección ni tuberías (pipes)
- Los comandos multipalabra requieren entrecomillado