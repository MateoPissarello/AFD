
# Implementación de un Autómata Finito Determinista en C

En este proyecto se realiza la implementación de un autómata finito determinista en C.

Un AFD está definido por una 5-tupla (**Q**, **Σ**, **δ**, **q0**, **F**) donde:
- **Q**: Conjunto finito de estados.
- **Σ**: Conjunto finito de símbolos (alfabeto).
- **δ**: Función de transición (Q × Σ → Q).
- **q0**: Estado inicial (q0 ∈ Q).
- **F**: Conjunto de estados de aceptación (F ⊆ Q).

El objetivo es crear un autómata que reciba una cadena y determine si es válida o no.
 
## ¿Cómo usarlo?

El código está diseñado para ser utilizado en una máquina que ejecute alguna distribución de Linux, y que cuente con [gcc](https://gcc.gnu.org/).

Una vez clonado este [repositorio](https://github.com/MateoPissarello/AFD.git) tendremos un binario ejecutable llamado **AFD**.

Este binario puede ser ejecutado facilmente desde la terminal:
```
$ ./AFD
```
### Ejemplo de ejecución

Una ejecución del programa se puede ver como lo siguiente:
```
Ingrese el nombre del archivo de configuracion (debe estar ubicado en la carpeta tests/): test01.txt
Ingrese la cadena a evaluar: aba
aba
Resultado: La cadena fue rechazada.
Ingrese la cadena a evaluar: abb
abb
Resultado: La cadena fue rechazada.
Ingrese la cadena a evaluar: ab
ab
Resultado: La cadena fue aceptada.
Ingrese la cadena a evaluar: abbb
abbb
Resultado: La cadena fue aceptada.
```
La primera línea indica que se debe ingresar el nombre del archivo de configuración, el cual debe estar ubicado en la carpeta **tests/**. Por defecto, se proporcionan algunos ejemplos, pero si lo deseas, puedes crear los tuyos propios, siempre y cuando se respete la **estructura del archivo de configuración**, que será explicada en detalle en otra sección.

Una vez indicado el archivo, podemos ingresar tantas cadenas como se desee, y el programa irá indicando si son cadenas válidas o no.

### Estructura del Archivo de Configuración
El archivo **test01.txt** se ve de la siguiente forma:
```
123 
ab
1
3
1a2
2b3
3a1
3b2
```
En este caso, el archivo cuenta con 8 líneas. A continuación, se detalla lo que representa cada una.
- **Primera línea (Q)**:
    ```
    123
    ```
    representa los estados cada estado debe ser representado por un `carácter individual`. En caso de tener más de uno, se deben colocar uno pegado al otro, sin espacios. Es decir, en este caso tenemos 3 estados:
    - Primer estado: 1
    - Segundo estado: 2
    - Tercer estado: 3
    Por lo tanto, un estado se representa por un caracter individual que es cualquier digito de la tabla [ASCII](https://elcodigoascii.com.ar/#google_vignette) que vaya hasta el número 127.

- **Segunda línea (Σ)**: 
    ```
    ab
    ```
    Esta linea indica cual es el alfabeto del Autómata. Al igual que los estados se representa por un `carácter individual`. De igual forma, si se tiene mas de un carácter en el alfabeto, se deben colocar uno pegado al otro.
    - Primer carácter del alfabeto: a
    - Segundo carácter del alfabeto: b

- **Tercera línea (q0)**:
    ```
    1
    ```
    Esta línea indica el estado inicial del autómata. Es importante resaltar que este solo puede estar conformado por un carácter; en caso de que haya más de uno, se devolverá un error.

- **Cuarta línea (F)**:
    ```
    3
    ```
    La línea 4 equivale al conjunto de estados de aceptación y se representa de la misma forma que en las líneas anteriores: si se tiene más de uno, se deben escribir pegados y sin espacios. Es importante que el estado de aceptación esté dentro de los estados definidos en la primera línea; de lo contrario, se devolverá un error.

- **Más alla de la Cuarta línea hasta el final del archivo (δ)**:
    ```
    1a2
    2b3
    3a1
    3b2
    ```
    Cada una de las líneas que siguen a la cuarta representa funciones de transición. Dichas funciones deben estar definidas con la estructura `estado_inicial` `carácter_alfabeto` `estado_destino`. Como es de esperar, los estados deben pertenecer a los estados definidos, y el carácter del alfabeto debe estar dentro de los definidos. En este caso tenemos 4 funciones de transición:
    - **Primera función de transicion**:
        ```
        1a2
        ```
        Ir del estado 1 al estado 2 a traves de a.
    
    - **Segunda función de transición**:
        ```
        2b3
        ```
        Ir del estado 2 al estado 3 a través de b.
    
    - **Tercera función de transición**:
        ```
        3a1
        ```
        Ir del estado 3 al estado 1 a través de a.
    
    - **Cuarta función de transición**
        ```
        3b2
        ```
        Ir del estado 3 al estado 2 a través de b.

### Diagramas de configuraciones
Si es necesario, para tener mas claridad, dentro de la carpeta de **tests**, existe otra llamada [**tests_diagrams**](https://github.com/MateoPissarello/AFD/tree/main/tests/tests_diagrams), que contiene la representación visual de cada uno de los archivos de configuración.

## Relacionado

Un repositorio que fue tomado como base para la creación de este proyecto es el siguiente:

[ADF_LP_2024_2 ](https://github.com/jofsanchezci/ADF_LP_2024_2.git)


## Autores

- [@MateoPissarello](https://github.com/MateoPissarello)
- [@DavidRJimenez](https://github.com/DavidRJimenez)
- [@CesarMartinez02](https://github.com/CesarMartinez02)

