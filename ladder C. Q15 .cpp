/*                                                      A. Lucky sum of digits

Petya loves lucky numbers. We all know that lucky numbers are the positive integers whose decimal representations contain only the lucky digits 4 and 7. For example, numbers 47, 744, 4 are lucky and 5, 17, 467 are not.
Petya wonders eagerly what minimum lucky number has the sum of digits equal to n. Help him cope with the task.

INPUT
The single line contains an integer n (1 ≤ n ≤ 106) — the sum of digits of the required lucky number.

OUTPUT
Print on the single line the result — the minimum lucky number, whose sum of digits equals n. If such number does not exist, print -1

I/P -> 11
0/P -> 47

I/P -> 10
O/P -> -1

*/


/*
     eg -> n= 11
           string ans = " ";
           check if n is divisible by 7 or not.
           No it is not then, divide it by 4 and subtract it by 4
           n = 11-4 = 7
           ans = 4
           
           Now n is divisible by 7
           
           n=7-7=0
           ans =47

*/



#include <iostream>
using namespace std;

int main() {
	
	int n;
	cin>>n;
	string s= "";
	
	while(n>0 and n%7!=0) n-=4, s.push_back('4');
	while(n>0 and n%7==0) n-=7, s.push_back('7');
	
	if(n==0) cout<<s;
	else cout<<-1;
	
	return 0;
}
