#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct person {
    int id;
    char *name;
    int age;
    int height;
    int weight;
};

void swapPersons(person &a, person &b) {
    person temp = a;
    a = b;
    b = temp;
}

class Heap {
private:
    person *heapArray;
    int heapSize;
    int capacity;
    bool isMaxHeap;

public:
    Heap(int capacity, bool isMaxHeap) : capacity(capacity), heapSize(0), isMaxHeap(isMaxHeap) {
        heapArray = new person[capacity];
    }

    int parent(int i) { return (i - 1) / 2; }
    int leftChild(int i) { return 2 * i + 1; }
    int rightChild(int i) { return 2 * i + 2; }

    void heapify(int i) {
        int l = leftChild(i);
        int r = rightChild(i);
        int selected = i;

        if (l < heapSize && (isMaxHeap ? heapArray[l].weight > heapArray[selected].weight : heapArray[l].age < heapArray[selected].age))
            selected = l;

        if (r < heapSize && (isMaxHeap ? heapArray[r].weight > heapArray[selected].weight : heapArray[r].age < heapArray[selected].age))
            selected = r;

        if (selected != i) {
            swapPersons(heapArray[i], heapArray[selected]);
            heapify(selected);
        }
    }

    void insert(person p) {
        if (heapSize == capacity) {
            cout << "Heap is full, cannot insert more elements." << endl;
            return;
        }

        heapArray[heapSize] = p;
        int i = heapSize;

        while (i > 0 && (isMaxHeap ? heapArray[i].weight > heapArray[parent(i)].weight : heapArray[i].age < heapArray[parent(i)].age)) {
            swapPersons(heapArray[i], heapArray[parent(i)]);
            i = parent(i);
        }

        heapSize++;
    }

    person extractRoot() {
        if (heapSize <= 0) {
            cout << "Heap is empty." << endl;
            person emptyPerson = {0, nullptr, 0, 0, 0};
            return emptyPerson;
        }

        person root = heapArray[0];
        heapArray[0] = heapArray[heapSize - 1];
        heapSize--;

        heapify(0);

        return root;
    }

    person peekRoot() {
        if (heapSize <= 0) {
            cout << "Heap is empty." << endl;
            person emptyPerson = {0, nullptr, 0, 0, 0};
            return emptyPerson;
        }

        return heapArray[0];
    }

    bool isEmpty() {
        return heapSize == 0;
    }

    ~Heap() {
        delete[] heapArray;
    }
};

void readPersonsFromFile(const char *filename, person *&personsArray, int &n) {
    ifstream inputFile(filename);

    if (!inputFile) {
        cerr << "Error opening file: " << filename << endl;
        exit(1);
    }

    inputFile >> n;
    personsArray = new person[n];

    for (int i = 0; i < n; i++) {
        inputFile >> personsArray[i].id;
        char name[100];
        inputFile >> name;
        personsArray[i].name = new char[strlen(name) + 1];
        strcpy(personsArray[i].name, name);
        inputFile >> personsArray[i].age >> personsArray[i].height >> personsArray[i].weight;
    }

    inputFile.close();
}

void deleteAllPersons(person *personsArray, int n) {
    for (int i = 0; i < n; i++) {
        delete[] personsArray[i].name;
    }
    delete[] personsArray;
}

int main() {
    int choice, n;
    person *personsArray = nullptr;
    Heap *heapAge = nullptr;
    Heap *heapWeight = nullptr;

    cout << "MAIN MENU (HEAP)" << endl;
    cout << "1. Read Data" << endl;
    cout << "2. Create a Min-heap based on the age" << endl;
    cout << "3. Create a Max-heap based on the weight" << endl;
    cout << "4. Display weight of the youngest person" << endl;
    cout << "5. Insert a new person into the Min-heap" << endl;
    cout << "6. Delete the oldest person" << endl;
    cout << "7. Exit" << endl;

    do {
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                readPersonsFromFile("input.txt", personsArray, n);
                cout << "Data loaded for " << n << " persons." << endl;
                break;
            case 2:
                delete heapAge;
                heapAge = new Heap(n, false);

                for (int i = 0; i < n; i++) {
                    heapAge->insert(personsArray[i]);
                }

                cout << "Min-heap based on age created." << endl;
                break;
            case 3:
                delete heapWeight;
                heapWeight = new Heap(n, true);

                for (int i = 0; i < n; i++) {
                    heapWeight->insert(personsArray[i]);
                }

                cout << "Max-heap based on weight created." << endl;
                break;
            case 4:
                if (heapAge) {
                    cout << "Weight of the youngest person: " << heapAge->peekRoot().weight << endl;
                } else {
                    cout << "Min-heap based on age is not yet created." << endl;
                }
                break;
            case 5:
                if (heapAge) {
                    person newPerson;
                    cout << "Enter new person's id: ";
                    cin >> newPerson.id;
                    cout << "Enter new person's name: ";
                    newPerson.name = new char[100];
                    cin.ignore();
                    cin.getline(newPerson.name, 100);
                    cout << "Enter new person's age: ";
                    cin >> newPerson.age;
                    cout << "Enter new person's height: ";
                    cin >> newPerson.height;
                    cout << "Enter new person's weight: ";
                    cin >> newPerson.weight;

                    heapAge->insert(newPerson);
                    cout << "New person inserted into Min-heap based on age." << endl;
                } else {
                    cout << "Min-heap based on age is not yet created." << endl;
                }
                break;
            case 6:
                if (heapAge) {
                    person oldest = heapAge->extractRoot();
                    cout << "Oldest person deleted: " << oldest.name << endl;
                    delete[] oldest.name;
                } else {
                    cout << "Min-heap based on age is not yet created." << endl;
                }
                break;
            case 7:
                // Cleanup and exit
                deleteAllPersons(personsArray, n);
                delete heapAge;
                delete heapWeight;
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
                break;
        }

    } while (choice != 7);

    return 0;
}


