# Creating Abstract Data Types in C

## Exercise 1. Add more functions on `Complex` type

1. Take Complex type discussed in the lecture. Let the name of source file be `complex.cpp`
2. Create following functions: 
    * reading a Complex object from console `void read_complex(Complex*)`
    * printing an Complex object `void print_complex(Complex)`
    * add two complex and return complex `Complex add_complex(Complex c1, Complex c2)`
    * subtract complex and return complex `Complex subtract_complex(Complex c1, Complex c2)`
    * multiply two complex and return complex `Complex add_complex(Complex c1, Complex c2)`
    * compute modulus of a complex number `double modulus(Complex c)`  
3. Call and test all above functions in `main` function

## Exercise 2. Inventory Item

1. Create C++ source file named as `inventory1.cpp` and add following functionality
1. Create a type `Item` using `typedef`. Let the `Item` have following fields  
`item_no short`, `description char[30]`, `cost float`.
2. Write code that constructs an Item object, assign values to it, and prints all its fields all on single line
3. Create functions for 
    * reading an Item object from console `void read_item(Item*)`
    * printing an Item object `void print_item(Item)`
3. Call and test all above functions in `main` function

## Exercise 3. Inventory implemented as array of Items

1. Create another C++ source file, name it as `inventory2.cpp`. 
1. Clear content of copied `main` function
2. in `main`, create an array of type `Item`. Let the size of array be 20.
3. Declare a global variable `NITEMS` of type `short` and initialized with zero. The objective of this variable is to maintain actual number of items in the inventory.
4. Create functions that manipulate the inventory 
    * add items to inventory; function prototype `void add_item(Item*, Item)` this function also increments global variable `NITEMS` accordingly.
    * search an item in inventory and return position `short find_item(Item*, short item_no)`
    * search an item in inventory and retutn Item object `Item find_item(Item*, short item_no)`
    * get an item at position index from inventory, `Item find_item(Item*, short index)`
    * update existing item `Item find_item(Item*, Item item, short index)` second parameter `item` is placed at position `index`. index starts from 0.
3. Call and test all above functions in `main` function
4. Add a functionality in main that prints all items in the `inventory`
