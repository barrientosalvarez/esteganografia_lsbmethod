/*
 * Clase main del proyecto Esteganografia por el método LSB. Este main procesa
 * los datos que el usuario ingresa por terminal, para que, en caso de que 
 * cumplan con el formato requerido, se prosiga a codificar o a develar un mensaje
 * (dependiendo de lo que pida el usuario). En caso de que los datos recibidos
 * no cumplan con el formato requerido, se enviará un mensaje de error en terminal y se 
 * solicitará sean ingresados nuevamente. En caso de que los datos ingresados 
 * hayan cumplido el formato requerido, y el proceso de esteganografía haya sido
 * realizado con éxito, se le notificará al usuario mediante un mensaje en terminal.
 *
 * Hecho por Jorge Miguel Aaron Barrientos Alvarez.
 * Contacto: jma.barrientos@ciencias.unam.mx.
 *
 * Este es un proyecto de software libre.
 *
 * Mi pinche kainal tiene que aprender a usar git :v
 * Abril 2022.
 */

#include <opencv4/opencv2/highgui/highgui.hpp>
#include <iostream>
#include <string.h>
#include "headers/encode.h"
#include "headers/decode.h"

using namespace std;

int main(int argc, char** argv)
{
    string c=argv[1];
    if(argc==5 && (c=="h" || c=="H"))
    {
        encode(argv);
        
    }

    else if(argc==4 && (c=="u" || c=="U"))
    {
        decode(argv);
    }
    else
    {
        cout<<"Argumentos erróneos, inténtese otra vez."<<endl;
        exit(-1);
    }
    
    cout<<"El proceso de esteganografía se realizó con éxito."<<endl;
    return 0;
}
