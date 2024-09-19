# Bancos - Sistema de gestion de cuentas bancarias
## Objetivos
Este proyecto tiene como finalidad desarrollar un sistema de gestión de cuentas bancarias que permita al consultor del banco registrar cuentas nuevas y consultar cuentas existentes. Cada cuenta incluye información sobre el titular y el saldo disponible. Además, se proporciona funcionalidad para listar las cuentas de manera ordenada, ya sea por el saldo (de forma ascendente o descendente) o por el nombre del titula

##Código
El código está diseñado con varias funciones clave:

Registro de cuentas: Permite al usuario registrar nuevas cuentas bancarias. Cada cuenta incluye información del titular (nombre y ciudad) y un saldo asociado.
Ordenación: Se implementa un algoritmo de ordenación tipo bubble sort para ordenar las cuentas. Este algoritmo es utilizado debido a su simplicidad y facilidad de manejo, lo que es adecuado para este tipo de sistemas.
Persistencia de datos: Los datos de las cuentas se almacenan en un archivo de texto (cuentas.txt) que registra todas las cuentas nuevas. De este modo, se asegura que las cuentas permanezcan almacenadas y sean recuperables en futuras ejecuciones del programa.

###Funcionalidades principales

Registrar una nueva cuenta:

  Se solicita al usuario el nombre del titular y el saldo de la cuenta.
  Los datos ingresados se almacenan en el archivo de texto cuentas.txt.
  
Mostrar cuentas registradas:

  El sistema puede mostrar las cuentas ordenadas de forma ascendente o descendente por el saldo o por el nombre del titular de la cuenta.

### Archivos clave del proyecto

1.main.cpp: Contiene el menú principal que permite al consultor interactuar con el sistema.
2.cuentas.txt: Archivo que almacena todas las cuentas registradas. Este archivo es fundamental para la persistencia de los datos.
3.cuentas.hpp: Define la estructura de la clase Cuenta y las funciones necesarias para el manejo de las cuentas bancarias.
4.cuentas.cpp: Implementa las funciones definidas en cuentas.hpp.


## Excepciones y recomendaciones
Es importante tomar en cuenta las siguientes consideraciones para asegurar el correcto funcionamiento del sistema:

-Validación de entradas numéricas: Si el usuario ingresa un número no válido (por ejemplo, una opción del menú que no existe), el sistema lanzará una excepción indicando que el número no es válido.
-Entrada de datos incorrecta: Si el usuario ingresa una letra o palabra en un campo donde se espera un número (como el saldo), el sistema podría comportarse de manera inesperada. Se recomienda interrumpir la ejecución y corregir el error para evitar un bloqueo.
-Números grandes: Si se ingresan números grandes para el saldo (mayores de 6 cifras), es posible que estos se representen en notación científica (por ejemplo, 5.02847e10). Si bien no afecta el funcionamiento del programa, esto podría confundir al usuario.
-Archivos de datos: El archivo cuentas.txt es esencial para el correcto funcionamiento del sistema. Si este archivo se elimina o se modifica incorrectamente, el sistema podría presentar fallos al intentar cargar las cuentas.

### Excepciones y recomendaciones adicionales
.Se recomienda no modificar manualmente el archivo cuentas.txt sin seguir el formato correcto para evitar errores.
.En caso de error en el ingreso de datos, se puede reiniciar el programa para corregir el flujo de ejecución.

  
 


    
