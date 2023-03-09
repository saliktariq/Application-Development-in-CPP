#include <iostream>
#define MAX_SIZE  100
using namespace std;

class MinHeap{
    private:
        int array[MAX_SIZE];
        int size;

    public:
        MinHeap(){
            size = 0;
        }

        int get_parent(int i){
            return (i-1)/2; //parent is at (i-1) / 2 not at i/2
        }

        void insert(int val){
            if(size >= MAX_SIZE){
                cout<<"\nHeap is full! Unable to insert\n";
                return;
            }

            array[size++] = val;

            for(int i = size-1; i > 0 && array[get_parent(i)] > array[i]; i = get_parent(i)){
                swap(array[get_parent(i)], array[i]);
            }
        }

        void print(){
            for(int i = 0; i < size; i++){
                cout << array[i] << " ";
            }
            cout << endl;
        }

        void delete_element(int val){
            int pos;
            for(pos = 0; pos < size; pos++){
                if(array[pos] == val){
                    break;
                }
            }
            if(pos == size){
                cout << "\nThe element to be deleted is not in the array\n";
                return;
            }

            /* otherwise replacing the element to be deleted with the last element 
            of the array to maintain binary tree */
            array[pos] = array[size-1];

            // reducing the size of the array
            size--;

            // finding the parent of element which we just deleted
            int parent = get_parent(pos);

            // swap element at deleted position with the parent which is larger than deleted position
            while(pos >= 0 && array[pos] < array[parent]){
                swap(array[pos], array[parent]);
                pos = parent; // update the position of deleted index to keep checking the full array
                parent = get_parent(pos); // fetch parent at updated position
            }

            // fix the heap property by swapping down the element at the deleted position
            int left_child = pos * 2 + 1;
            int right_child = pos * 2 + 2;
            while(left_child < size){
                int toddler = left_child;
                if(right_child < size && array[right_child] < array[left_child]){ // in case right child is smaller
                    toddler = right_child;
                }
                if(array[pos] > array[toddler]){
                    swap(array[pos], array[toddler]);
                    pos = toddler;
                    left_child = pos * 2 + 1;
                    right_child = pos * 2 + 2;
                }
                else {
                    break; // everything is in order

					}
					
				}
			}
		
	
};

int main(){
    MinHeap heap;
    int choice, val;

    do {
cout << "\n+-----------------------+" << endl;
cout << "¦       Menu            ¦" << endl;
cout << "¦-----------------------¦" << endl;
cout << "¦ 1. Insert element     ¦" << endl;
cout << "¦ 2. Delete element     ¦" << endl;
cout << "¦ 3. Print heap         ¦" << endl;
cout << "¦ 4. Exit               ¦" << endl;
cout << "+-----------------------+" << endl;
cout << "Enter your choice: ";
cin >> choice;

        switch(choice){
            case 1:
                cout << "Enter the element to be inserted: ";
                cin >> val;
                heap.insert(val);
                break;
            case 2:
                cout << "Enter the element to be deleted: ";
                cin >> val;
                heap.delete_element(val);
                break;
            case 3:
                heap.print();
                break;
            case 4:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice! Please enter a valid choice." << endl;
        }

    } while (choice != 4);

    return 0;
}

