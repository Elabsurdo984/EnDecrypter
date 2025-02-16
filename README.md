# EnDecrypter

Una biblioteca Python que proporciona una colección completa de algoritmos de cifrado, incluyendo tanto métodos clásicos como modernos, con una interfaz simple y consistente.

## Tabla de Contenidos
- [EnDecrypter](#endecrypter)
  - [Tabla de Contenidos](#tabla-de-contenidos)
  - [Instalación](#instalación)
    - [Requisitos](#requisitos)
  - [Características](#características)
  - [Uso](#uso)
    - [Cifrado César](#cifrado-césar)
    - [Cifrado Monoalfabético](#cifrado-monoalfabético)
    - [Cifrado Polialfabético](#cifrado-polialfabético)
    - [Cifrado por Transposición](#cifrado-por-transposición)
    - [Cifrado Hill](#cifrado-hill)
    - [Cifrado DES](#cifrado-des)
    - [Cifrado RC4](#cifrado-rc4)
    - [Cifrado RC5](#cifrado-rc5)
    - [Cifrado RC6](#cifrado-rc6)
    - [Triple DES](#triple-des)
    - [Utilidades Binarias](#utilidades-binarias)
  - [Documentación Detallada](#documentación-detallada)
    - [Comparativa de Cifrados](#comparativa-de-cifrados)
  - [Contribuir](#contribuir)
    - [Guía de Contribución](#guía-de-contribución)
  - [Licencia](#licencia)

## Instalación

```bash
pip install endecrypter
```

### Requisitos
- Python 3.12+
- pycryptodome (para cifrados DES, 3DES)
- NumPy (Para cifrados Hill)

## Características

- 📜 **Cifrados Clásicos**
  - César
  - Monoalfabético
  - Polialfabético (Vigenère)
  - Transposición (Rail Fence)
  - Hill
  
- 🔐 **Cifrados Modernos**
  - DES
  - RC4
  - RC5
  - RC6
  - 3DES
  
- 🛠️ **Utilidades**
  - Conversión Binaria

## Uso

### Cifrado César

El cifrado César es un tipo de cifrado por sustitución en el que cada letra del texto claro se reemplaza por una letra que se encuentra un número fijo de posiciones más adelante en el alfabeto. Este número fijo es conocido como **"desplazamiento"**.

```python
from endecrypter import CaesarCipher

# Cifrar un mensaje
mensaje = "Hello World"
desplazamiento = 3
cifrado = CaesarCipher.encrypt_caesar(mensaje, desplazamiento)
print(f"Texto cifrado: {cifrado}")  # Khoor Zruog

# Descifrar el mensaje
descifrado = CaesarCipher.decrypt_caesar(cifrado, desplazamiento)
print(f"Texto descifrado: {descifrado}")  # Hello World
```

### Cifrado Monoalfabético

El **cifrado monoalfabético** es un tipo de cifrado por sustitución en el que cada letra del texto claro se sustituye por una letra diferente del alfabeto, pero siempre de manera fija. Es decir, cada letra del alfabeto se reemplaza por otra letra del alfabeto de forma constante, sin importar su posición en el mensaje.

```python
from endecrypter import MonoalphabeticCipher

# Generar alfabeto de sustitución
alfabeto = MonoalphabeticCipher.generate_substitution_alphabet()

# Cifrar
mensaje = "Hello World"
cifrado = MonoalphabeticCipher.encrypt_monoalphabetic(mensaje, alfabeto)
print(f"Texto cifrado: {cifrado}")

# Descifrar
descifrado = MonoalphabeticCipher.decrypt_monoalphabetic(cifrado, alfabeto)
print(f"Texto descifrado: {descifrado}")  # Hello World
```

### Cifrado Polialfabético

El **cifrado polialfabético** es un tipo de cifrado por sustitución en el que se utilizan varios alfabetos para cifrar un mensaje, en lugar de un solo alfabeto como en el cifrado monoalfabético. Esto hace que el cifrado sea más seguro, ya que cada letra del texto claro puede ser sustituida por una letra diferente según una serie de reglas, lo que dificulta la tarea de los atacantes.

```python
from endecrypter import PolyalphabeticCipher

# Cifrar
mensaje = "HELLO WORLD"
clave = "KEY"
cifrado = PolyalphabeticCipher.encrypt_polyalphabetic(mensaje, clave)
print(f"Texto cifrado: {cifrado}")

# Descifrar
descifrado = PolyalphabeticCipher.decrypt_polyalphabetic(cifrado, clave)
print(f"Texto descifrado: {descifrado}")  # HELLO WORLD
```

### Cifrado por Transposición

El **cifrado de transposición** es un tipo de cifrado en el que el orden de las letras del mensaje se reorganiza, pero sin cambiar las propias letras. A diferencia de los cifrados por sustitución (como el cifrado César o monoalfabético), que modifican las letras del mensaje, el cifrado de transposición solo altera la posición de las letras.

```python
from endecrypter import TranspositionCipher

# Cifrar
mensaje = "Hello World"
rieles = 3
cifrado = TranspositionCipher.encrypt_transposition(mensaje, rieles)
print(f"Texto cifrado: {cifrado}")

# Descifrar
descifrado = TranspositionCipher.decrypt_transposition(cifrado, rieles)
print(f"Texto descifrado: {descifrado}")  # Hello World
```

### Cifrado Hill

El **cifrado Hill** es un algoritmo de cifrado por sustitución polialfabética que utiliza álgebra lineal para cifrar y descifrar mensajes. Fue desarrollado por Lester S. Hill en 1929 y es uno de los primeros métodos de cifrado en usar matrices. Este cifrado se basa en la idea de tratar el texto claro como un conjunto de vectores y las letras del mensaje se representan numéricamente, generalmente usando el sistema de asignación A=0, B=1, C=2, y así sucesivamente.

```python
from endecrypter import HillCipher

# Matriz clave 2x2
key = [
    [2, 3],
    [3, 6]
]

try:
    # Aseguramos que el texto sea un string
    text = "hello"
    print(f"Texto original: {text}")
    
    encrypted, padding_count = HillCipher.encrypt_hill(text, key)
    print(f"Texto encriptado: {encrypted}")
    
    decrypted = HillCipher.decrypt_hill(encrypted, key, padding_count)
    print(f"Texto desencriptado: {decrypted}")

except Exception as e:
    print(f"Error: {type(e).__name__} - {str(e)}")
```

### Cifrado DES

El **cifrado DES** (Data Encryption Standard) es un algoritmo de cifrado simétrico que utiliza una clave de 56 bits para cifrar bloques de 64 bits de datos. Funciona dividiendo el bloque de datos en dos mitades de 32 bits, y luego realiza 16 rondas de transformación utilizando operaciones de sustitución y permutación, aplicando la clave en cada ronda. La estructura del algoritmo sigue el modelo de red de Feistel, donde una mitad del bloque se modifica en función de la otra. Aunque DES fue un estándar de seguridad ampliamente utilizado, su clave corta lo hace vulnerable a ataques de fuerza bruta, y fue reemplazado por el más seguro AES.

```python
from endecrypter import DESCipher

# La clave debe ser de 8 bytes
clave = b"secretky"

# Cifrar
mensaje = "Hello World"
cifrado = DESCipher.encrypt_des(mensaje, clave)
print(f"Texto cifrado (bytes): {cifrado}")

# Descifrar
descifrado = DESCipher.decrypt_des(cifrado, clave)
print(f"Texto descifrado: {descifrado}")  # Hello World
```

### Cifrado RC4

**RC4** es un algoritmo de cifrado simétrico de flujo, desarrollado por Ron Rivest en 1987. Funciona generando una secuencia de claves pseudoaleatorias de longitud variable a partir de una clave inicial, que luego se combina con el texto claro mediante una operación de XOR (o exclusivo). El proceso de generación de la secuencia de claves se basa en una tabla de estado que se va modificando continuamente durante la operación, lo que permite cifrar los datos bit por bit. Aunque RC4 fue ampliamente utilizado en protocolos como SSL/TLS y WEP, su seguridad ha sido comprometida por diversas vulnerabilidades.

```python
from endecrypter import RC4Cipher

# La clave puede ser de cualquier longitud
clave = b"mi_clave_secreta"

# Cifrar
mensaje = "Hello World"
cifrado = RC4Cipher.encrypt_rc4(mensaje, clave)
print(f"Texto cifrado (bytes): {cifrado}")

# Descifrar
descifrado = RC4Cipher.decrypt_rc4(cifrado, clave)
print(f"Texto descifrado: {descifrado}")  # Hello World
```

### Cifrado RC5

**RC5** es un algoritmo de cifrado simétrico de bloques desarrollado por Ron Rivest en 1994. Funciona mediante una estructura de red de Feistel, y permite personalizar varios parámetros clave, como el tamaño de la clave, el número de rondas y el tamaño del bloque de datos, lo que le da flexibilidad y adaptabilidad a diferentes aplicaciones. El algoritmo usa una clave de longitud variable (de 0 a 2040 bits) y cifra bloques de datos de 32, 64 o 128 bits. RC5 aplica una serie de transformaciones, que incluyen permutaciones y sustituciones, a los bloques de datos durante un número de rondas definido por la clave.

```python
from endecrypter import RC5Cipher

# Generar una clave aleatoria de 16 bytes
key = RC5Cipher.generate_key(16)

# Texto a cifrar
mensaje = "Texto secreto"

try:
    # Cifrar el mensaje
    datos_cifrados = RC5Cipher.encrypt_rc5(mensaje, key)
    print("Mensaje cifrado: {datos_cifrados}")

    # Descifrar el mensaje
    texto_descifrado = RC5Cipher.decrypt_rc5(datos_cifrados, key)
    print(f"Mensaje descifrado: {texto_descifrado}")

except Exception as e:
    print(f"Error: {e}")
```

### Cifrado RC6

**RC6** es un algoritmo de cifrado simétrico de bloques desarrollado por Ron Rivest, Mahesh Rao, y Robert Sidney en 1997 como una extensión de RC5. RC6 fue uno de los finalistas en la competición para seleccionar el nuevo estándar de cifrado AES, aunque no fue elegido. Al igual que RC5, RC6 utiliza una estructura de red de Feistel, pero con mejoras que lo hacen más seguro y eficiente. RC6 permite bloques de datos de 128 bits y soporta claves de longitud variable (de 128, 192 o 256 bits). Además, utiliza una versión extendida de las operaciones de permutación y sustitución, y un número variable de rondas (de 20, 12 o 8, dependiendo de la longitud de la clave). A diferencia de RC5, RC6 incorpora un multiplicador en sus transformaciones, lo que aumenta su seguridad frente a ataques. Aunque no fue adoptado como AES, sigue siendo una opción robusta para aplicaciones que requieren un alto nivel de seguridad.

```python
from endecrypter import RC6Cipher

rc6 = RC6Cipher()
key = rc6.generate_key(16)
texto = "Mensaje secreto"

# Cifrar
cifrado = rc6.encrypt_rc6(texto, key)
print(cifrado)


# Descifrar
descifrado = rc6.decrypt_rc6(cifrado, key)
print(descifrado)
```

### Triple DES

**Triple DES (3DES)** es una variante del algoritmo DES diseñada para mejorar la seguridad de DES, que se volvió vulnerable debido a la corta longitud de su clave. 3DES aplica el algoritmo DES tres veces de manera secuencial sobre el mismo bloque de datos, utilizando tres claves diferentes (o la misma clave en algunos casos). Este proceso puede realizarse de tres formas diferentes: **EDE** (Encrypt-Decrypt-Encrypt), donde primero se cifra, luego se descifra y finalmente se cifra de nuevo, lo que mejora considerablemente la seguridad. Con tres aplicaciones de DES, 3DES efectivamente aumenta el tamaño de la clave a 168 bits (o 112 bits si se reutilizan algunas claves), lo que hace más difícil de romper mediante ataques de fuerza bruta. Aunque 3DES fue una mejora significativa sobre DES, sigue siendo relativamente lento en comparación con algoritmos más modernos, como **AES**, y debido a su vulnerabilidad a ciertos ataques, ha sido descontinuado para muchas aplicaciones y reemplazado por AES.

```python
from endecrypter import TripleDESCipher

# Generar una clave segura
key = TripleDESCipher.generate_key()

# Cifrar un mensaje
mensaje = "Información confidencial"
try:
    encrypted_data = TripleDESCipher.encrypt(mensaje, key)
    print("Mensaje cifrado exitosamente")

    # Descifrar el mensaje
    decrypted_text = TripleDESCipher.decrypt(encrypted_data, key)
    print(f"Mensaje descifrado: {decrypted_text}")

except ValueError as e:
    print(f"Error: {e}")
```

### Utilidades Binarias

El **binario** es un sistema numérico basado en dos dígitos: 0 y 1, conocido como sistema de numeración base 2. Cada cifra en un número binario se llama bit (binary digit), y es la unidad mínima de información en informática. El sistema binario es fundamental en la computación porque los ordenadores procesan y almacenan datos en esta forma, ya que los circuitos electrónicos solo pueden representar dos estados posibles: encendido (1) o apagado (0).

En el sistema binario, los números se representan utilizando combinaciones de 0s y 1s. Por ejemplo, el número binario 1010 representa el número decimal 10. Cada posición en un número binario tiene un valor que es una potencia de 2, comenzando desde la derecha con 2^0, 2^1, 2^2, y así sucesivamente. Para convertir un número binario a decimal, se suman los valores de las posiciones donde hay un 1.

```python
from endecrypter import Binary

# Convertir texto a binario
texto = "Hello"
binario = Binary.text_to_binary(texto)
print(f"Binario: {binario}")  # 01001000 01100101 01101100 01101100 01101111

# Convertir binario a texto
texto_recuperado = Binary.binary_to_text(binario)
print(f"Texto: {texto_recuperado}")  # Hello
```

## Documentación Detallada

### Comparativa de Cifrados

| Cifrado | Tipo | Clave | Fortaleza | Uso Recomendado |
|---------|------|-------|-----------|-----------------|
| César | Clásico | Número (1-25) | Muy Baja | Educativo |
| Monoalfabético | Clásico | Alfabeto | Baja | Educativo |
| Polialfabético | Clásico | Texto | Baja-Media | Educativo |
| Transposición | Clásico | Número | Baja | Educativo |
| Hill | Clasico | Matriz n * n | Baja-Media | Educativo |
| DES | Moderno | 8 bytes | Media-Alta | Datos sensibles |
| RC4 | Moderno | Variable | Media | Datos sensibles |
| Binario | Util | Texto | Muy Baja | Educativo |
| 3DES | Moderno | 3 de 24 bytes | Alta | Datos comunes |
| RC5 | Moderno | 16 bytes | Media-Alta | Datos sensibles |
| RC6 | Moderno | 16 bytes | Alta | Datos sensibles |

## Contribuir

1. Fork el repositorio
2. Crea una rama para tu feature (`git checkout -b feature/AmazingFeature`)
3. Commit tus cambios (`git commit -m 'Add some AmazingFeature'`)
4. Push a la rama (`git push origin feature/AmazingFeature`)
5. Abre un Pull Request

### Guía de Contribución

- Sigue el estilo de código existente
- Añade tests para nueva funcionalidad
- Actualiza la documentación según sea necesario
- Asegúrate de que todos los tests pasen

## Licencia

Distribuido bajo la Licencia GNU. Ver `LICENSE` para más información.
