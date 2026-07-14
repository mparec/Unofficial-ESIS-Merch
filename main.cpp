#include <iostream>
#include <conio.h>
#include <string>
#include <cstdlib>
#include "cabecera.h"
using namespace std;

struct Productos {
	string nombre[5] = {"Teclado mecanico", "Audifonos inalambricos", "Camiseta ESIS", "Cargador Portatil", "Airpods"};
	string ID[5] = {"0x45234", "0x73454", "0x84234", "0x85123", "0x24432"};
	double precio[5] = {175.5, 45.5, 12.4, 64.5, 250.6};
	int cantidad[5] = {5, 5, 5, 5, 5};
};

int main() {
	// Variables globales
	Productos P;
	double Bolsillo_derecho = 500.0;
	double carrito = 0.0;
	string cola; // ID ingresado
	int aeec = 0; // Articulos en el carrito
	bool producto_encontrado = false;
	
	while (true) {
		cout << // MENU
		"=============================================" << endl <<
		"            UNOFFICIAL ESIS MERCH            " << endl <<
		"=============================================" << endl <<
		"   1. INICIO                3. TU MOCHILA    " << endl <<
		"   2. TIENDA                0. SALIR         " << endl <<
		"=============================================" << endl <<
		">> Presione una tecla del 0 al 3: " << endl;	
		char opcion = _getch();
		
		switch (opcion) {
			case '1':
				system("cls");
				cout <<
				"=============================================" << endl <<
				"INICIO: BIENVENIDO A UNOFFICIAL ESIS MERCH " << endl <<
				"=============================================" << endl <<
				"En esta tienda virtual encontraras articulos " << endl <<
				"relacionados a la ESIS - UNJBG, hecha un " << endl <<
				"vistazo a la tienda presionando '2' o mira" << endl <<
				"los articulos en tu posesion presionando '3'," << endl <<
				"o sino presiona '0' para salir de la tienda." << endl <<
				"NOTA IMPORTANTE: A partir del 3er articulo en" << endl <<
				"el carrito obten un 33% de descuento!" << endl <<
				"DATO EXTRA: Para comprar el carrito ingresa" << endl <<
				"el ID 'ESIS-2026' en la tienda." << endl;
				break;
				
			case '2': {
				// Variables locales
				int pe;
				char ans;
				
				system("cls");
				cout <<
				"=============================================" << endl <<
				"TIENDA: LOS ARTICULOS MAS DESTACADOS" << endl <<
				"=============================================" << endl;
				for (int i = 0; i < 5; i++) {
					cout <<
					"Articulo " << i + 1 << ": " << P.nombre[i] << endl <<
					"ID: " << P.ID[i] << endl <<
					"Precio: $" << P.precio[i] << endl <<
					"Cantidad: " << P.cantidad[i] << endl <<
					"---------------------------------------------" << endl;
				}
				cout << "Tu bolsillo: $" << Bolsillo_derecho << endl;
				cout << ">> Escriba el ID del producto: "; cin >> cola;
				
				// ID Secreto
				
				if (cola == "ESIS-2026") { // AQUI SE USARA UNA FUNCION DE LA CABECERA
					comprar(Bolsillo_derecho, carrito, aeec);
					cout << 
					"---------------------------------------------" << endl <<
					"Carrito comprado!!!" << endl <<
					"Tu bolsillo: $" << Bolsillo_derecho << endl;
				} else {
					// Bucle de busqueda
					
						for (int i = 0; i < 5; i++) {
							if (cola == P.ID[i]) { // Encuentra el ID
								if (P.cantidad[i] > 0) { // Verifica si el articulo sigue disponible
									if (P.precio[i] <= Bolsillo_derecho) {
										producto_encontrado = true;
										pe = i;
										
									}
								}
							}
						}
					
					// Confirmar el producto encontrado
					
					if (producto_encontrado) {
						cout <<
						"---------------------------------------------" << endl <<
						"DATOS DEL PRODUCTO: " << endl <<
						"Nombre: " << P.nombre[pe] << endl <<
						"Precio: $" << P.precio[pe] << endl;
						cout << ">> Agregar este articulo al carrito? (S/Any)" << endl;
						cin >> ans;
						if (ans == 'S' || ans == 's') {
							if (carrito + P.precio[pe] <= Bolsillo_derecho) {
								aeec++;
								carrito += P.precio[pe];
								P.cantidad[pe]--;
								cout << "Precio acumulado: $" << carrito << endl;
								cout << "Articulos en el carrito: " << aeec << endl;
								if (aeec >= 3) {
									cout << "DESCUENTO ACTIVADO!!!" << endl;
								}
							} else {
								cout << "Lo sentimos, no puedes agregar mas articulos" << endl;
							}
						} else {
							cout << "Articulo ignorado..." << endl;
						}
					} else {
						cout << "Lo sentimos, algo salio mal..." << endl;
					}
					producto_encontrado = false;
				}		
				break;
			}
			
			case '3': {
				bool hay_productos = false;
				system("cls");
				cout <<
				"=============================================" << endl <<
				"TU MOCHILA: TUS ARTICULOS COMPRADOS O EN COLA" << endl <<
				"=============================================" << endl;
				for (int i = 0; i < 5; i++) {
					if (P.cantidad[i] < 5) { // Ya se realizaron compras
						cout <<
						"Articulo: " << P.nombre[i] << endl <<
						"Precio unitario: $" << P.precio[i] << endl <<
						"Unidades compradas: " << 5 - P.cantidad[i] << endl <<
						"Precio total: $" << P.precio[i] * (5 - P.cantidad[i]) << endl <<
						"---------------------------------------------" << endl;
						hay_productos = true;
					}
				}
				
				if (!hay_productos) {
					cout << "Lo sentimos, al parecer no compraste nada aun" << endl;
				}
				break;
			}
			
			case '0':
				cout << "Saliendo del programa, hasta luego...";
				return 0;
		}
	}
	
	return 0;
}