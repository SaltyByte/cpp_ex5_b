#include "doctest.h"
#include "BinaryTree.hpp"
#include <string>

using namespace ariel;
using namespace std;

BinaryTree<int>initIntTree(){
    BinaryTree<int> Tree;
    Tree.add_root(1)
    .add_left(1,2)
    .add_left(2,4)
    .add_right(2,5)
    .add_right(5,6)
    .add_right(6,10)
    .add_left(10,7)
    .add_right(10,11)
    .add_right(1,3)
    .add_left(3,9)
    .add_right(3,8);
    return Tree;
}

BinaryTree<string>initStringTree(){
    BinaryTree<string> Tree;
    Tree.add_root("1")
    .add_left("1", "2")
    .add_left("2", "4")
    .add_right("2", "5")
    .add_right("5", "6")
    .add_right("6", "10")
    .add_left("10", "7")
    .add_right("10", "11")
    .add_right("1", "3")
    .add_left("3", "9")
    .add_right("3", "8");
    return Tree;
}


//TEST_CASE("Pre Order Test Case"){
//    BinaryTree<int> treeInt = initIntTree();
//    auto iterInt = treeInt.begin_preorder();
//    CHECK(*iterInt == 1);
//    ++iterInt;
//    CHECK(*iterInt == 2);
//    ++iterInt;
//    CHECK(*iterInt == 4);
//    ++iterInt;
//    CHECK(*iterInt == 5);
//    ++iterInt;
//    CHECK(*iterInt == 6);
//    ++iterInt;
//    CHECK(*iterInt == 10);
//    ++iterInt;
//    CHECK(*iterInt == 7);
//    ++iterInt;
//    CHECK(*iterInt == 11);
//    ++iterInt;
//    CHECK(*iterInt == 3);
//    ++iterInt;
//    CHECK(*iterInt == 9);
//    ++iterInt;
//    CHECK(*iterInt == 8);
//    ++iterInt;
//    CHECK(iterInt == treeInt.end_preorder());
//
//    BinaryTree<string> treeString = initStringTree();
//    auto iterString = treeString.begin_preorder();
//    CHECK(*iterString == "1");
//    ++iterString;
//    CHECK(*iterString == "2");
//    ++iterString;
//    CHECK(*iterString == "4");
//    ++iterString;
//    CHECK(*iterString == "5");
//    ++iterString;
//    CHECK(*iterString == "6");
//    ++iterString;
//    CHECK(*iterString == "10");
//    ++iterString;
//    CHECK(*iterString == "7");
//    ++iterString;
//    CHECK(*iterString == "11");
//    ++iterString;
//    CHECK(*iterString == "3");
//    ++iterString;
//    CHECK(*iterString == "9");
//    ++iterString;
//    CHECK(*iterString == "8");
//    ++iterString;
//    CHECK(iterString == treeString.end_preorder());
//}

TEST_CASE("In Order Test Case"){
    BinaryTree<int> treeInt = initIntTree();
    auto iterInt = treeInt.begin_inorder();
    CHECK(*iterInt == 4);
    ++iterInt;
    CHECK(*iterInt == 2);
    ++iterInt;
    CHECK(*iterInt == 5);
    ++iterInt;
    CHECK(*iterInt == 6);
    ++iterInt;
    CHECK(*iterInt == 7);
    ++iterInt;
    CHECK(*iterInt == 10);
    ++iterInt;
    CHECK(*iterInt == 11);
    ++iterInt;
    CHECK(*iterInt == 1);
    ++iterInt;
    CHECK(*iterInt == 9);
    ++iterInt;
    CHECK(*iterInt == 3);
    ++iterInt;
    CHECK(*iterInt == 8);
    ++iterInt;
    CHECK(iterInt == treeInt.end_inorder());

    BinaryTree<string> treeString = initStringTree();
    auto iterString = treeString.begin_inorder();
    CHECK(*iterString == "4");
    ++iterString;
    CHECK(*iterString == "2");
    ++iterString;
    CHECK(*iterString == "5");
    ++iterString;
    CHECK(*iterString == "6");
    ++iterString;
    CHECK(*iterString == "7");
    ++iterString;
    CHECK(*iterString == "10");
    ++iterString;
    CHECK(*iterString == "11");
    ++iterString;
    CHECK(*iterString == "1");
    ++iterString;
    CHECK(*iterString == "9");
    ++iterString;
    CHECK(*iterString == "3");
    ++iterString;
    CHECK(*iterString == "8");
    ++iterString;
    CHECK(iterString == treeString.end_inorder());

}

TEST_CASE("Post Order Test Case"){
    BinaryTree<int> treeInt = initIntTree();
    auto iterInt = treeInt.begin_postorder();
    CHECK(*iterInt == 4);
    ++iterInt;
    CHECK(*iterInt == 7);
    ++iterInt;
    CHECK(*iterInt == 11);
    ++iterInt;
    CHECK(*iterInt == 10);
    ++iterInt;
    CHECK(*iterInt == 6);
    ++iterInt;
    CHECK(*iterInt == 5);
    ++iterInt;
    CHECK(*iterInt == 2);
    ++iterInt;
    CHECK(*iterInt == 9);
    ++iterInt;
    CHECK(*iterInt == 8);
    ++iterInt;
    CHECK(*iterInt == 3);
    ++iterInt;
    CHECK(*iterInt == 1);
    ++iterInt;
    CHECK(iterInt == treeInt.end_postorder());

    BinaryTree<string> treeString = initStringTree();
    auto iterString = treeString.begin_postorder();
    CHECK(*iterString == "4");
    ++iterString;
    CHECK(*iterString == "7");
    ++iterString;
    CHECK(*iterString == "11");
    ++iterString;
    CHECK(*iterString == "10");
    ++iterString;
    CHECK(*iterString == "6");
    ++iterString;
    CHECK(*iterString == "5");
    ++iterString;
    CHECK(*iterString == "2");
    ++iterString;
    CHECK(*iterString == "9");
    ++iterString;
    CHECK(*iterString == "8");
    ++iterString;
    CHECK(*iterString == "3");
    ++iterString;
    CHECK(*iterString == "1");
    ++iterString;
    CHECK(iterString == treeString.end_postorder());
}
TEST_CASE("Test Throws"){
    BinaryTree<int> tree {};
    CHECK_THROWS(tree.add_left(2,3));
    CHECK_THROWS(tree.add_right(2,3));
    auto start = tree.begin();
    auto end = tree.end();
    CHECK(start == end);
    tree.add_root(1);
    CHECK_THROWS(tree.add_root(2));
    CHECK_THROWS(tree.add_left(2,3));
    CHECK_THROWS(tree.add_right(2,3));

}