# SE2023-644275-TP1-DATASYS3
Controlador de teclado DATASYS3

Consigna

Implemente un controlador para el teclado DATASYS 3 que registre la presión de teclas y
las comunique por UART. Implemente una estrategia en la máquina de estados para evitar rebotes o falsas presiones. Desarrolle una solución a la propuesta basándose en una máquina de estados.
Utilice su criterio para determinar dónde y hasta qué profundidad desarrollar la solución con la máquina.


Descripción de la solución realizada

En líneas generales, el programa consiste en una máquina de 4 estados, implementada con punteros a funciones. Dentro del bucle principal, se relevan las variables y define el evento ocurrido en función de las antedichas. Seguido, se hace la llamada a la función que toma como parámetros el puntero de estados y el evento.
En la máquina de estados se dispone de un estado inicial y principal de escritura llamado “ESCRIBIENDO”, dónde el teclado DATASYS3 a disposición del usuario para que envíe caracteres mediante el puerto UART.
Por otro lado, está la posibilidad de, mediante la recepción de ciertas palabras claves vía UART, configurar el carácter o significado asignado a cada una de las teclas del DATASYS3. Para ello, basta con enviar la palabra clave “usar” y se actualizará el estado a “SETEO”. Una vez dentro, se puede volver al estado de escritura enviando la palabra “salir” mediante UART o, simplemente, esperando que se active el tiempo máximo de espera, volverá al estado ESCRIBIENDO.
Los estados mencionados, ESCRIBIENDO Y SETEO, tienen como disparador para cambiar de estado al evento “evt_presion_tecla”. Este evento es definido cuando se recibe el pulso de una tecla del DATASYS3. 
En ambos casos, al recibir el evento que indica la presión de una tecla, se muta a los estados “REBOTES_ESC” Y “REBOTES_SET” respectivamente, que determinarán si se trató de una señal espuria o efectivamente un pulsador accionado. 
Para lograr dicha definición, en ambos estados se realiza periódicamente una serie de chequeos de la tecla presionada. Este mecanismo consiste en disparar un evento temporizado que realiza la comparación entre la tecla presionada originalmente y la “nueva tecla” oprimida. Si coinciden aumentará un comparador y, en caso contrario, se decrementará. Este mecanismo es repetido hasta el disparo de un evento temporizador. 
Al terminar estas comparaciones, y salir del estado que chequea la veracidad de la señal tecla oprimida, se evalúa la variable comparadora para decidir si accionar con el carácter correspondiente o no. 
Terminado el proceso de decisión, dónde se realiza una acción o no con el carácter, se retorna al estado previo. En el caso ESCRIBIENDO, se decide si enviar o no el carácter y retorna al estado; por otro lado, para el estado SETEO, se decide si asignar o no el carácter antes de retornar.



Biblioteca externa utilizada: “keypad_8x16.h”

Para realizar el controlador del teclado DATASYS3, se generó el código pertinente al caso para realizar el escaneo de un teclado matricial genérico de 8 filas y 16 columnas. 
En él se encuentran configurados los puertos utilizados y la iniciación de los mismos, basándose en que se utilizará en la placa de desarrollo Blue Pill con el micro procesador STM32F103C8T6. Sin embargo, por el formato utilizado, se dispone la posibilidad de modificación y adaptación a otros teclados y/o procesadores de manera sencilla.


