/*****
 * Author   : brinkmwj
 * Date     : 2009-07-23
 * Sources  : All code is original
 * Purpose  : This file does not declare a class: Instead, it just declares some constants and functions
 *            used for performing the experiment.
 * Note     : DO NOT CHANGE THIS FILE!!! All implementations of these functions should be in Experiment.cpp
 *****/

//Used in the chiSquared test. This is the critical value for p=0.05, with
// 51 degrees of freedom. 
#define CRITICALVALUE 68.67

//Used in doOneExperiment
#define NUMEXPERIMENTS 10000

/* Use a one-dimensional array to represent a 52 x 52 matrix. Initialize all entries to 0.
 * //You will use this matrix to keep track of how many times card X ends up in position Y.
 *
 * Repeat NUMEXPERIMENTS times:
 *   Create a deck, then shuffle it numshuffles times. Then go through the deck. If card X is in
 *   position Y in the deck, do countMatrix[X*52 + Y] = countMatrix[X*52 + Y] + 1
 *
 * At the end, print out your count matrix in a file called table<numshuffles>.txt ... so if numshuffles
 * is 9, the file would be named table9.txt.  Your output should be formated to be human readable: that is, in 
 * row/column format with 52 cards per row.
 *
 * Finally, do a chiSquared test on the first row of countMatrix to see if the first card is randomly distributed
 * through the deck. If chiSquared(countMatrix,52) < CRITICALVALUE, then print out  (to cout) a message that looks like this:
 
 9 shuffles was fair, with chi^2 = 65.490

 * If chiSquared(countMatrix,52) >= CRITICALVALUE, then print out a message that looks like this:

 3 shuffles was biased, with chi^2 = 1078.34

 * Note: You should fill in the correct values for numshuffles and the chiSquared value in the messages!
 *
 * Finally, return the chiSquared value.
 */
double doOneExperiment(int numshuffles);

/*
 * Consider a single card in the deck. After shuffling, the position of the card
 * should be uniformly distributed through the deck. With this function, pass
 * in a pointer to the start of a row in your frequency table, and pass in the row
 * length (which is 52, because there are 52 positions). The function will calculate
 * the chi-squared statistic for the row. The higher the chiSquared, the better the
 * evidence that the card is NOT uniformly distributed through the deck.
 *
 * For this assignment, if chiSquared < CRITICALVALUE for the first card in the deck, 
 * then we accept the claim that the shuffle is fair. If chiSquared >= CRITICALVALUE,
 * then we have strong evidence that the shuffle was biased.
 *
 * Your job is to find the smallest value of numshuffles that results in chiSquared < CRITICALVALUE
 * for the first card in the deck
 */
double chiSquared(long* rowHead, int rowLength);

/*
 * Start with numshuffles = 0, and then do doOneExperiment for each value of numshuffles until
 * you find one with doOneExperiment(numshuffles) < CRITICALVALUE. At that point you can stop
 * because you will have found how many shuffles it takes to get a distribution that looks fair.
 * Otherwise, stop after you have increased numshuffles a number of times equal to MAXNUMSHUFFLES
 * (constant defined in Experiment.cpp to be equal to 15).
 * 
 * Note: The right answer is probably somewhere between 6 and 12 shuffles, so you probably have a problem
 * with your code if it takes more or less than that.
 */
void doExperimentRun();
