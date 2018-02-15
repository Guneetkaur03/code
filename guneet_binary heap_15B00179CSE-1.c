#include<stdio.h>
#include<conio.h>
#include<malloc.h>
struct node
{
	int val;
	struct node *left,*right;	
};
int heapSize = 0;
struct node *top = NULL;
struct node *insert(struct node *,int data, int heapSize);
struct node *extract_min(struct node *,int heapSize);
void display(struct node *, int heapSize);
void isempty(struct node *);
struct node * heapsort(struct node *, int heapSize);
struct node *heapify(struct node *, int heapSize, int i);
int main()
{
	int option,number,value,i;
	do
	{
		printf("\n Choose one of options \n 1. Insert \n 2. Extract Min \n 3.Is empty\n 4.Exit\n what would you like to do:");
		scanf("%d",&option);
		switch(option)
		{
			case 1:
				printf("\n Enter the number of elements you want to enter: ");
				scanf("%d",&number);
				printf("\n enter the elements: ");
				for(i=0;i<number;i++)
				{
					scanf("%d",&value);
					heapSize++;
					top = insert(top,value,heapSize);
				}
				heapsort(top,heapSize);
				printf("\nSorted Heap : \n");
				display(top,heapSize);
				break;
			case 2:
				top = extract_min(top,heapSize);
				heapSize--;
				display(top,heapSize);
				break;	
			case 3:
				isempty(top);
				break;
		}
	}while(option !=4);
	return 0;
}
struct node *insert(struct node* top,int data, int heapSize)
{
	int j;  
    int i = 0;
	struct node *new_node, *ptr;
	ptr = top;
	int binaryNum[1000];
	new_node = (struct node *)malloc(sizeof(struct node));
	new_node->val = data;
	if(top == NULL)
	{
		top = new_node;
		new_node->left = NULL;
		new_node->right = NULL;
				
	}
	else
	{
		printf("\n heapsize is %d",heapSize);
		while (heapSize > 0) {
       	 	binaryNum[i] = heapSize % 2;
       	 	heapSize = heapSize / 2;
        	i++;
   		}
   		printf("\n array size is %d",i);
   		int temp,start=0,end=i;
    	while (start < (end-1))
    	{
        	temp = binaryNum[start];   
        	binaryNum[start] = binaryNum[end-1];
        	binaryNum[end-1] = temp;
        	start++;
        	end--;
    	}   
    	printf("\n Prrinting array :");
		for(j =0;j<i;j++)
		{
			printf("%d ",binaryNum[j]);
		}
		printf("\n");
		for(j=1;j<i;j++)
		{
			if(binaryNum[j] == 0 )
			{
				if(ptr->left == NULL)
				{
					ptr->left = new_node;
					new_node->left = NULL;
					new_node->right = NULL;
					printf("\n inserting left %d\n",ptr->left->val);
				}
				else
				{
						ptr= ptr->left;	
				}
				
			}
			if(binaryNum[j] ==1)
			{
				if(ptr->right == NULL)
				{
					ptr->right = new_node;
					new_node->left = NULL;
					new_node->right = NULL;
					printf("\n inserting right %d\n",ptr->right->val);
				}
			
				else
				{
					ptr= ptr->right;
				}	
			}
		}
	}
	return top;
}
void display(struct node * top, int heapSize)
{
//	printf("\n %d heap size\n",heapSize);
	printf("\n %d ",top->val);	
	int j;
	for(j=2;j<=heapSize;j++)
	{
		int i=0,k;
		int size = j;
		int arr[1000];
		while (size > 0) {
       	 	arr[i] = size % 2;
       	 	size = size / 2;
        	i++;
   	}
   		int temp,start=0,end=i;
    	while (start < (end-1))
    	{
        	temp = arr[start];   
        	arr[start] = arr[end-1];
        	arr[end-1] = temp;
        	start++;
        	end--;
    	}  
		struct node *ptr = top;
    	for(k=1;k<i;k++)
		{
			if(arr[k] == 0 )
			{
				ptr = ptr->left;
			}
			else if(arr[k] = 1)
			{
				ptr= ptr->right;
			}
		}	
		printf("%d ",ptr->val);	
	}
}
void isempty(struct node * top)
{
	if(top == NULL)
	{
		printf("\n Heap is empty \n");
	}
	else
	{
		printf("\n Heap is not empty \n");
	}
}
struct node * heapsort(struct node *top, int heapSize)
{
	int i =0;
  for(i = heapSize/2;i>=1;i--)
	{
		heapify(top,heapSize,i);
	}
}
struct node *heapify(struct node *top, int heapSize, int i)
{
	int s = i;
	int j =0,k=0;
	int l = 2*i;
	int r = 2*i+1;
	struct node *ptr;
	struct node *small;
	ptr = top;
	int arrb[1000];
	while (i > 0) {
       	 	arrb[j] = i % 2;
       	 	i = i / 2;
        	j++;
   		}
   		int temp,start=0,end=j;
    	while (start < (end-1))
    	{
        	temp = arrb[start];   
        	arrb[start] = arrb[end-1];
        	arrb[end-1] = temp;
        	start++;
        	end--;
    	}
		for(k=1;k<j;k++)
		{
			if(arrb[k] == 0 )
			{
					ptr = ptr->left;	
			}
			if(arrb[k] ==1)
			{
					ptr = ptr->right;	
			}
		}
		small = ptr;
		if(l<=heapSize && ptr->left->val < ptr->val)
		{
			small = ptr->left;
			s = l;
		}
		if(r <=heapSize && ptr->right->val < small->val)
		{
			small = ptr->right;
			s = r;
		}
		if(small != ptr)
		{
			int temp = small->val;
			small->val = ptr->val;
			ptr->val = temp;
			heapify(top,heapSize,s);
		}
	return top;
}
struct node *extract_min(struct node *top, int heapSize)
{
	struct node *ptr =top;
	struct node *root = top;
	int arrb[1000];
	int k=0,j=0;
	int i =  heapSize;
	while (i > 0) {
		arrb[j] = i % 2;
      	i = i / 2;
      	j++;
   	}
   		int temp,start=0,end=j;
    	while (start < (end-1))
    	{
        	temp = arrb[start];   
        	arrb[start] = arrb[end-1];
        	arrb[end-1] = temp;
        	start++;
        	end--;
    	}   
		for(k=1;k<j;k++)
		{
			if(arrb[k] == 0 )
			{
				ptr= ptr->left;		
			}
			if(arrb[k] ==1)
			{
				ptr= ptr->right;
			}	
		}
		temp  = ptr->val;
		ptr->val = root->val;
		root->val =temp;
		free(ptr);
		heapSize = heapSize-1;
		heapify(top,heapSize,1);
}
