#include <stdio.h>

void
selectionSort (int arr[], int n)
{
  
for (int i = 0; i < n - 1; i++)
	{
	  
int minIdx = i;
	  
for (int j = i + 1; j < n; j++)
		{
		  
if (arr[j] < arr[minIdx])
			{
			  
minIdx = j;
			
}
		
}
	  
		// Swap arr[minIdx] and arr[i]
	  int temp = arr[minIdx];
	  
arr[minIdx] = arr[i];
	  
arr[i] = temp;

} 
} 
 
int

main ()
{
  
int arr[] = { 64, 25, 12, 22, 11 };
  
int n = sizeof (arr) / sizeof (arr[0]);
  
 
printf ("Original array: ");
  
for (int i = 0; i < n; i++)
	{
	  
printf ("%d ", arr[i]);
	
} 
printf ("\n");
  
 
selectionSort (arr, n);
  
 
printf ("Sorted array: ");
  
for (int i = 0; i < n; i++)
	{
	  
printf ("%d ", arr[i]);
	
} 
printf ("\n");
  
 
return 0;

}
