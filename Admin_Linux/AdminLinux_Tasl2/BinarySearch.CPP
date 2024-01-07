#include<iostream.h>
#include<conio.h>
#include<string.h>



#define arrlength	5
#define stringsnum  5
#define stringslen  20



////////////////////////////////////////////////////////////////////

class algorithms
{

  public:

		

		static int binarysearch(int * data,int size,int key);

		static int rbinarysearch(int * data,int start,int end,int key);

		static int binarysearch_string(char  data[][10], int size , char * str);

	




};//algorithms class

////////////////////////////////////////////////////////////////////
int algorithms::binarysearch(int * data,int size,int key)
		{
			int i,start=0,end,mid;

			end = size - 1;

			mid = (start + end)/2;

			while(end >= start)
				{
					mid = (start + end )/2;

					if(data[mid] > key)

							 end = mid-1;

					else if(data[mid] < key)

							 start = mid +1;

					else

							return mid;

				}//while


			 return -1;
		}//binary search


///////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////

int algorithms::binarysearch_string(char  data[][10],int size  , char* str)
		{
			int i,start=0,end,mid,compared;

			end = size - 1;

			mid = (start + end)/2;

			while(end >= start)
				{
					mid = (start + end )/2;
					compared = strcmp(data[mid] , str);


					if(compared==0)
								  return mid;


					else if(compared<0)

							 start = mid +1;

					else

							end = mid-1;

				}//while


			 return -1;
		}//binary search


///////////////////////////////////////////////////////////////////



//recusion binary search
int algorithms::rbinarysearch(int * data,int start,int end,int key)
		{
				int mid;

				if(start <= end)
					{
						mid = (start + end)/2;

						if(data[mid] > key)
								return algorithms::rbinarysearch(data ,start ,mid-1,key);

						else if (data[mid] < key)
								return algorithms::rbinarysearch(data ,mid+1, end,key);


						else
								return mid;

					}//if

					return -1;

		}//recursion binary search

//////////////////////////////////////////////////////////////////

int main(void)
{


//////////////////////////////////////////////////////////////////////////

	//sequential search in array of int

	int i , arr[arrlength] , foundindex ,foundindex1, key;
	char strings[5][10] = {"ab","cd","ef","gh","mn"};
	char str1[]="mn";




	clrscr();

	cout<<" hello this is binary search "<<endl;

	for(i=0 ; i<arrlength ;i++)
		 {
			cout<<"please enter elemnt  "<<i+1<<"\t";
			cin>>arr[i];
		 }//for

	cout<<" please enter the number you want to search about  "<<endl;
	cin>>key;

	foundindex = algorithms::binarysearch(arr,arrlength,key);

	if(foundindex > -1)
				cout<<"\n the number found in index : "<<foundindex<<endl;

	else
			cout<<"\n the number you entered not found "<<endl;


	getch();
////////////////////////////////////////////////////////////////////////////
//binary search with strings

	foundindex = algorithms::binarysearch_string(strings,arrlength,str1);

	if(foundindex > -1)
				cout<<"\n string found in index : "<<foundindex<<endl;

	else
				cout<<"\n string not found "<<endl;



/////////////////////////////////////////////////////////////////////
getch();

return 0;

}//main