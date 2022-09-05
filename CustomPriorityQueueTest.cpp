//
// Created by Xiaodong Liu on 9/5/22.
//
#include "CustomPriorityQueue.h"
#include "gtest/gtest.h"

namespace ns{
    class CustomPriorityQueueTest: public ::testing::Test{
    protected:
        class Rectangle{
        public:
            int width, height;
            Rectangle(int _width = 1, int _height = 1): width(_width), height(_height){}
            bool operator==(const Rectangle& other) const{
                return this->width == other.width && this->height == other.height;
            }
            bool operator!=(const Rectangle& other) const{
                return !(*this == other);
            }
        };
        void SetUp() {
            A = {Rectangle(1,1), Rectangle(0, 0), Rectangle(2,3), Rectangle(1,1),  Rectangle(3,3), Rectangle(3,4)};
            B = {3,5,4,0,8};
        }
        vector<Rectangle> A;
        vector<int> B;
        priority_queue<int, vector<int>, std::greater<int> > minHeap;
        priority_queue<int> maxHeap;
    };

    TEST_F(CustomPriorityQueueTest, MaxHeapInt){
        EXPECT_EQ(maxHeap.size(), 0);
        maxHeap.push(B[0]);
        EXPECT_EQ(maxHeap.top(), 3);
        maxHeap.push(B[1]);
        EXPECT_EQ(maxHeap.top(), 5);
        maxHeap.push(B[2]);
        EXPECT_EQ(maxHeap.top(), 5);
        maxHeap.push(B[3]);
        EXPECT_EQ(maxHeap.top(), 5);
        maxHeap.push(B[4]);
        EXPECT_EQ(maxHeap.top(), 8);
        maxHeap.pop();
        EXPECT_EQ(maxHeap.top(), 5);
        maxHeap.pop();
        EXPECT_EQ(maxHeap.top(), 4);
        maxHeap.pop();
        EXPECT_EQ(maxHeap.top(), 3);
        maxHeap.pop();
        EXPECT_EQ(maxHeap.top(), 0);
        maxHeap.pop();
        EXPECT_EQ(maxHeap.size(), 0);
    }

    TEST_F(CustomPriorityQueueTest, MinHeapInt){
        EXPECT_EQ(minHeap.size(), 0);
        minHeap.push(B[0]);
        EXPECT_EQ(minHeap.top(), 3);
        minHeap.push(B[1]);
        EXPECT_EQ(minHeap.top(), 3);
        minHeap.push(B[2]);
        EXPECT_EQ(minHeap.top(), 3);
        minHeap.push(B[3]);
        EXPECT_EQ(minHeap.top(), 0);
        minHeap.push(B[4]);
        EXPECT_EQ(minHeap.top(), 0);
        minHeap.pop();
        EXPECT_EQ(minHeap.top(), 3);
        minHeap.pop();
        EXPECT_EQ(minHeap.top(), 4);
        minHeap.pop();
        EXPECT_EQ(minHeap.top(), 5);
        minHeap.pop();
        EXPECT_EQ(minHeap.top(), 8);
        minHeap.pop();
        EXPECT_EQ(minHeap.size(), 0);
    }

    TEST_F(CustomPriorityQueueTest, MaxHeapRectangle){
        auto less = [](const Rectangle& a, const Rectangle& b){
            return a.width*a.height < b.width*b.height;
        };
        //A = {Rectangle(1,1), Rectangle(0, 0), Rectangle(2,3), Rectangle(1,1),  Rectangle(3,3), Rectangle(3,4)};
        priority_queue<Rectangle, vector<Rectangle>, decltype(less)> maxHeap(less);
        EXPECT_EQ(maxHeap.size(), 0);
        maxHeap.push(A[0]);
        EXPECT_EQ(maxHeap.top(), A[0]);
        maxHeap.push(A[1]);
        EXPECT_EQ(maxHeap.top(), A[0]);
        maxHeap.push(A[2]);
        EXPECT_EQ(maxHeap.top(), A[2]);
        maxHeap.push(A[3]);
        EXPECT_EQ(maxHeap.top(), A[2]);
        maxHeap.push(A[4]);
        EXPECT_EQ(maxHeap.top(), A[4]);
        maxHeap.push(A[5]);
        EXPECT_EQ(maxHeap.top(), A[5]);

        maxHeap.pop();
        EXPECT_EQ(maxHeap.top(), A[4]);
        maxHeap.pop();
        EXPECT_EQ(maxHeap.top(), A[2]);
        maxHeap.pop();
        EXPECT_EQ(maxHeap.top(), A[0]);
        maxHeap.pop();
        EXPECT_EQ(maxHeap.top(), A[0]);
        maxHeap.pop();
        EXPECT_EQ(maxHeap.top(), A[1]);
        maxHeap.pop();
        EXPECT_EQ(maxHeap.size(), 0);
    }

