#include <stdio.h>
#include <math.h> 

struct paquete
{
    int id;     //identificador de cada paquete
    int masa;   //masa del paquete que se genera aleatoriamente
    int tipo;   /**tipo de paquete:
                 0 = normal
                 1 = urgente
                 2 = radioactivo*/
};

int generarPaquetes()
{

}

double Gaussian_Distribution( double x )
{
   return  0.5 * ( 1.0 + erf( M_SQRT1_2 * x ) );
}

int main (int argc, const char* argv[] ) {
    
    printf("hello from transporter");
    
    return 0;
}