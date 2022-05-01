/*
 * Header del proyecto Esteganografia por el método LSB, el cual contiene la función
 * que nos permite ocultar (o codificar) un mensaje de texto simple en una imagen
 * con formato png de tal forma que el mensaje quede intacto y que la imagen no
 * presente variaciones visibles al ojo humano. Para entender más a profundidad el
 * funcionamiento de este header, recomiendo revisar la documentación de las bibliotecas
 * 'fstream' y 'opencv'.
 *
 * Hecho por Jorge Miguel Aaron Barrientos Alvarez.
 * Contacto: jma.barrientos@ciencias.unam.mx
 *
 * Este es un proyecto de software libre.
 *
 * Abril 2022.
 */

#ifndef ENCODE
#define ENCODE

#include <string.h>
#include <iostream>
#include <fstream>
#include <opencv4/opencv2/highgui/highgui.hpp>
#include "getbit.h"

using namespace std;
using namespace cv;

/**
 * Función que recive una serie de argumentos, accede y procesa los que son necesarios
 * y oculta el mensaje de un archivo de texto especificado en una imagen también
 * especificada. 
 * Esta función sigue la estrategia de la esteganografía por el método LSB: se busca
 * ocultar el mensaje en los bits menos significativos de los canales de los pixeles, 
 * de esta forma se puede ocultar un mensaje en una imagen sin que esta presente
 * cambios apreciables por el ojo humano respecto a la imagen original.
 * @param arreglo de argumentos ingresados por el usuario desde la terminal.
 */
int encode(char** argv)
{
    ifstream file(argv[2]);
    if(!file.is_open())
    {
        cout<<"Error al abrir el archivo. Inténtelo otra vez."<<endl;
        exit(-1);
    }

    Mat image=imread(argv[3]);
    if(image.empty())
    {
        cout<<"Error al abrir al imagen. Inténtelo otra vez."<<endl;
        exit(-1);
    }

    char c;
    file.get(c);
    int bitCounter=0;
    bool isNullChar=false;
    bool occult=false;

    for(int i=0; i<image.rows; i++)
    {
        for(int j=0; j<image.cols; j++)
        {
            for(int rgb=0; rgb<3; rgb++)
            {
                Vec3b pixel=image.at<Vec3b>(Point(i,j));

                if(getBit(c, 7-bitCounter))
                    pixel.val[rgb]|=1;

                else
                    pixel.val[rgb]&=254;

                image.at<Vec3b>(Point(i,j))=pixel;
                bitCounter++;

                if(isNullChar && bitCounter==8)
                {
                    occult=true;
                    goto EXIT;
                }

                if(bitCounter==8)
                {
                    bitCounter=0;
                    file.get(c);

                    if(file.eof())
                    {
                        isNullChar=true;
                        c='\0';
                    }
                }
            }
        }
    }
    EXIT:;
    
    if(!occult)
    {
        cout<<"No se pudo ocultar por completo el mensaje."<<endl;
        cout<<"Inténtese de nuevo con una imagen más grande"<<endl;
        exit(-1);
    }

    imwrite(argv[4], image);

    return 0;
}

#endif
