int calculate_sum() {
    //---- WRITE YOUR CODE BELOW THIS LINE
    
    int sum {};
    for (int i {1}; i <= 15; ++i) {
        if (i % 2 != 0) {
            sum += i;
        }
    }
    
    //---- WRITE YOUR CODE ABOVE THIS LINE
    //---- DO NOT MODIFY THE CODE BELOW
    return sum;
}
