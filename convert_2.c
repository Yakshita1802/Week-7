#include<stdio.h>
#include<stdlib.h>
//Program to convert a 32-bit Decimal numbers to Binary
// 1) No globals are allowed.
// 2) Your code must properly manage memory. All the dynamically allocated memory must be freed after use and there should be no memory accesses out of bound.
// 3) The output of binary value follows the format of grouping every four bits together with a space between groups. for instance,
// The Binary Notation of -1 is     0b1111 1111 1111 1111 1111 1111 1111 1111
// Please check sample outputs for more details 
// 4) Do not change the signature of convert_2, or your task receives zero

char* convert_2(int dec)
{
	//TODO: your implementation

  int _Size = 32;  // as per the required I used 32-bit decimal
  char *_blocks;
  _blocks = (char*)malloc((_Size + 9)*sizeof(char));  // I used 9 extra blocks for '0b' and space between groups 
  _blocks[0] = '0';  // first blocks will be '0'
  _blocks[1] = 'b';  // second blocks will be 'b'
  int _index = _Size + 8; // index of last block
  int _chunks = 1;  

  while(_index >= 2) // used while loop
  {
    if(_chunks == 0 ) 
    {    
    	_blocks[_index] = 	' '; // inserts a space if a 4 bit chunk is complete
	  }
		else 
    {
			// uses the and operator to determine whether the LSB is 1 or 0.
	  if(dec&1) 
    {  
			_blocks[_index] = 	'1';
		}
		else 
    {
			_blocks[_index] = 	'0';
		}
	        // The decimal is right-shifted by 1
	        // When it is 1101, it is 110
	  dec >>= 1;	
		} 
	  _index--;  // Decrement by 1
	  _chunks = (_chunks + 1)%5;  // increaments chunks 0 to 4 first start with 1
    }
    return _blocks;  
}
int main() {
	int n;
	char * bin;
	printf("Enter the Decimal Number\n");
	scanf("%d",&n);
	bin = convert_2(n);
	printf("The Binary Notation of %d is\t %s\n", n, bin);
	//TODO: do we need to release the memory of bin? who is responsible for releasing malloc-ed memory? who is using the memory for the last time?
return 0;
	// #who-used-up-last-inch-toilet-paper-replenish-it
}