// You do NOT have to write a main() function. The main() function is written by me
// behind the scenes to call your function and test your code.

void reverse_array(int* arr, int size) {
    //-- Write your code below this line 
    
    int temp_array[size];
    
    for (int i {size - 1}; i >= 0; --i) {
        temp_array[size - 1 - i] = arr[i];
    }
    
    for (int i {}; i < size; i++) {
        arr[i] = temp_array[i];
    }
    
    //-- Write your code above this line
}


