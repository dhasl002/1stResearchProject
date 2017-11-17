#include <stdio.h>
#include <stdlib.h>

#include <math.h>
#include <time.h>
#include <stdbool.h>

//function prototypes
void pathsWithoutRowsRemoved2(int path[], int tempChoice, double wtsForChoosing, int SecondValidityCheck[], double WtArray[], int rowPtr[], int Count[], int columnIndex[], double probability[], int isInvalid[], int adjCount[], int adjColumnIndex[], int adjRowPtr[], double adjWtArray[], double keptPaths[]);
void pathsWithoutRowsRemoved(int path[], int tempChoice, double wtsForChoosing, int SecondValidityCheck[], double WtArray[], int rowPtr[], int Count[], int columnIndex[], double probability[], int isInvalid[], int adjCount[], int adjColumnIndex[], int adjRowPtr[], double adjWtArray[]);
void pathsWithoutRowsRemoved3(int path[], int tempChoice, double wtsForChoosing, int SecondValidityCheck[], double WtArray[], int rowPtr[], int Count[], int columnIndex[], double probability[], int isInvalid[],  int adjCount[], int adjColumnIndex[], int adjRowPtr[], double adjWtArray[], double keptPaths[]);
void fixMinWtSubset(int partialPath[], double randMinWtEdges[], int isInvalid[], int adjCount[], int adjColumnIndex[], int adjRowPtr[], double adjWtArray[], double subsetMinWtEdges[], double pathEdges[], double keptPaths[], int Count[]);
void createSubsetRemovedRows(double LinearArray[], int removeProbability[], int removeProbabilitySorted[], int rowsToRemove[], int removeSubset[]);
void findSubsetSizeBinary(int partialPath[], double randMinWtEdges[], int isInvalid[], int adjCount[], int adjColumnIndex[], int adjRowPtr[], double adjWtArray[], double subsetMinWtEdges[], double pathEdges[], double keptPaths[]);
void findSubsetSize(int partialPath[], double randMinWtEdges[], int isInvalid[], int adjCount[], int adjColumnIndex[], int adjRowPtr[], double adjWtArray[], double subsetMinWtEdges[], double pathEdges[], double keptPaths[]);
void pickBestToRemove(double LinearArray[], int removeProbability[], int removeProbabilitySorted[], int rowsToRemove[]);
void setUpToRemove(double linearArray[], int removeProbability[]);
void computeVariables(FILE *input);
void printAdjRowPtr(int adjRowPtr[]);
void printAdjCount(int adjCount[]);
void printAdjColumn(int adjColumnIndex[], int adjRowPtr[]);
void printLinearArray(double LinearArray[]);
void printPath(int Path[], int adjColumnIndex[], double adjWtArray[], int adjRowPtr[]);
void printSecondValidityCheck(int adjCount[], int SecondValidityCheck[], int path[]);
void printValidPath(int path[], int minPath[]);
void readInput(double LinearArray[], FILE *input);
void createCompoundArr(double LinearArray[], double WtArray[], int columnIndex[], int Count[]);
void createRowPtr(int rowPtr[], int Count[]);
void initializeArr(int minPath[], int path[], int isInvalid[], int adjCount[], int adjRowPtr[], int Count[], int rowPtr[], int adjColumnIndex[], double adjustedArr[], int toRemove[], double keptPaths[], int rowsToRemove[],  double minWtEdges[]);
void removingRows(int adjColumnIndex[], int toRemove[], int rowPtr[], int adjRowPtr[], double WtArray[], int columnIndex[], double adjWtArray[], int rowsToRemove[], int rowsNotToRemove[]);
void createAdjCount(int adjCount[], int adjRowPtr[]);
void createRowsNotToRemove(int rowsNotToRemove[], int rowsToRemove[]);
void printRowsNotToRemove(int rowsNotToRemove[]);
void firstInPath(int path[]);
void repeatedStick(int isInvalid[], int r);
void randomRemoval(int rowsToRemove[]);
void printRowsToRemove(int rowsToRemove[]);
void triedAllOptions(int adjCount[], int path[], int SecondValidityCheck[]);
void reset2ndValidity(int adjCount[], int path[], int SecondValidityCheck[]);
void restartPath(int adjCount[], int path[], int SecondValidityCheck[], int isInvalid[], double probability[], double adjWtArray[], int adjRowPtr[]);
void findMin(int path[], int minPath[]);
void optimizeNodes(int originalPath[], int adjRowPtr[], int adjColumnIndex[], double adjWtArray[], int adjCount[]);
void keepPath(double keptPaths[], int newPath[], double weight);
void initializeProbabilityCorrectly(int adjCount[], double probability[], double adjWtArray[], int adjRowPtr[], int path[], double wtsForChoosing);
void normalizeByMax(int adjCount[], double probability[], double adjWtArray[], int adjRowPtr[], int path[], double wtsForChoosing);
void correctBiasedChoice(double probability[], int adjCount[], int path[], double adjWtArray[], int adjRowPtr[]);
void printTopPaths(double keptPaths[]);
void findPaths(int path[], int isInvalid[], int adjCount[], double adjWtArray[], int adjRowPtr[], int adjColumnIndex[], int minPath[], double keptPaths[], double wtsForChoosing, int SecondValidityCheck[], double probability[], int tempChoice);
void constructSetRemoved(int m, double minWtEdges[], double linearArray[], int rowsToRemove[], int rowsNotToRemove[]);
void printMinWtEdges(double minWtEdges[], int m);
void minSelectSet(double minWtEdges[], int k, double subsetMinWtEdges[]);
void printSubset(int k, double subsetMinWtEdges[]);
void randomSelectSet(int randNum, double subsetMinWtEdges[], double randMinWtEdges[]);
void printRandMinSet(double randMinWtEdges[], int randNum);
void resetKeptPaths(double keptPaths[], int uniquePaths);
void createPathsFromOneEdge(int subsetMinEdges, double subsetMinWtEdges[], double randMinWtEdges[],  int partialPath[], int rowsToRemove[], int adjRowPtr[], int adjColumnIndex[], int randMinEdges, int isInvalid[], int adjCount[], double adjWtArray[], double keptPaths[], double probability[], double wtsForChoosing, int numToCreate);
void createPathsFromSubset(int partialPath[], double randMinWtEdges[], int isInvalid[], int adjCount[], int adjColumnIndex[], int adjRowPtr[], double adjWtArray[], double subsetMinWtEdges[], double pathEdges[], double keptPaths[], int numToCreate);
void constructPartialPath(int partialPath[], double randMinWtEdges[], int rowsToRemove[]);
bool pathIsValid(int minPath[], int adjRowPtr[], int adjColumnIndex[], double adjWtArray[], int adjCount[]);
int cmpfunc (const void * a, const void * b);
int cmpfuncInt (const void * a, const void * b);
int findLargestCount(int adjCount[]);
bool isValidPartialPath(double randMinWtEdges[],  int partialPath[], int rowsToRemove[], int adjRowPtr[], int adjColumnIndex[], int randMinEdges, bool print);
bool CompletePathRandom(int partialPath[], double randMinWtEdges[], int isInvalid[], int adjCount[], int adjColumnIndex[], int adjRowPtr[], double adjWtArray[], double keptPaths[]);
double findWtOfPath(int path[], int adjColumnIndex[], double adjWtArray[], int adjRowPtr[]);
bool CompletePathFromMinEdges(int partialPath[], double randMinWtEdges[], int isInvalid[], int adjCount[], int adjColumnIndex[], int adjRowPtr[], double adjWtArray[], double subsetMinWtEdges[], double p[], double keptPaths[]);
bool CompletePathDeterministic(double subsetMinWtEdges[], double randMinWtEdges[],  int partialPath[], int rowsToRemove[], int adjRowPtr[], int adjColumnIndex[], int isInvalid[], int adjCount[], double adjWtArray[], double keptPaths[]);
bool CompletePathProbabilistic(int partialPath[], double randMinWtEdges[], int isInvalid[], int adjCount[], int adjColumnIndex[], int adjRowPtr[], double adjWtArray[], double keptPaths[], double probability[], double wtsForChoosing);
bool edgeExists(int edge1, int edge2, int adjRowPtr[], int adjColumnIndex[], double adjWtArray[], int adjCount[]);
bool edgesAreValid(int index1, int index2, double randMinWtEdges[]);
bool checkNewEdges(int partialPath[], int adjRowPtr[], int adjColumnIndex[]);
int whereToStartPath(int partialPath[]);

//constants in program
const double epsilon = .000001;   //for comparing doubles
int inputsPerLine = 0;  //number of inputs per line in input file
int lengthOfPath = 0;   //specifies the length of the valid path to be made
int N = 0; //number of helices
int M = 0; //2*number of sticks
int NE = 0; //number of edges 15706 27003 11750 5220 444 10916 1947 7548 3953
int N1 = 0; //number of layers with outgoing edges
const int PathsToKeep = 100; //paths to keep must be greater than unique paths!!!!!
const int invalidLimit = 1000;    //limit of invalid paths until you get a valid path
const int validPathNum = 1000; //number of valid paths that you want to generate
const double wtsForChoosing = 2;    //the weight we put on the nodes to be chosen
int numToRemove  = 0;     //number of rows to remove
int minEdgesToKeep = 0; //the amount of minimum edges to keep from the linear array 2000 1000 700 400 444 900? 700? 350
int subsetMinEdges = 0;  //the amount in a subset of the lowest edges from minEdgesToKeep
const int randMinEdges = 2;    //the amount in a random subset of the subsetMinEdges

int uniquePaths = 0;
double probValue = 0;
double runningProbSum = 0;
int randomTemp = 0; //when generating a path, we randomly select the next node in the sequence. This variable temporarily stores a value that corresponds to which random node is selected
double randomTemp2 = 0;
int nextValid = 0;  //holds the next node in the path to be added to path[i]
int CountisZero = 0;    //used to tell when there are no nodes coming out of a specific edge, in other words when Count[i] == 0
int invalidCount = 0;   //used to determine how many invalid rows were made before a valid one is
int i = 0;  //used for index in for loops
int j = 0;  //used when creating adjusted array
int numEdges = 0;
double minWeight = 150000;  //holds the minimum weight of all the valid paths
double runningWeightTotal = 0;  //adds all weights of current path and compares this weight to the minimum weight
bool invalid = false;   //used for efficiency, if all values of secondValidity array are 1, that means every possible random node has been selected and is invalid
bool startsWithZero = false;
bool tooManyTries = false;
int countTries = 0;
//bool pathHasRestarted = false;

