# clothing-store
## Exercise
Write a program for managing a clothing store archive. The items of clothing that can be sold are:
• Shirts
• Jackets
•	Trousers
• Skirts

The items of clothing in the archive can be found in 3 different states:
• State 1: garment not sold.
• Status 2: item of clothing sold.
• Status 3: item of clothing returned because it was defective.

The data relating to each item of clothing are:
• Code of the garment (A string of 5 characters), key field.
• Topology of the garment (A 9-character string [Shirt / Jacket / Pants / Skirt]).
• Brand of the garment (A string of 15 characters)
• State of the garment (A whole [1/2/3])
• Price of the item of clothing (A real)

The program stores data relating to current accounts in a hash table with collision lists and a bucket of size 3. The hash function is the product of the ascii codes of the first and last characters of the key characters of the key and calculates them the remainder of the integer division by 3. The program provides the following functions:

• Inserting a new item of clothing. (Functionality already provided)
• Sale or return of an item of clothing.
• Calculation of the total number of a particular type of garment of a given brand.
• Calculation of the total average price of clothing sold.
• Video printing of clothing. (Functionality already provided)

For the implementation of the application, the student has at his disposal:
• The files needed to create the entire project;
• The standard functions for the management of the hash table that must be used without making any changes to them (neither to the prototypes nor to their implementation provided);
• The definition of the prototypes of the functions to be implemented.

## Given files
The files provided are as follows:
• info.h (not to be changed)
Contains the definition of the TInfo type and the prototypes of the functions for its management.

• info.c (not to be changed)
Contains the implementation of the functions for the management of TInfo.

• list.h (not to be modified)
Contains the definition of the TList type and the prototypes of the functions for managing TList (standard functions)

• list.c (not to be modified)
Contains the implementation of the functions for managing TList (standard functions)

• hash.h (not to be changed)
Contains the definition of the THash type and the prototypes of the functions for the management of THash (standard functions)

• hash.c (to be completed)
Contains the implementation of the functions for the management of THash (standard functions). The student will have to implement the int f_hash (TKey key) function;

• menu.h (not to be changed)
Contains prototypes of user interface functions.

• menu.c (not to be changed)
Contains the implementation of the user interface functions.

• management_heads.h (not to be modified)
Contains the prototypes of the functions required by the application:
> int insert_head (THash clothing);

• The function reads the TInfo data and inserts a new node in the hash table. The function returns 1 if the insertion is successful, -1 otherwise. (The function is already provided)
> int sale_return_ garment (THash clothing);

• The function reads the code of the garment and the operation to be carried out. Then search for the item of clothing, if it is not found, -1 is returned, otherwise it is checked whether the chosen operation is feasible. If the operation is for sale and the garment is in state 1, the state of the garment is set to 2 and 1 is returned, if the state is different from 1, 0 is returned. return and the garment is in state 2, the state of the garment is set to 3 and 2 is returned, if the state is different from 2, 0 is returned.
> void conta_capi (THash clothing);

• The function reads the type and brand of the item of clothing of interest and calculates the quantity using the auxiliary function int conta (TList list, char type [], char brand []). At the end it prints the number of clothing items of interest. The function does not return any value.
> int counts (TList list, char type [], char brand []);

• The function calculates the number of garments of a given type and of a given brand within a list. The function returns the number of items found in the list (The function must be recursive).
> float average_price_sold (THash clothing);

• The function calculates the average price of all the items that have been sold. The function returns the calculated average price.
> void print_clothes (THash clothing);

• The print function, the information of all items of clothing in the archive. The function does not return any value. (The function is already provided)

• management_capi.c (to be completed)