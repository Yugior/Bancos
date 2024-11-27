# Bancos - Sistema de gestion de cuentas bancarias
## Objetivos
Este proyecto tiene como finalidad desarrollar un sistema de gestión de cuentas bancarias que permita al consultor del banco registrar cuentas nuevas y consultar cuentas existentes. Cada cuenta incluye información sobre el titular y el saldo disponible. Además, se proporciona funcionalidad para listar las cuentas de manera ordenada, ya sea por el saldo o por el nombre del titula

## Código
El código está diseñado con varias funciones clave:

### Complejidad del sistema

Considerando los archivos que se tienen en la implementación del proyecto, la complejidad final del programa es **O(n log n)** debido a la implementación de **Merge Sort** como método de ordenamiento. A continuación, se analiza de manera individual cada archivo para llegar a esta conclusión.

#### Main.cpp
El archivo `main.cpp` contiene el flujo principal de control y usa una instancia de `ListaDobleLigada` para manejar las cuentas. La complejidad depende de las operaciones en la clase `ListaDobleLigada` y la frecuencia de las opciones seleccionadas en el menú. Si bien la mayoría de las funciones varían en el main entre **O(1)** y **O(n)**, el peor caso de ejecución para el ordenamiento es ahora **O(n log n)** debido al cambio de Bubble Sort a Merge Sort.

#### Listas.h
En el archivo `Listas.h` se encuentran tres clases diferentes: **Nodo**, **Cuenta**, y **ListaDobleLigada**. Las clases de **Nodo** y **Cuenta** tienen una complejidad promedio de **O(1)**. Sin embargo, la clase `ListaDobleLigada` ahora utiliza **Merge Sort** para ordenar las cuentas, lo que reduce la complejidad de las funciones de ordenamiento a **O(n log n)**, en comparación con la anterior **O(n²)** de Bubble Sort.

#### Cuenta.h
Este archivo posee funciones similares a las encontradas en `Listas.h`; por lo tanto, su complejidad es **O(1)**.

#### Banco.h
Las funciones que administra, como `guardarCuentas` (que recorre todo el arreglo de cuentas), son en su mayoría **O(n)**. En casos diferentes, se tiene la función `getCuentas()` e `insertCuenta()` cuya complejidad es **O(1)**.

---

## Funcionalidades principales

### Registro de cuentas:
- Permite al usuario registrar nuevas cuentas bancarias. 
- Los datos ingresados se almacenan en el archivo de texto `cuentas.txt`, lo que permite que las cuentas nuevas se guarden permanentemente.

### Ordenación:
El código implementa **Merge Sort** dentro del archivo `Listas.h` en las funciones `ordenarPorNombre` y `ordenarPorDinero` de la clase `ListaDobleLigada`. Merge Sort divide la lista en sublistas más pequeñas, las ordena y luego las fusiona eficientemente en una lista ordenada.

#### Complejidad de Merge Sort:
- **Peor caso:** O(n log n)
- **Mejor caso:** O(n log n)
- **Promedio:** O(n log n)

Esto mejora considerablemente la eficiencia en comparación con Bubble Sort, especialmente para listas largas.

Características clave del nuevo método de ordenamiento:
- **Por nombre:** Ordena las cuentas alfabéticamente de acuerdo con el nombre del titular.
- **Por saldo:** Ordena las cuentas de forma ascendente o descendente según el saldo.
  
#### Persistencia de datos:
Los datos de las cuentas se almacenan en un archivo de texto (`cuentas.txt`), que guarda permanentemente todas las cuentas registradas, incluso tras cerrar el programa. Así, en futuras ejecuciones, se pueden recuperar y seguir gestionando.

#### Uso de listas doblemente ligadas:
- Las cuentas se gestionan a través de una lista doblemente ligada que permite una eficiente inserción y navegación tanto hacia adelante como hacia atrás.
- El sistema utiliza la estructura de nodos para almacenar cada cuenta y sus relaciones con cuentas anteriores y posteriores.


