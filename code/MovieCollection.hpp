#pragma once
#ifndef MovieCollection_H__
#define MovieCollection_H__

#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <sstream>

// Base class (pre-compiled from the solution to last week's assignment)
#include "../library/MovieCollectionBase.hpp"

using namespace std; 

class MovieCollection : public MovieCollectionBase {

    public:
        MovieCollection();
        ~MovieCollection();

        // Add new function definitions here
        void removeMovie(string movieName);
        void rotateLeftCollection(string movieName); // (LEFT ROTATE – To be mentioned in the readme) 
        string closestParent(string movie1, string movie2); // (Lowest Common Ancestor in a BST)
        string closestParentHelper(Movie* node, string movie1, string movie2);
        Movie* getRoot(){
            return root;
        }

        // void addBook(string bookName, string author, double rating);
        // void showBookCollection();
        // void showBook(string bookName);
        // void showBooksByAuthor(string author);
        // void showHighestRatedBooks();
        // int getHeightOfBookCollection();
};

//----------------- DONOT change the code given below --------------------------//
/**************** you can ignore this ******************/
/*     TraceNode memcheck definitions                  ***********/
/*     This will keep track of memory allocation and deallocation*/
/*     This is required for overloading new and delete **********/
/****************************************************************/

// struct traceNode
// {
//   std::string pType;
//   void *ptr;
//   traceNode *next = NULL;
//   traceNode(){}
//   traceNode(std::string t, void *p, traceNode *n) : pType(t), ptr(p), next(n) {}
// };

// extern traceNode *traceHead;
// extern bool verbose;
// extern int numAllocs;

// inline traceNode * addTraceNode(std::string pType, void *ptr, traceNode *traceHead)
// {
//   traceNode *nn = new traceNode(pType, ptr, traceHead);
//   return nn;
// }

// inline traceNode * removeTraceNode(traceNode *traceHead, void *ptr)
// {

//   if (traceHead == nullptr){
//     std::cerr << "[ERROR] Attempted to delete a node that was never allocated." << std::endl;
//     exit(1);
//   }
//   else if (traceHead->ptr == ptr){
//     traceNode *tmp = traceHead->next;
//     delete traceHead;
//     return tmp;
//   }
//   else{
//     traceHead->next = removeTraceNode(traceHead->next, ptr);
//     return traceHead;
//   }
// }
// //----------------------Overloads tree nodes---------------------------
// inline void* Movie::operator new(std::size_t bytes)
// {
//   numAllocs += 1;
//   void * buf = malloc(bytes);
//   memset(buf, 0x0, bytes);

//   if(verbose){
//     std::cout << "[GRADER] Created Movie with address: " << buf << std::endl;
//   }

//   traceHead = addTraceNode("BST", buf, traceHead);

//   return buf;
// }

// inline void Movie::operator delete(void *ptr)
// {
//   numAllocs -= 1;

//   if (verbose){
//       std::cout << "[GRADER] Deleted Movie with address: " << ptr << std::endl;
//   }

//   traceHead = removeTraceNode(traceHead, ptr);

//   free(ptr);
// }

// inline void printNode(traceNode * n)
// {
//   if(n->pType=="BST"){
//     Movie *b = (Movie*) n->ptr;
//     cout << "    Movie <" << b->movieName << ">" << endl;
//   }
// }

#endif
