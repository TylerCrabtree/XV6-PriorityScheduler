#include "param.h"
#include "types.h"
#include "stat.h"
#include "user.h"
//Tyler Crabtree
//Modded

//remove magic numbers
#define first 0
#define second 1
#define third 2


int
main(int argc, char *argv[])
{
    // prompt user
	printf(third, "Initiating priority scheduler\n");
    //values 
	int priority;
    int key;

    // make sure two arguments 
	if(argc < 2){
	    printf(third, "Include exactly 1 argument (added more arguments) \n");
	    exit();
	}
    if(argc > 2){
	    printf(third, "Include exactly 1 argument (include less arguments) \n");
	    exit();
	}

    // grab priority (if there is one)
	priority = atoi(argv[second]);


    // if the priority is too large prompt user
    if (priority > 200){
      printf(first, "Ensure range is from 0 to 200\n");
	    exit();
    }
    char checky =  (argv[second][first]); //check for negative


     // if priority is zero (atoi will make negs zero)
     if (priority == first){
        if (checky == '-'){ // check for neg sign to prompt user
         printf(first, "Ensure range is from 0 to 200\n");
	    exit();
    }
}
    //set priority
	key = setpriority(priority);
    // prompt user everything went well.
	printf(first, "Updated previous priority %d\n", key);
    exit();

}
