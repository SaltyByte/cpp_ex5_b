/**
 * Demo file for the exercise on binary tree
 *
 * @author Erel Segal-Halevi
 * @since 2021-04
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <vector>
#include <algorithm>

using namespace std;

#include "sources/BinaryTree.hpp"

using namespace ariel;

bool RandomBool() {
    return rand() % 2 == 0;
}

int main() {
//    BinaryTree<int> tree_of_ints;
//    tree_of_ints.add_root(1)
//            .add_left(1, 9)      // Now 9 is the left child of 1
//            .add_left(9, 4)      // Now 4 is the left child of 9
//            .add_right(9, 5)     // Now 5 is the right child of 9
//            .add_right(1, 3)     // Now 3 is the right child of 1
//            .add_left(1, 2);     // Now 2 is the left child of 1, instead of 9 (the children of 9 remain in place)
//
//    cout << tree_of_ints << endl;  /* Prints the tree in a reasonable format. For example:
//        1
//        |--------|
//        2        3
//        |---|
//        4   5
//  */
//
//    for (auto it = tree_of_ints.begin_preorder(); it != tree_of_ints.end_preorder(); ++it) {
//        cout << (*it) << " ";
//    }  // prints: 1 2 4 5 3
//    for (auto it = tree_of_ints.begin_inorder(); it != tree_of_ints.end_inorder(); ++it) {
//        cout << (*it) << " ";
//    }  // prints: 4 2 5 1 3
//    for (auto it = tree_of_ints.begin_postorder(); it != tree_of_ints.end_postorder(); ++it) {
//        cout << (*it) << " ";
//    }  // prints: 4 5 2 3 1
//
//    for (int element: tree_of_ints) {  // this should work like inorder
//        cout << element << " ";
//    }  // prints: 4 2 5 1 3
//
//
//    // The same should work with other types, e.g. with strings:
//
//    BinaryTree <string> tree_of_strings;
//    tree_of_strings.add_root("1")
//            .add_left("1", "9")      // Now 9 is the left child of 1
//            .add_left("9", "4")      // Now 4 is the left child of 9
//            .add_right("9", "5")     // Now 5 is the right child of 9
//            .add_right("1", "3")     // Now 3 is the right child of 1
//            .add_left("1", "2");     // Now 2 is the left child of 1, instead of 9 (the children of 9 remain in place)
//    cout << tree_of_strings << endl;
//
//    for (auto it = tree_of_strings.begin_preorder(); it != tree_of_strings.end_preorder(); ++it) {
//        cout << (*it) << " ";
//    }  // prints: 1 2 4 5 3
//    for (auto it = tree_of_strings.begin_inorder(); it != tree_of_strings.end_inorder(); ++it) {
//        cout << (*it) << " ";
//    }  // prints: 4 2 5 1 3
//    for (auto it = tree_of_strings.begin_postorder(); it != tree_of_strings.end_postorder(); ++it) {
//        cout << (*it) << " ";
//    }  // prints: 4 5 2 3 1
//
//    // demonstrate the arrow operator:
//    for (auto it = tree_of_strings.begin_postorder(); it != tree_of_strings.end_postorder(); ++it) {
//        cout << it->size() << " ";
//    }  // prints: 1 1 1 1 1
//
//
//    for (const string &element: tree_of_strings) {  // this should work like inorder
//        cout << element << " ";
//    }   // prints: 4 2 5 1 3
//
//    BinaryTree<int> tree1{};
//    tree1.add_root(1)
//            .add_left(1, 2)
//            .add_left(2, 4)
//            .add_right(2, 5)
//            .add_right(5, 6)
//            .add_right(6, 10)
//            .add_left(10, 7)
//            .add_right(10, 11)
//            .add_right(1, 3)
//            .add_left(3, 9)
//            .add_right(3, 8)
//            .add_left(7, 13)
//            .add_left(13, 14)
//            .add_left(9, 12);
//
//    BinaryTree<int> tree2{};
//    tree2.add_root(1)
//            .add_left(1, 2)
//            .add_left(2, 3)
//            .add_left(3, 4)
//            .add_left(4, 5);
//
//    BinaryTree<int> tree3{};
//    tree3.add_root(1)
//            .add_right(1, 2)
//            .add_right(2, 3)
//            .add_right(3, 4)
//            .add_right(4, 5);
//
//    BinaryTree<int> treeCpy1{tree1};
//    BinaryTree<int> treeEq1 = tree1;
//
//    BinaryTree<int> treeCpy2{tree2};
//    BinaryTree<int> treeEq2 = tree2;
//
//    BinaryTree<int> treeCpy3{tree3};
//    BinaryTree<int> treeEq3 = tree3;





