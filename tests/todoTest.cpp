#include "../header/todo.hpp"

#include "../header/date.hpp"

#include "../header/event.hpp"

#include "../header/task.hpp"
#include "../header/blackout_time.hpp"

#include "gtest/gtest.h"

TEST(EventTest, newEvent){
    Date* newDate= new Date(1,20);
    Event* e = new Event(newDate, "Baseball Practice", 1, 1230, 30, 1);
    EXPECT_EQ(e->getDate()->getMonth(),1);
    EXPECT_EQ(e->getDate()->getDay(),20);
    EXPECT_EQ(e->getName(),"Baseball Practice");
    EXPECT_EQ(e->getPriority(),1);
    EXPECT_EQ(e->getTime(), 1230);
    EXPECT_EQ(e->getDuration(), 30);

}

TEST(TaskTest, newTask){
    Date* newDate= new Date(1,20);
    Task* e = new Task(newDate, "Baseball Practice", 1, 1230, 30);
    EXPECT_EQ(e->getDate()->getMonth(),1);
    EXPECT_EQ(e->getDate()->getDay(),20);
    EXPECT_EQ(e->getName(),"Baseball Practice");
    EXPECT_EQ(e->getPriority(),1);
    EXPECT_EQ(e->getTime(), 1230);
    EXPECT_EQ(e->getDuration(), 30);

}



int main(int argc, char** argv) {
    // Initialize the Google Test framework
    ::testing::InitGoogleTest(&argc, argv);

    // Run the tests
    return RUN_ALL_TESTS();
}