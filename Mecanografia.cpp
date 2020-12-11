#include <iostream>
#include <conio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<windows.h>

using namespace std;

bool compara(char *s1, char *s2, int top){
	bool bandera = true;
	for(int i = 0; i < top; i++, s1++, s2++){
		if(*s1 != *s2){
			bandera = false;
			cout<<"\nError, letra #"<<i+1<<"["<<*s1<<"->"<<*s2<<"]";
		}
	}
	if(!bandera){
		cout<<"\n\nPresiona una Tecla para continuar . . .";		
		getch();
	}
	return bandera;
}

int main(){
	string letras = "qwertyuiopasdfghjklzxcvbnm";
	char palabra[11];
	bool bandera = true;
	int pos = 0;
	char usuario[11];
	
	//para la hora
	time_t now = time(NULL);
	tm *tim = localtime(&now);
	int segundos = 0;
	int minutos = 0;
	float promedio = 0;
	int errores = 0;
	
	while(bandera){
		errores = 0;
		promedio = 0;
		for(int i = 0; i < 10; i++){
			//llenar palabra
			system("cls");
			cout<<"\n\n\t\t - - - MECANOGRAFIA - - -\n\n\nCopia estas letras:\n\n";
			for(int j = 0; j < 10; j++){
				srand(time(NULL) + (10 * i) + j);
				pos = rand()%26;
				palabra[j] = letras[pos];
				cout<<palabra[j];
			}
			cout<<"\n";
			
			//pedir palabra
			
			while(!kbhit()){
				Sleep(100);
			}

			now = time(NULL);
			tim = localtime(&now);
			
			segundos = tim -> tm_sec;
			minutos = tim -> tm_min;
			
			cin.getline(usuario, 11, '\n');
			
			now = time(NULL);
			tim = localtime(&now);
			
			promedio += (tim -> tm_min - minutos) * 60 + (tim -> tm_sec - segundos);
			
			if(!compara(palabra,usuario,10))
				errores++;
		}
		//resultados
		cout<<"\n\nTuviste "<<10-errores<<" aciertos y "<<errores<<" errores\n";
		cout<<"El promedio de tiempo es de: "<<promedio/10<<endl;
		
		cout<<"\n\nIntentarlo otra vez? (s/n): ";
		if(getch() != 's') bandera = false;
	}
}

