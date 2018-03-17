// C++ program to find minimum time to finish tasks
// such that no two consecutive tasks are skipped.
#include <bits/stdc++.h>
using namespace std;

// arr[] represents time taken by n given tasks
void minTime(int arr[], int n)
{
	// Corner Cases
	if (n <= 0)
		return;

	// Initialize value for the case when there
	// is only one task in task list.
	int incl = arr[0]; // First task is included
	int excl = 0;	 // First task is exluded
    int *exar = new int[n];
    exar[0] = -1;
    int *inar = new int[n];
    inar[0] = 0;
    inar[1] = -1;
	// Process remaining n-1 tasks
	for (int i=1; i<n; i++)
	{
    	// Time taken if current task is included
    	// There are two possibilities
    	// (a) Previous task is also included
    	// (b) Previous task is not included
    	int *intemp = inar, *extemp = exar;
    	int incl_new = arr[i] + min(excl, incl);
        if (incl_new == arr[i] + incl){
            inar = new int[n];
            exar = new int[n];
            int p = 0;
            while(intemp[p]!=-1){
                inar[p] = intemp[p];
                p++;
            }
            inar[p] = i;
            inar[p+1] = -1;
        }
        else{
            inar = new int[n];
            exar = new int[n];
            int p = 0;
            while(extemp[p]!=-1){
                inar[p] = extemp[p];
                p++;
            }
            inar[p] = i;
            inar[p+1] = -1;
        }
        int p=0;
        while(intemp[p]!=-1){
            exar[p] = intemp[p];
            p++;
        }
        exar[p] = intemp[p];
        exar[p+1] = -1;
        delete intemp, extemp;
    	// Time taken when current task is not
    	// included. There is only one possibility
    	// that previous task is also included.
    	int excl_new = incl;

    	// Update incl and excl for next iteration
    	incl = incl_new;
    	excl = excl_new;
    	cout<<incl<<" "<<excl<<endl;
    	cout<<"Include : ";
    	for(int q=0;q<n && inar[q]!=-1;q++) cout<<inar[q]<<" ";
    	cout<<endl;
    	cout<<"Exclude : ";
    	for(int q=0;q<n && exar[q]!=-1;q++) cout<<exar[q]<<" ";
    	cout<<endl;

	}
	// Return maximum of two values for last task
	cout<<min(incl, excl)<<endl;

}

// Driver code
int main()
{
	int arr3[] = {10, 5, 2, 4, 8, 6, 7, 10};
	int n3 = sizeof(arr3)/sizeof(arr3[0]);
	minTime(arr3, n3);

	return 0;
}
