# Substitution Decoder
Decodes given text file, either by frequency analysis or using a Caesar cipher (not available yet). Eventually, I plan to allow the user to specify their own frequency table.

- Written by Michael Giancola
- Created on 8/6/15
- Last Modified 8/13/15

#### Usage Notes:
- Program ignores any non-letter characters, including numbers and spaces. They will not be present in the output.
- "make clean" destroys output files.

#### Release Notes:

##### 8/7/15 :
Changed method of assigning frequencies. Decryption works by using two arrays: an array of 26 ints, where arr[0] represents the frequency of the letter 'a', arr[1] the freequency of 'b', and so on; the other array contains the alphabet in order. The sorting method sorts the integer array in descending order, while at the same time sorting the alphabet in the same fashion. The end result is a character array in order of frequency (ie. arr[0] contains the most frequently used letter, and arr[25] contains the least frequently used letter).

Haven't tested yet.

##### 8/6/15 :
Wrote a bunch of code for Frequency Analysis. It almost works.. sort of. Okay not at all. It runs and creates a file, but there is something wrong with the frequency table.