    TEST_F(CustomPriorityQueueTest, MinHeapRectangle){
        auto greater = [](const Rectangle& a, const Rectangle& b){
            return a.width*a.height > b.width*b.height;
        };
        //A = {Rectangle(1,1), Rectangle(0, 0), Rectangle(2,3), Rectangle(1,1),  Rectangle(3,3), Rectangle(3,4)};
        priority_queue<Rectangle, vector<Rectangle>, decltype(greater)> minHeap(greater);
        EXPECT_EQ(minHeap.size(), 0);
        minHeap.push(A[0]);
        EXPECT_EQ(minHeap.top(), A[0]);
        minHeap.push(A[1]);
        EXPECT_EQ(minHeap.top(), A[1]);
        minHeap.push(A[2]);
        EXPECT_EQ(minHeap.top(), A[1]);
        minHeap.push(A[3]);
        EXPECT_EQ(minHeap.top(), A[1]);
        minHeap.push(A[4]);
        EXPECT_EQ(minHeap.top(), A[1]);
        minHeap.push(A[5]);
        EXPECT_EQ(minHeap.top(), A[1]);

        minHeap.pop();
        EXPECT_EQ(minHeap.top(), A[0]);
        minHeap.pop();
        EXPECT_EQ(minHeap.top(), A[0]);
        minHeap.pop();
        EXPECT_EQ(minHeap.top(), A[2]);
        minHeap.pop();
        EXPECT_EQ(minHeap.top(), A[4]);
        minHeap.pop();
        EXPECT_EQ(minHeap.top(), A[5]);
        minHeap.pop();
        EXPECT_EQ(minHeap.size(), 0);
    }

    TEST_F(CustomPriorityQueueTest, FindKthSmallest){
        //k = 5, n = 10
        int k = 5;
        vector<int> C = {100,21,32,40,5,2,3,1,9,0};
        vector<int> res;
        for(int i = 0; i < k; ++i){
            maxHeap.push(C[i]);
        }
        for(int i = k; i < C.size(); ++i) {
            maxHeap.push(C[i]);
            maxHeap.pop();
        }
        EXPECT_EQ(maxHeap.size(), k);
        EXPECT_EQ(maxHeap.top(), 5);
        maxHeap.pop();
        EXPECT_EQ(maxHeap.top(), 3);
        maxHeap.pop();
        EXPECT_EQ(maxHeap.top(), 2);
        maxHeap.pop();
        EXPECT_EQ(maxHeap.top(), 1);
        maxHeap.pop();
        EXPECT_EQ(maxHeap.top(), 0);
    }

    TEST_F(CustomPriorityQueueTest, FindKthLargest){
        //k = 5, n = 10
        int k = 5;
        vector<int> C = {100,21,32,5,2,3,40,1,9,0};
        vector<int> res;
        for(int i = 0; i < k; ++i){
            minHeap.push(C[i]);
        }
        for(int i = k; i < C.size(); ++i) {
            minHeap.push(C[i]);
            minHeap.pop();
        }
        EXPECT_EQ(minHeap.size(), k);
        EXPECT_EQ(minHeap.top(), 9);
        minHeap.pop();
        EXPECT_EQ(minHeap.top(), 21);
        minHeap.pop();
        EXPECT_EQ(minHeap.top(), 32);
        minHeap.pop();
        EXPECT_EQ(minHeap.top(), 40);
        minHeap.pop();
        EXPECT_EQ(minHeap.top(), 100);
    }
}