// C++ program to implement different operations
// on Binomial Heap

//#include<bits/stdc++.h>
//OJO: deglosé las librerías para que compilara
#include <iostream>
#include <list>

using namespace std;

// Estructura de Nodo
struct Node
{
	int data, degree; //Guarda dato y el grado de cada nodo
	Node *child, *sibling, *parent; //Punteros a hijo, hermano y padre
};

// Método para crear nodo con parámetro de dato
Node* newNode(int key)
{
	//Se inicializa con dato parámetro, grado 0 y punteros apuntando a NULL
	Node *temp = new Node;
	temp->data = key;
	temp->degree = 0;
	temp->child = temp->parent = temp->sibling = NULL;
	return temp;
}

// Método para hacer merge de dos "Binomial Trees" (b1 y b2)
Node* mergeBinomialTrees(Node *b1, Node *b2)
{
	// Valida, en función de la data, de que b1 es menor que b2
	if (b1->data > b2->data)
		swap(b1, b2);

	// El árbol mayor se hace hijo del árbol menor
	b2->parent = b1; // El padre de b2 queda como b1
	b2->sibling = b1->child; // El hermano de b2 queda apuntando al hijo de b1
	b1->child = b2; // El hijo de b1 queda apuntando a b2
	b1->degree++; // Se aumenta en 1 el grado almacenado en b1

	return b1;
}


// Función para unir dos "Binomial heaps" (l1 y l2)
list<Node*> unionBionomialHeap(list<Node*> l1, list<Node*> l2)
{
	// _new contendrá el nuevo heap unido
	// it y ot son iteradores para los heaps a unir
	list<Node*> _new;
	list<Node*>::iterator it = l1.begin();
	list<Node*>::iterator ot = l2.begin();
	while (it!=l1.end() && ot!=l2.end())
	{
		// Si el grado de l1 es menor o igual al grado de l2, guarda en el nuevo heap
		// el contenido del iterador de l1
		if((*it)->degree <= (*ot)->degree)
		{
			_new.push_back(*it);
			it++;
		}
		// Si el grado de l1 es mayor al grado de l2, guarda en el nuevo heap
		// el contenido del iterador de l2
		else
		{
			_new.push_back(*ot);
			ot++;
		}
	}

	// Si aún quedan elementos restantes en el "Binomial heap" l1,
	// guarda en el nuevo heap el contenido del iterador de l1
	while (it != l1.end())
	{
		_new.push_back(*it);
		it++;
	}

	// Si aún quedan elementos restantes en el "Binomial heap" l2,
	// guarda en el nuevo heap el contenido del iterador de l2
	while (ot!=l2.end())
	{
		_new.push_back(*ot);
		ot++;
	}

	return _new;
}

// Función de ajuste que reordena el heap para que esté en orden creciente según el grado,
// y ningún otro árbol binomial tengo el mismo grado
list<Node*> adjust(list<Node*> _heap)
{
	if (_heap.size() <= 1)
		return _heap;
	list<Node*> new_heap;
	list<Node*>::iterator it1,it2,it3;
	it1 = it2 = it3 = _heap.begin();

	if (_heap.size() == 2)
	{
		it2 = it1;
		it2++;
		it3 = _heap.end();
	}
	else
	{
		it2++;
		it3=it2;
		it3++;
	}
	
	while (it1 != _heap.end())
	{
		// Si solamente queda un elemento a se procesado
		if (it2 == _heap.end())
		it1++;

		// Si el grado del iterador it1 es menor que el de it2
		// El árbol apuntado por i1 y it2 no es posible entonces
		// avanza al siguiente en el heap
		else if ((*it1)->degree < (*it2)->degree)
		{
		it1++;
		it2++;
		if(it3!=_heap.end())
			it3++;
		}

		// Si los tres iteradores tienen el mismo grado
		// el grado de los tres consecutivos Binomial Tree será el mismo del heap
		else if (it3!=_heap.end() &&
			(*it1)->degree == (*it2)->degree &&
			(*it1)->degree == (*it3)->degree)
		{
		it1++;
		it2++;
		it3++;
		}

		// Si el grado grado de los iteradores it1 e it2 son iguales
		else if ((*it1)->degree == (*it2)->degree)
		{
			Node *temp;
			*it1 = mergeBinomialTrees(*it1,*it2);
			it2 = _heap.erase(it2);
			if(it3 != _heap.end())
				it3++;
		}
	}
	return _heap;
}

