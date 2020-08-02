/*
 Project 4 - Part 2 / 9
 Video: Chapter 3 Part 6

 Create a branch named Part2

New/This/Pointers/References conclusion

    Build/Run often with this task to make sure you're not breaking the code with each step.
    I recommend committing after you get each step working so you can revert to a working version easily if needed.
 
 0) in the blank space below, declare/define an empty struct named 'A' on a single Line. 
     on the lines below it, write a struct named 'HeapA' that correctly shows how to own an instance of 'A' 
         on the heap without leaking, without using smart pointers. 
 */

struct A{};

struct HeapA
{
    A* ptrA;
    HeapA() : ptrA( new A() ){}
    ~HeapA()
    {
        delete ptrA;
        ptrA = nullptr;
    }
};

 /*
 1) Edit your 3 structs so that they own a heap-allocated primitive type without using smart pointers named 'value'
         IntType should own a heap-allocated int, for example.
 
 2) give it a constructor that takes the appropriate primitive
    this argument will initialize the owned primitive's value.
         i.e. if you're owning an int on the heap, your ctor argument will initialize that heap-allocated int's value.
 
 3) modify those add/subtract/divide/multiply member functions from chapter 2 on it
         a) make them modify the owned numeric type
         b) set them up so they can be chained together.
             i.e.
             DoubleType dt(3.5);
             dt.add(3.0).multiply(-2.5).divide(7.2); //an example of chaining
 
 4) write add/subtract/divide/multiply member functions for each type that take your 3 UDTs
        These are in addition to your member functions that take primitives
        for example, IntType::divide(const DoubleType& dt);
        These functions should return the result of calling the function that takes the primitive.
     
 5) Don't let your heap-allocated owned type leak!
 
 6) replace your main() with the main() below.
    It has some intentional mistakes that you need to fix to match the expected output
    i.e. don't forget to dereference your pointers to get the value they hold.

 7) click the [run] button.  Clear up any errors or warnings as best you can.
 */

/*
your program should generate the following output EXACTLY.
This includes the warnings.
Use a service like https://www.diffchecker.com/diff to compare your output. 
you'll learn to solve the conversion warnings in the next project part.

18 warnings generated.
FloatType add result=4
FloatType subtract result=2
FloatType multiply result=4
FloatType divide result=0.25

DoubleType add result=4
DoubleType subtract result=2
DoubleType multiply result=4
DoubleType divide result=0.8

IntType add result=4
IntType subtract result=2
IntType multiply result=4
IntType divide result=1

Chain calculation = 590
New value of ft = (ft + 3.0f) * 1.5f / 5.0f = 0.975
---------------------

Initial value of dt: 0.8
Initial value of it: 590
Use of function concatenation (mixed type arguments) 
New value of dt = (dt * it) / 5.0f + ft = 95.375
---------------------

Intercept division by 0 
New value of it = it / 0 = error: integer division by zero is an error and will crash the program!
590
New value of ft = ft / 0 = warning: floating point division by zero!
inf
New value of dt = dt / 0 = warning: floating point division by zero!
inf
---------------------

good to go!





*/

#include <iostream>

struct DoubleType;
struct IntType;

//==============================================================================
struct FloatType
{
    float* floatPtr;
    FloatType( float f ) : floatPtr( new float( f ) ){}
    ~FloatType()
    {
        delete floatPtr;
        floatPtr = nullptr;
    }

    FloatType& add( float rhs );
    FloatType& subtract( float rhs );
    FloatType& multiply( float rhs );
    FloatType& divide( float rhs );

    FloatType& add( FloatType& rhs );
    FloatType& subtract( FloatType& rhs );
    FloatType& multiply( FloatType& rhs );
    FloatType& divide( FloatType& rhs );

    FloatType& add( DoubleType& rhs );
    FloatType& subtract( DoubleType& rhs );
    FloatType& multiply( DoubleType& rhs );
    FloatType& divide( DoubleType& rhs );

    FloatType& add( IntType& rhs );
    FloatType& subtract( IntType& rhs );
    FloatType& multiply( IntType& rhs );
    FloatType& divide( IntType& rhs );
};

struct DoubleType
{
    double* doublePtr;
    DoubleType( double d ) : doublePtr( new double( d ) ){}
    ~DoubleType()
    {
        delete doublePtr;
        doublePtr = nullptr;
    }

    DoubleType& add( double rhs );
    DoubleType& subtract( double rhs );
    DoubleType& multiply( double rhs );
    DoubleType& divide( double rhs );

    DoubleType& add( DoubleType& rhs );
    DoubleType& subtract( DoubleType& rhs );
    DoubleType& multiply( DoubleType& rhs );
    DoubleType& divide( DoubleType& rhs );

    DoubleType& add( IntType& rhs );
    DoubleType& subtract( IntType& rhs );
    DoubleType& multiply( IntType& rhs );
    DoubleType& divide( IntType& rhs );

