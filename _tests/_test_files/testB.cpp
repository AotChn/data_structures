#include "gtest/gtest.h"
#include <iostream>
#include <iomanip>

#include "../../includes/avl/avl.h"
#include "../../includes/avl/avl_functions.h"

using namespace std;

//----------------------------------------------------
//TEST MACROS //

#define avl_insert1 DISABLED_avl_insert1
#define avl_insert2 DISABLED_avl_insert2
#define avl_insert3 DISABLED_avl_insert3
// #define avl_insert4 DISABLED_avl_insert4



//----------------------------------------------------

class test_avl1 : public testing::Test{
  protected:
  AVL<int> a;
};

TEST_F(test_avl1, avl_insert1){
  for(int i=0; i<9;i++){
    a.insert(i);
  }
  std::cout<< a;
}

TEST_F(test_avl1, avl_insert2){
  for(int i=1; i<50;i++){
    a.insert(i);
  }
  std::cout<< a;
}

TEST_F(test_avl1, avl_insert3){
  for(int i=100; i<130;i++){
    a.insert(i);
  }
  std::cout<< a;
}

TEST_F(test_avl1, avl_insert4){
  for(int i=100000; i<100006;i++){
    a.insert(i);
  }
  std::cout<< a;
}


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  std::cout<<"\n\n----------running testB.cpp---------\n\n"<<std::endl;
  return RUN_ALL_TESTS();
}

