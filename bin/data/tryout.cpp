#include <bits/stdc++.h>
using namespace std;

int getOddPairsCount(int arr[], int n) {
   int count = 0;
   for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
         if ((arr[i] | arr[j]) % 2 != 0) {
            count++;
         }
      }
   }
   return count;

}

char printFormat(){
  char buffer [50];
  int n, a=5, b=3;
  n = sprintf (buffer, "%d plus %d is %d", a, b, a+b);
  return n;
}

int bigger(int x, int y){
   int sed = x > y;
   return sed?x:y;
}

int smaller(int x, int y){
   int sed = x < y;
   return sed?x:y;
}

int pointerfointer(int i){
   int* j = &i;   //create pointer (j) * -> get memlocation &(i)
   int k = *j;    //get val of pointer by *pointer(j)
   return k;
}

int cast(float l){
   return (int) l;
}

auto lop(int x, int y){
   bool sed = x == y;
   if(sed){
      return string("Even");
   }
    //return string("Odd");
}

void shifting( std::ostream& dest, uint32_t value )
{
    dest.put( (value >> 24) & 0xFF );
    dest.put( (value >> 16) & 0xFF );
    dest.put( (value >>  8) & 0xFF );
    dest.put( (value      ) & 0xFF );
}

int main() {
   int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

   int n = 10;
   cout << getOddPairsCount(arr, n) << endl;
   cout << bigger(20, 80) << endl;
   cout << smaller(20, 80) << endl;
   cout << pointerfointer(20) << endl;
   cout << cast(0.005) << endl;
   cout << lop(1, 1) << endl;
   cout << printf(%i, int32_t(2<<32) << endl);
   float f = 0.00;
   
   //float* j = &f;
   //shifting(&f, 0.005);



   return 0;
}