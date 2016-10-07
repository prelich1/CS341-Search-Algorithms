#include <iostream>
using namespace std;

struct rise {
  int length;
  int index;
};

rise longestCrossRise(int l, int m, int h, int a[], int r) 
{
    // start leftRise at 1 to automatically include the middle element
    // start rightRist at 0 as to not double count middle element
    int leftRise = 1;
    int rightRise = 0;
    int index = m;
    rise longRise;

    for (int i = m; i > l; i--)
    {
      if (a[i] > r*a[i-1])
      {	
	      leftRise++;
        index = i-1;
      }
      else
	break;
    }

    for (int i = m+1; i <= h; i++)
    {
      if (a[i] > r*a[i-1])
	       rightRise++;
      else
	break; 
    }

    longRise.length = rightRise + leftRise;
    longRise.index = index;

    return longRise;
}

rise longestRise(int l, int h, int a[], int r)
{
  rise longRise;

  if (l == h)
  {
    longRise.length = 1;
    longRise.index = l;
    return longRise;
  }

  int m = (l + h)/2;

  rise leftSubRise = longestRise(l, m, a, r);
  rise rightSubRise = longestRise(m+1, h, a, r);; 
  rise crossSubRise= longestCrossRise(l, m, h, a, r);
    
  longRise = leftSubRise;
  if (longRise.length < crossSubRise.length)
    {    
      longRise = crossSubRise;
    }

  if (longRise.length < rightSubRise.length)
    {
      longRise = rightSubRise;
    }
  
  return longRise;
}

int main(int argc, char* argv[])
{
  int n;
  int a[n];
  int r;

  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];

  cin >> r;

  rise longRise = longestRise(0, n-1, a, r);
  cout << longRise.length << " " <<a [longRise.index] << endl;

  return 0;
}
