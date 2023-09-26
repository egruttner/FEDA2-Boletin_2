#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class MinHeap {
private:
    vector<int> heap;

public:
    // Constructor por defecto
    MinHeap() {}

    // Insertar un elemento en el heap
    void insert(int value) {
        heap.push_back(value);
        push_heap(heap.begin(), heap.end(), greater<int>());
    }

    // Eliminar el elemento mínimo (raíz) del heap
    void deleteMin() {
        if (!isEmpty()) {
            pop_heap(heap.begin(), heap.end(), greater<int>());
            heap.pop_back();
        }
    }

    // Unir dos heaps
    void merge(MinHeap& otherHeap) {
        heap.insert(heap.end(), otherHeap.heap.begin(), otherHeap.heap.end());
        make_heap(heap.begin(), heap.end(), greater<int>());
    }

    // Verificar si el heap está vacío
    bool isEmpty() const {
        return heap.empty();
    }

    // Obtener el elemento mínimo (raíz) del heap
    int getMin() const {
        if (!isEmpty()) {
            return heap.front();
        } else {
            throw runtime_error("El heap está vacío.");
        }
    }

    // Imprimir el heap
    void print() const {
        for (int value : heap) {
            cout << value << " ";
        }
        cout << endl;
    }
};

int main() {
    MinHeap minHeap;
    
    minHeap.insert(3);
    minHeap.insert(5);
    minHeap.insert(2);
    minHeap.insert(9);

    cout << "Min Heap: ";
    minHeap.print();

    minHeap.deleteMin();
    cout << "Después de eliminar el mínimo: ";
    minHeap.print();

    MinHeap anotherHeap;
    anotherHeap.insert(1);
    anotherHeap.insert(7);

    cout << "Otro Min Heap: ";
    anotherHeap.print();

    minHeap.merge(anotherHeap);
    cout << "Después de unir los heaps: ";
    minHeap.print();

    return 0;
}
