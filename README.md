# Shuffled deck of playing cards sorted in a 2D array

## OVERVIEW:
In this assignment, you will write a C++ program that receives part
of a shuffled deck of playing cards and will sort them in a 2-dimensional
array.
Columns are in the order of spades, hearts, clubs, and diamonds.
Rows are in the order of 1 to 10 then Jack, Queen, and King.

### INPUT:
The input file contains a string listing some of the card's numbers and
the first letter of its suit.
• King denoted as K
• Queen denoted as Q
• Jack denoted as J
• Ace denoted as 1
Each card is separated from the next one with ", "and you can assume all
the inputs are in the correct form. See the example below as a valid
input:
QS, 8D, 4D, 1S, 10C, KH
(Queen of Spades), (8 of Diamonds), (4 of Diamonds), (Ace of Spades),
(10 of Clubs), (King of Hearts)

### OUTPUT:

Your output file should contain the 2D array with the cards received in
the input file notated in the 2D array with a 1 and the other cards not
received notated in the 2D array with a 0. 

### Example:

Input:

QS, 8D, 4D, 1S, 10C, KH

Output:

1000

0000

0000

0001

0000

0000

0000

0001

0000

0010

0000

1000

0100
