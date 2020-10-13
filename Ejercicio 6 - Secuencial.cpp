#include <iostream>
#include <stdlib.h>
using namespace std;
class Cola{
	private:
		int *items;
		int max;
		int pr;
		int ul;
		int cant;
	
	public:
		Cola(int max = 10);
		bool vacia();
		int insertar(int dat);
		int suprimir();
		void recorrer();
		~Cola();
};

Cola::Cola(int xmax){
	pr = 0;
	ul = 0;
	cant = 0;
	max = xmax;
	items = new int[max];
}


bool Cola::vacia(){
	return (cant == 0);
}

int Cola::insertar(int dat){
	int aux;
	if (cant < max){
		items[ul] = dat;
		ul = (ul + 1) % max;
		cant++;
		return (dat);
	}
	else return (0);
}

int Cola::suprimir(){
	int x;
	if (vacia()){
		printf("%s", "Pila vacia");
		return (0);
	}
	else{
		x = items[pr];
		pr = (pr + 1) % max;
		cant--;
		return (x);
	}
}

void Cola::recorrer(){
	int i,j;
	if (!vacia()){
		i = pr;
		j = 0;
		for(i; j<cant; i = (i+1)%max, j++){
			cout<<items[i]<<endl;
		}
	}
	else{
		puts("La cola esta vacia");
	}
}

Cola::~Cola(){
	delete[]items;
}

void test(Cola &unaCola){
	unaCola.insertar(10);
	unaCola.insertar(20);
	unaCola.insertar(30);
	unaCola.insertar(40);
	printf("\nElementos de la cola\n");
	printf("---------------------\n");
	unaCola.recorrer();
	printf("---------------------\n");
	
	printf("\n%d Eliminado\n", unaCola.suprimir());
	printf("%d Eliminado\n", unaCola.suprimir());
	
	printf("\nElementos de la cola\n");
	printf("---------------------\n");
	unaCola.recorrer();
	printf("---------------------\n");
	
	unaCola.insertar(50);
	unaCola.insertar(60);
	printf("\nElementos de la cola\n");
	printf("---------------------\n");
	unaCola.recorrer();
	printf("---------------------\n");
	
	printf("\n%d Eliminado\n", unaCola.suprimir());
	printf("%d Eliminado\n", unaCola.suprimir());
	
	printf("\nElementos de la cola\n");
	printf("---------------------\n");
	unaCola.recorrer();
	printf("---------------------\n");
	
	printf("\n%d Eliminado\n", unaCola.suprimir());
	printf("%d Eliminado\n", unaCola.suprimir());
	
	printf("\nElementos de la cola\n");
	printf("---------------------\n");
	unaCola.recorrer();
	printf("---------------------\n");
}

int main(){
	Cola unaCola(4);
	test(unaCola);
}
