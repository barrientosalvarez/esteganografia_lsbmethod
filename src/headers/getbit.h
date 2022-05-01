/*
 * Header del proyecto Esteganografía por el método LSB, el cual contiene la función
 * 'getBit', la cual es usada en los headers 'encode.h' y 'decode.h'. Esta función
 * accede al bit en una posición en específico de un caracter y lo devuelve.
 *
 * Hecho por Jorge Miguel Aaron Barrientos Alvarez
 * Contacto: jma.barrientos@ciencias.unam.mx
 *
 * Este es un proyecto de software libre.
 *
 * Abril2022
 */


#ifndef GETBIT
#define GETBIT

/**
 * Funcion que dado un caracter y una posición devuelve el bit del caracter ubicado
 * en dicha posición. Por comodidad se optó por usar una función que devuelve un
 * booleano: recordemos que 1 es equivalente a true y que 0 es equivalente a 
 * false.
 * La forma de acceder al bit menos significativo es usando al operador '&', ya que,
 * si bit menos significativo de un caracter c es 0, entonces c&1=0; de forma
 * similar, si el bit menos significativo de un caracter c es 1, entonces c&1=1.
 * @param un caracter y un índice entero; será extraido el bit i-ésimo del caracter
 * recibido.
 */
bool getBit(char c, int i)
{
    c>>=i;
    if(c & 1)
        return true;
    return false;
}

#endif