int main()
{
    time_t t;   //used for random generation
    srand((unsigned) time(&t));


    //Receives input file with NE*inputsPerLine entries.
    FILE *input;    //used for reading input
    input = fopen("weightList1.txt", "r");
    computeVariables(input);
    fclose(input);
    FILE *input2;    //used for reading input
    input2 = fopen("weightList1.txt", "r");


    double *LinearArray;   //linear array holding every value in input file
    LinearArray = (double *)malloc(sizeof(double)*(NE*inputsPerLine));
    //gets input from file and stores it in LinearArray
    readInput(LinearArray, input2);
    //printLinearArray(LinearArray);


    //All arrays used
    //int testPath[] ={25, 31, 77, 127, 179, 206, 228, 261, 302, 352, 368, 402, 454, 494, 550};  //a different valid path used for testing purposes
    double keptPaths[(lengthOfPath+2)*PathsToKeep]; // an array full of the best paths found, the number of paths to keep is specified by pathsToKeep
    int path[lengthOfPath];     //holds all the values of a valid path
    int partialPath[lengthOfPath];
    int minPath[lengthOfPath];  //holds the shortest path based on the weights of the path
    int adjRowPtr[M*N1+1];  //adjusted rowPtr, adjusted column index and
    int Count[M*N1]; //holds the amount of edges coming from a node
    int adjCount[M*N1]; //Count after 2 random rows have been removed
    int isInvalid[M];   //the isInvalid array holds whether a stick has been used in the current path already
    int toRemove[NE];  //used to remove rows from cumulative data structure. each 1 value corresponds to columnIndex and Weights that need to be deleted
    int rowsToRemove[numToRemove];
    int rowsNotToRemove[lengthOfPath];

    double minWtEdges[minEdgesToKeep*5];        //minimum edges to keep from the linear array
    double randMinWtEdges[randMinEdges*5];      //a random subset of the subsetMinEdges

    double pathEdges[lengthOfPath*5-5];
    int removeProbability[N];
    int removeProbabilitySorted[N];
    int removeSubset[numToRemove*2-1];

    //not enough space in stack, so must allocate the rest of the arrays to the heap
    double *subsetMinWtEdges;//a subset of the lowest edges from minEdgesToKeep
    subsetMinWtEdges = (double *)malloc(sizeof(double)*(subsetMinEdges*5));
    int *adjColumnIndex;//ColumnIndex array after 2 random rows have been removed
    adjColumnIndex = (int *)malloc(sizeof(int)*(NE));
    double *adjWtArray;//Weight array after 2 random rows have been removed
    adjWtArray = (double *)malloc(sizeof(double)*(NE));
    int *rowPtr; //array used for counting total edges coming from a node. Calculate by adding values of Count
    rowPtr = (int *)malloc(sizeof(int)*(M*N1+1));
    double *WtArray; //holds every weight from file
    WtArray = (double *)malloc(sizeof(double)*(NE));
    int *columnIndex;  //holds position of every node that receives an edge
    columnIndex = (int *)malloc(sizeof(int)*(NE));
    double *adjustedArr;    // array holding values of LinearArray but adjusted according to the random row deletion, this array is commented out at the moment
    adjustedArr = (double *)malloc(sizeof(double)*(NE*inputsPerLine));

    //initializes all arrays that need to be
    initializeArr( minPath, path, isInvalid, adjCount, adjRowPtr, Count, rowPtr, adjColumnIndex, adjustedArr, toRemove, keptPaths, rowsToRemove, minWtEdges);

    //pickBestToRemove(LinearArray, removeProbability, removeProbabilitySorted, rowsToRemove);
    //createSubsetRemovedRows(LinearArray, removeProbability, removeProbabilitySorted, rowsToRemove, removeSubset);
    //createRemovedSubsetProbabilistic(removeProbability, removeProbabilitySorted, rowsToRemove, removeSubset);

    rowsToRemove[0] = 8;
    rowsToRemove[1] = 13;

    //rowsToRemove[0] = 8; //8, 8, 8, 8
    //rowsToRemove[1] = 14;//14, 14, 15, 14
    //rowsToRemove[2] = 15;//17, 15, 17, 15
    //rowsToRemove[3] = 17;//19, 17, 19, 17
    //rowsToRemove[4] = 19;//20, 20, 20, 19


    //rowsToRemove[0] = 2;
    //rowsToRemove[1] = 5;
    //rowsToRemove[2] = 8;
    //rowsToRemove[3] = 11;
    //rowsToRemove[4] = 16;
   // rowsToRemove[5] = 17;
   // rowsToRemove[6] = 18;
   // rowsToRemove[7] = 19;
   // rowsToRemove[8] = 20;


    //rowsToRemove[0] = 1;
    //rowsToRemove[1] = 10;

    //rowsToRemove[0] = -1;

    //rowsToRemove[0] = 3;
    //rowsToRemove[1] = 9;
    //rowsToRemove[2] = 14;
    //rowsToRemove[3] = 17;

    //rowsToRemove[0] = 6;
    //rowsToRemove[1] = 9;

    //rowsToRemove[0] =2; //2,2,2,1
    //rowsToRemove[1] = 3; //3,3,4,4
    //rowsToRemove[2] = 11; //11,8,11,10
    //rowsToRemove[3] = 14; //14,11,14,11
    //rowsToRemove[4] = 15; //15,14,15,15
    //rowsToRemove[0] = -1;

    //rowsToRemove[0] = 1;
    //rowsToRemove[1] = 3;
    //rowsToRemove[2] = 11;
    //rowsToRemove[3] = 14;
    //rowsToRemove[4] = 15;

    //rowsToRemove[0] = 1;
    //rowsToRemove[1] = 5;

    //rowsToRemove[0] = 3; //3, 5, 5, 5
    //rowsToRemove[1] = 5; //5, 7, 7, 7
    //rowsToRemove[2] = 11; //11,11, 12, 9
/*
    bool again = false;
    do{
    //randomly finds the a given amount rows that will be removed
    again = false;
    printf("Rows to remove: \n");
    randomRemoval(rowsToRemove);
    for(i = 0; i < numToRemove; i++)
    {
        printf("%d ", rowsToRemove[i]);
    }
    printf("\n");

    setUpToRemove(LinearArray, removeProbability);
    for(i = 0; i < N; i++)
    {
        if(removeProbability[i] == 0)
        {
            for(j = 0; j < numToRemove; j++)
            {
                again = true;
                if(rowsToRemove[j] == i)
                {
                    again = false;
                    break;
                }
            }
        }
    }
    }
    while(again == true);
*/
    //creates a set of low weight edges with the rows to be removed not present
    constructSetRemoved(minEdgesToKeep, minWtEdges , LinearArray, rowsToRemove, rowsNotToRemove);
    //printMinWtEdges(minWtEdges, minEdgesToKeep);
    //creates a subset of the MinWtEdges
    minSelectSet(minWtEdges, subsetMinEdges, subsetMinWtEdges);
    //printSubset(subsetMinEdges, subsetMinWtEdges);
    //randomly selects a subset of the subset of the low weight edges, this subset is size 1 at the moment
    randomSelectSet(subsetMinEdges, subsetMinWtEdges, randMinWtEdges);
    //printRandMinSet(randMinWtEdges, randMinEdges);

    //creates an array holding all the rows that will not be removed
    createRowsNotToRemove(rowsNotToRemove, rowsToRemove);
    //printRowsNotToRemove()
    //creates three arrays that can be used to find the values of LinearArray more efficiently
    createCompoundArr(LinearArray, WtArray, columnIndex, Count);
    //creates the rowPtr from the Count array
    createRowPtr(rowPtr, Count);
    //removes rows based on the random numbers we generated earlier
    removingRows(adjColumnIndex, toRemove, rowPtr, adjRowPtr, WtArray, columnIndex, adjWtArray, rowsToRemove, rowsNotToRemove);
    //creates the adjusted count after all of the rows have been removed. Count is generated from the rowPtr this time
    createAdjCount(adjCount, adjRowPtr);

    //print functions previously used to verify that all the arrays are properly made
    //printLinearArray(LinearArray);
    //printAdjCount(adjCount);
    //printAdjRowPtr(rowPtr);
    //printAdjColumn(adjColumnIndex, adjRowPtr);

    //creates arrays after adjCount has been made
    int SecondValidityCheck[findLargestCount(Count)+1];
    double probability[findLargestCount(Count)+1];

    ///pathsWithoutRowsRemoved(path, 2, wtsForChoosing, SecondValidityCheck, WtArray, rowPtr, Count, columnIndex,  probability, isInvalid, adjCount, adjColumnIndex, adjRowPtr, adjWtArray);
    //int l = 0;
    //for(l = 0; l < 140000; l++)
    //pathsWithoutRowsRemoved2(path, 2, wtsForChoosing, SecondValidityCheck, WtArray, rowPtr, Count, columnIndex,  probability, isInvalid, adjCount, adjColumnIndex, adjRowPtr, adjWtArray, keptPaths);
    //printTopPaths(keptPaths);

    fixMinWtSubset(partialPath, randMinWtEdges, isInvalid, adjCount, adjColumnIndex, adjRowPtr, adjWtArray, subsetMinWtEdges, pathEdges, keptPaths, Count);


    //chooses edges in a deterministic way and attempts to finish the path
    //CompletePathDeterministic(subsetMinWtEdges, randMinWtEdges,  partialPath, rowsToRemove, adjRowPtr, adjColumnIndex, isInvalid, adjCount, adjWtArray, keptPaths);


    //constructs a specific amount of paths, only using edges from the low weight subset
    printf("Constructed paths from low weight edge subset:\n");
    createPathsFromSubset(partialPath, randMinWtEdges, isInvalid, adjCount, adjColumnIndex, adjRowPtr, adjWtArray, subsetMinWtEdges, pathEdges, keptPaths, 100);
    printTopPaths(keptPaths);
    //resetKeptPaths(keptPaths, uniquePaths);

    //constructs a specific amount of paths, using all edges, but begins with a randomly chosen edge from the low weight subset
    //printf("Constructed paths from one edge chosen randomly from the low weight subset\n");
    //createPathsFromOneEdge(subsetMinEdges, subsetMinWtEdges, randMinWtEdges,  partialPath, rowsToRemove, adjRowPtr, adjColumnIndex,  randMinEdges,  isInvalid, adjCount, adjWtArray, keptPaths, probability, wtsForChoosing, 10000);
    //printTopPaths(keptPaths);
    //resetKeptPaths(keptPaths, uniquePaths);


    //finds a specified amount of valid paths based using greedy method and assigning a probability of |Wmax-W|+Delta to each possible edge
    //printf("Constructed paths from all edges using greedy method |Wmax-W|:\n");
    //findPaths(path, isInvalid, adjCount, adjWtArray, adjRowPtr, adjColumnIndex, minPath, keptPaths, wtsForChoosing, SecondValidityCheck, probability, 1);
    //printTopPaths(keptPaths);
    //resetKeptPaths(keptPaths, uniquePaths);

    //finds a specified amount of valid paths based using greedy method and assigning a probability of 1/W^x to each possible edge where x is chosen by the user
    //printf("Constructed paths from all edges using greedy method 1/W^%f :\n", wtsForChoosing);
    //findPaths(path, isInvalid, adjCount, adjWtArray, adjRowPtr, adjColumnIndex, minPath, keptPaths, wtsForChoosing, SecondValidityCheck, probability, 2);
    //printTopPaths(keptPaths);


    fclose(input);
    return 0;
}
//constructs paths from all edges, but does not remove any rows before creating these paths
void pathsWithoutRowsRemoved(int path[], int tempChoice, double wtsForChoosing, int SecondValidityCheck[], double WtArray[], int rowPtr[], int Count[], int columnIndex[], double probability[], int isInvalid[],  int adjCount[], int adjColumnIndex[], int adjRowPtr[], double adjWtArray[])
{
    int wrong = 0;
    int startingRow = 0;    //holds randomly selected starting row
    int startingNum = 0;    //holds randomly selected starting stick
    int attemptsCount = 0;  //amount of times it takes to create a valid partial path
    int numSkipped = 0;     //the amount of skipped rows at a present point in the path construction
    bool tooManySkipped = false;    //if tooManySkipped is true, a new nextValid node must be found because the current node skips too many rows
    bool skippedAllRows = false;    //if this variable is true, we have skipped the maximum amount of rows possible
    bool endOfPath = false;         //used to signify that the end of the path has been reached
    bool lastValue = true;

    do{
        for(i = 0; i < lengthOfPath; i++)
        {
            path[i] = 0;
        }
        attemptsCount = 0;
        numSkipped = 0;
        tooManySkipped = false;
        skippedAllRows = false;
        endOfPath = false;
        lastValue = true;
        //randomly finds where the path should start
        startingRow = rand() % N;
        startingNum = rand() % M;
        wrong = 0;
        //adds the random start of the path to the path array in the correct position
        if(startingRow > numToRemove)
        {
            path[startingRow-numToRemove] = startingRow * M + startingNum;
            repeatedStick(isInvalid, startingRow * M + startingNum);//changes isInvalid to 1 if stick has already been used
            //printf("\n%d ", path[startingRow-numToRemove]);
            startingRow -= numToRemove;

        }
        else
        {
            path[startingRow] = startingRow * M + startingNum;
            repeatedStick(isInvalid, startingRow * M + startingNum);
            //printf("\n%d ", path[startingRow]);
        }


        for(i = startingRow+1; i < lengthOfPath; i++)
        {
            //resets array that holds the possible choices for the next valid part of the path
            reset2ndValidity(Count, path, SecondValidityCheck);

            //sets up a probability array that helps choose what the next node should be
            if(wtsForChoosing != 0)
            {
                if(tempChoice == 1)
                    normalizeByMax(Count, probability, WtArray, rowPtr, path, wtsForChoosing);
                if(tempChoice == 2)
                    initializeProbabilityCorrectly(Count, probability, WtArray, rowPtr,  path, wtsForChoosing);
            }
            //loop that attempts to find the next node
            do{
                    tooManySkipped = false;
                    attemptsCount++;
                    //if every valid edge from the node has been tried and has been determined invalid, the current path is invalid and must be restarted
                    triedAllOptions(Count, path, SecondValidityCheck);

                    //we call the path invalid if we have already attempted 1000 times
                    if(attemptsCount > invalidLimit)
                    {
                        invalid = true;
                        attemptsCount = 0;
                    }

                    //resets the path if incalid is true of Count is zero = 1
                    //if invalid is true or all values have been selected(CountisZero) then the path must be started over. All changed values must be set to their original.
                    if(invalid == true || CountisZero == 1)
                    {
                        skippedAllRows = false;
                        numSkipped = 0;
                        runningWeightTotal = 0;
                        CountisZero = 0;
                        invalidCount++;
                        reset2ndValidity(Count, path, SecondValidityCheck);
                        //resets path and isInvalid
                        for(j = 0; j < M; j++)
                        {
                            if(j < lengthOfPath)
                            {
                                path[j] = 0;
                            }
                            isInvalid[j] = 0;
                        }
                        startingRow = rand() % N;
                        startingNum = rand() % M;
                        //adds the random start of the path to the path array in the correct position
                        if(startingRow > numToRemove)
                        {
                            path[startingRow-numToRemove] = startingRow * M + startingNum;
                            repeatedStick(isInvalid, startingRow * M + startingNum);//changes isInvalid to 1 if stick has already been used
                            //printf("\n%d ", path[startingRow-numToRemove]);
                            startingRow -= numToRemove;

                        }
                        else
                        {
                            path[startingRow] = startingRow * M + startingNum;
                            repeatedStick(isInvalid, startingRow * M + startingNum);
                            //printf("\n%d ", path[startingRow]);
                        }
                        i = startingRow+1;
                        if(path[i-1] > M * (N-1))
                        {
                            endOfPath = true;
                        }

                    }

                    //if end of path is true, we want to exit this loop because we have reached the end of the path already
                    if(endOfPath != true)
                    {
                        //we can specify which function we want to use based on weights
                        if(wtsForChoosing != 0)
                        {
                            if(tempChoice == 1)
                                normalizeByMax(Count, probability, WtArray, rowPtr, path, wtsForChoosing);
                            if(tempChoice == 2)
                                initializeProbabilityCorrectly(Count, probability, WtArray, rowPtr,  path, wtsForChoosing);
                        }

                        //if this statement is false, we have an invalid path because when count is equal to 0 we have no valid edges coming from this node
                        if((Count[path[i-1]]) != 0)
                        {
                            if(wtsForChoosing == 0)
                                randomTemp = (rand() % (Count[path[i-1]]));//randomTemp is a random variable between 0 and how many edges are coming from the previous node in the path.
                            else
                                correctBiasedChoice(probability, Count, path, WtArray, rowPtr);
                        }
                        else
                            CountisZero = 1;    //when CountisZero is equal to 1, we have an invalid path

                        //randomtemp is either found by using a random number or letting correctBiasedChoice adjust it
                        //nextValid holds the next value of the valid path
                        //printf("%d ", (adjRowPtr[path[i-1]]));
                        nextValid = columnIndex[randomTemp + rowPtr[path[i-1]]];

                        //checks if we have skipped too many rows, if it is true, we want to rechoose the current node
                        if(numSkipped + (nextValid/M - (path[i-1]/M+1)) > numToRemove)
                        {
                            tooManySkipped = true;
                        }
                        //signifies that this random number has already been selected
                        SecondValidityCheck[randomTemp] = 1;
                    }
                    //printf("aaaaaaa %d %d", isInvalid[nextValid % M], CountisZero);
                }
                while((isInvalid[nextValid % M] == 1 || CountisZero == 1 || tooManySkipped == true) && endOfPath == false);

                //this is only meant for when the path is still continuing, therefore we skip it if we are at the endofpath
                if(endOfPath != true)
                {
                    //changes validity array that determines if a stick has been selected already
                    CountisZero = 0;
                    repeatedStick(isInvalid, (nextValid%M));
                    attemptsCount = 0;

                    //prints valid path up to the index
                    path[i] = nextValid;
                    //printf("%d ", path[i]);
                    //checks that the number of lines skipped matches the number of rows to remove
                    numSkipped += (path[i]/M - (path[i-1]/M+1));
                    if(numSkipped == numToRemove)
                    {
                        skippedAllRows = true;
                    }
                }
                //used when we have reached the end of the path, but the node values are not high enough, we adjust the path by moving each value closer to the front by one and then finding the last part of the path
                if(i == lengthOfPath-1 && path[i] < M *(N-1)-1)
                {
                    for(j = 0; j < lengthOfPath-1; j++)
                    {
                        path[j] = path[j+1];
                    }
                    i = lengthOfPath-2;
                }
                //signals the end of the path, breaks the loop in progress
                if(path[i] > M * (N-1))
                {
                    i = lengthOfPath;
                }


        }
        int savedIsInvalid[M];
        for(i = 0; i < M; i++)
        {
            savedIsInvalid[i] = isInvalid[i];
        }

        //fixes the path in the correct position
        while(path[lengthOfPath-1] == 0)
        {
            for(i = lengthOfPath-1; i > 0; i--)
            {
                path[i] = path[i-1];
            }
        }

        int end = 0;    //the start of the current path and the end of the front end of the path
        for(i = 0; i < lengthOfPath; i++)
        {
            if(path[i] != 0)
            {
                end = i;
                i = lengthOfPath;
            }
        }


        printf("\n");
        for(i = 0; i < lengthOfPath; i++)
        {
            printf("%d ", path[i]);
        }
        printf("\n");
        printf("numSkipped: %d ", numSkipped);


        int savedNumSkipped = numSkipped;
        CountisZero = 0;
        invalid = false;
        tooManySkipped = false;
        firstInPath(path);//finds the first value of the valid path
        //printf("%d ", path[0]);
        repeatedStick(isInvalid, randomTemp);//changes isInvalid to 1 if stick has already been used


        for(i=1; i<end-1; i++)//finds the rest of the values of the randomly generated valid path
        {
            //sets all values of array to 0. This signifies that none of the random values have been chosen yet
            reset2ndValidity(Count, path, SecondValidityCheck);
            //we can specify which function we want to use based on weights
            if(wtsForChoosing != 0)
            {
                if(tempChoice == 1)
                normalizeByMax(Count, probability, WtArray, rowPtr,  path, wtsForChoosing);
                if(tempChoice == 2)
                initializeProbabilityCorrectly(Count, probability, WtArray, rowPtr,  path, wtsForChoosing);
            }


            do  //attempts to find the next valid node in the path
            {
                tooManySkipped = false;
                //if finding the next edge takes more than 1000 tries, we call the path invalid. There might be a valid path, but taking this long means that it will have a high total weight
                attemptsCount++;
                //if every valid edge from the node has been tried and has been determined invalid, the current path is invalid and must be restarted
                triedAllOptions(Count, path, SecondValidityCheck);
                //we call the path invalid if we have already attempted 1000 times
                if(attemptsCount > invalidLimit)
                {
                    invalid = true;
                    attemptsCount = 0;
                }

                //if invalid is true or all values have been selected(CountisZero) then the path must be started over. All changed values must be set to their original.
                if(invalid == true || CountisZero == 1)
                {
                    wrong++;
                    if(wrong > 300)
                        break;

                    //printf("%d ", wrong);
                    skippedAllRows = false;
                    numSkipped = savedNumSkipped;
                    //pathHasRestarted = true;
                    //resets variables that were changed during path construction
                    runningWeightTotal = 0;
                    CountisZero = 0;
                    //adds to invalidCount because the path was restarted
                    invalidCount++;
                    //deletes all values of SecondValidityCheck because no random values have been selected yet
                    reset2ndValidity(adjCount, path, SecondValidityCheck);
                    //resets path and isInvalid
                    for(j = 0; j < M; j++)
                    {
                        if(j < end)
                        {
                            path[j] = 0;
                        }
                        isInvalid[j] = savedIsInvalid[j];
                    }
                    //must recreate first value of the path
                    firstInPath(path);
                    repeatedStick(isInvalid, randomTemp);
                    //printf("%d ", path[0]);
                    //i is set to 1 because we just found the first in path
                    i =1;
                }

                //we can specify which function we want to use based on weights
                if(wtsForChoosing != 0)
                {
                    if(tempChoice == 1)
                    normalizeByMax(Count, probability, WtArray, rowPtr,  path, wtsForChoosing);
                    if(tempChoice == 2)
                    initializeProbabilityCorrectly(Count, probability, WtArray, rowPtr,  path, wtsForChoosing);
                }


                //if this statement is false, we have an invalid path because when count is equal to 0 we have no valid edges coming from this node
                if((Count[path[i-1]]) != 0)
                {
                    if(wtsForChoosing == 0)
                        randomTemp = (rand() % (Count[path[i-1]]));//randomTemp is a random variable between 0 and how many edges are coming from the previous node in the path.
                    else
                        correctBiasedChoice(probability, Count, path, WtArray, rowPtr);
                }
                else
                    CountisZero = 1;    //when CountisZero is equal to 1, we have an invalid path

                //randomtemp is either found by using a random number or letting correctBiasedChoice adjust it
                //nextValid holds the next value of the valid path
                nextValid = columnIndex[randomTemp + rowPtr[path[i-1]]];
                //printf("%d ", nextValid);
                //signifies that this random number has already been selected
                SecondValidityCheck[randomTemp] = 1;

                //checks if we have skipped too many rows, if it is true, we want to rechoose the current node
                if(numSkipped + (nextValid/M - (path[i-1]/M+1)) > numToRemove)
                {
                    tooManySkipped = true;
                }

                //for the last value that connects the two partial paths
                /*
                if(i == end-1)
                {
                    if(!edgeExists(nextValid, path[end], adjRowPtr, adjColumnIndex, adjWtArray, adjCount))
                    {
                        lastValue = false;
                    }
                    else
                        lastValue = true;
                }
                if(lastValue == true && i == end-1)
                printf("%d:%d:%d ", isInvalid[nextValid % M], CountisZero, tooManySkipped);
                */
            }
            while( isInvalid[nextValid % M] == 1 || CountisZero == 1 || tooManySkipped == true || lastValue == false);//checks if nextValid is valid, loop again if nextValid is not part of the valid path. Or loop again if no edges are coming from the node

            if(wrong > 300)
                break;
            //changes validity array that determines if a stick has been selected already
            CountisZero = 0;
            repeatedStick(isInvalid, (nextValid%M));
            attemptsCount = 0;



            //prints valid path up to the index
            path[i] = nextValid;
            //printf("%d ", path[i]);

            //printf("%d ", numSkipped);
            numSkipped += (path[i]/M - (path[i-1]/M+1));
            //printf("%d ", numSkipped);

            if(numSkipped == numToRemove)
            {
                skippedAllRows = true;
            }
        }

    }while(wrong > 300);

    printf("\n");
    for(i = 0; i < lengthOfPath; i++)
    {
        printf("%d ", path[i]);
    }
    printf("\t%f ", findWtOfPath(path, adjColumnIndex, adjWtArray, adjRowPtr));

    printf("\n");
    printf("numSkipped: %d \n", numSkipped);




}
//version 2 which should be faster
void pathsWithoutRowsRemoved2(int path[], int tempChoice, double wtsForChoosing, int SecondValidityCheck[], double WtArray[], int rowPtr[], int Count[], int columnIndex[], double probability[], int isInvalid[],  int adjCount[], int adjColumnIndex[], int adjRowPtr[], double adjWtArray[], double keptPaths[])
{
    int wrong = 0;
    int startingRow = 0;    //holds randomly selected starting row
    int startingNum = 0;    //holds randomly selected starting stick
    int attemptsCount = 0;  //amount of times it takes to create a valid partial path
    int numSkipped = 0;     //the amount of skipped rows at a present point in the path construction
    bool tooManySkipped = false;    //if tooManySkipped is true, a new nextValid node must be found because the current node skips too many rows
    bool skippedAllRows = false;    //if this variable is true, we have skipped the maximum amount of rows possible
    bool endOfPath = false;         //used to signify that the end of the path has been reached
    bool lastValue = true;
    bool valid = false;
    bool choicesAvailable = true;
    bool alreadyTried = false;
    int currentRow = 0;
    int currentRowEnd = 0;
    int possibleChoice[300];
    int possibleChoiceMarker[300];
    int savedIsInvalid[M];
    int k = 0;
    int randPick = 0;
    bool restart = false;
    int l = 0;

    //loops until we find a valid path
    do{
        //restart variable controls the do-while loop
        restart = false;
        alreadyTried = false;
        //makes sure that path has no values in it
        for(i = 0; i < lengthOfPath; i++)
        {
            path[i] = 0;
        }
        //resets the repeated stick checking array
        for(i = 0; i < M; i++)
        {
            isInvalid[i] = 0;
        }
        //resets variable
        attemptsCount = 0;
        numSkipped = 0;
        tooManySkipped = false;
        skippedAllRows = false;
        endOfPath = false;
        lastValue = true;
        //randomly finds where the path should start
        startingRow = rand() % N1;
        startingNum = rand() % M;
        wrong = 0;
        //adds the random start of the path to the path array in the correct position
        if(startingRow > numToRemove)
        {
            path[startingRow-numToRemove] = startingRow * M + startingNum;
            repeatedStick(isInvalid, startingNum);//changes isInvalid to 1 if stick has already been used
            //printf("\n%d ", path[startingRow-numToRemove]);
            startingRow -= numToRemove;

        }
        else
        {
            path[startingRow] = startingRow * M + startingNum;
            repeatedStick(isInvalid, startingNum);
            //printf("\n%d ", path[startingRow]);
        }

        //loop that finishes from random point to end of path
        for(i = startingRow+1; i < lengthOfPath; i++)
        {
            //resets array that holds the possible choices for the next valid part of the path
            reset2ndValidity(Count, path, SecondValidityCheck);

            //sets up a probability array that helps choose what the next node should be
            if(wtsForChoosing != 0)
            {
                if(tempChoice == 1)
                    normalizeByMax(Count, probability, WtArray, rowPtr, path, wtsForChoosing);
                if(tempChoice == 2)
                    initializeProbabilityCorrectly(Count, probability, WtArray, rowPtr,  path, wtsForChoosing);
            }
            //loop that attempts to find the next node
            do{
                    tooManySkipped = false;
                    attemptsCount++;
                    //if every valid edge from the node has been tried and has been determined invalid, the current path is invalid and must be restarted
                    triedAllOptions(Count, path, SecondValidityCheck);

                    //we call the path invalid if we have already attempted 1000 times
                    if(attemptsCount > invalidLimit)
                    {
                        invalid = true;
                        attemptsCount = 0;
                    }

                    //resets the path if incalid is true of Count is zero = 1
                    //if invalid is true or all values have been selected(CountisZero) then the path must be started over. All changed values must be set to their original.
                    if(invalid == true || CountisZero == 1)
                    {
                        skippedAllRows = false;
                        numSkipped = 0;
                        runningWeightTotal = 0;
                        CountisZero = 0;
                        invalidCount++;
                        reset2ndValidity(Count, path, SecondValidityCheck);
                        //resets path and isInvalid
                        for(j = 0; j < M; j++)
                        {
                            if(j < lengthOfPath)
                            {
                                path[j] = 0;
                            }
                            isInvalid[j] = 0;
                        }
                        startingRow = rand() % N1;
                        startingNum = rand() % M;
                        //adds the random start of the path to the path array in the correct position
                        if(startingRow > numToRemove)
                        {
                            path[startingRow-numToRemove] = startingRow * M + startingNum;
                            repeatedStick(isInvalid, startingNum);//changes isInvalid to 1 if stick has already been used
                            //printf("\n%d ", path[startingRow-numToRemove]);
                            startingRow -= numToRemove;

                        }
                        else
                        {
                            path[startingRow] = startingRow * M + startingNum;
                            repeatedStick(isInvalid, startingNum);
                            //printf("\n%d ", path[startingRow]);
                        }
                        i = startingRow+1;
                        //printf(":%d ", (M*N1));
                        //printf("1:%d ", path[i-1]);
                        if(path[i-1] > M * (N1))
                        {
                            endOfPath = true;
                        }

                    }

                    //if end of path is true, we want to exit this loop because we have reached the end of the path already
                    if(endOfPath != true)
                    {
                        //we can specify which function we want to use based on weights
                        if(wtsForChoosing != 0)
                        {
                            if(tempChoice == 1)
                                normalizeByMax(Count, probability, WtArray, rowPtr, path, wtsForChoosing);
                            if(tempChoice == 2)
                                initializeProbabilityCorrectly(Count, probability, WtArray, rowPtr,  path, wtsForChoosing);
                        }

                        //if this statement is false, we have an invalid path because when count is equal to 0 we have no valid edges coming from this node
                        if((Count[path[i-1]]) != 0)
                        {
                            if(wtsForChoosing == 0)
                                randomTemp = (rand() % (Count[path[i-1]]));//randomTemp is a random variable between 0 and how many edges are coming from the previous node in the path.
                            else
                                correctBiasedChoice(probability, Count, path, WtArray, rowPtr);
                        }
                        else
                            CountisZero = 1;    //when CountisZero is equal to 1, we have an invalid path

                        //randomtemp is either found by using a random number or letting correctBiasedChoice adjust it
                        //nextValid holds the next value of the valid path
                        //printf("%d ", path[i-1]);
                        //printf("%d ", (rowPtr[path[i-1]]));
                        nextValid = columnIndex[randomTemp + rowPtr[path[i-1]]];

                        //checks if we have skipped too many rows, if it is true, we want to rechoose the current node
                        if(numSkipped + (nextValid/M - (path[i-1]/M+1)) > numToRemove)
                        {
                            tooManySkipped = true;
                        }
                        //signifies that this random number has already been selected
                        SecondValidityCheck[randomTemp] = 1;
                    }
                    //printf("aaaaaaa %d %d", isInvalid[nextValid % M], CountisZero);
                }
                while((isInvalid[nextValid % M] == 1 || CountisZero == 1 || tooManySkipped == true) && endOfPath == false);

                //this is only meant for when the path is still continuing, therefore we skip it if we are at the endofpath
                if(endOfPath != true)
                {
                    //changes validity array that determines if a stick has been selected already
                    CountisZero = 0;
                    repeatedStick(isInvalid, (nextValid%M));
                    attemptsCount = 0;

                    //prints valid path up to the index
                    path[i] = nextValid;
                    //printf("%d ", path[i]);
                    //checks that the number of lines skipped matches the number of rows to remove
                    numSkipped += (path[i]/M - (path[i-1]/M+1));
                    if(numSkipped == numToRemove)
                    {
                        skippedAllRows = true;
                    }
                }
                //used when we have reached the end of the path, but the node values are not high enough, we adjust the path by moving each value closer to the front by one and then finding the last part of the path
                if(i == lengthOfPath-1 && path[i] < M *(N-1)-1)
                {
                    for(j = 0; j < lengthOfPath-1; j++)
                    {
                        path[j] = path[j+1];
                    }
                    i = lengthOfPath-2;
                }
                //printf("2:%d ", path[i]);
                //signals the end of the path, breaks the loop in progress
                if(path[i] > M * (N1))
                {
                    i = lengthOfPath;
                }


            }
        //used for when path has randomly started at first position, but did not skip enough rows
        if(path[0] != 0 && numSkipped != numToRemove)
        {
            if((path[0]%M % 2) == 1)
            {
                isInvalid[path[0]%M] = 0;
                isInvalid[path[0]%M-1] = 0;
            }

            if((path[0]%M % 2) == 0)
            {
                isInvalid[path[0]%M] = 0;
                isInvalid[path[0]%M+1] = 0;
            }
            path[0] = 0;
        }
        //saves the current position of the stick so that when reseting the path below, we can come back to these position
        for(i = 0; i < M; i++)
        {
            savedIsInvalid[i] = isInvalid[i];
        }

        //fixes the path in the correct position
        while(path[lengthOfPath-1] == 0)
        {
            for(i = lengthOfPath-1; i > 0; i--)
            {
                path[i] = path[i-1];
            }
        }

        int end = 0;    //the start of the current path and the end of the front end of the path
        for(i = 0; i < lengthOfPath; i++)
        {
            if(path[i] != 0)
            {
                end = i;
                i = lengthOfPath;
            }
        }


        //printf("\n");
        //for(i = 0; i < lengthOfPath; i++)
        //{
        //    printf("%d ", path[i]);
        //}
        //printf("\n");
        //printf("numSkipped: %d ", numSkipped);



        //attempting to complete path backwards
        for(i = end-1; i >= 0; i--)
        {
            for(j = 0; j < 100; j++)
            {
                possibleChoice[i] = 0;
                possibleChoiceMarker[i] = 0;
            }
            k = 0;
            valid = false;

            currentRowEnd = path[i+1]/M;
            //printf("%d ", currentRowEnd);
            currentRow = currentRowEnd - (numToRemove-numSkipped+1);
            if(currentRow < 0)
                currentRow = 0;

            //printf("%d ", currentRow);
            //finds all possible nodes that could come before the current path
            for(j = rowPtr[currentRow*M]; j < rowPtr[currentRowEnd*M]; j++)
            {
                //printf("%d:%d ", columnIndex[j], path[i+1]);
                if(columnIndex[j] == path[i+1])
                {
                    for(l = 0; l < M*N1; l++)
                    {
                        if(j > rowPtr[l] && j < rowPtr[l+1])
                        {
                            possibleChoice[k] = l;
                            k++;
                            //printf("%d ", l);
                        }
                    }

                }
            }
            //printf("%d ", k);
            //attempts to find the next part of the path using the possible choices found aboce
            do{
                valid = false;
                //checks that there are choices available
                for(j = 0; j < k; j++)
                {
                    choicesAvailable = false;
                    if(possibleChoiceMarker[j] == 0)
                    {
                        choicesAvailable = true;
                        break;
                    }
                }
                if(choicesAvailable == false)
                {
                    //printf("TOO MANY");
                    restart = true;
                    for(j = 0; j < M; j++)
                    {
                        isInvalid[j] = savedIsInvalid[j];
                    }
                    break;
                }
                if(k == 0 && i == end-1)
                {
                    restart = true;
                    break;
                }
                if(k == 0 && i != end-1)
                {
                    i = end;
                    if(alreadyTried == true)
                    {
                        restart = true;
                    }
                    alreadyTried = true;
                    for(j = 0; j < M; j++)
                    {
                        isInvalid[j] = savedIsInvalid[j];
                    }
                    break;
                }

                do{
                    randPick = rand() % k;
                }while(possibleChoiceMarker[randPick] == 1);

                possibleChoiceMarker[randPick] = 1;
                valid = true;
            }while(isInvalid[possibleChoice[randPick] % M ] == 1);

            if(restart == true)
            {
                break;
            }

            if(valid == true)
            {
                path[i] = possibleChoice[randPick];
                //printf("%d ", path[i]);
                numSkipped += (path[i+1]/M)- (path[i]/M)-1;
                repeatedStick(isInvalid, path[i]%M);
            }

            if(i == 0 && numSkipped != numToRemove)
            {
                i = end;
            }

        }

        if(path[0] == path[1] || path[lengthOfPath-1] == path[lengthOfPath-2])
        {
            restart = true;
        }


    }while(restart == true);


    keepPath(keptPaths, path, findWtOfPath(path, columnIndex, WtArray, rowPtr));

/*
    printf("\n");
    for(i = 0; i < lengthOfPath; i++)
    {
        printf("%d ", path[i]);
    }
    printf("\tWeight: %f ", findWtOfPath(path, columnIndex, WtArray, rowPtr));
    printf("\n");
    printf("numSkipped: %d ", numSkipped);
*/
}
//version 3 will only build the path forward
void pathsWithoutRowsRemoved3(int path[], int tempChoice, double wtsForChoosing, int SecondValidityCheck[], double WtArray[], int rowPtr[], int Count[], int columnIndex[], double probability[], int isInvalid[],  int adjCount[], int adjColumnIndex[], int adjRowPtr[], double adjWtArray[], double keptPaths[])
{
    int wrong = 0;
    int startingRow = 0;    //holds randomly selected starting row
    int startingNum = 0;    //holds randomly selected starting stick
    int attemptsCount = 0;  //amount of times it takes to create a valid partial path
    int numSkipped = 0;     //the amount of skipped rows at a present point in the path construction
    bool tooManySkipped = false;    //if tooManySkipped is true, a new nextValid node must be found because the current node skips too many rows
    bool skippedAllRows = false;    //if this variable is true, we have skipped the maximum amount of rows possible
    bool endOfPath = false;         //used to signify that the end of the path has been reached
    bool lastValue = true;
    bool valid = false;
    bool choicesAvailable = true;
    int currentRow = 0;
    int currentRowEnd = 0;
    int possibleChoice[100];
    int possibleChoiceMarker[100];
    int k = 0;
    int randPick = 0;
    bool restart = false;
    int l = 0;



        //makes sure that path has no values in it
        for(i = 0; i < lengthOfPath; i++)
        {
            path[i] = 0;
        }
        //resets the repeated stick checking array
        for(i = 0; i < M; i++)
        {
            isInvalid[i] = 0;
        }
        //resets variable
        attemptsCount = 0;
        numSkipped = 0;
        tooManySkipped = false;
        skippedAllRows = false;
        endOfPath = false;
        lastValue = true;

            wrong = 0;

        firstInPath(path);
        repeatedStick(isInvalid, path[0]%M);

        //loop that finishes from random point to end of path
        for(i = 1; i < lengthOfPath; i++)
        {
            //resets array that holds the possible choices for the next valid part of the path
            reset2ndValidity(Count, path, SecondValidityCheck);

            //sets up a probability array that helps choose what the next node should be
            if(wtsForChoosing != 0)
            {
                if(tempChoice == 1)
                    normalizeByMax(Count, probability, WtArray, rowPtr, path, wtsForChoosing);
                if(tempChoice == 2)
                    initializeProbabilityCorrectly(Count, probability, WtArray, rowPtr,  path, wtsForChoosing);
            }
            //loop that attempts to find the next node
            do{
                    tooManySkipped = false;
                    attemptsCount++;
                    //if every valid edge from the node has been tried and has been determined invalid, the current path is invalid and must be restarted
                    triedAllOptions(Count, path, SecondValidityCheck);

                    //we call the path invalid if we have already attempted 1000 times
                    if(attemptsCount > invalidLimit)
                    {
                        invalid = true;
                        attemptsCount = 0;
                    }

                    //resets the path if incalid is true of Count is zero = 1
                    //if invalid is true or all values have been selected(CountisZero) then the path must be started over. All changed values must be set to their original.
                    if(invalid == true || CountisZero == 1)
                    {
                        skippedAllRows = false;
                        numSkipped = 0;
                        runningWeightTotal = 0;
                        CountisZero = 0;
                        invalidCount++;
                        reset2ndValidity(Count, path, SecondValidityCheck);
                        //resets path and isInvalid
                        for(j = 0; j < M; j++)
                        {
                            if(j < lengthOfPath)
                            {
                                path[j] = 0;
                            }
                            isInvalid[j] = 0;
                        }
                        firstInPath(path);
                        repeatedStick(isInvalid, path[0]%M);
                        i = 1;
                    }


                        //we can specify which function we want to use based on weights
                        if(wtsForChoosing != 0)
                        {
                            if(tempChoice == 1)
                                normalizeByMax(Count, probability, WtArray, rowPtr, path, wtsForChoosing);
                            if(tempChoice == 2)
                                initializeProbabilityCorrectly(Count, probability, WtArray, rowPtr,  path, wtsForChoosing);
                        }

                        //if this statement is false, we have an invalid path because when count is equal to 0 we have no valid edges coming from this node
                        if((Count[path[i-1]]) != 0)
                        {
                            if(wtsForChoosing == 0)
                                randomTemp = (rand() % (Count[path[i-1]]));//randomTemp is a random variable between 0 and how many edges are coming from the previous node in the path.
                            else
                                correctBiasedChoice(probability, Count, path, WtArray, rowPtr);
                        }
                        else
                            CountisZero = 1;    //when CountisZero is equal to 1, we have an invalid path

                        //randomtemp is either found by using a random number or letting correctBiasedChoice adjust it
                        //nextValid holds the next value of the valid path
                        //printf("%d ", path[i-1]);
                        //printf("%d ", (rowPtr[path[i-1]]));
                        nextValid = columnIndex[randomTemp + rowPtr[path[i-1]]];

                        //checks if we have skipped too many rows, if it is true, we want to rechoose the current node
                        if(numSkipped + (nextValid/M - (path[i-1]/M+1)) > numToRemove)
                        {
                            tooManySkipped = true;
                        }
                        //signifies that this random number has already been selected
                        SecondValidityCheck[randomTemp] = 1;

                    //printf("aaaaaaa %d %d", isInvalid[nextValid % M], CountisZero);
                }
                while((isInvalid[nextValid % M] == 1 || CountisZero == 1 || tooManySkipped == true));


                    //changes validity array that determines if a stick has been selected already
                    CountisZero = 0;
                    repeatedStick(isInvalid, (nextValid%M));
                    attemptsCount = 0;

                    //prints valid path up to the index
                    path[i] = nextValid;
                    //printf("%d ", path[i]);
                    //checks that the number of lines skipped matches the number of rows to remove
                    numSkipped += (path[i]/M - (path[i-1]/M+1));
                    if(numSkipped == numToRemove)
                    {
                        skippedAllRows = true;
                    }

            }

    //keepPath(keptPaths, path, findWtOfPath(path, columnIndex, WtArray, rowPtr));


    printf("\n");
    for(i = 0; i < lengthOfPath; i++)
    {
        printf("%d ", path[i]);
    }
    printf("\tWeight: %f ", findWtOfPath(path, columnIndex, WtArray, rowPtr));
    printf("\n");
    printf("numSkipped: %d ", numSkipped);

}
//fixes size of minWtSubset for certain circumstances
void fixMinWtSubset(int partialPath[], double randMinWtEdges[], int isInvalid[], int adjCount[], int adjColumnIndex[], int adjRowPtr[], double adjWtArray[], double subsetMinWtEdges[], double pathEdges[], double keptPaths[], int Count[])
{
    if(NE > 500)
    {
        subsetMinEdges = NE*.1;
        minEdgesToKeep = NE*.1;
        //findSubsetSize(partialPath, randMinWtEdges, isInvalid, adjCount, adjColumnIndex, adjRowPtr, adjWtArray, subsetMinWtEdges, pathEdges, keptPaths);
        findSubsetSizeBinary(partialPath, randMinWtEdges, isInvalid, adjCount, adjColumnIndex, adjRowPtr, adjWtArray, subsetMinWtEdges, pathEdges, keptPaths);
    }
    if(NE == subsetMinEdges)
    {
        int add = 0;
        int add2 = 0;
        for(i = 0; i < M*N1; i++)
        {
            add += Count[i];
            add2 += adjCount[i];
        }
        subsetMinEdges -= add-add2;
        minEdgesToKeep -= add-add2;
        //printMinWtEdges(minWtEdges, minEdgesToKeep);
    }
}
//finds a row to remove probabilistically, some flaws at the moment
void createRemovedSubsetProbabilistic(int removeProbability[], int removeProbabilitySorted[], int rowsToRemove[], int removeSubset[])
{
    double weightedRemove[N];
    double runningSum = 0;
    double sorted[N];

    for(i = 0; i < N; i++)
    {
        if(removeProbability[i] == 10000)
        {
            weightedRemove[i] = epsilon;
        }
        else
            weightedRemove[i] = removeProbability[i];
        sorted[i] = 0;
    }
    weightedRemove[0] = 1000;

    for(i = 0; i < N; i++)
    {
        runningSum += 1/(weightedRemove[i]+1);
        //printf("%f \n", weightedRemove[i]);
    }
    for(i = 0; i < N; i++)
    {
        weightedRemove[i] = (1/(weightedRemove[i]+1))/runningSum;
        sorted[i] = weightedRemove[i];
    }
    qsort(sorted, N, sizeof(double), cmpfunc);

    int k = 0;
    double runningPickNode = 0;
    double randNum = 0;
    //choose random number between zero and one
    randNum = ((double) rand()/RAND_MAX);
    //printf("%f ", randNum);
    //loop through every node
    for(j = 0; j < N; j++)
    {
        runningPickNode += sorted[j];
        //printf("%f ", runningPickNode);
        if(runningPickNode > randNum)
        {
            for(k = 0; k < N; k++)
            {
                if(sorted[j] == weightedRemove[k])
                {
                    printf("\n %d", k);
                }
            }

            break;
        }
    }
}
//creates a subset of possible rows to remove, then chooses them randomly
void createSubsetRemovedRows(double LinearArray[], int removeProbability[], int removeProbabilitySorted[], int rowsToRemove[], int removeSubset[])
{
    //counts how many times a row is used in the input file
    double runningSum = 0;
    double weightedRemove[N];
    setUpToRemove(LinearArray, removeProbability);
    removeProbability[0] = 10000;
    //creates an array that has these counts sorted
    for(i = 0; i < N; i++)
    {
        removeProbabilitySorted[i] = removeProbability[i];
        weightedRemove[i] = removeProbability[i];
    }
    qsort(removeProbabilitySorted, N, sizeof(int), cmpfuncInt);


    for(i = 0; i < N; i++)
    {
        printf("%f ", weightedRemove[i]);
    }
    //printf("\n\n");



    //picks numToRemove*2-1 lowest counted rows and places them in a subset
    int k = 0;
    for(i = 0; i < numToRemove*2-1; i++)
    {
        for(j = 0; j < N; j++)
        {
            if(removeProbabilitySorted[i] == removeProbability[j])
            {
                removeSubset[k] = j;
                removeProbability[j] = 10000;
                //printf("%d ", j);
                k++;
                j = N;
            }
        }
    }

    for(i = 0; i < numToRemove*2-1; i++)
    {
        printf("%d ", removeSubset[i]);
    }
    printf("\n\n");

    //creates an array used to make sure rows arent picked twice
    int temp = 0;
    int used[numToRemove*2-1];
    for(j = 0; j < numToRemove*2-1; j++)
    {
        used[j] = 0;
    }

    //picks the rows to remove randomly from the subset and prints it out, used makes sure that rows arent picked twice
    for(i = 0; i < 1000; i++)
    {
        do{
            temp = (rand() % (numToRemove*2-1));
        }while(used[temp] == 1);
        used[temp] = 1;

        printf("%d ", removeSubset[temp]);
        if((i+1) % 5 == 0)
        {
            printf("\n");
            for(j = 0; j < numToRemove*2-1; j++)
            {
                used[j] = 0;
            }
        }
    }

}
//finds the best subset size by generating a series of paths and changing the size of the subset in a binary manner to find the best fit for the input
void findSubsetSizeBinary(int partialPath[], double randMinWtEdges[], int isInvalid[], int adjCount[], int adjColumnIndex[], int adjRowPtr[], double adjWtArray[], double subsetMinWtEdges[], double pathEdges[], double keptPaths[])
{
    printf("finding size of minimum weight subset...\n");
    int bestSize = 0;
    double topWeight = 100000;
    double tmpAvgWt = 0;
    int index = 0;
    int lastSize = 0;
    int maxTooLow = 0;      //keeps track of the highest size that that the subset was deemed too small
    int minTooHigh = 10000; //keeps track of the lowest size the subset was deemed too big

    //loops a number of times each time adjusting the small weight subset size
    for(index = 0; index < 150; index++)
    {
        uniquePaths = 0;
        countTries = 0;
        tooManyTries = false;
        //creates a certain amount of paths and looks at the results
        createPathsFromSubset(partialPath, randMinWtEdges, isInvalid, adjCount, adjColumnIndex, adjRowPtr, adjWtArray, subsetMinWtEdges, pathEdges, keptPaths, 100);
        //if the subset cannot create the paths fast enough, make the subset bigger
        if(abs(minEdgesToKeep - lastSize) < 100)
        {

            break;
        }
        //printf(" %d ", uniquePaths);
        lastSize = minEdgesToKeep;

        //when the subset is too small
        if(uniquePaths < 95 || tooManyTries == true)
        {
            //if the current subset is bigger than maxTooLow, set maxTooLow to this subset size
            if(maxTooLow < minEdgesToKeep)
            {
                maxTooLow = minEdgesToKeep;
            }
            //if you have not reached a subset that is too big double the size
            if(minTooHigh == 10000)
            {
                minEdgesToKeep *= 2;
                subsetMinEdges *= 2;
                //if you ever go over the total amount of edges, set the subset size to the total amount of edges
                if(minEdgesToKeep > NE)
                {
                    minEdgesToKeep = NE;
                    subsetMinEdges = NE;
                }
            }
            //otherwise, change the size of the subset to the value between the mintoohigh and the current subset
            else
            {
                minEdgesToKeep = (minTooHigh + minEdgesToKeep)/2;
                subsetMinEdges = (minTooHigh + subsetMinEdges)/2;
            }

            resetKeptPaths(keptPaths, uniquePaths);
            //bestSize = minEdgesToKeep;
        }
        //if the subset is creating valid paths, save the best path and make the subset smaller
        else
        {
            //keep track of the average of the top 10 paths
            tmpAvgWt += keptPaths[(lengthOfPath+1)];
            for(j = 1; j < 10; j++)
            {
                tmpAvgWt += keptPaths[(lengthOfPath+1)+(lengthOfPath+2)*j];
                //printf("%f ", keptPaths[(lengthOfPath+1)+(lengthOfPath+2)*j]);
            }
            tmpAvgWt = tmpAvgWt/10;
            //if the top 10 paths average are less than the previous best average, set the best size to the current subset size
            if(topWeight > keptPaths[lengthOfPath+1])
            {
                topWeight = keptPaths[lengthOfPath+1];
                //printf("%f ", topWeight);
                bestSize = minEdgesToKeep;
            }
            //if this subset size is smaller than the minTooHigh value, set mintoohigh to the current subset size
            if(minTooHigh > minEdgesToKeep)
            {
                minTooHigh = minEdgesToKeep;
            }
            //binary search, so you want in between the current value and the highest lower bound
            minEdgesToKeep = (maxTooLow + minEdgesToKeep)/2;
            subsetMinEdges = (maxTooLow + subsetMinEdges)/2;

            resetKeptPaths(keptPaths, uniquePaths);
        }
        printf("%d ", minEdgesToKeep);
    }
    if(bestSize == 0)
        bestSize = NE;
    minEdgesToKeep = bestSize;
    subsetMinEdges = bestSize;
    printf("Size of subset: %d\n\n", bestSize);
}
//finds the best subset size by generating a series of paths and incrementing the size based on how the paths are structured
void findSubsetSize(int partialPath[], double randMinWtEdges[], int isInvalid[], int adjCount[], int adjColumnIndex[], int adjRowPtr[], double adjWtArray[], double subsetMinWtEdges[], double pathEdges[], double keptPaths[])
{
    //printf("%d\n", subsetMinEdges);
    int bestSize = 0;
    double topWeight = 100000;
    double tmpAvgWt = 0;
    int index = 0;

    //loops a number of times each time adjusting the small weight subset size
    for(index = 0; index < 150; index++)
    {
        uniquePaths = 0;
        countTries = 0;
        tooManyTries = false;
        //creates a certain amount of paths and looks at the results
        createPathsFromSubset(partialPath, randMinWtEdges, isInvalid, adjCount, adjColumnIndex, adjRowPtr, adjWtArray, subsetMinWtEdges, pathEdges, keptPaths, 100);
        //if the subset cannot create the paths fast enough, make the subset bigger
        //printf(" %d ", minEdgesToKeep);
        if(uniquePaths < 80 || tooManyTries == true)
        {
            subsetMinEdges += NE *.0005;
            minEdgesToKeep += NE *.0005;
            resetKeptPaths(keptPaths, uniquePaths);
            if(tooManyTries == true)
            {
                subsetMinEdges += NE *.01;
                minEdgesToKeep += NE *.01;
                index = 0;
            }
            bestSize = minEdgesToKeep;
        }
        //if the subset is creating valid paths, save the best path and make the subset smaller
        else
        {
            tmpAvgWt += keptPaths[(lengthOfPath+1)];
            subsetMinEdges -= NE *.0004;
            minEdgesToKeep -= NE *.0004;
            for(j = 1; j < 10; j++)
            {
                tmpAvgWt += keptPaths[(lengthOfPath+1)+(lengthOfPath+2)*j];
                //printf("%f ", keptPaths[(lengthOfPath+1)+(lengthOfPath+2)*j]);
            }
            tmpAvgWt = tmpAvgWt/10;

            if(topWeight > keptPaths[lengthOfPath+1])
            {
                topWeight = keptPaths[lengthOfPath+1];
                //printf("%f ", topWeight);
                bestSize = minEdgesToKeep + NE *.0004;
            }
            resetKeptPaths(keptPaths, uniquePaths);

        }
    }
    minEdgesToKeep = bestSize;
    subsetMinEdges = bestSize;
    printf("Size of subset: %d\n\n", bestSize);

}
//uses removeProbability to guess which rows should be removed
void pickBestToRemove(double LinearArray[], int removeProbability[], int removeProbabilitySorted[], int rowsToRemove[])
{
    if(numToRemove != 0)
    {
        setUpToRemove(LinearArray, removeProbability);
        //makes sure the first row isnt removed
        removeProbability[0] = 10000;
        //sort the removeProbability array and put it in removeProbabilitySorted
        for(i = 0; i < N; i++)
        {
            removeProbabilitySorted[i] = removeProbability[i];
        }
        int k = 0;
        qsort(removeProbabilitySorted, N, sizeof(int), cmpfuncInt);
        for(i = 0; i < N; i++)
        {
            //printf("%d ", removeProbability[i]);
        }

        //pick the rows that appear the least often
        for(i = 0; i < numToRemove; i++)
        {
            for(j = 0; j < N; j++)
            {
                if(removeProbabilitySorted[i] == removeProbability[j])
                {
                    rowsToRemove[k] = j;
                    removeProbability[j] = 10000;
                    //printf("%d ", j);
                    k++;
                    j = N;
                }
            }
        }
        qsort(rowsToRemove, numToRemove, sizeof(int), cmpfuncInt);
        for(i = 0; i < numToRemove; i++)
        {
            printf("%d ", rowsToRemove[i]);
        }
    }
    else
        rowsToRemove[0] = -1;
}
//sets up the remove probability array by adding one every time a row is used in the input file
void setUpToRemove(double linearArray[], int removeProbability[])
{
    for(i = 0; i < N; i++)
    {
        removeProbability[i] = 0;
    }
    for(i = 0; i < NE*inputsPerLine; i=i+inputsPerLine)
    {
        removeProbability[(int)linearArray[i]-1]++;
        removeProbability[(int)linearArray[i+2]-1]++;
    }
    for(i = 0; i < N; i++)
    {
        //printf("%d ", removeProbability[i]);
    }
}
//computes some of the variables by reading the input file before it is processed
void computeVariables(FILE *input)
{
    int lines = 1;
    int temp = 0;
    char ch = getc(input);
    char tempch = " ";
    while(ch != EOF)
    {
        //printf("%c ", ch);
        if ( ch == '\n')
        {
            break;
        }

        if(ch != ' ' && tempch == ' ')
        {
            //printf("%c ", ch);
            temp++;
        }


        tempch = ch;
        ch = getc(input);
    }
    //printf("%d", temp);
    inputsPerLine = temp;
    while(!feof(input))
    {
      ch = fgetc(input);
      if(ch == '\n')
      {
        lines++;
      }
    }
    //printf("%d\n", lines);
    NE = lines;
    subsetMinEdges = NE;
    minEdgesToKeep = NE;


    //printf("%d ", minEdgesToKeep);
}
//prints the row pointer after rows have been removed
void printAdjRowPtr(int adjRowPtr[])
{
    //prints adjusted row pointer array
    printf("%5d \n", adjRowPtr[0]);
    for(i = 1; i < M*N1+1; i++)
    {
        printf("%5d ", adjRowPtr[i]);
            if((i) %M == 0)
            printf("\n");
    }
    printf("\n");
}
//prints the Count array after the rows have been removed
void printAdjCount(int adjCount[])
{
    //prints adjusted count array
    for(i = 0; i < M*N1; i++)
    {
        printf("%2d ", adjCount[i]);
        if((i+1) %M == 0)
            printf("\n");
    }
    printf("\n");
}
//prints the ColumnIndex array after rows have been removed
void printAdjColumn(int adjColumnIndex[], int adjRowPtr[])
{
    //prints adjusted column index
    j =0;
    for(i = 0; i < NE; i++)
    {
        //j is used as an incrementor to make output readable
        while(adjRowPtr[j] == i)
        {
            printf("\n");
            j++;
        }

        if(adjColumnIndex[i] != 0)
            printf("%d ",adjColumnIndex[i]);
    }
}
//prints the full input file
void printLinearArray(double LinearArray[])
{
    for(i = 0; i < NE*inputsPerLine; i=i+inputsPerLine)
    {
        printf("%.0f \t %.0f \t %.0f \t %.0f \t %.5f \t %.0f \t %.0f \n", LinearArray[i], LinearArray[i+1], LinearArray[i+2], LinearArray[i+3], LinearArray[i+4], LinearArray[i+5], LinearArray[i+6]);
    }
}
//prints only the path with the lowest weight total
void printPath(int Path[], int adjColumnIndex[], double adjWtArray[], int adjRowPtr[])
{
    //printf("\nShortest Path: ");
    for(i = 0; i < lengthOfPath; i++)
    {
        printf("%d ", Path[i]);
    }
    printf(" Weight: %f \n\n", findWtOfPath(Path, adjColumnIndex, adjWtArray, adjRowPtr));
}
//prints the array that determines if every eligible node has been tried yet. When all 1's are printed out, you know that every value has been tried
void printSecondValidityCheck(int adjCount[], int SecondValidityCheck[], int path[])
{
    //prints all values of of secondValidity check, 0's signify that this random value has not been selected yet
    for(j = 0; j < adjCount[path[i-1]]; j++)
    {
        printf("%d", SecondValidityCheck[j]);
    }
    printf("\n");

}
//prints the full valid path that has been found, used when trying to print every path found
void printValidPath(int path[], int minPath[])
{
    if(invalidCount < invalidLimit)
    {
        for(i = 0; i < lengthOfPath; i++)
        {
            printf("%d ", path[i]);
        }
        //printf("\n");
        printf("Valid Path! \t Weight of Path: %f \n", runningWeightTotal);
        //printf("invalid path count: %d \n\n", invalidCount);
    }
}
//reads the input file and stores it in Linear array
void readInput(double LinearArray[], FILE *input)
{
    int largest = 0;
    int largestColumn = 0;
    int largestBeginRow = 0;
    //adds every value in input file to the linear array
    if(inputsPerLine == 7)
    {
        for(i = 0; i < NE*inputsPerLine; i=i+inputsPerLine)
        {
            fscanf (input, "%lf %lf %lf %lf %lf %lf %lf ", &LinearArray[i], &LinearArray[i+1], &LinearArray[i+2], &LinearArray[i+3], &LinearArray[i+4], &LinearArray[i+5], &LinearArray[i+6]);
            if(LinearArray[i] == 0 && i == 0)
            {
                startsWithZero = true;
            }
            if(startsWithZero == true)
            {
                LinearArray[i]++;
                LinearArray[i+2]++;
            }
            if(LinearArray[i+2] > largest)
            {
                largest = LinearArray[i+2];
            }
            if(LinearArray[i+1] > largestColumn)
            {
                largestColumn = LinearArray[i+1];
            }
            if(LinearArray[i+3] > largestColumn)
                {
                    largestColumn = LinearArray[i+3];
                }
            if(LinearArray[i] > largestBeginRow)
            {
                largestBeginRow = LinearArray[i];
            }
        }
    }

    if(inputsPerLine == 6)
    {
        for(i = 0; i < NE*inputsPerLine; i=i+inputsPerLine)
        {
            fscanf (input, "%lf %lf %lf %lf %lf %lf ", &LinearArray[i], &LinearArray[i+1], &LinearArray[i+2], &LinearArray[i+3], &LinearArray[i+4], &LinearArray[i+5]);
            //when input file starts with zeros instead on ones, just increment the row numbers
                if(LinearArray[i] == 0 && i == 0)
                {
                    startsWithZero = true;
                }
                if(startsWithZero == true)
                {
                    LinearArray[i]++;
                    LinearArray[i+2]++;
                }


                if(LinearArray[i+2] > largest)
                {
                    largest = LinearArray[i+2];
                }
                if(LinearArray[i+1] > largestColumn)
                {
                    largestColumn = LinearArray[i+1];
                }
                if(LinearArray[i+3] > largestColumn)
                {
                    largestColumn = LinearArray[i+3];
                }
                if(LinearArray[i] > largestBeginRow)
                {
                    largestBeginRow = LinearArray[i];
                }
        }
    }

    if(inputsPerLine == 9)
    {
        for(i = 0; i < NE*inputsPerLine; i=i+inputsPerLine)
        {
            fscanf (input, "%lf %lf %lf %lf %lf %lf %lf %lf %lf ", &LinearArray[i], &LinearArray[i+1], &LinearArray[i+2], &LinearArray[i+3], &LinearArray[i+5], &LinearArray[i+5], &LinearArray[i+4], &LinearArray[i+5], &LinearArray[i+5]);
            //when input file starts with zeros instead on ones, just increment the row numbers
                if(LinearArray[i] == 0 && i == 0)
                {
                    startsWithZero = true;
                }
                if(startsWithZero == true)
                {
                    LinearArray[i]++;
                    LinearArray[i+2]++;
                }
                if(LinearArray[i+2] > largest)
                {
                    largest = LinearArray[i+2];
                }
                if(LinearArray[i+1] > largestColumn)
                {
                    largestColumn = LinearArray[i+1];
                }
                if(LinearArray[i+3] > largestColumn)
                {
                    largestColumn = LinearArray[i+3];
                }
                if(LinearArray[i] > largestBeginRow)
                {
                    largestBeginRow = LinearArray[i];
                }
        }
    }
    lengthOfPath = (largestColumn+1)/2;
    N = largest;
    numToRemove = N-lengthOfPath;
    //printf("%  d   \n", N-lengthOfPath);
    M = (largestColumn+1);
    N1 = largestBeginRow;
}
//creates all compound arrays before row have been removed
void createCompoundArr(double LinearArray[], double WtArray[], int columnIndex[], int Count[])
{
    int index = 0;  //used as index for Count array
    //creates first three arrays from the linear array
    for(i = 0; i < NE; i++)
    {
        WtArray[i] = LinearArray[inputsPerLine*i+4];
        columnIndex[i] = (LinearArray[inputsPerLine*i+2]-1)*M + LinearArray[inputsPerLine*i+3];
        index = (int)((LinearArray[inputsPerLine*i]-1)*M + LinearArray[inputsPerLine*i+1]);
        Count[index] = Count[index] + 1;
    }
}
//creates row pointer from count array by summing each value of Count
void createRowPtr(int rowPtr[], int Count[])
{
    int runningTotal = 0;
    rowPtr[0] = 0;  //First value is always zero
    for(i = 0; i < M*N1+1; i++)
    {
        runningTotal = runningTotal+Count[i];
        rowPtr[i+1] = runningTotal;
    }
}
//initializes every array that needs it. Just sets all values to zero
void initializeArr(int minPath[], int path[], int isInvalid[], int adjCount[], int adjRowPtr[], int Count[], int rowPtr[], int adjColumnIndex[], double adjustedArr[], int toRemove[], double keptPaths[], int rowsToRemove[],  double minWtEdges[])
{
    //initializes all arrays that need to be
    for(i =0; i< NE; i++)
    {
        if(i < minEdgesToKeep*5)
        {
            minWtEdges[i] = 100000;
        }
        if(i < numToRemove)
        {
            rowsToRemove[i] = 0;
        }
        if(i < lengthOfPath)
        {
            minPath[i] = 0;
            path[i] = 0;
        }
        if( i < M)
        {
            isInvalid[i] = 0;
        }
        if(i < M*N1+1)
        {
            adjCount[i] = 0;
            adjRowPtr[i] = 0;
            Count[i] = 0;
            rowPtr[i] = 0;
        }
        if(i < ((lengthOfPath+2)*PathsToKeep))
        {
            //printf("%f", keptPaths[i-1]);
            keptPaths[i] = 10000.0;
        }
        adjColumnIndex[i] =0;
        adjustedArr[i] =0;
        toRemove[i] = 0;
    }
}
//Removing rows from compound data structure
void removingRows(int adjColumnIndex[], int toRemove[], int rowPtr[], int adjRowPtr[], double WtArray[], int columnIndex[], double adjWtArray[], int rowsToRemove[], int rowsNotToRemove[])
{
    int k = 0;  //temporary variable used for indexing

    //creates the array toRemove, 1's signify that this edge needs to be removed
    j = 0;
    for(i = 0; i < NE; i++)
    {
        while(i == rowPtr[j])
        {
            j++;
        }
        for(k = 0; k < lengthOfPath; k++)
        {
            if(rowsNotToRemove[k] == (int)((j-1)/M) && rowsNotToRemove[k+1] == (int)(columnIndex[i]/M))
            {
                k = lengthOfPath;
                toRemove[i] = 0;
            }
            else
                toRemove[i] = 1;
        }

    }

    //removes lines from compound data structure using the toRemove array
    j = 0;
    k = 1;
    adjRowPtr[0] = 0;
    for(i =0; i < NE; i++)
    {
        //k++ executes when we move to the next unique starting vertex (i.e 1,0 to 1,1)
        while(rowPtr[k] == i)
        {
            k++;
            adjRowPtr[k] = adjRowPtr[k-1];
        }
        //when we come to a row that should not be removed, we will copy over the weight and column. Also increments adjRowPtr
        if(toRemove[i] == 0)
        {
            adjWtArray[j] = WtArray[i];
            adjColumnIndex[j] = columnIndex[i];
            adjRowPtr[k]++;
            j++;
        }
    }
    //added to fix bug where end of array was not made properly
    int lastValue = 0;
    if(adjRowPtr[M*N1] == 0)
    {
        for(i = M*N1; i > 0; i--)
        {
            if(adjRowPtr[i] != 0)
            {
                lastValue = adjRowPtr[i];
                break;
            }
        }
        for(j = i+1; j< M*N1+1; j++)
        {
            adjRowPtr[j] = lastValue;
        }
    }
}
//creates adjusted count array from adjusted rowPtr
void createAdjCount(int adjCount[], int adjRowPtr[])
{
    int runningTotal = 0;
    for(i = 0; i < M*N1+1; i++)
    {
        adjCount[i] = adjRowPtr[i+1] - runningTotal;
        runningTotal = adjRowPtr[i+1];
    }
}
//creates an array that holds every row that is not removed
void createRowsNotToRemove(int rowsNotToRemove[], int rowsToRemove[])
{
    for(i = 0; i < lengthOfPath; i++)
    {
        rowsNotToRemove[i] = 0;
    }

    j = 0;
    int k = 0;
    for(i = 0; i < N; i++)
    {
        if(rowsToRemove[j] != i)
        {
           rowsNotToRemove[k] = i;
           k++;
        }
        else
        {
            j++;
        }
    }
}
//prints the array that holds every row not to remove
void printRowsNotToRemove(int rowsNotToRemove[])
{
    for(i = 0; i < lengthOfPath; i++)
    {
        printf("%i ", rowsNotToRemove[i]);
    }
    printf("\n");
}
//returns the largest value in adjCount array, used for constructing arrays
int findLargestCount(int adjCount[])
{
    int localMax = 0;
    for(i = 0; i < M*N1; i++)
    {
        if(localMax < adjCount[i])
        localMax = adjCount[i];
    }
    return localMax;
}
//finds the first node in the path and prints it out
void firstInPath(int path[])
{
    randomTemp = (rand()%M);
    path[0] = randomTemp;
}
//when a stick has been used already, it can no longer be selected. This is represented by isInvalid having a 1 in the stick's position
void repeatedStick(int isInvalid[], int r)
{
    //for odd values
    if((r % 2) == 1)
    {
        isInvalid[r] = 1;    //1 in isInvalid means that this is no longer a valid choice
        isInvalid[r-1] = 1;
    }
    //for even values or for 0
    if((r % 2) == 0)
    {
        isInvalid[r] = 1;    //1 in isInvalid means that this is no longer a valid choice
        isInvalid[r+1] = 1;
    }
}
//finds a specific amount of  random rows(helixes) that will be removed
void randomRemoval(int rowsToRemove[])
{
    //if the two rows to remove are the same, change the second one
    for(i = 0; i < numToRemove; i++)
    {
        rowsToRemove[i] = (rand() % N1)+1;
        //printf("%d ", rowsToRemove[i]);
        for(j = 0; j < numToRemove; j++)
        {
            while(rowsToRemove[i] == rowsToRemove[j] && i != j)
            {
                rowsToRemove[i] = (rand() % N1)+1;
                j = numToRemove;
            }
        }
    }
    //sort the rows to remove
    qsort(rowsToRemove, numToRemove, sizeof(int), cmpfuncInt);
}
//prints every row that will be removed
void printRowsToRemove(int rowsToRemove[])
{
    printf("Random Rows to be removed: ");
    for(i = 0; i < numToRemove; i++)
    {
        printf("%i, ", rowsToRemove[i]);
    }
    printf("\n");
}
//when all options to continue the current path have been exhausted, i.e, secondValidityCheck is full of 1's, this path is invalid
void triedAllOptions(int adjCount[], int path[], int SecondValidityCheck[])
{
    if(adjCount[path[i-1]] != 0)
    {
        //checks if all values of array are 1. If they are then this path is invalid
        for(j = 0; j < adjCount[path[i-1]]; j++)
        {
            invalid = true;
            if(SecondValidityCheck[j] == 0)
            {
                invalid = false;
                j = adjCount[path[i-1]]+1;
            }

        }
    }
}
//resets the Second validity check to zero when a node has been selected.
void reset2ndValidity(int adjCount[], int path[], int SecondValidityCheck[])
{
    for(j = 0; j < 60; j++)
    {
        SecondValidityCheck[j] = 0;
    }
}
//when path is invalid, start over and continue to try to find a valid path
void restartPath(int adjCount[], int path[], int SecondValidityCheck[], int isInvalid[], double probability[], double adjWtArray[], int adjRowPtr[])
{
    if(invalid == true || CountisZero == 1)
    {
        //pathHasRestarted = true;
        //resets variables that were changed during path construction
        runningWeightTotal = 0;
        CountisZero = 0;
        //adds to invalidCount because the path was restarted
        invalidCount++;
        //deletes all values of SecondValidityCheck because no random values have been selected yet
        reset2ndValidity(adjCount, path, SecondValidityCheck);
        //resets path and isInvalid
        for(j = 0; j < M; j++)
        {
            if(j < lengthOfPath)
            {
                path[j] = 0;
            }
            isInvalid[j] = 0;
        }
        //must recreate first value of the path
        firstInPath(path);
        repeatedStick(isInvalid, randomTemp);
        //i is set to 1 because we just found the first in path
        i =1;
    }
}
//finds the path with the least weight of all the valid paths
void findMin(int path[], int minPath[])
{
    if(runningWeightTotal < minWeight)
    {
        minWeight = runningWeightTotal;
        for(j = 0; j< lengthOfPath; j++)
        {
            minPath[j] = path[j];
        }
    }
}
//optimizes the best path by checking if the second node in a stick/column has a better weight. Checks from end of path to begining
void optimizeNodes(int originalPath[], int adjRowPtr[], int adjColumnIndex[], double adjWtArray[], int adjCount[])
{
    //temporary weights used to compare whether the optimized path should go to the 1st or 2nd node in a stick
    //temporary weights are set to 10000 because this is larger than a weight will ever be
    double tempWt = 10000;
    double tempWt2 = 10000;
    int optimizeCount = 0;
    //best Direction arrays hold 1's, 2's, and 0's. 1 means that the shortest path is to go to an odd node in the stick, 0 means that you must go to an even node, 2's mean there is no valid path from this node
    int bestDirectionEven[lengthOfPath-1];
    int bestDirectionOdd[lengthOfPath-1];
    //these arrays hold running weights. 18 weights are included for the 18 edges in the path. even represents the 1st node in a stick, odd represents the 2nd
    double bestWeightsEven[lengthOfPath-1];
    double bestWeightsOdd[lengthOfPath-1];
    //path that can be changed to compare weight values
    int adjustedPath[lengthOfPath];
    //initialize the directional arrays with all values equaling 2. This way if a value is not changed we will be able to tell easily.
    //adjusted path is set equal to the original one
    for(i = 0; i < lengthOfPath; i++)
    {
        adjustedPath[i] = originalPath[i];
        if(i != lengthOfPath-1)
        {
            bestDirectionEven[i] = 2;
            bestDirectionOdd[i] = 2;
            bestWeightsEven[i] = 0;
            bestWeightsOdd[i] = 0;
        }
    }
    //loops from back of path to front attempting to find a path that has a lower weight than the original one
    for(i = lengthOfPath-2; i >= 0; i--)
    {   //just to be sure, the adjusted path is set back to the original one in case changes have been made
        for(j = 0; j < lengthOfPath; j++)
        {
            adjustedPath[j] = originalPath[j];
        }
        //we begin with the edge of 2 even nodes
        if((originalPath[i] % 2) != 0)
        {
            adjustedPath[i] = adjustedPath[i]-1;
        }
        if((originalPath[i+1] % 2) != 0)
        {
            adjustedPath[i+1] = adjustedPath[i+1]-1;
        }
        //tempWt set to 0 because if we can find a valid edge, we wont want to add it to 10000
        tempWt = 0;
        //because bestWeightsEven is a running total in each index, we want to add the last weight to the current one. This is performed unless the array has no values
        if(i != lengthOfPath-2)
        tempWt += bestWeightsEven[i+1];
        //when the adjCount array is equal to zero, this means we have no valid edges coming from this node. We must st tempWt to 10000 because the loop below wont be executed
        if(adjCount[adjustedPath[i]] == 0)
        {
            tempWt += 10000;
        }
        //checks if edge exists and puts weight in tempWt. Otherwise if the edge does not exist tempWt will be greater than 10000
        for(j = 0; j < adjCount[adjustedPath[i]]; j++)
        {
            tempWt += 10000;
            //checks if path is valid in terms of the value before it
            if(adjustedPath[i+1] == adjColumnIndex[j + adjRowPtr[adjustedPath[i]]])
            {
                tempWt  += adjWtArray[j + adjRowPtr[adjustedPath[i]]] - ((j+1)*10000);
                j = adjCount[adjustedPath[i]];
            }
        }
        //we have found the weight of the edge between 2 even nodes, now we will adjust the bottom node to become odd
        adjustedPath[i+1] = adjustedPath[i+1]+1;
        //tempWt2 set to 0 because if we can find a valid edge, we wont want to add it to 10000
        tempWt2 = 0;
        //because bestWeightsOdd is a running total in each index, we want to add the last weight to the current one. This is performed unless the array has no values
        if(i != lengthOfPath-2)
        tempWt2 += bestWeightsOdd[i+1];
        //just like above, if count is equal to zero, there is no valid edge and setting tempWt2 to 10000 makes sure it is not selected as a valid one
        if(adjCount[adjustedPath[i]] == 0)
        {
            tempWt2 += 10000;
        }
        //checks if edge exists and puts weight in tempWt. Otherwise if the edge does not exist tempWt will be greater than 10000
        for(j = 0; j < adjCount[adjustedPath[i]]; j++)
        {
            tempWt2 += 10000;
            //checks if path is valid in terms of the value before it
            if(adjustedPath[i+1] == adjColumnIndex[j + adjRowPtr[adjustedPath[i]]])
            {
                tempWt2  += adjWtArray[j + adjRowPtr[adjustedPath[i]]] - ((j+1)*10000);
                j = adjCount[adjustedPath[i]];
            }
        }
        //now we have to decide which of the two edges is the better one to select
        //if the even edge is less than the odd edge, we will set the bestDirectionEven array to display this and add the new weight to the running total array
        if(tempWt < tempWt2)
        {
            bestDirectionEven[i] = 0;
            bestWeightsEven[i] = tempWt;
        }
        //if the odd edge is less than the even edge, we will do the same: set the bestDirectionEven array to display this and add the new weight to the running total array
        if(tempWt2 < tempWt)
        {
            bestDirectionEven[i] = 1;
            bestWeightsEven[i] = tempWt2;
        }
        //if by coincidence the two weights are the same (usually happens when both edges are invalid), we still need to add the new weight to the running total
        if(tempWt == tempWt2)
        {
            bestWeightsEven[i] = tempWt2;
        }
        //when both weights are greater than 10000, we know that both edges are invalid and must set the best directional array to 2 to display this
        if((tempWt > 10000) & (tempWt2 > 10000))
        {
            bestDirectionEven[i] = 2;
        }

        //We have found both edges coming from the even node, now we must find the edges coming from the odd node
        if((adjustedPath[i] % 2) != 1)
        {
            adjustedPath[i] = adjustedPath[i]+1;
        }
        // we begin with both edges being odd
        if((adjustedPath[i+1] % 2) != 1)
        {
            adjustedPath[i+1] = adjustedPath[i+1]+1;
        }
        //just as before, tempWt must be set to 0 so that the running total is not messed up
        tempWt = 0;
        //add the running total to the bestWeightsOdd unless there is nothing in the array yet
        if(i != lengthOfPath-2)
        tempWt += bestWeightsOdd[i+1];
        //if count is equal to 0, there are no valid edges from this node and we set the tempWt to display this
        if(adjCount[adjustedPath[i]] == 0)
        {
            tempWt += 10000;
        }

        //checks if edge exists and puts weight in tempWt. Otherwise if the edge does not exist tempWt will be greater than 10000
        for(j = 0; j < adjCount[adjustedPath[i]]; j++)
        {
            tempWt += 10000;
            //checks if path is valid in terms of the value before it
            if(adjustedPath[i+1] == adjColumnIndex[j + adjRowPtr[adjustedPath[i]]])
            {
                tempWt  += adjWtArray[j + adjRowPtr[adjustedPath[i]]] - ((j+1)*10000);
                j = adjCount[adjustedPath[i]];
            }
        }
        //now that the weight of the edge of two odd nodes has been recorded we will compare it to the edge of the beginning odd node and the ending even node
        adjustedPath[i+1] = adjustedPath[i+1]-1;
        //we set temp2 back to zero like we have done before
        tempWt2 = 0;
        //add the running total to the bestWeightsOdd unless there is nothing in the array yet
        if(i != lengthOfPath-2)
        tempWt2 += bestWeightsEven[i+1];
        //if the adjusted count array is equal to zero, just like before, we need to set the tempWt2 to and invalid weight value
        if(adjCount[adjustedPath[i]] == 0)
        {
            tempWt2 += 10000;
        }
        //checks if edge exists and puts weight in tempWt. Otherwise if the edge does not exist tempWt will be greater than 10000
        for(j = 0; j < adjCount[adjustedPath[i]]; j++)
        {
            tempWt2 += 10000;
            //checks if path is valid in terms of the value before it
            if(adjustedPath[i+1] == adjColumnIndex[j + adjRowPtr[adjustedPath[i]]])
            {
                tempWt2  += adjWtArray[j + adjRowPtr[adjustedPath[i]]] - ((j+1)*10000);
                j = adjCount[adjustedPath[i]];
            }
        }
        //now we need to decide which of the two edges are better
        //if the tempWt is less than tempWt2 then we know that the odd to odd edge is the better one. We adjust the arrays accordingly
        if(tempWt < tempWt2)
        {
            bestDirectionOdd[i] = 1;
            bestWeightsOdd[i] = tempWt;
        }
        //if the tempWt is less than tempWt2 then we know that the odd to even edge is better. Therefore we adjust the arrays to display this
        if(tempWt2 < tempWt)
        {
            bestDirectionOdd[i] = 0;
            bestWeightsOdd[i] = tempWt2;
        }
        //when both weights are equal which is rare. We need to make sure the running weight total is adjusted since neither of the if statements above will be executed
        if(tempWt == tempWt2)
        {
            bestWeightsOdd[i] = tempWt2;
        }
        //when both weights are greater than 10000, we know that both are invalid and we need to adjust the bestDirectionOdd array to convey this
        if((tempWt > 10000) & (tempWt2 > 10000))
        {
            bestDirectionOdd[i] = 2;
        }
        //used for debugging, displays the arrays as they are being made
    /*
        printf("\n");
        for(j = 0; j < lengthOfPath-1; j++)
            printf("%d ", bestDirectionEven[j]);
            printf("\n");
        for(j = 0; j < lengthOfPath-1; j++)
            printf("%d ", bestDirectionOdd[j]);
            printf("\n");
        for(j = 0; j < lengthOfPath-1; j++)
            printf("%f ", bestWeightsEven[j]);
            printf("\n");
        for(j = 0; j < lengthOfPath-1; j++)
            printf("%f ", bestWeightsOdd[j]);
            printf("\n");
    */
    }
    //before we build the optimized path we have found, adjusted array must be set back to its original values
    for(i = 0; i < lengthOfPath; i++)
    {
        adjustedPath[i] = originalPath[i];
    }
    //loops through original path given from top to bottom
    for(i = 0; i < lengthOfPath-1; i++)
    {   //if the path is at an even value, we look to the bestDirectionEven array to tell us where to go
        if(adjustedPath[i] % 2 == 0)
        {   //if the bestDirectionEven array tells us to go to an odd node, we make sure that the path is adjusted for this
            if(bestDirectionEven[i] == 1)
            {
                if(adjustedPath[i+1] % 2 == 0)
                {
                    adjustedPath[i+1] = adjustedPath[i+1]+1;
                }
            }
            //if the bestDirectionEven array tells us to go to an even node, we make sure that the path reflects this
            else if(bestDirectionEven[i] == 0)
            {
                if(adjustedPath[i+1] % 2 == 1)
                {
                    adjustedPath[i+1] = adjustedPath[i+1]-1;
                }
            }
        }
        //if the adjusted path instead is at an odd value, we must look to the bestDirectionOdd array to tell us where to go next
        else if(adjustedPath[i] % 2 == 1)
        {   //if the bestDirectionOdd array tells us to go to an odd node, we make sure that the path is adjusted for this
            if(bestDirectionOdd[i] == 1)
            {
                if(adjustedPath[i+1] % 2 == 0)
                {
                    adjustedPath[i+1] = adjustedPath[i+1]+1;
                }
            }
            //if the bestDirectionOdd array tells us to go to an even node, we make sure that the path reflects this
            else if(bestDirectionOdd[i] == 0)
            {
                if(adjustedPath[i+1] % 2 == 1)
                {
                    adjustedPath[i+1] = adjustedPath[i+1]-1;
                }
            }
        }
    }
    //checks that the new path is still valid
    pathIsValid(adjustedPath, adjRowPtr, adjColumnIndex, adjWtArray, adjCount);
    //compares new path to original to see if there was an improvement
    if(findWtOfPath(adjustedPath, adjColumnIndex, adjWtArray, adjRowPtr) < findWtOfPath(originalPath, adjColumnIndex, adjWtArray, adjRowPtr))
    {
        optimizeCount++;    //used to count how often there is an improvement when comparing many paths
        //if there is an improvement, we will adjust the original path to reflect the change
        for(i = 0; i < lengthOfPath-1; i++)
        {
            originalPath[i] = adjustedPath[i];
        }
        minWeight = findWtOfPath(adjustedPath, adjColumnIndex, adjWtArray, adjRowPtr);
    }

}
//decides if the path is valid based on used sticks and valid edges
bool pathIsValid(int Path[], int adjRowPtr[], int adjColumnIndex[], double adjWtArray[], int adjCount[])
{

    int stickUsed[M];
    for(i = 0; i < M; i++)
    {
        stickUsed[i] = 0;
    }
    //loops through whole path
    for(i = 1; i <= lengthOfPath; i++)
    {
        //dont want to go out of bounds when i == lengthOfPath
        if(i != lengthOfPath)
        {
            //checks that all edges actually exist
            if(!edgeExists(Path[i-1], Path[i], adjRowPtr, adjColumnIndex, adjWtArray, adjCount))
            {
                printf("edge does not exist!");
                return false;
            }
        }


        //checks that sticks arent used twice
        if(((Path[i-1] % M) % 2) == 1)
            {
                if(stickUsed[Path[i-1] % M] == 1 || stickUsed[(Path[i-1] % M) -1] == 1)
                {
                    //printf("Stick used twice!");
                    return false;
                }
                repeatedStick(stickUsed, (Path[i-1] % M));
            }
            if((((Path[i-1] % M) % 2) == 0))
            {
                if(stickUsed[Path[i-1] % M] == 1 || stickUsed[(Path[i-1] % M) +1] == 1)
                {
                    printf("Stick used twice!");
                    return false;
                }
                repeatedStick(stickUsed, (Path[i-1] % M));
            }
    }
    return true;
}
//returns true if edge exists else returns false
bool edgeExists(int edge1, int edge2, int adjRowPtr[], int adjColumnIndex[], double adjWtArray[], int adjCount[])
{
    for(j = adjRowPtr[edge1]; j < adjRowPtr[edge1+1]; j++)
    {
        if(adjColumnIndex[j] == edge2)
        {
            return true;
        }
    }
    return false;
}
//comparative function for qsort
int cmpfunc (const void * a, const void * b)
{
   double f = *((double*)a);
    double s = *((double*)b);
    if (f > s) return  1;
    if (f < s) return -1;
    return 0;
}
//comparative function when for qsort when the values are integers
int cmpfuncInt (const void * a, const void * b)
{
   int f = *((int*)a);
    int s = *((int*)b);
    if (f > s) return  1;
    if (f < s) return -1;
    return 0;
}
//keeps a certain amount of low weighted paths, called many times and checks if the new path belongs in the set
void keepPath(double keptPaths[], int newPath[], double weight)
{
    int k = 0;  //temporary variable used for indexing
    //loops through all paths saved
    for(i = lengthOfPath+1; i < (lengthOfPath+2)*PathsToKeep; i+=(lengthOfPath+2))
    {
        //printf("%d ", i);
        //checks if the weight of the new path is already in the saved paths, if it is add to the count
        if(weight == keptPaths[i])
        {
            keptPaths[i-1] += 1;
            break;
        }
        //if the weight is less than any of the kept paths, add it to the set and remove the highest weighted path in the set
        else if(weight < keptPaths[i])
        {
            uniquePaths++;
            //shifts the paths behind the current path down a low and removes the highest
            for(j = (lengthOfPath+2)*(PathsToKeep-1); j > i-lengthOfPath-2; j--)
            {
                keptPaths[j+lengthOfPath+2] = keptPaths[j];
            }
            //adds the current path to the
            for(j = i-lengthOfPath-1; j < i-1; j++)
            {
                keptPaths[j] = newPath[k];
                k++;
            }
            keptPaths[j+1] = weight;
            keptPaths[j] = 1;
            break;
        }
    }
}
//creates a probability array by giving weights based off of the possible choices
void initializeProbabilityCorrectly(int adjCount[], double probability[], double adjWtArray[], int adjRowPtr[], int path[], double wtsForChoosing)
{
    runningProbSum = 0;
    //initializes new array and also adds 1/w^2 to the runningProbSum where w is the weight
    for(j = 0; j < adjCount[path[i-1]]; j++)
    {
        probability[j] = 0;
        runningProbSum += 1/(pow((adjWtArray[j + adjRowPtr[path[i-1]]]), wtsForChoosing) );
    }
    //puts each weighted edge in the probability array
    for(j = 0; j < adjCount[path[i-1]]; j++)
    {
        probability[j] = (1/(pow((adjWtArray[j + adjRowPtr[path[i-1]]]), wtsForChoosing)))/runningProbSum;
        //printf("%f ", probability[j]);
    }
}
//similar to initializeProbabilityCorrectly but uses |Wmax-W|+Delta
void normalizeByMax(int adjCount[], double probability[], double adjWtArray[], int adjRowPtr[], int path[], double wtsForChoosing)
{
    double delta = 0;
    runningProbSum = 0;
    double maximum = 0;

    //finds delta whih is one percent of the maximum weight
    for(j = 0; j < adjCount[path[i-1]]; j++)
    {
        probability[j] = 0;
        if(maximum < adjWtArray[j + adjRowPtr[path[i-1]]])
        {
            maximum = adjWtArray[j + adjRowPtr[path[i-1]]];
        }
    }
    delta = maximum *.01;
    //printf("%f", delta);

    //gets runningProbSum
    for(j = 0; j < adjCount[path[i-1]]; j++)
    {
        probability[j] = maximum - adjWtArray[j + adjRowPtr[path[i-1]]] + delta;
        runningProbSum += pow(probability[j], wtsForChoosing);
    }

    //puts the correct values in probability
    for(j = 0; j < adjCount[path[i-1]]; j++)
    {
        probability[j] = (pow(probability[j], wtsForChoosing))/runningProbSum;
        //printf("%f ", probability[j]);
    }
}
//picks the next node in path based off the probability array
void correctBiasedChoice(double probability[], int adjCount[], int path[], double adjWtArray[], int adjRowPtr[])
{
    double runningPickNode = 0;
    //choose random number between zero and one
    randomTemp2 = ((double) rand()/RAND_MAX);
    //loop through every node
    for(j = 0; j < adjCount[path[i-1]]; j++)
    {
        runningPickNode += probability[j];
        if(runningPickNode > randomTemp2)
        {
            //probValue = probability[j];
            //printf("%f ", probValue);
            randomTemp = j;
            break;
        }
    }
}
//prints the paths that have been kept due to their low weights
void printTopPaths(double keptPaths[])
{
    //when unique paths is less than the amount of paths we want to keep
    if(uniquePaths <= PathsToKeep)
    {
        for(i = 0; i < ((lengthOfPath+2)*uniquePaths); i++)
        {
            if(i % (lengthOfPath+2) != lengthOfPath+1 && (i % (lengthOfPath+2) != lengthOfPath))
            printf("%.0f ", keptPaths[i]);

            if( (i % (lengthOfPath+2) == lengthOfPath) || i == lengthOfPath)
            {
                printf("\t Count: %.0f ", keptPaths[i]);
            }
            if( (i % (lengthOfPath+2) == lengthOfPath+1) || i == lengthOfPath+1)
            {
                printf("\t Weight: %f ", keptPaths[i]);
                printf("\n");
            }
        }
    }
    //when unique paths is greater than the amount of paths we want to keep
    else if(uniquePaths > PathsToKeep)
    {
        for(i = 0; i < ((lengthOfPath+2)*PathsToKeep); i++)
        {
            if(i % (lengthOfPath+2) != lengthOfPath+1 && (i % (lengthOfPath+2) != lengthOfPath))
            printf("%.0f ", keptPaths[i]);

            if( (i % (lengthOfPath+2) == lengthOfPath) || i == lengthOfPath)
            {
                printf("\t Count: %.0f ", keptPaths[i]);
            }
            if( (i % (lengthOfPath+2) == lengthOfPath+1) || i == lengthOfPath+1)
            {
                printf("\t Weight: %f ", keptPaths[i]);
                printf("\n");
            }
        }
    }

    printf("Number of different paths found: %d \n\n", uniquePaths);
}
//finds valid paths from all edges. Can either use this function to find the paths randomly or selecting the path based off the edge weights
void findPaths(int path[], int isInvalid[], int adjCount[], double adjWtArray[], int adjRowPtr[], int adjColumnIndex[], int minPath[], double keptPaths[], double wtsForChoosing, int SecondValidityCheck[], double probability[], int tempChoice)
{
    int l = 0;  //used for loops
    int attemptsCount = 0;  //used to count how many attempts the program is making to find the next node


    //loops every time a valid path is found. This determines how many valid paths that need to be made after the random removal of 2 rows
    for(l = 0; l < validPathNum; l++)
    {
        invalidCount = 0;//used to determine how many invalid rows were made before a valid one is
        firstInPath(path);//finds the first value of the valid path
        repeatedStick(isInvalid, randomTemp);//changes isInvalid to 1 if stick has already been used

        for(i=1; i<lengthOfPath; i++)//finds the rest of the values of the randomly generated valid path
        {
            //sets all values of array to 0. This signifies that none of the random values have been chosen yet
            reset2ndValidity(adjCount, path, SecondValidityCheck);

            //we can specify which function we want to use based on weights
            if(wtsForChoosing != 0)
            {
                if(tempChoice == 1)
                normalizeByMax(adjCount, probability, adjWtArray, adjRowPtr,  path, wtsForChoosing);
                if(tempChoice == 2)
                initializeProbabilityCorrectly(adjCount, probability, adjWtArray, adjRowPtr,  path, wtsForChoosing);
            }


            do  //attempts to find the next valid node in the path
            {
                //if finding the next edge takes more than 1000 tries, we call the path invalid. There might be a valid path, but taking this long means that it will have a high total weight
                attemptsCount++;
                //if every valid edge from the node has been tried and has been determined invalid, the current path is invalid and must be restarted
                triedAllOptions(adjCount, path, SecondValidityCheck);

                //we call the path invalid if we have already attempted 1000 times
                if(attemptsCount > invalidLimit)
                {
                    invalid = true;
                    attemptsCount = 0;
                }

                //if invalid is true or all values have been selected(CountisZero) then the path must be started over. All changed values must be set to their original.
                restartPath(adjCount, path, SecondValidityCheck, isInvalid, probability, adjWtArray, adjRowPtr);

                //we can specify which function we want to use based on weights
                if(wtsForChoosing != 0)
                {
                    if(tempChoice == 1)
                    normalizeByMax(adjCount, probability, adjWtArray, adjRowPtr,  path, wtsForChoosing);
                    if(tempChoice == 2)
                    initializeProbabilityCorrectly(adjCount, probability, adjWtArray, adjRowPtr,  path, wtsForChoosing);
                }


                //if this statement is false, we have an invalid path because when count is equal to 0 we have no valid edges coming from this node
                if((adjCount[path[i-1]]) != 0)
                {   if(wtsForChoosing == 0)
                        randomTemp = (rand() % (adjCount[path[i-1]]));//randomTemp is a random variable between 0 and how many edges are coming from the previous node in the path.
                    else
                        correctBiasedChoice(probability, adjCount, path, adjWtArray, adjRowPtr);
                }
                else
                    CountisZero = 1;    //when CountisZero is equal to 1, we have an invalid path

                //randomtemp is either found by using a random number or letting correctBiasedChoice adjust it
                //nextValid holds the next value of the valid path
                //printf("%d ", (adjRowPtr[path[i-1]]));
                nextValid = adjColumnIndex[randomTemp + adjRowPtr[path[i-1]]];
                //signifies that this random number has already been selected

                SecondValidityCheck[randomTemp] = 1;

                //printf("aaaaaaa %d %d", isInvalid[nextValid % M], CountisZero);
            }
            while( isInvalid[nextValid % M] == 1 || CountisZero == 1);//checks if nextValid is valid, loop again if nextValid is not part of the valid path. Or loop again if no edges are coming from the node
            //keeps track of the weight of the valid path
            runningWeightTotal+= adjWtArray[randomTemp + adjRowPtr[path[i-1]]];

            //changes validity array that determines if a stick has been selected already
            CountisZero = 0;
            repeatedStick(isInvalid, (nextValid%M));
            attemptsCount = 0;

            //prints valid path up to the index
            path[i] = nextValid;
            //printf("%d ", path[i]);
        }

        //if statement here because we don't want to keep invalid paths
        if(invalidCount < invalidLimit)
        keepPath(keptPaths, path, runningWeightTotal);

        //pathIsValid(path, adjRowPtr, adjColumnIndex, adjWtArray, adjCount);
        //optimizeNodes(path, adjRowPtr, adjColumnIndex, adjWtArray, adjCount);
    }
}
//constructs a set of m lowest weight edges from the linear array, but will not select edges that should be removed based on rowsToRemove
void constructSetRemoved(int m, double minWtEdges[], double linearArray[], int rowsToRemove[], int rowsNotToRemove[])
{
    createRowsNotToRemove(rowsNotToRemove, rowsToRemove);
    int k = 0;
    int n = 0;
    bool removed = false;
    double difference = 0;
    //loops through whole input file
    for(i = 4; i < NE*inputsPerLine; i+=inputsPerLine)
    {
        removed = false;
        //loops through lowest weight edges saved
        for(j = 4; j < m*5; j+=5)
        {
            //checks if the current edge will be removed based on rowsToRemove. If it should be removed, set removed to true
            for(n = 0; n < numToRemove; n++)
            {
                if(rowsToRemove[n]+1 == linearArray[i-2] || rowsToRemove[n]+1 == linearArray[i-4])
                {
                    removed = true;
                    j = m*5;
                }
            }

            //if edge skips rows that shouldn't be skipped, set removed to true
            difference = linearArray[i-2] - linearArray[i-4];
            if(difference > 1)
            {
                for(n = 0; n < lengthOfPath; n++)
                {
                    if(linearArray[i-4] == rowsNotToRemove[n]+1)
                    {
                        if(linearArray[i-2] != rowsNotToRemove[n+1]+1)
                        {
                            removed = true;
                            n = lengthOfPath;
                        }
                    }
                }
            }

            //Will save the edge as long as removed is equal to false and the current edge from the input file has a low enough weight
            if(removed == false && minWtEdges[j] > linearArray[i])
            {
                //printf("%f ", minWtEdges[j]);
                //shifts all edges greater than the current edge down a row
                for(k = m*5-6; k > j-5; k--)
                {
                    minWtEdges[k+5] = minWtEdges[k];
                }
                minWtEdges[j] = linearArray[i];
                minWtEdges[j-1] = linearArray[i-1];
                minWtEdges[j-2] = linearArray[i-2];
                minWtEdges[j-3] = linearArray[i-3];
                minWtEdges[j-4] = linearArray[i-4];

                j = m*5;
            }
        }
    }
}
//prints the minWtEdges array that holds all of the lowest weight edges, this array is generated by constructSetRemoved
void printMinWtEdges(double minWtEdges[], int m)
{
    int l = 0;
    for(l = 0; l < m*5; l++)
    {
        if((l+1) % 5 != 0 )
            printf("%.0f \t", minWtEdges[l]);
        if((l+1) % 5 == 0 )
        {
            printf("%f \n", minWtEdges[l]);
        }

    }
    printf("\n\n");
}
//constructs a subset with k edges of the minimum minWtEdges
void minSelectSet(double minWtEdges[], int k, double subsetMinWtEdges[])
{
    for(i = 0; i < k*5; i++)
    {
        subsetMinWtEdges[i] = minWtEdges[i];
    }
}
//prints out a subset of the minWtEdges that we kept, this subset only keeps the lowest edges
void printSubset(int k, double subsetMinWtEdges[])
{
    int l = 0;
    for(l = 0; l < k*5; l++)
    {
        if((l+1) % 5 != 0 )
            printf("%.0f \t", subsetMinWtEdges[l]);
        if((l+1) % 5 == 0 )
        {
            printf("%f \n", subsetMinWtEdges[l]);
        }
    }
    printf("\n\n");
}
//randomly constructs a subset of the subsetMinWtEdges with an amount of randminedges. This function will not select nodes of the same row twice
void randomSelectSet(int randNum, double subsetMinWtEdges[], double randMinWtEdges[])
{
    int l = 0;
    int random = 0;
    int alreadyChosen[randNum];
    bool same = false;
    for(i = 0; i < randNum; i++)
    {
        alreadyChosen[i] = 0;
    }

    //chooses a certain amount of edges to keep randomly in the amount of randMinEdges
    for(i = 0; i < randMinEdges; i++)
    {
        //makes sure that the same edge isnt chosen twice and edges in the same row arent chosen twice
        do{
            same = false;
            random = (rand() % randNum);
            for(l = 0; l < i; l++)
            {
                if(randMinWtEdges[l*5] == subsetMinWtEdges[random*5] || randMinWtEdges[l*5+2] == subsetMinWtEdges[random*5+2])
                {
                    same = true;
                }
            }

        }while(alreadyChosen[random] == 1 || same == true);

        alreadyChosen[random] = 1;
        same = false;

        //adds the edge to the set
        for(j = 0; j < 5; j++)
        {
            randMinWtEdges[(i*5)+j] = subsetMinWtEdges[(random*5)+j];
        }
    }
}
//prints the randomly generated subset of minWtEdges
void printRandMinSet(double randMinWtEdges[], int randNum)
{
    int l = 0;
    for(l = 0; l < randMinEdges*5; l++)
    {
        printf("%f ", randMinWtEdges[l]);
        if((l+1) % 5 == 0 )
            printf("\n");
    }
    printf("\n\n");

}
//finds the weight of a given path and returns it
double findWtOfPath(int path[], int adjColumnIndex[], double adjWtArray[], int adjRowPtr[])
{
    double wt = 0;

    for(i = 1; i < lengthOfPath; i++)
     {
         for(j = adjRowPtr[path[i-1]]; j < adjRowPtr[path[i-1]+1]; j++)
            {
                if(adjColumnIndex[j] == path[i])
                {
                    wt += adjWtArray[j];
                    //printf("%f ", adjWtArray[j]);
                }
            }
     }
     return wt;
}
//resets the array that holds the best paths
void resetKeptPaths(double keptPaths[], int uniquePaths)
{
    for(i = 0; i < ((lengthOfPath+2)*PathsToKeep); i++)
    {
        keptPaths[i] = 10000.0;
    }
    uniquePaths = 0;
}
//finds a specific amount of paths by constructing them probabilistically from all the edges. This path will start with a random low weighted edge
void createPathsFromOneEdge(int subsetMinEdges, double subsetMinWtEdges[], double randMinWtEdges[],  int partialPath[], int rowsToRemove[], int adjRowPtr[], int adjColumnIndex[], int randMinEdges, int isInvalid[], int adjCount[], double adjWtArray[], double keptPaths[], double probability[], double wtsForChoosing, int numToCreate)
{
    int ll = 0;
    for(ll = 0; ll < numToCreate; ll++){
        randomSelectSet(subsetMinEdges, subsetMinWtEdges, randMinWtEdges);
        while(isValidPartialPath(randMinWtEdges, partialPath, rowsToRemove, adjRowPtr, adjColumnIndex, randMinEdges, false) == false)
        {
            randomSelectSet(subsetMinEdges, subsetMinWtEdges, randMinWtEdges);
        }
        while(CompletePathProbabilistic(partialPath, randMinWtEdges, isInvalid, adjCount, adjColumnIndex, adjRowPtr, adjWtArray, keptPaths, probability, wtsForChoosing) == false)
        {

            randomSelectSet(subsetMinEdges, subsetMinWtEdges, randMinWtEdges);
            while(isValidPartialPath(randMinWtEdges, partialPath, rowsToRemove, adjRowPtr, adjColumnIndex, randMinEdges, false) == false)
            {
                randomSelectSet(subsetMinEdges, subsetMinWtEdges, randMinWtEdges);
            }
        }
    }
}
//finds a specific amount of paths by constructing them randomly, but only using low weight edges, just calls CompletePathFromMinEdges a certain amount of times
void createPathsFromSubset(int partialPath[], double randMinWtEdges[], int isInvalid[], int adjCount[], int adjColumnIndex[], int adjRowPtr[], double adjWtArray[], double subsetMinWtEdges[], double pathEdges[], double keptPaths[], int numToCreate)
{
    int ll = 0;
    for(ll = 0; ll < numToCreate; ll++)
    {
        countTries = 0;
        while(CompletePathFromMinEdges(partialPath, randMinWtEdges, isInvalid, adjCount, adjColumnIndex, adjRowPtr, adjWtArray, subsetMinWtEdges, pathEdges, keptPaths) == false)
        {
            countTries++;
            if(countTries > 10000 && numToCreate < 1000)
            {
                //printf("TOOOO MANNNYYY TRIEEESSSS");
                tooManyTries = true;
                ll = numToCreate;
                break;
            }

        }
    }
}
//Returns true if a set of edges randMinWtEdges forms a valid partial path (and sets Partial path to this valid partial path) false otherwise
bool isValidPartialPath(double randMinWtEdges[],  int partialPath[], int rowsToRemove[], int adjRowPtr[], int adjColumnIndex[], int randMinEdges, bool print)
{

    for(i = 0; i < lengthOfPath; i++)
    {
        partialPath[i]= 0;
    }
    //loops through random subset of low weight edges
    for(i = 0; i < randMinEdges; i++)
    {
        //loops through random subset of low weight edges
        for(j = 0; j < randMinEdges; j++)
        {
            //printf("%d %d \n", i, j);
            //returns false if row is used twice, if 2 edges are using the same row, if a row is skipped that an edge is in, or if a stick is used twice
            if(!edgesAreValid(i, j, randMinWtEdges))
            {
                return false;
            }
        }
    }
    //constructs the partial path, not always valid at this point
    constructPartialPath(partialPath, randMinWtEdges, rowsToRemove);

     for(i = 0; i < lengthOfPath; i++)
     {
         if(print == true)
        printf("%d ", partialPath[i]);
     }
     if(print == true)
    printf("\n\n");

    //checks if the edges that are formed after the partial path is constructed actually exist
    if(!checkNewEdges(partialPath, adjRowPtr, adjColumnIndex))
    {
        return false;
    }


    return true;
}
//returns false if row is used twice, if 2 edges are using the same row, if a row is skipped that an edge is in, or if a stick is used twice
bool edgesAreValid(int index1, int index2, double randMinWtEdges[])
{
    int k = 0;
    //return false if row is used twice
            if(index1 != index2 && (randMinWtEdges[index1*5] == randMinWtEdges[index2*5] || randMinWtEdges[index1*5+2] == randMinWtEdges[index2*5+2]))
            {
                return false;
            }

            //return false if 2 edges are in the same row, but not going to the same node
            if(randMinWtEdges[index1*5] == randMinWtEdges[index2*5+2])
            {
                if(randMinWtEdges[index1*5+1] != randMinWtEdges[index2*5+3])
                {
                    //printf("false1\n");
                    return false;
                }
            }
            //return false if one edge skips a row that another edge is in
            if((randMinWtEdges[index1*5+2] - randMinWtEdges[index1*5]) != 1)
            {
                for(k = 1; k < randMinWtEdges[index1*5+2] - randMinWtEdges[index1*5]; k++)
                {
                    if(randMinWtEdges[index1*5]+k == randMinWtEdges[index2*5] || randMinWtEdges[index1*5]+k == randMinWtEdges[index2*5+2])
                    {
                        //printf("false2\n");
                        return false;
                    }
                }
            }
            //return false if a stick is used twice
            if((int)randMinWtEdges[index1*5+1] % 2 == 1)
            {
                if(index1 != index2 && (randMinWtEdges[index1*5+1] == randMinWtEdges[index2*5+1] || randMinWtEdges[index1*5+1] == randMinWtEdges[index2*5+1]+1 || randMinWtEdges[index1*5+1] == randMinWtEdges[index2*5+3] || randMinWtEdges[index1*5+1] == randMinWtEdges[index2*5+3]+1 ))
                {
                    //printf("false3\n");
                    return false;
                }
            }
            if((int)randMinWtEdges[index1*5+1] % 2 == 0)
            {
                if(index1 != index2 && (randMinWtEdges[index1*5+1] == randMinWtEdges[index2*5+1] || randMinWtEdges[index1*5+1] == randMinWtEdges[index2*5+1]-1 || randMinWtEdges[index1*5+1] == randMinWtEdges[index2*5+3] || randMinWtEdges[index1*5+1] == randMinWtEdges[index2*5+3]-1 ))
                {
                    //printf("false4\n");
                    return false;
                }
            }
            if((int)randMinWtEdges[index1*5+3] % 2 == 1)
            {
                if(index1 != index2 && ((randMinWtEdges[index1*5+3] == randMinWtEdges[index2*5+1] &&  randMinWtEdges[index1*5+2] != randMinWtEdges[index2*5+2]) || randMinWtEdges[index1*5+3] == randMinWtEdges[index2*5+1]+1 || randMinWtEdges[index1*5+3] == randMinWtEdges[index2*5+3] || randMinWtEdges[index1*5+3] == randMinWtEdges[index2*5+3]+1 ))
                {
                    //printf("false5\n");
                    return false;
                }
            }
            if((int)randMinWtEdges[index1*5+3] % 2 == 0)
            {
                if(index1 != index2 && ((randMinWtEdges[index1*5+3] == randMinWtEdges[index2*5+1] &&  randMinWtEdges[index1*5+2] != randMinWtEdges[index2*5+2])|| randMinWtEdges[index1*5+3] == randMinWtEdges[index2*5+1]-1 || randMinWtEdges[index1*5+3] == randMinWtEdges[index2*5+3] || randMinWtEdges[index1*5+3] == randMinWtEdges[index2*5+3]-1 ))
                {
                   // printf("false6\n");
                    return false;
                }
            }
            return true;
}
//constructs the partial path, not always valid at this point
void constructPartialPath(int partialPath[], double randMinWtEdges[], int rowsToRemove[])
{
    //constructs partial path
    //printf("true\n");
    int k = 0;
    for(i = 0; i < randMinEdges*5; i+=5)
    {
        for(j = 0; j < numToRemove; j++)
        {
            if(rowsToRemove[j]+1 < randMinWtEdges[i])
            {
                k++;
            }
        }

        partialPath[(int)randMinWtEdges[i]-k-1] = (randMinWtEdges[i]-1)*M+randMinWtEdges[i+1];
        partialPath[(int)randMinWtEdges[i]-k] = (randMinWtEdges[i+2]-1)*M+randMinWtEdges[i+3];
        k = 0;
    }
}
//checks if the edges that are formed after the partial path is constructed actually exist
bool checkNewEdges(int partialPath[], int adjRowPtr[], int adjColumnIndex[])
{
    bool validPath = true;
    for(i = 1; i < lengthOfPath; i++)
    {   //checks that all edges actually exist
        if(partialPath[i-1] != 0 && partialPath[i] != 0)
        {
            validPath = false;
            //printf("%d %d",partialPath[i-1], adjRowPtr[partialPath[i-1]]);
            for(j = adjRowPtr[partialPath[i-1]]; j < adjRowPtr[partialPath[i-1]+1]; j++)
            {
                if(adjColumnIndex[j] == partialPath[i])
                {
                    validPath = true;
                    j = adjRowPtr[partialPath[i-1]+1];
                }
            }
            if(validPath == false)
            {
                //printf("Edge does not exist!");
                return false;
            }
        }
    }
    return true;
}
//completes a partial path randomly, returns false if this is not possible
bool CompletePathRandom(int partialPath[], double randMinWtEdges[], int isInvalid[], int adjCount[], int adjColumnIndex[], int adjRowPtr[], double adjWtArray[], double keptPaths[])
{
    int temp = 1;
    int randTemp = 0;
    int nxtValid = 0;
    int count = 0;
    int tries = 0;
    bool validPath = false;

    for(i = 0; i < lengthOfPath; i++)
    {
        //printf("original:%d ", partialPath[i]);
    }
    //printf("\n");

    for(i = 0; i < M; i++)
    {
        isInvalid[i] = 0;
    }

    //marks isInvalid so that sticks arent used twice
    for(i = 0; i < lengthOfPath; i++)
    {
        if(partialPath[i] != 0)
        {
            repeatedStick(isInvalid, (partialPath[i]%M));
        }
    }
    //finds first in path if it hasn't already happened
    if(partialPath[1] == 0)
    {
        firstInPath(partialPath);
    }
    //printf("%d ", partialPath[0]);
    //finds the place the path should start at
    temp = whereToStartPath(partialPath);
    //printf("%d \n\n", temp);

    //finds the rest of the path
    for(i = temp; i < lengthOfPath; i++)
    {
        if(partialPath[i+1] == 0)
        {
            do{
                tries++;
                if(tries > 1000)
                {
                    //printf("too many attempts!!!!\n\n");
                    return false;
                }
                if((adjCount[partialPath[i-1]]) != 0)
                {
                    randTemp = (rand() % (adjCount[partialPath[i-1]]));
                }
                else
                    count = 1;

                nxtValid = adjColumnIndex[randTemp + adjRowPtr[partialPath[i-1]]];

            //printf("%d %d %d ",nxtValid, isInvalid[nxtValid % M], count);
            }while( isInvalid[nxtValid % M] == 1 || count == 1);

            count = 0;
            repeatedStick(isInvalid, (nxtValid%M));
            partialPath[i] = nxtValid;
            //printf("%d ", partialPath[i]);
            tries = 0;
        }
        else if(partialPath[i+1] != 0)
        {
            do{
                tries++;
                if(tries > 1000)
                {
                    //printf("too many attempts!!!!\n\n");
                    return false;
                }

                if((adjCount[partialPath[i-1]]) != 0)
                {
                    randTemp = (rand() % (adjCount[partialPath[i-1]]));
                }
                else
                    count = 1;

                nxtValid = adjColumnIndex[randTemp + adjRowPtr[partialPath[i-1]]];

                validPath = false;

                for(j = adjRowPtr[nxtValid]; j < adjRowPtr[nxtValid+1]; j++)
                {
                    if(adjColumnIndex[j] == partialPath[i+1])
                    {
                        validPath = true;
                        j = adjRowPtr[nxtValid+1];
                    }
                }

            //printf("%d ",nxtValid);
            }while( isInvalid[nxtValid % M] == 1 || count == 1 || validPath == false);

            count = 0;
            repeatedStick(isInvalid, (nxtValid%M));
            partialPath[i] = nxtValid;
           // printf("%d ", partialPath[i]);
            i = lengthOfPath;
            tries = 0;


            for(j = 0; j < lengthOfPath; j++)
            {
                if(partialPath[j] == 0)
                {
                    i = j-1;
                    j = lengthOfPath;
                }
            }

        }
    }

    for(i = 0; i < lengthOfPath; i++)
     {
        //printf("%d ", partialPath[i]);
     }
     double x = findWtOfPath(partialPath, adjColumnIndex, adjWtArray, adjRowPtr);
     //printf("\t %f ", x);
    //printf("\n");
    keepPath(keptPaths, partialPath, x);
    return true;
}
//finds the place the path should start at
int whereToStartPath(int partialPath[])
{
    int pathPosition = 1;
    if(partialPath[1] != 0)
    {
        //printf("%d ", partialPath[1]);
        for(i = 1; i < lengthOfPath; i++)
        {
            if(partialPath[i] != 0)
            {
                pathPosition++;
            }
            if(partialPath[i] == 0)
            {
                break;
            }
        }
    }
    return pathPosition;
}
//completes a partial path by assigning probabilities to the possible edges to add to the path
bool CompletePathProbabilistic(int partialPath[], double randMinWtEdges[], int isInvalid[], int adjCount[], int adjColumnIndex[], int adjRowPtr[], double adjWtArray[], double keptPaths[], double probability[], double wtsForChoosing)
{
    int temp = 1;
    int nxtValid = 0;
    int count = 0;
    int tries = 0;
    bool validPath = false;
    randomTemp = 0;
    int valid = 0;

    for(i = 0; i < lengthOfPath; i++)
    {
        //printf("%d ", partialPath[i]);
    }
    //printf("\n");

    for(i = 0; i < M; i++)
    {
        isInvalid[i] = 0;
    }

    //marks isInvalid so that sticks arent used twice
    for(i = 0; i < lengthOfPath; i++)
    {
        if(partialPath[i] != 0)
        {
            valid++;
            repeatedStick(isInvalid, (partialPath[i]%M));
        }
    }

    //for when we need to mark the first stick because the path begins with 0
    if(valid == 1)
    {
        //printf("%d ", isInvalid[0]);
        repeatedStick(isInvalid, (partialPath[0]%M));
        //printf("%d ", isInvalid[0]);
    }
    //printf("%d ", valid);
    //finds first in path if it hasn't already happened
    if(partialPath[1] == 0)
    {
        firstInPath(partialPath);
        while(isInvalid[partialPath[0]] == 1)
        {
            firstInPath(partialPath);
        }
        repeatedStick(isInvalid, (partialPath[0]%M));
    }
    //to fix a bug
    if(partialPath[1] != 0 && partialPath[2] != 0)
    {
        partialPath[0] = -1;
    }
    //printf("%d ", partialPath[0]);
    //finds the place the path should start at
    temp = whereToStartPath(partialPath);
    //printf("%d \n\n", temp);

    //finds the rest of the path
    for(i = temp; i < lengthOfPath; i++)
    {
        normalizeByMax(adjCount, probability, adjWtArray, adjRowPtr, partialPath, wtsForChoosing);

        if(partialPath[i+1] == 0 || i == lengthOfPath-1)
        {
            do{
                tries++;
                if(tries > 1000)
                {
                    //printf("too many attempts!!!!\n\n");
                    return false;
                }
                if((adjCount[partialPath[i-1]]) != 0)
                {
                    correctBiasedChoice(probability, adjCount, partialPath, adjWtArray, adjRowPtr);
                }
                else
                    count = 1;

                nxtValid = adjColumnIndex[randomTemp + adjRowPtr[partialPath[i-1]]];

            //printf("%d %d %d ",nxtValid, isInvalid[nxtValid % M], count);
            }while( isInvalid[nxtValid % M] == 1 || count == 1);

            count = 0;
            repeatedStick(isInvalid, (nxtValid%M));
            partialPath[i] = nxtValid;
            //printf("%d ", partialPath[i]);
            tries = 0;
        }
        else if(partialPath[i+1] != 0 && i < lengthOfPath-1)
        {
            do{
                tries++;
                if(tries > 1000)
                {
                    //printf("too many attempts!!!!\n\n");
                    return false;
                }

                if((adjCount[partialPath[i-1]]) != 0)
                {
                    correctBiasedChoice(probability, adjCount, partialPath, adjWtArray, adjRowPtr);
                }
                else
                    count = 1;

                nxtValid = adjColumnIndex[randomTemp + adjRowPtr[partialPath[i-1]]];

                validPath = false;
                for(j = adjRowPtr[nxtValid]; j < adjRowPtr[nxtValid+1]; j++)
                {
                    //printf("%d ", partialPath[i+1]);
                    //printf("%d ", i+1);
                    if(adjColumnIndex[j] == partialPath[i+1])
                    {
                        validPath = true;
                        j = adjRowPtr[nxtValid+1];
                    }
                }

            //printf("%d ",nxtValid);
            }while( isInvalid[nxtValid % M] == 1 || count == 1 || validPath == false);

            count = 0;
            repeatedStick(isInvalid, (nxtValid%M));
            partialPath[i] = nxtValid;
           // printf("%d ", partialPath[i]);
            i = lengthOfPath;
            tries = 0;


            for(j = 1; j < lengthOfPath; j++)
            {
                if(partialPath[j] == 0)
                {
                    i = j-1;
                    j = lengthOfPath;
                }
            }

        }
    }


    //checking if first value of path was skipped
    for(i = 0; i < adjRowPtr[1]; i++)
    {
        validPath = false;
        if(adjColumnIndex[i] == partialPath[1] && partialPath[0] != -1)
        {
            validPath = true;
            i = adjRowPtr[1];
        }
    }
    int y = 0;
    double tmpWT = 1000000;
    //for when it is skipped

    if(validPath == false)
    {
        for(i = 0; i < adjRowPtr[M-1]; i++)
        {
            if(i == adjRowPtr[y])
            {
                y++;
            }
            if(adjColumnIndex[i] == partialPath[1] && isInvalid[y] != 1 && adjWtArray[i] < tmpWT)
            {
                validPath = true;
                partialPath[0] = y;
                tmpWT = adjWtArray[i];
            }
        }
    }

    if(validPath == false)
    {
        //printf("dddddddd");
        return false;
    }

    for(i = 0; i < lengthOfPath; i++)
     {
        //printf("%d ", partialPath[i]);
     }
     double x = findWtOfPath(partialPath, adjColumnIndex, adjWtArray, adjRowPtr);
     //printf("\t %f ", x);
    //printf("\n");

    //some paths created are invalid, this ensures they are not saved, fixed!
    if(!pathIsValid(partialPath, adjRowPtr, adjColumnIndex, adjWtArray, adjCount))
        return false;

    keepPath(keptPaths, partialPath, x);
    return true;
}
//constructs a path based on the subset of small weight edges. does this randomly just like findPaths
bool CompletePathFromMinEdges(int partialPath[], double randMinWtEdges[], int isInvalid[], int adjCount[], int adjColumnIndex[], int adjRowPtr[], double adjWtArray[], double subsetMinWtEdges[], double p[], double keptPaths[])
{
    int possibleChoices[500];
    int k = 0;
    int randTemp = 0;
    int verifiedStick[M];

    //initializes possibleChoices, path and verifiedStick
    for(i = 0; i < 500; i++)
    {
        possibleChoices[i] = -1;
        if(i < M)
        {
            verifiedStick[i] = 0;
        }
        if(i < lengthOfPath*5)
        {
            p[i] = 0;
        }
    }

    //printf("%d ", subsetMinEdges);
    //first node choosing
    for(i = 0; i < subsetMinEdges*5; i+=5)
    {
        //if the current edge is at beginning of path add it to the possible choices
        if(subsetMinWtEdges[i] == 1)
        {
            possibleChoices[k] = i;
            k++;
        }
    }

    if(k == 0)
    {
        printf("THIS NEEDS TO BE FIXED");
    }
    else
    {

        //printf("%d ", k);
        //randomly choose one of the possible choices
        randTemp = (rand() % (k));
        //printf("%d ", randTemp);
        //set the path equal to the choice we have made
        p[0] = subsetMinWtEdges[possibleChoices[randTemp]];
        p[1] = subsetMinWtEdges[possibleChoices[randTemp]+1];
        p[2] = subsetMinWtEdges[possibleChoices[randTemp]+2];
        p[3] = subsetMinWtEdges[possibleChoices[randTemp]+3];
        p[4] = subsetMinWtEdges[possibleChoices[randTemp]+4];

        repeatedStick(verifiedStick, ((int)p[1]));

    }

    //attempts to finish entire path
    for(i = 0; i < lengthOfPath; i++)
    {
        //resets the possible choices
        for(j = 0; j < 500; j++)
        {
            possibleChoices[j] = -1;
        }
        //resets k the amount of possible choices
        k = 0;

        for(j = 0; j < subsetMinEdges*5; j+=5)
        {
            //printf("%f %f %f %f \n", subsetMinWtEdges[j] , p[i*5+2], subsetMinWtEdges[j+1] , p[i*5+3]);
            //if the current edge matches with the previous one and is not using a stick twice, add it to the possible choices
            //printf("%d ", j);
            if(subsetMinWtEdges[j] == p[i*5+2] && subsetMinWtEdges[j+1] == p[i*5+3] && verifiedStick[(int)subsetMinWtEdges[j+3]] != 1)
            {
                possibleChoices[k] = j;
                k++;
            }
        }
        //printf("%d ", k);
        //if there is a possible choice, select it randomly and add it to the path
        if(k != 0)
        {
            randTemp = (rand() % (k));
            p[i*5+5] = subsetMinWtEdges[possibleChoices[randTemp]];
            p[i*5+6] = subsetMinWtEdges[possibleChoices[randTemp]+1];
            p[i*5+7] = subsetMinWtEdges[possibleChoices[randTemp]+2];
            p[i*5+8] = subsetMinWtEdges[possibleChoices[randTemp]+3];
            p[i*5+9] = subsetMinWtEdges[possibleChoices[randTemp]+4];

            //mark verifiedStick so that it is not used twice
            repeatedStick(verifiedStick, ((int)p[i*5+8]));
            repeatedStick(verifiedStick, ((int)p[i*5+6]));

        }
        if(k == 0)
        {
            i = lengthOfPath;
        }

    }

    //if there is a partial path, transfer it to the correct format and print it then return true else return false
    if(p[lengthOfPath*5-6] != 0)
    {/*
        for(i = 0; i < lengthOfPath*5-5; i+=5)
        {
            printf("%.0f %.0f %.0f %.0f %f ", p[i], p[i+1], p[i+2], p[i+3], p[i+4]);
        }
        printf("\n\n");
        */

       int validPath[lengthOfPath];
       validPath[0] = (p[0]-1)*M+p[1];
       k = 1;
       for(i = 2; i < lengthOfPath*5-5; i +=5)
       {
           validPath[k] = (int)(p[i]-1)*M+p[i+1];
           k++;
       }
       for(i = 0; i < lengthOfPath; i++)
       {
           //printf("%d ", validPath[i]);
       }
       //pathIsValid(validPath, adjRowPtr, adjColumnIndex, adjWtArray, adjCount);
       double x = findWtOfPath(validPath, adjColumnIndex, adjWtArray, adjRowPtr);
       //printf("\t\t %f ", x);
       //printf("\n");
       keepPath(keptPaths, validPath, x);
       return true;

    }
    else
        return false;
}
//constructs a path deterministically from the subset of small weight edges
bool CompletePathDeterministic(double subsetMinWtEdges[], double randMinWtEdges[],  int partialPath[], int rowsToRemove[], int adjRowPtr[], int adjColumnIndex[], int isInvalid[], int adjCount[], double adjWtArray[], double keptPaths[])
{
    //indexes for loops
    bool impossible = false;
    int falseCount = 0;
    int index = 0;
    int jindex = 0;
    int k = 0;
    int l = 0;
    int subCount = 0;
    int tempPartialPath[lengthOfPath];
    //marks 1 if an edge is not vaild with the currentEdges set
    int markedValid[subsetMinEdges];
    //the current edges that will form a valid path
    double currentEdges[lengthOfPath*5];
    //variable stays true when markedValid is all 1's
    bool noMoreChoices = true;
    //initializes
    for(i = 0; i < subsetMinEdges; i++)
    {
        if(i < lengthOfPath*5)
        {
            currentEdges[i] = 0;
        }
        markedValid[i] = 0;
    }

    //loops through all edges and picks the first edge that is not marked 1
    for(index = 0; index < subsetMinEdges; index++)
    {
        //checks if it is marked 1
        if(markedValid[index] == 0)
        {
            //once the edge is selected we do not want to pick it again
            markedValid[index] = 1;
            //adds the edge we have selected to the current edges
            for(jindex = 0; jindex < 5; jindex++)
            {
                currentEdges[k*5+jindex] = subsetMinWtEdges[index*5+jindex];
            }
            //increments k so that we do not overwrite the edge we have just selected
            k++;
            //printf("%d ", k);
            //if this variable is not changed to false, we know that all the edges are now invalid with the current set
            noMoreChoices = true;
            //checks if every edge is possible to add to the current set
            for(jindex = 0; jindex < subsetMinEdges; jindex++)
            {
                //printf("\n");
                //printf("%d", jindex);
                //does not even attempt to check the edges that have already been marked 1
                if(markedValid[jindex] == 0)
                {
                    //changes the variable because we know that not every edge is invalid
                    noMoreChoices = false;
                    //adds the edge to compare to the current edges, but does not increment k because we will overwrite this edge
                    currentEdges[k*5] = subsetMinWtEdges[jindex*5];
                    currentEdges[k*5+1] = subsetMinWtEdges[jindex*5+1];
                    currentEdges[k*5+2] = subsetMinWtEdges[jindex*5+2];
                    currentEdges[k*5+3] = subsetMinWtEdges[jindex*5+3];
                    currentEdges[k*5+4] = subsetMinWtEdges[jindex*5+4];
                    //checks if the edge that we are checking is valid
                    if(isValidPartialPath(currentEdges, partialPath, rowsToRemove, adjRowPtr, adjColumnIndex, k+1, false) == false)
                    {
                        //if the edge is invalid, mark it with a 1
                        markedValid[jindex] = 1;
                    }
                    else
                    {
                        for(l = 0; l < lengthOfPath; l++)
                        {
                            tempPartialPath[l] = partialPath[l];
                            //printf("%d ", tempPartialPath[l]);
                        }
                    }
                }
            }
            /*
            for(l = 0; l < subsetMinEdges; l++)
            {
                printf("%d ", markedValid[l]);
            }
            */
            //when there are no more edges to compare, end all the loops
            if(noMoreChoices == true)
            {
                index = subsetMinEdges;
            }
        }
    }
    //sometimes there is an edge that does not belong at the end, tis if statement fixes this problem
    if(isValidPartialPath(currentEdges, partialPath, rowsToRemove, adjRowPtr, adjColumnIndex, k+1, false) == false)
    {
        currentEdges[k*5] = 0;
        currentEdges[k*5+1] = 0;
        currentEdges[k*5+2] = 0;
        currentEdges[k*5+3] = 0;
        currentEdges[k*5+4] = 0;
        isValidPartialPath(currentEdges, partialPath, rowsToRemove, adjRowPtr, adjColumnIndex, k, false);
        for(l = 0; l < lengthOfPath; l++)
        {
            tempPartialPath[l] = partialPath[l];
            //printf("%d ", tempPartialPath[l]);
        }
    }


    for(index = 0; index < lengthOfPath*5; index++)
    {
        //printf("%f ", currentEdges[index]);
    }
    //printf("\n");

    for(index = 0; index < lengthOfPath; index++)
        {
            printf("%d ", tempPartialPath[index]);
        }
    //attempts to create a path from the current edges we have selected
    printf("\nPath constructed Deterministically: \n");
    //if a path cannot be constructed, let the user know
    if(CompletePathRandom(tempPartialPath, randMinWtEdges, isInvalid, adjCount, adjColumnIndex, adjRowPtr, adjWtArray, keptPaths) == false)
    {
        printf("Path constructed is not valid\n");
        for(index = 0; index < lengthOfPath; index++)
        {
            printf("%d ", tempPartialPath[index]);
        }
         printf("\n");

         while(CompletePathRandom(tempPartialPath, randMinWtEdges, isInvalid, adjCount, adjColumnIndex, adjRowPtr, adjWtArray, keptPaths) == false && impossible == false)
         {
             falseCount++;
             if(falseCount > 100)
             {
                 falseCount = 0;
                 for(index = lengthOfPath*5; index > 0; index--)
                 {
                     if(currentEdges[index] != 0)
                     {
                         subCount = ((index+1)/5)-1;
                         //printf("%d ", subCount);
                         currentEdges[index] = 0;
                         currentEdges[index-1] = 0;
                         currentEdges[index-2] = 0;
                         currentEdges[index-3] = 0;
                         currentEdges[index-4] = 0;
                       index = 0;

                     }
                 }
                 isValidPartialPath(currentEdges, partialPath, rowsToRemove, adjRowPtr, adjColumnIndex, subCount, false);

                 for(l = 0; l < lengthOfPath; l++)
                 {
                    tempPartialPath[l] = partialPath[l];
                    //printf("%d ", tempPartialPath[l]);
                 }
                 //printf("\n");
             }


         }
         printf("Fixed path:\n");
         for(index = 0; index < lengthOfPath; index++)
        {
            printf("%d ", tempPartialPath[index]);
        }
        printf("%f", findWtOfPath(tempPartialPath, adjColumnIndex, adjWtArray, adjRowPtr));
        printf("\n\n");

        return false;
    }
        /*
    else
    {
        for(i = 0; i < lengthOfPath; i++)
         {
            printf("%d ", tempPartialPath[i]);
         }
        printf("\n\n");
        return true;
    }
*/

    //prints the edges we selected. used for debugging
    for(i = 0; i < lengthOfPath*5; i++)
    {
        //printf("%f ", currentEdges[i]);
    }
   //printf("\n");
return true;
}