    DoubleType& add( FloatType& rhs );
    DoubleType& subtract( FloatType& rhs );
    DoubleType& multiply( FloatType& rhs );
    DoubleType& divide( FloatType& rhs );
};

struct IntType
{
    int* intPtr;
    IntType( int i ) : intPtr( new int( i ) ){}
    ~IntType()
    {
        delete intPtr;
        intPtr = nullptr;
    }

    IntType& add( int rhs );
    IntType& subtract( int rhs );
    IntType& multiply( int rhs );
    IntType& divide( int rhs );

    IntType& add( IntType& rhs );
    IntType& subtract( IntType& rhs );
    IntType& multiply( IntType& rhs );
    IntType& divide( IntType& rhs );

    IntType& add( FloatType& rhs );
    IntType& subtract( FloatType& rhs );
    IntType& multiply( FloatType& rhs );
    IntType& divide( FloatType& rhs );

    IntType& add( DoubleType& rhs );
    IntType& subtract( DoubleType& rhs );
    IntType& multiply( DoubleType& rhs );
    IntType& divide( DoubleType& rhs );
};

//==============================================================================
FloatType& FloatType::add( float rhs )
{
    *floatPtr += rhs;

    return *this;
}

FloatType& FloatType::subtract( float rhs )
{
    *floatPtr -= rhs;

    return *this;
}

FloatType& FloatType::multiply( float rhs )
{
    *floatPtr *= rhs;

    return *this;
}

FloatType& FloatType::divide( float rhs )
{
    if (rhs == 0.0f)
    {
        std::cout << std::endl << "warning, floating point division by zero returns 'inf' !" << std::endl;
    }

    *floatPtr /= rhs;

    return *this;
}


FloatType& FloatType::add( FloatType& rhs )
{
    return add( *rhs.floatPtr );
}

FloatType& FloatType::subtract( FloatType& rhs )
{
    return subtract( *rhs.floatPtr );
}

FloatType& FloatType::multiply( FloatType& rhs )
{
    return multiply( *rhs.floatPtr );
}

FloatType& FloatType::divide( FloatType& rhs )
{
    return divide( *rhs.floatPtr );
}


FloatType& FloatType::add( DoubleType& rhs )
{
    return add( *rhs.doublePtr );
}

FloatType& FloatType::subtract( DoubleType& rhs )
{
    return subtract( *rhs.doublePtr );
}

FloatType& FloatType::multiply( DoubleType& rhs )
{
    return multiply( *rhs.doublePtr );
}

FloatType& FloatType::divide( DoubleType& rhs )
{
    return divide( *rhs.doublePtr );
}


FloatType& FloatType::add( IntType& rhs )
{
    return add( *rhs.intPtr );
}

FloatType& FloatType::subtract( IntType& rhs )
{
    return subtract( *rhs.intPtr );
}

FloatType& FloatType::multiply( IntType& rhs )
{
    return multiply( *rhs.intPtr );
}

FloatType& FloatType::divide( IntType& rhs )
{
    return divide( *rhs.intPtr );
}

//==============================================================================
DoubleType& DoubleType::add( double rhs )
{
    *doublePtr += rhs;

    return *this;
}

DoubleType& DoubleType::subtract( double rhs )
{
    *doublePtr -= rhs;

    return *this;
}

DoubleType& DoubleType::multiply( double rhs )
{
    *doublePtr *= rhs;
    
    return *this;
}

DoubleType& DoubleType::divide( double rhs )
{
    if (rhs == 0.0)
    {
        std::cout << std::endl << "warning, floating point division by zero returns 'inf' !" << std::endl;
    }

    *doublePtr /= rhs;

    return *this;
}


DoubleType& DoubleType::add( DoubleType& rhs )
{
    return add( *rhs.doublePtr );
}

DoubleType& DoubleType::subtract( DoubleType& rhs )
{
    return subtract( *rhs.doublePtr );
}

DoubleType& DoubleType::multiply( DoubleType& rhs )
{
    return multiply( *rhs.doublePtr );
}

DoubleType& DoubleType::divide( DoubleType& rhs )
{
    return divide( *rhs.doublePtr );
}


DoubleType& DoubleType::add( IntType& rhs )
{
    return add( *rhs.intPtr );
}

DoubleType& DoubleType::subtract( IntType& rhs )
{
    return subtract( *rhs.intPtr );
}

DoubleType& DoubleType::multiply( IntType& rhs )
{
    return multiply( *rhs.intPtr );
}

DoubleType& DoubleType::divide( IntType& rhs )
{
    return divide( *rhs.intPtr );
}


DoubleType& DoubleType::add( FloatType& rhs )
{
    return add( *rhs.floatPtr );
}

DoubleType& DoubleType::subtract( FloatType& rhs )
{
    return subtract( *rhs.floatPtr );
}

