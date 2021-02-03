// Problem link: https://leetcode.com/contest/biweekly-contest-40/problems/design-front-middle-back-queue/

class FrontMiddleBackQueue {
    deque<int> firstHalf, secondHalf;
public:
    FrontMiddleBackQueue() {

    }

    void getSecondFrontToFirstBack() {
        int secondHalfFront = secondHalf.front();
        secondHalf.pop_front();
        firstHalf.push_back(secondHalfFront);
    }

    void getFirstBackToSecondFront() {
        int firstHalfBack = firstHalf.back();
        firstHalf.pop_back();
        secondHalf.push_front(firstHalfBack);
    }

    void pushFront(int val) {
        firstHalf.push_front(val);
        if (firstHalf.size() > secondHalf.size() + 1)
            getFirstBackToSecondFront();
    }

    void pushMiddle(int val) {
        if (firstHalf.size() == secondHalf.size() + 1)
            getFirstBackToSecondFront();
        firstHalf.push_back(val);
    }

    void pushBack(int val) {
        secondHalf.push_back(val);
        if (firstHalf.size() < secondHalf.size())
            getSecondFrontToFirstBack();
    }

    int popFront() {
        if (firstHalf.empty())
            return -1;
        if (firstHalf.size() == secondHalf.size())
            getSecondFrontToFirstBack();
        int ret = firstHalf.front();
        firstHalf.pop_front();
        return ret;
    }

    int popMiddle() {
        if (firstHalf.empty())
            return -1;
        int middle = firstHalf.back();
        firstHalf.pop_back();
        if (firstHalf.size() < secondHalf.size())
            getSecondFrontToFirstBack();
        return middle;
    }

    int popBack() {
        if (firstHalf.empty())
            return -1;
        if (secondHalf.empty()) {
            int ret = firstHalf.back();
            firstHalf.pop_back();
            return ret;
        }
        int ret = secondHalf.back();
        secondHalf.pop_back();
        if (firstHalf.size() > secondHalf.size() + 1)
            getFirstBackToSecondFront();
        return ret;
    }
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */