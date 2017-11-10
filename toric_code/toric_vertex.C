#include <vector>
#include <string>
#include <algorithm>
#include <iostream>


using namespace std;
int N = 2;
int x_size = N, z_size = N;
vector<int> V_vec;

int toric_vertex(){
  // here we construct a simple toric code on NxN lattice
  // Consider the vertex operators of total N^2-1 
  // i.e For 2x2 independent operators are V00, V01, V10
  // Vij = {X(ij), Z(ij), X(i,j-1), Z(i-1,j)} i,j=0,1 
  // Periodicity yields if i,j=-1, set i,j=2 
 
  int xmax = x_size+1, zmax = z_size+1;
  int x[xmax][zmax], z[xmax][zmax];

  for(int i=0; i<x_size; i++){
    for(int j=0; j<z_size; j++){
     
      // initialize zero entries
      for(int ix=0; ix<x_size; ix++){
	for(int iz=0; iz<z_size; iz++){
	  x[ix][iz] = 0, z[ix][iz] = 0;
	}
      }
	
      // define non-zero entries
      x[i][j] = 1, z[i][j] = 1;      
      int im1 = i-1, jm1 = j-1;
      if (im1==-1) im1 = x_size-1;
      if (jm1==-1) jm1 = z_size-1;
      x[i][jm1] = 1, z[im1][j] = 1;

      // loop over vertex vector space
      V_vec.clear();
      for(int vi=0; vi<x_size; vi++){
	for(int vj=0; vj<z_size; vj++){
	  V_vec.push_back(x[vi][vj]);
	}
      }
      for(int vi=0; vi<x_size; vi++){
        for(int vj=0; vj<z_size; vj++){
	  V_vec.push_back(z[vi][vj]);
	}
      }

      // print vertex matrix representation
      cout << "V" <<  "[ " << i << "] [" << j << "]:" << " ";
      for(int k=0; k<V_vec.size(); k++) cout << V_vec[k] << " " ;
      cout << " " << endl;
    }
  }


  return 0;
}