// Función para insertar un Binomial Tree en un Binomial heap
list<Node*> insertATreeInHeap(list<Node*> _heap,
			Node *tree)
{
	// Se crea un nuevo heap temporal (temp)
	list<Node*> temp;

	// Se inserta el Binomial Tree en el Heap temporal
	temp.push_back(tree);

	// Se llama al método de unión de Heaps para insertar el Binomial Tree en el Heap original
	temp = unionBionomialHeap(_heap,temp);

	return adjust(temp);
}

// Método para remover el elemento mínimo de un Binomial Heap
// Toma como entrada un Binomial Tree y retorna el Binomial Heap luego de haber
// removido la cabeza de ese árbol, es decir el elemento mínimo
list<Node*> removeMinFromTreeReturnBHeap(Node *tree)
{
	list<Node*> heap;
	Node *temp = tree->child;
	Node *lo;

	// Se hace un Binomial Heap a partir del Binomial Tree
	while (temp)
	{
		lo = temp;
		temp = temp->sibling;
		lo->sibling = NULL;
		heap.push_front(lo);
	}

	return heap;
}

// Se inserta la clave en el binomial heap
list<Node*> insert(list<Node*> _head, int key)
{
	Node *temp = newNode(key);
	return insertATreeInHeap(_head,temp);
}

// Función que retorna un puntero al nodo con valor mínimo en el Binomial Heap
Node* getMin(list<Node*> _heap)
{
	list<Node*>::iterator it = _heap.begin();
	Node *temp = *it;
	while (it != _heap.end())
	{
		if ((*it)->data < temp->data)
		temp = *it;
		it++;
	}

	return temp;
}

// Función para extraect el valor mínimo en el Heap
list<Node*> extractMin(list<Node*> _heap)
{
	list<Node*> new_heap,lo;
	Node *temp;

	temp = getMin(_heap); //Almacena el mínimo valor en el heap
	list<Node*>::iterator it;
	it = _heap.begin();
	while (it != _heap.end())
	{
		if (*it != temp)
		{
		// Inserta todos los Binomial Tree en el nuevo heap
		// salvo el binomial tree que tiene el elemento mínimo
		new_heap.push_back(*it);
		}
		it++;
	}
	lo = removeMinFromTreeReturnBHeap(temp);
	new_heap = unionBionomialHeap(new_heap,lo);
	new_heap = adjust(new_heap);
	
	return new_heap;
}

// Método para imprimir el Binomial Tree
void printTree(Node *h)
{
	while (h)
	{
		cout << h->data << " ";
		printTree(h->child);
		h = h->sibling;
	}
}

// Método para imprimir el Binomial Heap
void printHeap(list<Node*> _heap)
{
	//Recorre el heap con un iterador
	list<Node*> ::iterator it;
	it = _heap.begin();
	while (it != _heap.end())
	{
		printTree(*it);
		it++;
	}
}


// Bloque principal, main
int main()
{
	//int ch,key; //Al parecer no se usan
	list<Node*> _heap; //Heap principal

	// Inserta dada en el Heap
	_heap = insert(_heap,10);
	_heap = insert(_heap,20);
	_heap = insert(_heap,30);

	// Muestra el Heap luego de la inserción, para iniciar
	cout << "Heap elements after insertion:\n";
	printHeap(_heap);

	// Muestra el elemento mínimo del Heap
	Node *temp = getMin(_heap);
	cout << "\nMinimum element of heap "
		<< temp->data << "\n";

	// Elimina el elemento mínimo del Heap y luego muestra como quedó el Heap
	_heap = extractMin(_heap);
	cout << "Heap after deletion of minimum element\n";
	printHeap(_heap);

	return 0;
}
