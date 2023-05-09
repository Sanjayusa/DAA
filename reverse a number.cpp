#include <stdio.h>;
//Recursive function to
//reverse digits of number
int reversDigits(int num)
{
    static int rev_num = 0;
    static int base_pos = 1;
    if(num > 0)
    {
        reversDigits(num/10);
        rev_num += (num%10)*base_pos;
        base_pos *= 10;
    }
    return rev_num;
}
int main()
{
    int number, reversed = 0;
    //Input a number from user
    printf("Enter any number = ");
    scanf("%d", &number);
    reversed = reversDigits(number);
    printf("Reverse of no. is %d", reversed);
    return 0;
}
