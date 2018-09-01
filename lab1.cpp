//Jeremiah Kalmus
//Lab #1

#include <iostream>

using namespace std;

int main()

{
  const int LOW = 10;
  const int HIGH = 100;
  const int MAX = 13;
  int num;
  int counter = 0;
  int oddNum[MAX]; 
   
  cout << "Hello this is lab 1" << endl;
  cout << "Enter an ODD number between 10 and 100 ";
  cin >> num;
  
  while(counter < MAX)
    {
      cout << "Enter an ODD number between 10 and 100 ";
      cin >> num;
      
      if((num >= LOW) && (num <= HIGH) &&  (num % 2 != 0))
        {
          oddNum[counter] = num;
        }
      else
        {
          cout << "Sorry, that is not an ODD value between 10 and 100" << endl;
        }
      
      counter++;
    }

  for(int i=0;i<MAX;i++)
    {
      cout << oddNum[i] << endl;
    }
  cout << endl << "End of Lab1 Pgm" << endl;
  return 0;

}
