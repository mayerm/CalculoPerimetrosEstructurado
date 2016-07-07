// CalculadorDePerimetros.cpp : Calcula perimetros de un rectángulo y un triángulo, y la circunferencia de un círculo.
//

#include "stdafx.h"
#include <iostream>
#include <math.h>

const double PI = 3.141592653589793; //PI no está definido en la librería de math.h
struct Punto { double x, y; };
struct Circulo { Punto centro; double radio; };
struct Triangulo { Punto a, b, c; };
struct Rectangulo { double b, h; };

double ReadDouble(){
	double number;
	std::cout << "Ingrese un numero real, separando el entero del decimal con un '.'\n";
	std::cin >> number;
	return number;
}

Punto ReadPunto(){
	Punto punto;
	std::cout << "Ingrese el valor del eje X y luego el valor del eje Y\n\n";
	punto.x = ReadDouble();
	punto.y = ReadDouble();
	return punto;
}

Circulo ReadCirculo(){
	Circulo circulo;
	std::cout << "Ingrese el centro del circulo\n";
	circulo.centro = ReadPunto();
	std::cout << "Ingrese el radio del circulo\n";
	circulo.radio = ReadDouble();
	return circulo;
}

Triangulo ReadTriangulo(){
	Triangulo triangulo;
	std::cout << "Ingrese los vertices\n";
	triangulo.a = ReadPunto();
	triangulo.b = ReadPunto();
	triangulo.c = ReadPunto();
	return triangulo;
}

Rectangulo ReadRectangulo(){
	Rectangulo rectangulo;
//	std::cout << "Ingrese el punto de origen del cuadrado\n";
//  rectangulo.origen = ReadPunto();
	std::cout << "Ingrese la base y la altura del cuadrado\n";
	rectangulo.b = ReadDouble();
	rectangulo.h = ReadDouble();
	return rectangulo;
}

double GetCircunferencia(Circulo circulo){
	std::cout << "La circunferencia del círculo con centro (" << circulo.centro.x <<
		"," << circulo.centro.y << ") y radio " << circulo.radio << " es ";
	return (PI * 2 * circulo.radio);
}

double GetLongitudLado(Punto punto1, Punto punto2){
	return sqrt(pow(punto2.x - punto1.x, 2) + pow(punto2.y - punto1.y, 2));
}

double GetPerimTriang(Triangulo triangulo){
	std::cout << "El perimetro del triangulo con vertices (" 
		<< triangulo.a.x <<	"," << triangulo.a.y << "), (" 
		<< triangulo.b.x << "," << triangulo.b.y << "), (" 
		<< triangulo.c.x <<	"," << triangulo.c.y << ") es ";	
	return (GetLongitudLado(triangulo.a, triangulo.b) + GetLongitudLado(triangulo.b, triangulo.c) + GetLongitudLado(triangulo.c, triangulo.a));
}

double GetPerimRectang(Rectangulo rectangulo){
	std::cout << "El perimetro del rectangulo con base " << rectangulo.b << " y altura " << rectangulo.h << " es ";
	return (2 * (rectangulo.b + rectangulo.h));
}

int main()
{
	std::cout << GetCircunferencia(ReadCirculo()) << ".\n";
	std::cout << GetPerimTriang(ReadTriangulo()) << ".\n";
	std::cout << GetPerimRectang(ReadRectangulo()) << ".\n";
	return 0;
}

