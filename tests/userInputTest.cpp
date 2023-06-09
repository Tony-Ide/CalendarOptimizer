#include "../header/UserInterface.hpp"
#include "../src/UserInterface.cpp"

#include "gtest/gtest.h"

TEST(UserinputTest, TestUser) {
    UserInterface *UI = new UserInterface();
    UI->getLineFromUser();
    EXPECT_EQ(UI->getUserInput()[0],"add");
    delete UI;
}
TEST(UserinputTest, TestCommandAdd1){
    EXPECT_NO_THROW(new UserInterface("add task1 12/31 8 1"));
}
TEST(UserinputTest, TestCommandRemove){
    EXPECT_NO_THROW(new UserInterface("remove task1"));
}
TEST(UserinputTest, TestCommandEdit){
    EXPECT_NO_THROW(new UserInterface("edit task1 12/31 3 1"));
}
TEST(UserinputTest, TestCommandOrganize){
    EXPECT_NO_THROW(new UserInterface("organize"));
}

TEST(UserinputTest, TestWrongdate){
    try{a
        UserInterface *UI = new UserInterface("add task1 ab/cd 8 1");
    }
    catch(std::string err ){
        EXPECT_EQ(err, std::string("invalid month"));
        //EXPECT_TRUE(err.compare("invalid month"));
    }
}
TEST(UserinputTest, TestWrongTime){
    try{
        UserInterface *UI = new UserInterface("add task1 12/31 a 1");
    }
    catch(std::string err ){
        EXPECT_EQ( err,std::string("invalid duration time") );
    }
}
TEST(UserinputTest, TestWrongpriority){
   try{
        UserInterface *UI = new UserInterface("add task1 12/31 3 a");
    }
    catch(std::string err ){
        EXPECT_EQ( err,std::string("invalid proity") );
    }
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}