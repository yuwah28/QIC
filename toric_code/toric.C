#include "TROOT.h"
#include "TSystem.h"
#include "TMath.h"
#include "TObjArray.h"
#include "TClonesArray.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;
int N = 3;
int x_size = N, z_size = N;
vector<int> P_vec;

int toric(){
  // here we construct a simple toric code on NxN lattice
  // Consider first plaquett operators of total N^2-1 
  // i.e For 2x2 independent operators are P00, P01, P10
  // Pij = {X(ij), Z(ij), X(i+1,j), Z(i,j+1)} i,j=0,1 
  // Periodicity yields if i,j=2, set i,j=0 
 
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
      int ip1 = i+1, jp1 = j+1;
      if (i+1==x_size) ip1 = 0;
      if (j+1==z_size) jp1 = 0;
      x[ip1][j] = 1, z[i][jp1] = 1;

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

      //cout << "Print plaquett row vector... " << endl;
      cout << "P" <<  "[ " << i << "] [" << j << "]:" << " ";
      for(int k=0; k<P_vec.size(); k++) cout << P_vec[k] << " " ;
      cout << " " << endl;
    }
  }



  return 0;
}
