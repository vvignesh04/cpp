#include <iostream>
using namespace std;
void merge(int array[],int l,int m,int r)
{
  int i=l;
  int j=m+1;
  int k=l;
  int temp[10];
  while(i<=m && j<=r)
  {
    if(array[i]<array[j])
    {
      temp[k]=array[i];
      i++;
    }
    else{
      temp[k]=array[j];
      j++;
    }
    k++;
  }
  while(i<=m)
  {
    temp[k]=array[i];
    i++;
    k++;
  }
  while(j<=r)
  {
    temp[k]=array[j];
    j++;
    k++;
  }
  for(int s=l;s<r;s++)
  {
    array[s]=temp[s];
  }
}
void mergesort(int arr[],int l,int r)
{
  if(l<r)
  {
    int mid=(l+r)/2;
    mergesort(arr,l,mid+1);
    mergesort(arr,mid-1,r);
    merge(arr,l,mid,r);

  }
}
int main()
{
  int arr[]={5,4,3,2,1};
  mergesort(arr,0,4);
  for(int j=0;j<5;j++)
  {
    cout<<arr[j]<<" ";
  }
  cout<<"\n";
  return 0;
}
























/*

void merge(int array[], int l, int m, int r) {
    int i = l;
    int j = m + 1;
    int k = l;
    int temp[10];

    while (i <= m && j <= r) {
        if (array[i] <= array[j]) 
        {
            temp[k] = array[i];
            i++;
        } 
        else 
        {
            temp[k] = array[j];
            j++;
        }
        k++;
    }

    while (i <= m) 
    {
        temp[k] = array[i];
        i++;
        k++;
    }

    while (j <= r)
    {
        temp[k] = array[j];
        j++;
        k++;
    }

    for (int s = l; s <= r; s++)
    {
        array[s] = temp[s];
    }
}

void mergesort(int arr[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        mergesort(arr, l, m);
        mergesort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    
    int a[n];
    for (int i = 0; i < n; i++) {
        cout << "Enter element " << i + 1 << ": ";
        cin >> a[i];
    }

    cout << "Before sorting: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    mergesort(a, 0, n - 1);

    cout << "After sorting: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}
*/