//    for (auto it = tree1.begin_preorder(); it != tree1.end_preorder(); ++it) {
//        cout << *(it) << " ";
//    }
//    cout << endl;
//    for (auto it = tree1.begin_postorder(); it != tree1.end_postorder(); ++it) {
//        cout << *(it) << " ";
//    }
//    cout << endl;
//    for (auto it = tree1.begin_inorder(); it != tree1.end_inorder(); ++it) {
//        cout << *(it) << " ";
//    }
//
//    cout << endl;
//    cout << endl;
//
//    for (auto it = treeCpy1.begin_preorder(); it != treeCpy1.end_preorder(); ++it) {
//        cout << *(it) << " ";
//    }
//    cout << endl;
//    for (auto it = treeCpy1.begin_postorder(); it != treeCpy1.end_postorder(); ++it) {
//        cout << *(it) << " ";
//    }
//    cout << endl;
//    for (auto it = treeCpy1.begin_inorder(); it != treeCpy1.end_inorder(); ++it) {
//        cout << *(it) << " ";
//    }
//
//    cout << endl;
//    cout << endl;
//
//    for (auto it = treeEq1.begin_preorder(); it != treeEq1.end_preorder(); ++it) {
//        cout << *(it) << " ";
//    }
//    cout << endl;
//    for (auto it = treeEq1.begin_postorder(); it != treeEq1.end_postorder(); ++it) {
//        cout << *(it) << " ";
//    }
//    cout << endl;
//    for (auto it = treeEq1.begin_inorder(); it != treeEq1.end_inorder(); ++it) {
//        cout << *(it) << " ";
//    }
//
//    cout << endl;
//    cout << endl;
//    cout << endl;
//
//    for (auto it = tree2.begin_preorder(); it != tree2.end_preorder(); ++it) {
//        cout << *(it) << " ";
//    }
//    cout << endl;
//    for (auto it = tree2.begin_postorder(); it != tree2.end_postorder(); ++it) {
//        cout << *(it) << " ";
//    }
//    cout << endl;
//    for (auto it = tree2.begin_inorder(); it != tree2.end_inorder(); ++it) {
//        cout << *(it) << " ";
//    }
//
//    cout << endl;
//    cout << endl;
//
//    for (auto it = treeEq2.begin_preorder(); it != treeEq2.end_preorder(); ++it) {
//        cout << *(it) << " ";
//    }
//    cout << endl;
//    for (auto it = treeEq2.begin_postorder(); it != treeEq2.end_postorder(); ++it) {
//        cout << *(it) << " ";
//    }
//    cout << endl;
//    for (auto it = treeEq2.begin_inorder(); it != treeEq2.end_inorder(); ++it) {
//        cout << *(it) << " ";
//    }
//
//    cout << endl;
//    cout << endl;
//
//    for (auto it = treeCpy2.begin_preorder(); it != treeCpy2.end_preorder(); ++it) {
//        cout << *(it) << " ";
//    }
//    cout << endl;
//    for (auto it = treeCpy2.begin_postorder(); it != treeCpy2.end_postorder(); ++it) {
//        cout << *(it) << " ";
//    }
//    cout << endl;
//    for (auto it = treeCpy2.begin_inorder(); it != treeCpy2.end_inorder(); ++it) {
//        cout << *(it) << " ";
//    }
//
//    cout << endl;
//    cout << endl;
//    cout << endl;
//
//    for (auto it = tree3.begin_preorder(); it != tree3.end_preorder(); ++it) {
//        cout << *(it) << " ";
//    }
//    cout << endl;
//    for (auto it = tree3.begin_postorder(); it != tree3.end_postorder(); ++it) {
//        cout << *(it) << " ";
//    }
//    cout << endl;
//    for (auto it = tree3.begin_inorder(); it != tree3.end_inorder(); ++it) {
//        cout << *(it) << " ";
//    }
//
//    cout << endl;
//    cout << endl;
//
//    for (auto it = treeEq3.begin_preorder(); it != treeEq3.end_preorder(); ++it) {
//        cout << *(it) << " ";
//    }
//    cout << endl;
//    for (auto it = treeEq3.begin_postorder(); it != treeEq3.end_postorder(); ++it) {
//        cout << *(it) << " ";
//    }
//    cout << endl;
//    for (auto it = treeEq3.begin_inorder(); it != treeEq3.end_inorder(); ++it) {
//        cout << *(it) << " ";
//    }
//    cout << endl;
//    cout << endl;
//
//    for (auto it = treeCpy3.begin_preorder(); it != treeCpy3.end_preorder(); ++it) {
//        cout << *(it) << " ";
//    }
//    cout << endl;
//    for (auto it = treeCpy3.begin_postorder(); it != treeCpy3.end_postorder(); ++it) {
//        cout << *(it) << " ";
//    }
//    cout << endl;
//    for (auto it = treeCpy3.begin_inorder(); it != treeCpy3.end_inorder(); ++it) {
//        cout << *(it) << " ";
//    }

