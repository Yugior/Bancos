# Bancos - Sistema de gestion de cuentas bancarias
## Objetivos
Este proyecto tiene como finalidad desarrollar un sistema de gestión de cuentas bancarias que permita al consultor del banco registrar cuentas nuevas y consultar cuentas existentes. Cada cuenta incluye información sobre el titular y el saldo disponible. Además, se proporciona funcionalidad para listar las cuentas de manera ordenada, ya sea por el saldo o por el nombre del titula

## Código
El código está diseñado con varias funciones clave:


#### Registro de cuentas: 
- Permite al usuario registrar nuevas cuentas bancarias. 
- Los datos ingresados se almacenan en el archivo de texto cuentas.txt, lo que permite que las cuentas nuevas se guarden permanentemente.
  
#### Ordenación: 
- Se implementan algoritmos de burbuja para ordenar las cuentas.
- La ordenación puede realizarse de dos maneras:
- Por nombre: Ordena las cuentas alfabéticamente de acuerdo con el nombre del titular.
- Por saldo: Ordena las cuentas de forma ascendente o descendente según el saldo.
- Aunque bubble sort tiene una complejidad de O(n²), es adecuado para este sistema por su simplicidad, dado que la cantidad de cuentas en este contexto es limitada.
  
#### Persistencia de datos:
Los datos de las cuentas se almacenan en un archivo de texto (cuentas.txt), que guarda permanentemente todas las cuentas registradas, incluso tras cerrar el programa. Así, en futuras ejecuciones, se pueden recuperar y seguir gestionando.

#### Uso de listas doblemente ligadas
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

  
 


    
