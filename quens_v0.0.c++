#include <random>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <map>

const int N=5;

void set_complement(std::vector<int> &A, std::vector<int> &C);
void set_union(std::vector<int> &A, std::vector<int> &B, std::vector<int> &C); //Union of sets (std::vector<int>)

void N_j(std::vector<int> &myVector, int j); //Taken positions in the (j+1)th row

int random_value(std::vector<int> &myVector, double seed);
void print_vector(std::vector<int> &myVector);

int main(int argc, char *argv[])
{
  std::vector<int> a={1,2,3,4,5,0};
  std::vector<int> b={5,1};
  std::vector<int> c={1};
  std::vector<int> d;
  std::vector<int> e;
  std::random_device rd;
  print_vector(a);
  std::cout <<  random_value(a,rd()) << "\n";
  return 0;
}




void set_complement(std::vector<int> &A, std::vector<int> &C){
  std::vector<int> Universal;
  for (int i = 0; i < N; ++i) {
    Universal.push_back(i+1);
  }
  std::sort(A.begin(), A.end());
  
  std::set_difference(Universal.begin(), Universal.end(),
		      A.begin(), A.end(), 
		      std::inserter(C, C.begin()));
}

void set_union(std::vector<int> &A, std::vector<int> &B, std::vector<int> &C){
  std::sort(A.begin(), A.end());
  std::sort(B.begin(), B.end());
  std::set_union(A.begin(), A.end(),
		 B.begin(), B.end(),                  
		 std::back_inserter(C));
  
}

void N_j(std::vector<int> &myVector, int j){
  for (int i = 1; i <= N; ++i) {
    if( ( i != j-1 ) &&
	( i != j+1 ) &&
	( i != j ) ){
      myVector.push_back(i);
    }
    else continue;
  }
}


int random_value(std::vector<int> &myVector, double seed){
  std::mt19937 eng(seed); // seed the generator
  std::uniform_int_distribution<> distr(1,myVector.size()); // define the range
  return myVector[distr(eng)-1];
}

void print_vector(std::vector<int> &myVector){
  for(auto t : myVector)
    std::cout << t  << "\t";
  std::cout<<std::endl;
}