### Funcionalidades principales

Registrar una nueva cuenta:
  El sistema solicita al usuario el nombre del titular y el saldo de la cuenta.
  Los datos ingresados se guardan automáticamente en el archivo cuentas.txt.
  
Mostrar cuentas registradas:
  Se puede mostrar la lista de cuentas registradas, que pueden ordenarse:
  Por saldo, en orden ascendente o descendente.
  Por nombre, en orden alfabético.
  
Ordenar las cuentas:
  La lista de cuentas se puede ordenar:
  Por saldo: Permite visualizar de mayor a menor o viceversa.
  Por nombre: Ordena alfabéticamente a los titulares de las cuentas.
  
Guardar cuentas en archivo:
Tras cualquier modificación o registro de nuevas cuentas, el sistema guarda los cambios en el archivo cuentas.txt, asegurando la persistencia de la información.

### Archivos clave del proyecto

1.main.cpp: Contiene el menú principal que permite al consultor interactuar con el sistema.
2.cuentas.txt: Archivo que almacena todas las cuentas registradas. Este archivo es fundamental para la persistencia de los datos.
3.Cuenta.h: Define la estructura de la clase Cuenta y las funciones necesarias para el manejo de las cuentas bancarias.
4.Listas. Implementa una lista doblemente ligada para gestionar las cuentas de manera eficiente y estructurada, incluyendo métodos para insertar, mostrar, y ordenar cuentas.


## Excepciones y recomendaciones
Es importante considerar las siguientes recomendaciones para asegurar el correcto funcionamiento del sistema:

#### Validación de entradas numéricas:

  Si el usuario ingresa un valor no válido (por ejemplo, una opción del menú que no existe), el sistema lanzará una excepción que indicará que el número no es válido.
  Entrada de datos incorrecta:

  Si el usuario ingresa texto donde se espera un valor numérico (como el saldo), el sistema podría fallar o comportarse de manera inesperada. Es recomendable reiniciar el programa en caso de que ocurra este error.  
#### Números grandes en los saldos:

  Si se ingresan números muy grandes (mayores de 6 cifras) como saldo, podrían ser mostrados en notación científica (por ejemplo, 5.02847e10). Si bien esto no afecta el funcionamiento del programa, podría ser confuso para el usuario.
  Persistencia y manipulación del archivo cuentas.txt:
  
  El archivo cuentas.txt es esencial para la correcta operación del sistema. Si este archivo se elimina o se modifica incorrectamente, el sistema podría fallar al intentar cargar las cuentas.
  Se recomienda no modificar manualmente el archivo sin seguir el formato correcto para evitar errores.
  Reinicio en caso de error:

En caso de errores en el ingreso de datos, es aconsejable reiniciar el programa para corregir el flujo de ejecución.

### Excepciones y recomendaciones adicionales
.Se recomienda no modificar manualmente el archivo cuentas.txt sin seguir el formato correcto para evitar errores.
.En caso de error en el ingreso de datos, se puede reiniciar el programa para corregir el flujo de ejecución.

### Solución de errores y correcciones
El primer error que el sistema arrojo se dio al no reconocer ni encontrar las funciones que conforman el codigo al importarlas al `main.cpp`
En su anterioridad, el codigo dividida los archivos en `.h` y `.cpp` para una mejor lectura de este; sin embargo el error permaencia tras intentos de corregirlo y se opto por usar únicamente archivos `.h`, sacrificando lejibilidad y formato del programa a cambio de la compliación correcta del mismo proyecto.

Dentro del proyecto se uso buble sort para el ordenamiento de las cuentas en el proyecto debido a lo sencillo de porgramarlo e incluirlo, sin embargo debido las necesidades del cliente, ya su poca escalabilidad respecto a una mayor carga de datos, se modifico el archivo `Listas.h` quien se encargaba de ordenar las listar con BubleSort;Ahora se ha realizado un cambi para utilizar MergeSort y bajar su complejidad a O(n log n).

  
 


    
