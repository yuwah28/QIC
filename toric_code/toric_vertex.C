#include <vector>
#include <string>
#include <algorithm>
#include <iostream>


using namespace std;
int N = 2;
int x_size = N, z_size = N;
vector<int> P_vec;

int toric_vertex(){
  // here we construct a simple toric code on NxN lattice
  // Consider the vertex operators of total N^2-1 
  // i.e For 2x2 independent operators are P00, P01, P10
  // Pij = {X(ij), Z(ij), X(i,j-1), Z(i-1,j)} i,j=0,1 
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

      // loop over plaquett vector space
      P_vec.clear();
      for(int pi=0; pi<x_size; pi++){
	for(int pj=0; pj<z_size; pj++){
	  P_vec.push_back(x[pi][pj]);
	}
      }
      for(int pi=0; pi<x_size; pi++){
        for(int pj=0; pj<z_size; pj++){
	  P_vec.push_back(z[pi][pj]);
	}
      }

      // print vertex matrix representation
      cout << "P" <<  "[ " << i << "] [" << j << "]:" << " ";
      for(int k=0; k<P_vec.size(); k++) cout << P_vec[k] << " " ;
      cout << " " << endl;
    }
  }


  return 0;
}
