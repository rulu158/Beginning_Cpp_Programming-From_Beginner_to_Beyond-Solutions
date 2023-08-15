// You do NOT have to write a main() function. The main() function is written by me
// behind the scenes to call your function and test your code.

int find_max_element(int* arr, int size) {
    //-- Write your code below this line 

    if (size < 1) {
        return -1;
    }

    int max_num {*arr};
    for (int i {}; i < size; ++i) {
        if (*(arr + i) > max_num) {
            max_num = *(arr + i);
        }
    }
    
    return max_num;

    //-- Write your code below this line 
}
