#include <iostream>
#include <windows.h>
using namespace std;

void CoordenadaUlam(int input, int &xs, int &ys)
{
	int step_count = 1;
	int step_limit = 2;
	int adder = 1;
	int x = 0, y = 0;
	for (int n = 2; n != input + 1; n++,
		step_count++) {
		if (step_count <= .5 * step_limit)
			x += adder;
		else if (step_count <= step_limit)
			y += adder;
		if (step_count == step_limit) {
			adder *= -1;
			step_limit += 2;
			step_count = 0;
		}
	}
	xs = x;
	ys = y;
}

int get_num_with_coordinates(int x, int y)
{
	int temp = 1;
	int tempx=0;
	int tempy=0;
	int cont = 1;
	while (true)
	{
		if (tempx == x && tempy == y)
		{
			break;
		}
		CoordenadaUlam(temp, tempx, tempy);
		//cout << tempx << " " << tempy << endl;
		temp++;
		cont++;
	}
	if (cont == 1)
	{
		return cont;
	}
	else
	{
		return cont - 1;
	}
}

int main()
{
	int opcion = 0;
	int xs;
	int ys;
	int input;
	while (true)
	{
		cout << "1) Obtener las coordenadas de un numero de la espiral de Ulam" << endl;
		cout << "2) Obtener un numero de la espiral de Ulam por medio de una coordenada" << endl;
		cout << "Ingrese 1 o 2" << endl;
		cin >> opcion;
		if (opcion == 1)
		{
			xs = 0;
			ys = 0;
			cout << "Ingrese numero de espiral: " << endl;
			cin >> input;
			CoordenadaUlam(input, xs, ys);
			cout << "x: " << xs << " y: " << ys << endl;
			system("pause");
			system("cls");
		}
		if (opcion == 2)
		{
			cout << "Ingrese la coordenada x: "; cin >> xs;
			cout << "Ingrese la coordenada y: "; cin >> ys;
			cout << "el numero de la espiral de Ulam que esta en esa coordenada es: "<<get_num_with_coordinates(xs, ys) << endl;
			system("pause");
			system("cls");
		}
	}
}
