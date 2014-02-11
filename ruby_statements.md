STATEMENTS
==========

Daemons
-------

###01 First Daemon

Write a program that logs "I'm a daemon doing daemon things" into a tempfile every five seconds.

Use ruby 1.9.2 or above and

```ruby
Process.daemon
```

###02 Fork

Daemonize a program using _Kernel#fork_.


###03 Windows Service

Create a windows service accepting command line arguments register and delete.
With no arguments and when not registered it prints usage.
When initiated it shall watch for the existence of "_C:\WeAreOne.txt_" and if doesn't
exist or is removed it will recreate it with a default content.

Trabajo Resumen
---------------

Resuelve el problema marcado con tu número de lista resto 9. Usa _semaforos_ y _mutex_es o _pool_ de hilos.

###01 La Peluquería

Simula el comportamiento de una peluquería donde hay cuatro sillas para cortarse el pelo y 20 clientes. Imprime el número de cliente atendido y el número de silla en el que se le corta el pelo.

###02 La pescadería.

Crea un hilo que genera clientes en un periodo de tiempo aleatorio y un pescadero que tarda un tiempo aleatorio en atender a cada cliente. Avisa cuando se genere un cliente indicando su número de ticket. Imprime también el número de cliente que se va a atender.

###03 El supermercado

En un supermercado especializado en leche hay tres empleados que pueden atender la caja o reponer. El programa genera clientes transcurrido un periodo de tiempo aleatorio. Estos harán cola para coger un número variable (y menor de 6) de cartones de leche y se pondrán en línea de cajas para pagar. Por otro lado, los empleados tienen que reponer o cobrar. Simula el funcionamiento del supermercado, indicando en todo momento el número de clientes en cada cola y la ocupación de los empleados.

###04 De Excursión

Sea el array _colegio_ con 2000 niños y el array campo, inicialmente vacío, separados entre sí por un trayecto de 7 segundos. Usando 6 autobuses de 52 plazas que pueden cargar niños simultáneamente (aunque no al mismo niño) y descargarlos en el campo (aunque no en el mismo sitio), simular el transporte del colegio al campo.


###05 Problema Nocturno

Sean 2 personas de la misma estatura y talla que desean ir desde su barracón al baño para ir al servicio por la noche. Sea un par de zapatillas (derecha e izquierda). Las 2 personas pueden acceder simultáneamente a coger una zapatilla y luego otra. Crea un programa que asegure que todos van al servicio y devuelven las zapatillas sin que se produzca interbloqueo por tener uno la zapatilla del pie izquierdo y el otro la del derecho.

###06 Los Comensales

Sea una mesa circular con 4 platos y cuatro comensales. Para poder comer es necesario coger el cubierto de la izquierda y el de la derecha. Crea un programa donde los 4 comensales (4 hilos) coman un ratito y descansen un ratito.


###07 Lectores y Escritores

Sean 7 hilos que leen y otros 7 que escriben en cuatro ficheros. Los lectores pueden concurrir en un fichero. La escritura debe ser exclusiva y por tanto debe ser prioritaria. No se admitirán nuevos lectores si un escritor desea escribir. Escribe un programa cumpliendo lo anterior evite la inanición de los lectores. Los ficheros no son un recurso real, sino un objeto que permite leer y escribir.

###08 PI

Crea un proceso demonio que rellene un fichero en segundo plano con los decimales de PI usando el algritmo de Chudnosvsky. Cada nuevo término aporta 14 decimales más al cálculo.

###09 Los ascensores

Sea un rascacielo con planta alta y planta baja exclusivamente. Sean 3 ascensores con capacidad para 4 personas que pueden subir, bajar, cargar y descargar. El aforo de la planta alta son 20 personas. Crea un programa que simule el funcionamiento del edificio. Es posible que el ascensor diga que no es posible cargar en ese viaje. Los tres ascensores conocen en cada momento el aforo y el plan de carga de los otros ascensores.

