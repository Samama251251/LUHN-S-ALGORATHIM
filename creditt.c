#include <cs50.h>
#include <stdio.h>

int main(void)
{
     long ccn;
     ccn = get_long ("Enter credit card number\n");
     long k = ccn;
     //the following code will count no of digits in credit card number
     int no_of_digits = 0;
     while(k>0){
          k = k/10;
          no_of_digits++;
          }
       // the above code will count no of digits in credit number
     int odd_last_digit;
     int even_last_digit;
     long reverse_even=0;
     long reverse_odd=0;
     long j=ccn;
     // the following code will seprate digits of credit card number present at odd places from numbers present in even places
     for(int i = 1; i <= no_of_digits; i++){
          if(i%2!= 0){
               odd_last_digit = j%10;
               reverse_odd=(reverse_odd*10)+odd_last_digit;
               }
          if(i%2==0){
               even_last_digit=j%10;
               reverse_even=(reverse_even*10)+(even_last_digit);
          }
          j=j/10;
 }
 //now we have seprated digits present at even places and at odd places
 long copy_reverse_odd=reverse_odd;
 long copy_reverse_even=reverse_even;
 int sum_reverse_odd=0;
 int last_reverse_odd;
 int last_reverse_even;
 int llast_reverse_even;
 int sum_reverse_even;
 while(copy_reverse_odd>0)
 {
     last_reverse_odd=copy_reverse_odd%10;
     sum_reverse_odd=(sum_reverse_odd)+last_reverse_odd;
     copy_reverse_odd=copy_reverse_odd/10;
 }
 while(copy_reverse_even>0)
 {
     last_reverse_even=(copy_reverse_even%10)*2;
     if(last_reverse_even>=10)
     {
          while(last_reverse_even>0)
          {
               llast_reverse_even=last_reverse_even%10;
               sum_reverse_even=sum_reverse_even+llast_reverse_even;
               last_reverse_even=last_reverse_even/10;

          }
     }
     else
     {

          sum_reverse_even=sum_reverse_even+last_reverse_even;
     }
     copy_reverse_even=copy_reverse_even/10;
}
     int checksum=sum_reverse_even+sum_reverse_odd;
     // finding the first number of credit card
     long duplicate_ccn=ccn;
     long first_digit;
     while(duplicate_ccn>0){
          first_digit=duplicate_ccn%10;
          duplicate_ccn=duplicate_ccn/10;
     }
     //finding the second number of credit card
     long copy_ccn=ccn;
     long second_digit;
     while(copy_ccn>10){
          second_digit=copy_ccn%10;
          copy_ccn=copy_ccn/10;
     }
     long first_two_numbers=(first_digit*10)+second_digit;
     if(checksum%10==0)
     {
        if(no_of_digits==15 && (first_two_numbers == 34 || first_two_numbers==37))
        {
          printf("AMEX\n");
        }
        else if(no_of_digits==16 && (first_two_numbers==51 || first_two_numbers==52 || first_two_numbers==53 || first_two_numbers==54 || first_two_numbers==55)){
          printf("MASTERCARD\n");
        }
        else if((no_of_digits==13 || no_of_digits==16) && first_digit==4)
        {
          printf("VISA\n");
        }
        else
        {
          printf("INVALID\n");
        }
     }
     else
     {
          printf("INVALID\n");
     }
}