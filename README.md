### Encriptador y Desencriptador en C++ (Cifrado César)

Este proyecto implementa un programa en C++ que permite encriptar y desencriptar un texto usando el algoritmo de Cifrado César. El Cifrado César es un tipo de cifrado por sustitución en el que cada letra en el texto es desplazada un número fijo de posiciones en el alfabeto.


## Características

    Soporta caracteres en minúsculas y mayúsculas.
    No afecta los caracteres no alfabéticos (como números, signos de puntuación y espacios).
    Permite ingresar el texto y el valor de desplazamiento a través de la línea de comandos.

## Instalación

Asegúrate de tener un compilador de C++ instalado en tu sistema. Algunas opciones populares son:
        GCC (en Linux)
        GCC (en Windows)
        Xcode (en macOS)

Clona el repositorio o descarga el archivo fuente.

`git clone https://github.com/tu-usuario/EnDecrypter.git`
`cd EnDecrypter`

Compila el archivo fuente con el compilador de tu elección. Por ejemplo, si usas GCC:

g++ -o (El nombre que quieras) main.cpp

Ejecuta el programa:

    ./(El nombre que pusiste)

## Uso

    Al ejecutar el programa, se solicitará que ingreses un texto que deseas encriptar.
    Luego, se pedirá que ingreses el desplazamiento, que es el número de posiciones que se desplazará cada letra en el texto.
    El programa mostrará el texto encriptado y luego el texto desencriptado para verificar que el proceso sea correcto.

## Ejemplo de ejecución:

Introduce el texto: Hola Mundo!
Introduce el desplazamiento: 3
Texto encriptado: Krod Pxqgr!
Texto desencriptado: Hola Mundo!

## Cómo funciona

* **Encriptación:**
        Cada letra del texto se reemplaza por la letra que se encuentra un número fijo de posiciones más adelante en el alfabeto.
        Si se alcanza el final del alfabeto, el desplazamiento continúa desde el principio (es decir, el alfabeto es cíclico).
* **Desencriptación:**
        Para desencriptar el texto, simplemente se aplica el desplazamiento inverso, es decir, se mueve cada letra hacia atrás por el mismo número de posiciones.

Archivos del Proyecto

    main.cpp: Código fuente principal en C++.
    README.md: Este archivo, que explica cómo usar el proyecto.

Dependencias

    No se requieren bibliotecas externas para este proyecto. Solo se usa la librería estándar de C++.

Contribuciones

Si deseas contribuir al proyecto, puedes realizar un fork del repositorio y enviar un pull request con tus cambios.
Licencia

Este proyecto está bajo la Licencia GPL. Consulta el archivo LICENSE para más detalles.