//
//
//    for (auto it = tree2.begin_preorder(); it != tree2.end_preorder(); ++it) {
//        cout << *(it) << " ";
//    }
//
//    cout << endl;
//
//    for (auto it = tree2.begin_postorder(); it != tree2.end_postorder(); ++it) {
//        cout << *(it) << " ";
//    }
//
//    cout << endl;
//
//    for (auto it = tree2.begin_inorder(); it != tree2.end_inorder(); ++it) {
//        cout << *(it) << " ";
//    }
//
//    cout << endl;
//
//    for (auto it = tree3.begin_preorder(); it != tree3.end_preorder(); ++it) {
//        cout << *(it) << " ";
//    }
//    cout << endl;
//    for (auto it = tree3.begin_postorder(); it != tree3.end_postorder(); ++it) {
//        cout << *(it) << " ";
//    }
//    cout << endl;
//    for (auto it = tree3.begin_inorder(); it != tree3.end_inorder(); ++it) {
//        cout << *(it) << " ";
//    }



    const int tsize = 5;
    vector<double> randomVals(tsize);
    auto random_unique_double = []() {
        static double n = 1;
        double v = (double) ((unsigned int) rand() % 100) / 100;
        n++;
        return n + v;
    };

    auto print = [](double n) { cout << ", " << n; };
    for (int i = 0; i < 5; i++) {
        generate(randomVals.begin(), randomVals.end(), random_unique_double);
        BinaryTree<double> tree;
        tree.add_root(randomVals[0]);

        // generate random tree, but with values that in the vector we created
        // this new tree inorder, postorder and preorder should be a permutation of the vector!
        for (unsigned int k = 1; k < randomVals.size(); k++) {
            if (RandomBool()) {
                tree.add_left(randomVals[k - 1], randomVals[k]);
            } else {
                tree.add_right(randomVals[k - 1], randomVals[k]);
            }
        }

        // looks like the checking permutation on the default iterator is impossible
        // so we copying tree values into a list and then comparing the two vectors.
        vector<double> copied(tsize);
        unsigned int j = 0;
        for (auto it = tree.begin_preorder(); it != tree.end_preorder(); ++it, j++) {
            copied[j] = *it;
        } // prints: 1 2 4 5 3
        is_permutation(copied.begin(), copied.end(), randomVals.begin(), randomVals.end());

    }
}


