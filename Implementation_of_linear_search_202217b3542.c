#include <stdio.h>   
int
linearSearch (int arr[], int n, int target) 
 { int i;
  
for (i = 0; i < n; i++)
	
	{
	  if (arr[i] == target)
		
		{
		  
return i;			// Element found at index i   
		}
	
}
  
return -1;					// Element not found   
}


 
int
main ()
{
  
int arr[] = { 10, 2, 8, 5, 17 };
  int n = sizeof (arr) / sizeof (arr[0]);
  int target = 5;
  
int result = linearSearch (arr, n, target);
  if (result == -1)
	
	{
	  printf ("Element not found in the array.\n");
	
}
  else
	
	{
	  printf ("Element found at index: %d\n", result);
	
}
  return 0;

}