DoubleType& DoubleType::multiply( FloatType& rhs )
{
    return multiply( *rhs.floatPtr );
}

DoubleType& DoubleType::divide( FloatType& rhs )
{
    return divide( *rhs.floatPtr );
}

//==============================================================================
IntType& IntType::add( int rhs )
{
    *intPtr += rhs;

    return *this;
}

IntType& IntType::subtract( int rhs )
{
    *intPtr -= rhs;

    return *this;
}

IntType& IntType::multiply( int rhs )
{
    *intPtr *= rhs;

    return *this;
}

IntType& IntType::divide( int rhs )
{
    if (rhs == 0)
    {
        std::cout << "error, integer division by zero will crash the program!";
        
        return *this;
    }

    *intPtr /= rhs;
    
    return *this;
}


IntType& IntType::add( IntType& rhs )
{
    return add( *rhs.intPtr );
}

IntType& IntType::subtract( IntType& rhs )
{
    return subtract( *rhs.intPtr );
}

IntType& IntType::multiply( IntType& rhs )
{
    return multiply( *rhs.intPtr );
}

IntType& IntType::divide( IntType& rhs )
{
    return divide( *rhs.intPtr );
}


IntType& IntType::add( FloatType& rhs )
{
    return add( *rhs.floatPtr );
}

IntType& IntType::subtract( FloatType& rhs )
{
    return subtract( *rhs.floatPtr );
}

IntType& IntType::multiply( FloatType& rhs )
{
    return multiply( *rhs.floatPtr );
}

IntType& IntType::divide( FloatType& rhs )
{
    return divide( *rhs.floatPtr );
}


IntType& IntType::add( DoubleType& rhs )
{
    return add( *rhs.doublePtr );
}

IntType& IntType::subtract( DoubleType& rhs )
{
    return subtract( *rhs.doublePtr );
}

IntType& IntType::multiply( DoubleType& rhs )
{
    return multiply( *rhs.doublePtr );
}

IntType& IntType::divide( DoubleType& rhs )
{
    return divide( *rhs.doublePtr );
}
//==============================================================================

int main()
{   
    //testing instruction 0
    HeapA heapA; 

    //assign heap primitives
    FloatType ft ( 2.0f );
    DoubleType dt ( 2 );
    IntType it ( 2 ) ;

    std::cout << "FloatType add result=" << ft.add( 2.0f ).value << std::endl;
    std::cout << "FloatType subtract result=" << ft.subtract( 2.0f ).value << std::endl;
    std::cout << "FloatType multiply result=" << ft.multiply( 2.0f ).value << std::endl;
    std::cout << "FloatType divide result=" << ft.divide( 16.0f).value << std::endl << std::endl;

    std::cout << "DoubleType add result=" << dt.add(2.0).value << std::endl;
    std::cout << "DoubleType subtract result=" << dt.subtract(2.0).value << std::endl;
    std::cout << "DoubleType multiply result=" << dt.multiply(2.0).value << std::endl;
    std::cout << "DoubleType divide result=" << dt.divide(5.f).value << std::endl << std::endl;

    std::cout << "IntType add result=" << it.add(2).value << std::endl;
    std::cout << "IntType subtract result=" << it.subtract(2).value << std::endl;
    std::cout << "IntType multiply result=" << it.multiply(2).value << std::endl;
    std::cout << "IntType divide result=" << it.divide(3).value << std::endl << std::endl;
    std::cout << "Chain calculation = " << (it.multiply(1000).divide(2).subtract(10).add(100)).value << std::endl;

        // FloatType object instanciation and method tests
    // --------
    std::cout << "New value of ft = (ft + 3.0f) * 1.5f / 5.0f = " << ft.add( 3.0f ).multiply(1.5f).divide(5.0f).value << std::endl;
       
    std::cout << "---------------------\n" << std::endl; 
    
    // DoubleType/IntType object instanciation and method tests
    // --------
    std::cout << "Initial value of dt: " << dt.value << std::endl;
    std::cout << "Initial value of it: " << it.value << std::endl;
    // --------
    std::cout << "Use of function concatenation (mixed type arguments) " << std::endl;
    std::cout << "New value of dt = (dt * it) / 5.0f + ft = " << (dt.multiply(it).divide(5.0f).add(ft).value) << std::endl;

    std::cout << "---------------------\n" << std::endl; 
    
    // Intercept division by 0
    // --------
    std::cout << "Intercept division by 0 " << std::endl;
    std::cout << "New value of it = it / 0 = " << it.divide(0).value << std::endl;
    std::cout << "New value of ft = ft / 0 = " << ft.divide(0).value << std::endl;
    std::cout << "New value of dt = dt / 0 = " << dt.divide(0).value << std::endl;

    std::cout << "---------------------\n" << std::endl; 

    std::cout << "good to go!\n";

    return 0;
}



