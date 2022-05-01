/*
 * Header del proyecto Esteganografia por el método LSB, el cual contiene la función
 * que nos permite develar (o decodificar) un mensaje de texto simple que ha sido
 * ocultado con anterioridad en una imagen con formato png. Para entender más a 
 * profundidad el funcionamiento de este header, recomiendo revisar la documentación
 * de las bibliotecas 'fstream' y 'opencv'.
 *
 * Hecho por Jorge Miguel Aaron Barrientos Alvarez.
 * Contacto: jma.barrientos@ciencias.unam.mx
 *
 * Este es un proyecto de software libre.
 *
 * Abril 2022.
 */


#ifndef DECODE
#define DECODE

#include <iostream>
#include <fstream>
#include <opencv4/opencv2/highgui/highgui.hpp>
#include "getbit.h"
#include <string.h>
using namespace std;
using namespace cv;

/**
 * Funcion que recive una serie de argumentos, accede y procesa los que son necesarios
 * y devela el mensaje de texto simple oculto en una imagen para posteriormente 
 * gaurdar dicho mensaje en un archivo de texto.
 * Esta función sigue la estrategia de la esteganografía por el método LSB; accede
 * al bit menos significativo de cada byte de cada canal de color de la imagen, 
 * para crear el mensaje con dicha información.
 * @param arreglo de argumentos ingresados por el usuario desde la terminal.
 */
int decode(char** argv)
{
    Mat image=imread(argv[2]);
    if(image.empty())
    {
        cout<<"Ocurrió un error al tratar de abrir la imagen, inténtese otra vez."<<endl;
        exit(-1);
    }

    string message="";
    char c=0;
    int bitCounter=0;

    for(int i=0; i<image.rows; i++)
    {
        for(int j=0; j<image.cols; j++)
        {
            for(int rgb=0; rgb<3; rgb++)
            {
                Vec3b pixel=image.at<Vec3b>(Point(i,j));

                if(getBit(pixel.val[rgb], 0))
                    c|=1;

                bitCounter++;

                if(bitCounter==8)
                {
                    if(c=='\0')
                        goto EXIT;

                    message+=c;
                    c=0;
                    bitCounter=0;
                }
                else
                {
                    c<<=1;
                }
            }
        }
    }
    EXIT:;
    
    ofstream file;
    file.open(argv[3]);
    file<<message;
    file.close();
    return 0;

}

#endif
