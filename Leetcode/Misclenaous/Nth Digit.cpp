/*  So we've to find the Nth digit in sequence, which can be achieved in 3 steps
    1. Calculate how many digits the number will have.
    2. Calculate the actual number
    3. Return the target digit we wanted from the above number

    https://leetcode.com/problems/nth-digit/discuss/488294/C%2B%2B-O(lgN)-Time-O(1)-Space
    TC: O(log10 N)

    Input: 250

        There are 9 one-digit numbers (1 ~ 9) which have 1 * 9 = 9 digits in total.
        There are 90 two-digit numbers (10 ~ 99) which have 2 * 90 = 180 digits in total.
        There are 900 three-digit numbers (100 ~ 999) which have 3 * 900 = 2700 digits in total.
        There are 9000 four-digit numbers (1000 ~ 9999) which have 4 * 9000 = 36000 digits in total.

        After step 1, you will find that the 250th digit must belong to a 3-digit number, n = 250 - 9 - 90 * 2 = 61, and digits = 3.

        In step 2, we will find the target number, which named as number in my code. From step 1, the n becomes to 61, which means "the 61st digit in 3-digit number is the digit we are looking for." Easily, we know the 61st digit in 3-digit number belongs to number = 100 + 61 / 3 = 100 + 20 = 120. index is the index of the target digit in number. If index equals to 0, it means the target digit is the last digit of number.

        Step 3, from step 2, we know index = n % digits = 61 % 3 = 1, which means the target digit is the 1st digit in number. Then, return 1.

        Ex: n = 361 ans = 1

 */

class Solution {
public:
    int findNthDigit(int n) 
    {
        // calculate how many digits the number will have
        long base = 9, digit = 1;
        while(n-base*digit>0)
        {
            n -= base*digit;
            base *= 10;
            digit++;
        }

        int index = n%digit;     // find the digit within the number K 
        if(index == 0)          // if index = 0, then required digit is last digit of number
            index = digit;

        // calculate the required number
        long number = 1;
        for(int i=1; i<digit; i++)
            number *= 10;

        number += (index==digit)? n/digit-1 : n/digit;

        // fReturn the target digit we wanted from the above number
        for(int i = index; i<digit; i++)    // divide all the digits till we reach the index
            number /= 10;

        return number%10;
    }
};

