#include <bits/stdc++.h>
using namespace std  ;

// CLASS - to conenct daat members and functions together ( so that they can NOT be accessed outside class = Encapsulation )
// and it helps to defins user-defiend data type . 

// Object  - An instance of the class .  Memory is allocated ONLY when object is made , NOT when class is declared 

// Inheritance - Properties (data meber and functions) of one class is inherited by another class . 
// Use virtual keywof with function name of PArent class , 
// so that ths function can b e Over-written by child class(during inheriatnce)-> show polymorphism 

// POlymorphism - Same opertor/ functions works differntly in different situations .

//ACCESS modifiers- > private(cant be asseced outside funcn)
// public - can be accesed outside funcn 
// protectd - cna be accesd by parent and child class only 

class Car {
public :
  int name ; 

  virtual void print(string s  ){
    cout << "This Car is " << s << endl ;
  }
} ;

// Inherit the properies of PArent class (Car) in child class cycle  , child : PArent

class Cycle :public Car {
   
   public:

    void print( string s )  {
        cout << "The Name of this Cycle is" << s << endl ;
    }
} ;


int main() {
  
  //MAke an instanc eof clas you want (USe class name as new-data type name )
  Car A ; 
  A.print("Maruti") ;

  Cycle B ;
  B.print("Hero") ;

   return  0 ;
}