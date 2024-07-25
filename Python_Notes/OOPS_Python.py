class People :
    age = 10 # staic var 
    cnt= 0
    def __init__(self , Name ):
        self.name = Name# instance var 
        People.cnt+=1 
    def change(self) :
        self.age = 12
        a = 10
        print(a)
    def change_(self) :
        pass
    class inner:
        def disp(self): # constructor nad self /staic is As important for Inner class (initialize it seperately after outer class )
            print("Inner class defined ")

            
    @classmethod 
    def count(cls ):
        print(cls.cnt)
    def __del__ (self ) :
        print("destrotying object and Garbage collector colecting it /..")
    
  
# ONly constructor runs by default , rest of methods have to be run speertaely 
p1 = People("hello")
p2 = People("World")

People.age = 11 
# People.change() -> wrong 

# del People.age-> correct (del static using Class Name NOT using obje NAme , since its now created an instance var)
# del p1.age -> incorrect , 

print(p1.age , p1.name)
print(p2.age  , p2.name )
p1.change()
People.count()
i1 = p1.inner()
i1.disp()

import gc 
print( gc.isenabled())

del p1 




#Polymorphism   same FUnction( wrt its NAme) behaves Differntly in diff situatinos (ie in diff classes )

class Duck :
    def __init__(self) :
        self.legs =2 
        
    def talk( self):
        print("Quack")
        
class Dog :
    def __init__(self) :
        self.legs =4 
         
    def talk(self) :   # POlymorphism 
        print("bark")
    def walk(self ) :
        print("Walking")
    def __add__(self, other ) :
        print( self.legs + other.legs )
d  =Duck()
b = Dog()
d.talk()
b.talk()
# hasattr( d , 'walk' )
b+ d


class parent :
    def __init__ ( self ) :
        self.x = 10 
    def name( self ):
        print( "parent")

class child( parent ) :
    
    def __init__ (self ) :
        super().__init__() # always use super().init__() (without self)arg inside cosntructor of child class 
        # and , 
        print(self.x)
        
    def name( self ) :
        # print(self.x)
        print("child")

c= child()
d = parent()


    
