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
    - [Cifrado DES](#cifrado-des)
    - [Cifrado RC4](#cifrado-rc4)
    - [Cifrado RC5](#cifrado-rc5)
    - [Cifrado RC6](#cifrado-rc6)
    - [Triple DES](#triple-des)
    - [Utilidades Binarias](#utilidades-binarias)
  - [Documentación Detallada](#documentación-detallada)
    - [Comparativa de Cifrados](#comparativa-de-cifrados)
    - [Consideraciones de Seguridad](#consideraciones-de-seguridad)
  - [Contribuir](#contribuir)
    - [Guía de Contribución](#guía-de-contribución)
  - [Licencia](#licencia)

## Instalación

```bash
pip install EnDecrypter
```

### Requisitos
- Python 3.12+
- pycryptodome (para cifrados DES)

## Características

- 📜 **Cifrados Clásicos**
  - César
  - Monoalfabético
  - Polialfabético (Vigenère)
  - Transposición (Rail Fence)
  
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

El cifrado César desplaza cada letra del alfabeto un número fijo de posiciones.

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

Sustituye cada letra por otra según un alfabeto de sustitución aleatorio.

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

Implementación del cifrado Vigenère que usa una palabra clave para cifrar.

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

Implementación del cifrado Rail Fence que reordena las letras en un patrón zigzag.

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

### Cifrado DES

Implementación del algoritmo DES (Data Encryption Standard).

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

Implementación del algoritmo de cifrado de flujo RC4.

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

Implementacion del algoritmo de cifrado RC5

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

Implementacion del Cifrado RC6, el RC5 mejorado

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

Implementacion del Triple DES, DES pero genera 3 llaves mas que el DES

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

Herramientas para conversión entre texto y formato binario.

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
| DES | Moderno | 8 bytes | Media-Alta | Datos sensibles |
| RC4 | Moderno | Variable | Media | Datos sensibles |
| Binario | Util | Texto | Muy Baja | Educativo |
| 3DES | Moderno | 3 de 24 bytes | Alta | Datos comunes |
| RC5 | Moderno | 16 bytes | Media-Alta | Datos sensibles |
| RC6 | Moderno | 16 bytes | Alta | Datos sensibles |

### Consideraciones de Seguridad

- Los cifrados clásicos son **solo para fines educativos**
- DES y RC4, aunque más seguros, pueden no ser suficientes para datos altamente sensibles
- Para máxima seguridad, considere usar algoritmos más modernos como AES o si no pruebe usando 3DES ya implementado

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
