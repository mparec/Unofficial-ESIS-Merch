#include "cabecera.h"
using namespace std;

void comprar(double &bolsillo, double &carrito, int &articulos) {
	if (articulos > 0) { // verifica si hay articulos en el carrito
		if (articulos >= 3) { // Verifica si hay al menos 3 articulos para el descuento
			bolsillo -= 0.67 * carrito;
		} else {
			bolsillo -= carrito;
		}
		carrito = 0.0;
		articulos = 0;
	}
}