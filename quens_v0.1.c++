#include <random>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <map>
#include <typeinfo>
const int N=5;


void set_complement(std::vector<int> &A, std::vector<int> &C);
void set_union(std::vector<int> &A, std::vector<int> &B, std::vector<int> &C); //Union of sets (std::vector<int>)
void set_intersec(std::vector<int> &A, std::vector<int> &B, std::vector<int> &C);
void N_j(std::vector<int> &myVector, int j); //Taken positions in the (j+1)th row

int random_value(std::vector<int> &myVector, double seed);
void print_vector(std::vector<int> &myVector);
void remove_value(std::vector<int> &myVector, int value);

int main(int argc, char *argv[])
{

  std::random_device rd;
  std::vector< std::vector<int> > total_arrangements;
  std::vector< int > arrangement;
  std::vector<int> G_i;  // Global taken 'till the i-th row.
  std::vector<int> Next_taken;
  std::vector<int> Taken_effective;
  std::vector<int> Available_effective;
  
  N_j(Next_taken,0);
  set_union(G_i,Next_taken,Taken_effective);
  set_complement(Taken_effective,Available_effective);

  int i=0;
  

  G_i.push_back(3);
  arrangement.push_back(3);
  i=1;
  N_j(Next_taken,3);
  set_union(G_i,Next_taken,Taken_effective);
  set_complement(Taken_effective,Available_effective);

  G_i.push_back(5);
  arrangement.push_back(5);

  i=2;
  N_j(Next_taken,5);
  set_union(G_i,Next_taken,Taken_effective);
  set_complement(Taken_effective,Available_effective);

  G_i.push_back(2);
  arrangement.push_back(2);
  i=3;
  N_j(Next_taken,2);
  set_union(G_i,Next_taken,Taken_effective);
  set_complement(Taken_effective,Available_effective);
  G_i.push_back(4);
  arrangement.push_back(4);

  i=4;
  N_j(Next_taken,4);
  set_union(G_i,Next_taken,Taken_effective);
  set_complement(Taken_effective,Available_effective);

  print_vector(G_i);
  print_vector(arrangement);
  total_arrangements.push_back(arrangement);
  
  // std::cout << "G_" <<i<< "\n";
  // print_vector(G_i);

  // std::cout << "N_" <<i<< "\n";
  // print_vector(Next_taken);

  // std::cout << "T_" <<i<< "\n";
  // print_vector(Taken_effective);

  
  return 0;
}


//  Functions
void remove_value(std::vector<int> &myVector, int value){
  myVector.erase( std::remove( myVector.begin(),
			       myVector.end(),
			       value),
		  myVector.end());
}



void N_j(std::vector<int> &myVector, int j){
  myVector.clear();
  if (j==0) {}

  else {
    for (int i = 1; i <= N; ++i) {
      if( ( i == j-1 ) ||
	  ( i == j+1 ) ||
	  ( i == j ) ){
	myVector.push_back(i);
      }
    }
  }
}


int random_value(std::vector<int> &myVector, double seed){
  std::mt19937 eng(seed); // seed the generator
  std::uniform_int_distribution<> distr(1,myVector.size()); // define the range
  return myVector[distr(eng)-1];
}

void print_vector(std::vector<int> &myVector){
  if (myVector.size()==0) {
    std::cout << "------Empty Set-----" << "\n";    
  }
  else {
    
    for(auto t : myVector)
      std::cout << t  << "\t";
    std::cout<<std::endl;

  }
}

void set_union(std::vector<int> &A, std::vector<int> &B, std::vector<int> &C){
  std::sort(A.begin(), A.end());
  std::sort(B.begin(), B.end());
  C.clear();
  std::set_union(A.begin(), A.end(),
		 B.begin(), B.end(),                  
		 std::back_inserter(C));
  
}


void set_complement(std::vector<int> &A, std::vector<int> &C){
  C.clear(); 
  std::vector<int> Universal;
  for (int i = 0; i < N; ++i) {
    Universal.push_back(i+1);
  }
  std::sort(A.begin(), A.end());
  
  std::set_difference(Universal.begin(), Universal.end(),
		      A.begin(), A.end(), 
		      std::inserter(C, C.begin()));
}

void set_intersec(std::vector<int> &A, std::vector<int> &B, std::vector<int> &C){
  C.clear();
  std::sort(A.begin(), A.end());
  std::sort(B.begin(), B.end());
  std::set_intersection(A.begin(), A.end(),
			B.begin(), B.end(),
			std::back_inserter(C));
}
