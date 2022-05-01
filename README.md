# Proyecto 2 Modelado y programación 2022-2.

Esteganografía por método LSB.

## Semblanza.
La esteganografía es el conunto de técnicas algorítmocas para ocultar un conjunto de datos en otro de forma

que los primeros no sean evidentes, permanezcan integros y sean recuperables mientras que los segundos, a los

que se les denomina portadores, no deben verse alterados de manera evidente. Un método común es ocultar 

mensajes de texto claro en archivos de imágenes. Se aprovecha en este caso el hecho de que, con frecuencia, 

las imágenes no requieren de preservar todos los datos que contienen para ser útiles.

Un método usado para almacenar un archivo de texto en una imagen consiste en usar el bit menos significativo de 

cada byte de datos de la imagen para guardar un bit de los datos a ocultar.

## Distribución del proyecto.
Dentro de la carpeta 'resources' se agregaron imagenes png y archivos de texto plano con mensajes de prueba que 

son útiles para probar el funcionamiento del proyecto. Las imágenes y los mensajes están relacionados, aunque 

pueden ser usados libremente.
```bash
.
├── esteganografia
├── README.md
├── resources
│   ├── images
│   │   ├── bcs.png
│   │   ├── fuji.png
│   │   ├── peaky.png
│   │   └── rulfo.png
│   └── messages
│       ├── mensajebcs.txt
│       ├── mensajecp.txt
│       ├── mensajejr.txt
│       └── mensajepb.txt
└── src
    ├── headers
    │   ├── decode.h
    │   ├── encode.h
    │   └── getbit.h
    └── main.cpp
```
## Requisitos.
Para la ejecusión correcta del proyecto necesitamos verificar que nuestro equipo cuenta con: 
* Un compilador para C++ (recomiendo ampliamente el compilador del GNU proyect). La instalación es sencilla y puedes
encontrarla en cualquier buscador web (recuerda especificar tu sistema operativo).
* La biblioteca OpenCV. En el caso que tu sistema operativo sea una distribución reciente de Ubuntu, vastará con correr
el siguiente comando en terminal para descargarla:
```bash
sudo apt install libopencv-dev
```
En otro caso la instalación será muy sencilla también y puedes encontrarla en cualquier buscador web (recuerda especificar
tu sistema operativo).

## Compilación. Por si acaso.
Para ejecutar el programa, tal cual como se encontró en el repositorio, no es necesario compilar nada. Pero, si por 

alguna razón llegase a ser necesario (por ejemplo, si el archivo ejecutable 'esteganografia' es eliminado 

permanentemente por error), para compilar el proyecto tenemos que hacer lo siguiente: estando en terminal y a la

altura de src debemos de correr el siguiente comando:
```bash
g++ -o esteganografia main.cpp `pkg-config --cflags --libs opencv4`
```
Una vez creado el archivo ejecutable 'esteganografia', recomiendo cortarlo y pegarlo a la altura de 

'esteganografia_lsb', para que el proyecto funcione con las instrucciones específicas a continuación. 

Esto no es completamente necesario, pero sí recomendable. Si prefieres dejar el ejecutable en una 

altura distinta, tendrás que  adecuar los comandos de las instrucciones siguientes con base en la 

nueva distribución de los archivos para que todo funcione correctamente.

## Ejecución.
Nota preeliminar: el proyecto funciona correctamente con imágenes en formato 'png', no puedo asegurar

que funcione correctamente con otros formatos. 


Para correr el programa es necesario correr el archivo ejecutable 'esteganografía'. La forma ideal es desde 

terminal y  a la altura de 'esteganografia_lsb'. Para ejecutar el programa, tienes que seguir al pie de la

letra las siguientes  instrucciones. Es importante que sigas las intrucciones al pie de la letra, de otra 

forma el proyecto no funcionará correctamente:

Primero, para ocultar un mensaje necesitarás lo siguiente:
* La poderosa bandera 'h' (también funciona 'H')
* El nombre del archivo que contiene el texto a ocultar. Recomiendo que lo coloques en la carpeta 'messages', dentro de 
'resources'. Esto para un manejo más ordenado y limpio de todos los archivos.
* El nombre del archivo de la imagen. Recomiendo que la coloques en la carpeta 'images', dentro de 'resources'. Esto
para un manejo más odenado y limpio de todos los archivos.
* El nombre del archivo de la imagen resultante con los datos ocultos. Recomiendo que pienses en un nombre descriptivo, 
esto para un manejo más ordenado y limpio de los archivos.

Cuando tengas todo esto, deberás de ejecutar el siguiente comando desde la terminal y a la altura de 'esteganografia_lsb':
```bash
./esteganografia h resources/messages/nombre_archivo_mensaje.txt resources/images/nombre_img_original.png resources/images/nombre_img_final.png 
```

Nota: los nombres son solo descriptivos e ilustrativos, no tienen que llamarse así necesariamente.

Si todo ha salido bien, se mostrará en terminal un mensaje informando que todo ha salido bien. Si todo salió

bien, se habrá creado una nueva imagen en la carpeta 'images', dentro de 'resources', la cual contiene

el mensaje escondido.

Luego, para develar un mensaje necesitarás lo siguiente:
* La poderosa bandera 'u' (también funciona con 'U')
* El nombre del archivo con la imagen que contiene los datos ocultos. Recomiendo que la coloques en la carpeta 'images',
dentro de 'resources'. Esto para un manejo más ordenado y limpio de los archivos.
* El nombre del archivo en el que se guardará el texto develado. Recomiendo que pienses en un nombre descriptivo, esto
para un manejo más ordenado y limpio de los archivos.

Cuando tengas todo esto, deberás de ejecutar el siguiente comando desde la terminal y a la altura de 'esteganografia_lsb':
```bash
./esteganografia u resources/images/imagen_con_mensaje.png resources/messages/archivo_para_mensaje.txt
```

Si todo ha salido bien, se mostraŕa en terminal un mensaje informando que todo ha salido bien. Si todo salió bien,

se habrá creado un nuevo archivo de texto en la carpeta 'messages', dentro de 'resources', el cual contendrá el mensaje develado.

## Mensaje de error.

Si por alguna razón se muestra en terminal un mensaje que indica que ha habido un error al recibir los argumentos,

vuelve a leer las instrucciones. Si el error persiste y estás 100% seguro que el error no es tuyo, siéntete en la 

libertad de revisar el código fuente para buscar posibles errores.

## Autor.

Jorge Miguel Aaron Barrientos Alvarez.

Contacto: jma.barrientos@ciencias.unam.mx

