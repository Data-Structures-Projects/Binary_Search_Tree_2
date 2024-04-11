#include "MovieCollection.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

MovieCollection::MovieCollection() {
    root = nullptr;
}

void _destructMovieCollection(Movie *movie) {
    if (movie == nullptr) return;
    else {
        _destructMovieCollection(movie->left);
        _destructMovieCollection(movie->right);
        delete movie;
    }
}

MovieCollection::~MovieCollection() {
    _destructMovieCollection(root);
}



void MovieCollection::removeMovie(string movieName) {
    Movie* temp = root;
    Movie* prev;
    while(temp && temp->movieName != movieName){
        if(movieName > temp->movieName){
            prev = temp;
            temp = temp->right;
        }else{
            prev = temp;
            temp = temp->left;
        }
    }
    if(!temp){
        cout << "Movie not found!" << endl;
        return;
    }
    if(!temp->left && !temp->right){
        delete temp;
        return;
    }
    if(!temp->left || !temp->right){
        if(!temp->left){
            if(temp == root){
                root = temp->right;
                delete temp;
                return;
            }
            if(temp->movieName > prev -> movieName){
                prev->right = temp -> right;
                delete temp;
                return;
            }else{
                prev->left = temp -> right;
                delete temp;
                return;
            }
        }
        if(!temp->right){
            if(temp == root){
                root = temp->left;
                delete temp;
                return;
            }
            if(temp->movieName > prev -> movieName){
                prev->right = temp -> left;
                delete temp;
                return;
            }else{
                prev->left = temp -> left;
                delete temp;
                return;
            }
        }
        
    }
    Movie* successor = temp->right;
    while(successor->left){
        successor = successor -> left;
    }
    if(successor-> right){
        Movie* succ_right;
        while(successor -> right){
            succ_right = successor -> right;
        }
        successor -> left = temp -> left;
        succ_right -> right = temp->right;
        delete successor;
        return;
    }
    successor -> left = temp -> left;
    temp = successor;
    delete successor;
}


void MovieCollection::rotateLeftCollection(string movieName) {
    Movie* x = root;
    Movie* xp;
    while(x && x->movieName != movieName){
        if(movieName > x->movieName){
            xp = x;
            x = x->right;
        }else{
            xp = x;
            x = x->left;
        }
    }
    if(!x){
        return;
    }
    if(!x->right){
        return;
    }
    if(x == root){
        Movie* y = x->right;
        Movie* yl = nullptr;
        if(y->left){
            yl = y->left;
        }
        root = y;
        x->right = yl;
        y->left = x;
        return;
    }
    Movie* y = x->right;
    Movie* yl = nullptr;
    if(y->left){
        yl = y->left;
    }
    if(xp->left){
            if(xp->left == x){
                xp->left = y;
                x->right = yl;
                y->left = x;
                return;
        }
    }else{
        xp->right = y;
        x->right = yl;
        y->left = x;
        return;
    }
}

string MovieCollection::closestParentHelper(Movie* node, string movie1, string movie2){
    if (node->movieName > movie1 && node->movieName > movie2){
        return closestParentHelper(node->left, movie1, movie2);
    }
    if (node->movieName < movie1 && node->movieName < movie2){
        return closestParentHelper(node->right, movie1, movie2);
    }
    return node->movieName;
}

string MovieCollection::closestParent(string movie1, string movie2) {
    Movie* one = root;
    Movie* two = root;
    while(one && one->movieName != movie1){
        if(movie1 > one->movieName){
            one = one->right;
        }else{
            one = one->left;
        }
    }
    while(two && two->movieName != movie2){
        if(movie2 > two->movieName){
            two = two->right;
        }else{
            two = two->left;
        }
    }
    if(!one){
        cout << "Movie not found!" << endl;
        return "Error - wrong movie name";
    }
    if(!two){
        cout << "Movie not found!" << endl;
        return "Error - wrong movie name";
    }
    return closestParentHelper(root, movie1, movie2);
}
